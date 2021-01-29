#include <mutex>

#include "common.h"

static recursive_mutex lock_;

static void exec()
{
    for (int i = 0; i < COUNT; i++)
    {
        lock_.lock();
        count_++;
        lock_.unlock();
    }
}

int main()
{
    test(exec);
}