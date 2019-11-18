#include <stdio.h>

int main()
{
  int x = 49;
  printf("x: %d\n\n", x);

  printf("%s", !(x >= 0 && x < 50 || x > 50 && x <= 100) ? "true\n" : "false\n");
  printf("x: %d\n\n", x);

  printf("%s", (x++ == 49 || x-- == 49) ? "true\n" : "false\n");
  printf("x: %d\n\n", x);

  printf("%s", (!(x >= 0 && x < 50 || x > 50 && x <= 100)) ? "true\n" : "false\n");
  printf("x: %d\n\n", x);

  return 0;
}