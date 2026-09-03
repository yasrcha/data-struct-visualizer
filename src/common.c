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
        if(*value < limit) {
            (*value)++;
        }
    }
    if(DrawButton(btnDecrement, "-")) {
        if(*value >= 0) {
            (*value)--;
        }
    }

    DrawText(label, middlePosition - ((MeasureText(label, fontSize - 5)) / 2), height - spacing, fontSize - 5, WHITE);
    const char *text = TextFormat("%d", *value);
    float textSize = MeasureText(text, fontSize);
    DrawText(text, middlePosition - (textSize / 2), height, fontSize, WHITE);

    return *value;
}

void DrawListVisualizer(const List *l, int selectedIndex, float offsetX, float availableWidth, float screenHeight) {
    const float slotSize = 48.0f;
    const float spacing = 8.0f;
    const int fontSize = 20;

    // Largura total dos slots fixos
    float totalWidth = (MAX_SIZE_STRUCT * slotSize) + ((MAX_SIZE_STRUCT - 1) * spacing);

    // Centraliza horizontalmente dentro dos 70% e verticalmente na tela
    float startX = offsetX + (availableWidth - totalWidth) / 2.0f;
    float startY = (screenHeight - slotSize) / 2.0f;

    for (int i = 0; i < MAX_SIZE_STRUCT; i++) {
        float x = startX + i * (slotSize + spacing);
        float y = startY;
        Rectangle slot = { x, y, slotSize, slotSize };

        // 1. Se tem valor diferente de -1, desenha o preenchimento azul e o número
        if (l->data[i] != -1) {
            DrawRectangleRec(slot, (Color){ 37, 99, 235, 255 }); // Azul

            const char *valText = TextFormat("%d", l->data[i]);
            int textWidth = MeasureText(valText, fontSize);
            DrawText(valText,
                     (int)(x + (slotSize - textWidth) / 2),
                     (int)(y + (slotSize - fontSize) / 2),
                     fontSize, WHITE);
        }

        // 2. Contorno do slot (destaque branco se for a posição selecionada no seletor)
        if (i == selectedIndex) {
            DrawRectangleLinesEx(slot, 2.5f, WHITE);
        } else {
            DrawRectangleLinesEx(slot, 1.5f, (Color){ 80, 80, 80, 255 });
        }

        // 3. Índice da posição [0] a [9] logo abaixo
        const char *idxText = TextFormat("[%d]", i);
        int idxWidth = MeasureText(idxText, 14);
        DrawText(idxText,
                 (int)(x + (slotSize - idxWidth) / 2),
                 (int)(y + slotSize + 6),
                 14, GRAY);
    }
}
