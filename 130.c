/*
A number consisting entirely of ones is called a repunit. We shall define R(k) to be a repunit of length k; for example, R(6) = 111111.

Given that n is a positive integer and GCD(n, 10) = 1, it can be shown that there always exists a value, k, for which R(k) is divisible by n, and let A(n) be the least such value of k; for example, A(7) = 6 and A(41) = 5.

You are given that for all primes, p > 5, that p − 1 is divisible by A(p). For example, when p = 41, A(41) = 5, and 40 is divisible by 5.

However, there are rare composite values for which this is also true; the first five examples being 91, 259, 451, 481, and 703.

Find the sum of the first twenty-five composite values of n for which
GCD(n, 10) = 1 and n − 1 is divisible by A(n).
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

unsigned longDiv( uint64_t n ) {
	unsigned num = 1, result = 1;
	while ( num ) {
		num *= 10;
		num += 1;
		num %= n;
		++result;
	}
	return result;
}

int main() {
	uint64_t i = 13, result = 0;
	int wheel[ 4 ] = { 4, 2, 2, 2 };
	int index = 0, count = 0;
	while ( 1 ) {
		if ( !isPrime( i, base, 5 ) ) {
			if ( ( i - 1 ) % longDiv( i ) == 0 ) {
				result += i;
				++count;
				if ( count == 25 ) {
					printf("Result: %lu\n", result);
					return 0;
				}
			}
		}
		i += wheel[ index ];
		index = ( index + 1 ) & 3;
	}
}