/*

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int isPrime( int n ) {
	if ( n == 2 || n == 3 ) return 1;
	else if ( !( n % 2 ) ) return 0;
	else if ( !( n % 3 ) ) return 0;
	int i = 5, w = 2;
	while ( i <= n / 2 ) {
		if ( !( n % i ) ) return 0;
		i += w;
		w = 6 - w;
	}
	return 1;
}

uint64_t gcd(uint64_t u, uint64_t v) {
  int shift;
  if ( u == 0 ) return v;
  if ( v == 0 ) return u;
  shift = __builtin_ctzl(u | v);
  u >>= __builtin_ctz(u);
  do {
    v >>= __builtin_ctz(v);
    if ( u > v ) {
      uint64_t t = v;
      v = u;
      u = t;
    }  
    v = v - u;
  } while ( v != 0 );
  return u << shift;
}

// unsigned addFraction( unsigned n1, unsigned d1, unsigned n2, 
//                  unsigned d2 ) {
// 	unsigned d, n;	
//   d = gcd( d1, d2 );
//   d = d1 * d2 / d;

//   n = n1 * ( d / d1 ) + n2 * ( d / d2 );

//   int cf = gcd( n, d );
//   n /= cf;
//   d /= cf;
//   unsigned res[ 2 ] = { n, d };
//   return res;
// }

static int cache[ 81 ];

int recurse( uint64_t currN, uint64_t currD, uint64_t lastNum ) {
	if ( lastNum == 80 || 2 * currN > currD ) return 0;
	else if ( currN && currD && 2 * currN == currD ) {
		printf("%lu / %lu  last: %lu\n", currN, currD, lastNum);
		return 1;
	}
	int res = 0;
	if ( !currD ) {
		for ( int i = lastNum+1; i <= 80; i++ ) {
			if ( cache[ i ] ) continue;
			uint64_t n = 1, d = i*i;
			int check = recurse( n, d, i );
			if ( check ) res++;
		}
	}
	else {
		for ( int i = lastNum+1; i <= 80; i++ ) {
			if ( cache[ i ] ) continue;
			uint64_t d, n, d1 = i*i;
			d = gcd( currD, d1 );
			d = currD * d1 / d;
			n = currN * d / currD + d / d1;
			uint64_t cf = gcd( d, n );
			n /= cf;
			d /= cf;
			int check = recurse( n, d, i );
			if ( check ) res++;  
		}
	}
	return res;
}


int main() {
	for ( int i = 11; i < 80; ++i ) {
		if ( isPrime( i ) && i >= 11 && i != 13 ) {
			int n = i;
			while ( n < 80 ) {
				cache[ n ]++;
				n += i;
			}
		}
	}
	printf("Result: %d\n", recurse( 0, 0, 1 ));
	return 0;
}