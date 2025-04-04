/*
A number consisting entirely of ones is called a repunit. We shall define R(k) to be a repunit of length k; for example, R(6) = 111111.

Given that n is a positive integer and GCD(n, 10) = 1, it can be shown that there always exists a value, k, for which R(k) is divisible by n, and let A(n) be the least such value of k; for example, A(7) = 6 and A(41) = 5.

The least value of n for which A(n) first exceeds ten is 17.

Find the least value of n for which A(n) first exceeds one-million.
*/

#include <stdio.h>
#include <stdint.h>

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
	uint64_t i = 1000001;
	int wheel[ 4 ] = { 2, 4, 2, 2 };
	int index = 0;
	while ( 1 ) {
		if ( longDiv( i ) > 1000000 ) {
			printf("Result: %lu\n", i);
			return 0;
		}
		i += wheel[ index ];
		index = ( index + 1 ) & 3;
	}
}