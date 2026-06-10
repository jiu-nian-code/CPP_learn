#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

int main()
{
	char str[] = "abcdef";
	strcpy(str + 2, str); // 内存重叠！
	return 0;
}