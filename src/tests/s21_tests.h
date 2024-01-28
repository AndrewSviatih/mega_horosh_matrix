#ifndef SRC_TESTS_INCLUDES_S21_TESTS_H_
#define SRC_TESTS_INCLUDES_S21_TESTS_H_

#include <check.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

#include "../s21_matrix_lib/s21_matrix.h"

// Suite *suite_memchr(void);


void run_tests(void);
void run_testcase(Suite *testcase, int counter_testcase);

#endif  // SRC_TESTS_INCLUDES_S21_TESTS_H_