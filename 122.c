/*
The most naive way of computing n^15 requires fourteen multiplications:

n × n × ... × n = n^15

But using a "binary" method you can compute it in six multiplications:

n × n = n2
n^2 × n^2 = n^4
n^4 × n^4 = n^8
n^8 × n^4 = n^12
n^12 × n^2 = n^14
n^14 × n = n^15

However it is yet possible to compute it in only five multiplications:

n × n = n^2
n^2 × n = n^3
n^3 × n^3 = n^6
n^6 × n^6 = n^12
n^12 × n^3 = n^15

We shall define m(k) to be the minimum number of multiplications to compute n^k; for example m(15) = 5.

For 1 ≤ k ≤ 200, find ∑ m(k).
*/

#include <stdio.h>

static int path[ 201 ];
static int count[ 201 ] = { [ 0 ... 200 ] = 12 };

void findPath( int currExp, int steps ) {
	if ( currExp > 200 || steps > count[ currExp ] ) return;
	count[ currExp ] = steps;
	path[ steps ] = currExp;
	for ( int i = steps; i >= 0; --i ) {
		findPath( currExp + path[ i ], steps + 1 );
	}
	
}

int main() {
	findPath( 1, 0 );
	int result = 0;
	for ( int i = 1; i < 201; ++i ) {
		result += count[ i ];
	}
	printf("Result: %d\n", result);
	return 0;
}