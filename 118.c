/*
Using all of the digits 1 through 9 and concatenating them freely to form decimal integers, different sets can be formed. Interestingly with the set {2,5,47,89,631}, all of the elements belonging to it are prime.

How many distinct sets containing each of the digits one through nine exactly once contain only prime elements?
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

int setIsPandigital( uint64_t nums[], int n ) {
	uint64_t check = 0; 
	for ( int i = 0; i < n; ++i ) {
		uint64_t curr = nums[ i ];
		while ( curr ) {
			unsigned temp = curr % 10;
			curr /= 10;
			if ( check & ( 1 << temp ) ) return 0;
			check |= ( 1 << temp );
		}
	}
	return 1;
}

int hasNoRepeats( uint64_t n ) {
	uint64_t check = 0;
	while ( n ) {
		unsigned temp = n % 10;
		if ( check & ( 1 << temp ) ) return 0;
		check |= ( 1 << temp );
		n /= 10;
	}
	return 1;
}

int analyzePerm( int num[ 9 ], int digitsLeft, uint64_t set[], int n ) {
	if ( !setIsPandigital( set, n ) ) return 0;
	else {
		if ( !digitsLeft ) return 1;
		int count = 0;
		for ( int i = 1; i <= digitsLeft; ++i ) {
			uint64_t a = 0;
			for ( int j = 0; j < i; ++j ) {
				a = a*10 + num[ 9-digitsLeft+j ];
			}
			if ( n && set[ n-1 ] > a ) continue;
			if ( isPrime( a, base, 5 ) ) {
				set[ n ] = a; 
				count += analyzePerm( num, digitsLeft-i, set, n+1 );
				set[ n ] = 0;
			}
		}
		return count;
	}
}

int findPerms( int digits[ 9 ], int num[ 9 ], int digitsLeft ) {
	if ( !digitsLeft ) {
		uint64_t set[ 9 ] = { 0 };
		return analyzePerm( num, 9, set, 0 );
	}
	int count = 0;
	for ( int i = 0; i < 9; ++i ) {
		if ( digits[ i ] == 0 ) {
			digits[ i ] = 1;
			num[ 9-digitsLeft ] = i+1;
			count += findPerms( digits, num, digitsLeft-1 );
			num[ 9-digitsLeft ] = 0;
			digits[ i ] = 0;
		}
	}
	return count; 
}

int main() {
	int digits[ 9 ] = { 0 };
	int num[ 9 ] = { 0 };
	printf("%d\n", findPerms( digits, num, 9 ));
}