#include "common.h"

int arr[ARRAY_SIZE];

int main()
{
    for (int i = 0; i < LOOP_SIZE; i++)
    {
        for (int j = 0; j < ARRAY_SIZE; j++)
        {
            arr[j] = j;
        }
    }
}