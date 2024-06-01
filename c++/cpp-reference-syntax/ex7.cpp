#include <iostream>
using namespace std;

int& RefReturnFunc(int &ref)
{
    ref++;
    return ref;
}

int Func(int &ref)
{
    ref++;
    return ref;
}

int main(void)
{
    // int num1=1;
    // int num2=RefReturnFunc(num1);

    // num1+=10;
    // num2+=100;
    // cout<<"num1: "<<num1<<endl;
    // cout<<"num2: "<<num2<<endl;
    // // num1: 12
    // // num2: 102
    // cout<<"num1: "<<&num1<<endl;
    // cout<<"num2: "<<&num2<<endl;
    // // num1: 0x16f9f2c38
    // // num2: 0x16f9f2c34


    int num1=1;
    int num2=RefReturnFunc(num1);
    int &num3=RefReturnFunc(num1);
    int num4=Func(num1);
    // int &num5=Func(num1); // 컴파일 에러

    cout<<"num1: "<<&num1<<endl;
    cout<<"num2: "<<&num2<<endl;
    cout<<"num3: "<<&num3<<endl;
    cout<<"num4: "<<&num4<<endl;
    return 0;
}
