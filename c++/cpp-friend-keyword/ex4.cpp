#include <iostream>

class Integer {
    private:
        int value;
    public:
        Integer(int value): value(value) {}
        friend void increment(Integer integer) {
            std::cout<<integer.value<<std::endl;
            integer.value++;
            std::cout<<integer.value<<std::endl;
        }
};

int main(void) {
    Integer num(10);
    increment(num);

    Integer other(20);
    // num.increment(other); // [컴파일 에러]
}
