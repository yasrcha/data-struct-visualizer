#include "raylib.h"

#include "common.h"
#include "../include/gui/gui_menu.h"
#include "../include/gui/gui_list.h"
#include "../include/gui/gui_queue.h"
#include "../include/gui/gui_stack.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "DataStruct Visualizer | Yasmin N. Rocha | APS, Estrutura de Dados, Manuel Martins");

    Image icon = LoadImage("assets/icons8-technology-100.png");
    SetWindowIcon(icon);
    SetTargetFPS(60);

    ClearBackground(BLACK);

    AppScreen currentScreen = SCREEN_MENU;

    List myList;
    ListInit(&myList);

    Queue myQueue;
    QueueInit(&myQueue);

    while (!WindowShouldClose()) {
        BeginDrawing();
        switch (currentScreen) {
        case SCREEN_MENU:
            DrawMenuScreen(&currentScreen);
            break;
        case SCREEN_LIST:
            DrawListScreen(&currentScreen, &myList);
            break;
        case SCREEN_QUEUE:
            DrawQueueScreen(&currentScreen, &myQueue);
            break;
        case SCREEN_STACK:
            DrawStackScreen(&currentScreen);
            break;
        default:
            break;
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
