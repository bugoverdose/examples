#include <iostream>

class Integer {
    private:
        int value;
    public:
        Integer(int value): value(value) {}
        friend void increment(Integer integer);
};

void increment(Integer integer) {
    std::cout<<integer.value<<std::endl;
    integer.value++;
    std::cout<<integer.value<<std::endl;
}

void increment(Integer integer, int value) {
    // integer.value++; // [컴파일 에러]
}


int main(void) {
    Integer num(10);
    increment(num);
}
