#include "c_stack_double.h"
void double_c_stack_remove(c_stack_double* stack) {
  if (!double_c_stack_valid(stack)) return;
  free(stack->values);
  stack->length = 0;
  stack->aloc_size = 0;
  stack->values = NULL;
}
