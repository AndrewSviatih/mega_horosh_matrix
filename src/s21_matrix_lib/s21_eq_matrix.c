#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;

  if (s21_is_Emty(A) == 0 && s21_is_Emty(B) == 0 && A->columns == B->columns &&
      A->rows == B->rows) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (round(A->matrix[i][j] * pow(10, 7)) !=
            round(B->matrix[i][j] * pow(10, 7))) {
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

// int main () {

//     matrix_t m = {0};
//     int rows = rand() % 100 + 1;
//     int cols = rand() % 100 + 1;
//     rows = -rows;
//     cols = -cols;
//     s21_create_matrix(rows, cols, &m);
//     matrix_t mtx = {0};
//     const int rows1 = rand() % 100 + 1;
//     const int cols1 = rand() % 100 + 1;
//     s21_create_matrix(rows1, cols1, &mtx);
//     s21_eq_matrix(&m, &mtx);

//     s21_remove_matrix(&m);
//     s21_remove_matrix(&mtx);
// }