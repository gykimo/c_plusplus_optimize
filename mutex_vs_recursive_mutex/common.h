#include <thread>
#include <functional>
#include <iostream>
#include <unistd.h>

using namespace std;

const int COUNT = 1000 * 1000 * 10;
const int THREAD_COUNT = 2;
int count_ = 0;

void test(std::function<void()> func)
{
    thread *threads[THREAD_COUNT] = {0};

    for (int i = 0; i < THREAD_COUNT; i++)
    {
        threads[i] = new thread(func);
    }

    for (int i = 0; i < THREAD_COUNT; i++)
    {
        threads[i]->join();
    }

    if (count_ == COUNT * THREAD_COUNT)
    {
        //cout << "ok, count: " << count_ << endl;
    }
    else
    {
        cout << "fail, count: " << count_ << endl;
    }
}