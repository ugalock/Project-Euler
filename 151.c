/*
A printing shop runs 16 batches (jobs) every week and each batch requires a sheet of special colour-proofing paper of size A5.

Every Monday morning, the foreman opens a new envelope, containing a large sheet of the special paper with size A1.

He proceeds to cut it in half, thus getting two sheets of size A2. Then he cuts one of them in half to get two sheets of size A3 and so on until he obtains the A5-size sheet needed for the first batch of the week.

All the unused sheets are placed back in the envelope.

At the beginning of each subsequent batch, he takes from the envelope one sheet of paper at random. If it is of size A5, he uses it. If it is larger, he repeats the 'cut-in-half' procedure until he has what he needs and any remaining sheets are always placed back in the envelope.

Excluding the first and last batch of the week, find the expected number of times (during each week) that the foreman finds a single sheet of paper in the envelope.

Give your answer rounded to six decimal places using the format x.xxxxxx .

***Notes***
Pretty straightforward for this one. Recursively move down the tree of all possible pieces of paper that could be selected and combine their probabilities as we move back up the call stack. Had all types as double on the first go, but float was accurate anough and shaved off some milliseconds 
*/

#include <stdio.h>

float recurse( int envelope[] ) {
	int length = 0;
	for ( int i = 0; i < 5; ++i ) {
		length += envelope[ i ];
	}
	float res = 0;
	if ( length == 1 ) {
		if ( envelope[ 4 ] == 1 ) return 0;
		if ( !envelope[ 0 ] ) res = 1;
	}
	for ( int i = 0; i < 5; ++i ) {
		if ( !envelope[ i ] ) continue;

		int new[ 5 ] = { 0 };
		for ( int j = 0; j < 5; ++j ) new[ j ] = envelope[ j ];
		new[ i ] -= 1;
		for ( int j = i+1; j < 5; ++j ) new[ j ] += 1;
		float p = (float)envelope[ i ] / (float)length;
		res += recurse( new ) * p;
	}
	return res;
}

int main() {
	int envelope[ 5 ] = { 1, 0, 0, 0, 0 };
	printf("Result: %.6f\n", recurse( envelope ));
}