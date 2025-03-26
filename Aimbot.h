#pragma once
#include "GameTypes.h"

void Aimbot(const AimbotCfg& aimbotConfig) {
    if (!aimbotConfig.aimbot) return;

    Enemy* target = nullptr;
    float bestFov = aimbotConfig.fovValue;

    for (auto& enemy : EnemyList) {
        if (enemy.Character != nullptr && enemy.Player != nullptr && IsVisible(enemy)) {
            Vector3 screenPos;
            if (WorldToScreen(enemy.Character->position, screenPos)) {
                float fov = CalculateFov(screenPos);
                if (fov < bestFov) {
                    bestFov = fov;
                    target = &enemy;
                }
            }
        }
    }

    if (target) {
        AimAtTarget(target, aimbotConfig);
    }
}

void AimAtTarget(Enemy* target, const AimbotCfg& aimbotConfig) {
    Vector3 aimPos = GetAimPosition(target, aimbotConfig.aimBone);
    if (aimbotConfig.aimbotSmooth) {
        // Smooth aiming logic here
    } else {
        // Direct aiming logic here
    }
}

bool IsVisible(Enemy& enemy) {
    // Implement visibility check logic here
    return true;
}

Vector3 GetAimPosition(Enemy* enemy, BodyPart aimBone) {
    // Get the position of the specified bone
    return enemy->Character->GetBonePosition(aimBone);
}
