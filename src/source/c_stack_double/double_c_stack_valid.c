#include "c_stack_double.h"
bool double_c_stack_valid(c_stack_double* stack) { 
  if (!stack) return false;
  if (!stack->values) return false;
  return true;
}
