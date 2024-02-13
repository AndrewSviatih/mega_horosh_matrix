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

void get_cofactor(double **m, double **tmp, int skip_row, int skip_col,
                  int size) {
    for (int i = 0, row = 0; row < size; row++) {
        for (int j = 0, col = 0; col < size; col++) {
            if (row != skip_row && col != skip_col) {
                tmp[i][j] = m[row][col];
                j++;
                if (j == size - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

double det(double **m, int size) {
    double res = 0;

    if (size == 1)
        return m[0][0];
    matrix_t tmp = {0};
    if (s21_create_matrix(size, size, &tmp))
        return INCORRECT_MATRIX;

    int sign = 1;
    for (int i = 0; i < size; i++) {
        get_cofactor(m, tmp.matrix, 0, i, size);
        res += sign * m[0][i] * det(tmp.matrix, size - 1);
        sign = -sign;
    }

    s21_remove_matrix(&tmp);
    return res;
}

int s21_determinant(matrix_t *A, double *result) {
    if (s21_is_Emty(A) || !result)
        return INCORRECT_MATRIX;

    if (A->rows != A->columns)
        return CALC_ERROR;

    if (A->rows == 1)
        *result = A->matrix[0][0];
    else
        *result = det(A->matrix, A->rows);

    return OK;
}



// void minor_matrix(matrix_t *A, matrix_t *minorA, int row, int column) {
//   int m_row = 0;
//   int m_col = 0;
//   for (int i = 0; i < A->rows; i++) {
//     if (i == row) {
//       continue;
//     }
//     m_col = 0;
//     for (int j = 0; j < A->columns; j++) {
//       if (j == column) {
//         continue;
//       }
//       minorA->matrix[m_row][m_col] = A->matrix[i][j];
//       m_col++;
//     }
//     m_row++;
//   }
// }

// double s21_get_determinant(matrix_t *A) {
//   double flag = 0.0;
//   // если матрица very small
//   if (A->rows == 1) {
//     flag = A->matrix[0][0];
//   } else {
//     matrix_t tmp = {0};
//     s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
//     for (int i = 0; i < A->columns; i++) {
//       minor_matrix(A, &tmp, 0, i);
//       if (i % 2) {
//         flag -= A->matrix[0][i] * s21_get_determinant(&tmp);
//       } else {
//         flag += A->matrix[0][i] * s21_get_determinant(&tmp);
//       }
//     }
//     s21_remove_matrix(&tmp);
//   }
//   return flag;
// }

// int s21_determinant(matrix_t *A, double *result) {
//   *result = 0.0;
//   int flag = 0;
//   if (s21_is_Emty(A) == 0) {
//     if (A->rows == A->columns) {
//       *result = s21_get_determinant(A);
//     } else {
//       flag = 2;
//     }
//   } else {
//     flag = 1;
//   }
//   return flag;
// }

// double get_complement(int cur_row, int cur_col, double determinant) {
//   return pow(-1, (cur_row + cur_col)) * determinant;
// }

// int s21_calc_complements(matrix_t *A, matrix_t *result) {
//   int flag = OK;
//   matrix_t minorA;

//   if (!s21_is_Emty(A)) {
//     if (A->columns == A->rows) {
//       flag = s21_create_matrix(A->columns - 1, A->rows - 1, &minorA);
//       if (flag == OK) {
//         for (int cur_row = 0; cur_row < A->rows; cur_row++) {
//           for (int cur_col = 0; cur_col < A->columns; cur_col++) {
//             double determinant = 0;
//             minor_matrix(A, &minorA, cur_row, cur_col);
//             s21_determinant(&minorA, &determinant);
//             result->matrix[cur_row][cur_col] = get_complement(cur_row, cur_col, determinant);
//           }
//         }
//       } else {
//         flag = INCORRECT_MATRIX;
//       }
//     } else {
//       flag = INCORRECT_MATRIX;
//     }
//   } else {
//     flag = INCORRECT_MATRIX;
//   }

//   s21_remove_matrix(&minorA);
//   return flag;
// }

// int main() {
//   const int size = 5;
//   matrix_t m;
//   s21_create_matrix(size, size, &m);
//   m.matrix[0][1] = 6;
//   m.matrix[0][2] = -2;
//   m.matrix[0][3] = -1;
//   m.matrix[0][4] = 5;
//   m.matrix[1][3] = -9;
//   m.matrix[1][4] = -7;
//   m.matrix[2][1] = 15;
//   m.matrix[2][2] = 35;
//   m.matrix[3][1] = -1;
//   m.matrix[3][2] = -11;
//   m.matrix[3][3] = -2;
//   m.matrix[3][4] = 1;
//   m.matrix[4][0] = -2;
//   m.matrix[4][1] = -2;
//   m.matrix[4][2] = 3;
//   m.matrix[4][4] = -2;

//   double ress = 0;
//   // printf("%lf", ress);
//   int code = s21_determinant(&m, &ress);

//   s21_remove_matrix(&m);
// }