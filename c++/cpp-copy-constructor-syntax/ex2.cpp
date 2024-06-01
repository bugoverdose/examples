#include <iostream>
using namespace std;

class Integer
{
    public:
      int* value;
      Integer(int* value): value(value)
      {}
      Integer(Integer &other): value(other.value)
      {}
      void ChangeValue(int num)
      {
        *value=num;
      }
};

int main(void)
{
    int num = 10;
    Integer int1(&num);
    Integer int2=int1;
    cout<< &int1<<endl;
    cout<< &int2<<endl;
    cout<<int1.value<<endl;
    cout<<int2.value<<endl;

    int1.ChangeValue(20);
    cout<<*int1.value<<endl;
    cout<<*int2.value<<endl;

    num = 30;
    cout<<*int1.value<<endl;
    cout<<*int2.value<<endl;
    return 0;
}

// 쓸데 없이 코드량이 많아서 제외한 다른 예시
// #include <list>

// class IntList
// {
//     private:
//       list<int>* numbers;
//     public:
//       IntList(list<int> * numbers)
//       {
//         this->numbers = numbers;
//       }
//       void PrintData()
//       {
//         list<int>::iterator it;
//         cout<<"numbers: ";
//         for(it = numbers->begin();it != numbers->end();it++){ 
//           cout<<*it<<" ";
//         }
//         cout<<endl;
//       }
// };

// int main(void)
// {
//     list<int> li;
//     li.push_back(10);
//     IntList list1 = IntList(&li);
//     IntList list2 = IntList(list1);
//     cout<<"list1 : "<<&list1<<endl;
//     cout<<"list2 : "<<&list2<<endl;
//     li.push_back(20);
//     list1.PrintData();
//     list2.PrintData();
//     return 0;
// }