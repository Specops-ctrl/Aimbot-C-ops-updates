#include <Windows.h>
#include "ESP.h"
#include "Aimbot.h"

ESPCfg espConfig;
AimbotCfg aimbotConfig;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)MainThread, hModule, 0, nullptr);
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

DWORD WINAPI MainThread(LPVOID lpParam) {
    while (true) {
        DrawESP(espConfig);
        Aimbot(aimbotConfig);
        Sleep(10); // Adjust the sleep duration as needed
    }
    return 0;
}
