#include "c_stack_int.h"
bool int_c_stack_valid(c_stack_int* stack) {
  if (!stack) return false;
  if (!stack->values) return false;
  return true;
}
