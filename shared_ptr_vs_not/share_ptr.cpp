#include "common.h"

class Child
{
public:
    int attr_;
};

class Parant_SharePtr
{
public:
    shared_ptr<Child> c;
};

int main()
{
    Parant_SharePtr p1;
    p1.c.reset(new Child());

    Parant_SharePtr p2;
    for (int i = 0; i < COUNT; i++)
    {
        p2 = p1;
    }
    return 0;
}