#include "common.h"

const int ATTR_SIZE = 1000;

class Child
{
public:
    int attr_[ATTR_SIZE];
};

class Parant
{
public:
    Child c;
};

int main()
{
    Parant p1;
    Parant p2;
    for (int i = 0; i < COUNT; i++)
    {
        p2 = p1;
    }
    return 0;
}