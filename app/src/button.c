#include "button.h"
#include "helpers.h"

void BUTTON_init(BUTTON_t *button, void (*btnPressedCallback)(), void (*btnReleasedCallback)())
{
    button->currentState = BUTTON_notPressed;
    button->requestedState = BUTTON_notPressed;
    button->stateChangeMillis = 0;

    button->buttonPressedCallback = btnPressedCallback;
    button->buttonReleasedCallback = btnReleasedCallback;

    button->settings.debounceMillis = 10;
}

void BUTTON_update(BUTTON_t *button, BUTTON_state_t state)
{
    if (button->requestedState != state)
        button->stateChangeMillis = millis();

    button->requestedState = state;

    if ((button->currentState != button->requestedState) &&
        (millis() - button->stateChangeMillis))
    {
        button->currentState = button->requestedState;

        if (button->currentState == BUTTON_pressed)
        {
            if (button->buttonPressedCallback != NULL)
                button->buttonPressedCallback();
        }
        else if (button->currentState == BUTTON_notPressed)
        {
            if (button->buttonReleasedCallback != NULL)
                button->buttonReleasedCallback();
        }
    }
}