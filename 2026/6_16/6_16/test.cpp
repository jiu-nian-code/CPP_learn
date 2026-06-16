#include<iostream>

class A
{
public:
	A& operator=(const A& a)
	{

	}
};

A& operator=(const A& a)
{

}

int main()
{

	return 0;
}