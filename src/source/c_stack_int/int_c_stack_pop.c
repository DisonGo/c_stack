#include "c_stack_int.h"
void int_c_stack_pop(c_stack_int* stack) {
  if (!int_c_stack_valid(stack)) return;
  if (stack->length == 0) return;
  size_t len = --stack->length;
  stack->values[len] = 0;
}
