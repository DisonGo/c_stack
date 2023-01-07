#include "c_stack_int.h"
void int_c_stack_push(c_stack_int* stack, int value) {
  if (!int_c_stack_valid(stack)) return;
  if (++stack->length > stack->aloc_size) {
    stack->aloc_size *= 2;
    if (stack->aloc_size > C_STACK_MAX_SIZE) {
      stack->aloc_size /= 2;
      stack->length--;
      return;
    } else {
      stack->values = realloc(stack->values, stack->aloc_size);
      if (!stack->values) return;
    }
  }
  stack->values[stack->length - 1] = value;
}
