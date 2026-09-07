#ifndef GUI_LIST_H
#define GUI_LIST_H

#include "common.h"
#include "list.h"

void DrawListScreen(AppScreen *currentScreen, List *l);
void DrawListVisualizer(const int *data, int selectedIndex, float availableWidth, float offSetX, float centerY);

#endif
