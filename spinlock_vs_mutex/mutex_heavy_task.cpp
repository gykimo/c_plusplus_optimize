#include <mutex>
#include <stdlib.h>
#include "common.h"

static mutex lock_;

static void exec()
{
    int mem_len = 1024 * 1024 * 4;

    for (int i = 0; i < 10000; i++)
    {
        lock_.lock();

        count_++;
        void *mem = malloc(mem_len);
        memset(mem, 0, mem_len);
        free(mem);

        lock_.unlock();
    }
}

int main()
{
    test(exec);
}