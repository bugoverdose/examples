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

class Derived : protected Base
{
  public:
    Derived(int num1, int num2, int num3): Base(num1, num2, num3){
      cout<<"constructor from Derived"<<endl;
    };
    void ShowDerivedData()
    {
      cout<<"ShowDerivedData"<<endl;
      // cout<<num1<<endl; // [컴파일 실패]
      cout<<num2<<endl;
      cout<<num3<<endl;
      ShowBaseData();
    }
};

class DeDerived : protected Derived
{
  public:
    DeDerived(int num1, int num2, int num3): Derived(num1, num2, num3){
      cout<<"constructor from DeDerived"<<endl;
    };
    void ShowDeDerivedData()
    {
      cout<<"ShowDeDerivedData"<<endl;
      cout<<num2<<endl;
      cout<<num3<<endl;
      ShowBaseData();
    }
};

int main(void)
{
    Derived obj(1, 2, 3);
    // [출력] constructor from Base
    // [출력] constructor from Derived
    
    // cout<<obj.num2<<endl; // [컴파일 실패] protected
    // cout<<obj.num3<<endl; // [컴파일 실패] public => protected로 변환

    // obj.ShowBaseData(); // [컴파일 실패] public => protected로 변환
    obj.ShowDerivedData();

    DeDerived obj2(1, 2, 3);
    // obj2.ShowDerivedData(); // [컴파일 실패] public => protected로 변환
    obj2.ShowDeDerivedData(); 
    return 0;
}
