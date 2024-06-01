#include <iostream>
using namespace std;

int main(void)
{
    // int &ref=20; // 컴파일 실패
    const int &ref=20;

    const int num=100;
    const int &ref1=num;
    const int &ref2=100;

    // const int num=100;
    // const int &ref=num;

    // const int num=100;
    // int &ref=num; // 컴파일 실패
    // ref+=10;
    // cout<<"num1: "<<num<<endl;

    // int &num3=num1;
    // int &num4=num3;
    return 0;
}