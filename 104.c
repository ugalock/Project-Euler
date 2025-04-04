/*
The Fibonacci sequence is defined by the recurrence relation:

    Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.

It turns out that F541, which contains 113 digits, is the first Fibonacci number for which the last nine digits are 1-9 pandigital (contain all the digits 1 to 9, but not necessarily in order). And F2749, which contains 575 digits, is the first Fibonacci number for which the first nine digits are 1-9 pandigital.

Given that Fk is the first Fibonacci number for which the first nine digits AND the last nine digits are 1-9 pandigital, find k.
*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>

int isPandigital( long num ) {
	long digits = 0;
	while ( num ) {
		unsigned d = num % 10;
		num /= 10;
		if ( digits & ( (unsigned)1 << d ) ) return 0;
		digits |= ( (unsigned)1 << d );
	}
	return digits == 1022;
}

int main() {
	double logPhi = 0.20898764024997873;
	double logRoot5 = 0.3494850021680094;
	int check = 0, n = 2;
	long first = 1, second = 1, next = 0;
	while ( !check ) {
		++n;
		next = ( first + second ) % 1000000000;
		first = second;
		second = next;
		if ( isPandigital( next ) ) {
			double temp = (double)n * logPhi - logRoot5;
			long first10 = (long)pow( 10, temp - (long)temp + 8);
			if ( isPandigital( first10 ) ) check = 1;
		}
	}
	printf("Result: %d\n", n);
	return 0;
}