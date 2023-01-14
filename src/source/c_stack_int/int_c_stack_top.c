#include "c_stack_int.h"
int* int_c_stack_top(c_stack_int* stack) {
  if (!int_c_stack_valid(stack)) return NULL;
  if (int_c_stack_empty(stack)) return NULL;
  return &stack->values[stack->length - 1];
}
