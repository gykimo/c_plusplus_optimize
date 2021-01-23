#include "common.h"

int main()
{
    vector<TestClass> v(COUNT);

    for (int i = 0; i < COUNT; i++)
    {
        v[i] = TestClass();
    }
}