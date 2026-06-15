#include<iostream>

inline int add(int a = 1, int b = 2);

int main()
{
	std::cout << add() << std::endl;
	return  0;
}