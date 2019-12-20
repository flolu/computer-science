#include<stdio.h>

int linearSearch(int n, int a[], int l) {
  for (int i = 0; i < l; i++) {
    if (a[i] == n) return i;
  }
  return -1;
}

int binarySearch(int n, int a[], int l) {
  int range_start = 0, range_end = l - 1;
  while (1) {
    int middle = (range_start + range_end) / 2;
    if (a[middle] == n) return middle;
    if (range_start > range_end) return -1;
    if (a[middle] < n) range_start = middle + 1;
    else range_end = middle - 1;
  }
}

int main(void) {
  int a[10] = {-4434, -435, -3, 0, 4, 34, 46, 7657, 765666};
  int position = linearSearch(4, a, 9);
  int position = binarySearch(4434, a, 9);
  printf("Found element at position %d\n", position);
  return 0;
}