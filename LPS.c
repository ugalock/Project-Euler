#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cache[ 2002 ];

void LPS( char* str, int len, int ret[ 2 ] ) {
	if ( !len ) return;
	memset( cache, 0, sizeof( cache ) );
	int n = 2 * len + 1, e = -1, d = -1, maxLen = 0, maxPos = 0, center = 1, ctr_r = 2, r, l;
	for ( int i = 0; i <= n; ++i ) {
		if ( i & 1 ) cache[ i ]++;
	}
	for ( r = 2; r < n; r++ ) {
		l = 2 * center - r;
		e = 0;
		d = ctr_r - r;
		if ( d > 0 ) {
			if ( cache[ l ] < d || ( cache[ l ] == d && r == n-1 ) ) 
				cache[ r ] = cache[ l ];
			else if ( cache[ l ] == d && r < n-1 ) {
				cache[ r ] = cache[ l ];
				e = 1;
			}
		} else {
			cache[ r ] = 0;
			e = 1;
		}

		if ( e == 1 ) {
			while ( ( ( r+cache[ r ] ) < n && ( r-cache[ r ] ) > 0 ) && 
              ( !( (r+cache[ r ]+1) % 2 ) || 
              ( str[ (r+cache[ r ]+1)/2 ] == str[ (r-cache[ r ]-1)/2 ] ) ) ) {

        cache[ r ]++;
			}
		}

		maxPos = cache[ r ] > maxLen ? r : maxPos;
		maxLen = cache[ r ] > maxLen ? cache[ r ] : maxLen;
		// printf("%d\n", cache[r]);
		if ( r + cache[ r ] > ctr_r ) {
			center = r;
			ctr_r = r + cache[ r ]; 
		}
	}

	ret[ 0 ] = ( maxPos - maxLen ) / 2;
	ret[ 1 ] = ret[ 0 ] + maxLen - 1;
}

char* longestPalindrome(char* s) {
    int* nums = (int*)malloc( sizeof( int ) * 2 );
    LPS( s, strlen( s ), nums);
    char* str = (char*)malloc( nums[ 1 ]-nums[ 0 ]+2 );
    // printf("%d %d\n", nums[ 0 ], nums[ 1 ]);
    strncpy( str, &s[ nums[ 0 ] ], nums[ 1 ]-nums[ 0 ]+1);
    return str;
}

int main() {
	printf("%s\n", longestPalindrome("adam"));
	printf("%s\n", longestPalindrome("aracecar"));
	printf("%s\n", longestPalindrome("aaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaa"));
	printf("%s\n", longestPalindrome("weowineflnlknmefkknkolweoiholwjeifcoihjnclknlkjdsncljnkljsdncljnljnljnljnljnljnwefrpijw"));
	printf("%s\n", longestPalindrome("kayak"));
	printf("%s\n", longestPalindrome("jglknendplocymmvwtoxvebkekzfdhykknufqdkntnqvgfbahsljkobhbxkvyictzkqjqydczuxjkgecdyhixdttxfqmgksrkyvopwprsgoszftuhawflzjyuyrujrxluhzjvbflxgcovilthvuihzttzithnsqbdxtafxrfrblulsakrahulwthhbjcslceewxfxtavljpimaqqlcbrdgtgjryjytgxljxtravwdlnrrauxplempnbfeusgtqzjtzshwieutxdytlrrqvyemlyzolhbkzhyfyttevqnfvmpqjngcnazmaagwihxrhmcibyfkccyrqwnzlzqeuenhwlzhbxqxerfifzncimwqsfatudjihtumrtjtggzleovihifxufvwqeimbxvzlxwcsknksogsbwwdlwulnetdysvsfkonggeedtshxqkgbhoscjgpiel"));
}