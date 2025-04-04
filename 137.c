/*
Consider the infinite polynomial series AF(x) = xF1 + x2F2 + x3F3 + ..., where Fk is the kth term in the Fibonacci sequence: 1, 1, 2, 3, 5, 8, ... ; that is, Fk = Fk−1 + Fk−2, F1 = 1 and F2 = 1.

For this problem we shall be interested in values of x for which AF(x) is a positive integer.
Surprisingly AF(1/2) 	 =  	(1/2).1 + (1/2)2.1 + (1/2)3.2 + (1/2)4.3 + (1/2)5.5 + ...
  	 =  	1/2 + 1/4 + 2/8 + 3/16 + 5/32 + ...
  	 =  	2

The corresponding values of x for the first five natural numbers are shown below.
x						AF(x)
√2−1				1
1/2					2
(√13−2)/3		3
(√89−5)/8		4
(√34−3)/5		5

We shall call AF(x) a golden nugget if x is rational, because they become increasingly rarer; for example, the 10th golden nugget is 74049690.

Find the 15th golden nugget.


***Notes***
So this sequence Af(x) can be re-written as Af(x) = x / (1 - x  - x^2) 
( proof here: https://math.stackexchange.com/questions/338740/the-generating-function-for-the-fibonacci-numbers )

Since we want Af(x) to be an integer n, n = x / (1- x - x^2) and nx^2 + (n + 1)x - n = 0
==> x is rational iff sqrt(5n^2 + 2n + 1) is an integer using the quadratic equation.
Let y^2 = 5n^2 + 2n + 1 ==> 5y^2 = 25n^2 + 10n + 5 ==> 5y^2 = (5n + 1)^2 + 4
and this can be solved like Pell equation using https://www.alpertron.com.ar/QUAD.HTM
and we get the recursive solution 
a(n+1) = 9a(n) + 20b(n) 
b(n+1) = 4a(n) + 9b(n)
where a = 5n+1 ==> if a-1 % 5 == 0, n is an integer and x is rational 
*/

#include <stdio.h>
#include <stdint.h>

int main() {
	int count = 1; // count starts at 1 because (1-1) % 5 == 0 and n > 0
	uint64_t n = 0;
	uint64_t a = 1, b = 1, x = 4, y = 2, u = 11, v = 5, temp;
	// Have to check for nuggets for all of the positive solutions of the Pell equation
	while ( 1 ) {
		temp = a;
		a = 9*a + 20*b;
		b = 4*temp + 9*b;
		temp = x;
		x = 9*x + 20*y;
		y = 4*temp + 9*y;
		temp = u;
		u = 9*u + 20*v;
		v = 4*temp + 9*v;
		if ( (a-1) % 5 == 0 ) ++count;
		if ( count == 15 ) {
			printf("Result: %lu\n", (a-1)/5);
			return 0;
		}
		if ( (u-1) % 5 == 0 ) ++count;
		if ( count == 15 ) {
			printf("Result: %lu\n", (u-1)/5);
			return 0;
		}
		if ( (x-1) % 5 == 0 ) ++count;
		if ( count == 15 ) {
			printf("Result: %lu\n", (x-1)/5);
			return 0;
		}

	}
	return 0;
}