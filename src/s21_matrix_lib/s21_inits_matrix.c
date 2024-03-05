#include "../s21_matrix.h"

int s21_create_matrix(const int rows, const int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0) return INCORRECT_MATRIX;

  result->rows = rows;
  result->columns = columns;
  result->matrix = calloc(rows, sizeof(double *));

  if (!result->matrix) return INCORRECT_MATRIX;

  for (int i = 0; i < rows; i++) {
    result->matrix[i] = calloc(columns, sizeof(double));
    if (!result->matrix[i]) {
      /* clean-up before exit */
      for (int j = 0; j < i; j++) free(result->matrix[j]);
      free(result->matrix);

      return INCORRECT_MATRIX;
    }
  }
  return OK;
}

void s21_remove_matrix(matrix_t *const A) {
  if (A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) free(A->matrix[i]);
    free(A->matrix);
  }
}