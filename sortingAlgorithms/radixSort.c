/*
Main idea: Sort successively and in a stable manner from the least to the most sugnificant digit
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>
#include "basic_operations.h"

int get_digit(int N, int d) {
  return (N/(int)pow(10, d-1))%10;
}

void countingSort_by_digit(int* A, int n, int d) {
  int* B = generate_array(n);
  for (int i = 0; i < n; i++) B[i] = A[i];
  int* C = generate_array(11);
  for (int j = 0; j < n; j++) C[get_digit(A[j], d)]++;
  for (int i = 1; i <= 10; i++) C[i] += C[i-1];
  for (int j=n-1; j >= 0; j--) {
    A[C[get_digit(B[j], d)]-1] = B[j];
    C[get_digit(B[j], d)]--;
  }
  destroy_array(B);
  destroy_array(C);
}

void radixSort(int* A, int n) {
  int digits = (int)log10(A[get_max_i(A, 0, n)]) + 1;
  for (int i = 1; i <= digits; i++) {
    countingSort_by_digit(A, n, i);
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
  radixSort(A, array_size);
  for (int i=0; i < array_size; i++) printf("A[%i] = %i\n", i, A[i]);
  destroy_array(A);
  return 0;
}
