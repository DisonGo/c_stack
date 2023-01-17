#ifndef C_STACK_DOUBLE_H_
#define C_STACK_DOUBLE_H_
#include <stdlib.h>

#include "c_stack_support_module.h"

typedef struct _c_stack_double {
  double* values;
  size_t length;
  size_t aloc_size;
} c_stack_double;

int double_c_stack_init(size_t size, c_stack_double* stack);
bool double_c_stack_valid(c_stack_double* stack);
bool double_c_stack_empty(c_stack_double* stack);
size_t double_c_stack_size(c_stack_double* stack);
double* double_c_stack_top(c_stack_double* stack);
int double_c_stack_push(c_stack_double* stack, double value);
int double_c_stack_pop(c_stack_double* stack);
void double_c_stack_remove(c_stack_double* stack);

#endif  // C_STACK_DOUBLE_H_