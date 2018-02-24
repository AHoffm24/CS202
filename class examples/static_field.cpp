#include <iostream>
using namespace std;

class staticClass
{
public:
int get();
void set(int);
Private:
static int x;
}

int staticClass::x = 0;
}
int staticClass::get()
{
        return x;
}
void staticClass::set(int y)
{
        x = y;
}
int main()
{
        staticClass sc1;

        cout << sc1.get() << endl;
        return 0;
}
