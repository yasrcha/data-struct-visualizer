#include "common.h"
#include "queue.h"

void QueueInit(Queue *q) {
    q->size = 0;
    for(int i = 0; i < MAX_SIZE_STRUCT; i++) {
        q->data[i] = -1;
    }
}

bool QueueInsert(Queue *q, int value) {
    if (q->size >= MAX_SIZE_STRUCT) {
        return false;
    }

    q->data[q->size] = value;
    q->size++;
    return true;
}

bool QueueRemove(Queue *q) {
    // 1. Se estiver vazia, não remove
    if (q->size == 0) {
        return false;
    }

    // 2. Puxa todos os elementos 1 posição para a esquerda
    for (int i = 0; i < q->size - 1; i++) {
        q->data[i] = q->data[i + 1];
    }

    // 3. Limpa o último slot que sobrou e decrementa o tamanho
    q->data[q->size - 1] = -1;
    q->size--;
    return true;
}

StructStatus GetQueueStatus(Queue *q) {
    if (q->size == 0) {
        return LIST_EMPTY;
    }
    if (q->size == MAX_SIZE_STRUCT) {
        return LIST_FULL;
    }
    return LIST_AVAILABLE;
}
