#ifndef LIST_H
#define LIST_H

#include "common.h"

typedef struct {
    int data[MAX_SIZE_STRUCT];
    int size;
} List;

void ListInit(List *l);
bool ListInsert(List *l, int value, int index);
bool ListRemove(List *l, int index);
bool ListStatus(List *l);

#endif
