#include <iostream>
#include <thread>

using namespace std;

// 동적 배열 std:vector는 thread-safe하지 않음!
// 동시 접근이 발생하면서 SIGABRT 발생하고 빌드 과정에서 크래시남!
// STL(Standard Template Library)의 컨테이너들은 전부 기본적으로 멀티 쓰레드 환경에서 동작 불가!
// atomic<vector<int>>처럼 감싸서도 해결 불가
vector<int> v;

void Push()
{
    for (int i = 0; i < 10000; i++)
    {
        v.push_back(i);
    }
}

void issue1()
{
    thread t1(Push);
    thread t2(Push);

    t1.join();
    t2.join();

    cout << v.size() << endl;
    // SIGABRT 발생!
    // 동적 배열에서 복수의 스레드가 동시에 push_back을 호출하는 경우, 하나의 스레드가 크기를 증가시키기 위해 재할당하는 동안 다른 스레드가 기존 메모리에 접근 가능!

    // 쓰레드1 
    // [1][2][3] - 기존 배열에서 용량이 꽉 찼다고 판단하고
    // [1][2][3][][][] - 신규 배열을 생성
    // => 신규 배열로 대체하기 위해 기존 배열을 제거

    // 쓰레드2
    // [1][2][3] - 기존 배열에서 용량이 꽉 찼다고 판단하고 확장 시도
    // 문제는 그 사이에 이미 해당 기존 배열이 쓰레드1에 의해 제거됨 => 해제 불가 = 더블 프리 문제!
}

void issue2()
{
    // 미리 할당하여 배열 확장이 발생하지 않도록 함
    v.reserve(20000);

    thread t1(Push);
    thread t2(Push);

    t1.join();
    t2.join();

    cout << v.size() << endl; // 10395, 11168 등 20000보다 작음!
    // push_back 호출시, 현재 vector의 size 정보를 토대로 바로 다음 index에 새로운 값 추가하는 구조
    // => 특정 쓰레드에서 size 값을 읽고, 해당 위치에 추가하는 동안 다른 쓰레드에서 같은 곳에 값 추가하면서 덮어씀 => 데이터 유실 이슈
}

int main()
{
    // issue1();
    issue2();
}
