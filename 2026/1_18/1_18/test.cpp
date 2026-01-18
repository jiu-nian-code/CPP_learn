#include<iostream>
#include<vector>
#include<string>
#include<ios>

class B
{
public:
	int _b = 0;
};

class A
{
	int _a = 2;
public:
	A() {}
	explicit operator B()
	{
		return B();
	}
};

int main()
{
	//A a;
	////int b = a;
	//int b = static_cast<int>(a);
	//std::cout << b << std::endl;

	//std::string str;
	//while (std::cin >> str)
	//{
	//	std::cout << str << std::endl;
	//}


	return 0;
}