#ifndef BUTTON
#define BUTTON

#include "stdint.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct
    {
        uint32_t debounceMillis;

        // button meta data: do not change
        uint32_t lastValidButtonPress;
    } BUTTON_t;

    void BUTTON_init(BUTTON_t *button);
    bool BUTTON_checkPressed(BUTTON_t *button, uint32_t currentMillis);
#ifdef __cplusplus
}
#endif

#endif /* BUTTON */