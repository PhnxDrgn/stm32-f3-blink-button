#include "button.h"

void BUTTON_init(BUTTON_t *button)
{
    // default settings
    button->debounceMillis = 150;

    // init meta data
    button->lastValidButtonPress = 0;
}

bool BUTTON_checkPressed(BUTTON_t *button, uint32_t currentMillis)
{
    if ((currentMillis - button->lastValidButtonPress) >= button->debounceMillis)
    {
        button->lastValidButtonPress = currentMillis;
        return true;
    }

    return false;
}