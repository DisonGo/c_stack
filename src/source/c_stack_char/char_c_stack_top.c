#include "c_stack_char.h"
char* char_c_stack_top(c_stack_char* stack) {
  if (!char_c_stack_valid(stack)) return NULL;
  return &stack->values[stack->length - 1];
}
