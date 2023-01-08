#include "c_stack_char.h"
int char_c_stack_push(c_stack_char* stack, char value) {
  if (!char_c_stack_valid(stack)) return C_STACK_NULL_REF;
  if (++stack->length > stack->aloc_size) {
    stack->aloc_size *= 2;
    if (stack->aloc_size > C_STACK_MAX_SIZE) {
      stack->aloc_size /= 2;
      stack->length--;
      return C_STACK_BAD_SIZE;
    } else {
      stack->values = realloc(stack->values, stack->aloc_size);
      if (!stack->values) return C_STACK_NULL_REF;
    }
  }
  stack->values[stack->length - 1] = value;
  return C_STACK_OK;
}
