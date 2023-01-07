#include "c_stack_int.h"
void int_c_stack_remove(c_stack_int* stack) {
  if (!int_c_stack_valid(stack)) return;
  free(stack->values);
  stack->length = 0;
  stack->aloc_size = 0;
  stack->values = NULL;
}
