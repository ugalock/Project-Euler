/*
The minimum number of cubes to cover every visible face on a cuboid measuring 3 x 2 x 1 is twenty-two.

If we then add a second layer to this solid it would require forty-six cubes to cover every visible face, the third layer would require seventy-eight cubes, and the fourth layer would require one-hundred and eighteen cubes to cover every visible face.

However, the first layer on a cuboid measuring 5 x 1 x 1 also requires twenty-two cubes; similarly the first layer on cuboids measuring 5 x 3 x 1, 7 x 2 x 1, and 11 x 1 x 1 all contain forty-six cubes.

We shall define C(n) to represent the number of cuboids that contain n cubes in one of its layers. So C(22) = 2, C(46) = 4, C(78) = 5, and C(118) = 8.

It turns out that 154 is the least value of n for which C(n) = 10.

Find the least value of n for which C(n) = 1000.
*/

#include <stdio.h>

unsigned cuboidLayer( int numLayers, int l, int w, int h) {
	return 2 * ( l*w + w*h + l*h ) + ( l + w + h + numLayers - 2 ) * ( 4*numLayers - 4 );
}

int main() {
	static unsigned cn[ 20000 ];
	for ( int x = 1; cuboidLayer( 1, x, x, x ) < 20000; ++x ) {
		for ( int y = x; cuboidLayer( 1, x, y, y ) < 20000; ++y ) {
			for ( int z = y; cuboidLayer( 1, x, y, z ) < 20000; ++z ) {
				for ( int n = 1; cuboidLayer( n, x, y, z ) < 20000; ++n ) {
					cn[ cuboidLayer( n, x, y, z ) ]++;
				}
			}
		}
	}
	int i = 0; 
	while ( cn[ i ] != 1000 && i < 20000 ) ++i;
	printf("Result: %u\n", i);
}