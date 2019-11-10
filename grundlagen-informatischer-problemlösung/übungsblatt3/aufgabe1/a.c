#include <stdio.h>

int main() {
  int x = 49;
  printf("%s", !(x >= 0 && x < 50 || x > 50 && x <= 100) ? "true\n" : "false\n");
  printf("%s", (x++ == 49 || x-- == 49) ? "true\n" : "false\n");
  printf("%s", (!(x >= 0 && x < 50 || x > 50 && x <= 100)) ? "true\n" : "false\n");
  int k; scanf("%d", &k);
  printf("%s", (!(k > 0 && k%10 <= 7) == (!(k > 0) || !(k%10 <= 7))) ? "true\n" : "false\n");
  return 0;
}