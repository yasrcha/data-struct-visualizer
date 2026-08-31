#include "common.h"

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
