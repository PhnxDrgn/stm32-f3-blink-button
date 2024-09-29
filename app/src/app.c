#include "main.h"
#include "app.h"
#include "led.h"
#include "button.h"
#include "helpers.h"
#include <stdbool.h>
#include <stdint.h>

uint32_t blinkTimeMillis = 150; // blink on time

LED_STATE_t ledState = LED_OFF;
uint32_t blinkStateMillis = 0;
bool doubleClicked = false;

BUTTON_t button;

void APP_main()
{
    BUTTON_init(&button);
    button.buttonPressedCallback = APP_buttonClicked;
    button.doubleClickCallback = APP_doubleClick;

    while (1)
    {
        // update button state
        BUTTON_update(&button, getBtnState());

        // check blink time to reset
        if (!doubleClicked &&
            (ledState == LED_ON) &&
            ((millis() - blinkStateMillis) > blinkTimeMillis))
        {
            // turn on off
            ledState = LED_OFF;
            LED_setState(ledState);
        }
    }
}

void APP_buttonClicked()
{
    // reset start time for blink
    blinkStateMillis = millis();

    if (ledState != LED_ON)
    {
        // turn on led
        ledState = LED_ON;
        LED_setState(ledState);
    }

    doubleClicked = false;
}

void APP_doubleClick()
{
    if (ledState != LED_ON)
    {
        // turn on led
        ledState = LED_ON;
        LED_setState(ledState);
    }
    doubleClicked = true;
}