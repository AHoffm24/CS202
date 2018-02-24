#include "binNumber.h"
#include <iostream>
#include <string>
using namespace std;
/*----------------------------------------------------
Default Constructor
PARAMETERS:
POSTCONDITION:
----------------------------------------------------*/
binNumber::binNumber()
{
numString = "0";
}
/*----------------------------------------------------
Constructor
PARAMETERS:
POSTCONDITION:
----------------------------------------------------*/
binNumber::binNumber(string literal)
{
int i = 0;
while(literal[0] == '0')
{
	literal.erase(0,1);
}
numString = literal;
}
/*----------------------------------------------------
OPERATOR OVERLOADED:
PARAMETERS:
POSTCONDITION:
----------------------------------------------------*/
binNumber& binNumber::operator=(string literal)
{
	//YOUR CODE COMES ABOVE THE RETURN STATEMENT
	while(literal[0] == '0')
	{
		literal.erase(0,1);
	}
	numString = literal;

	return *this; //KEEP THIS LINE IN
}
/*----------------------------------------------------
OPERATOR OVERLOADED:
PARAMETERS:
POSTCONDITION:
----------------------------------------------------*/
binNumber binNumber::operator+(const binNumber& bNum) const
{
	string num1 = numString;
	string num2 = bNum.numString;
	int carryover;
	if (num1.length() < num2.length())
	{
		while (num1.length() != num2.length())
		{
			num1 = "0" + num1;
		}
	}
	else
		while(num1.length() != num2.length())
		{
			num2 = "0" + num2;
		}
	carryover = 0;
	string sum;
	sum.resize(num1.length());
	for(int i = num1.length() - 1; i >= 0; i--)
	{
		int n1 = num1[i] - '0';
		int n2 = num2[i] - '0';
		int result = n1 + n2 + carryover;
		carryover = result / 2;
		result = result % 2;
		sum[i] = result + '0';
	}
	if (carryover > 0)
	{
		sum = "1" + sum;
	}
return binNumber(sum);

}
/*----------------------------------------------------
OPERATOR OVERLOADED:
PARAMETERS:
POSTCONDITION:
----------------------------------------------------*/
binNumber binNumber::operator+(string literal) const
{
	string num1 = numString;
	string num2 = literal;
	int carryover;
	if (num1.length() < num2.length())
	{
		while (num1.length() != num2.length())
		{
			num1 = "0" + num1;
		}
	}
	else
		while(num1.length() != num2.length())
		{
			num2 = "0" + num2;
		}
	carryover = 0;
	string sum;
	sum.resize(num1.length());
	for(int i = num1.length() - 1; i >= 0; i--)
	{
		int n1 = num1[i] - '0';
		int n2 = num2[i] - '0';
		int result = n1 + n2 + carryover;
		carryover = result / 2;
		result = result % 2;
		sum[i] = result + '0';
	}
	if (carryover > 0)
	{
		sum = "1" + sum;
	}
return binNumber(sum);
}
/*----------------------------------------------------
OPERATOR OVERLOADED:
PARAMETERS:
POSTCONDITION:
----------------------------------------------------*/
binNumber binNumber::operator-(const binNumber& bNum) const
{
	string num1 = numString;
	string num2 = bNum.numString;
	int result;
			while(num1.length() != num2.length())
			{
				num2 = "0" + num2;
			}

		string sum = num1;
		for(int i = 0; i < num1.length(); i++)
		{
			int n1 = num1[i] - '0';
			int n2 = num2[i] - '0';

			if (n2 > n1)
			{
				sum[i] = '1';
				int n = 1;
				while(sum[i - n] == '0')
				{
					sum[i - n] = '1';
					n++;
				}
				sum[i-n] = '0';
			}
			else
			{
				result = n1 - n2;
				sum[i] = result + '0';
			}
		}
		while(sum[1] == '0')
		{
			sum.erase(0,1);
		}
		

		return binNumber(sum);
}
/*----------------------------------------------------
OPERATOR OVERLOADED:
PARAMETERS:
POSTCONDITION:
----------------------------------------------------*/
binNumber binNumber::operator-(string literal) const
{
	string num1 = numString;
	string num2 = literal;
	int result;
			while(num1.length() != num2.length())
			{
				num2 = "0" + num2;
			}

		string sum = num1;
		for(int i = 0; i < num1.length(); i++)
		{
			int n1 = num1[i] - '0';
			int n2 = num2[i] - '0';

			if (n2 > n1)
			{
				sum[i] = '1';
				int n = 1;
				while(sum[i - n] == '0')
				{
					sum[i - n] = '1';
					n++;
				}
				sum[i-n] = '0';
			}
			else
			{
				result = n1 - n2;
				sum[i] = result + '0';
			}
		}
			while(sum[0] == '0')
			{
				sum.erase(0,1);
			}

		return binNumber(sum);
}
/*----------------------------------------------------
OPERATOR OVERLOADED:
PARAMETERS:
POSTCONDITION:
----------------------------------------------------*/
bool binNumber::operator==(const binNumber& bNum) const
{
	string num1 = numString;
	string num2 = bNum.numString;
	if (num1 == num2)
	 	return true;
	else
		return false;
}
/*----------------------------------------------------
OPERATOR OVERLOADED:
PARAMETERS:
POSTCONDITION:
----------------------------------------------------*/
bool binNumber::operator!=(const binNumber& bNum) const
{
	string num1 = numString;
	string num2 = bNum.numString;
	if (num1 == num2)
	 	return false;
	else
		return true;
}
/*----------------------------------------------------
OPERATOR OVERLOADED:
PARAMETERS:
POSTCONDITION:
----------------------------------------------------*/
bool binNumber::operator<(const binNumber& bNum) const
{
		string num1 = numString;
		string num2 = bNum.numString;
		if (num1 < num2)
		 	return true;
		else
			return false;
}
/*----------------------------------------------------
OPERATOR OVERLOADED:
PARAMETERS:
POSTCONDITION:
----------------------------------------------------*/
bool binNumber::operator>(const binNumber& bNum) const
{
	string num1 = numString;
	string num2 = bNum.numString;
	if (num1 > num2)
		return true;
	else
		return false;
}
/*----------------------------------------------------
OPERATOR OVERLOADED:
PARAMETERS:
POSTCONDITION:
----------------------------------------------------*/
bool binNumber::operator<=(const binNumber& bNum) const
{
string num1 = numString;
string num2 = bNum.numString;
if (num1 <= num2)
	return true;
else
	return false;
}
/*----------------------------------------------------
OPERATOR OVERLOADED:
PARAMETERS:
POSTCONDITION:
----------------------------------------------------*/
bool binNumber::operator>=(const binNumber& bNum) const
{
string num1 = numString;
string num2 = bNum.numString;
if (num1 >= num2)
	return true;
else
	return false;
}
/*----------------------------------------------------
OPERATOR OVERLOADED:
PARAMETERS:
POSTCONDITION:
----------------------------------------------------*/
binNumber operator+(string lhs, const binNumber& rhs)
{
string num1 = lhs;
string num2 = rhs.numString;
int carryover;
if (num1.length() < num2.length())
{
	while (num1.length() != num2.length())
	{
		num1 = "0" + num1;
	}
}
else
	while(num1.length() != num2.length())
	{
		num2 = "0" + num2;
	}
carryover = 0;
string sum;
sum.resize(num1.length());
for(int i = num1.length() - 1; i >= 0; i--)
{
	int n1 = num1[i] - '0';
	int n2 = num2[i] - '0';
	int result = n1 + n2 + carryover;
	carryover = result / 2;
	result = result % 2;
	sum[i] = result + '0';
}
if (carryover > 0)
{
	sum = "1" + sum;
}
return binNumber(sum);
}
/*----------------------------------------------------
OPERATOR OVERLOADED:
PARAMETERS:
POSTCONDITION:
----------------------------------------------------*/
binNumber operator-(string lhs, const binNumber& rhs)
{
string num1 = lhs;
string num2 = rhs.numString;
int result;
		while(num1.length() != num2.length())
		{
			num2 = "0" + num2;
		}

	string sum = num1;
	for(int i = 0; i < num1.length(); i++)
	{
		int n1 = num1[i] - '0';
		int n2 = num2[i] - '0';

		if (n2 > n1)
		{
			sum[i] = '1';
			int n = 1;
			while(sum[i - n] == '0')
			{
				sum[i - n] = '1';
				n++;
			}
			sum[i-n] = '0';
		}
		else
		{
			result = n1 - n2;
			sum[i] = result + '0';
		}
	}
	while(sum[1] == '0')
	{
		sum.erase(0,1);
	}

	return binNumber(sum);
}
/*----------------------------------------------------
OPERATOR OVERLOADED:
PARAMETERS:
POSTCONDITION:
----------------------------------------------------*/
ostream& operator<<(ostream& out, const binNumber& bNum)
{
	//YOUR CODE COMES ABOVE THE RETURN STATEMENT
	out << bNum.numString;
	return out; //LEAVE THIS LINE IN
}
