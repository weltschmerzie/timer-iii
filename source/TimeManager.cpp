#include "plugin.h"
#include "TimeManager.h"
#include "CClock.h"

bool TimeManager::bTimeFrozen = false;
int TimeManager::frozenHours = 0;
int TimeManager::frozenMinutes = 0;

void TimeManager::SetTime(int hours, int minutes) {
    CClock::SetGameClock(hours, minutes);
}

int TimeManager::GetHours() {
    return CClock::ms_nGameClockHours;
}

int TimeManager::GetMinutes() {
    return CClock::ms_nGameClockMinutes;
}

void TimeManager::FreezeTime(bool freeze) {
    bTimeFrozen = freeze;
    if (bTimeFrozen) {
        frozenHours = GetHours();
        frozenMinutes = GetMinutes();
    }
}

void TimeManager::Update() {
    if (bTimeFrozen) {
        SetTime(frozenHours, frozenMinutes);
    }
} 