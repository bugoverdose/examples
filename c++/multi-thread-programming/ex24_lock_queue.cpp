#include <iostream>
#include <atomic>
#include <queue>
#include <mutex>
#include <future>
#include <thread>

using namespace std;

#define OUT

template<typename T>
class LockQueue
{
public:
	LockQueue() { }

	// 복사하지 못하도록 막음
	LockQueue(const LockQueue&) = delete;
	LockQueue& operator=(const LockQueue&) = delete;

	void Push(T value)
	{
		lock_guard<mutex> lock(_mutex);
		_queue.push(std::move(value));

		_condVar.notify_one();
	}

	bool TryPop(T& value)
	{
		lock_guard<mutex> lock(_mutex);
		if (_queue.empty())
			return false;

		value = std::move(_queue.front());
		_queue.pop();
		return true;
	}

	void WaitPop(T& value)
	{
		unique_lock<mutex> lock(_mutex);
		_condVar.wait(lock, [this] { return _queue.empty() == false; });

		value = std::move(_queue.front());
		_queue.pop();
	}

private:
	queue<T> _queue;
	mutex _mutex;
	condition_variable _condVar;
};

LockQueue<int> q;

void Push()
{
	while (true)
	{
		int value = rand() % 100;
		q.Push(value);

		this_thread::sleep_for(chrono::milliseconds(10));
	}
}

void Pop()
{
	while (true)
	{
		int data = 0;
		if (q.TryPop(OUT data))
			cout << data << endl;
		// q.WaitPop(OUT data);
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
