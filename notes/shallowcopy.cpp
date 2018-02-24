#include <iostream>
#include <cstdlib>
using namespace std;

class bag
{
public:
  bag();
  bag(int);
  int getAt(int) const;
  void setAt(int, int);
  void resize(int);
  int get_length() const;
  friend ostream& operator<<(ostream&, const bag&);
private:
  int length;
  int * lst;
};

bag::bag()
{
  lst = NULL;
  length = 0;
}

bag::bag(int size)
{
  lst = new int[size];
  length = size;
}

int bag::getAt(int position) const
{
  if (lst == NULL)
    return 0;

  if (position >= 0 && position < length)
    return lst[position];
  else
    return 0;
}

void bag::setAt(int position, int value)
{
  if (lst == NULL)
    return;

  if (position < 0 || position >= length)
    return;

  lst[position] = value;
}

void bag::resize(int amount)
{
  int * tmp;

  length += amount;
  tmp = new int[length];
  for (int i = 0; i < length; i++)
    tmp[i] = lst[i];
  delete [] lst;
  lst = tmp;
}

int bag::get_length() const
{
  return length;
}

ostream& operator<<(ostream& out, const bag& b)
{
  if (b.lst == NULL)
    out << "";
  else
    {
      for (int i = 0; i < b.length; i++)
	out << b.lst[i] << " ";
    }
  return out;
}

int main()
{
  bag b1(5);
  for (int i = 0; i < b1.get_length(); i++)
    b1.setAt(i, rand() % 5);

  cout << "Initial b1" << endl << b1 << endl;

  b1.resize(5);

  for (int i = 5; i < b1.get_length(); i++)
    b1.setAt(i, rand() % 5);

  cout << "b1 resized" << endl << b1 << endl;

  bag b2(b1); //shallow copy

  cout << "after copy constructor" << endl;
  cout << "b1: " << b1 << endl;
  cout << "b2: " << b2 << endl;

  b2.setAt(0, 100);
  cout << "After b2 setAt index 0 to 100" << endl;
  cout << "b1: " << b1 << endl;
  cout << "b2: " << b2 << endl;

  b1.setAt(1, 200);
  cout << "After setting b1 index 1 to 200" << endl;
  cout << "b1: " << b1 << endl;
  cout << "b2: " << b2 << endl;

  bag b3;

  b3 = b1; //shallow copy
  cout << "b3 = b1" << endl;
  cout << "b1: " << b1 << endl;
  cout << "b2: " << b2 << endl;
  cout << "b3: " << b3 << endl;

  b3.setAt(2, 300);
  cout << "Set b3 index 2 to 300" << endl;
  cout << "b1: " << b1 << endl;
  cout << "b2: " << b2 << endl;
  cout << "b3: " << b3 << endl;

  return 0;
}
