#include "c_stack_char.h"
bool char_c_stack_valid(c_stack_char* stack) {
  if (!stack) return false;
  if (!stack->values) return false;
  return true;
}
