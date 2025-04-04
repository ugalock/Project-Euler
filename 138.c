/*
Consider the isosceles triangle with base length, b = 16, and legs, L = 17.

By using the Pythagorean theorem it can be seen that the height of the triangle, 
h = √(172 − 82) = 15, which is one less than the base length.

With b = 272 and L = 305, we get h = 273, which is one more than the base length, and this is the second smallest isosceles triangle with the property that h = b ± 1.

Find ∑ L for the twelve smallest isosceles triangles for which h = b ± 1 and b, L are positive integers.

***Notes***
For integers m, n > 0, all primitive triples are given by:
a = m^2 - n^2, b = 2mn, c = m^2 + n^2 where a < b < c
we want triangles s.t. 2a - b = +/- 1 and squaring both sides we can see that
4a^2 - 4ab + b^2 = 1, meaning that the ratio between c0 / c1 will equal c1 / c2, etc.
which implies a recurrence relationship. Solving the first 3 by hand with this knowledge 
leads to the relationship: 
a(n+1) = 17a + 4b
b(n+1) = 4a + b 		for (a0, b0) == (1,0)
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
  return printf("%s\n", s);
}

int main() {
	__uint128_t result = 0, a = 1, b = 0, temp;
	int count = 0;
	while ( count < 12 ) {
		++count;
		temp = a;
		a = 17*a + 4*b;
		b = 4*temp + b;
		result += a;
	}
	print_uint128( result );
	return 0;
}