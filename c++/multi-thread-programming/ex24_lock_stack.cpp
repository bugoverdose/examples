#include <iostream>
#include <atomic>
#include <stack>
#include <mutex>
#include <future>
#include <thread>

using namespace std;

#define OUT

template<typename T>
class LockStack
{
public:
	LockStack() { }

	// 복사하지 못하도록 막음
	LockStack(const LockStack&) = delete;
	LockStack& operator=(const LockStack&) = delete;

	void Push(T value)
	{
		lock_guard<mutex> lock(_mutex);
		_stack.push(std::move(value));

		_condVar.notify_one();
	}

	bool TryPop(T& value)
	{
		lock_guard<mutex> lock(_mutex);
		// NOTE: Empty 함수 호출 후 Pop을 호출하는 구조가 아니라, 락을 잡고 Empty인지 체크 + Pop 시도까지 함께 진행.
		if (_stack.empty())
			return false;

		value = std::move(_stack.top());
		_stack.pop();
		return true;
	}

	void WaitPop(T& value)
	{
		unique_lock<mutex> lock(_mutex);
		// 비어있지 않은 경우(empty == false) 통과. 비어있는 동안에는 쓰레드를 대기 상태로 전환.
		_condVar.wait(lock, [this] { return _stack.empty() == false; });

		value = std::move(_stack.top());
		_stack.pop();
	}

private:
	stack<T> _stack;
	mutex _mutex;
	condition_variable _condVar;
};

LockStack<int> s;

void Push()
{
	while (true)
	{
		int value = rand() % 100;
		s.Push(value);

		this_thread::sleep_for(chrono::milliseconds(10));
	}
}

void Pop()
{
	while (true)
	{
		int data = 0;
		if (s.TryPop(OUT data))
			cout << data << endl;
		// s.WaitPop(OUT data);
		// cout << data << endl;
	}
}

int main()
{
	thread t1(Push);
	thread t2(Pop);
	thread t3(Pop);

	t1.join();
	t2.join();
	t3.join();
}
