#define _CRT_SECURE_NO_WARNINGS 1

#include"My_Vector.h"

using namespace jiunian;

void test_1()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	for (auto e : a)
	{
		std::cout << e << std::endl;
	}
	return;
}

void test_2()
{
	vector<int> a(11, 11);
	for (auto e : a)
	{
		std::cout << e << std::endl;
	}
	return;
}


void test_3()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	vector<int>::iterator first = a.begin();
	vector<int>::iterator last = a.end();
	vector<int> b(first, last);
	for (auto e : b)
	{
		std::cout << e << std::endl;
	}
	return;
}


void test_4()
{
	vector<int> a(4, 15);
	vector<int> b(a);
	for (auto e : a)
	{
		std::cout << e << std::endl;
	}
	return;
}


void test_5()
{
	vector<int> a(4, 15);
	vector<int> b(5, 5);
	b = a;
	for (auto e : b)
	{
		std::cout << e << std::endl;
	}
	return;
}

void test_6()
{
	vector<int> a;
	vector<int> b(5, 11);
	//b = a;
	a.resize(2, 5);
	for (auto e : a)
	{
		std::cout << e << std::endl;
	}
	return;
}

void test_7()
{
	const vector<int> a(5, 11);
	//a.resize(3, 5);
	for (int i = 0; i < 4; ++i)
	{
		std::cout << a[i] << " ";
	}
	return;
}

void test_8()
{
	vector<int> a(5, 11);
	a.pop_back();
	a.pop_back();
	a.pop_back();
	a.pop_back();
	a.pop_back();
	for (auto e : a)
	{
		std::cout << e << " ";
	}
	return;
}

void test_9()
{
	vector<int> a(15, 11);
	//a.pop_back();
	//a.pop_back();
	//a.pop_back();
	//a.pop_back();
	//a.pop_back();
	vector<int> b(5, 12);
	a.swap(b);
	for (auto e : a)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
	for (auto e : b)
	{
		std::cout << e << " ";
	}
	return;
}

void test_10()
{
	vector<int> a(15, 11);
	//vector<int> b(5, 12);
	//a.swap(b);
	a.insert(a.begin(), 5);
	for (auto e : a)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
	return;
}

void test_11()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	a.erase(a.begin() + 3);
	for (auto e : a)
	{
		std::cout << e << " ";
	}
	return;
}

//int main()
//{
//	std::vector<int> a;
//	std::vector<int>::iterator b = a.begin();
//	std::vector<int>::iterator c = a.end();
//	std::cout << (c < b) << std::endl;
//	return 0;
//}

int main()
{
	test_11();
	return 0;
}