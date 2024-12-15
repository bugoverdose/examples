#include <iostream>
#include <thread>
#include <atomic>
#include <queue>
#include <windows.h>

using namespace std;

mutex m;
queue<int> q;
HANDLE handle;

void Producer()
{
    while (true)
    {
        {
            unique_lock<mutex> lock(m);
            q.push(100);
        }

        // 이벤트를 Signal (파란색)으로 설정!
        ::SetEvent(handle);
        
        // 가끔가다가 하나씩 데이터를 추가하는 구조. Consumer 쪽에서 스핀락으로 꾸준히 체크하기에는 비효율적
        // => 이벤트를 통해 새로운 데이터가 추가되었을 때에 Consumer 쪽에 신호를 보내기!
        this_thread::sleep_for(chrono::milliseconds(10000));
    }
}

void Consumer()
{
    while (true)
    {
        // Non-Signal 상태일 때에는 `CPU를 점유하지 않고 무한정 대기`
        // 이벤트가 Signal 상태가 되었을 때, 커널에 의해 깨어나면서 아래쪽 코드 실행
        ::WaitForSingleObject(handle, INFINITE);
        // auto reset의 경우, 자동으로 Non-Signal 상태로 전환됨.
        // ::ResetEvent(handle); // manual reset의 경우, 별도로 Non-Signal 상태로 전환해줘야 함.

        unique_lock<mutex> lock(m);
        if (q.empty() == false)
        {
            int data = q.front();
            q.pop();
            cout << data << endl;
        }
    }
}

int main()
{
    // CreateEvent: `커널 오브젝트`인 이벤트 객체 하나 생성! 
    // handle은 이벤트 식별을 위한 정수값
    // - ManualReset 여부에 따라 manual reset vs auto reset
    handle = ::CreateEvent(NULL/* 보안 관련 속성*/, false/* ManualReset */, false/*InitialState*/, NULL);

    // 커널 오브젝트는 말 그대로 커널에서 관리되는 오브젝트
    // - 이벤트는 커널 오브젝트들 중에서도 상대적으로 가벼운 편
    // - 같은 머신 위에서 실행되는 다른 프로세스들 간의 동기화 과정에도 활용 가능

    // 모든 커널 오브젝트는 아래와 같은 속성들을 공용으로 지님
    // - Usage Count : 이 오브젝트를 몇 명이 사용하고 있는가
    // - Signal (파란불) / Non-Signal (빨간불) - bool 타입으로 관리

    thread t1(Producer);
    thread t2(Consumer);

    t1.join();
    t2.join();

    // 생성된 이벤트 제거. handle을 통해 이벤트 지정.
    ::CloseHandle(handle);
}
