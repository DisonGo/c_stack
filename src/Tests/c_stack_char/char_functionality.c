#include "c_stack_test.h"
START_TEST(init_test) {
  c_stack_char stack = {0};
  size_t size = rand() % 100000;
  int res = st_init(char, size, &stack);
  ck_assert_int_eq(res, C_STACK_OK);
}
END_TEST
START_TEST(push_test) {
  c_stack_char stack = {0};
  size_t size = rand() % 100000;
  int res = char_c_stack_init(size, &stack);
  ck_assert_int_eq(res, C_STACK_OK);
  for (size_t i = 0; i < size; i++)
    char_c_stack_push(&stack, (char)rand() % 128);
  ck_assert_uint_eq(size, stack.length);
  char_c_stack_remove(&stack);
}
END_TEST
START_TEST(pop_test) {
  c_stack_char stack = {0};
  size_t size = rand() % 100000;
  int res = char_c_stack_init(size, &stack);
  ck_assert_int_eq(res, C_STACK_OK);
  for (size_t i = 0; i < size; i++)
    char_c_stack_push(&stack, (char)rand() % 128);
  ck_assert_uint_eq(size, stack.length);
  for (size_t i = 0; i < size; i++) char_c_stack_pop(&stack);
  ck_assert_uint_eq(0, stack.length);
  char_c_stack_remove(&stack);
}
END_TEST
START_TEST(empty_test) {
  c_stack_char stack = {0};
  size_t size = rand() % 1000 + 1;

  int res = char_c_stack_init(size, &stack);
  ck_assert_int_eq(res, C_STACK_OK);

  for (size_t i = 0; i < size; i++)
    char_c_stack_push(&stack, (char)(rand() + 1) % 128);

  bool empty = char_c_stack_empty(&stack);
  fail_unless(empty == false);
  char_c_stack_remove(&stack);

  c_stack_char stack_empty = {0};
  res = char_c_stack_init(1, &stack_empty);
  ck_assert_int_eq(res, C_STACK_OK);
  empty = char_c_stack_empty(&stack_empty);
  ck_assert_int_eq(empty, 1);
  char_c_stack_remove(&stack_empty);
}
END_TEST
START_TEST(size_test) {
  c_stack_char stack = {0};
  size_t size = rand() % 1000 + 1;

  int res = char_c_stack_init(size, &stack);
  ck_assert_int_eq(res, C_STACK_OK);

  for (size_t i = 0; i < size; i++)
    char_c_stack_push(&stack, (char)(rand() + 1) % 128);
  size_t len = char_c_stack_size(&stack);
  ck_assert_int_eq(len, size);
  char_c_stack_remove(&stack);
}
END_TEST
START_TEST(top_test) {
  c_stack_char stack = {0};
  size_t size = rand() % 1000 + 1;

  int res = char_c_stack_init(size, &stack);
  ck_assert_int_eq(res, C_STACK_OK);

  for (size_t i = 0; i < size; i++)
    char_c_stack_push(&stack, (char)(rand() + 1) % 128);
  char *top_item = char_c_stack_top(&stack);
  ck_assert_ptr_nonnull(top_item);
  char_c_stack_remove(&stack);

  top_item = char_c_stack_top(&stack);
  ck_assert_ptr_null(top_item);

  res = char_c_stack_init(1, &stack);
  ck_assert_int_eq(res, C_STACK_OK);

  top_item = char_c_stack_top(&stack);
  ck_assert_ptr_null(top_item);
  char_c_stack_remove(&stack);
}
END_TEST
START_TEST(push_overload_test) {
  c_stack_char stack = {0};
  size_t size = rand() % 100000;
  int res = char_c_stack_init(size, &stack);
  ck_assert_int_eq(res, C_STACK_OK);
  for (size_t i = 0; i < size * 3; i++)
    char_c_stack_push(&stack, (char)rand() % 128);
  ck_assert_uint_eq(size * 3, stack.length);
  char_c_stack_remove(&stack);
}
END_TEST
Suite *suite_char_functionality(void) {
  Suite *s = suite_create(PRETTY_PRINT("char_functionality"));
  TCase *tc = tcase_create("char_functionality_tc");
  tcase_add_loop_test(tc, init_test, 0, TEST_COUNT);
  tcase_add_loop_test(tc, push_test, 0, TEST_COUNT);
  tcase_add_loop_test(tc, push_overload_test, 0, TEST_COUNT);
  tcase_add_loop_test(tc, pop_test, 0, TEST_COUNT);
  tcase_add_loop_test(tc, empty_test, 0, TEST_COUNT);
  tcase_add_loop_test(tc, size_test, 0, TEST_COUNT);
  tcase_add_loop_test(tc, top_test, 0, TEST_COUNT);
  suite_add_tcase(s, tc);
  return s;
}