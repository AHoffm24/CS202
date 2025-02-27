//Binary calculator 
#include <iostream>
#include "binNumber.h"
using namespace std;

int main()
{
	binNumber b1("1000000");
	binNumber b2("00100");
	binNumber b3("100");
	binNumber result;

	result = b1 + b2;
	cout << result << endl;

	result = b1 - b2;
	cout << result << endl;

	result = b3 - b2;
	cout << result << endl;

	result = b3 - b2;
	cout << result << endl;

	b3 = "11111111111";
	b2 = "11111111111";
	result = b3 - b2;
	cout << result << endl;

	result = b2 + b3;
	cout << result << endl;

	b1 = "1111111111111111111111111111111";
	b1 = b1 + "1";
	cout << b1 << endl;

	b3 = "1000000000000000000000000000000";
	b3 = b3 - "1";
	cout << b3 << endl;

	b1 = "00001001011101011110011";
	b2 = "1000011111000011100000110";
	result = b1 + b2;
	cout << result << endl;

	result = b2 - b1;
	cout << result << endl;

	b1 = "101010101010101010101010101010101";
	b2 = "00000001";

	result = b1 - b2;
	cout << result << endl;

	if (b1 > b2)
		cout << "b1 is larger than b2" << endl;

	b3 = "101010101010101010101010101010101";

	if (b1 == b3)
		cout << "b1 equals b3" << endl;

	b1 = b1 - "000001";;

	if (b1 < b3)
		cout << "b1 is less than b3" << endl;

	if (!(b1 > b3))
		cout << "b1 is not greater than b3" << endl;

	b2 = b3;

	if (b2 <= b3)
		cout << "b2 is less than or equal to b3" << endl;

	if (b3 >= b2)
		cout << "b3 is greater than or equal to b2" << endl;

	b3 = "10101010";
	b2 = "10101011";

	if (b3 != b2)
		cout << "b3 is not equal to b2" << endl;

	result = "01001001" + b3;
	cout << result << endl;

	result = "0101000011001100111" - b2;
	cout << result << endl;

	return 0;
}
