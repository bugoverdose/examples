#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex m1;
mutex m2;

void Func()
{
    for (int i = 0; i < 1000; i++)
    {
        // 내부적으로 일관된 순서를 통해 언제나 순차적으로 락을 거는 기능.
        std::lock(m1, m2);

        // do something...

        // adopt_lock : 이미 락 걸린 상태이니, 생성자 호출될 때 락 걸지 말고 소멸될 때에 해제만 하기
        lock_guard<mutex> g1(m1, std::adopt_lock);
        lock_guard<mutex> g2(m2, std::adopt_lock);
    }
}

int main()
{
    thread t1(Func);
    thread t2(Func);

    t1.join();
    t2.join();

    cout << "Finished" << endl;
}
