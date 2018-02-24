#include <iostream>
#include <cstdlib>
using namespace std;

const size_t LENGTH1 = 10;
const size_t LENGTH2 = 20;
int main()
{
	int * arr;
	//Allocate a dynamic array of length 10
	arr = new int[LENGTH1];

	for (int i = 0; i < LENGTH1; i++)
		arr[i] = (rand() % 10) + 1;

	for (int i = 0; i < LENGTH1; i++)
		cout << arr[i] << " ";
	cout << endl;

	//Let's resize the array

	int * tmp_array;

	tmp_array = new int[LENGTH2]; //create an array of length 20

	//We need to copy the old array into this new array
	for (int i = 0; i < LENGTH1; i++)
		tmp_array[i] = arr[i];

	//Now we need to deallocate the old array
	delete [] arr;

	arr = tmp_array; //now arr has been properly resized from 10 elements to 20 elements
	tmp_array = NULL; //just for good measure

	//populate the new elements
	for (int i = LENGTH1; i < LENGTH2; i++)
		arr[i] = (rand() % 10) + 1;

	for (int i = 0; i < LENGTH2; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}
