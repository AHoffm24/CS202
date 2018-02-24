/*
CHAPTER 15: Recursion
- repitition structure
- point is to call the function within itself

-iterative structure(for looping)
- 2 cases
    - base cases
        - stopping case
    - general cases(recursive case)
        - loop body, starting case
                - !5 = 5 * !4
                - !4 = 4 * !3
                - !3 = 3 * !2
                - !2 = 2 * 1
    - linked list recursive definition
        - empty linked list
        - a node that points to another linked list
        - [][head]->[][]->[][]->[][/]
*/
#include <iostream>
using namespace std;
void printHW(int);
void printHWMod(int);
int power(int, int);
int factorial(int);
int fib(int);
int summ(int);

int main()
{
    int fact;
    printHW(5);
    cout << endl;
    printHWMod(5);

    fact = factorial(5);
    cout << "Factorial: " << fact << endl;

    fact = fib(6);
    cout << "Fib:       " << fact << endl;
    fact = power(2, 6);
    cout << "Power:     "<< fact << endl;
    fact = summ(6);
    cout << "Sum:       "<< fact << endl;
    return 0;


}
int summ(int number)
{
int sum = 0;
if (number == 1)
    return number;
else
    sum = summ(number - 1);
    return sum + number;



}
int power(int num, int exponent)
{
    int sum = 0;
    if(exponent == 1)
       return num;
    else
    sum = power(num, (exponent-1));
    sum = sum * num;

    return sum;
}
void printHW(int iteration)
{
    if (iteration <= 0) //base case
        return;
    else
    { //general case
    cout << "hello world! step Number: " << iteration << endl;
    printHW(iteration-1);
    }
    return;
}
void printHWMod(int iteration)
{
    if (iteration <= 0) //base case
        return;
    else
    {
    printHWMod(iteration-1);
    cout << "hello world! step Number: " << iteration << endl;
    }
    return;
}
int factorial(int fact)
{
    int sum = 0;
    if(fact <= 1)
        return 1;
    else
    {
        sum = factorial(fact - 1);
        sum = fact * sum;
    }
    return sum;
//5, 4, 3, 2, 1
//sum = 2 * 1,
//sum = 3 * 2,
//sum = 4 * 6,
//sum = 5 * 24
}
int fib(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fib(n-1) + fib(n-2);
}
