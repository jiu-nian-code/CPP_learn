#include<iostream>
#include<functional>
#include<unordered_map>

//template<class F>
//int use_F(F f, int a)
//{
//	static int var = 0;
//	++var;
//	std::cout << var << std::endl;
//	std::cout << &var << std::endl;
//	return f(a);
//}
//
//struct functor
//{
//	int operator()(int a) { return a; }
//};
//
//int func(int a) { return a / 2; }
//
//void PRINT(char a, char b, char c, char d)
//{
//	printf("a: %c, b: %c, c: %c, d: %c.\n", a, b, c, d);
//}

//class Print
//{
//public:
//	void PRINT(char a, char b, char c, char d)
//	{
//		printf("a: %c, b: %c, c: %c, d: %c.\n", a, b, c, d);
//	}
//
//	void test()
//	{
//		std::function<void(char, char)> func = std::bind(&Print::PRINT, this, 'a', 'b', std::placeholders::_1, std::placeholders::_2);
//		func('c', 'd');
//	}
//};
//
//int main()
//{
//	//int a = 8;
//	//std::cout << use_F(functor(), a) << std::endl;
//	//std::cout << use_F(func, a) << std::endl;
//	//std::cout << use_F([](int a) { return a / 4; }, a) << std::endl;
//	//std::function<int(int)> func1 = functor();
//	//std::function<int(int)> func2 = func;
//	//std::function<int(int)> func3 = [](int a) { return a / 4; };
//	//std::cout << use_F(func1, a) << std::endl;
//	//std::cout << use_F(func2, a) << std::endl;
//	//std::cout << use_F(func3, a) << std::endl;
//	//std::unordered_map<std::string, std::function<int(int, int)>> channel;
//	//channel["+"] = [](int a, int b) { return a + b; };
//	//channel["-"] = [](int a, int b) { return a - b; };
//	//channel["*"] = [](int a, int b) { return a * b; };
//	//channel["/"] = [](int a, int b) { return a / b; };
//
//	//auto ret1 = std::bind(func, 1);
//	//auto ret2 = std::bind(func, 2);
//	//std::cout << typeid(ret1).name() << std::endl;
//	//std::cout << typeid(ret2).name() << std::endl;
//
//	//PRINT('a', 'b', 'c', 'd');
//	//std::function<void(int, int)> func1 = std::bind(PRINT, 'a', std::placeholders::_2, 'b', std::placeholders::_1);
//	//func1('c', 'd');
//	// 打印结果: a: a, b: b, c: d, d: c.
//	Print pt;
//	std::function<void(char, char)> func1 = std::bind(&Print::PRINT, pt, 'a', 'b', std::placeholders::_1, std::placeholders::_2);
//	std::function<void(char, char)> func2 = std::bind(&Print::PRINT, Print(), 'a', 'b', std::placeholders::_1, std::placeholders::_2);
//	pt.test();
//	func1('c', 'd');
//	func2('c', 'd');
//	// 打印结果: 
//	// a : a, b : b, c : c, d : d.
//	// a : a, b : b, c : c, d : d.
//	return 0;
//}

void PRINT(char a, char b, char c, char d)
{
	printf("a: %c, b: %c, c: %c, d: %c.\n", a, b, c, d);
}

int main()
{
	std::function<void(char, char)> func1 = std::bind(PRINT, 'a', 'b', std::placeholders::_1, std::placeholders::_2);
	func1('c', 'd');
	return 0;
}