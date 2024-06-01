#include <iostream>
using namespace std;

int main(void)
{
    int num1=100;
    int &num2=num1;
    int &num3=num1;
    int &num4=num3;

    cout<<"num1: "<<num1<<endl;
    cout<<"num2: "<<num2<<endl;
    cout<<"num3: "<<num3<<endl;
    cout<<"num4: "<<num4<<endl;
    // num1: 100
    // num2: 100
    // num3: 100
    // num4: 100

    // int &ref;
    // int &ref=NULL;

    int arr[3]={1, 3, 5};
    int &first=arr[0];
    int &second=arr[1];
    int &third=arr[2];

    cout<<"first: "<<first<<endl;
    cout<<"second: "<<second<<endl;
    cout<<"third: "<<third<<endl;
    // first: 1
    // second: 3
    // third: 5

    int num=10;
    int *ptr=&num;
    int *(&ptrRef)=ptr;

    cout<<"ptr: "<<*ptr<<endl;
    cout<<"ptrRef: "<<*ptrRef<<endl;

    return 0;
}