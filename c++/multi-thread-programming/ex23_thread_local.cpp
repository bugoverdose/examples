#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

using namespace std;

// 각 쓰레드 단위로 접근 가능한 전역변수 취급
thread_local int LThreadId = 0;

void ThreadMain(int threadId)
{
    // 쓰레드 단위로 값 할당. 다른 쓰레드에 영향 미치지 않음.
    LThreadId = threadId;

    while (true)
    {
        cout << LThreadId << endl;
        this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main()
{
    vector<thread> threads;
    for (int i = 0; i < 10; i++)
    {
        int threadId = i + 1;
        threads.push_back(thread(ThreadMain, threadId));
    }
    for (thread& t : threads)
    {
        t.join();
    }
}
