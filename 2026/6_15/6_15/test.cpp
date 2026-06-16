#include<iostream>

class A
{
public:
    void func()
    {
        std::cout << "hello world" << std::endl;
    }
};
class B {
    A* ptr;
public:
    B(A* p) : ptr(p) {}
    ~B() { if (ptr) ptr->func(); }
};

// 类内声明顺序：A 在先，B 在后
class Demo
{
    A objA;
    B objB;
public:
    // 构造函数1：列表顺序 B → A
    Demo() : objB(&objA), objA() {}
    // 构造函数2：列表顺序 A → B
    Demo(int) : objA(), objB(&objA) {}
};

int main()
{
    Demo d(1);
    return 0;
}