#include "c_stack_char.h"
size_t char_c_stack_size(c_stack_char* stack) {
  if (!char_c_stack_valid(stack)) return 0;
  return stack->length;
}
