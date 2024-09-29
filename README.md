# ENPM615 Assignment 1
Manoj Franklin

Andy Hoang

Simple Push Button Blink on NUCLEO-F303K8

This project was created using my [stm32-f3-blink template](https://github.com/PhnxDrgn/stm32-f3-blink).

## How it Works
### Hardware
- The LED used was the built-in LED in the NUCLEO-F303K8 board.
- The button was a generic breadboard push button.

### Circuit
- LED
    - The LED was built in so nothing was changed about it.
- Button
    - One side of the button was connected to ground while the other side was conncted to pin D13

### Board Support Package
The board support package (BSP) was created using the STM32CubeMX program provided by ST.

Since the NUCLEO board is a product of ST, the board was selected as a starting point in that program. The board's pinout showed that the LED was pin PB_3 so that pin was set as a GPIO_Output. The pin selected for the button was pin PB_4 so that pin was set as a GPIO_Input with the pin pulled up. That way, by default, the pin would be read as "GPIO_PIN_SET" and when the button was pushed, it would be read as "GPIO_PIN_RESET".

### The Program
#### Compiling
In STM32CubeMX, I set the toolchain/IDE setting to Makefile so it would output files that I could use CMake with. I copied the `arm-none-eabi-gcc.cmake` file and used it with my `CMakeLists.txt` to compile the code for the ARM processor.

#### App
In the `main.c` generated from STM32CubeMX, there are sections left for user code. I wrote my application in a file called `app.c`. This file contains my app's main while loop. I created an `app.h` file that I added to the `main.c` file to link the app to the board. The `app.c` includes the generated `main.h` file which is where I added prototypes for generic functions used in app like `millis()` and `getBtnState()`.

In every loop of my app's infinite while loop, it updates the button's state. If the button's state changes from not pressed to pressed, it will call the button `buttonPressedCallback` function. This function turns on the LED and resets the timer for how long the LED has been on. Once the timer hits 150 ms, the led is set to off. I also noticed there was an issue with debouncing when the button was released so I added in a debounce timer to check for input changes over 100 ms before changing the button's state.

I also added in a double click feature where if the last click was within 200 ms of the current one, it will make the LED stay on, a single click after that will turn it off again.