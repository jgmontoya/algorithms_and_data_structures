/*
Task: To sort an array A[0..n-1]
Main idea: To the left of the j-index everything is sorted.
           On each iteration we move the value that on A[j] so that A[0..j] is sorted
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

void insertionSort(int* A, int n) {
  for (int j=1; j < n; j++) {
    int key = A[j];
    int i = j-1;
    while (i >= 0 && A[i] > key) {
      swap(A, i+1, i); //A[i+1] <-> A[i]
      i--;
    }
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
  insertionSort(A, array_size);
  for (int i=0; i < array_size; i++) printf("A[%i] = %i\n", i, A[i]);
  destroy_array(A);
  return 0;
}
