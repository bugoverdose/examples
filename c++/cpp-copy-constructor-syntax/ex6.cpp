#include <iostream>
using namespace std;

class SimpleClass
{
    public:
      int num;
      SimpleClass(int n): num(n)
      {
        cout<<"Create new object: "<<this<<endl;
      }
      explicit SimpleClass(SimpleClass &obj): num(obj.num)
      {
        cout<<"Create copy of "<<&obj<<": "<<this<<endl;
      }
};

int main(void)
{
    int num1(10);
    int num2=10;
  
    int &ref1(num1);
    int &ref2=num1;
  
    SimpleClass ob1(10);
    SimpleClass ob2(ob1);
    // SimpleClass ob3=ob1; // SimpleClass ob3(ob1);로 묵시적 변환
    return 0;
}
