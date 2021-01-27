#include "common.h"

inline int add(int num, int delta)
{
    return num + delta;
}

int main()
{
    int num = 0;

    for (int i = 0; i < COUNT; i++)
    {
        num=add(num, 1);
    }
    return 0;
}