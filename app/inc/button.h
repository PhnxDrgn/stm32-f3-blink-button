#ifndef BUTTON
#define BUTTON

#include "stdint.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef enum
    {
        BUTTON_pressed,
        BUTTON_released,
    } BUTTON_state_t;

#ifdef __cplusplus
}
#endif

#endif /* BUTTON */