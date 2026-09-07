#ifndef LIST_H
#define LIST_H

#include "common.h"

typedef struct {
    int data[MAX_SIZE_STRUCT];
    int size;
} List;

typedef enum {
    LIST_EMPTY = 0,
    LIST_FULL,
    LIST_AVAILABLE
} ListStatus;

ListStatus GetListStatus(List *l);

void ListInit(List *l);
bool ListInsert(List *l, int value, int index);
bool ListRemove(List *l, int index);

#endif
