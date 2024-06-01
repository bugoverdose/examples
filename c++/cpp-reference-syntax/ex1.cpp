#include <iostream>
using namespace std;

int main(void)
{
    int num=100;
    int &ref=num;

    cout<<"num: "<<&num<<endl;
    cout<<"ref: "<<&ref<<endl;
    // num: 0x16b3dec38
    // ref: 0x16b3dec38

    num=200;
    cout<<"val: "<<num<<endl;
    cout<<"ref: "<<ref<<endl;
    // val: 200
    // ref: 200

    ref=300;
    cout<<"val: "<<num<<endl;
    cout<<"ref: "<<ref<<endl;
    // val: 300
    // ref: 300
    return 0;
}