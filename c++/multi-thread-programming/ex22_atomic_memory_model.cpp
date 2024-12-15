#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

atomic<bool> ready;
int value;

void Producer()
{
    value = 10;

    // ready.store(true, memory_order::memory_order_seq_cst);
    ready.store(true, memory_order::memory_order_release); // ---- 절취선 ----
    // ready.store(true, memory_order::memory_order_relaxed);
}

void Consumer()
{
    // while (ready.load(memory_order::memory_order_seq_cst) == false)
    while (ready.load(memory_order::memory_order_acquire) == false) // ---- 절취선 ----
    // while (ready.load(memory_order::memory_order_relaxed) == false)
    {
        
    }
    cout << value << endl; 
    // 코드 재배치 문제, 가시성 문제가 없다면 무조건 10이 떠야 함
}

int main()
{
    // Memory Model : 3가지 정책 분류
    // 1) Sequentially Consistent : seq_cst
    // 2) Acquire-Release : consume, acquire, release, acq_rel
    // acq_rel = acquire + release
    // consume은 문제가 많아서 쓰지 않음. C++ 17에서 고치려고 시도?
    // 3) Relaxed : relaxed

    ready.store(false);
    value = 0;
    thread t1(Producer);
    thread t2(Consumer);
    t1.join();
    t2.join();

    // 1) seq_cst : 가장 엄격함. 보수적 = 컴파일러 최적화 여지가 적음 = 소스코드 그대로 직관적으로 동작
    // 가시성 보장. 코드 재배치 문제 발생하지 않음!
    // 멀티 쓰레드 환경에서는 가장 이상적. 애초에 디폴트 설정.
    // 인텔, AMD의 경우 애당초 순차적 일관성을 보장함. seq_cst를 사용했을 때, 딱히 부하가 없음! 성능 저하 없이 이상적!
    // 다만, ARM의 경우 차이가 날 수 있다고 함.

    // 2) acquire-release
    // release 명령 이전의 메모리 명령들이 해당 명령 이후로 재배치되는 것을 방지! 
    // - release 이전의 소스코드들끼리는 순서가 마음대로 변경될 수 있음. 
    // - 다만, release 이후로 이동하지는 않음.`value = 10;` 코드가 release 이후로 이동 불가.
    // acquire 모드로 같은 변수를 읽는 쓰레드가 있다면, release 이전의 명령들을 acquire하는 시점에 관찰 가능!
    // - release 이전의 명령어들이 전부 다 실행된 이후에 acquire 모드로 실행
    // - 즉, 가시성이 보장됨!

    // 3) relaxed : 가장 자유로움 = 컴파일러 최적화 여지 많음 = 직관적이지 않음
    // 가시성 해결 불가. 코드 재배치도 멋대로 발생 가능. (극악의 확률이므로 재현되기 힘들기는 함)
    // 절대적인 원칙인 "동일 객체에 대한 동일 관찰 순서"만 보장됨!
    // 실제로는 거의 사용하지 않음!

    // Q. 무조건 Atomic을 활용해야 하는가?
    // A. CPU에서 메모리 배리어라는 기능 지원. C++ 표준에서 지원하는 다른 기능들 존재.
    // ex) atomic을 통해 fence를 설정하여 가시성 보장 + 코드 재배치 문제 발생하지 않도록 지정 가능하기도 함.
    // std::atomic_thread_fence(memory_order::memory_order_release);
    // std::atomic_thread_fence(memory_order::memory_order_acquire);
}
