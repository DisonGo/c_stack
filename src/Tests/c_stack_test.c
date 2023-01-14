#include "c_stack_test.h"
static int failed_tests = 0;

int main(void) {
  srand(time(0));
  run_tests();

  if (failed_tests) {
    fprintf(stderr, "%d\n", failed_tests);
  }

  return EXIT_SUCCESS;
}
void print_stack_int(c_stack_int *stack) {
  printf("%15s:\n", "Stack info");
  printf("%15s:%- 15li\n", "Length", stack->length);
  printf("%15s:%- 15li\n", "Allocated size", stack->aloc_size);
  printf("%15s:", "Values");
  for (size_t i = 0; i < stack->length; i++)
    printf("%i%s", stack->values[i], (i + 1 < stack->length) ? " " : "\n");
  printf("\n");
}
void print_stack_double(c_stack_double *stack) {
  printf("%15s:\n", "Stack info");
  printf("%15s:%- 15li\n", "Length", stack->length);
  printf("%15s:%- 15li\n", "Allocated size", stack->aloc_size);
  printf("%15s:", "Values");
  for (size_t i = 0; i < stack->length; i++)
    printf("%lf%s", stack->values[i], (i + 1 < stack->length) ? " " : "");
  printf("\n");
}
void print_stack_char(c_stack_char *stack) {
  printf("%15s:\n", "Stack info");
  printf("%15s:%- 15li\n", "Length", stack->length);
  printf("%15s:%- 15li\n", "Allocated size", stack->aloc_size);
  printf("%15s:", "Values");
  size_t size = stack->length > 10000 ? 10000 : stack->length;
  if (!size) printf(" Empty");
  for (size_t i = 0; i < size; i++) printf("%c", stack->values[i]);
  printf("\n");
}
void run_testcase(Suite *testcase) {
  static int counter_testcase = 1;

  if (counter_testcase > 1) putchar('\n');

  printf(GRN "%s%d%s" ENDCOLOR, "CURRENT TEST: ", counter_testcase, "\n");
  counter_testcase++;

  SRunner *sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  failed_tests += srunner_ntests_failed(sr);

  srunner_free(sr);
}

void run_tests(void) {
  Suite *list_cases[] = {// suite_int_memory,
                         //  suite_int_functionality,
                         //  suite_double_memory,
                         //  suite_double_functionality,
                         suite_char_memory(), suite_char_functionality(), NULL};
  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}
