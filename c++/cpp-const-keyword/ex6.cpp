#include <iostream>

class Class {
    private:
        int value; 
    public:
        Class(int num): value(num){}
        void Method() { 
            value += 1;
        }
        void ConstMethod() const {
            // value += 1; // [컴파일 에러]
        }
};

int main(void)
{
    Class a(10);
    a.Method();
    a.ConstMethod();
   
    const Class b(20);
    // b.Method(); // [컴파일 에러]
    b.ConstMethod();
    return 0;
}
