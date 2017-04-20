/*
Main idea: Select the minimum value of A[0..n-1] and place it on A[0].
           On each iteration we then select the min value of the remaining array.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "basic_operations.h"

void selectionSort(int* A, int n) {
  for (int i = 0; i < n; i++) {
    int min_i = get_min_i(A, i ,n);
    swap(A, i, min_i);
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
  selectionSort(A, array_size);
  for (int i=0; i < array_size; i++) printf("A[%i] = %i\n", i, A[i]);
  destroy_array(A);
  return 0;
}
