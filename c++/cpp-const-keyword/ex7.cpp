#include <iostream>

class Class {
    public:
        Class(){}
        void Method() { 
            std::cout<<"method"<<std::endl;
        }
        void Method() const {
            std::cout<<"const method"<<std::endl;
        }
};

int main(void)
{
    Class a;
    a.Method(); // 출력: method
    const Class b;
    b.Method(); // 출력: const method
    return 0;
}
