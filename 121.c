/*
A bag contains one red disc and one blue disc. In a game of chance a player takes a disc at random and its colour is noted. After each turn the disc is returned to the bag, an extra red disc is added, and another disc is taken at random.

The player pays £1 to play and wins if they have taken more blue discs than red discs at the end of the game.

If the game is played for four turns, the probability of a player winning is exactly 11/120, and so the maximum prize fund the banker should allocate for winning in this game would be £10 before they would expect to incur a loss. Note that any payout will be a whole number of pounds and also includes the original £1 paid to play the game, so in the example given the player actually wins £9.

Find the maximum prize fund that should be allocated to a single game in which fifteen turns are played.
*/

#include <stdio.h>
#include <stdint.h>

static inline uint64_t pop64(uint64_t y) {
	y -= ((y >> 1) & 0x5555555555555555ull);
	y = (y & 0x3333333333333333ull) + (y >> 2 & 0x3333333333333333ull);
	return ((y + (y >> 4)) & 0xf0f0f0f0f0f0f0full) * 0x101010101010101ull >> 56;
}

int main() {
	uint64_t base = 1, count = 1;
	for ( int i = 2; i <= 16; ++i ) base *= i;
	for ( uint64_t i = 1; i < 32768; ++i ) {
		if ( pop64( i ) > 7 ) continue;
		uint64_t n = 1;
		for ( unsigned j = 0; j < 15; ++j ) {
			if ( i & ( 1 << j ) ) n *= j + 1;
		}
		count += n;
	}
	printf("Result: %lu\n", base / count );
	return 0;

}