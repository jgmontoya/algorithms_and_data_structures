/*
Main idea: Count the number of elements of a given key, then reproduce the elements sorted
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "basic_operations.h"

void countingSort(int* A, int n, int k) {
  int* B = generate_array(n);
  for (int i = 0; i < n; i++) B[i] = A[i];
  int* C = generate_array(k+1);
  for (int j = 0; j < n; j++) C[A[j]]++;
  for (int i = 1; i <= k; i++) C[i] += C[i-1];
  for (int j=n-1; j >= 0; j--) {
    A[C[B[j]]-1] = B[j];
    C[B[j]] = C[B[j]] - 1;
  }
  destroy_array(B);
  destroy_array(C);
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
  countingSort(A, array_size, num_limit);
  for (int i=0; i < array_size; i++) printf("A[%i] = %i\n", i, A[i]);
  destroy_array(A);
  return 0;
}
