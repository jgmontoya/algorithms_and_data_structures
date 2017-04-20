
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
