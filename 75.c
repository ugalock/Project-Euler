/*
It turns out that 12 cm is the smallest length of wire that can be bent to form an integer sided right angle triangle in exactly one way, but there are many more examples.

12 cm: (3,4,5)
24 cm: (6,8,10)
30 cm: (5,12,13)
36 cm: (9,12,15)
40 cm: (8,15,17)
48 cm: (12,16,20)

In contrast, some lengths of wire, like 20 cm, cannot be bent to form an integer sided right angle triangle, and other lengths allow more than one solution to be found; for example, using 120 cm it is possible to form exactly three different integer sided right angle triangles.

120 cm: (30,40,50), (20,48,52), (24,45,51)

Given that L is the length of the wire, for how many values of L ≤ 1,500,000 can exactly one integer sided right angle triangle be formed?
*/
#include <stdio.h>
#include <math.h> 

unsigned gcd(unsigned u, unsigned v)
{
  int shift;
  if ( u == 0 ) return v;
  if ( v == 0 ) return u;
  shift = __builtin_ctz(u | v);
  u >>= __builtin_ctz(u);
  do {
    v >>= __builtin_ctz(v);
    if ( u > v ) {
      unsigned t = v;
      v = u;
      u = t;
    }  
    v = v - u;
  } while ( v != 0 );
  return u << shift;
}

int main() {
	int L[ 1500001 ] = { 0 };
	int limit, m, n, a, b, c, l, k, result;
	limit = 1500000;
	result = 0;
	for ( m = 2; m < (int)sqrt( limit / 2 ); ++m ) {
		for ( n = 1; n < m; ++n ) {
			if ((( n + m ) & 1 ) && gcd( n, m ) == 1 ) {
				a = 2 * ( m * m + m * n );
				l = a;
				while ( l <= limit ) {
					++L[ l ];
					if ( L[ l ] == 1 ) result++;
					else if ( L[ l ] == 2 ) result--;
					l += a;
				}
			}
		}
	}
	printf("Results: %d\n", result);
	return 0;

}
