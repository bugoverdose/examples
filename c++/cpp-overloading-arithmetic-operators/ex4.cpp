#include <iostream>

class Integer {
    private:
        int value;
    public:
        Integer(int value): value(value) {}
        int GetValue() const {
            return value;
        }
        void PrintValue() {
            std::cout<<value<<std::endl;
        }
};

Integer operator+(const Integer &num1, const Integer &num2) {
    Integer integer(num1.GetValue() + num2.GetValue());
    return integer;
}

int main(void) {
    Integer num1(10);
    Integer num2(20);
    Integer num = num1 + num2;
    num.PrintValue(); // 출력: 30
}
