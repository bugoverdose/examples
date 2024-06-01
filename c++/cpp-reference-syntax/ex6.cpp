#include <iostream>
using namespace std;

int Do(int &ref)
{
    ref++;
}

int Func(const int &ref)
{
    // ref=1; // 컴파일 에러
}

int main(void)
{
    int num=1;
    Do(num);
    cout<<num<<endl;
    return 0;
}
