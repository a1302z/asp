#include <stdio.h>
#include <string.h>

#define MATSIZE 8

extern void _asm_matQuad(float* m1, float* m2, float* result);


void printMatrix(float* matrix, int rows, int cols) {
  printf("matrix[%d][%d] [\n", cols, rows);

  int i;
  for (i = 0; i < cols; i++) {
    printf("  [");

    int j;
    for (j = 0; j < rows; j++) {
      printf(" %.3f", *(matrix + i*cols + j));
      (j < rows - 1) ? printf(",") : printf("");
    }

    (i < cols - 1) ? printf(" ],\n") : printf(" ]\n");
  }

  printf("]\n");
}


int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Usage: %s <number>\n", argv[0]);
    return 1;
  }

  float matrix[MATSIZE][MATSIZE] = {
    { 1.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f },
    { 0.514f, 0.000f, 0.486f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f },
    { 0.000f, 0.514f, 0.000f, 0.486f, 0.000f, 0.000f, 0.000f, 0.000f },
    { 0.000f, 0.000f, 0.514f, 0.000f, 0.486f, 0.000f, 0.000f, 0.000f },
    { 0.000f, 0.000f, 0.000f, 0.514f, 0.000f, 0.486f, 0.000f, 0.000f },
    { 0.000f, 0.000f, 0.000f, 0.000f, 0.514f, 0.000f, 0.486f, 0.000f },
    { 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.514f, 0.000f, 0.486f },
    { 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 1.000f },
  };

  float result[MATSIZE][MATSIZE] = {
    { 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f },
    { 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f },
    { 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f },
    { 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f },
    { 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f },
    { 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f },
    { 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f },
    { 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f },
  };

  float temp[MATSIZE][MATSIZE];
  memcpy(&temp[0][0], &matrix[0][0], MATSIZE*MATSIZE*sizeof(float));

  int loops = atoi(argv[1]);

  int i;
  for (i = 0; i < loops; i++) {
    _asm_matQuad(&temp[0][0], &matrix[0][0], &result[0][0]);
    memcpy(&temp[0][0], &result[0][0], MATSIZE*MATSIZE*sizeof(float));
  }

  printMatrix(&result[0][0], MATSIZE, MATSIZE);

  return 0;
}
