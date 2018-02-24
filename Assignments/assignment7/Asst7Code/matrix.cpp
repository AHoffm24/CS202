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
	
}
/*-----------------------------------------------
CONSTRUCTOR
PARAMETERS:
POSTCONDITION/RESULT:
-----------------------------------------------*/
matrix::matrix(size_t r, size_t c, int ** a)
{
	
}
/*-----------------------------------------------
CONSTRUCTOR
PARAMETERS:
POSTCONDITION/RESULT:
-----------------------------------------------*/
matrix::matrix(size_t r, size_t c)
{
	
}
/*-----------------------------------------------
COPY CONSTRUCTOR
PARAMETERS:
POSTCONDITION/RESULT:
-----------------------------------------------*/
matrix::matrix(const matrix& copy)
{
	
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
		//YOUR CODE COMES HERE
	}
	return *this; //LEAVE THIS PART IN
}
/*-----------------------------------------------
DESTRUCTOR: Deallocates the dynamic memory
-----------------------------------------------*/
matrix::~matrix()
{
	
}
/*-----------------------------------------------
FUNCTION NAME:
PARAMETERS:
POSTCONDITION/RESULT:
-----------------------------------------------*/
matrix matrix::operator*(const matrix& rhs) const
{
	
}
/*-----------------------------------------------
FUNCTION NAME:
PARAMETERS:
POSTCONDITION/RESULT:
-----------------------------------------------*/
matrix matrix::operator+(const matrix& rhs) const
{
	
}
/*-----------------------------------------------
FUNCTION NAME:
PARAMETERS:
POSTCONDITION/RESULT:
-----------------------------------------------*/
matrix matrix::operator*(int rhs) const
{	
	
}
/*-----------------------------------------------
FUNCTION NAME:
PARAMETERS:
POSTCONDITION/RESULT:
-----------------------------------------------*/
matrix operator*(int lhs, const matrix& rhs)
{
	
}
/*-----------------------------------------------
FUNCTION NAME:
PARAMETERS:
POSTCONDITION/RESULT:
-----------------------------------------------*/
ostream& operator<<(ostream& out, const matrix& rhs)
{
	//YOUR CODE COMES ABOVE THE RETURN STATEMENT
	return out; //LEAVE THIS PART IN
}