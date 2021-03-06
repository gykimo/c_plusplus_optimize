
#include "common.h"

// Document if a class/type is a lockable type (such as the Mutex class).
class __attribute__((lockable)) GlobalLockPod
{
public:
    void Lock()
    {
        while (__sync_val_compare_and_swap(&lock_acquired, 0, 1))
        {
            sched_yield();
        }
    }

    void Unlock()
    {
        int old_value = __sync_val_compare_and_swap(&lock_acquired, 1, 0);
    }

    volatile int lock_acquired;
};

GlobalLockPod lock_;

static void exec()
{
    for (int i = 0; i < COUNT; i++)
    {
        lock_.Lock();
        count_++;
        lock_.Unlock();
    }
}

int main()
{
    test(exec);
}