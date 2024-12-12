#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class User;
class Account;

class UserManager
{
    public:
        // 싱글톤으로 모든 사용자들 관리
        static UserManager* instance()
        {
            static UserManager instance;
            return &instance;
        }

        User* GetUser(int id)
        {
            lock_guard<mutex> guard(_mutex);
            // TOOD
            return nullptr;
        }
        void ProcessSave();

    private:
        mutex _mutex;
};

class AccountManager
{
    public:
        // 싱글톤으로 모든 계정들 관리
        static AccountManager* instance()
        {
            static AccountManager instance;
            return &instance;
        }

        Account* GetAccount(int id)
        {
            lock_guard<mutex> guard(_mutex);
            // TODO
            return nullptr;
        }

        void ProcessLogin();
    
    private:
        mutex _mutex;
};

void UserManager::ProcessSave()
{
    // user lock
    lock_guard<mutex> guard(_mutex);
    // account lock
    Account* account = AccountManager::instance()->GetAccount(100);
}

void AccountManager::ProcessLogin()
{
    // account lock
    lock_guard<mutex> guard(_mutex);
    // user lock
    User* user = UserManager::instance()->GetUser(100);

    // 이처럼 user lock => account lock 순서로 획득하도록 강제하면 데드락 방지 가능.
    // // user lock
    // User* user = UserManager::instance()->GetUser(100);
    // // account lock
    // lock_guard<mutex> guard(_mutex);
}


void Func1()
{
    for (int i = 0; i < 1000; i++)
    {
        UserManager::instance()->ProcessSave();
    }
}

void Func2()
{
    for (int i = 0; i < 1000; i++)
    {
        AccountManager::instance()->ProcessLogin();
    }
}

int main()
{
    thread t1(Func1);
    thread t2(Func2);
    // 쓰레드1: account lock 획득한 상태에서 user lock 획득 시도
    // 쓰레드2: user lock 획득한 상태에서 account lock 획득 시도
    // => 교착 상태에 빠져 양쪽 다 무한 대기

    t1.join();
    t2.join();

    cout << "Finished" << endl;
}
