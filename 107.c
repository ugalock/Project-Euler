/*
The following undirected network consists of seven vertices and twelve edges with a total weight of 243: https://projecteuler.net/project/images/p107_1.gif

The same network can be represented by the matrix below:
  A	 B	C	 D	E	 F	G
A	-	 16	12 21	-	 -	-
B	16 -	-	 17	20 -	-
C	12 -	-	 28	-	 31	-
D	21 17	28 -	18 19	23
E	-	 20 -	 18	-	 -	11
F	-	 -	31 19	-	 -	27
G	-	 -	-	 23	11 27	-

However, it is possible to optimise the network by removing some edges and still ensure that all points on the network remain connected. The network which achieves the maximum saving is shown below. It has a weight of 93, representing a saving of 243 − 93 = 150 from the original network.

Using network.txt (right click and 'Save Link/Target As...'), a 6K text file containing a network with forty vertices, and given in matrix form, find the maximum saving which can be achieved by removing redundant edges whilst ensuring that the network remains connected.
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int i, j, n = 0, count = 0;
  int firstSum = 0, sum = 0;
  char ( *lines )[ 40 ] = NULL;
  static int network[ 40 ][ 40 ];
  FILE *f = fopen("107_network.txt", "r");
  if ( !f ) {
    fprintf(stderr, "Error opening file\n");
    return 1;
  } 
  if ( !( lines = malloc( 40 * sizeof *lines ) ) ) {
    fprintf (stderr, "Error in malloc\n");
    return 1;
  }
  const char d[ 2 ] = ",";
  while (n < 40 && fgets( lines[ n ], 200, f)) {
    char *p = lines[ n ];
  	i = 0;
    char *token;
    token = strtok( p, d );
    while ( token ) {
    	int temp = 0;
    	if ( *token != '-' ) {
	    	temp = atoi( token );
    	}
    	network[ n ][ i ] = temp;
    	firstSum += temp;
    	token = strtok( NULL, d );
    	++i;
    }
    ++n;
  }
  uint64_t bitmap = (uint64_t)1;
  for ( i = 0; i < 39; ++i ) {
  	int min = 1000;
  	int best = -1;
  	for ( j = 0; j < 40; ++j ) {
  		if ( bitmap & (uint64_t)1 << j ) {
  			int map = 0;
  			int k = 0; 
  			while ( map < 40 ) {
  				if ( network[ j ][ map ] ) {
  					if ( !( bitmap & (uint64_t)1 << map ) && network[ j ][ map ] < min ) {
  						min = network[ j ][ map ];
	  					best = map;
  					}
  				}
  				++map;
  			}
  		}
  	}
  	sum += min;
  	bitmap |= (uint64_t)1 << best;
  }

  printf("Result: %d\n", firstSum / 2 - sum );
  
  return 0;
}