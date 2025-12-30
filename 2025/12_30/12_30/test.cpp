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

int main()
{
	//std::vector<Product> arr = { {"banana", 3, 10}, {"apple", 2, 35}, {"pear", 4, 20}};
	//std::sort(arr.begin(), arr.end(), compare_by_price());
	//for (auto& e : arr)
	//	printf("name: %-8s price: %2d sales: %2d\n", e._name.c_str(), e._price, e._sales);
	//std::cout << std::endl << std::endl;
	//std::sort(arr.begin(), arr.end(), compare_by_sales());
	//for (auto& e : arr)
	//	printf("name: %-8s price: %2d sales: %2d\n", e._name.c_str(), e._price, e._sales);
	//std::cout << std::endl << std::endl;
	//std::sort(arr.begin(), arr.end(), compare_by_name());
	//for (auto& e : arr)
	//	printf("name: %-8s price: %2d sales: %2d\n", e._name.c_str(), e._price, e._sales);

	//std::vector<Product> arr = { {"banana", 3, 10}, {"apple", 2, 35}, {"pear", 4, 20} };
	//auto compare_by_price = [](const Product& a, const Product& b)->bool {
	//	return a._price > b._price;
	//};
	//std::sort(arr.begin(), arr.end(), compare_by_price);
	//for (auto& e : arr)
	//	printf("name: %-8s price: %2d sales: %2d\n", e._name.c_str(), e._price, e._sales);
	//std::cout << std::endl << std::endl;
	//auto compare_by_sales = [](const Product& a, const Product& b)->bool {
	//	return a._sales > b._sales;
	//};
	//std::sort(arr.begin(), arr.end(), compare_by_sales);
	//for (auto& e : arr)
	//	printf("name: %-8s price: %2d sales: %2d\n", e._name.c_str(), e._price, e._sales);
	//std::cout << std::endl << std::endl;
	//auto compare_by_name = [](const Product& a, const Product& b)->bool {
	//	return a._name > b._name;
	//};
	//std::sort(arr.begin(), arr.end(), compare_by_name);
	//for (auto& e : arr)
	//	printf("name: %-8s price: %2d sales: %2d\n", e._name.c_str(), e._price, e._sales);

	int k = 4;
	int v = 8;
	auto add = [=](int a, int b) mutable { ++k; ++v;  return (a + b) * k * v; };
	std::cout << add(1, 1) << std::endl;
	std::cout << k << " " << v << std::endl;
	return 0;
}