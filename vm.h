#include "types.h"
#define STACK_SIZE 256

typedef struct {
    Object* stack[STACK_SIZE];
    int stack_size;
} VM;
