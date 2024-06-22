#include <iostream>

class Person {
    private:
        int age;
        int height;
    public:
        Person(int age = 0, int height = 0): age(age), height(height) {}
        friend std::istream& operator>>(std::istream&, Person&);
        friend std::ostream& operator<<(std::ostream&, const Person&);
};

std::istream& operator>>(std::istream& in, Person& person) {
    in>>person.age>>person.height;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Person& person) {
    out<<"[age: "<<person.age<<", height: "<<person.height<<"]";
    return out;
}

int main(void) {
    Person person = Person();
    std::cin>>person;
    // 입력: 20 180
    std::cout<<person<<std::endl;
    // 출력: [age: 20, height: 180]
}
