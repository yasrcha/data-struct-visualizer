#ifndef QUEUE_H
#define QUEUE_H

#include "common.h"

typedef struct {
    int data[MAX_SIZE_STRUCT];
    int size;
} Queue;

void QueueInit(Queue *q);
bool QueueInsert(Queue *q, int value);
bool QueueRemove(Queue *q);
StructStatus GetQueueStatus(Queue *q);
#endif
