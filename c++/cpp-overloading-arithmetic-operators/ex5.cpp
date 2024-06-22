#include <iostream>

class Integer {
    private:
        int value;
    public:
        Integer(int value): value(value) {}
        Integer operator+(const Integer &ref) {
            Integer integer(value + ref.value);
            return integer;
        }
        Integer operator-(const Integer &ref) {
            Integer integer(value - ref.value);
            return integer;
        }
        Integer operator*(const Integer &ref) {
            Integer integer(value * ref.value);
            return integer;
        }
        Integer operator/(const Integer &ref) {
            Integer integer(value / ref.value);
            return integer;
        }
        Integer operator%(const Integer &ref) {
            Integer integer(value % ref.value);
            return integer;
        }
        int GetValue() {
            return value;
        }
};

int main(void) {
    Integer a(10);
    Integer b(3);
    std::cout<<(a + b).GetValue()<<std::endl; // 출력: 13
    std::cout<<(a - b).GetValue()<<std::endl; // 출력: 7
    std::cout<<(a * b).GetValue()<<std::endl; // 출력: 30
    std::cout<<(a / b).GetValue()<<std::endl; // 출력: 3
    std::cout<<(a % b).GetValue()<<std::endl; // 출력: 1
}
