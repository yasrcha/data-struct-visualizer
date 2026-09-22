#ifndef STACK_H
#define STACK_H

#include "common.h"

typedef struct {
    int data[MAX_SIZE_STRUCT];
    int size;
} Stack;

void StackInit(Stack *s);
bool StackInsert(Stack *s, int value);
bool StackRemove(Stack *s);
StructStatus GetStackStatus(Stack *s);

#endif
