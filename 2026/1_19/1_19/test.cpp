#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
#include<ctime>
#include<vector>

void PRINT(int num)
{
	for (int i = 0; i < num; ++i)
	{
		std::cout << "thread " << std::this_thread::get_id() << ": " << i << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

int main()
{
	//std::vector<std::thread> arr(20);
	//for (auto& e : arr)
	//	e = std::thread(PRINT, 10);
	//for (auto& e : arr)
	//	e.join();
	std::thread th1;
	{
		std::thread th2(PRINT, 10);
		th1 = std::move(th2);
	}
	std::unique_ptr<std::thread> th_ptr;
	{
		std::thread th2(PRINT, 10);
		th_ptr = std::move(std::unique_ptr<std::thread>(new std::thread(std::move(th2))));
	}
	th1.join();
	th_ptr->join();
	return 0;
}