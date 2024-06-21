#include <iostream>

class Patrick;

class Spongebob {
    private:
        int age;
        void ShowMyInfo() {
            std::cout<<age<<std::endl;
        }
        friend class Patrick;
    public:
        Spongebob(int age): age(age) {}
        void ShowPrivateInfo(Patrick patrick);
};

class Patrick {
    private:
        int height;
        void ShowMyInfo() {
            std::cout<<height<<std::endl;
        }
        friend class Spongebob;
    public:
        Patrick(int height): height(height) {}
        void ShowPrivateInfo(Spongebob spongebob);
};

void Spongebob::ShowPrivateInfo(Patrick patrick){
    std::cout<<patrick.height<<std::endl; 
    patrick.ShowMyInfo();
}

void Patrick::ShowPrivateInfo(Spongebob spongebob) {
    std::cout<<spongebob.age<<std::endl;
    spongebob.ShowMyInfo();
};

int main(void) {
    Spongebob a(10);
    Patrick b(20);
    a.ShowPrivateInfo(b);
    b.ShowPrivateInfo(a);
}