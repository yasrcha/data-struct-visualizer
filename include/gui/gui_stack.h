#ifndef GUI_STACK_H
#define GUI_STACK_H

#include "common.h"
#include "stack.h"

void DrawStackScreen(AppScreen *currentScreen, Stack *s);
void DrawStackVisualizer(const int *data, float availableWidth, float offSetX, float centerY);

#endif
