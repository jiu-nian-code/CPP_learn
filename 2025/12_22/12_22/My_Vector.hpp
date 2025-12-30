#pragma once
#include<iostream>
#include<vector>
#include<cassert>

namespace jiunian
{
    template<class T>
    class vector
    {
    public:
        using iterator = T*;
        using const_iterator = const T*;
        iterator begin() { return _start; }
        iterator end() { return _finish; }
        const_iterator begin() const { return _start; }
        const_iterator end() const { return _finish; }
        size_t size() { return _finish - _start; }
        size_t size() const { return _finish - _start; }
        size_t capacity() { return _end_of_storage - _start; }
        size_t capacity() const { return _end_of_storage - _start; }
        vector() {}
        vector(int n, const T& value = T()) { resize(n, value); } // TODO?也许可以增加效率
        vector(std::initializer_list<T> il)
        {
            auto it = il.begin();
            while (it != il.end())
            {
                push_back(*it);
                ++it;
            }
        }
        template<class InputIterator>
        vector(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                push_back(*first);
                ++first;
            }
        }
        vector(const vector<T>& v) noexcept
        {
            std::cout << "vector(const vector<T>& v) --深拷贝" << std::endl;
            reserve(v.capacity());
            for (auto e : v)
                push_back(e);
        }
        vector(vector<T>&& v) noexcept
        {
            std::cout << "vector(vector<T>&& v) --移动构造" << std::endl;
            swap(v);
        }
        void swap(vector<T>& v)
        {
            std::swap(v._start, _start);
            std::swap(v._finish, _finish);
            std::swap(v._end_of_storage, _end_of_storage);
        }
        const T& operator[](size_t pos)const
        {
            assert(pos < size());
            return _start[pos];
        }
        vector<T>& operator= (const vector<T>& v)
        {
            std::cout << "vector<T>& operator= (const vector<T>& v) --深拷贝" << std::endl;
            vector<T> tmp(v);
            swap(tmp);
            return *this;
        }
        vector<T>& operator= (vector<T>&& v)
        {
            std::cout << "vector<T>& operator= (vector<T>&& v) --移动拷贝" << std::endl;
            swap(v);
            return *this;
        }
        ~vector()
        {
            if (_start == nullptr) return;
            delete[] _start;
            _start = nullptr;
            _finish = nullptr;
            _end_of_storage = nullptr;
        }
        void reserve(size_t sz)
        {
            if (sz < capacity()) return;
            size_t new_size = capacity() == 0 ? 4 : capacity();
            while (new_size < sz) new_size *= 2;
            iterator tmp = new T[new_size]{};
            if (!tmp) { printf("new error."); return; }
            size_t old_size = size();
            if (old_size > 0)
            {
                for (size_t i = 0; i < old_size; ++i)
                    tmp[i] = std::move(_start[i]); // 如果 T 支持移动，这里会很高效
                delete[] _start;
            }
            _start = tmp;
            _finish = tmp + old_size;
            _end_of_storage = tmp + new_size;
        }
        iterator insert(iterator pos, const T& value)
        {
            size_t len = pos - _start;
            if (len > size()) return iterator();
            if (_finish == _end_of_storage)
            {
                reserve(capacity() + 1);
                pos = _start + len;
            }
            iterator cur = _finish;
            while (cur >= _start && cur != pos)
            {
                *(cur) = *(cur - 1);
                cur--;
            }
            *cur = value;
            _finish++;
            return pos;
        }
        iterator insert(iterator pos, T&& value)
        {
            size_t len = pos - _start;
            if (len > size()) return iterator();
            if (_finish == _end_of_storage)
            {
                reserve(capacity() + 1);
                pos = _start + len;
            }
            iterator cur = _finish;
            while (cur >= _start && cur != pos)
            {
                *(cur) = *(cur - 1);
                cur--;
            }
            *cur = std::move(value);
            // *cur = value;
            _finish++;
            return pos;
        }
        iterator erase(iterator pos)
        {
            if (pos > _finish) return;
            size_t len = pos - _start;
            while (pos + 1 != _finish) *pos = *(pos + 1), pos++;
            _finish--;
            return _start + len;
        }
        void resize(size_t sz, const T& value = T())
        {
            if (sz < size()) { _finish = _start + sz; return; }
            reserve(sz);
            while (_finish != _start + sz)
            {
                *_finish = value;
                ++_finish;
            }
        }
        void pop_back()
        {
            iterator pos = end() - 1;
            erase(pos);
        }
        void push_back(const T& value) { insert(end(), value); }
        void push_back(T&& value) { insert(end(), std::move(value)); }
    private:
        iterator _start = nullptr;
        iterator _finish = nullptr;
        iterator _end_of_storage = nullptr;
    };
}