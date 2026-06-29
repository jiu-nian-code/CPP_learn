#include<iostream>
#include<vector>

void quick_sort(std::vector<int>& arr)
{
	if (arr.empty()) return;
	int left = 0, right = 1;
	int flag = arr[0];
	while (left < right && right < arr.size())
	{
		if (arr[right] == flag)
		{
			++right;
		}
		else if (arr[right] < flag)
		{
			std::swap(arr[left++], arr[right]);
		}
		else
		{

		}
	}
}

int main()
{

	return 0;
}