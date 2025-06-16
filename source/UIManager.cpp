#include "plugin.h"
#include "UIManager.h"
#include "TimeManager.h"
#include "imgui.h"

bool UIManager::bMenuVisible = false;

void UIManager::Init() {
    // Initialization if needed in the future
}

void UIManager::Render() {
    if (!bMenuVisible) {
        return;
    }

    // Begin ImGui window
    ImGui::Begin("Time Controller", &bMenuVisible);

    // Display current time
    ImGui::Text("Current Time: %02d:%02d", TimeManager::GetHours(), TimeManager::GetMinutes());

    // Time manipulation buttons
    if (ImGui::Button("Hour+")) {
        TimeManager::SetTime(TimeManager::GetHours() + 1, TimeManager::GetMinutes());
    }
    ImGui::SameLine();
    if (ImGui::Button("Hour-")) {
        TimeManager::SetTime(TimeManager::GetHours() - 1, TimeManager::GetMinutes());
    }
    ImGui::SameLine();
    if (ImGui::Button("Min+")) {
        TimeManager::SetTime(TimeManager::GetHours(), TimeManager::GetMinutes() + 1);
    }
    ImGui::SameLine();
    if (ImGui::Button("Min-")) {
        TimeManager::SetTime(TimeManager::GetHours(), TimeManager::GetMinutes() - 1);
    }

    // Freeze time checkbox
    if (ImGui::Checkbox("Freeze Time", &TimeManager::bTimeFrozen)) {
        TimeManager::FreezeTime(TimeManager::bTimeFrozen);
    }

    ImGui::End();
}

void UIManager::ToggleMenu() {
    bMenuVisible = !bMenuVisible;
} 