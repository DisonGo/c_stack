#include "c_stack_int.h"
bool int_c_stack_empty(c_stack_int* stack) {
  if (!int_c_stack_valid(stack)) return false;
  bool res = false;
  res = stack->length ? false : true;
  return res;
}
