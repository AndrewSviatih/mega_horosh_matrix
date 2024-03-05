#include "../s21_matrix.h"

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

bool validate(matrix_t *matrix) {
  return matrix && (matrix->rows > 0) && (matrix->columns > 0) &&
      matrix->matrix;
}
