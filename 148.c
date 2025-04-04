/*
We can easily verify that none of the entries in the first seven rows of Pascal's triangle are divisible by 7:
  	  	  	  	  	  	 1
  	  	  	  	  	 1 	  	 1
  	  	  	  	 1 	  	 2 	  	 1
  	  	  	 1 	  	 3 	  	 3 	  	 1
  	  	 1 	  	 4 	  	 6 	  	 4 	  	 1
  	 1 	  	 5 	  	10 	  	10 	  	 5 	  	 1
1 	  	 6 	  	15 	  	20 	  	15 	  	 6 	  	 1

However, if we check the first one hundred rows, we will find that only 2361 of the 5050 entries are not divisible by 7.

Find the number of entries which are not divisible by 7 in the first one billion (109) rows of Pascal's triangle.

***Notes***
Solution is based on Lucas' Theorem:
https://en.wikipedia.org/wiki/Lucas%27s_theorem

Given the remainders of N / p, where p is prime, in base p (mod p ), 
the sum of every member of the rows { 1 ... 1e9 } of Pascal's triangle
will be given by the recursive function:
f( Curr_digit) = Sumtorial( Curr_digit ) * sumtorial( p )^( #digits_left )
	+ ( Curr_digit + 1 ) * f( Next_digit )
where the digits are { 3, 3, 5, 3, 1, 6, 0, 0, 6, 1, 5 }  
*/

#include <math.h>
#include <stdio.h>
#include <stdint.h>

uint64_t sum( uint64_t n ) { return n * ( n+1 ) / 2; }

uint64_t lucas( int nums[], int start, int end, int p ) {
	if ( start > end ) return 1;
	uint64_t n = nums[ start ];
	return sum( n ) * pow(sum( p ), end-start) + ( n+1 )*lucas( nums, start+1, end, p );

}

int main() {
	//remainders of 1e9 - 1 divided by 7
	static int nums[ 11 ] = { 3, 3, 5, 3, 1, 6, 0, 0, 6, 1, 5 };

	printf("Result: %lu\n", lucas( nums, 0, 10, 7 ) );
}