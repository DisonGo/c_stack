#ifndef C_STACK_CHAR_H_
#define C_STACK_CHAR_H_
#include <stdlib.h>

#include "c_stack_support_module.h"

typedef struct _c_stack_char {
  char* values;
  size_t length;
  size_t aloc_size;
} c_stack_char;

int char_c_stack_init(size_t size, c_stack_char* stack);
bool char_c_stack_valid(c_stack_char* stack);
bool char_c_stack_empty(c_stack_char* stack);
size_t char_c_stack_size(c_stack_char* stack);
char* char_c_stack_top(c_stack_char* stack);
void char_c_stack_push(c_stack_char* stack, char value);
void char_c_stack_pop(c_stack_char* stack);
void char_c_stack_remove(c_stack_char* stack);

#endif  // C_STACK_CHAR_H_