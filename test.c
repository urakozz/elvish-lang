#include <stdio.h>
int main( ) {

  int size;

  printf( "Enter a size :");
  scanf("%d", &size);

  printf( "\nSize is: %d\n", size);

  int mx[size][size];
  int maximums[size];

  int i, j, max;

  for ( i = 0; i < size; i ++ ) {
    for ( j = 0; j < size; j ++ ) {
      printf("Input %i, %i element of matrix:", i, j);
      scanf("%i", &mx[i][j]);
      printf( "\n" );
      if (0 == j) {
        max = mx[i][j];
      } else {
        if (mx[i][j] > max) {
          max = mx[i][j];
        }
      }
    }
    maximums[i] = max;
  }

  printf("\nunsorted mx:\n");
  for ( i = 0; i < size; i ++ ) {
    for ( j = 0; j < size; j ++ ) {
      printf( "%d ", mx[i][j] );
    }

    printf( "\n" );
   }

  printf("\nmaximums:\n");
  for ( i = 0; i < size; i ++ ) {
    printf( "%d\n", maximums[i] );
  }

   int tmp, k;
   // slow insertion sort because i'm lazy
   for ( i = 0; i < size; i ++ ) {
     for (j = i; j > 0; j--) {
       if (maximums[j]>maximums[j-1]) {
         tmp = maximums[j];
         maximums[j] = maximums[j-1];
         maximums[j-1] = tmp;

          //OMG such a boring language
          for( k = 0; k < size; k ++ ){
            tmp = mx[j][k];
            mx[j][k] = mx[j-1][k];
            mx[j-1][k] = tmp;
          }
         }
       }
     }

     printf("\nsorted maximums:\n");
     for ( i = 0; i < size; i ++ ) {
          printf( "%d\n", maximums[i] );
     }

     printf("\nsorted mx:\n");
     for ( i = 0; i < size; i ++ ) {
        for ( j = 0; j < size; j ++ ) {
            printf( "%d ", mx[i][j] );
        }

        printf( "\n" );
      }

     return 0;
}
