#include "c_stack_char.h"
int char_c_stack_init(size_t size, c_stack_char* stack) {
  if (!stack) return C_STACK_NULL_REF;
  if (size >= C_STACK_MAX_SIZE) return C_STACK_BAD_SIZE;
  stack->aloc_size = !size ? C_STACK_BASE_SIZE : size;
  stack->values = calloc(stack->aloc_size, sizeof(char));
  if (!stack->values) {
    stack->length = 0;
    stack->aloc_size = 0;
    return C_STACK_NULL_REF;
  }
  stack->length = 0;
  return C_STACK_OK;
}