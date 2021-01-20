#include <map>

#include "common.h"

using namespace std;

static map<int, int> map_;

int main()
{
    for (int i = 0; i < COUNT; i++)
    {
        map_[i] = i;
    }

    int v = 0;
    for (int i = 0; i < COUNT; i++)
    {
        v = map_[i];
    }
}