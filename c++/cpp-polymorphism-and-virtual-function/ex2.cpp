#include <iostream>
using namespace std;

class Bird {
    public:
        void fly() {
            cout<<"I'm a bird. I can fly!"<<endl;
        };
};

class Penguin : public Bird {
    public:
        void fly() {
            cout<<"I'm a penguin. I can not fly!"<<endl;
        };
        void swim() {
            cout<<"I'm a penguin. I can swim!"<<endl;
        };
};

int main(void)
{
    Penguin* penguin = new Penguin();
    Bird* bird = penguin;
    cout<<penguin<<endl; // [출력] 0x130e06a90
    cout<<bird<<endl; // [출력] 0x130e06a90

    penguin->fly(); // [출력] I'm a penguin. I can not fly!
    bird->fly(); // [출력] I'm a bird. I can fly!

    penguin->swim(); // [출력] I'm a penguin. I can swim!
    // bird->swim(); // 컴파일 실패

    // ==============

    // Bird* bird = new Penguin();
    // Penguin* penguin = bird; // 컴파일 실패
    return 0;
}
