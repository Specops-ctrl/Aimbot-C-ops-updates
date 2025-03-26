#pragma once
#include "GameTypes.h"
#include "ImGui/imgui.h"

void DrawESP(const ESPCfg& espConfig) {
    for (const auto& enemy : EnemyList) {
        if (enemy.Character != nullptr && enemy.Player != nullptr) {
            Vector3 screenPos;
            if (WorldToScreen(enemy.Character->position, screenPos)) {
                if (espConfig.box) {
                    DrawBox(screenPos, espConfig.boxColor);
                }
                if (espConfig.snapline) {
                    DrawSnapline(screenPos, espConfig.snaplineColor);
                }
                if (espConfig.name) {
                    DrawText(screenPos, enemy.Name.c_str(), espConfig.nameColor);
                }
            }
        }
    }
}

bool WorldToScreen(const Vector3& worldPos, Vector3& screenPos) {
    // Implement your world to screen conversion here
    return true;
}

void DrawBox(const Vector3& pos, const ImVec4& color) {
    // Implement box drawing using ImGui or your preferred graphics library
}

void DrawSnapline(const Vector3& pos, const ImVec4& color) {
    // Implement snapline drawing using ImGui or your preferred graphics library
}

void DrawText(const Vector3& pos, const char* text, const ImVec4& color) {
    // Implement text drawing using ImGui or your preferred graphics library
}
