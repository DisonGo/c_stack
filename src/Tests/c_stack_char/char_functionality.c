#include "c_stack_test.h"
START_TEST(init_test) {
  c_stack_char stack = {0};
  size_t size = rand() % 100000;
  int res = char_c_stack_init(size, &stack);
  ck_assert_int_eq(res, C_STACK_OK);
}
END_TEST
START_TEST(push_test) {
  c_stack_char stack = {0};
  size_t size = rand() % 100000;
  int res = char_c_stack_init(size, &stack);
  ck_assert_int_eq(res, C_STACK_OK);
  if (res == C_STACK_OK) {
    for (size_t i = 0; i < size; i++)
      char_c_stack_push(&stack, (char)rand() % 128);
    ck_assert_uint_eq(size, stack.length);
  }
}
END_TEST
START_TEST(push_overload_test) {
  c_stack_char stack = {0};
  size_t size = rand() % 100000;
  int res = char_c_stack_init(size, &stack);
  ck_assert_int_eq(res, C_STACK_OK);
  if (res == C_STACK_OK) {
    for (size_t i = 0; i < size * 3; i++)
      char_c_stack_push(&stack, (char)rand() % 128);
    ck_assert_uint_eq(size * 3, stack.length);
  }
}
END_TEST
Suite *suite_char_functionality(void) {
  Suite *s = suite_create(PRETTY_PRINT("char_functionality"));
  TCase *tc = tcase_create("char_functionality_tc");
  tcase_add_loop_test(tc, init_test, 0, 1000);
  tcase_add_loop_test(tc, push_test, 0, 1000);
  tcase_add_loop_test(tc, push_overload_test, 0, 1000);
  suite_add_tcase(s, tc);
  return s;
}