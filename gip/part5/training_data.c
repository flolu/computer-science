#include<stdio.h>
#include<math.h>

int main() {
  int jump_counter = 0;
  float biggest, second_biggest, smallest, average;

  printf("Sprungdaten eingeben:\n");
  while (1) {
    float x;
    scanf("%f", &x);
    if (x <= 0)
      break;
    average = ((average * jump_counter) + x) / (jump_counter + 1);
    if (jump_counter == 0) {
      biggest = x;
      smallest = x;
      second_biggest = x;
    }
    if (x > biggest) {
      second_biggest = biggest;
      biggest = x;
    }
    if (x < smallest)
      smallest = x;
    jump_counter++;
  }

  printf("Anzahl Sprünge: %d\n", jump_counter);
  printf("Größte Weite: %.2f\n", biggest);
  printf("Zweitgrößte Weite: %.2f\n", second_biggest);
  printf("Kleinste Weite: %.2f\n", smallest);
  printf("Mittlere Weite: %.2f\n", average);
  printf("Differenz der größten und kleinsten Weite: %.2f\n", fabs(biggest - smallest));

  return 0;
}