#include "c_stack_int.h"
size_t int_c_stack_size(c_stack_int* stack) {
  if (!int_c_stack_valid(stack)) return 0;
  return stack->length;
}
