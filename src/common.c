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
