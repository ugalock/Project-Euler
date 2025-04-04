/*
Let (a, b, c) represent the three sides of a right angle triangle with integral length sides. It is possible to place four such triangles together to form a square with length c.

For example, (3, 4, 5) triangles can be placed together to form a 5 by 5 square with a 1 by 1 hole in the middle and it can be seen that the 5 by 5 square can be tiled with twenty-five 1 by 1 squares.

However, if (5, 12, 13) triangles were used then the hole would measure 7 by 7 and these could not be used to tile the 13 by 13 square.

Given that the perimeter of the right triangle is less than one-hundred million, how many Pythagorean triangles would allow such a tiling to take place?

***Notes***
a^2 + b^2 = c^2, k = a - b ==> c == 0 (mod (a - b)) ==> c = ky and since 
a,b,c are coprime (primitive triples only), we can see that k = 1
a^2 + b^2 = k^2y^2 ==> a^2 + (a - k)^2 = k^2y^2 ==> 2a^2 - 2ak + k^2 = k^2y^2
4a^2 - 4ak + 2k^2 = 2k^2y^2 ==> (2a/k - 1)^2 + 1 = 2y^2 ==> x^2 - 2y^2 = -1 for 
x == (2a/k - 1) == a + b, which is a Diophantine equation and our 
bounds are x + y < 10^8
Recurrence relationship:
x(n+1) = 3x + 4y
y(n+1) = 2x + 3y
It results in only 11 primitive triples meeting our requirements, but we can check 
every multiple them up to the bound with 10^8 / ( x + y )
*/

#include <stdio.h>

int main() {
	int temp, x = 7, y = 5;
	long result = 0, bound = 100000000;
	while ( x + y < bound ) {
		result += bound / ( x + y );
		temp = x;
		x = 3*x + 4*y;
		y = 2*temp + 3*y;
	}
	printf("Result: %ld\n", result);
}