#include<iostream>
#include<memory>
#include<exception>

template<class T>
class smart_ptr
{
	T* _ptr;
public:
	smart_ptr(T* ptr) : _ptr(ptr) {}
	~smart_ptr() { delete _ptr; }
	T& operator*() { return *_ptr; }
	T* operator->() { return _ptr; }
};

class A
{
public:
	A() { std::cout << "A()" << std::endl; }
	~A() { std::cout << "~A()" << std::endl; }
	void PRINT() { std::cout << _a << std::endl; }
	int _a = 1;
};

void div()
{
	int a, b;
	std::cin >> a >> b;
	if (b == 0) throw std::invalid_argument("Division by zero error.");
}

void func()
{
	smart_ptr<A> ptr1(new A());
	smart_ptr<A> ptr2(new A());
	ptr1->_a++;
	(*ptr1).PRINT();
}

//int main()
//{
//	try
//	{
//		func();
//	}
//	catch (std::exception& ep)
//	{
//		std::cout << ep.what() << std::endl;
//	}
//	return 0;
//}
// 打印结果为: 
// A()
// A()
// 2
// ~A()
// ~A()

//int main()
//{
//	std::auto_ptr<A> ap(new A());
//	return 0;
//}

int main()
{
	std::auto_ptr<A> ptr(new A());
	return 0;
}