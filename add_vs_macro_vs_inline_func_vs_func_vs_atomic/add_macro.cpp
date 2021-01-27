#include "common.h"

#define add( a, b) a+b

int main()
{
    int num = 0;

    for (int i = 0; i < COUNT; i++)
    {
        num = add(num, 1);
    }
    return 0;
}