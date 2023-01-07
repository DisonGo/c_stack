#include "c_stack_char.h"
void char_c_stack_pop(c_stack_char* stack) {
  if (!char_c_stack_valid(stack)) return;
  if (stack->length == 0) return;
  size_t len = --stack->length;
  stack->values[len] = 0;
}
