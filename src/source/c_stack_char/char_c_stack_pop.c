#include "c_stack_char.h"
int char_c_stack_pop(c_stack_char* stack) {
  if (!char_c_stack_valid(stack)) return C_STACK_NULL_REF;
  if (stack->length == 0) return C_STACK_OK;
  size_t len = --stack->length;
  stack->values[len] = 0;
  return C_STACK_OK;
}
