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

void print_matrix(const matrix_t *mtrx) {
  for (int i = 0; i < mtrx->columns; i++) {
    for (int j = 0; j < mtrx->rows; j++) {
      printf("%.2lf ", mtrx->matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void minor_matrix(matrix_t *A, matrix_t *minorA, int row, int column) {
  int m = 0, n = 0;
  for (int i = 0; i < A->columns; i++) {
    if (i == row) continue;
    n = 0;
    for (int j = 0; j < A->rows; j++) {
      if (j == column) continue;
      minorA->matrix[m][n++] = A->matrix[i][j];
      if (n == minorA->columns) m++;
    }
  }
}

int s21_determinant(matrix_t *A, double *result) {
  int flag = OK;
  if (!s21_is_Emty(A)) {
      if (A->columns == 1) {
        *result = A->matrix[0][0];
      } else if (A->columns == 2) {
        *result = A->matrix[0][0] * A->matrix[1][1] -
                  A->matrix[0][1] * A->matrix[1][0];
      } else {
        for (int mainColumn = 0; mainColumn < A->columns; mainColumn++) {
          matrix_t tmp_minor = {0};
          double subDeterminant = 0.0;
          s21_create_matrix(A->rows - 1, A->columns - 1, &tmp_minor);
          minor_matrix(A, &tmp_minor, 0, mainColumn);
          s21_determinant(&tmp_minor, &subDeterminant);
          if (mainColumn % 2 == 0) {
            *result -= A->matrix[0][mainColumn] * subDeterminant;
          } else {
            *result -= A->matrix[0][mainColumn] * subDeterminant;
          }
          s21_remove_matrix(&tmp_minor);
        }
        }
      } else {
        flag = INCORRECT_MATRIX;
      }
    return flag;
}

double get_complement(int cur_row, int cur_col, double determinant) {
  return pow(-1, (cur_row + cur_col)) * determinant;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag = OK;
  matrix_t minorA = {0};

  if (!s21_is_Emty(A)) {
    if (A->columns == A->rows) {
      flag = s21_create_matrix(A->columns - 1, A->rows - 1, &minorA);
      if (flag == OK) {
        for (int cur_row = 0; cur_row < A->rows; cur_row++) {
          for (int cur_col = 0; cur_col < A->columns; cur_col++) {
            double determinant = 0;
            minor_matrix(A, &minorA, cur_row, cur_col);
            s21_determinant(&minorA, &determinant);
            result->matrix[cur_row][cur_col] = get_complement(cur_row, cur_col, determinant);
          }
        }
        print_matrix(result);
      } else {
        flag = INCORRECT_MATRIX;
      }
    } else {
      flag = INCORRECT_MATRIX;
    }
  } else {
    flag = INCORRECT_MATRIX;
  }

  s21_remove_matrix(&minorA);
  return flag;
}

// int main() {
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
//       m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX) + 1;
      
//     }
//   }

//   for (int i = 0; i < rows1; i++) {
//     for (int j = 0; j < cols1; j++) {
//       mtx.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX) + 1;
//     }
//   }

  

//   matrix_t res = {0};
//   s21_sum_matrix(&m, &mtx, &res);
//   s21_remove_matrix(&m);
//   s21_remove_matrix(&mtx);
//   s21_remove_matrix(&res);
// }