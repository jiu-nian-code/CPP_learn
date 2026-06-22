//#include<iostream>
//
//int globalVar = 1;
//static int staticGlobalVar = 1;
//void Test()
//{
//    static int staticVar = 1;
//    int localVar = 1;
//
//    int num1[10] = { 1, 2, 3, 4 };
//    char char2[] = "abcd";
//    const char* pChar3 = "abcd";
//    int* ptr1 = (int*)malloc(sizeof(int) * 4);
//    int* ptr2 = (int*)calloc(4, sizeof(int));
//    int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//    free(ptr1);
//    free(ptr3);
//}
//
////1. 选择题：
////选项 : A.栈  B.堆  C.数据段(静态区)  D.代码段(常量区)
////globalVar在哪里？__C__   staticGlobalVar在哪里？__C__
////staticVar在哪里？__C__   localVar在哪里？__A__
////num1 在哪里？__A__
////
////char2在哪里？__A__ * char2在哪里？__A__
////pChar3在哪里？__A__ * pChar3在哪里？__D__
////ptr1在哪里？__A__
////
////2. 填空题：
////sizeof(num1) = __40__;
////sizeof(char2) = __5__;
////sizeof(pChar3) = __4或8__;
////sizeof(ptr1) = __8__;
////3. sizeof 和 strlen 区别？一个球类型大小，一个求字符串长度，如果都求字符串，那么sizeof会包含/0，strlen不包含
////* ptr1在哪里？__堆上__
////strlen(char2) = __4__;
////strlen(pChar3) = __4__;
//
//int main()
//{
//
//	return 0;
//}


#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<string>

using namespace std;

class person
{
	string name;
public:
	person(const string& x = string()) :
		name(x)
	{}

	void name_print()
	{
		cout << name << endl;
	}
};

class father : public person
{
	int fa_money;
public:
	father(int a = 1000000, const string& x = string("little head")) :
		fa_money(a),
		person(x)
	{
		//cout << "father(int a = 1000000)" << endl;
	}

	father(const father& x) :
		fa_money(x.fa_money)
	{
		//cout << "father(const father& x)" << endl;
	}

	~father()
	{
		//cout << "~father()" << endl;
	}

	father* operator&()
	{
		return this;
	}

	const father* operator&()const
	{
		return this;
	}

	father& operator=(const father& x)
	{
		//cout << "father& operator=(const father & x)" << endl;
		fa_money = x.fa_money;
		return *this;
	}

	void print()
	{
		cout << fa_money << endl;
	}
};

class son : public father, public person
{
	int so_money;
public:
	son(int a = 1000, int b = 1000000, const string& x = string("big head")) :
		father(b),
		person(x),
		so_money(a)
	{
		//cout << "son(int a = 1000, int b = 1000000)" << endl;
	}

	son(const son& x) :
		father(x),
		so_money(x.so_money)
	{
		//cout << "son(const son& x):" << endl;
	}

	~son()
	{
		//father::~father();
		//cout << "~son()" << endl;
	}

	son* operator&()
	{
		return this;
	}

	const son* operator&()const
	{
		return this;
	}

	son& operator=(const son& x)
	{
		//cout << "son& operator=(const son& x)" << endl;
		so_money = x.so_money;
		father::operator=(x);
		return *this;
	}

	void print(int a)
	{
		cout << so_money << endl;
	}
};

int main()
{
	son x;
	x.father::name_print(); // 不加出错，二义性
	x.person::name_print();
	return 0;
}