/*
It is easily proved that no equilateral triangle exists with integral length sides and integral area. However, the almost equilateral triangle 5-5-6 has an area of 12 square units.

We shall define an almost equilateral triangle to be a triangle for which two sides are equal and the third differs by no more than one unit.

Find the sum of the perimeters of all almost equilateral triangles with integral side lengths and area and whose perimeters do not exceed one billion (1,000,000,000).
***********************
Notes:
b = a +/- 1
a^2 = h^2 + ( b / 2 )^2
case (+):
a^2 = h^2 + ( ( a + 1 ) / 2 )^2
3a^2 = 4h^2 + 2a + 1 (multiply by 3)
9a^2 - 6a = 12h^2 + 3 (group and divide by 4)
( ( 3a - 1 ) / 2 )^2 - 3h^2 = 1
or x^2 - 3y^2 = 1 for x = ( 3a - 1 ) / 2 and y = h^2
case (-):
by symmetry we have the same Pell equation, but x = ( 3a + 1 ) / 2

so a = ( 2x +/- 1 ) / 3
and so area A = ( x +/- 2 ) * y / 3
( we can check if 3a % 3 == 0 instead of costly divisions )
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
	uint64_t x = 2, y = 1, count = 0;
	uint64_t a, area, xn, yn;
	while ( x < 500000000 ) {
		a = 2 * x - 1;
		area = ( x - 2 ) * y;
		if ( a > 0 && area > 0 && !( a % 3 ) && !( area % 3 ) ) {
			count += a + 1;
		}
		a = 2 * x + 1;
		area = ( x + 2 ) * y;
		if ( a > 0 && area > 0 && !( a % 3 ) && !( area % 3 ) ) {
			count += a - 1;
		}
		xn = 3 * y + 2 * x;
		yn = 2 * y + x;
		x = xn;
		y = yn;
	}
	printf("Result: %lu\n", count);
}