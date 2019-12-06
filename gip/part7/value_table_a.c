#include<stdio.h>

double quadrat(double x) { return x*x; }

void wertetabelle(double (*f)(double), double min, double max, double step) {
  int steps = (max - min) / step;
  for (int i = 0; i <= steps; i++) {
    double x = min + (i * step);
    printf("f(%lf) = %lf\n", x, f(x));
  }
}

int main() {
  wertetabelle(quadrat, 0.0, 10.0, 1.0);
  return 0;
}