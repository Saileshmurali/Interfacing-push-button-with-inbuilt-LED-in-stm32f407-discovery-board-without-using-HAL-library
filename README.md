# Interfacing-push-button-with-inbuilt-LED-in-stm32f407-discovery-board-without-using-HAL-library
The need for NOP inside delay varies from compiler to compiler. Some compilers would optimise the code if the NOP line is absent, so the delay function won't be executed.
