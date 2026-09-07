#ifndef GUI_QUEUE_H
#define GUI_QUEUE_H

#include "common.h"
#include "queue.h"

void DrawQueueScreen(AppScreen *currentScreen, Queue *q);
void DrawQueueVisualizer(const int *data, float availableWidth, float offSetX, float centerY);

#endif
