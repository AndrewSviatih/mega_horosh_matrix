#include "s21_matrix.h"

int s21_is_Emty(matrix_t *matrix) {
  int res = OK;
  if (matrix == NULL || matrix->matrix == NULL || matrix->rows <= 0 ||
      matrix->columns <= 0) {
    res = INCORRECT_MATRIX;
  }
  return res;
}
