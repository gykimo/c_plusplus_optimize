#include "common.h"

class TestClass
{
public:
    int arr0;
    int arr1;
    int arr2;
    int arr3;
    int arr4;
    int arr5;
    int arr6;
    int arr7;
    int arr8;
    int arr9;
};

TestClass c;

int main()
{
    for (int i = 0; i < LOOP_SIZE; i++)
    {
        c.arr0 = 0;
        c.arr1 = 1;
        c.arr2 = 2;
        c.arr3 = 3;
        c.arr4 = 4;
        c.arr5 = 5;
        c.arr6 = 6;
        c.arr7 = 7;
        c.arr8 = 8;
        c.arr9 = 9;
    }
}