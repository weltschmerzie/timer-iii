#include "plugin.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "UIManager.h"
#include "CKeyboardState.h" 
#include "eKeys.h"

// We will leave it empty for now.
// Later we will add logic for hotkeys here.
void InputManager::ProcessInput() {
    // Check for key presses once per frame
    if (KeyPressed(eKeys::KEY_F5)) {
        // Set time to noon
        TimeManager::SetTime(12, 0);
    }

    if (KeyPressed(eKeys::KEY_F6)) {
        // Set time to midnight
        TimeManager::SetTime(0, 0);
    }

    if (KeyPressed(eKeys::KEY_F7)) {
        // Toggle time freeze
        TimeManager::FreezeTime(!TimeManager::bTimeFrozen);
    }

    if (KeyPressed(eKeys::KEY_F8)) {
        // Toggle menu visibility
        UIManager::ToggleMenu();
    }
} 