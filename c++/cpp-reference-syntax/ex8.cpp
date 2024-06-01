#include <iostream>
using namespace std;

int& RefReturnFunc()
{
    int num=20;
    num+=10;
    return num;
}

int main(void)
{
    int num=RefReturnFunc();
    cout<<"num: "<<endl;
    cout<<"num: "<<endl;
    cout<<"num: "<<endl;
    cout<<"num: "<<num<<endl;
    return 0;
}
