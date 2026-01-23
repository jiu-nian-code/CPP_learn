#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<atomic>

//bool is_one = true; // 是不是一号线程打印
//int num = 0;

int main()
{
	//std::mutex mt;
	//std::condition_variable cv;
	//std::thread th1([&]() {
	//	for (int i = 0; i < 10; ++i)
	//	{
	//		std::unique_lock<std::mutex> lock(mt);
	//		cv.wait(lock, []() { return is_one; });
	//		++num;
	//		std::cout << "thread " << std::this_thread::get_id() << ": " << num << std::endl;
	//		is_one = !is_one;
	//		cv.notify_one();
	//	}
	//});
	//std::thread th2([&]() {
	//	for (int i = 0; i < 10; ++i)
	//	{
	//		std::unique_lock<std::mutex> lock(mt);
	//		cv.wait(lock, []() { return !is_one; });
	//		++num;
	//		std::cout << "thread " << std::this_thread::get_id() << ": " << num << std::endl;
	//		is_one = !is_one;
	//		cv.notify_one();
	//	}
	//});
	std::atomic<float> a = 1.1;
	//std::thread th1([&](int num) {
	//	for (int i = 0; i < num; ++i)
	//		++a;
	//}, 10000);
	//std::thread th2([&](int num) {
	//	for (int i = 0; i < num; ++i)
	//		++a;
	//}, 10000);
	//th1.join();
	//th2.join();
	std::cout << a << std::endl; // 20000
	return 0;
}