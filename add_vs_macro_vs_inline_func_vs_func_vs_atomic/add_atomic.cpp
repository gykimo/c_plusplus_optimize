#include "common.h"

int main()
{
    int num = 0;

    for (int i = 0; i < COUNT; i++)
    {
        __sync_add_and_fetch(&num, 1);
    }
    return 0;
}