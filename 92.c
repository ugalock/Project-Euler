/*
A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.

For example,

44 → 32 → 13 → 10 → 1 → 1
85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89

Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.

How many starting numbers below ten million will arrive at 89?
*/

#include <stdio.h>

int squareDigits( int n ) {
	int result = 0;
	while ( n ) {
		result += ( n % 10 ) * ( n % 10 );
		n /= 10;
	}
	return result;
}

int main() {
	int n, count = 0;
	static int cache[ 567 ];
	for ( int i = 1; i < 10000000; ++i ) {
		int oneCount = 0, count_89 = 0;
		n = squareDigits( i );
		while ( oneCount != 2 && count_89 != 2 ) {
			if ( n == 1 ) ++oneCount;
			else if ( n == 89 ) ++count_89;
			else if ( cache[ n ] ) count_89 = 2; 
			n = squareDigits( n );
		}
		if ( count_89 == 2 ) {
			++count;
			cache[ squareDigits( i ) ]++;
		}
	}
	printf("Result: %d\n", count);
}