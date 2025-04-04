/*
If a box contains twenty-one coloured discs, composed of fifteen blue discs and six red discs, and two discs were taken at random, it can be seen that the probability of taking two blue discs, P(BB) = (15/21)×(14/20) = 1/2.

The next such arrangement, for which there is exactly 50% chance of taking two blue discs at random, is a box containing eighty-five blue discs and thirty-five red discs.

By finding the first arrangement to contain over 1012 = 1,000,000,000,000 discs in total, determine the number of blue discs that the box would contain.

Credit to https://www.alpertron.com.ar/QUAD.HTM for solving Diophantine recurrence relation
*/

#include <stdio.h>

int main() {
	long anext, bnext;
	long a = 85;
	long b = 120;

	long limit = 1e12;
	while ( b < limit ) {
		anext = 3 * a + 2 * b - 2;
		bnext = 4 * a + 3 * b - 3;
		a = anext;
		b = bnext;
	}
	printf("There are %ld blue discs\n", a);
}