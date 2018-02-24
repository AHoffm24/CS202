pointers in class(allocate memory to them)

know why copy constructors exist - avoid shallow copying/ to create a deep copy
assignment operator - avoid shallow copying

destructor - avoid memory leaks

inheritance - "is a" relation - true false on difference between the 2
composition - "has a" relation -

important to know for inheritance
-Inheritance| public | protected | private
---------------------------------------------------
- public    | public | protected | N/A
---------------------------------------------------
- private   | private| Private   | N/a
---------------------------------------------------
//


//Public inheritance
class base
{
public:
    base(int x)
    {
        y = x;
    }
    int squared() //
    {
        return y*y;
    }
private:
    int y;
}

class derived : public base
{
public:
    derived(int x) : base (x)
    {
        //empty body because base class constructor
        //is called
    }
}
int main()
{
    derived d(4);
    cout << d.squared() << endl;
    //squared was copied into this class through public inheritance and can legally call it in main like below
    //will work because of public inheritance
}


//private inheritance
class base
{
public:
    base(int x)
    {
        y = x;
    }
    int squared() //
    {
        return y*y;
    }
private:
    int y;
}

class derived2 : private base //if you dont put
//private infront of base it will by default be
//private
{
public:
    derived2(int x) : base (x)
    {
        //empty body because base class constructor
        //is called
    }
      int squared() //function override example
      {
          return base::squared();
      }
      int squared(int z) //function overload example
      {
          return z * squared();
      }
}
int main()
{
    derived d(4);
    cout << d.squared() << endl;
    derived2 d2(3);
    cout << d2.squared()<<endl;
    // must create the squared class for d2
    //because of private inheritance
}
function overiding vs function overloading
overide: it always calls a function that was declared inside the function first, and then will look into the derived class if it cannot find it.

overloading: we have 2 functions of the same name
but with different parameters list. example above
with the int squared with and without a parameter.



3 basic princials of object oriented design(OOD)
1. Encapsulation
2. Inheritance
3. Polymorphism
//THIS WILL BE A QUESTION ON A TEST. MUST KNOW
//what everything is and be able to write an open
//ended answer

char c;
char *c;
c = 'a';
cPtr= &c; //cptr and c are now pointing at the same thing.
*cPtr = 'B';
cPtr = new char;
cPtr = new char;

dangling pointer//
int x
int *ptr
x = 3;
*ptr = x; //will crash program
*ptr = new int;
*ptr = x; //will not crash. Now = 3;

int *ptr2;
ptr2 = ptr;
ptr = x; //will fail
ptr = &x; // will work;
x = ptr2; //invalid
ptr = &ptr2; //invalid
