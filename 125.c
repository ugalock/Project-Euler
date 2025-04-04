/*
The palindromic number 595 is interesting because it can be written as the sum of consecutive squares: 6^2 + 7^2 + 8^2 + 9^2 + 10^2 + 11^2 + 12^2.

There are exactly eleven palindromes below one-thousand that can be written as consecutive square sums, and the sum of these palindromes is 4164. Note that 1 = 0^2 + 1^2 has not been included as this problem is concerned with the squares of positive integers.

Find the sum of all the numbers less than 10^8 that are both palindromic and can be written as the sum of consecutive squares.

***Notes***
n^2 + n < 10^8 is the limit for our consecutive squares so n < 7071
*/

#include <stdio.h>
#include <stdint.h>


int isPalindrome( uint64_t n ) {
	uint64_t check = 0, num = n, temp;
	while ( num ) {
		temp = num % 10;
		check = check * 10 + temp;
		num /= 10;
	}
	return n == check;
}

uint64_t sumSquares( uint64_t n ) {
	return ( n * ( n + 1 ) * ( 2 * n + 1 ) ) / 6;
}

int main() {
	static int check[ 100000000 ];
	static uint64_t squares[ 7071 ];
	uint64_t result = 0, limit = 100000000;
	for ( int i = 1; i < 7071; ++i ) {
		squares[ i ] = sumSquares( i );
		for ( int j = i-2; j >= 0; --j ) {
			uint64_t n = squares[ i ] - squares[ j ];
			if ( n >= limit ) break;
			if ( isPalindrome( n ) && !check[ n ] ) {
				result += n;
				check[ n ] = 1;
			} 
		}
	}
	
	printf("Result: %lu\n", result);
	return 0;
}