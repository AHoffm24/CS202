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
{
rows = 0;
columns = 0;
element = NULL;
}
/*-----------------------------------------------
CONSTRUCTOR
PARAMETERS:
POSTCONDITION/RESULT:
-----------------------------------------------*/
matrix::matrix(size_t r, size_t c, int ** a)
{
 rows = r;
 columns = c;
 element = new int*[rows];

 for(int i = 0; i < rows; i++)
 {
	 element[i] = new int[columns];

	 for(int j = 0; j < columns; j++)
	 {
		 element[i][j] = a[i][j];
	 }
 }
}
/*-----------------------------------------------
CONSTRUCTOR
PARAMETERS:
POSTCONDITION/RESULT:
-----------------------------------------------*/
matrix::matrix(size_t r, size_t c)
{
rows = r;
columns = c;
element = new int*[rows];
for(int i = 0; i < rows; i++)
{
	element[i] = new int[columns];
}

}
/*-----------------------------------------------
COPY CONSTRUCTOR
PARAMETERS:
POSTCONDITION/RESULT:
-----------------------------------------------*/
matrix::matrix(const matrix& copy)
{
rows = copy.rows;
columns = copy.columns;
if (copy.element == NULL)
	{
		element = NULL;
		return;
	}
else
element = new int*[rows];
for (int i = 0; i < rows; i++)
{
	element[i] = new int[columns];
	for(int j = 0; j < columns; j++)
	{
		element[i][j] = copy.element[i][j];
	}
}
}
/*-----------------------------------------------
ASSIGNMENT OPERATOR
PARAMETERS:
POSTCONDITION/RESULT:
-----------------------------------------------*/
const matrix& matrix::operator=(const matrix& rhs)
{
	if (this != &rhs)
	{

		if(element != NULL)
		{
			for(int i = 0; i < rows; i++)
			{
				delete [] element[i];
			}
			delete [] element;
		}
        rows = rhs.rows;
        columns = rhs.columns;
		element = new int*[rows];
		for(int n = 0; n < rows; n++)
		{
			element[n] = new int[columns];
        }
        for(int k = 0; k < rows; k++)
        {
			for(int j = 0; j < columns; j++)
			{
				element[k][j] = rhs.element[k][j];
			}
		}
	}

	return *this; //LEAVE THIS PART IN
}
/*-----------------------------------------------
DESTRUCTOR: Deallocates the dynamic memory
-----------------------------------------------*/
matrix::~matrix()//if getting seg fault exit out
{
	if(element != NULL)
	{
		for(int i = 0; i < rows; i++)
		{
			delete [] element[i];
		}
		delete [] element;
		element = NULL;
	}
}
/*-----------------------------------------------
FUNCTION NAME:
PARAMETERS:
POSTCONDITION/RESULT:
-----------------------------------------------*/
matrix matrix::operator*(const matrix& rhs) const
{
	if(columns != rhs.rows)
		{
			matrix temp;
			return temp; //empty matrix
		}
    if(element == NULL || rhs.element == NULL)
        {
            matrix temp;
            return temp;
        }
	matrix temp(rows, rhs.columns);

	for (int y = 0; y < temp.rows; y++)
	{
		for (int z = 0; z < temp.columns; z++)
		{
			temp.element[y][z] = 0;
		}
	}
	for(int i = 0; i < temp.rows; i++)
	{
		for(int j = 0; j < temp.columns; j++)
		{
			for(int k = 0; k < columns; k++)
			{
		 		temp.element[i][j] += element[i][k] * rhs.element[k][j];
			}
		}
	}
	return temp;
}
/*-----------------------------------------------
FUNCTION NAME:
PARAMETERS:
POSTCONDITION/RESULT:
-----------------------------------------------*/
matrix matrix::operator+(const matrix& rhs) const
{
	if(rows != rhs.rows || columns != rhs.columns || element == NULL)
		{
			matrix temp;
			return temp; //empty matrix
		}

	matrix temp(rows, columns);

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			temp.element[i][j] = element[i][j] + rhs.element[i][j];
		}
	}
	return temp;
}
/*-----------------------------------------------
FUNCTION NAME:
PARAMETERS:
POSTCONDITION/RESULT:
-----------------------------------------------*/
matrix matrix::operator*(int rhs) const
{
	if(element == NULL)
	{
		matrix temp;
		return temp;
	}

	matrix temp(rows, columns);

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns;j++)
		{
			temp.element[i][j] = element[i][j] * rhs;
		}
	}
	return temp;
}
/*-----------------------------------------------
FUNCTION NAME:
PARAMETERS:
POSTCONDITION/RESULT:
-----------------------------------------------*/
matrix operator*(int lhs, const matrix& rhs)
{
	if(rhs.element == NULL)
	{
		matrix temp;
		return temp;
	}

	matrix temp(rhs.rows, rhs.columns);

	for(int i = 0; i < rhs.rows; i++)
	{
		for(int j = 0; j < rhs.columns; j++)
		{
		temp.element[i][j] = lhs * rhs.element[i][j];
		}
	}
	return temp;
}
/*-----------------------------------------------
FUNCTION NAME:
PARAMETERS:
POSTCONDITION/RESULT:
-----------------------------------------------*/
ostream& operator<<(ostream& out, const matrix& rhs)
{

    for(int i = 0; i < rhs.rows; i++)
    {
        for(int j = 0; j < rhs.columns; j++)
        {
		out << rhs.element[i][j] << " " ;
        }
        out << endl;
    }

	//YOUR CODE COMES ABOVE THE RETURN STATEMENT
	return out; //LEAVE THIS PART IN
}
