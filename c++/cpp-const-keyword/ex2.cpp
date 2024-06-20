#include <iostream>

int main(void)
{
    int a = 10;
    int b = 20;
    const int* ptr = &a;
    // *ptr = 100; // [컴파일 에러]
    a = 100;
    std::cout<<*ptr<<std::endl;
    ptr = &b;
    std::cout<<*ptr<<std::endl;
    // *ptr = 200; // [컴파일 에러]
    return 0;
}
