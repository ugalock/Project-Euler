/*
Considering 4-digit primes containing repeated digits it is clear that they cannot all be the same: 1111 is divisible by 11, 2222 is divisible by 22, and so on. But there are nine 4-digit primes containing three ones:

1117, 1151, 1171, 1181, 1511, 1811, 2111, 4111, 8111

We shall say that M(n, d) represents the maximum number of repeated digits for an n-digit prime where d is the repeated digit, N(n, d) represents the number of such primes, and S(n, d) represents the sum of these primes.

So M(4, 1) = 3 is the maximum number of repeated digits for a 4-digit prime where one is the repeated digit, there are N(4, 1) = 9 such primes, and the sum of these primes is S(4, 1) = 22275. It turns out that for d = 0, it is only possible to have M(4, 0) = 2 repeated digits, but there are N(4, 0) = 13 such cases.

In the same way we obtain the following results for 4-digit primes.
d 	M(4, d) 	N(4, d) 	S(4, d)
0 	2 				13 				67061
1 	3 				9 				22275
2 	3 				1 				2221
3 	3 				12 				46214
4 	3 				2 				8888
5 	3 				1 				5557
6 	3 				1 				6661
7 	3 				9 				57863
8 	3 				1 				8887
9 	3 				7 				48073

For d = 0 to 9, the sum of all S(4, d) is 273700.

Find the sum of all S(10, d).
*/

#include <stdio.h>
#include <stdint.h>

#define NUMDIGITS 10

static int num[ 10 ];
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

int millerRabin( __uint128_t a, __uint128_t n ) {
  int t = 0;
  __uint128_t u = n - 1;
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


__uint128_t analyzeNum() {
	if ( num[ 0 ] == 0 || num[ NUMDIGITS-1 ] % 2 == 0 ) return 0;
	__uint128_t n = 0;
	for ( int i = 0; i < NUMDIGITS; ++i ) {
		n = n*10 + num[ i ];
	}
	// printf("%lld\n", n);
	if ( isPrime( n, base, 5 ) ) {
		return n;
	} 
	return 0;
}

__uint128_t findNumbers( int currD, int index, int iter, int fill ) {
	if ( !iter ) {
		return analyzeNum();
	}
	if ( fill ) {
		for ( int k = 0; k < NUMDIGITS; ++k ) {
			num[ k ] = currD;
		}
	}
	__uint128_t sum = 0;
	for ( int i = index; i < NUMDIGITS; ++i ) {
		for ( int j = 0; j < 10; ++j ) {
			if ( j == currD ) continue;
			num[ i ] = j;
			sum += findNumbers( currD, i+1, iter-1, 0 );
			num[ i ] = currD;
		}
	}
	return sum;
}

int main() {
	__uint128_t result = 0;
	for ( int i = 0; i < 10; ++i ) {
		for ( int j = 1; j < NUMDIGITS; ++j ) {
			__uint128_t r = findNumbers( i, 0, j, 1 );
			if ( r ) {
				result += r;
				break;
			}
		}
	}
	printf("Results: %lu\n", (uint64_t)result);
	return 0;
}
