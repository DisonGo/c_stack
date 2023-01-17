#include "c_stack_char.h"
void char_c_stack_remove(c_stack_char* stack) {
  if (!char_c_stack_valid(stack)) return;
  free(stack->values);
  stack->length = 0;
  stack->aloc_size = 0;
  stack->values = NULL;
}
