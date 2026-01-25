#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>

class Singleton
{
public:
	static Singleton& GetInstance()
	{
		static Singleton sl;
		return sl;
	}
private:
	Singleton() {}
	Singleton(const Singleton& self) = delete;
	Singleton& operator=(const Singleton& self) = delete;
};

namespace jiunian
{
	template<class T>
	class shared_ptr
	{
		T* _ptr;
		std::atomic<size_t>* _ref_count;
	public:
		using Self = shared_ptr<T>;
		shared_ptr() : _ptr(nullptr), _ref_count(new std::atomic<size_t>(0)) {}
		shared_ptr(T* ptr) : _ptr(ptr), _ref_count(new std::atomic<size_t>(1)) {}
		~shared_ptr()
		{
			if (_ptr && --(*_ref_count) == 0)
				delete _ptr, delete _ref_count;
		}
		T& operator*() { return *_ptr; }
		T* operator->() { return _ptr; }
		T* get() { return _ptr; }
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
}

int main()
{
	Singleton& sl = Singleton::GetInstance();
	return 0;
}