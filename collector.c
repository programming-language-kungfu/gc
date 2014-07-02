#include "types.h"

void mark (Object* object ) {
    if (object->marked) return;

    object->marked = 1;

    if (object->type == OBJ_PAIR) {
        mark(object->head);
        mark(object->tail);
    }
}


void mark_all (VM* vm) {
    for(int i=0; i< vm->stack_size; i++) {
        mark(vm->stack[i])
    }
}
