/*
There are some prime values, p, for which there exists a positive integer, n, such that the expression n^3 + n^2xp is a perfect cube.

For example, when p = 19, 8^3 + 8^2×19 = 12^3.

What is perhaps most surprising is that for each prime with this property the value of n is unique, and there are only four such primes below one-hundred.

How many primes below one million have this remarkable property?

***Notes***
As the example hints at and some factoring proves, n^3( ( p + n ) / n ) = a^3
==> p+n and n are perfect cubes (as well as n^2)
This, along with the knowledge that n,p,a are all integers lets us reshape the formula as
n + p = a^3/n^2 (we know n + p is an integer) so p = x^3 - y^3 where x^3=a^3/n^2 and y^3=n
The last insight is that p = ( x - y )( x^2 + xy + y^2 ), and since p is prime we know that x - y must equal 1 or p, and we exclude p since we're only interested in positive x,y
*/

#include <stdio.h>
#include <stdint.h>

static int base[ 5 ] = { 2, 3, 5, 7, 11 };

__uint128_t power( __uint128_t x, __uint128_t y, __uint128_t p ) {
  __uint128_t res = 1;      
  x %= p;         
  while ( y > 0 ) {
    if ( y & 1 ) res = ( res * x ) % p;
    y >>= 1;
    x = ( x * x ) % p;
  }
  return res;
}

int millerRabin( int a, uint64_t n ) {
  int t = 0;
  uint64_t u = n - 1;
  while ( ( u & 1 ) == 0 ) {
    t++;
    u >>= 1;
  }

  __uint128_t xi1 = power( a, u, n );
  __uint128_t xi2;

  for (int i = 0; i < t; i++) {
      xi2 = ( xi1 * xi1 ) % n;
      if ( ( xi2 == 1 ) && ( xi1 != 1 ) && ( xi1 != ( n - 1 ) ) )
        return 1;
      xi1 = xi2;
  }
  if ( xi1 != 1 ) return 1;
  return 0;
}

int isPrime(__uint128_t n, int base[], int numBase ) {
  if (n <= 1) return 0;
  if (n == 2) return 1;
  if (n % 2 == 0) return 0;
  if (n < 9) return 1;
  if (n % 3 == 0) return 0;
  if (n % 5 == 0) return 0;

  for ( int i = 0; i < numBase; i++ ) {
    if ( millerRabin( base[ i ], n ) ) return 0;
  }
  return 1;
}

int main() {
	int result = 0, i = 1;
	while( 3 * ( i * i + i ) < 999999 ) {
		if ( isPrime( 3 * ( i * i + i ) + 1, base, 5 ) ) result++;
		i++;
	}
	printf("Result: %d\n", result);
}