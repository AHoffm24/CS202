/*
Review on algorithms
- step by step process
- returns correct output for any input
- must finish in finite time (must have an endput eventually)

Measure of an algorithm
- we ant a fast algorithm
- fast?
    - number of steps it takes to complete
    - write a function with respect to the input to determine growth rate
asymptotic complez classes
- 0(f[n])     - upper bound (worst case)
- theta(f[n]) - in between
- omega(f[n]) - lower bound (best case)

-0(f[n])
    - a class of functions bounded by f[n]
    - g(n) = 0(f[n]) does g of n belong in f[n]
    - g[n]<= (c.f[n])
            c >= 1
            n > no

 n = 0(n)
 n < = c * n;
 c> 1
 n > no
 no = 1

 example Sn + 6 = 0(n)
         sn + 6 < = c * n
         c = 6
         n > no
         no = 1

 0(n) is the class of the linear functions and below linear

 log_2 of n = 0(n)
 log_2 of n < = c * n
 c = 1
 n > no
 no = 1
