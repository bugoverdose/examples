#include <iostream>
#include <thread>

using namespace std;

int x = 0;
int y = 0;
int r1 = 0;
int r2 = 0;
volatile bool ready;

void Thread_1()
{
    while (!ready)
    {
    }
    y = 1; // Store y
    r1 = x; // Load x
}

void Thread_2()
{
    while (!ready)
    {
    }
    x = 1; // Store x
    r2 = y; // Load y
}

int main()
{
    int count = 0;
    while (true)
    {
        ready = false;
        count++;
        x = y = r1 = r2 = 0;

        thread t1(Thread_1);
        thread t2(Thread_2);

        // 두 쓰레드 모두 생성되었을 때 동시에 실행되도록
        ready = true;

        t1.join();
        t2.join();

        // 논리적으로 둘 다 0인 상황이 있으면 안될 것 같은데, 실제로는 낮은 확률로 발생 가능.
        // 가시성 이슈!
        if (r1 == 0 && r2 == 0)
            break;
    }
    cout << count << " 번만에 탈출" << endl;
}
