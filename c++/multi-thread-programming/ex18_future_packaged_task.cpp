#include <iostream>
#include <thread>
#include <future>

using namespace std;

int Calculate()
{
    int sum = 0;
    for (int i = 0; i < 100000; i++) {
        sum += 1;
    }
    return sum;
}

void TaskWorker(std::packaged_task<int(void)>&& task)
{
    task();
}

int main()
{
    // NOTE: int(void)는 Calculate 함수의 시그니처에 맞추어 반환값(매개변수)
    std::packaged_task<int(void)> task(Calculate);
    std::future<int> future = task.get_future();

    // 매개변수로 task의 소유권 전달하면서, 별도 쓰레드에서 처리하도록 함.
    // 하나의 쓰레드에 복수의 task 처리하도록 전달할 수도, 복수의 쓰레드에 복수의 task 전달할 수도 있음. 
    std::thread t(TaskWorker, std::move(task));

    int sum = future.get();
    cout << sum << endl;

    t.join();
}
