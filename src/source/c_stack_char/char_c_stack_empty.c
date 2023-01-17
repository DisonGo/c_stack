#include "c_stack_char.h"
#include "stdio.h"
bool char_c_stack_empty(c_stack_char* stack) {
  if (!char_c_stack_valid(stack)) return false;
  bool res = false;
  res = stack->length ? false : true;
  return res;
}
