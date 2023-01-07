#ifndef C_STACK_INT_H_
#define C_STACK_INT_H_
#include <stdlib.h>

#include "c_stack_support_module.h"

typedef struct _c_stack_int {
  int* values;
  size_t length;
  size_t aloc_size;
} c_stack_int;
int int_c_stack_init(size_t size, c_stack_int* stack);
bool int_c_stack_valid(c_stack_int* stack);
bool int_c_stack_empty(c_stack_int* stack);
size_t int_c_stack_size(c_stack_int* stack);
int* int_c_stack_top(c_stack_int* stack);
void int_c_stack_push(c_stack_int* stack, int value);
void int_c_stack_pop(c_stack_int* stack);
void int_c_stack_remove(c_stack_int* stack);

#endif  // C_STACK_INT_H_