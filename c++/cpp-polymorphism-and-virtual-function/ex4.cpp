#include <iostream>
using namespace std;

class Bird {
    public:
        virtual void fly() {
            cout<<"I'm a bird. I can fly!"<<endl;
        };
};

class Penguin : public Bird {
    public:
        virtual void fly() {
            cout<<"I'm a penguin. I can not fly!"<<endl;
        };
};

int main(void)
{
    Bird* birds[3];
    birds[0] = new Penguin();
    birds[1] = new Bird();
    birds[2] = new Penguin();

    for (int i = 0; i < 3; i++) {
        birds[i]->fly();
    }
    // [출력] I'm a penguin. I can not fly!
    // [출력] I'm a bird. I can fly!
    // [출력] I'm a penguin. I can not fly!
    return 0;
}
