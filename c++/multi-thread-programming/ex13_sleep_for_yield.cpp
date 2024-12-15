#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

class SleepLock
{
    public:
        void lock()
        {
            bool expected = false;
            bool desired = true;
            // CAS(Compare-And-Swap)
            while (_locked.compare_exchange_strong(expected, desired) == false)
            {
                expected = false;

                // 락 획득 실패하면, 실행권 양도하여 커널모드에서 스케줄러가 다른 OS Thread 선택하여 실행
                
                // 1) 실행 => 대기 - 100ms 동안 OS Thread 대기 상태로 전환. 대기가 끝나면 준비 상태로 전환되어 스케줄링 대상으로 전환.
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                // this_thread::sleep_for(100ms); // 위와 동일

                // 2) 실행 => 준비 - 즉시 스케줄링 대상으로 전환
                // this_thread::yield();
                // this_thread::sleep_for(0ms); // 위와 동일
            }
        }
        void unlock()
        {
            _locked.store(false);
        }
    private:
        atomic<bool> _locked{false};
};

int sum = 0;
SleepLock sleepLock;

void Add()
{
    for (int i = 0; i < 1000000; i++)
    {
        lock_guard<SleepLock> guard(sleepLock);
        sum++;
    }
}

void Sub()
{
    for (int i = 0; i < 1000000; i++)
    {
        lock_guard<SleepLock> guard(sleepLock);
        sum--;
    }
}

int main()
{
    thread t1(Add);
    thread t2(Sub);

    t1.join();
    t2.join();

    cout << sum << endl;
}
