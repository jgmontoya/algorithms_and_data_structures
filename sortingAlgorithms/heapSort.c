/*
Main idea: Create a max heap, move that element to the last position, then repeat with smaller heap.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "basic_operations.h"

int parent(int i) {
  return i/2;
}

int left(int i) {
  return 2*i;
}

int right(int i) {
  return 2*i+1;
}

void max_heapify(int* A, int heap_size, int i) {
  int l = left(i);
  int r = right(i);
  int max = i;
  if (l <= heap_size && A[l] > A[max]) max = l;
  if (r <= heap_size && A[r] > A[max]) max = r;
  if (max != i) {
    swap(A, max, i);
    max_heapify(A, heap_size, max);
  }
}

void build_max_heap(int* A, int n) {
  int heap_size = n;
  int i = parent(n);
  while (i >= 1) {
    max_heapify(A, n, i);
    i--;
  }
}

void heapSort(int* A, int n) {
  build_max_heap(A, n);
  int heap_size = n;
  for (int i=n; i >= 2; i--) {
    swap(A, i, 1);
    heap_size--;
    max_heapify(A, heap_size,1);
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
  int* A = generate_array(array_size+1);
  for (int i = 1; i < array_size+1; i++) A[i] = randint(0, num_limit);
  printf("\n");
  heapSort(A, array_size);
  for (int i=1; i < array_size+1; i++) printf("A[%i] = %i\n", i, A[i]);
  destroy_array(A);
  return 0;
}
