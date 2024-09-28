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

In every loop of my app's infinite while loop, it polls for the state of the button. If the button's state was not pressed and the last state was pressed, that means that the button was just released. That was when I turned the LED on and reset the LED on timer. Once the timer hits 150 ms, the led is set to off. I decided to implement this application this way because it reminds me of selecting something on a computer or phone where the release of the button is when the object is selected. In this case, the object being selected is the LED blink. In the video attached in ELMS, you can see the button being held down which does not blink the LED, only when it gets released does the LED activate.
