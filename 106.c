/*
Let S(A) represent the sum of elements in set A of size n. We shall call it a special sum set if for any two non-empty disjoint subsets, B and C, the following properties are true:

    S(B) ≠ S(C); that is, sums of subsets cannot be equal.
    If B contains more elements than C then S(B) > S(C).

For this problem we shall assume that a given set contains n strictly increasing elements and it already satisfies the second rule.

Surprisingly, out of the 25 possible subset pairs that can be obtained from a set for which n = 4, only 1 of these pairs need to be tested for equality (first rule). Similarly, when n = 7, only 70 out of the 966 subset pairs need to be tested.

For n = 12, how many of the 261625 subset pairs that can be obtained need to be tested for equality?

NOTE: This problem is related to Problem 103 and Problem 105.

***Notes***

****4****
n=2			4 choose 2 * 2 choose 2 = 6
14	23		1 / 6

****5****
n=2			5 choose 2 * 3 choose 2 = 30
14	23		5 / 30
15  23
15	24
15	34
25	34

****6****
n=2			6 choose 2 * 4 choose 2 = 90
14	23		15 / 90
15  23
15	24
15	34
25	34
16	23
16	24
16	25
16	34
16	35
16	45
26	34
26  35
26	45
36	45

n=3			6 choose 3 * 3 choose 3 = 20
126	 345	5 / 20
136	 245
146  235
156  234
145	 236

****7****
n=2			7 choose 2 * 5 choose 2 = 210
( already counting sets from 6 ; n=2 )	35 / 210
17	...  5 choose 2 = 10
27	...	 4 choose 2 = 6
37  ...  3 choose 2 = 3
47  ...  2 choose 2 = 1

n=3 		7 choose 3 * 4 choose 3 = 140
( already counting sets from 6 ; n=3 )
guessing it's 35 / 140 because the ratios for choosing 2 remained consistent

Now 4 choose 4 = 1 and our test for 4 ; n=2 is 1
6 choose 4 = 15 and our test for 6 ; n=2 is 15, etc...
so there is some ratio that equals 1 for n=2

6 choose 6 = 1 and 6 ; n=3 is 5
7 choose 6 = 7 and 7 ; n=3 is 5

We've got a pattern!

Pretty stuck here for a while but some serious googling led me to Dyck paths which are given by:
C( 2a+1, a-1 ) where a == n-1 ===> C( 2n-1, n-2 );
*/

#include <stdio.h>

static inline long factorial( int n ) {
	long result = 1;
	while ( n > 1 ) {
		result *= n--;
	} 
	return result;
}

static inline int comb( int n, int c ) {
	return factorial( n ) / ( factorial( c ) * factorial( n-c ) );
}

int main() {
	int result = 0;
	for ( int n = 2; n <= 6; ++n ) {
		result += comb( 12, 2*n ) * comb( 2*n-1, n-2 );
	}
	printf("Result: %d\n", result);
	return 0;
}