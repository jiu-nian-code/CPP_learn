#include<iostream>
#include<vector>


const char* my_strstr(const char* str1, const char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	std::vector<int> arr(len2);
	int i = 0, j = 1;
	while (j < len2)
	{
		if (str2[i] == str2[j]) arr[j++] = ++i;
		else arr[j++] = i = 0;
	}
	int x = 0, y = 0;
	while (y < len2 && x < len1)
	{
		if (str1[x] == str2[y]) ++x, ++y;
		else y = arr[y];
	}
	if (y == strlen(str2)) return str1 + x - len2;
	return nullptr;
}

void* my_memcpy(void* destination, const void* source, size_t num)
{
	void* ret = destination;
	char* des = (char*)destination;
	char* sou = (char*)source;
	while (num--) *(des++) = *(sou++);
	return ret;
}

void* my_memmove(void* destination, const void* source, size_t num)
{
	void* ret = destination;
	char* des = (char*)destination;
	char* sou = (char*)source;
	if (destination > source)
	{
		des = des + num - 1;
		sou = sou + num - 1;
		while (num--) *(des--) = *(sou--);
	}
	else
	{
		while (num--) *(des++) = *(sou++);
	}
	return ret;
}

int main()
{
	char arr1[100];
	char arr2[100] = "hello world";
	std::cout << (char*)my_memmove(arr2 + 1, arr2, 2) << std::endl;
	return 0;
}