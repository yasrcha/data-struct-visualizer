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

    // Button -> Properties and Retangle Values
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

    DrawListVisualizer(l->data, selectedIndex, availableWidth, controllerSideWidth, windowCenterY);

    StructStatus status = GetListStatus(l);
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

void DrawListVisualizer(const int *data, int selectedIndex, float availableWidth, float offSetX, float centerY) {
    float slotSize = 48.0f;
    float spacing = 8.0f;
    const int fontSize = 20;
    const int valuefontSize = fontSize + 10;
    float totalWidth = (MAX_SIZE_STRUCT * slotSize) + ((MAX_SIZE_STRUCT - 1) * spacing);
    float startX = offSetX + (availableWidth - totalWidth) / 2;
    float startY = centerY - (slotSize / 2.0f);

    for(int i = 0; i < MAX_SIZE_STRUCT; i++) {
        float x = startX + i * (slotSize + spacing);
        float y = startY;
        Rectangle slot = {x, y, slotSize, slotSize};

        DrawRectangle(x, y, slotSize, slotSize, BLUE);

        const char *text = TextFormat("[%d]", i + 1);
        float textSize = MeasureText(text, fontSize);
        DrawText(text, x + ((slotSize - textSize) / 2), y + slotSize + spacing, fontSize, WHITE);

        if(data[i] != -1) {
            DrawRectangle(x, y, slotSize, slotSize, DARKBLUE);
            const char *valueTxt = TextFormat("%d", data[i]);
            float valueTxtSize = MeasureText(valueTxt, valuefontSize);
            DrawText(valueTxt, x + ((slotSize - valueTxtSize) / 2), startY + ((slotSize - valuefontSize) / 2), valuefontSize, WHITE);
        }

        if (i + 1 == selectedIndex) {
            DrawRectangleLinesEx(slot, 2.5f, WHITE);
        } else {
            DrawRectangleLinesEx(slot, 1.5f, (Color){ 80, 80, 80, 255 });
        }
    }
}
