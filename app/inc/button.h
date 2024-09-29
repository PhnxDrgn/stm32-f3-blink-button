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
        uint32_t doubleClickMillis;
    } BUTTON_settings_t;

    typedef struct
    {
        BUTTON_state_t currentState;   // state that gets set after debounce check, aka the user desired state of the button
        BUTTON_state_t requestedState; // state that gets updated in each cycle
        uint32_t stateChangeMillis;    // time since requested state changes between pressed and notPressed
        uint32_t lastClickMillis;      // time since last click

        BUTTON_settings_t settings; // settings

        void (*buttonPressedCallback)();  // callback for when the current state changes from notPressed to pressed
        void (*buttonReleasedCallback)(); // callback for when the current state changes from pressed to notPressed
        void (*doubleClickCallback)();    // callback for when a double click is detected
    } BUTTON_t;

    void BUTTON_init(BUTTON_t *button);
    void BUTTON_update(BUTTON_t *button, BUTTON_state_t state);

#ifdef __cplusplus
}
#endif

#endif /* BUTTON */