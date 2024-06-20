#include <iostream>

class Class {
    public:
        Class(){}
        Class(const Class& other){
            std::cout<<"copying "<<&other<<" to "<<this<<std::endl;
        }
        void Method() { 
            std::cout<<"method called by "<<this<<std::endl;
        }
        void Method() const {
            std::cout<<"const method called by "<<this<<std::endl;
        }
};

const Class& ConstReturnFunc(Class &obj) {
    return obj;
}

int main(void)
{
    Class obj;

    ConstReturnFunc(obj).Method(); 
    // 출력: const method called by 0x16da4ebdb
    
    Class returnedObj = ConstReturnFunc(obj); 
    // 출력: copying 0x16da4ebdb to 0x16da4ebda
    returnedObj.Method();
    // 출력: method called by 0x16da4ebda
    return 0;
}
