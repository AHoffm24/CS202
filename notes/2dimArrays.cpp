#include <iostream>
#include <cstdlib>
using namespace std;

const size_t ROW1 = 3;
const size_t COL1 = 3;

const size_t ROW2 = 5;
const size_t COL2 = 5;

int main()
{
	int ** twoDim;

	twoDim = new int*[ROW1];

	for (int i = 0; i < ROW1; i++)
		twoDim[i] = new int[COL1];

	//At this point twoDim is now a 3 x 3 array

	//Now we will populate the matrix with random numbers
	for (int i = 0; i < ROW1; i++)
		for (int j = 0; j < COL1; j++)
			twoDim[i][j] = (rand() % 20) + 1;

	cout << "Original matrix" << endl;

	for (int i = 0; i < ROW1; i++)
	{
		for (int j = 0; j < COL1; j++)
			cout << twoDim[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	//Let's resize twoDim

	int ** tmp_array;

	tmp_array = new int*[ROW2];

	for (int i = 0; i < COL2; i++)
		tmp_array[i] = new int[COL2];

	//Now tmp_array is pointing to a 5 x 5 array

	//Copy the old array into the new array
	for (int i = 0; i < ROW1; i++)
		for (int j = 0; j < COL1; j++)
			tmp_array[i][j] = twoDim[i][j];

	//We have to deallocate the the old dynamic 2D array
	for (int i = 0; i < ROW1; i++)
		delete [] twoDim[i]; //deallocate the columns
	delete [] twoDim; //deallocate the rows

	twoDim = tmp_array; //now twoDim has been resized to a 5 x 5 array
	tmp_array = NULL; //just for good measure

	//We will populate the extra elements
	for (int i = 0; i < ROW2; i++)
		for (int j = 0; j < COL2; j++)
			if (i >= ROW1 || j >= COL1) //populate the new elements only
				twoDim[i][j] = (rand() % 20) + 1;

	cout << "Resized matrix" << endl;

	for (int i = 0; i < ROW2; i++)
	{
		for (int j = 0; j < COL2; j++)
			cout << twoDim[i][j] << " ";
		cout << endl;
	}

	return 0;
}
