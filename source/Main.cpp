#include "plugin.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "UIManager.h"

using namespace plugin;

class TimerIII {
public:
    TimerIII() {
        // Initialize UIManager
        UIManager::Init();

        // We will call ProcessInput and Update every frame
        Events::gameProcessEvent.Add(InputManager::ProcessInput);
        Events::gameProcessEvent.Add(TimeManager::Update);

        // We will render our UI on the drawing event
        Events::drawingEvent.Add(UIManager::Render);
	}
} timer_iiiPlugin;