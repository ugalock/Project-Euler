/*
Given the positive integers, x, y, and z, are consecutive terms of an arithmetic progression, the least value of the positive integer, n, for which the equation, 
x^2 − y^2 − z^2 = n, has exactly two solutions is n = 27:

34^2 − 27^2 − 20^2 = 12^2 − 9^2 − 6^2 = 27

It turns out that n = 1155 is the least value which has exactly ten solutions.

How many values of n less than one million have exactly ten distinct solutions?

***Notes***
( x+d )^2 - x^2 - ( x-d )^2 = n
4xd - x^2 = n
*/

#include <stdio.h>

int main() {
	static int solutions[ 50000001 ] = { 0 };
	for ( long x = 1; x <= 50000000; ++x ) {
		for ( long n = x/4+1; n < x; ++n ) {
			long f = x*(4*n-x);
			if ( f > 0 && f < 50000000 ) solutions[ f ]++;
			else break;
		}
	}
	int count = 0;
	for ( int i = 1; i < 50000001; ++i ) {
		if ( solutions[ i ] == 1 ) {
			++count;
		}
	}
	printf("Result: %d\n", count);
}