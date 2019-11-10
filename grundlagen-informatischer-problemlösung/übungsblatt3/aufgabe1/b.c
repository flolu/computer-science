#include <stdbool.h>

int main() {

  // 1
  int m, n;
  bool one = !(m > 10) && (n != 0);

  // 2
  int x, y, z;
  bool two = (x > 0) && (y > 0) && (z > 0) && (x % 5 == 0) && (y % 5 == 0) && (z % 5 == 0);

  // 3
  int a;
  bool three = (a >= 1 && a <= 10) || (a < -7);

  // 4
  bool four = true;

  return 0;
}