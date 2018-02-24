//Adam Hoffman
//cs202-1002
//vasko monday wendesday 1130-1245
//2000970666

/*
I check the entire file and had prof.Vasko check my program for memory leak
errors and were unable to find anything wrong. Valgrind on bobby was giving me
the error of possible memory leaks, but after numerous checking was unable to
find anything. 
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

void resize(double *&, size_t, size_t&);
double deviation(double*, size_t);
double mean(double*, size_t);

int main(int args, char * argv[])
{
/************************************************************
varaible declorations
************************************************************/
    double * arr;     //main dynamic array
    double tmpnum    = 0;  //tmp double num holder
    double avg       = 0;
    double median    = 0;
    double stdDev    = 0;
    size_t incAmount = 0;//increment read counter
    size_t size      = 0;//array counter
    size_t capacity  = 0;//inc capacity by incAmount
    size_t tmpint    = 0;

/************************************************************
    file stream
************************************************************/
    ifstream in;
    string filename = argv[1];
    in.open(filename.c_str());
    if (!in) //test to see if file is reading
    {
        cout << " file not opened for input" << endl;
        return 0;
    }

/************************************************************
    getting inc amount
    creating array = size capacity
************************************************************/
    incAmount = atoi(argv[2]);
    capacity  = incAmount;
    arr = new double[capacity];

/************************************************************
    read decimal and store it into the dnymaic array at
    position size and then increment size by one.

    if(size == capacity), resize array by incAmount and
    inc capcity by incAmount as well
    if not at end of file go back to read decimal

************************************************************/
    in >> tmpnum;
    while(in)
    {
        arr[size] = tmpnum;
        size++;
        if(size == capacity)
        {
        resize(arr, incAmount, capacity);
        }
        in >> tmpnum;
    } //end of while(in)

    in.close(); //closing in filesteam
/************************************************************
 sort(array, array + size) is a functtion from algorithm library
************************************************************/
    sort(arr, arr + size);

/************************************************************
get median
if size = odd
median = array[size / 2]
if size = even
median = (array[size / 2] + array[(size / 2) - 1])/2
************************************************************/
    if(size%2 == 1)
    {
        tmpint = size / 2;
        median = arr[tmpint];
    }
    else
    {
        tmpint = size / 2;
        tmpnum = arr[tmpint];
        tmpint--;
        median = (tmpnum + arr[tmpint])/2.0;
    }
    avg    = mean(arr, size);
    stdDev = deviation(arr, size);

    cout << setw(25) << left << "median:";
    cout << setw(10) << left << fixed << setprecision(2) << median << endl;
    cout << setw(25) << left << "mean:";
    cout << setw(10) << left << setprecision(2) <<  avg << endl;
    cout << setw(25) << left << "standard deviation:";
    cout << setw(10) << left << stdDev << endl;

    delete [] arr;
    arr = NULL;
    return 0;
    //done
}

/*---------------------------------------------------------------
Function name: resize
PARAMETERS: double array pointer = arr
            size_t incAmount = incAmount
            size_t capacity  = incAmount * number of resizes
POSTCONDITION:
            returns resized array to main by reference
            returns capacity back to main by refence

---------------------------------------------------------------*/
void resize(double *& array, size_t incAmount, size_t& capacity)
{
    double * tmparr;
    size_t size = capacity;
    capacity = capacity + incAmount; //increasing capacity
    tmparr   = new double[capacity];
    for(size_t i = 0; i < size; i++)
    {
       tmparr[i] = array[i];
    } // of for loop
    delete [] array; //clearing arrays pointer
    array  = tmparr;
    tmparr = NULL; //stop dangling pointers

    return;
}
/*---------------------------------------------------------------
Function name: deviation
PARAMETERS:double array pointer = arr, size_t length = size; from main
POSTCONDITION: returns a double the standard deviation of the array being
passed
---------------------------------------------------------------*/
double deviation(double * array, size_t length)
{
    double avg    = 0;
    double stdDev = 0;
    double total1  = 0;
    double total2  = 0;

    for(size_t i = 0; i < length; i++)
    {
       total1 = total1 + array[i];
    }

    avg = total1 / length;

    for(size_t s = 0; s < length; s++)
    {
        total2  = array[s];
        total2  = total2 - avg;
        stdDev  = stdDev + pow(total2, 2);
    }
    stdDev = stdDev / (length-1);
    stdDev = sqrt(stdDev);

    return stdDev;


}
/*---------------------------------------------------------------
Function name: mean
PARAMETERS:double array pointer =  arr, size_t length = size ; from main
POSTCONDITION: returns the mean of the entire array being passed.
returns a type double of the mean of the array back to main
---------------------------------------------------------------*/
double mean(double * array, size_t length)
{
    double total = 0;
    for(size_t i = 0; i < length; i++)
    {
        total = total + array[i];
    }
    total = total / length;

    return total;

}
