#include <iostream>
using namespace std;
int ack(int, int, int&);

int main()
{

 int x =2;
 int y =2;
 cout << ack(x, y) << endl;;

    return 0;
}
//implementation of the recursive ackerman function
int ack(int m, int n)
{
    if (m == 0){
        cout << "step 3: ";
        cout << "A(" << m << ", " << n << ")  ";
        cout << " = " << n+1 << endl;
        return n+1;
    }
    if((m > 0) && (n == 0)){
        cout << "step 2: ";
        cout << "A(" << m << ", " << n << ")  ";

        return ack(m-1, 1);
    }
    if((m > 0) && (n > 0)){
        cout << "step 1: ";
        cout << "A(" << m << ", " << n << ")  " <<endl;

        return ack(m-1, ack(m, n-1));
    }
}//end ack
