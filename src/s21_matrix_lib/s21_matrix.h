#ifndef STRING_S21_MATRIX_H
#define STRING_S21_MATRIX_H

#include "stdio.h"
#include "stdlib.h"
// #include "string.h"
#include <math.h>

#include "stdarg.h"
#include "stdint.h"

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// void *s21_memchr(const void *str, int c, s21_size_t n);

#endif  // STRING_S21_MATRIX_H

int s21_is_Emty(matrix_t *matrix);

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);
