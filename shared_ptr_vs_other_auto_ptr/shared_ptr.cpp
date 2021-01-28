#include <memory>

#include "common.h"

using namespace std;

class TestClass
{
public:
    int attr_;
};

int main()
{
    shared_ptr<TestClass> p1(new TestClass());

    for (int i = 0; i < COUNT; i++)
    {
        shared_ptr<TestClass> p2 = p1;
    }
}