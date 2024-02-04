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

// int main () {

//   matrix_t A = {0};
//   // matrix_t B = {0};
//   matrix_t res = {0};
//   s21_create_matrix(10, 10, &A);
//   // s21_create_matrix(3, 3, &B);
//   for (int i = 0; i < A.rows; i++) {
//     for (int j = 0; j < A.columns; j++) {
//         A.matrix[i][j] = i;
//         printf("%lf ", A.matrix[i][j]);
//     }
//     printf("\n");
//   }
//   printf("\n");
//   // for (int i = 0; i < B.rows; i++) {
//   //   for (int j = 0; j < B.columns; j++) {
//   //       B.matrix[i][j] = i+j;
//   //       printf("%lf ", B.matrix[i][j]);
//   //   }
//   //   printf("\n");
//   // }
//   // printf("\n");

//   int flag = s21_transpose(&A, &res);
//   if (flag) {
//     printf("err");
//   } else {
//     for (int i = 0; i < A.columns; i++) {
//       for (int j = 0; j < A.rows; j++) {
//         printf("%lf ", res.matrix[i][j]);
//       }
//     printf("\n");
//     }
//   }
//   s21_remove_matrix(&A);
//   // s21_remove_matrix(&B);
//   s21_remove_matrix(&res);
// }