#ifndef INPUT_READING_H
#define INPUT_READING_H

#include "main.h"  // Include the main header file for your project

// Define the button reading and checking functions
void button_reading(void);
unsigned char is_button_pressed(uint8_t index);
unsigned char is_button_pressed_1s(uint8_t index);

#endif /* INPUT_READING_H */
