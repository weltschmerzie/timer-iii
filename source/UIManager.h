#pragma once

class UIManager {
public:
    static bool bMenuVisible;

    static void Init();
    static void Render();
    static void ToggleMenu();
}; 