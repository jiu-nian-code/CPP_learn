#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<ios>
#include<fstream>
#include<filesystem>
#include<sstream>

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

struct Date
{
	int _year;
	int _month;
	int _day;
	void PRINT()
	{
		std::cout << _year << "-" << _month << "-" << _day << std::endl;
	}
};

int main()
{
	std::ostringstream oss;
	std::istringstream iss("hello world 2");
	oss << "hello world " << 1;
	std::cout << oss.str() << std::endl;
	std::string str1, str2;
	int a;
	std::cout << iss.str() << std::endl;
	iss >> str1 >> str2 >> a;
	std::cout << str1 << " " <<  str2 << " " << a << std::endl;
	std::cout << iss.str() << std::endl;
	//´òÓ¡½á¹û:
	//hello world 1
	//hello world 2
	//hello world 2
	//hello world 2
	//
	return 0;
}