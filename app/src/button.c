#include "button.h"
#include "helpers.h"

void BUTTON_init(BUTTON_t *button)
{
    button->currentState = BUTTON_notPressed;
    button->requestedState = BUTTON_notPressed;
    button->stateChangeMillis = 0;
    button->lastClickMillis = 0;

    button->buttonPressedCallback = NULL;
    button->buttonReleasedCallback = NULL;
    button->doubleClickCallback = NULL;

    button->settings.debounceMillis = 10;
    button->settings.doubleClickMillis = 200;
}

void BUTTON_update(BUTTON_t *button, BUTTON_state_t state)
{
    if (button->requestedState != state)
        button->stateChangeMillis = millis();

    button->requestedState = state;

    if ((button->currentState != button->requestedState) && // state changed with debounce check
        (millis() - button->stateChangeMillis) > button->settings.debounceMillis)
    {
        button->currentState = button->requestedState;

        if (button->currentState == BUTTON_pressed) // button pressed actions
        {
            if (millis() - button->lastClickMillis < button->settings.doubleClickMillis) // double click
            {
                if (button->doubleClickCallback != NULL)
                {
                    button->lastClickMillis = millis();
                    button->doubleClickCallback();
                }
            }
            else // single click
            {
                if (button->buttonPressedCallback != NULL)
                {
                    button->lastClickMillis = millis();
                    button->buttonPressedCallback();
                }
            }
        }
        else if (button->currentState == BUTTON_notPressed) // button released action
        {
            if (button->buttonReleasedCallback != NULL)
                button->buttonReleasedCallback();
        }
    }
}