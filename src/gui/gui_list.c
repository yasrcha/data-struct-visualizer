#include <stddef.h>
#include <raylib.h>

#include "common.h"
#include "gui_list.h"
#include "list.h"

void DrawListScreen(AppScreen *currentScreen, List *l) {
    ClearBackground(BLACK);

    // Screen -> Size n Positions Properties
    float windowFullWidth = GetScreenWidth();
    float windowFullHeight = GetScreenHeight();

    float controllerSideWidth = windowFullWidth * .3; // 30% da Janela para os CONTROLLERS
    float controllerSideCenter = controllerSideWidth / 2;
    float windowCenterY = windowFullHeight / 2;

    // Button -> Properties
    int btnWidth = 100;
    int btnHeight = 25;
    int spacing = 20;
    Rectangle btnInsert = {controllerSideCenter - (btnWidth / 2), windowCenterY - btnHeight + 100 - spacing, btnWidth, btnHeight};
    Rectangle btnRemove = {controllerSideCenter - (btnWidth / 2), windowCenterY - (btnHeight / 2) + 100, btnWidth, btnHeight};
    Rectangle btnBack = {controllerSideCenter - (btnWidth / 2), windowCenterY + 100 + btnHeight + spacing, btnWidth, btnHeight};

    // Divisor Line
    DrawLine(controllerSideWidth, 0, controllerSideWidth, windowFullHeight, WHITE);

    static int value = 0;
    static int index = 0;
    int selectedValue = DrawValueSelector(controllerSideCenter, 20, 9999, 100, "Value: ", &value);
    int selectedIndex = DrawValueSelector(controllerSideCenter, 20, MAX_SIZE_STRUCT - 1, 180, "Position: ", &index);

    if(DrawButton(btnInsert, "Insert")) {
        ListInsert(l, selectedValue, selectedIndex);
    }
    if(DrawButton(btnRemove, "Remove")) {
        ListRemove(l, selectedIndex);
    }
    if(DrawButton(btnBack, "Back")) {
        *currentScreen = SCREEN_MENU;
    }
}
