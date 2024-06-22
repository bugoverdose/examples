#include <iostream>

class Integer {
    private:
        int value;
    public:
        Integer(int value): value(value) {}
        friend Integer operator+(const Integer &num1, const Integer &num2);
        void PrintValue() {
            std::cout<<value<<std::endl;
        }
};

Integer operator+(const Integer &num1, const Integer &num2) {
    Integer integer(num1.value + num2.value);
    return integer;
}

int main(void) {
    Integer num1(10);
    Integer num2(20);
    Integer num = num1 + num2;
    num.PrintValue(); // 출력: 30
}
