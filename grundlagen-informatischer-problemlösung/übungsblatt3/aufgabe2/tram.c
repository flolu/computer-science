#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct station
{
  int line;
  int stop;
};

struct trip
{
  struct station start;
  struct station end;
};

bool compare_stations(struct trip t, struct station s1, struct station s2)
{
  return (t.start.line == s1.line && t.start.stop == s1.stop && t.end.line == s2.line && t.end.stop == s2.stop) ||
         (t.start.line == s2.line && t.start.stop == s2.stop && t.end.line == s1.line && t.end.stop == s1.stop);
}

bool is_short_trip(struct trip t)
{
  if (compare_stations(t, (struct station){5, 2}, (struct station){4, 2}) ||
      compare_stations(t, (struct station){0, 0}, (struct station){2, 1}))
    return false;

  if (abs(t.start.stop - t.end.stop) == 1 &&
      (t.start.line == t.end.line ||
       t.start.line == 0 || t.end.line == 0))
    return true;

  if (abs(t.start.line % 5 - t.end.line % 5) == 1 &&
      t.start.stop == 2 && t.end.stop == 2)
    return true;

  return false;
}

int count_zone_crosses(struct trip t)
{
  if (t.start.stop > 2 && t.end.stop > 2 && t.start.line != t.end.line)
    return 2;
  if ((t.start.stop > 2 && t.end.stop < 3) || (t.start.stop < 3 && t.end.stop > 2))
    return 1;

  return 0;
}

int count_end_stops(struct trip t)
{
  return (t.start.stop == 5 ? 1 : 0) + (t.end.stop == 5 ? 1 : 0);
}

bool is_start_equal_to_end(struct trip t)
{
  return t.start.line == t.end.line && t.start.stop == t.end.stop;
}

int main()
{
  int start_input, end_input;
  printf("Starthaltestelle: ");
  scanf("%d", &start_input);
  printf("Zielhaltestelle: ");
  scanf("%d", &end_input);

  struct trip trip = {
      {(start_input / 10) % 10, start_input % 10},
      {(end_input / 10) % 10, end_input % 10}};

  int price = 0;
  price = is_short_trip(trip) ? 2 : 3;
  price += count_zone_crosses(trip);
  price += count_end_stops(trip);
  price = is_start_equal_to_end(trip) ? 0 : price;

  printf("%d Euro\n", price);
  return 0;
}