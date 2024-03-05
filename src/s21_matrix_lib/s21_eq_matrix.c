#include "../s21_matrix.h"

#define SUCCESS 1
#define FAILURE 0

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;

  if (!s21_is_Emty(A) && !s21_is_Emty(B) && A->columns == B->columns &&
      A->rows == B->rows) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (roundl(A->matrix[i][j] * powl(10, 7)) !=
            roundl(B->matrix[i][j] * powl(10, 7))) {
          res = FAILURE;
          break;
        }
      }
      if (res == FAILURE) break;
    }
  } else {
    res = FAILURE;
  }

  return res;
}