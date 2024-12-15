#include <iostream>
#include <thread>
#include <future>

using namespace std;

// cf) 오른값(Rvalue Reference; &&): Rvalue(임시값)을 참조할 수 있는 특별한 타입의 참조. 소유권을 전달받기 때문.
void PromiseWorker(std::promise<string>&& promise)
{
    // promise에 대응되는 future에 해당 값 설정
    promise.set_value("Secret Message");
}

int main()
{
    // 미래(std::future)에 결과물을 반환해줄 것에 대한 약속(std::promise)
    // - promise는 다른 쓰레드로 넘겨주고, future는 메인 쓰레드에서 그대로 관리
    std::promise<string> promise;
    std::future<string> future = promise.get_future();

    // promise의 소유권을 다른 쓰레드로 전달. 메인 쓰레드에서는 promise 더 이상 조작 불가!
    thread t(PromiseWorker, std::move(promise));

    // promise에 값이 설정될 때까지 대기했다가 설정된 값 반환!
    string msg = future.get();
    cout << msg << endl;

    t.join();
}
