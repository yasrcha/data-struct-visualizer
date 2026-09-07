#include "common.h"
#include "list.h"

/* LIST:
* Só aceitam números positivos;
* Se o valor em algum index for -1, signidica que ela está vazia;
* C usa NULL apenas para ponteiros :(
*/
void ListInit(List *l) {
    for(int i = 0; i < MAX_SIZE_STRUCT; i++) {
        l->data[i] = -1;
    }
    l->size = 0;
}

// Insere Item na Lista
bool ListInsert(List *l, int value, int index) {
    if(l->size >= MAX_SIZE_STRUCT || index < 0 || index > l->size) {
        return false;
    }

    for(int i = l->size; i > index; i--) {
        l->data[i] = l->data[i - 1];
    }

    l->data[index] = value;
    l->size++;
    return true; // Retorna True pq a função é booleana -> Se adicionar, retorna True; Se não adicionar, retorna False | Para cada retorno tem um corpotamento
}

// Remove Item da Lista
bool ListRemove(List *l, int index) {
    if (index < 0 || index >= MAX_SIZE_STRUCT || l->data[index] == -1) {
        return false;
    }
    for(int i = index; i < l->size - 1; i++) {
        l->data[i] = l->data[i+1];
    }

    l->data[l->size - 1] = -1;
    l->size--;
    return true;
}

StructStatus GetListStatus(List *l) {
    if (l->size == 0) {
        return LIST_EMPTY;
    }
    if (l->size == MAX_SIZE_STRUCT) {
        return LIST_FULL;
    }
    return LIST_AVAILABLE;
}
