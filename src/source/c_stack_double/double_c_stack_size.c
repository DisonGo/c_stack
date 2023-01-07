#include "c_stack_double.h"
size_t double_c_stack_size(c_stack_double* stack) {
  if (!double_c_stack_valid(stack)) return 0;
  return stack->length;
}
