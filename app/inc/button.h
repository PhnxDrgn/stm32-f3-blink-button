#ifndef BUTTON
#define BUTTON

#include "stdint.h"
#include "stdbool.h"
#include "stddef.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef enum
    {
        BUTTON_pressed,
        BUTTON_notPressed,
    } BUTTON_state_t;

    typedef struct
    {
        uint32_t debounceMillis;
    } BUTTON_settings_t;

    typedef struct
    {
        BUTTON_state_t currentState;
        BUTTON_state_t requestedState;
        uint32_t stateChangeMillis;

        BUTTON_settings_t settings;

        void (*buttonPressedCallback)();
        void (*buttonReleasedCallback)();
    } BUTTON_t;

    void BUTTON_init(BUTTON_t *button, void (*btnPressedCallback)(), void (*btnReleasedCallback)());
    void BUTTON_update(BUTTON_t *button, BUTTON_state_t state);

#ifdef __cplusplus
}
#endif

#endif /* BUTTON */