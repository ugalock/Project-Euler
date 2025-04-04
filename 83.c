/*
The minimal path sum in the 5 by 5 matrix below, by starting in any cell in the left column and finishing in any cell in the right column, and only moving up, down, left, and right, is indicated in red and bold; the sum is equal to 994.

Find the minimal path sum, in matrix.txt (right click and "Save Link/Target As..."), a 31K text file containing a 80 by 80 matrix, from the left column to the right column.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "libastar/astar.h"

static uint32_t nums[ 80 ][ 80 ];
static char map[ 80 ][ 80 ];

uint32_t get_map_cost ( const uint32_t x, const uint32_t y ) {
  if ( x >= 0 && x < 80 && y >= 0 && y < 80 ) {
    return nums[ y ][ x ];
  } else {

  }
}

int main() {
  int i, j, result, n = 0;
  astar_t * as;
  char ( *lines )[ 6 ] = NULL;
  static int path[ 80 ];
  FILE *f = fopen("83_matrix.txt", "r");
  if ( !f ) {
    fprintf(stderr, "Error opening file\n");
    return 1;
  } 
  if ( !( lines = malloc( 6400 * sizeof *lines ) ) ) {
    fprintf (stderr, "Error in malloc\n");
    return 1;
  }
  while (n < 6400 && fgets( lines[ n ], 6, f)) {
    char *p = lines[ n ];                  
    p[ 4 ] = '\0'; 
    ++n;                         
  }
  n = 0;
  for ( i = 0; i < 80; ++i ) {
    for ( j = 0; j < 80; ++j ) {
      nums[ i ][ j ] = (uint32_t)atoi( lines[ n ] );
      ++n;
    }
  }
  as = astar_new( 80, 80, get_map_cost, NULL);
  astar_set_movement_mode (as, DIR_CARDINAL);
  astar_set_origin( as, 0, 0);
  result = astar_run( as, 0, 0, 79, 79);
  if (astar_have_route (as)) {
    direction_t * directions, * dir;
    uint32_t s, num_steps;
    int x, y;

    num_steps = astar_get_directions (as, &directions);

    x = 0;
    y = 0;
    dir = directions;
    uint32_t sum = 0;
    for (i = 0; i < num_steps; i++, dir++) {
      assert( x < 80 );
      assert( x >= 0 );
      assert( y >= 0 );
      assert( y < 80 );
      map[ y ][ x ] = 'X';
      sum += nums[ y ][ x ];
      

      // Get the next (x, y) co-ordinates of the map.
      x += astar_get_dx (as, *dir);
      y += astar_get_dy (as, *dir);
    }
    sum += nums[ 79 ][ 79 ];
    printf ("Route found in %d steps at a cost of %u\n", num_steps, sum);
  }
  for ( i = 0; i < 80; ++i ) {
    for ( j = 0; j < 80; ++j ) {
      if ( map[ i ][ j ] == 'X' ) printf("%c", map[ i ][ j ]);
      else
        printf("-");
    }
    printf("\n");
  }

  return 0;
}