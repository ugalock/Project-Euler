/*
The number 145 is well known for the property that the sum of the factorial of its digits is equal to 145:

1! + 4! + 5! = 1 + 24 + 120 = 145

Perhaps less well known is 169, in that it produces the longest chain of numbers that link back to 169; it turns out that there are only three such loops that exist:

169 → 363601 → 1454 → 169
871 → 45361 → 871
872 → 45362 → 872

It is not difficult to prove that EVERY starting number will eventually get stuck in a loop. For example,

69 → 363600 → 1454 → 169 → 363601 (→ 1454)
78 → 45360 → 871 → 45361 (→ 871)
540 → 145 (→ 145)

Starting with 69 produces a chain of five non-repeating terms, but the longest non-repeating chain with a starting number below one million is sixty terms.

How many chains, with a starting number below one million, contain exactly sixty non-repeating terms?
*/
#include <stdio.h>


int isInArray(int *array, int array_size, int number) {
    for (int i = 0; i < array_size; ++i) {
        if (array[i] == number) {
            return 1;
        }
    }
    return 0;
}

int fact[ 10 ] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

int main() {
	int count, check, temp, result = 0;
	for ( int i = 1; i < 1000000; ++i ) {
		int chain[ 63 ] = { 0 };
		chain[ 0 ] = i;
		check = 0;
		for ( count = 1; count < 61; ++count ) {
			if ( count == 60 ) {
				result += 1;
			}
			temp = 0;
			int n = chain[ count - 1 ];
			do {
				temp += fact[ n % 10 ];
				n /= 10;
			} while ( n > 0 );

			chain[ count ] = temp;
			if ( isInArray( chain, count-1, temp ) ) {
				break;
			}
		}
	}
	printf("Result: %d\n", result);
	return 0;
}