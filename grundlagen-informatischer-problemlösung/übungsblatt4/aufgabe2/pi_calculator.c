#include <stdio.h>
#include <math.h>

int main()
{
  float accuracy;
  printf("Genauigkeit eingeben: ");
  scanf("%f", &accuracy);

  float pi = 0;
  int n = 0;
  int is_done = 0;
  while (!is_done)
  {
    int numerator = n % 2 == 0 ? 1 : -1;
    float denominator = 2 * n + 1;
    float summand = numerator / denominator;
    if (fabs(summand) < accuracy)
    {
      is_done = 1;
    }
    pi += summand;
    n++;
  }
  pi *= 4;

  printf("Pi nach %d Iterationen: %f\n", n, pi);
  printf("Abstand zum genauen Pi: %f\n", fabs(pi - M_PI));

  return 1;
}