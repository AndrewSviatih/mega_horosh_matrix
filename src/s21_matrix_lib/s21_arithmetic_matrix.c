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

void print_matrix(matrix_t mtrx) {
  for (int i = 0; i < mtrx.columns; i++) {
    for (int j = 0; j < mtrx.rows; j++) {
      printf("%.2lf ", mtrx.matrix[i][j]);
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
    if (A->columns == A->rows) {
      if (A->columns == 1) {
        *result = A->matrix[0][0];
      } else if (A->columns == 2) {
        *result = A->matrix[0][0] * A->matrix[1][1] -
                  A->matrix[0][1] * A->matrix[1][0];
      } else {
        matrix_t tmp = {0};
        s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
        for (int mainColumn = 0; mainColumn < A->columns; mainColumn++) {
          minor_matrix(A, &tmp, 0, mainColumn);
          if (mainColumn % 2 == 0) {
            s21_determinant(A, result);
            //            *result +=
            //          } else {
            //            *result -=
            //          }
          }
          s21_remove_matrix(&tmp);
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

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag = OK;
  matrix_t minorA = {0};

  if (!s21_is_Emty(A)) {
    if (A->columns == A->rows) {
      flag = s21_create_matrix(A->columns - 1, A->rows - 1, &minorA);
      if (flag == OK) {
        for (int cur_row = 0; cur_row < A->rows; cur_row++) {
          for (int cur_col = 0; cur_col < A->columns; cur_col++) {
            minor_matrix(A, &minorA, cur_row, cur_col);
            print_matrix(minorA);
          }
        }
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

int main() {
  matrix_t A = {0};
  // matrix_t B = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &res);
  // s21_create_matrix(3, 3, &B);
  for (int cur_row = 0; cur_row < A.rows; cur_row++) {
    for (int cur_col = 0; cur_col < A.columns; cur_col++) {
      A.matrix[cur_row][cur_col] = cur_row + cur_col;
    }
  }
  print_matrix(A);
  int flag = 0;
  flag = s21_calc_complements(&A, &res);
  if (flag) {
    printf("err");
  } else {
    //    print_matrix(res);
  }
  s21_remove_matrix(&res);
  s21_remove_matrix(&A);
  // s21_remove_matrix(&B);
}