/*

*/

#include <stdio.h>
#include <stdint.h>

static uint64_t cache[ 1000 ];

uint64_t backtrackBlocks( int totalLength, int blocksLeft, int minBlock ) {
	if ( blocksLeft < minBlock ) return 1;
	if ( cache[ blocksLeft ] ) return cache[ blocksLeft ];
	uint64_t count = 1;
	for ( int i = 0; i <= totalLength - minBlock; ++i ) {
		for ( int j = minBlock; j <= blocksLeft-i; ++j ) {
			count += backtrackBlocks( totalLength, blocksLeft - i - j - 1, minBlock );
		}
	}
	if ( count > 1000000 ) return 0;
	cache[ blocksLeft ] = count;
	return count;
}

int main() {
	for ( int i = 3; ; ++i ) {
		if ( !backtrackBlocks( i, i, 50 ) ) {
			printf("Result: %d\n", i);
			break;
		}
	}
	return 0;
}