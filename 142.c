/*
Find the smallest x + y + z with integers x > y > z > 0 such that x + y, x − y, x + z, x − z, y + z, y − z are all perfect squares.

***Notes***
So we can work off of the equations x+y = a^2, x-y = b^2, x+z = c^2, x-z = d^2
y+z = e^2, y-z = f^2 with the condition that x > y > z > 0
We can see that 2x = a^2 + b^2, meaning a and b share parity, and the same goes for 
2y = e^2 + f^2. We can also note that because b^2 + f^2 = d^2, we can now note that 
a,b,c all share parity.
Our Pythagorean triples that must hold are:
b^2 + e^2 = c^2
c^2 + f^2 = a^2 = d^2 + e^2
and our end result will be given by (a^2 + b^2 + 2e^2) / 2 
So our conditions to check are e^2 + b^2 is a perfect square, f^2 + c^2 is a perfect square, if e is odd, then b is even, and a, b are of the same parity. 
*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>

uint64_t isPerfectSquare( uint64_t n ) {
	int temp = n % 10; 
	if ( temp == 2 || temp == 3 || temp == 7 || temp == 8 ) return 0;
	double s = sqrt(n);

	if ((uint64_t)s * (uint64_t)s == n) return (uint64_t) s;
	return 0;
}

int main() {
	for ( uint64_t e = 1; ; ++e ) {
		uint64_t e2 = e*e;
		for ( uint64_t b = 1 + (e & 1); b <= e; b += 1 + (e & 1) ) {
			uint64_t b2 = b*b;
			if ( !isPerfectSquare( e2 + b2 ) ) continue;
			for ( uint64_t f = 1; f < e; ++f ) {
				uint64_t a2 = e2 + b2 + f*f;
				if ( ( a2 % 2 == b2 % 2 ) && isPerfectSquare( b2 + f*f ) 
					&& isPerfectSquare( a2 ) ) {
					uint64_t result = ( a2 + b2 + 2*e2 ) / 2;
					printf("Result: %lu\n", result);
					return 0;
				}
			}
		}
	}
}
