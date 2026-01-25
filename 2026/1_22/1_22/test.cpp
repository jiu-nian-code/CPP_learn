#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<atomic>
#include<future>
#include<functional>

//bool is_one = true; // 是不是一号线程打印
//int num = 0;

//int main()
//{
//	//std::mutex mt;
//	//std::condition_variable cv;
//	//std::thread th1([&]() {
//	//	for (int i = 0; i < 10; ++i)
//	//	{
//	//		std::unique_lock<std::mutex> lock(mt);
//	//		cv.wait(lock, []() { return is_one; });
//	//		++num;
//	//		std::cout << "thread " << std::this_thread::get_id() << ": " << num << std::endl;
//	//		is_one = !is_one;
//	//		cv.notify_one();
//	//	}
//	//});
//	//std::thread th2([&]() {
//	//	for (int i = 0; i < 10; ++i)
//	//	{
//	//		std::unique_lock<std::mutex> lock(mt);
//	//		cv.wait(lock, []() { return !is_one; });
//	//		++num;
//	//		std::cout << "thread " << std::this_thread::get_id() << ": " << num << std::endl;
//	//		is_one = !is_one;
//	//		cv.notify_one();
//	//	}
//	//});
//	std::atomic<float> a = 1.1;
//	//std::thread th1([&](int num) {
//	//	for (int i = 0; i < num; ++i)
//	//		++a;
//	//}, 10000);
//	//std::thread th2([&](int num) {
//	//	for (int i = 0; i < num; ++i)
//	//		++a;
//	//}, 10000);
//	//th1.join();
//	//th2.join();
//	std::cout << a << std::endl; // 20000
//	return 0;
//}

//void test(std::promise<int>& pr)
//{
//	//try
//	//{
//	//	throw std::runtime_error("出错了");
//	//}
//	//catch (...)
//	//{
//	//	pr.set_exception(std::current_exception()); // 传递异常
//	//}
//	pr.set_value(100);
//}
//
//int main()
//{
//	std::promise<int> pr;
//	std::future<int> fu = pr.get_future();
//	std::thread th1(test, std::ref(pr));
//	int ret = 0;
//	try
//	{
//		ret = fu.get(); // 重新抛出异常
//		ret = fu.get(); // 重新抛出异常
//	}
//	catch (const std::runtime_error& e)
//	{
//		std::cout << "捕获异常：" << e.what() << std::endl;
//	}
//	std::cout << ret << std::endl;
//	th1.join();
//	return 0;
//}

//int test()
//{
//	//throw std::runtime_error("出错了");
//	return 100;
//}
//
//int main()
//{
//	//auto fu = std::async(std::launch::async, test);
//	//int ret = 0;
//	//try
//	//{
//	//	ret = fu.get(); // 重新抛出异常
//	//}
//	//catch (const std::runtime_error& e)
//	//{
//	//	std::cout << "捕获异常：" << e.what() << std::endl;
//	//}
//	//std::cout << ret << std::endl;
//
//	std::atomic_flag af = true;
//	return 0;
//}

#include <atomic>
#include <thread>
#include <iostream>
class SpinLock
{
    std::atomic_flag flag = ATOMIC_FLAG_INIT;
public:
    void lock()
    {
        // 等待直到锁被释放
        while(flag.test_and_set(std::memory_order_acquire));
    }
    void unlock() { flag.clear(std::memory_order_release); }
};

int i = 0;

void task(SpinLock& spinlock)
{
    int num = 10000;
    while(num--)
    {
        spinlock.lock();
        // 执行临界区代码
        ++i;
        spinlock.unlock();
    }
}

int main()
{
    SpinLock spinlock;
    std::thread t1(task, std::ref(spinlock));
    std::thread t2(task, std::ref(spinlock));
    t1.join();
    t2.join();
    std::cout << i << std::endl; // 20000
    return 0;
}