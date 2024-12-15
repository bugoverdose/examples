#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

// 잘못 구현된 스핀락!
// 문제점: 락이 해제된 시점에 때 복수의 쓰레드들이 동시에 임계영역(critical section)에 접근하고, 동시에 락을 걸 수 있음.
//
// 해결방안
// (1) 락이 해제된 것을 인지하는 작업
// (2) 임계영역(critical section)에 접근하여 락을 거는 작업
// (1)+(2)가 동시에 진행될 수 있어야 함! CAS(Compare-And-Swap)
class SpinLock
{
    public:
        void lock()
        {
            while (_locked)
            {

            }
            _locked = true;
        }
        void unlock()
        {
            _locked = false;
        }
    private:
        // volatile : 해당 변수 _locked에 컴파일러에게 최적화를 하지 말아달라고 부탁. true/false를 할당하는 모든 로직을 실제로 실행!
        volatile bool _locked = false;
};

int sum = 0;
SpinLock spinLock;

void Add()
{
    for (int i = 0; i < 1000000; i++)
    {
        lock_guard<SpinLock> guard(spinLock);
        sum++;
    }
}

void Sub()
{
    for (int i = 0; i < 1000000; i++)
    {
        lock_guard<SpinLock> guard(spinLock);
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
