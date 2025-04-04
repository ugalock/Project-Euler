/*
A positive integer, n, is divided by d and the quotient and remainder are q and r respectively. In addition d, q, and r are consecutive positive integer terms in a geometric sequence, but not necessarily in that order.

For example, 58 divided by 6 has quotient 9 and remainder 4. It can also be seen that 4, 6, 9 are consecutive terms in a geometric sequence (common ratio 3/2).
We will call such numbers, n, progressive.

Some progressive numbers, such as 9 and 10404 = 1022, happen to also be perfect squares.
The sum of all progressive perfect squares below one hundred thousand is 124657.

Find the sum of all progressive perfect squares below one trillion (1012).

***Notes***
n = dq + r where n is a perfect square. r < d < q ( if q < d then we can switch)
and the geometric progression means we know d = rk, q = rk^2 for some k > 0
We can say that k = a/b where gcd(a,b) = 1 and a > b, so d = ra/b, q = ra^2/b^2
==> r = qb^2/a^2 == tb^2 for t = q/a^2
==> n = dq + r == tb(ta^3 + b)
so our bounds are 2 < a < 10000 (a^3 < 1e12)
b < a, gcd(a,b) == 1, b^2a^3 + b^2 < 1e12
tb(ta^3 + b) < 1e12
*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>

uint64_t isPerfectSquare( uint64_t n ) {
	int temp = n % 10; 
	if ( temp == 2 || temp == 3 || temp == 7 || temp == 8 ) return 0;
	double s = sqrt(n);

	if ((uint64_t)s * (uint64_t)s == n) return (uint64_t) s;
	return 0;
}

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

uint64_t gcd(uint64_t u, uint64_t v) {
  int shift;
  if ( u == 0 ) return v;
  if ( v == 0 ) return u;
  shift = __builtin_ctzl(u | v);
  u >>= __builtin_ctzl(u);
  do {
    v >>= __builtin_ctzl(v);
    if ( u > v ) {
      uint64_t t = v;
      v = u;
      u = t;
    }  
    v = v - u;
  } while ( v != 0 );
  return u << shift;
}


int main() {
	__uint128_t result = 0, limit = 1000000000000; 
	static int cache[ 1000000 ];
	for ( uint64_t a = 2; a < 10000; ++a ) {
		uint64_t a3 = a*a*a;
		unsigned i = ( a + 1 ) % 2 + 1;
		for ( uint64_t b = 1; b < a; b += i ) {
			if ( b*b*(a3+1) >= limit ) break;
			if ( gcd( a, b ) == 1 ) {
				uint64_t t = 1, temp = b*b*(a3+1);
				while ( temp < limit ) {
					uint64_t s = isPerfectSquare( temp );
					if ( s ) {
						if ( !cache[ s ] ) {
							result += temp;
							cache[ s ]++;
						}
					}
					t++;
					temp = b*t*(a3*t+b);
				}
			}
		}
	}
	print_uint128( result );
	return 0;
}