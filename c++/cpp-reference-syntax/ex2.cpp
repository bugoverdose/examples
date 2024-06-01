#include <iostream>
using namespace std;

int main(void)
{
    int *ptr=new int;
    int &ref=*ptr;
    ref=20;
    cout<<"ref: "<<ref<<endl;
    cout<<"*ptr: "<<*ptr<<endl;
    return 0;
}