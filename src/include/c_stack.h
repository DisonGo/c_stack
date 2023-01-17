#ifndef C_STACK_H_
#define C_STACK_H_
#include "c_stack_char.h"
#include "c_stack_double.h"
#include "c_stack_int.h"

#define st_init(type, size, stack_ptr) type##_c_stack_init(size, stack_ptr)
#define st_empty(type, stack_ptr) type##_c_stack_empty(stack_ptr)
#define st_pop(type, stack_ptr) type##_c_stack_pop(stack_ptr)
#define st_push(type, stack_ptr, value) type##_c_stack_pop(stack_ptr, value)
#define st_remove(type, stack_ptr) type##_c_stack_remove(stack_ptr)
#define st_size(type, stack_ptr) type##_c_stack_size(stack_ptr)
#define st_top(type, stack_ptr) type##_c_stack_top(stack_ptr)
#define st_valid(type, stack_ptr) type##_c_stack_remove(stack_ptr)

#endif  // C_STACK_H_