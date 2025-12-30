#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
#include<ctime>
#include"my_vector.hpp"

using namespace std;

//class Date
//{
//	int _year;
//	int _month;
//	int _day;
//public:
//	Date(int y, int m, int d) : _year(y), _month(m), _day(d) {}
//
//	void PRINT() { std::cout << "year: " << _year << " " << "month: " << _month << " " << "day: " << _day << std::endl; }
//};
//
//struct Point
//{
//	Point(int a, int b) : _a(a), _b(b)
//	{
//		std::cout << "Point(int a, int b)" << std::endl;
//	}
//
//	Point(const Point& pt) : _a(pt._a), _b(pt._b)
//	{
//		std::cout << "Point(const Point& pt)" << std::endl;
//	}
//
//	int _a;
//	int _b;
//};
//
//template<class T>
//void PRINTING(std::initializer_list<T> il)
//{
//	for (auto& e : il)
//		std::cout << e << " ";
//	std::cout << std::endl;
//}
//
//void func(auto x)
//{
//	std::cout << x << std::endl;
//}

//int main()
//{
	//int a { 1 };
	//std::cout << a << std::endl;
	//Date d = { 1, 1, 1 };
	//d.PRINT();
	//Date{ 2025, 12, 24 }.PRINT();
	//Date *date_ptr = new Date{ 2025, 1, 1 };
	//date_ptr->PRINT();
	//int arr[]{ 1, 2, 3, 4 };
	//for (int i = 0; i < 4; ++i)
	//	std::cout << arr[i] << std::endl;
	//printf("|%*d|\n", 1, 8);
	//auto init = { 1, 2, 3 };
	//std::cout << typeid(init).name() << std::endl;
	// const int* ptr = { 1, 2, 3 };
	//
	// int arr1[4] = { 1, 2, 3, 4 };
	// int arr2[] = { 1, 2, 3, 4 }; // 等价上一行
	// Point pt = { 1, 2 };
	// std::cout << sizeof(arr2) << std::endl;
	// std::cout << pt._a << " " << pt._b << std::endl;
	//for (int i = 0; i < 4; ++i)
	//	std::cout << arr3[i] << std::endl;
	//
	//int a = { 1 };
	//int b { 1 };
	//Point pt = { 1, 2 }; 
	// 这里就能看出C++对C语言的兼容了，如果没有写构造，汇编代码就只是对结构体成员变量直接进行赋值，
	// 但是如果有构造函数，则是进行构造函数的调用，而且如果构造函数的参数不符合，还会报错
	//
	//std::vector<int> arr1 { 1, 2, 3 };
	//std::vector<int> arr2 = { 1, 2, 3 };
	//Point pt1 { 1, 2 };
	//Point pt2 = { 1, 2 };
	//
	//auto init1 = { 1, 2, 3 };
	//auto init2 = { 1, 2, 3, 4, 5, 6 };
	//std::cout << sizeof(init1) << std::endl;
	//std::cout << sizeof(init2) << std::endl;
	//// 输出结果: 16 16
	//std::cout << init1.size() << std::endl;
	//std::cout << init2.size() << std::endl;
	// PRINTING({1, 2, 3, 4});
	//jiunian::vector<int> arr = { 1, 2, 3 };
	//for (auto& e : arr)
	//	std::cout << e << " ";
	//std::cout << std::endl;
	//
	//std::unordered_map<int, int> mp{ {1, 1}, {2, 2}, {3, 30} };
	//std::vector<std::pair<int, int>> arr1{ {1, 2}, {1, 2}, {1, 2} };
	//jiunian::vector<int> arr2 = {1, 2, 3};
	//arr.push_back(1);
	//arr.push_back(2);
	//arr.push_back(3);
	//arr.push_back(1);
	//
	//std::vector<int>arr{1, 2, 3};
	//for (auto& e : arr)
	//	std::cout << e << std::endl;
	//std::unordered_map<int, int>mp{ {1, 1}, {2, 2}, {3, 3} };
	//for (auto& [k, v] : mp) // 结构化绑定，C++17支持
	//	std::cout << k << " " << v << std::endl;
	//auto it = arr.begin();
	//std::cout << typeid(it).name() << std::endl;
	//std::cout << typeid(it).raw_name() << std::endl;
	//decltype(it) tmp;
	//std::cout << typeid(tmp).name() << std::endl;
	//
	//auto x = 5, * y = &x;   // 正确：x是int，y是int*
	//// auto a = 1, b = 2.0; // 错误：a和b的类型不一致
	// 
	//std::vector<int>arr{ 1, 2, 3 };
	//auto it = arr.begin();
	//typeid(it).name() tmp; // 报错
	//decltype(it) tmp = it; // 直接推导变量
	//std::vector<decltype(1 * 1.2)> num; // 也能当模板参数，里面也能传表达式
	//std::cout << typeid(it).name() << std::endl;
	//return 0;
//}

//template<class Container, class Index>
//decltype(auto) func(Container& c, Index i)
//{
//	char& a = c[i];
//	return a;
//}
//
//int add(int a, int b)
//{
//	return a + b;
//}

//void func(int&& a)
//{
//	std::cout << "void func(int&& a)" << std::endl;
//}
//
//void func(const int& a)
//{
//	std::cout << "void func(const int& a)" << std::endl;
//}

//jiunian::vector<int> func()
//{
//	jiunian::vector<int> ret1{ 1, 2, 3 };
//	jiunian::vector<int> ret2{ 4, 5, 6 };
//	return (rand() % 2) ? ret1 : ret2; // 条件返回，通常禁用 RVO
//}

jiunian::vector<int>&& func()
{
	jiunian::vector<int> ret{ 1, 2, 3 };
	return move(ret);
}

int main()
{
	srand(time(NULL));
	//std::vector<char> arr{'a', 'b', 'c'};
	//int a = 1;
	//int& b = a;
	//decltype(auto) c = b;
	//c++;
	//for (auto& e : arr)
	//	std::cout << e << std::endl;
	// std::cout << c << std::endl;

	//std::cout << typeid(tmp).name() << std::endl;
	//int& n = i;
	//decltype(auto) m = n;
	//std::cout << typeid(i).name() << std::endl;

	//int a = 1; // 右值可以在右边
	//int b = a; // 左值可以在右边
	// 1 = a; // 右值不能在左边
	// 1 + 1 = a;
	// add(1, 1) = a;
	//int& ref_a = a; // 左值引用可以引用左值
	//int&& ref_c = 1; // 右值引用可以引用右值
	//int&& ref_d = add(1, 1);
	//int&& ref_e = 1 + 1;

	//"abcd"; // 乍一看是右值
	//const char* str = "abcd"; // 其实是左值，只是不能修改
	//std::cout << &"abcd" << std::endl; // 可以取地址，不过这里这个表达式自动返回自己的首元素地址，再取地址就是指针的地址
	//std::cout << &str[2] << std::endl; // 这里则是最好的证明，即使加上偏移量还是能取地址

	// int& ref_a = 1; // 错误
	//const int& ref_a = 1;
	//int b = 1;
	//// int&& ref_b = b; // 错误
	//int&& ref_b = std::move(b); // move函数转化后可以
	//std::unordered_map<int, int> mp;

	//int a = 1;
	//int& b = a;
	//decltype(auto) c = b; // int&
	//auto d = b; // int
	//c++;
	//d++;
	//std::cout << c << std::endl; // 打印结果： 2

	//func(1);
	//int a = 1;
	//func(a);
	// 结果:
	// void func(int&& a)
	// void func(int& a)

	//jiunian::vector<int> arr;
	//arr = func();
	//jiunian::vector<int> arr = func();
	//for (auto& e : arr)
	//	std::cout << e << " ";
	//std::cout << std::endl;

	//jiunian::vector<int> arr1{ 1, 2, 3 };
	//std::move(arr1);
	//jiunian::vector<int> arr2 = arr1;
	// 打印结果: vector(const vector<T>& v) --深拷贝
	//jiunian::vector<int> arr1{ 1, 2, 3 };
	//jiunian::vector<int> arr2 = std::move(arr1);
	// 打印结果: vector(vector<T>&& v) --移动构造

	jiunian::vector<jiunian::vector<int>> arr;
	arr.reserve(10);
	arr.push_back(jiunian::vector<int>{1, 2, 3});
	for (auto& e : arr)
	{
		for (auto& n : e)
			std::cout << n << " ";
		std::cout << std::endl;
	}
	//jiunian::vector<int> a{ 1, 2, 3 };
	//arr.push_back(a);
	//std::cout << "----------------------------------------" << std::endl;

	//arr.push_back(std::move(a));
	//std::cout << "----------------------------------------" << std::endl;

	//arr.push_back({ 1, 2, 3 });

	//std::vector<jiunian::vector<int>> arr(10);
	//arr.reserve(10); // 提前扩容，不然触发扩容迁移数据影响观察结果
	//jiunian::vector<int> a{ 1, 2, 3 };
	//arr.push_back(a);
	//std::cout << "----------------------------------------" << std::endl;

	//arr.push_back(std::move(a));
	//std::cout << "----------------------------------------" << std::endl;

	//arr.push_back({ 1, 2, 3 });

	// 打印结果: 
	// vector(const vector<T>&v) --深拷贝
	// ----------------------------------------
	// vector(vector<T> && v) --移动构造
	// ----------------------------------------
	// vector(vector<T> && v) --移动构造

	//std::vector<jiunian::vector<int>> arr;
	//arr.reserve(10); // 提前扩容，不然触发扩容迁移数据影响观察结果
	//jiunian::vector<int> a{ 1, 2, 3 };
	//arr.insert(arr.begin(), a);
	//std::cout << "----------------------------------------" << std::endl;

	//arr.insert(arr.begin(), std::move(a));
	//std::cout << "----------------------------------------" << std::endl;

	//arr.insert(arr.begin(), jiunian::vector<int>{ 1, 2, 3 });
	// insert正好有initializer_list版本的重载，这里不在前面声明jiunian::vector<int>会变成插入三个容量分别为1, 2, 3的jiunian::vector<int>

	// 打印结果: 
	// vector(const vector<T>& v) --深拷贝
	// ----------------------------------------
	// vector(vector<T> && v) --移动构造
	// vector(vector<T> && v) --移动构造
	// vector<T>&operator= (vector<T> && v) --移动拷贝
	// ----------------------------------------
	// vector(vector<T> && v) --移动构造
	// vector(vector<T> && v) --移动构造
	// vector<T>&operator= (vector<T> && v) --移动拷贝
	// vector<T>&operator= (vector<T> && v) --移动拷贝
	return 0;
}