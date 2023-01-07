#include "c_stack_double.h"
bool double_c_stack_empty(c_stack_double* stack) {
  if (!double_c_stack_valid(stack)) return true;
  return stack->length ? false : true;
}
