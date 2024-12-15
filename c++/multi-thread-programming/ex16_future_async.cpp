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

int main()
{
    // 동기(synchronous) 실행
    int sum = Calculate();
    cout << sum << endl;

    // 다른 곳에서 Calculate 처리하고, 그 사이에 다른 작업 진행하는 것을 원한다면?
    // 별도의 쓰레드를 생성하여 병렬적으로 처리. 다만, 실행 결과를 전달받는 것에서 추가 작업 필요!
    // thread t(Calculate);
    // // TODO: 다른 작업 진행.
    // t.join();

    // std::future: 비동기 실행!
    {
        /**
        std::async에는 launch policy 전달 가능
        1) deferred 전달: lazy evaluation. 지연하여 실행. 
        - not 멀티쓰레드 프로그래밍. 진짜로 get/wait 호출 시점에 실행
        - 커맨드 패턴! 비동기이기는 하지만, future 없이 나중에 실행하는 것과 실질적으로 동일. 효용이 적음.
        2) async 전달: 별도의 쓰레드를 만들어서 실행
        - 멀티쓰레드 프로그래밍. 메인쓰레드 실행되는 동안, 별도의 쓰레드에서 병렬 처리!
        - 실행 결과는 get/wait 호출 시점에 반환.
        3) deferred | async 전달: 둘 중 하나를 알아서 선택하여 실행
        */
        // 쓰레드 하나 생성하여, 하나의 함수 비동기적으로 실행!
        std::future<int> future = std::async(std::launch::async, Calculate);

        // TODO: future 객체 생성만 하고, 다른 작업 진행

        // future_status : 실행 중인 함수가 완료된 상태인지 체크 가능
        // std::future_status status = future.wait_for(1ms);
        // if (status == future_status::ready)
        // {
        // }

        // 완료될 때까지 계속 대기
        // future.wait();

        // get: 결과물이 실제로 필요해진 시점에 대기하여 받고, future는 더 이상 유효하지 않게 됨! (wait + 반환)
        int sum = future.get();
        cout << sum << endl;
    }
    { // future로 객체의 멤버함수 호출하기
        class Knight
        {
        public:
            int GetHp() { return 100; }
        };
        Knight knight;
        std::future<int> future = std::async(std::launch::async, &Knight::GetHp, knight);
        int hp = future.get();
        cout << hp << endl;
    }
}
