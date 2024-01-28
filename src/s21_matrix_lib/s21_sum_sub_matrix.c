#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {

  int flag = 0;

  if (!s21_is_Emty(A) && !s21_is_Emty(B)) {
    if (A->columns == B->columns && A->rows == B->rows) {
      flag = s21_create_matrix(A->rows, A->columns, result);
      if (result != NULL) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
          }
        }
      } else {
        flag = 1;
      }
    } else {
      flag = 2;
    }
  } else {
    flag = 1;
  }

  return flag;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {

  int flag = 0;

  if (!s21_is_Emty(A) && !s21_is_Emty(B)) {
    if (A->columns == B->columns && A->rows == B->rows) {
      flag = s21_create_matrix(A->rows, A->columns, result);
      if (result != NULL) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
          }
        }
      } else {
        flag = 1;
      }
    } else {
      flag = 2;
    }
  } else {
    flag = 1;
  }

  return flag;
}