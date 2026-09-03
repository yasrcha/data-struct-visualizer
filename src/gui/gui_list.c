#include <stddef.h>
#include <raylib.h>

#include "common.h"
#include "gui_list.h"
#include "list.h"

void DrawListScreen(AppScreen *currentScreen, List *l) {
    ClearBackground(BLACK);

    float controllerSide = GetScreenWidth() * .3; // 30% da Janela para os CONTROLLERS
    float controllerSideMiddle = controllerSide / 2; // Meio da Parte de CONTROLLERS
    float middleHeight = GetScreenHeight() / 2;

    // Divisor Line
    DrawLine(controllerSide, 0, controllerSide, GetScreenHeight(), WHITE);

    int btnWidth = 100;
    int btnHeight = 25;
    int spacing = 20;

    Rectangle btnInsert = {controllerSideMiddle - (btnWidth / 2), middleHeight - btnHeight + 100 - spacing, btnWidth, btnHeight};
    Rectangle btnRemove = {controllerSideMiddle - (btnWidth / 2), middleHeight - (btnHeight / 2) + 100, btnWidth, btnHeight};
    Rectangle btnBack = {controllerSideMiddle - (btnWidth / 2), middleHeight + 100 + btnHeight + spacing, btnWidth, btnHeight};

    static int value = 0;
    static int index = 0;

    int selectedValue = DrawValueSelector(controllerSideMiddle, 20, 9999, 100, "Value: ", &value);
    int selectedIndex = DrawValueSelector(controllerSideMiddle, 20, MAX_SIZE_STRUCT - 1, 180, "Position: ", &index);

    if(DrawButton(btnInsert, "Insert")) {
        ListInsert(l, selectedValue, selectedIndex);
    }
    if(DrawButton(btnRemove, "Remove")) {
        ListRemove(l, selectedIndex);
    }
    if(DrawButton(btnBack, "Back")) {
        *currentScreen = SCREEN_MENU;
    }

    float screenW = (float)GetScreenWidth();
    float screenH = (float)GetScreenHeight();

    float panelWidth = screenW * 0.30f;       // 30% da barra de controles
    float visualizerWidth = screenW * 0.70f;  // 70% da área de desenho

    // Passa o ponteiro da lista e o índice atual selecionado no seletor "Posição:"
    DrawListVisualizer(l, index, panelWidth, visualizerWidth, screenH);
}
