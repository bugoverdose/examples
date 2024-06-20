#include <iostream>

int main(void)
{
    const int a = 10;
    int const b = 20;
    std::cout<<a+10<<std::endl;
    // a = 20; // [컴파일 에러]
    // a += 10; // [컴파일 에러]
    std::cout<<a+b<<std::endl;
    // b = 100; // [컴파일 에러]
    return 0;
}
