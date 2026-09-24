#include <raylib.h>
#include "common.h"
#include "stack.h"
#include "gui_stack.h"

void DrawStackScreen(AppScreen *currentScreen, Stack *s) {
    ClearBackground(BLACK);

    // Screen -> Size n Positions Properties
    float windowFullWidth = GetScreenWidth();
    float windowFullHeight = GetScreenHeight();

    float controllerSideWidth = windowFullWidth * .3; // 30% Screen -> CONTROLLERS on the Left Side
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

     // Valule Selectors
    static int value = 1;
    int selectedValue = DrawValueSelector(controllerSideCenter, 20, 9999, 100, "Value: ", &value);

    // Action Buttons -> Add, Remove itens from the struct. Back Button is a Nav Button (Return to Menu Screen)
    if(DrawButton(btnInsert, "Insert")) {
        StackInsert(s, selectedValue);
    }
    if(DrawButton(btnRemove, "Remove")) {
        StackRemove(s);
    }
    if(DrawButton(btnBack, "Back")) {
        *currentScreen = SCREEN_MENU;
        StackInit(s);
    }

    float availableWidth = windowFullWidth * 0.70f;

    // Draw Struct Visualizer > 70% left on the Right Side of the Screen (availableWidth)
    DrawStackVisualizer(s->data, availableWidth, controllerSideWidth, windowCenterY);

    // STATUS msg Properties
    StructStatus status = GetStackStatus(s);
    char *statusMsg = "";
    Color statusColor = WHITE;

    switch (status) {
        case LIST_EMPTY:
            statusMsg = "A pilha está vazia!";
            statusColor = GREEN;
            break;
        case LIST_AVAILABLE:
            statusMsg = "Ainda há\nespaços\ndisponíveis!";
            statusColor = YELLOW;
            break;
        case LIST_FULL:
            statusMsg = "A pilha\nestá cheia!";
            statusColor = RED;
            break;
        default:
            break;
    };

    // Draw Status Msg Text
    DrawText(statusMsg, (availableWidth / 2), windowCenterY - (20 / 2), 20, statusColor);
}

// Função que Desenha na Tela a Estrutura (Pilha/Stack)
void DrawStackVisualizer(const int *data, float availableWidth, float offSetX, float centerY) {
    float slotSize = 30.0f;
    float spacing = 8.0f;
    const int fontSize = 20;
    const int valuefontSize = fontSize + 10;

    float totalHeight = (MAX_SIZE_STRUCT * slotSize) + ((MAX_SIZE_STRUCT - 1) * spacing);
    float startX = offSetX + (availableWidth - slotSize) / 2.0f;
    float startY = centerY - (totalHeight / 2.0f); // Centralizado usando o centerY passado

    for (int i = 0; i < MAX_SIZE_STRUCT; i++) {
        float x = startX;
        float y = startY + (MAX_SIZE_STRUCT - 1 - i) * (slotSize + spacing); // Inverte o Desenho dos SLOTS, deixando os indices menores na base da pilha ao invés de no topo

        DrawRectangle(x, y, slotSize, slotSize, BLUE);

        const char *text = TextFormat("[%d]", i + 1);
        DrawText(text, x + slotSize + spacing, y + (slotSize - fontSize) / 2.0f, fontSize, WHITE);

        if (data[i] != -1) {
            DrawRectangle(x, y, slotSize, slotSize, DARKBLUE);

            const char *valueTxt = TextFormat("%d", data[i]);
            float valueWidth = MeasureText(valueTxt, valuefontSize);

            DrawText(valueTxt, x + (slotSize - valueWidth) / 2.0f, y + (slotSize - valuefontSize) / 2.0f, valuefontSize, WHITE);
        }
    }
}
