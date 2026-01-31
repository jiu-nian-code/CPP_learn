//#include<iostream>
//
////class Singleton
////{
////public:
////	static Singleton* GetInstance() { return &_sl; }
////private:
////	Singleton() {};
////	Singleton(const Singleton& self) = delete;
////	Singleton& operator=(const Singleton& self) = delete;
////	static Singleton _sl;
////};
////
////Singleton Singleton::_sl;
////
////int main()
////{
////	Singleton* sl = Singleton::GetInstance();
////	return 0;
////}
//
//template<class T, class t>
//int func(T a, T b)
//{
//	t x;
//	return a + b;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 1;
//	std::cout << func(a, b);
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//
//using namespace std;
//
//class father final
//{
//	int _money = 1000000;
//public:
//	virtual const father& money(int a) final
//	{
//		cout << 1000000 << endl;
//		return *this;
//	}
//
//	virtual ~father()
//	{
//		cout << "~father()" << endl;
//	}
//};
//
//class son : public father // 错误，不能被继承
//{
//	int _money = 1000;
//public:
//	virtual ~son()
//	{
//		cout << "~son()" << endl;
//	}
//};

//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//
//using namespace std;
//
//class father
//{
//	int _money = 1000000;
//public:
//	//virtual const father& money(int a)
//	//{
//	//	cout << 1000000 << endl;
//	//	return *this;
//	//}
//
//	virtual ~father()
//	{
//		cout << "~father()" << endl;
//	}
//};
//
//class son final : public father
//{
//	int _money = 1000;
//public:
//	virtual const son& money(int b)
//	{
//		cout << 1000 << endl;
//		return *this;
//	}
//
//	virtual ~son()
//	{
//		cout << "~son()" << endl;
//	}
//};
//
//class sonofson : public son // 错误，不能被继承
//{
//
//};

#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<string>

using namespace std;

class A
{
	int _a;
public:
	A(int a = 1) :
		_a(a)
	{

	}

	virtual void print()
	{
		cout << _a << endl;
	}
};

class B : virtual public A
{
	int _b;
public:
	B(int a = 1, int b = 2) :
		A(a),
		_b(b)
	{

	}

	virtual void print()
	{
		cout << _b << endl;
	}

	virtual void B_func()
	{
	}
};

class C : virtual public A
{
	int _c;
public:
	C(int a = 1, int c = 3) :
		A(a),
		_c(c)
	{

	}

	virtual void print()
	{
		cout << _c << endl;
	}

	virtual void C_func()
	{
	}
};

class D : public B, public C
{
	int _d;
public:
	D(int a = 1, int b = 2, int c = 3, int d = 4) :
		B(a, b),
		C(a, c),
		_d(d)
	{

	}

	virtual void print()//B和C都重写了，D必须重写，不然会报错
	{
		cout << _d << endl;
	}

	virtual void D_func()
	{

	}
};

int main()
{
	D d;
	return 0;
}
