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
  int n;
  printf("Zahl eingeben: ");
  scanf("%d", &n);
  int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
  int position_linear_search = linearSearch(n, primes, 25);
  int position_binary_search = binarySearch(n, primes, 25);
  printf("Suchergebnis der linearen Suche: %d\n", position_linear_search);
  printf("Suchergebnis der binären Suche: %d\n", position_binary_search);
  return 0;
}