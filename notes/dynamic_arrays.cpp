//dynamic arrays
int *a;
a = new int[5];
*a = 3;           //a is going to point to first element of the array and
                  //put 3 inside of it.
a = a + 1;  /*a is a pointer containing an address, so plus one moves to the
            1 = move 4 byte over(int is 4 byte of memory, char would be 1 byte )
            next address in the array. aka array[1]*/
*a = 5      //array now hold ('3')_('5')_(' ')_(' ')_(' ')
a = a -1;

for(int i = 0; i < 5; i++)
{
    *(a+i) = (rand()%5)+ 1;  //generates a random number for each member of
                             //of the array.
                             //(3)_(5)_(1)_(4)_(2)
}
/*CODE BELOW IS IDENTICAL TO FOR LOOP ABOVE. BOTH WILL WORK WITH POINTERS*/
for(int i = 0; i < 5; i++)
{
    a[i] = (rand()%5)+ 1;
}



//making deep copy of arrays
int *temp_array;
temp_array = new int[10];  //(3)_(5)_(1)_(4)_(2)_()_()_()_()_()
//making a deep copy of the origional array *a
for(int i = 0; i < 5; i++)
{
    temp_array[i] = a[i]
}
delete[] a; //will automatically delete the whole array;
a = temp_array;
//now *a points to temp_array; (now array is also 10 blocks wide)
temp_array = NULL; //temp_array points no where now because its not good to have
                   //2 points pointing to one spot



//dynamic arrays
int **twoDim;                   //now have a block of 4 bytes[ ]
twoDim = new int *[3];          //[(0 - twoDim pointing to this block)_(1)_(2)]

for(int i = 0; i < 3; i++)
{
   twoDim[i] = new int[3]      //[(0)_(1)_(2)] - all 3 spots have an address
}                              //each spot in array above points to 3 seperate
 *twoDim = 7                              //arrays.
 twodim[1][2] = 10                              [(0)_(1)_(2)]
 twoDim[2][1] = 8                               0= {(7)_()_()}
                                                1= {()_()_(10)}
                                                2= {()_(8)_()}

delete[]twodim;   //will only deallocate the array that points to the other
                  //pointers;

//how to deallocate the entire element
for(int i = 0; i < 3; i++) //this will deallocate every bit of the dynamic array
{
   delete[]twoDim[i];
}
delete[] twoDim;


//3 dementional array, WILL NOT BE ON EXAM. ONLY 1 and 2 dementional ARRAY

/*3 DEMANTIONAL ARRAY*/
char ***c;
new char** char[2];                 [(0)_(1)]
                                     0= {(address to another arr of pointers )}
                                     1= {(address to another arr of pointers)}
                                     look up example online
for(int i = 0; i < 2; i++)
{
   [i] = new char*[2]
}
for(int i = 0; i < 2; i++)
{
    for(int j = 0; j < 2; j++)
    [i][j] = new char*[2]
}

//follow the indenci to the right element
