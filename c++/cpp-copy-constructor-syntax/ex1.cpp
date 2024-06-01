#include <iostream>
using namespace std;

class SimpleClass
{
    private:
      int num; 
    public:
      SimpleClass(int n): num(n)
      {
        cout<<"Create new object"<<endl;
      }
      // 복사 생성자
      SimpleClass(const SimpleClass &obj): num(obj.num)
      {
        cout<<"Create copy of "<<&obj<<endl;
      }
      void AddNum(int n)
      {
        num += n;
      }
      void PrintData()
      {
        cout<<num<<endl;
      }
};

int main(void)
{
    SimpleClass obj1 = SimpleClass(10);
    SimpleClass obj2 = SimpleClass(obj1);
    cout<<"obj1 : "<<&obj1<<endl;
    cout<<"obj2 : "<<&obj2<<endl;
    obj1.AddNum(5);
    obj1.PrintData();
    obj2.PrintData();
    return 0;
}