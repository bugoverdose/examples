#include <iostream>
#include <thread>
#include <mutex> // Windows/Linux 공용

using namespace std;

// 동적 배열 std:vector 자체는 thread-safe하지 않음
vector<int> v;

// Mutual Exclusive (상호배타적)
mutex m;

void Push()
{
    for (int i = 0; i < 10000; i++)
    {
        // 다른 쓰레드에서 블록킹되도록 락 걸기
        m.lock();

        v.push_back(i);

        // 락 해제
        m.unlock();
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
