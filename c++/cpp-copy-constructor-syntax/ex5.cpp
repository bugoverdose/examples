#include <iostream>
using namespace std;

class SimpleClass
{
    public:
      SimpleClass()
      {
        cout<<"Create new object: "<<this<<endl;
      }
      // 복사 생성자
      SimpleClass(const SimpleClass &obj)
      {
        cout<<"Create copy of "<<&obj<<": "<<this<<endl;
      }
};

SimpleClass PassAndReturn(SimpleClass ob /* [출력] Create copy of 0x16d9fad9a: 0x16d9fad98 */) { 
  cout<<"passed ob: "<<&ob<<endl; // [출력] passed ob: 0x16d9fad98
  return ob; // [출력] Create copy of 0x16d9fad98: 0x16d9fad99
}

int main(void)
{
    SimpleClass ob1; // [출력] Create new object: 0x16d9fad9b
    cout<<"ob1: "<<&ob1<<endl; // [출력] ob1: 0x16d9fad9b
    SimpleClass ob2 = ob1; // [출력] Create copy of 0x16d9fad9b: 0x16d9fad9a
    cout<<"ob2: "<<&ob2<<endl; // [출력] ob2: 0x16d9fad9a
    SimpleClass ob3 = PassAndReturn(ob2); 
    cout<<"returned ob3: "<<&ob3<<endl; // [출력] returned ob3: 0x16d9fad99
    return 0;
}
