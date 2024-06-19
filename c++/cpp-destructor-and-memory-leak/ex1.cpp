#include <iostream>

class One {
    public:
        One() {};
        ~One() {
            std::cout<<"Destroying One"<<std::endl;
        };
};

class Two {
    private:
        One* one;
    public:
        Two() {
            one = new One();
        };
        ~Two() {
            // delete one;
            std::cout<<"Destroying Two"<<std::endl;
        };
};

void doSomething() {
    Two two;
    // ...
    return;
    // [출력] Destroying Two
}

int main(void)
{
    std::cout<<"Before doSomething"<<std::endl;
    doSomething();
    std::cout<<"After doSomething"<<std::endl;
    return 0;
}
