#include<iostream>
#include<memory>
#include<exception>

namespace jiunian
{
	template<class T>
	class auto_ptr
	{
		T* _ptr;
	public:
		using Self = auto_ptr<T>;
		auto_ptr(T* ptr = nullptr) : _ptr(ptr) {}
		~auto_ptr() { delete _ptr; }
		T& operator*() { return *_ptr; }
		T* operator->() { return _ptr; }
		auto_ptr(Self& ap) { _ptr = ap._ptr, ap._ptr = nullptr; }
		Self& operator=(Self& ap) { _ptr = ap._ptr, ap._ptr = nullptr; return *this; }
		T* get() { return _ptr; }
	};

	template<class T>
	class unique_ptr
	{
		T* _ptr;
	public:
		using Self = unique_ptr<T>;
		unique_ptr() : _ptr(nullptr) {}
		unique_ptr(T* ptr) : _ptr(ptr) {}
		~unique_ptr() { delete _ptr; }
		T& operator*() { return *_ptr; }
		T* operator->() { return _ptr; }
		T* get() { return _ptr; }
		Self& operator=(const Self& up) = delete;
		Self& operator=(Self&& up) { _ptr = up._ptr, up._ptr = nullptr; return *this; }
		unique_ptr(const Self& up) = delete;
		unique_ptr(Self&& up) { _ptr = up._ptr, up._ptr = nullptr; }
	};

	template<class T>
	class shared_ptr
	{
		T* _ptr;
		size_t* _ref_count;
	public:
		using Self = shared_ptr<T>;
		shared_ptr() : _ptr(nullptr), _ref_count(new size_t(0)) {}
		shared_ptr(T* ptr) : _ptr(ptr), _ref_count(new size_t(1)) {}
		~shared_ptr()
		{
			if (_ptr && --(*_ref_count) == 0)
				delete _ptr, delete _ref_count;
		}
		T& operator*() { return *_ptr; }
		T* operator->() { return _ptr; }
		T* get() { return _ptr; }
		T* get() const { return _ptr; }
		size_t use_count() { return *_ref_count; }
		Self& operator=(const Self& sp)
		{
			if (sp._ptr == _ptr) return *this;
			if (_ptr && --(*_ref_count) == 0)
				delete _ptr, delete _ref_count;
			_ptr = sp._ptr;
			_ref_count = sp._ref_count;
			++(*_ref_count);
			return *this;
		}
		Self& operator=(Self&& sp)
		{
			if (sp._ptr == _ptr) return *this;
			if (_ptr && --(*_ref_count) == 0)
				delete _ptr, delete _ref_count;
			_ptr = sp._ptr;
			_ref_count = sp._ref_count;
			sp._ptr = nullptr;
			sp._ref_count = new size_t(0);
			return *this;
		}
		shared_ptr(const Self& sp) : _ptr(sp._ptr), _ref_count(sp._ref_count) { ++(*_ref_count); }
		shared_ptr(Self&& sp) : _ptr(sp._ptr), _ref_count(sp._ref_count)
		{
			sp._ptr = nullptr;
			sp._ref_count = new size_t(0);
		}
	};

	template<class T>
	class weak_ptr
	{
		T* _ptr;
	public:
		using Self = weak_ptr<T>;
		weak_ptr() : _ptr(nullptr) {}
		weak_ptr(const jiunian::shared_ptr<T>& sp) : _ptr(sp.get()) {}
		T& operator*() { return *_ptr; }
		T* operator->() { return _ptr; }
		weak_ptr(const Self& wp) { _ptr = wp._ptr; }
		weak_ptr(Self&& wp) { _ptr = wp._ptr; wp._ptr = nullptr; }
		Self& operator=(const Self& wp) { _ptr = wp._ptr; return *this; }
		Self& operator=(const jiunian::shared_ptr<T>& sp) { _ptr = sp.get(); return *this; }
		Self& operator=(Self&& wp) { _ptr = wp._ptr, wp._ptr = nullptr; return *this; }
		T* get() { return _ptr; }
	};
}

class A
{
public:
	A() { std::cout << "A()" << std::endl; }
	~A() { std::cout << "~A()" << std::endl; }
	void PRINT() { std::cout << _a << std::endl; }
	int _a = 1;
};

void div()
{
	int a, b;
	std::cin >> a >> b;
	if (b == 0) throw std::invalid_argument("Division by zero error.");
}

void func()
{
	jiunian::auto_ptr<A> ptr1(new A());
	jiunian::auto_ptr<A> ptr2(new A());
	ptr1->_a++;
	(*ptr1).PRINT();
}

//int main()
//{
//	try
//	{
//		func();
//	}
//	catch (std::exception& ep)
//	{
//		std::cout << ep.what() << std::endl;
//	}
//	return 0;
//}
// 打印结果为: 
// A()
// A()
// 2
// ~A()
// ~A()

//int main()
//{
//	std::auto_ptr<A> ap(new A());
//	return 0;
//}

class Node
{
public:
	Node() { std::cout << "Node()" << std::endl; }
	~Node() { std::cout << "~Node()" << std::endl; }
	jiunian::weak_ptr<Node> _next;
	int _var;
};

int main()
{
	//jiunian::auto_ptr<A> ptr1(new A());
	//jiunian::auto_ptr<A> ptr2(ptr1);
	//jiunian::auto_ptr<A> ptr3 = ptr2;
	//std::cout << ptr1.get() << std::endl;
	//std::cout << ptr2.get() << std::endl;
	//std::cout << ptr3.get() << std::endl;

	//jiunian::unique_ptr<A> ptr1(new A());
	//jiunian::unique_ptr<A> ptr2(std::move(ptr1));
	////std::unique_ptr<A> ptr2(ptr1); // 会报错
	//jiunian::unique_ptr<A> ptr3;
	//ptr3 = std::move(ptr2);
	////ptr3 = ptr2; // 会报错
	//std::cout << ptr1.get() << std::endl;
	//std::cout << ptr2.get() << std::endl;
	//std::cout << ptr3.get() << std::endl;

	//jiunian::shared_ptr<A> ptr1(new A());
	//jiunian::shared_ptr<A> ptr2(ptr1);
	//jiunian::shared_ptr<A> ptr3(std::move(ptr1));
	//ptr3 = std::move(ptr1);
	//ptr3->_a++;
	//ptr3->PRINT();
	//std::cout << ptr1.get() << std::endl;
	//std::cout << ptr2.get() << std::endl;
	//std::cout << ptr3.get() << std::endl;
	//std::cout << ptr1.use_count() << std::endl; // 打印引用计数

	jiunian::shared_ptr<Node> no1(new Node());
	jiunian::shared_ptr<Node> no2(new Node());
	no1->_next = no2;
	no2->_next = no1;
	std::cout << no1.use_count() << std::endl;
	std::cout << no2.use_count() << std::endl;
	return 0;
}
// 打印结果为:
// Node()
// Node()
// 1
// 1
// ~Node()
// ~Node()