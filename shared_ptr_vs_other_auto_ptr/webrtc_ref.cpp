#include "common.h"
#include "refcountedobject.h"
#include "scoped_ref_ptr.h"

using namespace std;

class TestClass
{
public:
    int attr_;
    virtual int AddRef() const = 0;
    virtual int Release() const = 0;
};

int main()
{
    rtc::scoped_refptr<TestClass> p1(new rtc::RefCountedObject<TestClass>());

    for (int i = 0; i < COUNT; i++)
    {
        rtc::scoped_refptr<TestClass> p2 = p1;
    }
}