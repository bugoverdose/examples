#include <iostream>
using namespace std;

class Bird {
    public:
        Bird() {};
        Bird(const Bird &obj) {
            cout<<"Copying: "<<&obj<<" to "<<this<<endl;
        };
};

class Penguin : public Bird {
    public:
        Penguin() {};
};

int main(void)
{
    Penguin penguin;
    Bird& ref = penguin;
    Bird* pointer = &penguin;

    cout<<&penguin<<endl;
    cout<<&ref<<endl;
    cout<<pointer<<endl;

    // Penguin penguin;
    // cout<<&penguin<<endl;
    Bird bird = penguin;
    cout<<&bird<<endl;

    return 0;
}
