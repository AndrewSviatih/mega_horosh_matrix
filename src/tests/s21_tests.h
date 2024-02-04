#ifndef SRC_TESTS_INCLUDES_S21_TESTS_H_
#define SRC_TESTS_INCLUDES_S21_TESTS_H_

#include <check.h>
#include <float.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../s21_matrix_lib/s21_matrix.h"
#define SUCCESS 1
#define FAILURE 0
// enum { OK = 0, INCORRECT_MATRIX = 1, CALC_ERROR = 2, MALLOC_FAILED = 3 };

// Suite *suite_memchr(void);
Suite *suite_create_matrix(void);
Suite *suite_eq_matrix(void);

Suite *suite_sum_matrix(void);

void run_tests(void);
void run_testcase(Suite *testcase, int counter_testcase);
double get_rand(double min, double max);

#endif  // SRC_TESTS_INCLUDES_S21_TESTS_H_