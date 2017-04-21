/*
Main idea: Use a pivot to search for the k smallest element, discarding the partition that is known to not contain the answer.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "sortingAlgorithms/basic_operations.h"

int partition(int* A, int p, int r) {
  int i = p-1;
  int j = p;
  while (j <= r) {
    if (A[j] <= A[r]) {
      i++;
      swap(A, i, j);
    }
    j++;
  }
  return i;
}

int random_partition(int* A, int p, int r) {
  int i = randint(p, r);
  swap(A, r, i);
  return partition(A, p, r);
}

void quickSort(int* A, int p, int r) {
  if (p < r) {
    int q = random_partition(A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q+1, r);
  }
}

int randomizedSelect(int* A, int p, int r, int i) {
  if (p == r) return A[p];
  int q = random_partition(A, p, r);
  int k = q - p + 1;
  if (i == k) return A[q];
  if (i < k) randomizedSelect(A, p, q-1, i);
  if (i > k) randomizedSelect(A, q+1, r, i-k);
}

int main(int argc, char const *argv[]) {
  //input: single number n (size of the array to create)
  if (argc != 4) {
    printf("Usage: %s <n> <m> <k>\n", argv[0]);
    printf("\t <n>: Length of the array to sort (array will be generated randomly)\n");
    printf("\t <m>: Generated integers will be in range 0..m-1\n");
    printf("\t <k>: kth smallest number searched");
    return 1;
  }
  srand(time(NULL));
  int array_size = strtol(argv[1], NULL, 10);
  int num_limit = strtol(argv[2], NULL, 10);
  int k = strtol(argv[3], NULL, 10);
  int* A = generate_array(array_size);
  for (int i = 0; i < array_size; i++) A[i] = randint(0, num_limit);
  int res = randomizedSelect(A, 0, array_size-1, k);
  for (int i=0; i < array_size; i++) printf("A[%i] = %i\n", i, A[i]);
  printf("The %i-th smallest number is %i", k, res);
  destroy_array(A);
  return 0;
}
