#ifndef STRING_S21_MATRIX_H
#define STRING_S21_MATRIX_H

#include <float.h>
#include <math.h>

#include "stdarg.h"
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"

enum { OK = 0, INCORRECT_MATRIX = 1, CALC_ERROR = 2 };

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;
#endif  // STRING_S21_MATRIX_H

int s21_is_Emty(matrix_t *matrix);

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
double s21_get_determinant(matrix_t *A);

// helpers for complements & determinant
double get_complement(int cur_row, int cur_col, double determinant);
void minor_matrix(matrix_t *A, matrix_t *minorA, int row, int column);
