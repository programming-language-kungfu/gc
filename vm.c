#include "types.h"
#define STACK_SIZE 256

typedef struct {
    Object* stack[STACK_MAX];
    int stack_size;
} VM;

VM * new_vm () {
    VM * vm = malloc(sizeof(VM));
    vm->stack_size = 0;
    return vm;
}

void push (VM* vm, Object* value) {
    assert(vm->stack_size < STACK_SIZE, "Stack Overflow");
    vm->stack[vm->stack_size++] = value;
}

Object* pop (VM* vm) {
    assert(vm->stack[--vm->stack_size] > 0, "Stack Underflow");
    return vm->stack[--vm->stack_size];
}

Object* new_object (ObjectType type) {
    Object* object = malloc(sizeof(Object));
    object->marked = 0;
    object->type = type;
    return object;
}

void push_in (VM* vm, int int_value) {
    Object* object = new_object(OBJ_INT);
    object->value = int_value;
    push(vm, object);
}

Object* push_pair(VM* vm) {
    Object* object = new_object(OBJ_PAIR);
    object->tail = pop(vm);
    object->head = pop(vm);

    push(vm ,object);
    return object;
}
