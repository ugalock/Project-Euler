/*

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

int millerRabin( int a, __uint128_t n ) {
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

int isPrime(__uint128_t n ) {
  if (n <= 1) return 0;
  if (n == 2) return 1;
  if (n % 2 == 0) return 0;
  if (n < 9) return 1;
  if (n % 3 == 0) return 0;
  if (n % 5 == 0) return 0;

  static int b1[ 2 ] = { 2, 3 };
  static int b2[ 2 ] = { 31, 73 };
  static int b3[ 3 ] = { 2, 7, 61 };
  static int b4[ 7 ] = { 2, 3, 5, 7, 11, 13, 17 };
  static __uint128_t l1, l2, l3, l4, l5;
  l1 = 1373653;
  l2 = 9080191;
  l3 = 4759123141;
  l4 = 2152302898747;
  l5 = 3474749660383;

  if ( n < l1 ) {
    for ( int i = 0; i < 2; i++ ) {
      if ( millerRabin( b1[ i ], n ) ) return 0;
    }
    return 1;
  } else if ( n < l2 ) {
    for ( int i = 0; i < 2; i++ ) {
      if ( millerRabin( b2[ i ], n ) ) return 0;
    }
    return 1;
  } else if ( n < l3 ) {
    for ( int i = 0; i < 3; i++ ) {
      if ( millerRabin( b3[ i ], n ) ) return 0;
    }
    return 1;
  } else if ( n < l4 ) {
    for ( int i = 0; i < 5; i++ ) {
      if ( millerRabin( b4[ i ], n ) ) return 0;
    }
    return 1;
  } else if ( n < l5 ) {
    for ( int i = 0; i < 6; i++ ) {
      if ( millerRabin( b4[ i ], n ) ) return 0;
    }
    return 1;
  } else {
    for ( int i = 0; i < 7; i++ ) {
      if ( millerRabin( b4[ i ], n ) ) return 0;
    }
    return 1;
  }
}



int main() {
	__uint128_t result = 1242490; 
	int nums[ 6 ] = { 1, 3, 7, 9, 13, 27 };
	for ( uint64_t i = 1000000; i < 150000000; i += 10 ) {
    if ( i % 3 != 1 && i % 3 != 2 ) continue;
    if ( i % 7 != 3 && i % 7 != 4 ) continue;
    __uint128_t i2 = i*i;
		int c = 1;
		for ( int j = 0; j < 6; ++j ) {
      __uint128_t t = i2 + nums[ j ];
			if ( !isPrime( t ) ) {
				c = 0;
				break;
			}
		}
		if ( c && !isPrime( i2+19 ) && !isPrime( i2+21 ) ) 
      result += i;
	}
	print_uint128( result );
	return 0;
}