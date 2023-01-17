#include "c_stack_test.h"
#define RANDOM_RANGE 10000
START_TEST(init_test) {
  c_stack_double stack = {0};
  size_t size = rand() % RANDOM_RANGE;
  int res = double_c_stack_init(size, &stack);
  ck_assert_int_eq(res, C_STACK_OK);
}
END_TEST
START_TEST(push_test) {
  c_stack_double stack = {0};
  size_t size = rand() % RANDOM_RANGE;
  int res = double_c_stack_init(size, &stack);
  ck_assert_int_eq(res, C_STACK_OK);
  for (size_t i = 0; i < size; i++) double_c_stack_push(&stack, rand() % 128);
  ck_assert_uint_eq(size, stack.length);
  double_c_stack_remove(&stack);
}
END_TEST
START_TEST(pop_test) {
  c_stack_double stack = {0};
  size_t size = rand() % RANDOM_RANGE;
  int res = double_c_stack_init(size, &stack);
  ck_assert_int_eq(res, C_STACK_OK);
  for (size_t i = 0; i < size; i++) double_c_stack_push(&stack, rand() % 128);
  ck_assert_uint_eq(size, stack.length);
  for (size_t i = 0; i < size; i++) double_c_stack_pop(&stack);
  ck_assert_uint_eq(0, stack.length);
  double_c_stack_remove(&stack);
}
END_TEST
START_TEST(empty_test) {
  c_stack_double stack = {0};
  size_t size = rand() % RANDOM_RANGE + 1;

  int res = double_c_stack_init(size, &stack);
  ck_assert_int_eq(res, C_STACK_OK);

  for (size_t i = 0; i < size; i++)
    double_c_stack_push(&stack, (rand() + 1) % 128);

  bool empty = double_c_stack_empty(&stack);
  fail_unless(empty == false);
  double_c_stack_remove(&stack);

  c_stack_double stack_empty = {0};
  res = double_c_stack_init(1, &stack_empty);
  ck_assert_int_eq(res, C_STACK_OK);
  empty = double_c_stack_empty(&stack_empty);
  ck_assert_int_eq(empty, 1);
  double_c_stack_remove(&stack_empty);
}
END_TEST
START_TEST(size_test) {
  c_stack_double stack = {0};
  size_t size = rand() % RANDOM_RANGE + 1;

  int res = double_c_stack_init(size, &stack);
  ck_assert_int_eq(res, C_STACK_OK);

  for (size_t i = 0; i < size; i++)
    double_c_stack_push(&stack, (rand() + 1) % 128);
  size_t len = double_c_stack_size(&stack);
  ck_assert_int_eq(len, size);
  double_c_stack_remove(&stack);
}
END_TEST
START_TEST(top_test) {
  c_stack_double stack = {0};
  size_t size = rand() % RANDOM_RANGE + 1;

  int res = double_c_stack_init(size, &stack);
  ck_assert_int_eq(res, C_STACK_OK);

  for (size_t i = 0; i < size; i++)
    double_c_stack_push(&stack, (rand() + 1) % 128);
  double *top_item = double_c_stack_top(&stack);
  ck_assert_ptr_nonnull(top_item);
  double_c_stack_remove(&stack);

  top_item = double_c_stack_top(&stack);
  ck_assert_ptr_null(top_item);

  res = double_c_stack_init(1, &stack);
  ck_assert_int_eq(res, C_STACK_OK);

  top_item = double_c_stack_top(&stack);
  ck_assert_ptr_null(top_item);
  double_c_stack_remove(&stack);
}
END_TEST
START_TEST(push_overload_test) {
  c_stack_double stack_overload = {0};
  size_t size = rand() % RANDOM_RANGE;
  int res = double_c_stack_init(size, &stack_overload);
  ck_assert_int_eq(res, C_STACK_OK);
  for (size_t i = 0; i < size * 3; i++)
    double_c_stack_push(&stack_overload, rand() % 128);
  ck_assert_uint_eq(size * 3, stack_overload.length);
  double_c_stack_remove(&stack_overload);
}
END_TEST
Suite *suite_double_functionality(void) {
  Suite *s = suite_create(PRETTY_PRINT("double_functionality"));
  TCase *tc = tcase_create("double_functionality_tc");
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