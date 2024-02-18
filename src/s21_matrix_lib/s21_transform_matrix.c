#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int flag = 0;
  if (!s21_is_Emty(A)) {
    flag = s21_create_matrix(A->columns, A->rows, result);
    if (result != NULL && flag == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    } else {
      flag = 1;
    }
  } else {
    flag = 1;
  }
  return flag;
}