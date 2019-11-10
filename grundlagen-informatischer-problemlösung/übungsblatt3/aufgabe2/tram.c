#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct station {
  short unsigned int line;
  short unsigned int stop;
};

struct trip {
  struct station start;
  struct station end;
};

void validate_input(struct trip trip) {

}

bool is_short_trip(struct trip trip) {
  if ((trip.start.line == 5 && trip.start.stop == 2) && (trip.end.line == 4 && trip.end.stop == 2)) {
    return false;
  }
  if ((trip.start.line == 4 && trip.start.stop == 2) && (trip.end.line == 5 && trip.end.stop == 2)) {
    return false;
  }

  if ((trip.start.line == 0 && trip.start.stop == 0) && (trip.end.line == 2 && trip.end.stop == 1)) {
    return false;
  }
  if ((trip.start.line == 2 && trip.start.stop == 1) && (trip.end.line == 0 && trip.end.stop == 0)) {
    return false;
  }

  if (trip.start.line == trip.end.line && abs(trip.start.stop - trip.end.stop) == 1) {
    return true;
  }

  return false;
}

int count_zone_crosses(struct trip trip) {
  return 0;
}

int count_end_stops(struct trip trip) {
  return 0;
}

int main() {
  int start = 00, end = 00;

  printf("Starthaltestelle: ");
  scanf("%d", &start);
  printf("Zielhaltestelle: ");
  scanf("%d", &end);

  struct station start_station = { (start - (start % 10)) / 10, start % 10 };
  struct station end_station = { (end - (end % 10)) / 10, end % 10 };
  struct trip trip = { start_station, end_station };

  validate_input(trip);

  int price = 3;

  if (is_short_trip(trip)) {
    price = 2;
  }

  int zone_crosses = count_zone_crosses(trip);
  price += zone_crosses;

  int end_stops = count_end_stops(trip);
  price += end_stops;

  printf("is_short_trip: %d, zone_crosses: %d, end_stops: %d\n", is_short_trip(trip), zone_crosses, end_stops);
  printf("%d Euro\n", price);
  return 0;
}