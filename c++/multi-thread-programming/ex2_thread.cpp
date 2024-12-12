#include <iostream>
#include <thread>

using namespace std;

void Runner()
{
    cout << "Hello World from Thread" << endl;
}

int main()
{
    // 신규 쓰레드 객체 t 생성
    std::thread t;
    cout << t.get_id() << endl; // 0x0
    
    // Runner 함수로 쓰레드 객체 t 실행
    t = std::thread(Runner);
     // 본격적으로 OS 쓰레드가 만들어지면서 쓰레드의 고유 식별자가 할당됨
    cout << t.get_id() << endl; // 0x16f193000

    // CPU 코어 개수. 논리적으로 동시에 실행 가능한 쓰레드 개수! (100% 정확하지는 않고, 상황에 따라 0 출력 가능)
    int core_count = t.hardware_concurrency(); 
    cout << core_count << endl; // 10

    // 객체 t가 관리하는 쓰레드가 살아있는지 체크 (쓰레드의 id가 0인지 아닌지 체크)
    if (t.joinable())
        // 쓰레드 t가 종료될 때까지 메인 쓰레드에서 대기
        t.join();

    // std::tread 객체 t에서 실제 쓰레드를 분리. 메인함수에서 분리하여 백그라운드에서 독립적으로 실행.
    // 해당 프로그램 내에서 더 이상 객체 t의 정보를 알아내는 등의 작업 불가능해짐! (실질적으로 거의 사용하지 않음)
    // t.detach();

    cout << "Hello World from Main" << endl;
}
