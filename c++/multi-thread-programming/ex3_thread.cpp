#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void Runner(int num)
{
    cout << num;
}

int main()
{
    vector<std::thread> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(std::thread(Runner, i));
    }

    for (int i = 0; i < 10; i++)
    {
        if (v[i].joinable())
            v[i].join();
    }
    cout << endl << "Hello World from Main" << endl;
}
// [출력]
// 0132456789
// Hello World from Main