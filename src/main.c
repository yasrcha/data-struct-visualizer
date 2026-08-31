#include "raylib.h"
#include "../include/common.h"
#include "gui_menu.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "DataStruct Visualizer | Yasmin N. Rocha | APS, Estrutura de Dados, Manuel Martins");

    Image icon = LoadImage("assets/icons8-technology-100.png");
    SetWindowIcon(icon);
    SetTargetFPS(60);

    AppScreen currentScreen = SCREEN_MENU;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKGRAY);

        DrawMenuScreen(&currentScreen);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
