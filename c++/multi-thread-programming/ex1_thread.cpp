#include <iostream>
#include <thread>

// 입출력, 쓰레드 생성 등의 작업은 전부 시스템콜을 통해 OS 커널에 요청해줘야 하는 작업들

// 쓰레드 생성을 위해 운영체제에서 제공하는 API는 기본적으로 윈도우/리눅스별로 다름.
// - Windows의 경우 `#include <Windows.h>`로 헤더파일 추가 후 CreateThread 함수 활용
// - `thread`는 리눅스/윈도우에 종속되지 않는 운영체제 API 제공. cpp 11부터 표준으로 들어옴.

using namespace std;

void Runner()
{
    cout << "Hello World from Thread" << endl;
}

int main()
{
    // 신규 OS 쓰레드 생성 및 Runner 함수 실행
    std::thread t(Runner);

    cout << "Hello World from Main" << endl;
    // SIGABRT 발생
    // 생성된 스레드가 제대로 종료되기 전에 메인 쓰레드 및 프로세스가 종료되었기 때문
    // std::thread 객체는 스레드가 실행 중인 상태에서 소멸될 수 없으므로, std::terminate()가 호출되고 SIGABRT 시그널이 발생
}

// [출력]
// Hello World from Main
// libc++abi: terminating
// Hello World from Thread
// [1]    7312 abort      ./output/ex1_create_thread
