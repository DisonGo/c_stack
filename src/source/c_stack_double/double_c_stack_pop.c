#include "c_stack_double.h"
void double_c_stack_pop(c_stack_double* stack) {
  if (!double_c_stack_valid(stack)) return;
  if (stack->length == 0) return;
  size_t len = --stack->length;
  stack->values[len] = 0;
}
