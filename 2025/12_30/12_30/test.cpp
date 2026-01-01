#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

//void Func(int& x)
//{
//	std::cout << "void Func(int& x)" << std::endl;
//}
//void Func(const int& x)
//{
//	std::cout << "void Func(const int& x)" << std::endl;
//}
//void Func(int&& x)
//{
//	std::cout << "void Func(int&& x)" << std::endl;
//}
//void Func(const int&& x)
//{
//	std::cout << "void Func(const int&& x)" << std::endl;
//}
//
//template<class T>
//void PerfectForword(T&& val)
//{
//	//Func(val);
//	Func(std::forward<T>(val));
//	//Func(std::move(val));
//}
//
//int main()
//{
//	int a = 1;
//	const int b = 1;
//	PerfectForword(a);
//	PerfectForword(b);
//	PerfectForword(1);
//	PerfectForword(std::move(b));
//	return 0;
//}

struct Product
{
	std::string _name;
	int _price;
	int _sales;
	Product(const std::string& name, int price, int sales) : _name(name), _price(price), _sales(sales) {}
};

//struct compare_by_price
//{
//	bool operator()(const Product& a, const Product& b)
//	{
//		return a._price > b._price;
//	}
//};
//
//struct compare_by_sales
//{
//	bool operator()(const Product& a, const Product& b)
//	{
//		return a._sales > b._sales;
//	}
//};
//
//struct compare_by_name
//{
//	bool operator()(const Product& a, const Product& b)
//	{
//		return a._name > b._name;
//	}
//};

//void  func()
//{
//	std::cout << 1 << std::endl;
//}
//
//int main()
//{
//	//std::vector<Product> arr = { {"banana", 3, 10}, {"apple", 2, 35}, {"pear", 4, 20}};
//	//std::sort(arr.begin(), arr.end(), compare_by_price());
//	//for (auto& e : arr)
//	//	printf("name: %-8s price: %2d sales: %2d\n", e._name.c_str(), e._price, e._sales);
//	//std::cout << std::endl << std::endl;
//	//std::sort(arr.begin(), arr.end(), compare_by_sales());
//	//for (auto& e : arr)
//	//	printf("name: %-8s price: %2d sales: %2d\n", e._name.c_str(), e._price, e._sales);
//	//std::cout << std::endl << std::endl;
//	//std::sort(arr.begin(), arr.end(), compare_by_name());
//	//for (auto& e : arr)
//	//	printf("name: %-8s price: %2d sales: %2d\n", e._name.c_str(), e._price, e._sales);
//
//	//std::vector<Product> arr = { {"banana", 3, 10}, {"apple", 2, 35}, {"pear", 4, 20} };
//	//auto compare_by_price = [](const Product& a, const Product& b)->bool {
//	//	return a._price > b._price;
//	//};
//	//std::sort(arr.begin(), arr.end(), compare_by_price);
//	//for (auto& e : arr)
//	//	printf("name: %-8s price: %2d sales: %2d\n", e._name.c_str(), e._price, e._sales);
//	//std::cout << std::endl << std::endl;
//	//auto compare_by_sales = [](const Product& a, const Product& b)->bool {
//	//	return a._sales > b._sales;
//	//};
//	//std::sort(arr.begin(), arr.end(), compare_by_sales);
//	//for (auto& e : arr)
//	//	printf("name: %-8s price: %2d sales: %2d\n", e._name.c_str(), e._price, e._sales);
//	//std::cout << std::endl << std::endl;
//	//auto compare_by_name = [](const Product& a, const Product& b)->bool {
//	//	return a._name > b._name;
//	//};
//	//std::sort(arr.begin(), arr.end(), compare_by_name);
//	//for (auto& e : arr)
//	//	printf("name: %-8s price: %2d sales: %2d\n", e._name.c_str(), e._price, e._sales);
//
//	int k = 4;
//	int v = 8;
//	//auto add = [&, v](int a, int b) { return a + b; };
//	//auto red = [add](int a, int b) mutable { std::cout << add(a, b) << std::endl; return (a - b); };
//	auto f1 = [](int a, int b) { return a + b; };
//	auto f2 = [](int a, int b) { return a + b; };
//	f1(1, 1);
//	f2(1, 1);
//	std::cout << typeid(f1).name() << std::endl;
//	std::cout << typeid(f2).name() << std::endl;
//	// ´òÓ¡½á¹û: 
//	// class `int __cdecl main(void)'::`2'::<lambda_1>
//	// class `int __cdecl main(void)'::`2'::<lambda_2>
//	// std::cout << add(1, 1) << std::endl;
//	// std::cout << k << " " << v << std::endl;
//	return 0;
//}

struct Date
{
	int _year;
	int _month;
	int _day;
	Date(int year = 1, int month = 1, int day = 1) : _year(year), _month(month), _day(day) {}
};

template<class ...Args>
void func(Args... args)
{
	Date* d = new Date(args...);
}

int main()
{

	return 0;
}