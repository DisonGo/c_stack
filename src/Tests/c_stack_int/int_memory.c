#include "c_stack_test.h"
START_TEST(init_null_test) {
  c_stack_int *stack = NULL;
  int res = int_c_stack_init(10, stack);
  ck_assert_int_eq(res, C_STACK_NULL_REF);
}
END_TEST
START_TEST(init_bad_size_test) {
  c_stack_int stack = {0};
  int res = int_c_stack_init(C_STACK_MAX_SIZE + 1, &stack);
  ck_assert_int_eq(res, C_STACK_BAD_SIZE);
}
END_TEST
START_TEST(empty_invalid_test) {
  c_stack_int *stack = NULL;
  bool res = int_c_stack_empty(stack);
  ck_assert_int_eq(res, false);
}
END_TEST
START_TEST(pop_invalid_test) {
  c_stack_int stack = {0};
  int res = int_c_stack_pop(NULL);

  ck_assert_int_eq(res, C_STACK_NULL_REF);

  int_c_stack_init(0, &stack);
  res = int_c_stack_pop(&stack);
  ck_assert_int_eq(res, C_STACK_OK);

  int_c_stack_remove(&stack);
}
END_TEST
START_TEST(push_invalid_test) {
  c_stack_int stack = {0};
  size_t size = C_STACK_MAX_SIZE - 1;
  int res = int_c_stack_push(NULL, 1);

  ck_assert_int_eq(res, C_STACK_NULL_REF);

  int_c_stack_init(size, &stack);
  for (size_t i = 0; i <= size; i++)
    res = int_c_stack_push(&stack, rand() % 128);
  ck_assert_int_eq(res, C_STACK_BAD_SIZE);
  int_c_stack_remove(&stack);
}
END_TEST
START_TEST(size_invalid_test) {
  c_stack_int *stack = NULL;
  int res = int_c_stack_size(stack);
  ck_assert_int_eq(res, 0);
}
START_TEST(top_invalid_test) {
  c_stack_int *stack = NULL;
  int *res = int_c_stack_top(stack);
  ck_assert_ptr_null(res);
}
END_TEST
Suite *suite_int_memory(void) {
  Suite *s = suite_create(PRETTY_PRINT("int_memory"));
  TCase *tc = tcase_create("int_memory_tc");
  tcase_add_test(tc, init_null_test);
  tcase_add_test(tc, init_bad_size_test);
  tcase_add_test(tc, empty_invalid_test);
  tcase_add_test(tc, pop_invalid_test);
  tcase_add_test(tc, push_invalid_test);
  tcase_add_test(tc, size_invalid_test);
  tcase_add_test(tc, top_invalid_test);
  suite_add_tcase(s, tc);
  return s;
}