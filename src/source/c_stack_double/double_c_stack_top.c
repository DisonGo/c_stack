#include "c_stack_double.h"
double* double_c_stack_top(c_stack_double* stack) {
  if (!double_c_stack_valid(stack)) return NULL;
  if (double_c_stack_empty(stack)) return NULL;
  return &stack->values[stack->length - 1];
}
