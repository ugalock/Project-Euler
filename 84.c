/*
What are the most likely squares on a Monopoly board to end your turn on when rolling two 4-sided die?

Board labels:
GO A1 CC1 A2 T1 R1 B1 CH1 B2 B3 JAIL C1 U1 C2 C3 R2 D1 CC2 D2 D3 FP E1 CH2 E2 E3 R3 F1 F2 U2 F3 G2J G1 G2 CC3 G3 R4 CH3 H1 T2 H2
00 01  02 03 04 05 06  07 08 09   10 11 12 13 14 15 16  17 18 19 20 21  22 23 24 25 26 27 28 29  30 31 32  33 34 35  36 37 38 39

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>


static int Chest[ 16 ] = { 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static int Chance[ 16 ] = { 1, 10, 11, 24, 39, 5, -1, -1, -2, -3, 0, 0, 0, 0, 0, 0 };

static int railroads[ 4 ] = { 5, 15, 25, 35 } ;
static int utilities[ 2 ] = { 13, 29 };

struct diceInfo {
	int roll;
	int doubles;
};

int drawChance( int pos ) {
	return ( pos == 7 || pos == 22 || pos == 36 );
}

int drawChest( int pos ) {
	return ( pos == 2 || pos == 17 || pos == 33 );
}

int findNextRailroad( int pos ) {
	while ( pos % 10 != 5 ) {
		++pos;
		pos %= 40;
	}
	return pos;
}

int findNextUtility( int pos ) {
	while ( 1 ) {
		if ( pos == 12 || pos == 27 ) return pos;
		++pos;
		pos %= 40;
	}
} 
 
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
 
void shuffle( int arr[], int n )
{
  for (int i = n-1; i > 0; i--)
  {
      int j = rand() % ( i+1 );
      swap( &arr[ i ], &arr[ j ] );
  }
}

void normalize( int64_t arr[], int n, double result[] ) {
	double sum = 0.0;
	for ( int i = 0; i < n; ++i ) {
		sum += (double)arr[ i ];
	}
	for ( int i = 0; i < n; ++i ) {
		result[ i ] = (double)arr[ i ] / sum;
	}
}

void rollTwoDice( int numSides, struct diceInfo *info ) {
	int roll1 = 1 + rand() % numSides;
	int roll2 = 1 + rand() % numSides;
	info->roll = roll1 + roll2;
	info->doubles = roll1 == roll2;
	
}


int main() {
	srand ( time( NULL ) );
	int64_t visits[ 40 ] = { 0 };
	static double probs[ 40 ];
	struct diceInfo diceRoll;
	int i, j, pos, chanceDeckPos, chestDeckPos, chanceCard, chestCard, doubles;
	for ( i = 0; i < 100; ++i ) {
		
		doubles = 0;
		pos = 0; 
		chanceDeckPos = 0;
		chestDeckPos = 0;
		shuffle( Chance, 16 );
		shuffle( Chest, 16 );
		visits[ 0 ]++;
		
		for ( j = 0; j < 10000; ++j ) {
			rollTwoDice( 6, &diceRoll );
			doubles = diceRoll.doubles ? doubles+1 : 0;

			if ( doubles == 3 ) {
				pos = 10;
				diceRoll.doubles = 0;
			} else {
				pos = ( diceRoll.roll + pos ) % 40;
				if ( drawChance( pos ) ) {
					chanceCard = Chance[ chanceDeckPos ];
					chanceDeckPos = ++chanceDeckPos % 16;
					if ( !chanceCard ) {
						;
					} else if ( chanceCard < 0 ) {
						if ( chanceCard == -1 ) {
							pos = findNextRailroad( pos );
						} else if ( chanceCard == -2 ) {
							pos = findNextUtility( pos );
						} else {
							pos = ( pos + 37 ) % 40;
						}
					} else if ( chanceCard == 1 ) {
						pos = 0; 
					} else {
						pos = chanceCard;
					} 
				} else if ( drawChest( pos ) ) {
					chestCard = Chest[ chestDeckPos ];
					chestDeckPos = ++chestDeckPos % 16; 
					if ( !chestCard ) {
						;
					} else if ( chestCard == 1 ) {
						pos = 0;
					} else {
						pos = chestCard;
					}
				}
			}
			pos = pos == 30 ? 10 : pos;
			visits[ pos ]++;			
		}
	}
	normalize( visits, 40, probs );
	for ( i = 0; i < 40; ++i ) {
		printf("%d: %lf\n", i, probs[ i ]);
	}
	int highest, second, third;
	double curr;
	highest = 0;
	second = 0;
	third = 0;
	curr = 0.0;
	for ( i = 0; i < 40; ++i ) {
		highest = probs[ i ] > curr ? i : highest;
		curr = probs[ i ] > curr ? probs[ i ] : curr;
	}
	probs[ highest ] = 0;
	curr = 0.0;
	for ( i = 0; i < 40; ++i ) {
		second = probs[ i ] > curr ? i : second;
		curr = probs[ i ] > curr ? probs[ i ] : curr;
	}
	probs[ second ] = 0;
	curr = 0.0;
	for ( i = 0; i < 40; ++i ) {
		third = probs[ i ] > curr ? i : third;
		curr = probs[ i ] > curr ? probs[ i ] : curr;
	}
	probs[ third ] = 0;

	printf("%d %d %d\n", highest, second, third);
	
	return 0;
}