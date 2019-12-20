#include<stdio.h>

void generate_magic_square(int n) {
  int square[n][n];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      square[i][j] = 0;

  int row = n - 1, column = n / 2;
  int successor = 2;
  square[row][column] = 1;

  while(successor <= n * n) {
    row = row == n - 1 ? 0 : row + 1;
    column = column == n - 1 ? 0 : column + 1;
    if (square[row][column] == 0) {
      square[row][column] = successor;
      successor++;
    } else {
      while (1) {
        row = row == n - 1 ? 0 : row + 1;
        column = column == 0 ? n - 1 : column - 1;
        if (square[row][column] == 0) {
          square[row][column] = successor;
          successor++;
          break;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      printf(" %d ", square[i][j]);
    printf("\n");
  }
  printf("\n");
}

int main(void) {
  int n;
  printf("Ungerade Zahl eingeben: ");
  scanf("%d", &n);
  generate_magic_square(n);
  return 0;
}