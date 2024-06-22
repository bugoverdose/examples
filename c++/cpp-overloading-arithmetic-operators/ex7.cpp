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
        Integer operator+(int num) {
            Integer integer(value + num);
            return integer;
        }
        void PrintValue() {
            std::cout<<value<<std::endl;
        }
};

int main(void) {
    Integer num1(10);
    Integer num2(20);
    Integer num3 = num1 + num2;
    num3.PrintValue(); // 출력: 30

    Integer num4 = num3 + 100;
    num4.PrintValue(); // 출력: 130

    // Integer num5 = 100 + num4; // [컴파일 에러]
}
