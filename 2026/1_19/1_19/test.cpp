#include<iostream>
#include<thread>
#include<mutex>
#include<windows.h>

void PRINT(int num)
{
	for(int i = 0; i < num; ++i)
	{
		std::cout << "thread " << std::this_thread::get_id() << ": " << i << std::endl;
		Sleep(1000);
	}
}

int main()
{
	std::thread th1(PRINT, 10);
	std::thread th2(PRINT, 10);
	th1.join();
	th2.join();
	return 0;
}