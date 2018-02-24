#include <iostream>
using namespace std;

class foo /*class functions, check notes from day 2 for better understanding of class vs structs*/
{

  public:
    void set(int x_param)
    {
      x = x_param;
    }
    int get()
    {
      return x;
    }
  private:
    int x;
};

int main()
{
  foo f1;
  f1.set(11);

  foo f2;
  f2.set(12);

  cout << "f1: " << f1.get() << endl;
  cout << "f2: " << f2.get() << endl;

  return 0;
}
