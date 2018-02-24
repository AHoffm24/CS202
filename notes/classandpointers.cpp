/*
- copy constructors do not work properly with pointers;
- will initially print out right values, but dont be fooled.
- problems will arise.
- need to learn more on deep vs shallow copies
- rule of 3
       - you must have these implemented since there is a pointer variable in
         the class
       - bad(const bag&);//copy constructor
       - ~bag(); //destructor
       bag & operator=(const bag&); //assignment operator
- destructor always have a ~ infront of it;
    - takes no parameters
    - can only! have "1"! destructor per class
    - they destroy the object

- this pointer
- pointer that points to the object that calls its member function
*/
