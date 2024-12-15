#include <iostream>
#include <thread>
#include <atomic>
#include <queue>
#include <mutex>

using namespace std;

mutex m;
queue<int> q;

// cf) User-Level Object (not 커널 오브젝트)
condition_variable cv;

void Producer()
{
    while (true)
    {
        {
            // 1) Lock을 잡고
            unique_lock<mutex> lock(m);
            // 2) 공유 변수 값을 수정
            q.push(100);
            // 3) Lock을 풀고
        }
        // 4) 조건변수를 통해 다른 쓰레드에게 통지
        cv.notify_one(); // wait 중인 쓰레드가 있으면 딱 1개만 깨운다!
        // cv.notify_all(); // wait 중인 쓰레드를 전부 다 깨운다!

        this_thread::sleep_for(chrono::milliseconds(1));
    }
}

void Consumer()
{
    while (true)
    {
        cout << "Consumer!" << endl;
        // 1) Lock을 잡으려고 시도한다. lock_guard와는 달리 unique_lock는 중간에 락을 해제할 수 있으므로 condition variable에서 활용하기 용이.
        unique_lock<mutex> lock(m);
        // 2) 조건 확인 - predicate으로 전달된 람다 확인
        // 만족O => 바로 빠져 나와서 코드를 이어서 진행
        // 만족X => Lock을 풀어주고 대기 상태로 전환! (q가 비어있지 않을 때까지 대기)
        // 즉, 이벤트(WaitForSingleObject)와의 차이점: 무조건 대기상태에 빠지는 것이 아니라, 조건에 따라 대기할수도 안할수도 있음.
        cv.wait(lock, []() { return q.empty() == false; });
        
        // 대기 중이었다면 Producer에 의해 notify_one 호출 시점에 위의 과정 재시도!
        
        // Q. notify_one을 했으면 항상 조건식을 만족하는 것이 아닌가? 굳이 조건을 체크해줘야 하나?
        // A. Spurious Wakeup! wait 중이다가 다시 실행 상태가 되었으나, 막상 q를 보니 비어있을 수도 있음. 
        // 다른 쓰레드에 의해 공유자원이 이미 수정되었을 수 있음! 그래서 condition variable 활용하는 것!
        // 이 문제는 notify_one 호출 시점에 Lock을 잡고 있지 않기 때문에 발생하는 것!

        int data = q.front();
        q.pop();
        cout << q.size() << endl;
    }
}

int main()
{
    thread t1(Producer);
    thread t2(Consumer);

    t1.join();
    t2.join();
}

// ====================================================

// (1) 기본 버전. mutex 락과 한 쌍으로 함께 사용
// #include <mutex>
// condition_variable cv;

// (2) 더 범용적인 버전
// #include <condition_variable>
// condition_variable_any cv;
