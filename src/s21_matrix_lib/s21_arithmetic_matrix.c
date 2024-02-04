#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;

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
        flag = INCORRECT_MATRIX;
      }
    } else {
      flag = CALC_ERROR;
    }
  } else {
    flag = INCORRECT_MATRIX;
  }

  return flag;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;

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
        flag = INCORRECT_MATRIX;
      }
    } else {
      flag = CALC_ERROR;
    }
  } else {
    flag = INCORRECT_MATRIX;
  }

  return flag;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int flag = OK;

  if (!s21_is_Emty(A)) {
    flag = s21_create_matrix(A->rows, A->columns, result);
    if (result != NULL && flag == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    } else {
      flag = INCORRECT_MATRIX;
    }
  } else {
    flag = INCORRECT_MATRIX;
  }

  return flag;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;
  if (!s21_is_Emty(A) && !s21_is_Emty(B) && A->columns == B->rows) {
    flag = s21_create_matrix(A->columns, B->rows, result);
    if (result != NULL && flag == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          for (int k = 0; k < A->rows; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    } else {
      flag = INCORRECT_MATRIX;
    }
  } else {
    flag = CALC_ERROR;
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

// int main () {
//   matrix_t m = {0};
//   const int rows = rand() % 100 + 1;
//   const int cols = rand() % 100 + 1;
//   s21_create_matrix(rows, cols, &m);
//   matrix_t mtx = {0};
//   const int rows1 = rand() % 100 + 1;
//   const int cols1 = rand() % 100 + 1;
//   s21_create_matrix(rows1, cols1, &mtx);

//   for (int i = 0; i < rows; i++) {
//     for (int j = 0; j < cols; j++) {
//       m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
//     }
//   }
//   for (int i = 0; i < rows1; i++) {
//     for (int j = 0; j < cols1; j++) {
//       mtx.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
//     }
//   }

//   matrix_t res = {0};
//   s21_sum_matrix(&m, &mtx, &res);
//   s21_remove_matrix(&m);
//   s21_remove_matrix(&mtx);
//   s21_remove_matrix(&res);
// }