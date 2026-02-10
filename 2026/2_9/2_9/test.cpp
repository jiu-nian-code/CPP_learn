#include<iostream>
#include<vector>
#include<unordered_map>

void test1(std::initializer_list<std::pair<int, int>> arr)
{
	for (auto [x, y] : arr)
		std::cout << x << " " << y << std::endl;
}

int main()
{
	test1({ {1, 1}, {2, 2}, {3, 3} });
	return 0;
}