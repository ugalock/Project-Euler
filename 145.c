/*
Some positive integers n have the property that the sum [ n + reverse(n) ] consists entirely of odd (decimal) digits. For instance, 36 + 63 = 99 and 409 + 904 = 1313. We will call such numbers reversible; so 36, 63, 409, and 904 are reversible. Leading zeroes are not allowed in either n or reverse(n).

There are 120 reversible numbers below one-thousand.

How many reversible numbers are there below one-billion (109)?
*/

#include <stdio.h>

int incNum( int num[ 9 ], int start ) {
	int curr = 8, carry = 1;
	if ( num[ 0 ] == 5 ) return -1;
	while ( carry && curr >= 0 ) {
		if ( num[ curr ] == 9 && carry ) {
			if ( curr ) num[ curr ] = 0;
			else return -1; 
			--curr;
		} else {
			num[ curr ]++;
			break;
		}
	}
	return start < curr ? start : curr;
}

int checkNum( int num[ 9 ], int start ) {
	if ( num[ 8 ] == 0 ) return 0;
	int n, i = 8, carry = 0;
	while ( start <= 8 ) {
		n = num[ i ] + num[ start ] + carry;
		if ( n % 2 == 0 ) return 0;
		if ( n >= 10 ) carry = 1;
		else carry = 0;
		++start;
		--i;
	}
	return 1;
} 

int main() {
	int num[ 9 ] = { 0 }, result = 0;
	num[ 8 ] = 9;
	int n = 8; 
	for ( int i = 0; n > 0; ++i ) {
		n = incNum( num, n );
		if ( 8-n != 4 && checkNum( num, n ) ) result++;
	}
	printf("%d\n", result );
	
}