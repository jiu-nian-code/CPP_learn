#include<iostream>

namespace thx
{
	template<class T>
	class list
	{
		template<class T>
		class node
		{
		public:
			using self = node<T>;
			self* _prev;
			self* _next;
			T _val;
			node(T val, self* prev = nullptr, self* next = nullptr) : _val(val), _prev(prev), _next(next) {}
		};
	public:
		using NODE = node<T>;
		class iterator
		{
			node<T>* _point;
		public:
			iterator(node<T>* pt) : _point(pt) {}
			iterator operator++(int)
			{
				node<T>* ret = _point;
				_point = _point->_next;
				return iterater(ret);
			}
			iterator operator++()
			{
				_point = _point->_next;
				return iterater(_point);
			}
			T& operator*()
			{
				return _point->_val;
			}
			T* operator->()
			{
				return &(_point->_val);
			}
			node<T>* get_point() { return _point; }
		};
		list() : _head(new NODE(T(), nullptr, nullptr)), _size(0) {}
		iterator begin() { return iterator(_head->_next); }
		iterator end()
		{
			NODE* cur = _head;
			while (cur->_next)
			{
				cur = cur->_next;
			}
			return iterator(cur);
		}
		bool insert(int pos, const T& val)
		{
			NODE* cur = _head;
			while (pos-- && cur)
			{
				cur = cur->_next;
			}
			if (pos > 0 || cur == nullptr) return false;
			NODE* newnode = new NODE(val);
			NODE* next_node = cur->_next;
			newnode->_next = cur->_next;
			newnode->_prev = cur;
			cur->_next = newnode;
			if(next_node) next_node->_prev = newnode;
			++_size;
			return true;
		}
		bool insert(iterator pos, const T& val)
		{
			NODE* cur = pos.get_point();
			if (!cur) return false;
			NODE* newnode = new NODE(val);
			NODE* prevnode = cur->_prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			newnode->_prev = prevnode;
			prevnode->_next = newnode;
			++_size;
			return true;
		}
		bool erase(int pos)
		{
			NODE* cur = _head;
			while (pos-- && cur)
			{
				cur = cur->_next;
			}
			if (pos > 0 || cur == nullptr) return false;
			NODE* del_node = cur->_next;
			if (!del_node) return false;
			NODE* next_node = del_node->_next;
			cur->_next = next_node;
			if (next_node) next_node->_prev = cur;
			delete del_node;
			--_size;
			return true;
		}
		bool erase(iterator pos)
		{
			NODE* cur = pos.get_point();
			if (!cur) return false;
			NODE* prevnode = cur->_prev;
			NODE* nextnode = cur->_next;
			prevnode->_next = nextnode;
			if(nextnode) nextnode->_prev = prevnode;
			delete cur;
			--_size;
			return true;
		}
		size_t size() { return _size; }
		bool empty() { _head->_next ? false : true; }
		bool push_back(const T& val)
		{
			return insert(_size, val);
		}
		bool pop_back()
		{
			return erase(_size - 1);
		}
		bool push_front(const T& val)
		{
			return insert(0, val);
		}
		bool pop_front()
		{
			return erase(0);
		}
		void PRINT()
		{
			NODE* cur = _head;
			while (cur)
			{
				cur = cur->_next;
				if(cur) std::cout << cur->_val << std::endl;
			}
		}
		~list()
		{
			NODE* cur = _head;
			while (cur)
			{
				NODE* prev_cur = cur;
				cur = cur->_next;
				delete prev_cur;
				--_size;
			}
			_head = nullptr;
		}
	private:
		NODE* _head;
		size_t _size;
	};
}

int main()
{
	thx::list<int> l;
	l.push_back(0);
	l.insert(l.begin(), 1);
	l.insert(l.begin(), 2);
	l.insert(l.begin(), 3);
	l.insert(l.begin(), 4);
	l.erase(l.begin());
	l.PRINT();
	return 0;
}