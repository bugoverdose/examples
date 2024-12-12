#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

vector<int> v;
mutex m;

// RAII (Resource Acquisition is Initialization) 패턴
// wrapper class를 통해 생성자에서 락을 걸고, 소멸자에서 락을 해제하는 구조
// 객체 생성으로 인한 약간의 성능저하가 존재하지만, 락 해제를 잊어버리는 일을 방지
// std:lock_guard와 같이 표준에도 포함됨
template<typename T>
class LockGuard
{
    public:
        LockGuard(T& m)
        {
            _mutex = &m;
            _mutex->lock();
        }

        ~LockGuard()
        {
            _mutex->unlock();
        }
    private:
        T* _mutex;
};

void Push()
{
    // 락의 범위를 넓게 잡으면 10000번의 모든 작업이 끝날 때까지 다른 쓰레드 블록킹되도록 할 수 있음
    // LockGuard<std::mutex> lockGuard(m);

    for (int i = 0; i < 10000; i++)
    {
        // 방법1. 생성자 호출되면서 락을 걸고, 스코프 벗어나면 소멸자 호출되면서 락 해제
        LockGuard<std::mutex> lockGuard(m);
        // std:lock_guard<std::mutex> lockGuard(m); // 동일

        // 방법2. 명시적으로 lock 메서드 호출 시점에 락을 걸고, 소멸자에서 락 해제
        // std::unique_lock<std::mutex> uniqueLock(m, std::defer_lock);
        // uniqueLock.lock();

        v.push_back(i);
    }
}

int main()
{
    thread t1(Push);
    thread t2(Push);

    t1.join();
    t2.join();

    cout << v.size() << endl; // 20000
}
