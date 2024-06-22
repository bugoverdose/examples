#include <iostream>

class Integer {
    private:
        int value;
    public:
        Integer(int value): value(value) {}
        friend Integer operator+(const Integer num1, int num2);
        friend Integer operator+(int num1, const Integer num2);
        void PrintValue() {
            std::cout<<value<<std::endl;
        }
};

Integer operator+(const Integer num1, int num2) {
    return Integer(num1.value + num2);
}

Integer operator+(int num1, const Integer num2) {
    return Integer(num1 + num2.value);
}

int main(void) {
    Integer num(10);
    
    Integer num2 = num + 20;
    num2.PrintValue(); // 출력: 30

    Integer num3 = 100 + num2;
    num3.PrintValue(); // 출력: 130
}
