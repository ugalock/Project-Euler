/*
Consider the infinite polynomial series AG(x) = xG1 + x^2G2 + x^3G3 + ..., where Gk is the kth term of the second order recurrence relation Gk = Gk−1 + Gk−2, G1 = 1 and G2 = 4; that is, 1, 4, 5, 9, 14, 23, ... .

For this problem we shall be concerned with values of x for which AG(x) is a positive integer.

The corresponding values of x for the first five natural numbers are shown below.
x							AG(x)
(√5−1)/4			1
2/5						2
(√22−2)/6			3
(√137−5)/14		4
1/2						5

We shall call AG(x) a golden nugget if x is rational, because they become increasingly rarer; for example, the 20th golden nugget is 211345365.

Find the sum of the first thirty golden nuggets.

***Notes***
Af(x) is very similar to problem 137, but this time we have to add 3x^2 to the numerator,
giving Af(x) = (x + 3x^2) / (1 - x - x^2) 
Since we want Af(x) to be an integer n, 
n = (x + 3x^2) / (1 - x - x^2) and (n+3)x^2 + (n+1)x - n = 0
n - nx - nx^2 = x + 3x^2 ==> (n+3)x^2 + (n+1)x -n = 0 
==> x is rational iff sqrt(5n^2 + 14n + 1) is an integer using the quadratic equation.
Let X = 5n + 7 and Y = y then we have the Diophantine equation:
X^2 - 5Y^2 = 44
and we get the same recursive solution as 137 
a(n+1) = 9a(n) + 20b(n) 
b(n+1) = 4a(n) + 9b(n)

*/

#include <stdio.h>
#include <stdint.h>

int print_uint128(__uint128_t n) {
  if (n == 0)  return printf("0\n");

  char str[40] = {0}; 
  char *s = str + sizeof(str) - 1;
  while ( n ) {
    *--s = "0123456789"[n % 10];
    n /= 10;                     
  }
  return printf("Result: %s\n", s);
}

int main() {
	int count = 0;
	__uint128_t result = 0;
	int64_t a = 7, b = 1, x = 8, y = 2, u = 13, v = 5, temp;
	int64_t a2 = 7, b2 = -1, x2 = 8, y2 = -2, u2 = 13, v2 = -5;

	while ( count < 30 ) {
		temp = a;
		a = 9*a + 20*b;
		b = 4*temp + 9*b;
		if ( (a-7) % 5 == 0 ) {
			++count;
			result += (a-7)/5;
		}
		if ( count == 30 ) {
			print_uint128( result );
			return 0;
		}
		temp = x;
		x = 9*x + 20*y;
		y = 4*temp + 9*y;
		if ( (x-7) % 5 == 0 ) {
			++count;
			result += (x-7)/5;
		}
		if ( count == 30 ) {
			print_uint128( result );
			return 0;
		}
		temp = u;
		u = 9*u + 20*v;
		v = 4*temp + 9*v;
		if ( (u-7) % 5 == 0 ) {
			++count;
			result += (u-7)/5;
		}
		if ( count == 30 ) {
			print_uint128( result );
			return 0;
		}
		temp = a2;
		a2 = 9*a2 + 20*b2;
		b2 = 4*temp + 9*b2;
		if ( (a2-7) % 5 == 0 ) {
			++count;
			result += (a2-7)/5;
		}
		if ( count == 30 ) {
			print_uint128( result );
			return 0;
		}
		temp = x2;
		x2 = 9*x2 + 20*y2;
		y2 = 4*temp + 9*y2;
		if ( (x2-7) % 5 == 0 ) {
			++count;
			result += (x2-7)/5;
		}
		if ( count == 30 ) {
			print_uint128( result );
			return 0;
		}
		temp = u2;
		u2 = 9*u2 + 20*v2;
		v2 = 4*temp + 9*v2;
		if ( (u2-7) % 5 == 0 ) {
			++count;
			result += (u2-7)/5;
		}
		if ( count == 30 ) {
			print_uint128( result );
			return 0;
		}
	}
}