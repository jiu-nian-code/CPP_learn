#include<iostream>
#include<vector>
#include<string>

class A
{
	int _a = 0;
public:
	A() = default;

	virtual void print()
	{
		std::cout << _a << std::endl;
	}
};

class B : public A
{
	int _b;
public:
	B() = default;

	virtual void print()
	{
		std::cout << _b << std::endl;
	}
};

class C
{
public:
	C() = default;
};

class D
{
	C _c;
public:
	D(C c) : _c(c) {};
};

int main()
{
	//int a = 1;
	//double b = a;
	//float c = a;
	//int* d = (int*)a; // 没法隐私转换，但是两者之间还是有点关系，所以可以强转
	//std::string str;
	//// std::vector arr = str; 如果两者之间没有一点关系，那么就不能转换
	//A ca;
	//B ca = ca; // 但是如果构成隐式类型转换，则可以转换

	//int pos = 0;
	//size_t sz = 0;
	//while (pos >= sz) // 死循环，pos整形提升成size_t，此时没有负数
	//{
	//	std::cout << "hello world" << std::endl;
	//	--pos;
	//}

	//int a = 1;
	//double b = static_cast<double>(a);
	//char c = 'a';
	//int d = static_cast<int>(c);
	//int* c = reinterpret_cast<int*>(a);
	//float f = 3.14f;
	//int i = reinterpret_cast<int&>(f);
	//float a = 3.1415926;
	//int b = reinterpret_cast<int&>(a); // 打印结果: 1078530010
	//int c = static_cast<int>(a); // 打印结果: 3
	//std::cout << b << std::endl;
	//std::cout << c << std::endl;
	//volatile const int a = 1;
	////int* b = reinterpret_cast<int*>(&a);
	//int* b = const_cast<int*>(&a);
	//(*b)++;
	//std::cout << a << std::endl; // 打印结果: 2
	//std::cout << *b << std::endl; // 打印结果: 2
	B a;
	A b = reinterpret_cast<A&>(a);
	//std::cout << b << std::endl;
	return 0;
}