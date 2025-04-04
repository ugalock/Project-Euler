/*
A hexagonal tile with number 1 is surrounded by a ring of six hexagonal tiles, starting at "12 o'clock" and numbering the tiles 2 to 7 in an anti-clockwise direction.

New rings are added in the same fashion, with the next rings being numbered 8 to 19, 20 to 37, 38 to 61, and so on. The diagram below shows the first three rings.

https://projecteuler.net/project/images/p128.gif

By finding the difference between tile n and each of its six neighbours we shall define PD(n) to be the number of those differences which are prime.

For example, working clockwise around tile 8 the differences are 12, 29, 11, 6, 1, and 13. So PD(8) = 3.

In the same way, the differences around tile 17 are 1, 17, 16, 1, 11, and 10, hence PD(17) = 2.

It can be shown that the maximum value of PD(n) is 3.

If all of the tiles for which PD(n) = 3 are listed in ascending order to form a sequence, the 10th tile would be 271.

Find the 2000th tile in this sequence.
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
	int count = 3;
	uint64_t start = 2;
	for ( uint64_t n = 1; ; ++n ) {
		int corners[ 2 ] = { 0 };
		uint64_t i = 6*n;
		if ( isPrime( 2*i+5, base, 5 ) ) {
			corners[ 0 ]++;
		}
		if ( isPrime( 2*i-7, base, 5 ) ) {
			corners[ 1 ]++;
		}
		if ( isPrime( i-1, base, 5 ) ) {
			corners[ 0 ]++;
			corners[ 1 ]++;
		}
		if ( isPrime( i+1, base, 5 ) ) {
			corners[ 0 ]++;
		}
		if ( isPrime( i+5, base, 5 ) ) {
			corners[ 1 ]++;
		}
		for ( int j = 0; j < 2; ++j ) {
			if ( corners[ j ] == 3 ) ++count;
			if ( count == 2000 ) {
				if ( j == 1 ) {
					printf("Result: %lu\n", start+i-1);
					return 0;
				}
				printf("Result: %lu\n", start);
				return 0;
			}
		}
		start += i;
	}
}
