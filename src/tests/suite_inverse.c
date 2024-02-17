#include "s21_tests.h"

//START_TEST(s21_inverse_1) {
//  matrix_t A, C;
//  s21_create_matrix(3, 3, &A);
//  s21_create_matrix(3, 3, &C);
//  C.matrix[0][0] = 1.0;
//  C.matrix[0][1] = -1.0;
//  C.matrix[0][2] = 1.0;
//  C.matrix[1][0] = -38.0;
//  C.matrix[1][1] = 41.0;
//  C.matrix[1][2] = -34.0;
//  C.matrix[2][0] = 27.0;
//  C.matrix[2][1] = -29.0;
//  C.matrix[2][2] = 24.0;
//  A.matrix[0][0] = 2.0;
//  A.matrix[0][1] = 5.0;
//  A.matrix[0][2] = 7.0;
//  A.matrix[1][0] = 6.0;
//  A.matrix[1][1] = 3.0;
//  A.matrix[1][2] = 4.0;
//  A.matrix[2][0] = 5.0;
//  A.matrix[2][1] = -2.0;
//  A.matrix[2][2] = -3.0;
//  matrix_t B;
//  s21_inverse_matrix(&A, &B);
//  int res = s21_eq_matrix(&B, &C);
//  ck_assert_int_eq(res, 1);
//  s21_remove_matrix(&A);
//  s21_remove_matrix(&B);
//  s21_remove_matrix(&C);
//}
//END_TEST
//
//START_TEST(test_one_by_one) {
//  matrix_t m = {0};
//  matrix_t result = {0};
//  int codec = s21_create_matrix(1, 1, &m);
//  if (!codec) {
//    m.matrix[0][0] = 1431.12312331;
//    int code = s21_inverse_matrix(&m, &result);
////    printf("%lf, %lf", result.matrix[0][0], 1.0 / m.matrix[0][0]);
//    ck_assert_int_eq(result.matrix[0][0] == (1.0 / m.matrix[0][0]), 1);
//    ck_assert_int_eq(code, OK);
//    s21_remove_matrix(&m);
//    s21_remove_matrix(&result);
//  }
//}
//END_TEST
//
//START_TEST(test_zero_det) {
//  matrix_t m = {0};
//  matrix_t result = {0};
//  int codec = s21_create_matrix(1, 1, &m);
//  if (!codec) {
//    int code = s21_inverse_matrix(&m, &result);
//    ck_assert_int_eq(code, CALC_ERROR);
//    s21_remove_matrix(&m);
//  }
//}
//END_TEST
//
//START_TEST(test_incorrect) {
//  matrix_t m = {0};
//  matrix_t result = {0};
//  int code = s21_inverse_matrix(&m, &result);
//  ck_assert_int_eq(code, INCORRECT_MATRIX);
//}
//END_TEST
//
//START_TEST(determinant) {
//  const int size = 2;
//  matrix_t m = {0};
//  s21_create_matrix(size, size, &m);
//  m.matrix[0][0] = 1;
//  m.matrix[0][1] = 1;
//  m.matrix[1][0] = 1;
//  m.matrix[1][1] = 1;
//
//  matrix_t result = {0};
//  int code = s21_inverse_matrix(&m, &result);
//  ck_assert_int_eq(code, CALC_ERROR);
//
//  s21_remove_matrix(&m);
//}
//END_TEST
//
//START_TEST(test_not_sqare) {
//  matrix_t m = {0};
//  matrix_t result = {0};
//  int codec = s21_create_matrix(1, 4, &m);
//  if (!codec) {
//    int code = s21_inverse_matrix(&m, &result);
//    ck_assert_int_eq(code, CALC_ERROR);
//    s21_remove_matrix(&m);
//  }
//}
//END_TEST
//
//START_TEST(test_normal) {
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
//    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
//    ck_assert_int_eq(code, OK);
//
//    s21_remove_matrix(&m);
//    s21_remove_matrix(&result);
//    s21_remove_matrix(&expected);
//  }
//}
//END_TEST
//
//START_TEST(inverse) {
//  /* const int size = rand() % 100 + 1; */
//  const int size = 3;
//  matrix_t m = {0};
//  s21_create_matrix(size, size, &m);
//
//  m.matrix[0][0] = 2;
//  m.matrix[0][1] = 5;
//  m.matrix[0][2] = 7;
//  m.matrix[1][0] = 6;
//  m.matrix[1][1] = 3;
//  m.matrix[1][2] = 4;
//  m.matrix[2][0] = 5;
//  m.matrix[2][1] = -2;
//  m.matrix[2][2] = -3;
//
//  matrix_t res = {0};
//  s21_inverse_matrix(&m, &res);
//
//  matrix_t expected = {0};
//  s21_create_matrix(size, size, &expected);
//  expected.matrix[0][0] = 1;
//  expected.matrix[0][1] = -1;
//  expected.matrix[0][2] = 1;
//  expected.matrix[1][0] = -38;
//  expected.matrix[1][1] = 41;
//  expected.matrix[1][2] = -34;
//  expected.matrix[2][0] = 27;
//  expected.matrix[2][1] = -29;
//  expected.matrix[2][2] = 24;
//
//  ck_assert_int_eq(s21_eq_matrix(&expected, &res), SUCCESS);
//
//  s21_remove_matrix(&expected);
//  s21_remove_matrix(&res);
//  s21_remove_matrix(&m);
//}
//END_TEST
//
START_TEST(test_s21_inverse_matrix) {
  double m[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
  double r[3][3] = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};
  matrix_t matrix, res_org, res_my;
  s21_create_matrix(3, 3, &matrix);
  s21_create_matrix(3, 3, &res_org);
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = m[i][j];
      printf("%lf ", matrix.matrix[i][j]);
    }
    printf("\n");
  }
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      res_org.matrix[i][j] = r[i][j];
    }
  }
  printf("\n");
  int ret = s21_inverse_matrix(&matrix, &res_my);
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      printf("%lf ", res_my.matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      printf("%lf ", res_org.matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_org, &res_my);
  ck_assert_int_eq(ret, 1);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);
}
END_TEST

Suite *suite_inverse_matrix(void) {
  Suite *s = suite_create("suite_inverse_matrix");
  TCase *tc = tcase_create("case_inverse_matrix");

//  tcase_add_test(tc, inverse);
//  tcase_add_test(tc, s21_inverse_1);
//  tcase_add_test(tc, determinant);
//
//  tcase_add_test(tc, test_normal);
//  tcase_add_test(tc, test_not_sqare);
//  tcase_add_test(tc, test_zero_det);
//  tcase_add_test(tc, test_incorrect);
//  tcase_add_test(tc, test_one_by_one);

  tcase_add_test(tc, test_s21_inverse_matrix);

  suite_add_tcase(s, tc);
  return s;
}