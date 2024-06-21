#include <iostream>

class Squidward;

class Spongebob {
    private:
        int age;
        void ShowMyInfo() {
            std::cout<<age<<std::endl;
        }
        friend class Squidward;
    public:
        Spongebob(int age): age(age) {}
        void ShowPrivateInfo(Squidward squidward);
};

class Squidward {
    private:
        int height;
        void ShowMyInfo() {
            std::cout<<height<<std::endl;
        }
    public:
        Squidward(int height): height(height) {}
        void ShowPrivateInfo(Spongebob spongebob);
};

void Spongebob::ShowPrivateInfo(Squidward squidward){
    // std::cout<<squidward.height<<std::endl; // [컴파일 에러]
    // squidward.ShowMyInfo(); // [컴파일 에러]
    squidward.ShowPrivateInfo(*this);
}

void Squidward::ShowPrivateInfo(Spongebob spongebob) {
    std::cout<<spongebob.age<<std::endl;
    spongebob.ShowMyInfo();
};

int main(void) {
    Spongebob a(10);
    Squidward b(20);
    a.ShowPrivateInfo(b);
    b.ShowPrivateInfo(a);
}