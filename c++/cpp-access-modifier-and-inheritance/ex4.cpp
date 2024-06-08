#include <iostream>
using namespace std;

class Base
{
  private:
    int num1;
  protected:
    int num2;
  public:
    int num3;
    Base(int num1, int num2, int num3): num1(num1), num2(num2), num3(num3){
      cout<<"constructor from Base"<<endl;
    };
    void ShowBaseData()
    {
      cout<<"ShowBaseData"<<endl;
      cout<<num1<<endl;
      cout<<num2<<endl;
      cout<<num3<<endl;
    }
};

class Derived : private Base
{
  public:
    Derived(int num1, int num2, int num3): Base(num1, num2, num3){};
    void ShowDerivedData()
    {
      cout<<"ShowDerivedData"<<endl;
      cout<<num2<<endl;
      cout<<num3<<endl;
      ShowBaseData();
    }
};

class DeDerived : private Derived
{
  public:
    DeDerived(int num1, int num2, int num3): Derived(num1, num2, num3){};
    void ShowDeDerivedData()
    {
      cout<<"ShowDeDerivedData"<<endl;
      // cout<<num2<<endl; // [컴파일 실패] protected => private
      // cout<<num3<<endl; // [컴파일 실패] protected => private
      // ShowBaseData(); // [컴파일 실패] protected => private
      ShowDerivedData();
    }
};

int main(void)
{
    DeDerived obj(1, 2, 3);
    // obj.ShowDerivedData(); // [컴파일 실패] public => private
    obj.ShowDeDerivedData(); 
    return 0;
}
