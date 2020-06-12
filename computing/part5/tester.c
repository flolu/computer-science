#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>

unsigned W = sizeof(unsigned) * 8;
unsigned x, y;

unsigned a() { return ~((x | (~x + 1)) >> (W - 1)) & 1; }
unsigned b() { return ~((x >> (W - 1)) >> 1); }
unsigned c() { return ~(~x | (y ^ (INT_MIN + INT_MAX))); }
unsigned d() { return x ^ (INT_MIN + INT_MAX); }
unsigned e() { return ((x ^ y) & ~y) | (~(x ^ y) & y); }
unsigned f() { return ((x < 0) ? (x + 3) : x) >> 2; }

void test_all(unsigned expected_value)
{
  printf("a: %0x ?== %0x (match: %d)\n", expected_value, a(), expected_value == a());
  printf("b: %0x ?== %0x (match: %d)\n", expected_value, b(), expected_value == b());
  printf("c: %0x ?== %0x (match: %d)\n", expected_value, c(), expected_value == c());
  printf("d: %0x ?== %0x (match: %d)\n", expected_value, d(), expected_value == d());
  printf("e: %0x ?== %0x (match: %d)\n", expected_value, e(), expected_value == e());
  printf("f: %0x ?== %0x (match: %d)\n", expected_value, f(), expected_value == f());
}

int main(void)
{
  srand(time(NULL));
  x = (~rand()) + 1;
  y = (~rand()) + 1;

  printf("1:\n");
  test_all(x);

  printf("\n2:\n");
  test_all(x & y);

  printf("\n3:\n");
  test_all((x < 0 ? 1 : -1));

  return 0;
}