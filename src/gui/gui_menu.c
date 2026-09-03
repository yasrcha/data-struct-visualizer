#include <raylib.h>
#include "common.h"
#include "gui_menu.h"

void DrawMenuScreen(AppScreen *currentScreen) {
    ClearBackground(BLACK);
    
    int fontSizeTitle = 40;
    int fontSizeText = 15;

    DrawText("Data Struct Vizualizer", ((GetScreenWidth() - MeasureText("Data Struct Vizualizer", fontSizeTitle)) / 2), 50, fontSizeTitle, WHITE); // Title
    DrawText("Escolha qual estrutura você quer criar e interagir com:", ((GetScreenWidth() - MeasureText("Escolha qual estrutura você quer criar e interagir com:", fontSizeText)) / 2), 100, fontSizeText, WHITE); //Text

    Rectangle btnList = {300, 160, 200, 50};
    Rectangle btnQueue = {300, 220, 200, 50};
    Rectangle btnStack = {300, 280, 200, 50};


    if(DrawButton(btnList, "List")) {
        *currentScreen = SCREEN_LIST;
    }
    if (DrawButton(btnQueue, "Queue")) {
        *currentScreen = SCREEN_QUEUE;
    }
    if (DrawButton(btnStack, "Stack")) {
        *currentScreen = SCREEN_STACK;
    }
};
