#include<iostream>
#include<atomic>

namespace thx
{
	template<class T>
	class shared_ptr
	{
		std::atomic<int>* _ref_num;
		T* _ptr;
	public:
		using self = shared_ptr<T>;
		shared_ptr(T* ptr) : _ptr(ptr)
		{
			if (!_ref_num) _ref_num = new std::atomic<int>(0);
			++(*_ref_num);
		}
		shared_ptr(const self& x)
		{
			_ref_num = x._ref_num;
			++(*_ref_num);
			_ptr = x._ptr;
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		T* get() { return _ptr; }
		int count() { return *_ref_num; }
		self& operator=(const self& x)
		{
			if (x._ptr == _ptr) return *this;
			--(*_ref_num);
			if (*_ref_num == 0)
			{
				delete _ref_num;
				delete _ptr;
				return *this;
			}
			_ref_num = x._ref_num;
			++(*_ref_num);
			_ptr = x._ptr;
			return *this;
		}
		~shared_ptr()
		{
			--(*_ref_num);
			if (*_ref_num == 0)
			{
				delete _ref_num;
				delete _ptr;
			}
		}
	};
}

struct A
{
	int _n;
	A(int n) : _n(n) { std::cout << "create A " << _n <<  std::endl; }
	~A() { std::cout << "destory A " << _n  << std::endl; }
};

int main()
{
	thx::shared_ptr<A> ptr1(new A(1));
	thx::shared_ptr<A> ptr2(new A(2));
	// ptr1 = ptr2;
	// std::cout << ptr2.count() << std::endl;
	std::cout << (*ptr1)._n << std::endl;
	std::cout << ptr1->_n << std::endl;
	return 0;
}