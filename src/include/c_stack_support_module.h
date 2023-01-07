#ifndef C_STACK_SUPPORT_MODULE_H_
#define C_STACK_SUPPORT_MODULE_H_

#ifndef C_STACK_BUFFER_SIZE
#define C_STACK_BUFFER_SIZE 1024
#endif

#ifndef C_STACK_BASE_SIZE
#define C_STACK_BASE_SIZE 1
#endif

#ifndef C_STACK_MAX_SIZE
#define C_STACK_MAX_SIZE 1 << 23
#endif

typedef enum _bool { true = 1, false = 0 } bool;

enum c_stack_error {
  C_STACK_OK = 0,
  C_STACK_NULL_REF = 1,
  C_STACK_BAD_SIZE = 2,
  C_STACK_MEMORY = 3
};

#endif  // C_STACK_SUPPORT_MODULE_H_
