#include <iostream>

void addAndPrint(int& num1, int& num2)
{
    std::cout<<num1+num2<<std::endl;
}

// void addAndPrint(const int& num1, const int& num2)
// {
//     std::cout<<num1+num2<<std::endl;
// }

void add(int& num, int value)
{
    num += value;
}

int main(void)
{
    const int& a = 10;
    const int& b = 20;
    // addAndPrint(a, b); // [컴파일 에러]
    addAndPrint(const_cast<int&>(a), const_cast<int&>(b)); // 출력: 30

    // a += 100; // [컴파일 에러]
    add(const_cast<int&>(a), 100);
    std::cout<<a<<std::endl; // 출력: 100
    return 0;
}
