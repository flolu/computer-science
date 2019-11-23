#include<stdio.h>
#include<math.h>

struct vector2d {
  float x;
  float y;
};

int main(){
  struct vector2d p1, p2, p3;
  printf("Punkt 1 eingeben: "); scanf("%f %f", &p1.x, &p1.y);
  printf("Punkt 2 eingeben: "); scanf("%f %f", &p2.x, &p2.y);
  printf("Punkt 3 eingeben: "); scanf("%f %f", &p3.x, &p3.y);

  struct vector2d a = { p1.x - p2.x, p1.y - p2.y };
  struct vector2d b = { p1.x - p3.x, p1.y - p3.y };

  float area = (a.x * b.y - a.y * b.x) / 2;
  printf("%f Flächeneinheiten\n", fabs(area));

  return 0;
}