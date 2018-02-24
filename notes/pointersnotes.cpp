#include <iostream>
using namespace std;

void foo1(char*);
void foo2(char*);
void foo3(char*&);

int main()
{
	char * ch;
	ch = new char;
	*ch = 'A';

	foo1(ch);
	cout << *ch << endl; //prints out B

	*ch = 'A'; //resetting back to the original

	foo2(ch);
	cout << *ch << endl; //prints A

	foo3(ch);
	cout << *ch << endl; //prints B

	delete ch;

	return 0;
}

/*------------------------------------------------
Inside foo1, even though we are passing the pointer
by value, we can still dereference the pointer and
modify the character object that ch is pointing to
so after the function completes, ch points to an character
that contains the letter B
------------------------------------------------*/
void foo1(char * ch)
{
	*ch = 'B';
}

/*------------------------------------------------
Inside foo2, we are setting the pointer ch to a new
character, so basically modifying the contents of
a value parameter, so inside the function ch will
point to a character that contains the letter B,
after the function completes, the parameter ch will
reset and will point to the original character before
the function was called, so the character allocated
in this function will no longer be accessible and
it was not properly deallocated which causes a memory
leak
------------------------------------------------*/
void foo2(char * ch)
{
	ch = new char;
	*ch = 'B';

	delete ch; //will prevent memory leak
}
/*------------------------------------------------
Inside foo3, we are passing the pointer as a reference
parameter, so if we change what ch points to, it will
not reset back to what it pointed to originally, however
now we have a memory leak again because we didn't
deallocate the memory before assigning ch to a new
character
------------------------------------------------*/
void foo3(char *& ch)
{
	delete ch; //prevents memory leak

	ch = new char;
	*ch = 'B';
}
