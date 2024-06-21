#include <iostream>

class Calculator {
    public:
        void Increment(Integer integer);
        void Add(Integer integer, int value);
};

class Integer {
    private:
        int value;
    public:
        Integer(int value): value(value) {}
        friend void Calculator::Increment(Integer integer);
};

void Calculator::Increment(Integer integer) {
    integer.value++;
}

void Calculator::Add(Integer integer, int value) {
    // integer.value += value; // [컴파일 에러]
}

int main(void) {
    Calculator cal;
    Integer num(10);
    cal.Increment(num);
    cal.Add(num, 20);
}