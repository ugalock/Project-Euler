/*
Three distinct points are plotted at random on a Cartesian plane, for which -1000 ≤ x, y ≤ 1000, such that a triangle is formed.

Consider the following two triangles:

A(-340,495), B(-153,-910), C(835,-947)

X(-175,41), Y(-421,-714), Z(574,-645)

It can be verified that triangle ABC contains the origin, whereas triangle XYZ does not.

Using triangles.txt (right click and 'Save Link/Target As...'), a 27K text file containing the co-ordinates of one thousand "random" triangles, find the number of triangles for which the interior contains the origin.

NOTE: The first two examples in the file represent the triangles in the example given above.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void getCofactor(int A[ 3 ][ 3 ], int temp[ 3 ][ 3 ], int p, int q, int n ) {
  int i = 0, j = 0;

  for ( int row = 0; row < n; row++ ) {
    for ( int col = 0; col < n; col++ ) {
      if ( row != p && col != q ) {
        temp[ i ][ j++ ] = A[ row ][ col ];

        if ( j == n - 1 ) {
          j = 0;
          i++;
        }
      }
    }
  }
}
 
int determinant( int A[ 3 ][ 3 ], int n ) {
  int temp[ 3 ][ 3 ], D = 0, sign = 1; 
  if ( n == 1 ) return A[ 0 ][ 0 ];
 
  for ( int f = 0; f < n; f++ ) {
    getCofactor( A, temp, 0, f, n );
    D += sign * A[ 0 ][ f ] * determinant( temp, n - 1 );
    sign = -sign;
  }
 
  return D;
}
 
void adjoint( int A[ 3 ][ 3 ], int adj[ 3 ][ 3 ] ) {

  int sign = 1;
  int temp[ 3 ][ 3 ];
 
  for ( int i = 0; i < 3; i++ ) {
    for ( int j = 0; j < 3; j++ ) {
      getCofactor( A, temp, i, j, 3 );
      sign = ( ( i + j ) % 2 == 0 ) ? 1 : -1;
      adj[ j ][ i ] = ( sign ) * ( determinant( temp, 2 ) );
    }
  }
}
 
int inverse( int A[ 3 ][ 3 ], float inverse[ 3 ][ 3 ] ) {
  int det = determinant( A, 3 );
  if ( !det ) return 0;
  int adj[ 3 ][ 3 ];
  adjoint( A, adj );

  for ( int i = 0; i < 3; i++ )
    for ( int j = 0; j < 3; j++ )
      inverse[ i ][ j ] = adj[ i ][ j ] / (float)( det );

  return 1;
}

int main() {
  int i, j, n = 0, count = 0;
  char ( *lines )[ 32 ] = NULL;
  FILE *f = fopen("102_triangles.txt", "r");
  if ( !f ) {
    fprintf(stderr, "Error opening file\n");
    return 1;
  } 
  if ( !( lines = malloc( 1000 * sizeof *lines ) ) ) {
    fprintf (stderr, "Error in malloc\n");
    return 1;
  }
  while (n < 1000 && fgets( lines[ n ], 32, f)) {
    char *p = lines[ n ];
    int row, col;
    float inv[ 3 ][ 3 ];
    int A[ 3 ][ 3 ];
    for ( i = 0; p[ i ] != '\n'; ++i ) { ; }                  
    p[ i ] = '\0';
    char *d = ",";
    char *token;
    token = strtok( p, d );
    A[ 0 ][ 0 ] = atoi( token );
    for ( col = 0; col < 3; ++col ) {
      for ( row = 0; row < 3; ++row ) {
        if ( !row && !col ) continue;
        if ( row == 2 ) {
          A[ row ][ col ] = 1;
        } else {
          token = strtok( NULL, d );
          A[ row ][ col ] = atoi( token );
        }
      }
    }
    if ( inverse( A, inv ) ) {
      float a = inv[ 2 ][ 2 ];
      float b = inv[ 1 ][ 2 ];
      float c = inv[ 0 ][ 2 ];
      if ( (a > 0) && (b > 0) && ( c > 0 ) && ( a+b+c < 3 ) ) {
        ++count;
      } 
    }
    ++n;                      
  }
  printf("Result: %d\n", count);
  return 0;
}