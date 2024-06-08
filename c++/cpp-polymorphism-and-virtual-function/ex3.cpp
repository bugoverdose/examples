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
    Bird* birds[3];
    birds[0] = new Penguin();
    birds[1] = new Bird();
    birds[2] = new Penguin();

    for (int i = 0; i < 3; i++) {
        birds[i]->fly();
    }
    return 0;
}
