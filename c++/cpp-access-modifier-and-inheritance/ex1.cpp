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
      cout<<"ShowBaseData from Base"<<endl;
      cout<<num1<<endl;
      cout<<num2<<endl;
      cout<<num3<<endl;
    }
};

int main(void)
{
    Base obj(1, 2, 3); // [출력] constructor from Base
    // cout<<obj.num1<<endl; // [컴파일 실패]
    // cout<<obj.num2<<endl; // [컴파일 실패]
    cout<<obj.num3<<endl; // [출력] 3
    obj.ShowBaseData(); 
    // [출력] 1 from Base
    // [출력] 2 from Base
    // [출력] 3 from Base
    return 0;
}
