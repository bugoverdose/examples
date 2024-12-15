#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

atomic<bool> flag;

int main()
{
    flag = false;

    // 기본적으로 Lock을 걸어주지 않음
    cout << flag.is_lock_free() << endl; // 1 

    // flag = true;
    flag.store(true, memory_order::memory_order_seq_cst);

    // bool val = flag;
    bool val = flag.load(memory_order::memory_order_seq_cst);

    // 이전 flag 값을 prev에 넣고, flag 값을 수정
    {
        bool prev = flag.exchange(true);
        // 아래 과정과 논리적으로 동일하지만, 아래 작업은 두 단계로 진행되므로 멀티쓰레드 환경에서는 예상 못한 동작 가능.
        // bool prev = flag;
        // flag = true;
    }

    // CAS(Compare-And-Swap) 조건부 수정
    {
        bool expected = false;
        bool desired = true;
        // flag == expected인 경우, desired로 수정하고 return true
        flag.compare_exchange_strong(expected, desired);
        // 아래 작업을 원자적으로 진행!
        // if (flag == expected)
        // {
        //     flag = desired;
        //     return true;
        // }
        // else
        // {
        //     expected = flag;
        //     return false;
        // }

        // compare_exchange_weak의 동작 방식은 compare_exchange_strong와 기본적으로 동일. 로직 자체는 동일!
        // Sparious Failure (가짜 실패) : 하드웨어 이슈 등 문제 상황 발생시, false 반환될수도 있음! 엄밀하지 않음!
        // strong보다 성능이 좋다고는 하는데, 대부분의 경우 유의미한 수준은 아님! strong은 문제 상황 발생시 그저 루프를 한번 더 도는게 전부이기 때문.
        flag.compare_exchange_weak(expected, desired);
        // if (flag == expected)
        // {
        //     if (문제 상황)
        //         return false;
        //     flag = desired;
        //     return true;
        // }
        // else
        // {
        //     expected = flag;
        //     return false;
        // }
    }
}
