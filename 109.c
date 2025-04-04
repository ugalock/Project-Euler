/*
Really long to explain- but basically how many ways can you checkout playing darts with a score of less than 100?
*/

#include <stdio.h>

int main() {
  static int allThrows[ 62 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 25, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 
    32, 34, 36, 38, 40, 50, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48, 51, 54, 57, 60 };
  static int doubles[ 21 ] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 
    32, 34, 36, 38, 40, 50 };
  int results = 21; // all miss / miss / double combos are < 100
  for ( int i = 0; i < 2; ++i ) {
    for ( int j = 0; j < 21; ++j ) {
      if ( i == 0 ) { // check miss / score / double combos
        for ( int k = 0; k < 62; ++k ) {
          if ( doubles[ j ] + allThrows[ k ] < 100 ) ++results;
        }
      } else {
        for ( int k = 0; k < 62; ++k ) {
          for ( int l = k; l < 62; ++l ) { // checking score / score / double combos
            if ( doubles[ j ] + allThrows[ k ] + allThrows[ l ] < 100 )
              ++results;
          }
        }
      }
    }
  }
  printf("Results: %d\n", results);
  return 0;
}