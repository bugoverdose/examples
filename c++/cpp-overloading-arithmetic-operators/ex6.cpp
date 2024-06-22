#include <iostream>

class Integer {
    private:
        int value;
    public:
        Integer(int value): value(value) {}
        Integer operator+(const Integer &ref) {
            std::cout<<"method"<<std::endl;
            Integer integer(value + ref.value);
            return integer;
        }
        friend Integer operator+(const Integer &num1, const Integer &num2);
};

Integer operator+(const Integer &num1, const Integer &num2) {
    std::cout<<"function"<<std::endl;
    Integer integer(num1.value + num2.value);
    return integer;
}

int main(void) {
    Integer num1(10);
    Integer num2(20);
    Integer num3 = num1 + num2; // 출력: method
}
