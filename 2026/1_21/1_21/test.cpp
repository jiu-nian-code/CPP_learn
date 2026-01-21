#include<thread>
#include<iostream>
#include<functional>
#include<mutex>

namespace jiunian
{
    class lock_guard
    {
        std::mutex& _mt;
    public:
        lock_guard(std::mutex& mt) : _mt(mt) { _mt.lock(); }
        ~lock_guard() { _mt.unlock(); }
    };
}

std::mutex mt;

void print_even(int x) {
    if (x % 2 == 0) std::cout << x << " is even\n";
    else throw (std::logic_error("not even"));
}

void print_thread_id(int id)
{
    try
    {
        std::unique_lock<std::mutex> lock(mt);
        print_even(id);
    }
    catch (std::logic_error&)
    {
        std::cout << "[exception caught]\n";
    }
}

int main()
{
    std::thread threads[10];
    for (int i = 0; i < 10; ++i)
        threads[i] = std::thread(print_thread_id, i + 1);
    for (auto& th : threads) th.join();
    return 0;
}