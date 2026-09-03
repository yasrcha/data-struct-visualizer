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
    if(index < 0 || index >= MAX_SIZE_STRUCT || l->data[index] != -1) {
        return false;
    }
    l->data[index] = value;
    l->size++;
    return true;
}

// Remove Item da Lista
bool ListRemove(List *l, int index) {
    if (index < 0 || index >= MAX_SIZE_STRUCT || l->data[index] == -1) {
        return false;
    }
    l->data[index] = -1;
    l->size--;
    return true;
}

// Verifica se há index vazios ou se estão todos cheios
bool ListStatus(List *l) {
    if(l->size < MAX_SIZE_STRUCT) {
        return true;
    } else {
        return false;
    }
}
