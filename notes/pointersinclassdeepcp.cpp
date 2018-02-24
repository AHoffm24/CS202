#include <iostream>
#include <cstdlib>
using namespace std;

class bag
{
public:
  bag();
  bag(int);

  //RULE OF 3
  //You must have these implemented since there is a pointer variable in the class
  bag(const bag&); //copy constructor
  ~bag(); //Destructor
  bag& operator=(const bag&); //assignment operator
  /////////////////////////////////

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
//////////////////////////////////////////////////
//bag b2(b1);

//copy constructor that will perform a deep copy of the object
bag::bag(const bag& copy)
{

  length = copy.length;

  lst = new int[length];
  for (int i = 0; i < length; i++)
    lst[i] = copy.lst[i];
}
/*------------------------------------------------
Destructor
This gets called when the object goes out of scope,
i.e. the object gets destroyed, this will deallocate
any dynamic memory

Each class can only have 1 destructor and it takes no
parameters
------------------------------------------------*/
bag::~bag()
{
  if (lst != NULL)
    delete [] lst;
}

//bag b3;
//b3 = b1;
//b3.operator=(b1);

//b1 = b1;
//b1 = b2 = b3 = b4;

//Our custom assignment operator to perform a deep copy
bag& bag::operator=(const bag& rhs)
{
  if (this != &rhs)
    {
      length = rhs.length;

      if (lst != NULL)
	delete [] lst;

      lst = new int[length];

      for (int i = 0; i < length; i++)
	lst[i] = rhs.lst[i];
    }

  return *this;
}
///////////////////////////////////////////////
//cout << b1.getAt(0) << endl;

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
  if (position < 0 || position >= length)
    return;
  if (lst == NULL)
    return;

  lst[position] = value;
}

void bag::resize(int amount)
{
  int * tmp;

  length += amount;
  tmp = new int[amount + length];
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
  for (int i = 0; i < 5; i++)
    b1.setAt(i, rand() % 5);

  cout << "b1 initial" << endl;
  cout << "b1: " << b1 << endl;

  b1.resize(5);
  for (int i = 5; i < b1.get_length(); i++)
    b1.setAt(i, rand() % 5);

  cout << "b1 after resizing" << endl;
  cout << "b1: " << b1 << endl;

  bag b2(b1);
  cout << "copy constructor" << endl;
  cout << "b1: " << b1 << endl;
  cout << "b2: " << b2 << endl;

  b1.setAt(0, 100);
  cout << "b1.setAt(0, 100);" << endl;
  cout << "b1: " << b1 << endl;
  cout << "b2: " << b2 << endl;

  b2.setAt(1, 200);
  cout << "b2.setAt(1, 200);" << endl;
  cout << "b1: " << b1 << endl;
  cout << "b2: " << b2 << endl;

  bag b3;
  b3 = b2;

  cout << "b3 = b2;" << endl;
  cout << "b1: " << b1 << endl;
  cout << "b2: " << b2 << endl;
  cout << "b3: " << b3 << endl;

  b3.setAt(2, 300);
  cout << "b3.setAt(2, 300);" << endl;
  cout << "b1: " << b1 << endl;
  cout << "b2: " << b2 << endl;
  cout << "b3: " << b3 << endl;

  b2.setAt(3, 400);
  cout << "b2.setAt(3, 400);" << endl;
  cout << "b1: " << b1 << endl;
  cout << "b2: " << b2 << endl;
  cout << "b3: " << b3 << endl;


  return 0;
}
