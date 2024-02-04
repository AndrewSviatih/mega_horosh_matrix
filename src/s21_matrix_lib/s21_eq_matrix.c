#include "s21_matrix.h"

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

// int main () {
//   matrix_t A = {0};
//   matrix_t B = {0};
//   s21_create_matrix(2, 2, &A);
//   s21_create_matrix(2, 2, &B);
//   A.matrix[0][0] = 1.01;
//   A.matrix[0][1] = -2;
//   A.matrix[1][0] = 3.05;
//   A.matrix[1][1] = -4;
//   B.matrix[0][0] = 1.01;
//   B.matrix[0][1] = -2;
//   B.matrix[1][0] = 3.05;
//   B.matrix[1][1] = -4;
//   int result = s21_eq_matrix(&A, &B);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
// }