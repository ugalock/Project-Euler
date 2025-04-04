/*
The proper divisors of a number are all the divisors excluding the number itself. For example, the proper divisors of 28 are 1, 2, 4, 7, and 14. As the sum of these divisors is equal to 28, we call it a perfect number.

Interestingly the sum of the proper divisors of 220 is 284 and the sum of the proper divisors of 284 is 220, forming a chain of two numbers. For this reason, 220 and 284 are called an amicable pair.

Perhaps less well known are longer chains. For example, starting with 12496, we form a chain of five numbers:

12496 → 14288 → 15472 → 14536 → 14264 (→ 12496 → ...)

Since this chain returns to its starting point, it is called an amicable chain.

Find the smallest member of the longest amicable chain with no element exceeding one million.
*/
#include <stdio.h>

int nextLink( int n ) {
	int sum = 1;
	for ( int i = 2; i * i <= n; ++i ) {
		if ( !( n % i ) ) {
			sum += i;
			if ( i * i != n ) sum += n / i;
		}
	}
	return sum;
}

int main() {
	int i, n, min, num, count, lowest = 0, longest = 0;
	static int cache[ 1000000 ];
	for ( i = 2; i < 1000000; ++i ) {
		cache[ i ] = nextLink( i );
	}
	for ( i = 2; i < 1000000; ++i ) {
		n = cache[ i ];
		min = 1000000;
		min = n < min ? n : min;
		count = 0; 
		while ( n != i ) {
			++count;
			if ( count > 30 || n >= 1000000 ) {
				count = 0;
				break;
			}
			n = cache[ n ];
			min = n < min ? n : min;
		}
		if ( count > longest && n == i ) {
			longest = count;
			lowest = min;
		}
	}
	printf("Longest chain found of length %d with a minimum of %d\n", longest, lowest);
	return 0;
}