/*
Main idea: Divide and conquer algorithm.
           Split the array in two equally-sized arrays and sort them, then merge.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "basic_operations.h"

void merge(int* A, int p, int q, int r) {
  int* L = generate_array(q-p+2);
  int* R = generate_array(r-q+1);
  for (int k = 0; k <= q-p; k++) L[k] = A[p+k];
  for (int k = 0; k <= r-q-1; k++) R[k] = A[q+1+k];
  L[q-p+1] = R[r-q] = INT_MAX;
  int i = 0;
  int j = 0;
  for (int k = p; k <= r; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    }
    else {
      A[k] = R[j];
      j++;
    }
  }
  destroy_array(L);
  destroy_array(R);
}

void mergeSort(int* A, int i, int r) {
  if (i < r) {
    int q = (i+r)/2; // Find midpoint
    mergeSort(A, i, q); // Sort first half
    mergeSort(A, q+1, r); // Sort second half
    merge(A, i, q, r); // Merge the sorted parts
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
  for (int i = 0; i < array_size; i++) A[i] = rand()%num_limit;
  mergeSort(A, 0, array_size);
  for (int i=0; i < array_size; i++) printf("A[%i] = %i\n", i, A[i]);
  destroy_array(A);
  return 0;
}
