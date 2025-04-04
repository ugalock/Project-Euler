/*
Continuation of 112: How many numbers < 10^100 are not bouncy?

***NOTES***

 <      #bouncy   #not bouncy   #inc    #dec
 10     0         9             9       10
 100    0         99            45      55
 1000   525       474           220     286
 1e4    8325      1674          715     1001
 1e5    95046     4953          2002    3003
 1e6    987048    12951         5005    8008
 1e7    9969183   30816         11440   19448
 1e8    99932013  67986         24310   43758

So the inc and dec columns are in the same columns of Pascal's triangle but one row apart,
and there are obviously duplicates for every number that consists of only one digit 
(and then subtract both of the zeroes off as well)
This makes sense because really inc/dec numbers are a combinatorics problem but it's
to just build the triangle than use GMP to deal with 109 choose 9 and 110 choose 10
*/

#include <stdio.h>
#include <stdint.h>

static uint64_t pascalsTriangle[ 111 ][ 112 ] = { 0 };

void pascal() {
  pascalsTriangle[ 0 ][ 0 ] = 1;
  pascalsTriangle[ 1 ][ 0 ] = 1;
  pascalsTriangle[ 1 ][ 1 ] = 1;
  for ( uint64_t i = 2; i < 111; ++i ) {
    pascalsTriangle[ i ][ 0 ] = 1;
    for ( uint64_t j = 1; j <= i+1; ++j ) {
      pascalsTriangle[ i ][ j ] = pascalsTriangle[ i-1 ][ j-1 ] + pascalsTriangle[ i-1 ][ j ];
    }
  }
}

int main() {
  pascal();
  uint64_t result = pascalsTriangle[ 109 ][ 9 ] + pascalsTriangle[ 110 ][ 10 ];
  printf("Result: %lu\n", result-1002);
}