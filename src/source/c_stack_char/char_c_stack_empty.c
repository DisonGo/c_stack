#include "c_stack_char.h"
bool char_c_stack_empty(c_stack_char* stack) { 
  if (!char_c_stack_valid(stack)) return true;
  return stack->length ? false : true;
}
