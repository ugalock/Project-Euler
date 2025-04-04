/*
Too long to paste- but basically given 50 unsolved sudoku puzzles, solve them
and return the sum of the 3 digit number formed by the first three numbers 
in the upper-left hand corner

square = 3 * ( row / 3 ) + col / 3
*/


#include <stdio.h>

int getSquare( int row, int col ) {
	return 3 * ( row / 3 ) + ( col / 3 );
}

int checkRow( int grid[ 9 ][ 9 ], int row, int val ) {
	for ( int i = 0; i < 9; ++i ) {
		if ( grid[ row ][ i ] == val ) return 0;
	}
	return 1;
}

int checkColumn( int grid[ 9 ][ 9 ], int column, int val ) {
	for ( int i = 0; i < 9; ++i ) {
		if ( grid[ i ][ column ] == val ) return 0;
	}
	return 1;
}

int checkSquare( int grid[ 9 ][ 9 ], int square, int val ) {
	int col = ( square % 3 ) * 3;
	int row = ( square / 3 ) * 3;
	for ( int i = row; i < row + 3; ++i ) {
		for ( int j = col; j < col + 3; ++j ) {
			if ( grid[ i ][ j ] == val ) return 0;
		}
	}
	return 1;
}

int solvePuzzle( int grid[ 9 ][ 9 ], int currRow, int currCol ) {
	while ( grid[ currRow ][ currCol ] ) {
		currCol = ( currCol + 1 ) % 9;
		if ( !currCol ) ++currRow;
	} 
	if ( currRow == 9 ) {
		for ( int i = 0; i < 9; ++i ) {
			for ( int j = 0; j < 9; ++j ) {
				if ( grid[ i ][ j ] == 0 ) return 0;
			}
		}
		return 1;
	}
	int check;
	for ( int i = 1; i < 10; ++i ) {
		if ( checkSquare( grid, getSquare( currRow, currCol ), i ) &&
			checkColumn( grid, currCol, i ) && checkRow( grid, currRow, i ) ) {
			grid[ currRow ][ currCol ] = i; 
			int newCol = ( currCol + 1 ) % 9;
			if ( !newCol ) ++currRow;
			check = solvePuzzle( grid, currRow, newCol );
			if ( !check ) {
				if ( !newCol ) --currRow;
				grid[ currRow ][ currCol ] = 0;
			} else {
				return 1;
			} 
		}
	}
	return 0;
}

int main() {
  int i, j, check, n = 0;
	char ( *lines )[ 10 ] = NULL;
	FILE *f = fopen("96_sudoku.txt", "r");
	if ( !f ) {
		fprintf(stderr, "Error opening file\n");
		return 1;
	} 
	if ( !( lines = malloc( 450 * sizeof *lines ) ) ) {
    fprintf (stderr, "Error in malloc\n");
    return 1;
  }
  while (n < 450 && fgets( lines[ n ], 11, f)) {
    char *p = lines[ n ];
    for ( i = 0; p[ i ] != '\n'; ++i ) { ; }                  
    p[ i ] = '\0';
    if ( p[ 0 ] != 'G' ) n++;                         
  }
  static int puzzle[ 50 ][ 9 ][ 9 ];
  for ( n = 0; n < 50; ++n ) {
	  for ( i = 0; i < 9; ++i ) {
	  	for ( j = 0; j < 9; ++j ) {
	  		puzzle[ n ][ i ][ j ] =  lines[ n*9+i ][ j ] - '0';
	  	}
	  }
	}
	int result = 0;
	for ( i = 0; i < 50; ++i ) {
		check = solvePuzzle( puzzle[ i ], 0, 0 );
		if ( !check ) {
			printf("Solving failed on puzzle: %d\n", i);
			return -1;
		} else {
			result += puzzle[ i ][ 0 ][ 0 ]*100 + puzzle[ i ][ 0 ][ 1 ]*10 + puzzle[ i ][ 0 ][ 2 ];
		}
	}	
	printf("Result: %d\n", result);
	return 0;  
}