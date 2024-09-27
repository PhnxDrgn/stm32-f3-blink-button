#include "main.h"
#include "app.h"
#include "led.h"
#include <stdint.h>

void app()
{
    while (1)
    {
        static uint32_t refMillis = 0;
        static LED_STATE_t ledState = LED_OFF;

        uint32_t currentMillis = millis();

        if (currentMillis - refMillis > 1000)
        {
            refMillis = currentMillis;
            
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
        }
    }
}