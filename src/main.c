#include "tests/s21_tests.h"

int main(void) {
    run_tests();

    return 0;
}

void run_testcase(Suite *testcase, int counter_testcase) {

    if (counter_testcase > 1)
        putchar('\n');
    printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
    counter_testcase++;
    SRunner *sr = srunner_create(testcase);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
}

void run_tests(void) {

    int counter_testcase = 0;

    Suite *list_cases[] = {S21_NULL};

    for (Suite **current_testcase = list_cases; *current_testcase != S21_NULL;
        current_testcase++) {
        run_testcase(*current_testcase, counter_testcase);
        counter_testcase++;
    }
}