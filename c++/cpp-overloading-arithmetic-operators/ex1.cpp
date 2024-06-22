#include <iostream>

class Integer {
    private:
        int value;
    public:
        Integer(int value): value(value) {}
};

int main(void) {
    int a = 10;
    int b = 3;
    
    std::cout<<a + b<<std::endl; // 출력: 13
    std::cout<<a - b<<std::endl; // 출력: 7
    std::cout<<a * b<<std::endl; // 출력: 30
    std::cout<<a / b<<std::endl; // 출력: 3
    std::cout<<a % b<<std::endl; // 출력: 1

    Integer num1(10);
    Integer num2(20);
    // Integer num3 = num1+num2; // [컴파일 에러]
}
