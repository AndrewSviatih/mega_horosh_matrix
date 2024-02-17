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
  int m_row = 0;
  int m_col = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == row) {
      continue;
    }
    m_col = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == column) {
        continue;
      }
      minorA->matrix[m_row][m_col] = A->matrix[i][j];
      m_col++;
    }
    m_row++;
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
        for (int mainColumn = 0; mainColumn < A->columns; mainColumn++) {
          matrix_t tmp_minor = {0};
          double subDeterminant = 0.0;
          s21_create_matrix(A->rows - 1, A->columns - 1, &tmp_minor);
          minor_matrix(A, &tmp_minor, 0, mainColumn);
          s21_determinant(&tmp_minor, &subDeterminant);
          if (mainColumn % 2) {
            *result -= A->matrix[0][mainColumn] * subDeterminant;
          } else {
            *result += A->matrix[0][mainColumn] * subDeterminant;
          }
          s21_remove_matrix(&tmp_minor);
        }
      }
    } else {
      flag = CALC_ERROR;
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
      flag = s21_create_matrix(A->columns, A->rows, result);
      flag = s21_create_matrix(A->columns - 1, A->rows - 1, &minorA);
      if (flag == OK) {
        for (int cur_row = 0; cur_row < A->rows; cur_row++) {
          for (int cur_col = 0; cur_col < A->columns; cur_col++) {
            double determinant = 0;
            minor_matrix(A, &minorA, cur_row, cur_col);
            s21_determinant(&minorA, &determinant);
            result->matrix[cur_row][cur_col] =
                get_complement(cur_row, cur_col, determinant);
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

  s21_remove_matrix(&minorA);
  return flag;
}

double get_matrix_inverse_element(double determinant,
                                  double transposed_element) {
  return 1 / (transposed_element * determinant);
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int flag = OK;
  matrix_t complements_matrix = {0};
  matrix_t transposed_matrix = {0};

  if (!s21_is_Emty(A)) {
    if (A->columns == A->rows) {
      flag = s21_create_matrix(A->columns, A->rows, result);
      if (!flag) {
        double determinant;
        if (A->rows == 1 && A->matrix[0][0] != 0) {
          result->matrix[0][0] = 1.0 / A->matrix[0][0];
        } else if (is_matrix_can_inverse(A, &determinant)) {
          s21_calc_complements(A, &complements_matrix);
          s21_transpose(&complements_matrix, &transposed_matrix);
          for (int i = 0; i < result->rows; i++) {
            for (int j = 0; j < result->columns; j++) {
              result->matrix[i][j] = get_matrix_inverse_element(
              determinant, transposed_matrix.matrix[i][j]);
            }
          }
        } else {
          flag = CALC_ERROR;
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
  s21_remove_matrix(&complements_matrix);
  s21_remove_matrix(&transposed_matrix);

  return flag;
}

// double get_rand(double min, double max) {
//   double val = (double)rand() / RAND_MAX;
//   return min + val * (max - min);
// }

//int main() {
//  matrix_t m = {0};
//  matrix_t expected = {0};
//  int codec1, codec2;
//  codec1 = s21_create_matrix(3, 3, &m);
//  if (!codec1) codec2 = s21_create_matrix(3, 3, &expected);
//
//  if (!codec1 && !codec2) {
//    m.matrix[0][0] = 2;
//    m.matrix[0][1] = 5;
//    m.matrix[0][2] = 7;
//
//    m.matrix[1][0] = 6;
//    m.matrix[1][1] = 3;
//    m.matrix[1][2] = 4;
//
//    m.matrix[2][0] = 5;
//    m.matrix[2][1] = -2;
//    m.matrix[2][2] = -3;
//
//    expected.matrix[0][0] = 1;
//    expected.matrix[0][1] = -1;
//    expected.matrix[0][2] = 1;
//
//    expected.matrix[1][0] = -38;
//    expected.matrix[1][1] = 41;
//    expected.matrix[1][2] = -34;
//
//    expected.matrix[2][0] = 27;
//    expected.matrix[2][1] = -29;
//    expected.matrix[2][2] = 24;
//    matrix_t result = {0};
//    int code = s21_inverse_matrix(&m, &result);
//
//    s21_remove_matrix(&m);
//    s21_remove_matrix(&result);
//    s21_remove_matrix(&expected);
//  }
//}