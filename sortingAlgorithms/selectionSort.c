/*
Main idea: Select the minimum value of A[0..n-1] and place it on A[0].
           On each iteration we then select the min value of the remaining array.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generate_array(int n) {
  int* array = malloc(n*sizeof(int));
  return array;
}

void destroy_array(int* array) {
  free(array);
}

void swap(int* A, int i, int j) {
  // Swaps elements with indexes i and j in the array A
  int aux = A[i];
  A[i] = A[j];
  A[j] = aux;
}

int get_min_i(int* A, int i, int j) {
  // Returns index of the minimum value in A[i..j]
  int current_min = i;
  for (int k=i; k < j; k++) {
    if (A[k] < A[current_min]) {
      current_min = k;
    }
  }
  return current_min;
}

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
  for (int i = 0; i < array_size; i++) A[i] = rand()%num_limit;
  selectionSort(A, array_size);
  for (int i=0; i < array_size; i++) printf("A[%i] = %i\n", i, A[i]);
  destroy_array(A);
  return 0;
}
