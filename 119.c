/*
The number 512 is interesting because it is equal to the sum of its digits raised to some power: 5 + 1 + 2 = 8, and 83 = 512. Another example of a number with this property is 614656 = 284.

We shall define an to be the nth term of this sequence and insist that a number must contain at least two digits to have a sum.

You are given that a2 = 512 and a10 = 614656.

Find a30.
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

static __uint128_t nums[ 100 ];

int comparator(const void *p, const void *q) {
  __uint128_t l = *(const __uint128_t *)p;
  __uint128_t r = *(const __uint128_t *)q;
  if ( l > r ) return 1;
  if ( l < r ) return -1;
  return 0;
}

int sumDigits( __uint128_t n ) {
	int result = 0;
	while ( n ) {
		result += n % 10;
		n /= 10;
	}
	return result;
}

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
	int index = 0;
	for ( int n = 2; n < 300; ++n ) {
		__uint128_t num = n;
		for ( int i = 0; i < 50; ++i ) {
			num *= n;
			if ( sumDigits( num ) == n ) {

				nums[ index ] = num;
				++index;
			}
		}
		if ( index == 50 ) break;
	}
	qsort( (void*)nums, 50, sizeof( __uint128_t ), comparator );
	
	print_uint128( nums[ 29 ] );
	return 0;
}