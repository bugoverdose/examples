#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int main()
{
    int a = 0;
    a = 1;
    a = 2;
    a = 3;
    a = 4;
    cout << a << endl;
    // 이대로 컴파일할 경우, 어셈블리어상으로 컴파일러에서는 굳이 1,2,3으로 할당하는 작업을 생략하고, a = 4만 실행하는 최적화 적용함.
    
    // volatile : C++ 기준으로는 컴파일러에게 최적화를 하지 말아달라고 부탁할 뿐. 
    // C#과 Java의 volatile의 경우 추가적으로 memory barrier, 가시성 등 추가적인 기능 제공.
    int b = 0;
    b = 1;
    b = 2;
    b = 3;
    b = 4;
    cout << b << endl;
    // 실제로 어셈블리어에서 b에 일련의 값들을 그대로 재할당함. 최적화 진행하지 않음!
}
