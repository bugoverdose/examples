#include <iostream>

int main(void)
{
    int a = 10;
    int b = 20;
    int* const ptr = &a;
    *ptr = 100;
    std::cout<<*ptr<<std::endl; // 출력: 100
    a = 200;
    std::cout<<*ptr<<std::endl; // 출력: 200
    // ptr = &b; // [컴파일 에러]
    return 0;
}
