#include "main.h"
#include "app.h"
#include "led.h"
#include "button.h"
#include "stdbool.h"
#include <stdint.h>

uint32_t blinkTimeMillis = 150; // blink on time

LED_STATE_t ledState = LED_OFF;
uint32_t blinkStateMillis = 0;
BUTTON_state_t lastButtonState = BUTTON_notPressed;

void APP_main()
{
    while (1)
    {
        bool buttonState = getBtnState();

        bool buttonReleased = (buttonState == BUTTON_notPressed) && (lastButtonState != buttonState); // button changed to released

        if (buttonReleased)
        {
            // reset start time for blink
            blinkStateMillis = millis();

            if (ledState != LED_ON)
            {
                // turn on led
                ledState = LED_ON;
                LED_setState(ledState);
            }
        }

        // check blink time to reset
        if ((ledState == LED_ON) && ((millis() - blinkStateMillis) > blinkTimeMillis))
        {
            // turn on off
            ledState = LED_OFF;
            LED_setState(ledState);
        }

        lastButtonState = buttonState;
    }
}