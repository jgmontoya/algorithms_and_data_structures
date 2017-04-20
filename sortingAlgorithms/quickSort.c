/*
Main idea: Figure out the sorted position of a pivot element q, then sort A[0..q-1] and A[q+1..n-1]
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "basic_operations.h"



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

int main(int argc, char const *argv[]) {
  //input: single number n (size of the array to create)
  if (argc != 3) {
    printf("Usage: %s <n> <k>\n", argv[0]);
    printf("\t <n>: Length of the array to sort (array will be generated randomly)\n");
    printf("\t <k>: Generated integers will be in range 0..k-1\n");
    return 1;
  }
  srand(time(NULL));
  int array_size = strtol(argv[1], NULL, 10);
  int num_limit = strtol(argv[2], NULL, 10);
  int* A = generate_array(array_size);
  for (int i = 0; i < array_size; i++) A[i] = randint(0, num_limit);
  quickSort(A, 0, array_size-1);
  for (int i=0; i < array_size; i++) printf("A[%i] = %i\n", i, A[i]);
  destroy_array(A);
  return 0;
}
