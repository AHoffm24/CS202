#include <iostream>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "matrix.h"
using namespace std;
/*-----------------------------------------------
Default constructor: creates an empty matrix
-----------------------------------------------*/
matrix::matrix()
{ // this works
	rows = 0;
	columns = 0;
	element = NULL;
}
/*-----------------------------------------------
CONSTRUCTOR
PARAMETERS: r = rows, c = columns, int ** a = 2 dimensional array
POSTCONDITION/RESULT: takes a 2 dimensional array and creates a 2 dimensional linked list
-----------------------------------------------*/
matrix::matrix(size_t r, size_t c, int ** a)
{ //this works
	rows = r;
	columns  = c;
	element = new LinkedList<int>[rows];
	for(int i = 0; i < rows; i++)
	{
	    for(int j = 0; j < columns; j++)
	    {
	    element[i].insert_back(a[i][j]);
	    }
	}
}
/*-----------------------------------------------
CONSTRUCTOR
PARAMETERS: r = rows, c = columns
POSTCONDITION/RESULT: returns matrix filled with zeros that is matrix[r][c]
-----------------------------------------------*/
matrix::matrix(size_t r, size_t c)
{ // this works
	rows = r;
	columns  = c;
	element = new LinkedList<int>[rows];
	for(int i = 0; i < rows; i++)
	{
	    for(int j = 0; j < columns; j++)
	    {
	    element[i].insert_back(0);
	    }
	}
}
/*-----------------------------------------------
COPY CONSTRUCTOR
PARAMETERS: matrix to be copied
POSTCONDITION/RESULT: rows = copy.rows
			 	   columns = copy.columns
				    matrix = copy.matrix
-----------------------------------------------*/
matrix::matrix(const matrix& copy)
{ // this works
		rows = copy.rows;
		columns = copy.columns;
		element = new LinkedList<int>[rows];
	    LinkedList<int>::iterator it;       //how to create a iterators for LL
	    //this or the onebelow. // could avoid using iteratory by using copy constructor
	    for(int i = 0; i < rows; i++)
	    {
	        it = copy.element[i].begin();
	        for(int j = 0; j < columns; j++)
	        {
	            element[i].insert_back(*it);
	            it++;
	        }
	    }
}
/*-----------------------------------------------
ASSIGNMENT OPERATOR
PARAMETERS: result, rhs matrix
POSTCONDITION/RESULT: sets the matrix from the right hand sides and returns
it to the result matrix in main.
-----------------------------------------------*/
const matrix& matrix::operator=(const matrix& rhs)
{ //good
	// think this works
	if (this != &rhs)
	{
		if (element != NULL)
		{
			//deallocate memory
			for(int i = 0; i < rows; i++)
			{
				element[i].destroyList();
			}
			delete [] element;
		}
		rows = rhs.rows;
		columns = rhs.columns;
		element = new LinkedList<int>[rows];
		LinkedList<int>::iterator it;
		for(int j = 0; j < rows; j++)
		{
			it = rhs.element[j].begin();
			for(int k = 0; k < columns; k++)
			{
			element[j].insert_back(*it);
			it++;
			}
		}
	}
	return *this;
}
/*-----------------------------------------------
DESTRUCTOR: Deallocates the dynamic memory
-----------------------------------------------*/
matrix::~matrix()
{ //good
	//what he gave us
	if(element != NULL)
	{
		for(int i = 0; i < rows; i++)
		{
			element[i].destroyList();
		}
		delete [] element;
	}
}
/*-----------------------------------------------
FUNCTION NAME: operator*
PARAMETERS: matrix rhs
POSTCONDITION/RESULT: returns matrix lhs * matrix rhs
-----------------------------------------------*/
matrix matrix::operator*(const matrix& rhs) const
{ // look how to multiply a matricy
	//broken

	if (columns != rhs.rows)
	{
		matrix temp;
		return temp;
	}
	matrix temp(rows, rhs.columns);
	LinkedList<int>::iterator it;
	LinkedList<int>::iterator it2;
	LinkedList<int>::iterator it3;
	for(int i = 0; i < temp.rows; i++)
	{
		it3 = temp.element[i].begin();
		for(int j = 0; j < temp.columns; j++)
		{
			for(int k = 0; k < columns; k++)
			{
				it = element[i].begin();
				it2 = rhs.element[k].begin();
				for(int x = 0; x < k; x++)
					it++;

				for(int x = 0; x < j; x++)
					it2++;
				temp.element[i].reassign(it3, *it3 + (*it * *it2));
			}

			it3++;

		}
	}
	// multiply by matricy
	return temp;
}
/*-----------------------------------------------
FUNCTION NAME:operator+
PARAMETERS: matrix origional, matrix rhs
POSTCONDITION/RESULT: creates a temp matrix, and
adds element[i][j] + rhs.element[i][j] = temp.element[i][j]
returns temp.

-----------------------------------------------*/
matrix matrix::operator+(const matrix& rhs) const
{ //does not work yet
	int hold;
	if (rhs.rows != rows || rhs.columns != columns)
	{//this part works
		matrix temp;
		return temp;
	}
	//not adding last row
	matrix temp(rhs.rows, rhs.columns);
	LinkedList<int>::iterator it;
	LinkedList<int>::iterator it2;
	LinkedList<int>::iterator it3;
	for (int i = 0; i  < temp.rows; i++)
	{
		it = element[i].begin();
		it2 = rhs.element[i].begin();
		it3 = temp.element[i].begin();
		for(int j = 0; j < temp.columns; j++)
		{
			temp.element[i].reassign(it3, (*it+*it2));
			it++;
			it2++;
			it3++;
		}
	}
	return temp;
	// matrix[i][j] + rhs.matrix [i][j]
}
/*-----------------------------------------------
FUNCTION NAME: operator*
PARAMETERS: matrix, int rhs to be multiplied.
POSTCONDITION/RESULT: multiple each member of the matrix by rhs and return;
-----------------------------------------------*/
matrix matrix::operator*(int rhs) const
	{ // this works
	int hold;
	matrix temp(rows, columns);
	LinkedList<int>::iterator it;

	for(int i = 0; i < temp.rows; i++)
	{
		it = element[i].begin();

		for(int j = 0; j < temp.columns; j++)
		{
		hold = rhs * *it;
		temp.element[i].insert_back(hold);
		temp.element[i].remove_front();
		it++;
		}
	}
	return temp;
	// matrix * 4

}
/*-----------------------------------------------
FUNCTION NAME: operator*
PARAMETERS: integer to be multiplied by each member element of the matrix,
			matrix rhs
POSTCONDITION/RESULT: returns new matrix, with int * matrix[i][j]
-----------------------------------------------*/
matrix operator*(int lhs, const matrix& rhs)
{ // this works
	int hold;
	matrix temp(rhs.rows, rhs.columns);
	// 4 * matrix[]
	LinkedList<int>::iterator it;
	LinkedList<int>::iterator it2;

	for(int i = 0; i < rhs.rows; i++)
	{
		it = rhs.element[i].begin();
		it2 = temp.element[i].begin();

		for(int j = 0; j < rhs.columns; j++)
		{
			hold = (lhs * (*it));
			temp.element[i].reassign(it2, (lhs * *it));
			it++;
			it2++;
		}
	}
	return temp;
}
/*-----------------------------------------------
FUNCTION NAME: output operator<<
PARAMETERS: ostream out, matrix to be printed
POSTCONDITION/RESULT: returns ostream out that will printed
the matrix that prints as the matrix should look.
i.e {1, 2, 3}{3, 3, 3}
example output:	1 2 3
				3 3 3
-----------------------------------------------*/
ostream& operator<<(ostream& out, const matrix& rhs)
{ //this works

LinkedList<int>::iterator it;
for(int i = 0; i < rhs.rows; i++)
{
	it = rhs.element[i].begin();
	for(int j = 0; j < rhs.columns; j++)
	{
		out << setw(5) << setfill(' ') << left << *it;
		it++;
	}
	out << endl;
}
	return out;
}
