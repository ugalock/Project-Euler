/*
Working from left-to-right if no digit is exceeded by the digit to its left it is called an increasing number; for example, 134468.

Similarly if no digit is exceeded by the digit to its right it is called a decreasing number; for example, 66420.

We shall call a positive integer that is neither increasing nor decreasing a "bouncy" number; for example, 155349.

Clearly there cannot be any bouncy numbers below one-hundred, but just over half of the numbers below one-thousand (525) are bouncy. In fact, the least number for which the proportion of bouncy numbers first reaches 50% is 538.

Surprisingly, bouncy numbers become more and more common and by the time we reach 21780 the proportion of bouncy numbers is equal to 90%.

Find the least number for which the proportion of bouncy numbers is exactly 99%.
*/

#include <stdio.h>

int isBouncy( int num ) {
	int d = num % 10;
	num /= 10;
	int temp, checkInc = 0, checkDec = 0;

	while ( num ) {
		temp = num % 10;
		num /= 10;
		if ( temp > d ) checkDec = 1;
		else if ( temp < d ) checkInc = 1;
		if ( checkDec & checkInc ) return 1;
		d = temp;
	}
	return ( checkInc & checkDec );
}

int main() {
	int result = 0;
	int i = 100;
	int check = 1000;
	while ( check < 1000000000 ) {
		i++;
		if ( isBouncy( i ) ) ++result;
		if ( i == check ) {
			printf("Bouncy: %d Non-bouncy: %d\n", result, i-result-1);
			check *= 10;
		}
	}
	return 0;
}