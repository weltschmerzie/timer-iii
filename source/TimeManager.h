#pragma once

class TimeManager {
public:
    static bool bTimeFrozen;

    static void Update();
    static void SetTime(int hours, int minutes);
    static int GetHours();
    static int GetMinutes();
    static void FreezeTime(bool freeze);

private:
    static int frozenHours;
    static int frozenMinutes;
}; 