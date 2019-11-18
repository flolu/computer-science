#include <stdio.h>
#include <math.h>

int main()
{
  float accuracy;
  printf("Genauigkeit eingeben: ");
  scanf("%f", &accuracy);

  float pi = 0;
  int n = 0;

  while (1)
  {
    float numerator = n % 2 == 0 ? 1 : -1;
    float denominator = 2 * n + 1;
    float summand = numerator / denominator;

    if (fabs(summand) < accuracy)
      break;

    pi += summand;
    n++;
  }
  pi *= 4;

  printf("Pi nach %d Iterationen: %f\n", n, pi);
  printf("Abweichung: %f\n", fabs(pi - M_PI));

  return 0;
}