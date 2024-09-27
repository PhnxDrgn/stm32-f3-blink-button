#include "main.h"
#include "app.h"
#include "led.h"
#include "button.h"
#include "stdbool.h"
#include <stdint.h>

volatile bool buttonUpdate = false;
bool buttonAction = false;
volatile LED_STATE_t ledState = LED_OFF;
BUTTON_t button;

void APP_main()
{
    // inits
    BUTTON_init(&button);

    while (1)
    {
        if (buttonUpdate)
        {
            buttonAction = BUTTON_checkPressed(&button, millis());
            buttonUpdate = false;
        }

        if (buttonAction)
        {
            switch (ledState)
            {
            case LED_OFF:
                ledState = LED_ON;
                break;

            case LED_ON:
                ledState = LED_OFF;
                break;
            }

            LED_setState(ledState);
            buttonAction = false;
        }
    }
}

void APP_buttonPressed()
{
    buttonUpdate = true;
}