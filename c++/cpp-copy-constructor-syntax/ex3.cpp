#include <iostream>
using namespace std;

class DeepCopyInteger
{
    public:
      int* value;
      DeepCopyInteger(int* value): value(value)
      {}
      DeepCopyInteger(DeepCopyInteger &other)
      {
        int copy = *other.value;
        this->value= new int(copy);
      }
      void ChangeValue(int num)
      {
        *value=num;
      }
};

int main(void)
{
    int num = 10;
    DeepCopyInteger int1(&num);
    DeepCopyInteger int2=int1;
    cout<< &int1<<endl;
    cout<< &int2<<endl;
    cout<<int1.value<<endl;
    cout<<int2.value<<endl;

    int1.ChangeValue(20);
    cout<<*int1.value<<endl;
    cout<<*int2.value<<endl;

    int2.ChangeValue(30);
    cout<<*int1.value<<endl;
    cout<<*int2.value<<endl;
    return 0;
}
