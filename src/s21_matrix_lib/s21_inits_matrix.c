#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int err = OK;
  double *ptr = NULL;

  if (rows < 1 || columns < 1) {
    err = INCORRECT_MATRIX;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)malloc(rows * sizeof(double *));
    if (result->matrix == NULL) {
      err = INCORRECT_MATRIX;
    } else {
      ptr = (double *)malloc(rows * columns * sizeof(double));
      if (ptr == NULL) {
        free(result->matrix);
        err = INCORRECT_MATRIX;
      } else {
        for (int i = 0; i < rows; i++) {
          result->matrix[i] = ptr + columns * i;
        }
      }
    }
    if (err) free(result->matrix);
  }

  return err;
}

void s21_remove_matrix(matrix_t *A) {
  if (!s21_is_Emty(A)) {
    free(A->matrix[0]);
    free(A->matrix);
  }

  A->matrix = NULL;
  A->rows = 0;
  A->columns = 0;
}

// int main() {
//     int rows = 1;
//     int columns = 1;
//     matrix_t result;

//     if (s21_create_matrix(rows, columns, &result) == 0) {

//         for (int i = 0; i < rows; i++) {
//             for (int j = 0; j < columns; j++) {
//                 result.matrix[i][j] = i + j;
//             }
//         }

//         for (int i = 0; i < rows; i++) {
//             for (int j = 0; j < columns; j++) {
//                 printf("%lf ", result.matrix[i][j]);
//             }
//             printf("\n");
//         }
//     s21_remove_matrix(&result);
//     }

//     return 0;
// }