#include <stdlib.h>

int* generate_array(int n) {
  int* array = calloc(n, sizeof(int));
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
  // Returns index of the minimum value in A[i..j-1]
  int current_min = i;
  for (int k=i; k < j; k++) {
    if (A[k] < A[current_min]) current_min = k;
  }
  return current_min;
}

int get_max_i(int* A, int i, int j) {
  // Returns index of the maximum value in A[i..j-1]
  int current_max = i;
  for (int k = i; k < j; k++) {
    if (A[k] > A[current_max]) current_max = k;
  }
  return current_max;
}

int randint(int min, int max) {
return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}
