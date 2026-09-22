#include "common.h"
#include "stack.h"



void StackInit(Stack *s) {
    for(int i = 0; i <= MAX_SIZE_STRUCT; i++) {
        s->data[i] = -1;
    }
    s->size = 0;
}

bool StackInsert(Stack *s, int value) {
    // Significa que a pilha está cheia e não da para adicionar mais nada
    if(s->size >= MAX_SIZE_STRUCT) {
        return false;
    }

    s->data[s->size] = value;
    s->size++;
    return true;
}

bool StackRemove(Stack *s) {
    if(s->size == 0) {
        return false;
    }

    s->data[s->size - 1] = -1;
    s->size--;
    return true;
}

StructStatus GetStackStatus(Stack *s) {
    if (s->size == 0) {
        return LIST_EMPTY;
    }
    if (s->size == MAX_SIZE_STRUCT) {
        return LIST_FULL;
    }
    return LIST_AVAILABLE;
}
