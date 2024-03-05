#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;

  if (!s21_is_Emty(A) && !s21_is_Emty(B)) {
    if (A->columns == B->columns && A->rows == B->rows) {
      flag = s21_create_matrix(A->rows, A->columns, result);
      if (!flag) {
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

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int code = OK;

  if (!validate(A)) {
    code = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    code = CALC_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);

    if (A->rows == 1) {
      result->matrix[0][0] = A->matrix[0][0];
    } else {
      int sign;
      matrix_t temp;

      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          minor_mat(i, j, A, &temp);
          sign = ((i + j) % 2 == 0) ? 1 : -1;
          result->matrix[i][j] = det(&temp) * sign;
          s21_remove_matrix(&temp);
        }
      }
    }
  }

  return code;
}

int s21_determinant(matrix_t *A, double *result) {
  int code = OK;

  if (!validate(A))
    code = INCORRECT_MATRIX;
  else if (A->rows != A->columns)
    code = CALC_ERROR;
  else
    *result = det(A);

  return code;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int code = OK;

  if (!validate(A))
    code = INCORRECT_MATRIX;
  else if (A->rows != A->columns)
    code = CALC_ERROR;
  else {
    double determinant = det(A);

    if (fabs(determinant) < 1e-7) {
      code = CALC_ERROR;
    } else {
      if (A->columns == 1) {
        s21_create_matrix(A->columns, A->rows, result);
        result->matrix[0][0] = 1 / A->matrix[0][0];
      } else {
        matrix_t comp, trans;

        s21_calc_complements(A, &comp);
        s21_transpose(&comp, &trans);

        s21_mult_number(&trans, 1 / determinant, result);

        s21_remove_matrix(&comp);
        s21_remove_matrix(&trans);
      }
    }
  }

  return code;
}

void minor_mat(int row, int column, matrix_t *M, matrix_t *result) {
  s21_create_matrix(M->rows - 1, M->columns - 1, result);

  int di = 0, dj = 0;

  for (int i = 0; i < result->rows; i++) {
    if (i == row) di = 1;
    dj = 0;

    for (int j = 0; j < result->columns; j++) {
      if (j == column) dj = 1;
      result->matrix[i][j] = M->matrix[i + di][j + dj];
    }
  }
}

double det(matrix_t *M) {
  double result = 0;

  if (M->rows == 1)
    result = M->matrix[0][0];
  else if (M->rows == 2)
    result = (M->matrix[0][0] * M->matrix[1][1]) -
        (M->matrix[0][1] * M->matrix[1][0]);
  else {
    int sign = 1;
    for (int i = 0; i < M->rows; i++) {
      matrix_t temp;
      minor_mat(0, i, M, &temp);

      result += sign * M->matrix[0][i] * det(&temp);
      sign *= -1;

      s21_remove_matrix(&temp);
    }
  }

  return result;
}