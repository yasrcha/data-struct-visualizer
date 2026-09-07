#ifndef COMMON_H
#define COMMON_H

#define MAX_SIZE_STRUCT 10

#include "raylib.h"


// Enumera as diferentes páginas do visualizador.
typedef enum {
    SCREEN_MENU = 0,
    SCREEN_LIST, // 1
    SCREEN_QUEUE, // 2
    SCREEN_STACK // 3
} AppScreen;

typedef enum {
    LIST_EMPTY = 0,
    LIST_FULL,
    LIST_AVAILABLE
} StructStatus;

#include "list.h"
#include "queue.h"

bool DrawButton(Rectangle bounds, const char *text);
int DrawValueSelector(float middlePosition, int fontSize, int limit, int height, const char *label, int *value);

#endif
