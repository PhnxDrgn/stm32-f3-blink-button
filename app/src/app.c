#include "main.h"
#include "app.h"
#include "led.h"
#include "button.h"
#include "stdbool.h"
#include <stdint.h>

uint32_t blinkTimeMillis = 500; // blink on time

volatile bool buttonUpdate = false;
bool buttonAction = false;
LED_STATE_t ledState = LED_OFF;
uint32_t blinkStateMillis = 0;
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
            // only blink if blink is not already in progress
            if (ledState == LED_OFF)
            {
                // update start time for blink
                blinkStateMillis = millis();

                // turn on LED
                ledState = LED_ON;
                LED_setState(ledState);
            }

            // reset action trigger
            buttonAction = false;
        }

        // check blink time to reset
        if ((ledState == LED_ON) && ((millis() - blinkStateMillis) > blinkTimeMillis))
        {
            // turn on off
            ledState = LED_OFF;
            LED_setState(ledState);
        }
    }
}

void APP_buttonPressed()
{
    buttonUpdate = true;
}