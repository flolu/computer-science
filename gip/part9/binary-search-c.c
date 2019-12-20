#include<stdio.h>

int binarySearch(int n, int a[], int l) {
  int* range_start = &a[0];
  int* range_end = &a[l - 1];
  while(1) {
    if (range_start > range_end) return -1;
    int* middle = ((range_end - range_start) / 2) + range_start;
    if (*middle == n) return middle - &a[0];
    if (*middle > n) range_end = middle - 1;
    else range_start = middle + 1;
  }
}

int main(void) {
  int n;
  printf("Zahl eingeben: ");
  scanf("%d", &n);
  int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
  int position_binary_search = binarySearch(n, primes, 25);
  printf("Suchergebnis der binären Suche: %d\n", position_binary_search);
  return 0;
}