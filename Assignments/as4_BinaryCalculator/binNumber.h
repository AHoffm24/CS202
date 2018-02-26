#include <iostream>
#include <string>
using namespace std;

class binNumber
{
public:
	binNumber();
	binNumber(string);
	binNumber& operator=(string);
	binNumber operator+(const binNumber&) const;
	binNumber operator+(string) const;
	binNumber operator-(const binNumber&) const;
	binNumber operator-(string) const;

	bool operator==(const binNumber&) const;
	bool operator!=(const binNumber&) const;
	bool operator<(const binNumber&) const;
	bool operator>(const binNumber&) const;
	bool operator<=(const binNumber&) const;
	bool operator>=(const binNumber&) const;

	friend binNumber operator+(string, const binNumber&);
	friend binNumber operator-(string, const binNumber&);
	friend ostream& operator<<(ostream&, const binNumber&);

private:
	string numString;
};

/*left Number will always be bigger than right number. Will not deal with
negative numbers. Only subtracting one number by another, and the answer will always be positive.
*/

/*
 100001
 + 1001
=101010

binNumber b1("01101")
binNumber b2(" 110")
numstring.erase(0,1) // will erase the first char in the string until the first character in the string is not a zero anymore.
b1 numstring = "1101"
b2 numstring = "110"

binNumber binNumber :: operator+ (const binNumber& bNum)
 1101         11111
+ 110		+ 00001
C1000  carry  10000
 10011		 100000


*/
