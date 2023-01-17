#ifndef C_STACK_TEST_H_
#define C_STACK_TEST_H_
#include "c_stack.h"
#include "c_stack_colors.h"
#include "check.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define TEST_COUNT 100
/* Int stack tests*/

Suite *suite_int_memory(void);
Suite *suite_int_functionality(void);

/* Double stack tests*/

Suite *suite_double_memory(void);
Suite *suite_double_functionality(void);

/* Char stack tests*/

Suite *suite_char_memory(void);
Suite *suite_char_functionality(void);

void print_stack_int(c_stack_int *stack);
void print_stack_double(c_stack_double *stack);
void print_stack_char(c_stack_char *stack);
void run_tests(void);
void run_testcase(Suite *testcase);
#endif  // C_STACK_TEST_H_