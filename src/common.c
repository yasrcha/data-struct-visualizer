#include <stddef.h>
#include "common.h"
#include "list.h"

bool DrawButton(Rectangle bounds, const char *text) {
    Vector2 mousePos = GetMousePosition(); // Pega a posição do mouse dentro da janela.
    bool isHouvered = CheckCollisionPointRec(mousePos, bounds); // Verifica se o mouse esta dentro dos limites do botão.

    Color btnColor = isHouvered ? (Color){70, 130, 180, 255} : (Color){ 52, 73, 94, 255 };
    DrawRectangleRounded(bounds, 0.2f, 4, btnColor);

    int fontSize = 20;
    int textWidth = MeasureText(text, fontSize);
    DrawText(text, bounds.x + (bounds.width - textWidth) / 2, bounds.y + (bounds.height - fontSize) / 2, fontSize, WHITE);

    return isHouvered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON); // Retorna True só se o mouse estiver em cima do botão E o botão esquerdo do mouse for pressionado;
}

int DrawValueSelector(float middlePosition, int fontSize, int limit, int height, const char *label, int *value) {
    int spacing = 25;
    int btnSize = fontSize;

    Rectangle btnIncrement = {middlePosition - (btnSize / 2) + spacing, height, btnSize, btnSize};
    Rectangle btnDecrement = {middlePosition - (btnSize / 2) - spacing, height, btnSize, btnSize};

    if(DrawButton(btnIncrement, "+")) {
        if(*value <= limit) {
            (*value)++;
        }
    }
    if(DrawButton(btnDecrement, "-")) {
        if(*value > 1) {
            (*value)--;
        }
    }

    DrawText(label, middlePosition - ((MeasureText(label, fontSize - 5)) / 2), height - spacing, fontSize - 5, WHITE);
    const char *text = TextFormat("%d", *value);
    float textSize = MeasureText(text, fontSize);
    DrawText(text, middlePosition - (textSize / 2), height, fontSize, WHITE);

    return *value;
}

void DrawStructVisualizer(const int *data, int selectedIndex, float availableWidth, float offSetX, float centerY) {
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
