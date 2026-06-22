#include<iostream>

template<typename Container, typename Index>
auto accessElement(Container& c, Index i) -> decltype(c[a]) {
	int a = 1;
	return c[i];
}

int main()
{

	return 0;
}