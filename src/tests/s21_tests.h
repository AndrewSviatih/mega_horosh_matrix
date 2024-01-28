#ifndef SRC_TESTS_INCLUDES_S21_TESTS_H_
#define SRC_TESTS_INCLUDES_S21_TESTS_H_

#include <check.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

#include "../s21_matrix_lib/s21_matrix.h"
enum { OK = 0, INCORRECT_MATRIX = 1, CALC_ERROR = 2, MALLOC_FAILED = 3 };

// Suite *suite_memchr(void);
Suite *suite_create_matrix(void);

void run_tests(void);
void run_testcase(Suite *testcase, int counter_testcase);

#endif  // SRC_TESTS_INCLUDES_S21_TESTS_H_