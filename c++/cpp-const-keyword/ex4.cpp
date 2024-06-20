#include <iostream>

int main(void)
{
    int a = 10;
    const int &ref = a;
    // ref = 100 // [컴파일 에러]
    a = 100;
    std::cout<<ref<<std::endl;

    int b = 20;
    int const ref2 = b;
    // ref2 = 200; // [컴파일 에러]
    b = 200;
    std::cout<<ref2<<std::endl;
    return 0;
}
