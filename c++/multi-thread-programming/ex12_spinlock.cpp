#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

/* [compare_exchange_strong의 의사코드] - CAS(Compare-And-Swap) 연산!
if (_locked == expected)
{
    expected = _locked;
    _locked = desired;
    return true;
}
else
{
    expected = _locked;
    return false;
}
*/
class SpinLock
{
    public:
        void lock()
        {
            bool expected = false;
            bool desired = true;
            // _locked = false(expected)인 경우, _locked = true(desired)로 수정 => 락 획득하면서 while문 탈출
            while (_locked.compare_exchange_strong(expected, desired) == false)
            {
                // _locked = true인 경우, expected = true으로 수정되기 때문에
                // 락 획득에 실패할 때마다 매번 다시 expected 값을 false로 수정 필요!
                expected = false;
            }
        }
        void unlock()
        {
            _locked.store(false);
            // _locked = false; // 위와 동일
        }
    private:
        atomic<bool> _locked{false};
        // atomic에 volatile까지 포함되므로 불필요
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
