/*
Let p(n) represent the number of different ways in which n coins can be separated into piles. For example, five coins can be separated into piles in exactly seven different ways, so p(5)=7.

OOOOO
OOOO   O
OOO   OO
OOO   O   O
OO   OO   O
OO   O   O   O
O   O   O   O   O
Find the least value of n for which p(n) is divisible by one million.
*/
#include <stdio.h>
#include <stdint.h>

static int64_t cache[ 100000 ];

int main() {
	int sign, i, j, p, n = 1;            
  cache[ 0 ] = 1;
	while( 1 ){
    i = 0;
    p = 1;
    cache[ n ] = 0;
 
    while ( p <= n ) {                    
        sign = ( ( i >> 1 ) & 1 ) ? -1 : 1;
        cache[ n ] += sign * cache[ n - p ] ;
        cache[ n ] %= 1000000;
        i++;
                  
        j = !( i & 1 ) ? i / 2 + 1 : -1 * ( i / 2 + 1 );
        p = j * ( 3 * j - 1 ) / 2;
    } 
                 
    if ( cache[ n ] == 0 ) break;
    n++;
	}
	printf("%d\n", n);
	return 0;
}
