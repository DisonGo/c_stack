#include "c_stack_int.h"
bool int_c_stack_empty(c_stack_int* stack) {
  if (!int_c_stack_valid(stack)) return true;
  return stack->length ? false : true;
}
