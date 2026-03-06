#include<iostream>
template <typename T>
class MyTemplate {
public:
    void print() {
        // 打印当前实例的内存地址（验证是否为同一个实例）
        printf("MyTemplate<%s> 实例地址：%p\n", typeid(T).name(), this);
    }
};