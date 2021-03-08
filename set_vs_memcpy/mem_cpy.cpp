#include "common.h"

int arr[ARRAY_SIZE];

int main()
{
    int arr2[ARRAY_SIZE];
    // for (int j = 0; j < ARRAY_SIZE; j++)
    // {
    //     arr2[j] = j;
    // }

    arr2[0] = 0;
    arr2[1] = 1;
    arr2[2] = 2;
    arr2[3] = 3;
    arr2[4] = 4;
    arr2[5] = 5;
    arr2[6] = 6;
    arr2[7] = 7;
    arr2[8] = 8;
    arr2[9] = 9;

    for (int i = 0; i < LOOP_SIZE; i++)
    {
        memcpy(arr, arr2, sizeof(arr2));
    }
}