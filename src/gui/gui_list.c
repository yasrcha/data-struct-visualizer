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
    
    // Seletores de Index e de Valores
    static int value = 1;
    static int index = 1;
    int selectedValue = DrawValueSelector(controllerSideCenter, 20, 9999, 100, "Value: ", &value);
    int selectedIndex = DrawValueSelector(controllerSideCenter, 20, l->size, 180, "Position: ", &index);

    // Botões de Ação -> Adiciona, Remove e volta para a tela inicial
    if(DrawButton(btnInsert, "Insert")) {
        ListInsert(l, selectedValue, selectedIndex - 1);
    }
    if(DrawButton(btnRemove, "Remove")) {
        ListRemove(l, selectedIndex - 1);
    }
    if(DrawButton(btnBack, "Back")) {
        *currentScreen = SCREEN_MENU;
        ListInit(l);
    }

    float availableWidth = windowFullWidth * 0.70f;

    DrawStructVisualizer(l->data, selectedIndex, availableWidth, controllerSideWidth, windowCenterY);

    ListStatus status = GetListStatus(l);
    char *statusMsg = "";
    Color statusColor = WHITE;

    switch (status) {
        case LIST_EMPTY:
            statusMsg = "A lista está vazia!";
            statusColor = GREEN;
            break;
        case LIST_AVAILABLE:
            statusMsg = "Ainda há espaços disponíveis!";
            statusColor = YELLOW;
            break;
        case LIST_FULL:
            statusMsg = "A lista está cheia!";
            statusColor = RED;
            break;
        default:
            break;
    };

    int textSize = MeasureText(statusMsg, 20);
    float textX = controllerSideWidth + (availableWidth - textSize) / 2;
    DrawText(statusMsg, textX, (windowCenterY + 100), 20, statusColor);
}
