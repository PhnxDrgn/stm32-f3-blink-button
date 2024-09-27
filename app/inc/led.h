#ifndef LED
#define LED

#ifdef __cplusplus
extern "C"
{
#endif

    typedef enum LED_STATE
    {
        LED_OFF = 0,
        LED_ON
    } LED_STATE_t;

    void LED_setState(LED_STATE_t state);

#ifdef __cplusplus
}
#endif

#endif /* LED */