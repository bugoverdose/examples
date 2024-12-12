#include <iostream>
#include <thread>

using namespace std;

// Race Condition
// stack 영역에서 관리되는 경우, 다른 함수의 영향을 받지 않음.
// data, heap 영역은 쓰레드들이 공용으로 사용
// 전역 변수는 data 영역에 올라가므로 멀티쓰레드 환경에서 동시에 수정시 race condition 발생 가능!
int sum = 0;

void Add()
{
    for (int i = 0; i < 1000000; i++)
    {
        sum++;
        // 어셈블리어 기준 동작 방식
        // mov - 데이터 영역에 있는 sum의 값을 EAX 레지스터로 이동
        // inc - EAX 레지스터의 값을 1 증가시킴
        // mov - EAX 레지스터의 값을 데이터 영역에 있는 sum에 다시 저장
        // => CPU는 메모리의 값을 읽어오고 연산하는 두 가지 행동을 동시에 진행 불가! 그러므로 이처럼 단계적으로 진행.
    }
}

void Sub()
{
    for (int i = 0; i < 1000000; i++)
    {
        sum--;
        // 아래와 동일
        // int eax = sum;
        // sum = sum - 1;
        // sum = eax;
    }
}

int main()
{
    Add();
    Sub();
    cout << sum << endl; // 0
    
    thread t1(Add);
    thread t2(Sub);
    t1.join();
    t2.join();
    cout << sum << endl; // 135565, -856538 등 매번 달라짐
    // sum=0일 때 동시에 Add는 1로 수정하고, Sub은 -1으로 수정 => 변경 유실 발생!
}
