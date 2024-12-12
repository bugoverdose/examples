#include <iostream>
#include <thread>
#include <atomic> // Windows/Linux 모두 호환. c++ 11 이상에서 제공. (cf. InterlockedAdd 함수 등은 윈도우 한정)

using namespace std;

// atomic 연산 = All-Or-Nothing
// atomic 클래스로 정의
atomic<int> sum(0);
// 참고. 복사할 수 없으므로 아래와 같은 방식은 컴파일 에러
// atomic<int> sum = 0;

void Add()
{
    for (int i = 0; i < 1000000; i++)
    {
        sum.fetch_add(1);
        // sum++; // 동일하게 동작
    }
}

void Sub()
{
    for (int i = 0; i < 1000000; i++)
    {
        sum.fetch_add(-1);
        // sum--; // 동일하게 동작
    }
}

int main()
{
    thread t1(Add);
    thread t2(Sub);
    t1.join();
    t2.join();
    cout << sum << endl; // 0
    // 주의사항: atomic 연산은 느림
}
