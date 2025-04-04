/*
It is well known that if the square root of a natural number is not an integer, then it is irrational. The decimal expansion of such square roots is infinite without any repeating pattern at all.

The square root of two is 1.41421356237309504880..., and the digital sum of the first one hundred decimal digits is 475.

For the first one hundred natural numbers, find the total of the digital sums of the first one hundred decimal digits for all the irrational square roots.
*/
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <gmp.h>

uint64_t sqrtApprox( unsigned long n) {
	uint64_t sum = 0;
	mpz_t a, b, limit, ten, zero, temp;
	mpz_init( zero );
	mpz_init( temp );
	mpz_init( a );
	mpz_init( b );
	mpz_init( limit );
	mpz_init( ten );
	mpz_add_ui( a, a, 5 * n);
	mpz_add_ui( b, b, 5 );
	mpz_add_ui( ten, ten, 10);
	mpz_pow_ui( limit, ten, 110 );

  while ( mpz_cmp( b, limit ) < 0 ) {
    if ( mpz_cmp( b, a ) <= 0 ) {
    	mpz_sub( a, a, b );
    	mpz_add_ui( b, b, 10);	
    } else {
    	mpz_mul_ui( a, a, 100 );
    	mpz_tdiv_q_ui( b, b, 10 );
    	mpz_mul_ui( b, b, 100 );
    	mpz_add_ui( b, b, 5 );
    }
  }
  mpz_tdiv_q_ui( b, b, 100000000000);
  while ( mpz_cmp( zero, b ) != 0 ) {
  	sum += mpz_mod_ui( temp, b, 10 );
  	mpz_tdiv_q_ui( b, b, 10 );
  }
  return sum;
}

int main() {
	uint64_t sum = 0;
	int j = 1;
	for ( int i = 1; i < 100; ++i ) {
		if ( j * j == i ) {
			++j;
			continue;
		} else {
			sum += sqrtApprox( (unsigned)i );
		}

	}
	printf("sum: %lu\n", sum);
	return 0;
}