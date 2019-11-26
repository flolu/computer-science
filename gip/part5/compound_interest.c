#include<stdio.h>
#include<math.h>

int main(void) {
  double capital, interest_rate;
  int years;
  printf("Startkapital in EUR: "); scanf("%lf", &capital);
  printf("Zinssatz in Prozent: "); scanf("%lf", &interest_rate);
  printf("Laufzeit in Jahren: "); scanf("%d", &years);

  printf("┏━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━┓\n");
  printf("┃ Jahr\t┃ Kapital in EUR\t┃\n");
  printf("┣━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━┫\n");
  for (int i = 1; i <= years; i++) {
    double current_capital = capital * pow((1 + (interest_rate / 100)), i);
    printf("┃ %d\t┃ %.2lf\t\t┃\n", i, current_capital);
  }
  printf("┗━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┛\n");
  return 0;
}