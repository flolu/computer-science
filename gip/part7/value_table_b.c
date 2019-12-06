#include<stdio.h>
#include <stdarg.h>

double cubic(double x) { return x*x*x+2.0; }

void wertetabelle(double (*f)(double), int count, ...) {
  va_list args;
  va_start(args, count);
  for (int i = 0; i < count; i++) {
    double x = va_arg(args, double);
    printf("f(%lf) = %lf\n", x, f(x));
  }
  va_end(args);
}

int main() {
  wertetabelle(cubic, 4, 3.0, 7.0, 11.0, 41.0);
  return 0;
}