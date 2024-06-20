#include <iostream>

class Class {
    public:
        Class(){}
        void Method() { 
            std::cout<<"method: "<<this<<std::endl;
        }
        void Method() const {

            std::cout<<"const method: "<<this<<std::endl;
        }
};

void CallMethod(const Class obj) {
    obj.Method();
} 

int main(void)
{
    Class obj;
    obj.Method(); // 출력: method: 0x16ce12bdb
    CallMethod(obj); // 출력: const method: 0x16ce12baf
    return 0;
}
