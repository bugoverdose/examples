#include <iostream>

class Person {
    public:
        int age;
        int height;
        Person(int age = 0, int height = 0): age(age), height(height) {}
};

int main(void) {
    Person person = Person();
    // std::cin>>person; // [컴파일 에러]
    // std::cout<<person<<std::endl; // [컴파일 에러]
}
