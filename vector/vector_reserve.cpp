#include "common.h"

int main()
{
    vector<TestClass> v;
    v.reserve(COUNT);

    for (int i = 0; i < COUNT; i++)
    {
        v[i] = TestClass();
    }
}