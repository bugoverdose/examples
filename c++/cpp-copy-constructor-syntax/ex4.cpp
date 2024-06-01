#include <iostream>
using namespace std;

void Func1(int n) {
}

int Func2() {
  int n = 10;
  return n;
}

int main(void)
{
    // 1번 케이스
    int num1 = 10;
    int num2 = num1;
    // 2번 케이스
    Func1(10);
    // 3번 케이스
    Func2();
    return 0;
}
