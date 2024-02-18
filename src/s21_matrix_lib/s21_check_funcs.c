#include "s21_matrix.h"

int s21_is_Emty(matrix_t *matrix) {
  int res = OK;
  if (matrix == NULL || matrix->matrix == NULL) {
    if (matrix->rows <= 0 || matrix->columns <= 0) {
      res = INCORRECT_MATRIX;
    }
    res = INCORRECT_MATRIX;
  }
  return res;
}

int is_matrix_can_inverse(matrix_t *A) {
  double determinant = 0.0;
  s21_determinant(A, &determinant);
  return fabs(determinant) > 1e-6;
}
