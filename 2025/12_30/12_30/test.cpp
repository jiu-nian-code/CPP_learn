#include<iostream>

void Func(int& x)
{
	std::cout << "void Func(int& x)" << std::endl;
}
void Func(const int& x)
{
	std::cout << "void Func(const int& x)" << std::endl;
}
void Func(int&& x)
{
	std::cout << "void Func(int&& x)" << std::endl;
}
void Func(const int&& x)
{
	std::cout << "void Func(const int&& x)" << std::endl;
}

template<class T>
void PerfectForword(T&& val)
{
	//Func(val);
	Func(std::forward<T>(val));
	//Func(std::move(val));
}

int main()
{
	int a = 1;
	const int b = 1;
	PerfectForword(a);
	PerfectForword(b);
	PerfectForword(1);
	PerfectForword(std::move(b));
	return 0;
}