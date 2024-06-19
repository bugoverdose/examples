#include <iostream>
#include <cstring>

class First {
    private:
        char* str1;
    public:
        First(char* str) {
            this->str1=new char[strlen(str)+1];
            strcpy(this->str1, str);
        };
        ~First() {
            std::cout<<"Destroying First"<<std::endl;
            std::cout<<"Destroying '"<<str1<<"'"<<std::endl;
            delete []str1;
        };
};

class Second : public First {
    private:
        char* str2;
    public:
        Second(char* str1, char* str2) : First(str1) {
            this->str2=new char[strlen(str2)+1];
            strcpy(this->str2, str2);
        };
        ~Second() {
            std::cout<<"Destroying Second"<<std::endl;
            std::cout<<"Destroying '"<<str2<<"'"<<std::endl;
            delete []str2;
        };
};

int main(void)
{
    Second* second = new Second("one", "two");
    delete second;
    // [출력] Destroying Second
    // [출력] Destroying 'two'
    // [출력] Destroying First
    // [출력] Destroying 'one'

    std::cout<<"==================="<<std::endl;

    First* first = new Second("one", "two");
    delete first;
    // [출력] Destroying First
    // [출력] Destroying 'one'
    return 0;
}
