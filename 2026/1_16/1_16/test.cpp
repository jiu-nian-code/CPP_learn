#include<iostream>
#include<mutex>

//class CopyBan
//{
//public:
//	CopyBan() {}
//	CopyBan(const CopyBan& self) = delete;
//	CopyBan& operator=(const CopyBan& self) = delete;
//};

//class CopyBan
//{
//public:
//	CopyBan() {}
//private:
//	CopyBan(const CopyBan& self);
//	CopyBan& operator=(const CopyBan& self);
//};

//class HeapOnly
//{
//public:
//	static HeapOnly* create_HeapOnly() { return new HeapOnly; }
//private:
//	HeapOnly() {}
//	HeapOnly(const HeapOnly& self) = delete;
//	HeapOnly& operator=(const HeapOnly& self) = delete;
//};

class HeapOnly
{
public:
	void delete_HeapOnly() { delete this; }
private:
	~HeapOnly() {}
};

class StackOnly
{
public:
	static StackOnly create_StackOnly() { return StackOnly(); }
private:
	void* operator new(size_t size) = delete;
	void operator delete(void* p) = delete;
	StackOnly() {};
};

class NonInherit
{
public:
	static NonInherit create_NonInherit()
	{
		return NonInherit();
	}
private:
	NonInherit() {}
};

class A : public NonInherit
{

};

//class Singleton
//{
//public:
//	static Singleton* GetInstance() { return &_sl; }
//private:
//	Singleton() {}
//	Singleton(const Singleton& self) = delete;
//	Singleton& operator=(const Singleton& self) = delete;
//	static Singleton _sl;
//};

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (!_sl)
		{
			std::unique_lock<std::mutex> lock(_mt);
			if (!_sl) _sl = new Singleton;
		}
		return _sl;
	}

	void DelInstance()
	{
		std::cout << "DelInstance()" << std::endl;
		if (_sl)
		{
			std::unique_lock<std::mutex> lock(_mt);
			if (_sl)
			{
				delete _sl;
				_sl = nullptr;
			}
		}
	}

	class gc
	{
	public:
		~gc() { _sl->DelInstance(); }
	};

	static gc _gc;
private:
	Singleton() {}
	Singleton(const Singleton& self) = delete;
	Singleton& operator=(const Singleton& self) = delete;
	static Singleton* _sl;
	static std::mutex _mt;
};

Singleton* Singleton::_sl = nullptr;
Singleton::gc Singleton::_gc;
std::mutex Singleton::_mt;

class B
{
public:
	~B() { std::cout << "~B()" << std::endl; }
};

int main()
{
	//CopyBan cb1;
	//CopyBan cb2 = cb1;
	//CopyBan cb3(cb1);
	//HeapOnly* ho = new HeapOnly;
	//ho->delete_HeapOnly();
	//StackOnly so1 = StackOnly::create_StackOnly();
	//StackOnly* so1 = new StackOnly;
	//StackOnly* so2 = new StackOnly(so1);
	//A a;
	Singleton* sl = Singleton::GetInstance();
	return 0;
}