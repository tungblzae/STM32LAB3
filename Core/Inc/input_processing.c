       //Lab3ex7
        #include "main.h"
        #include "input_reading.h"
        #include "output_display.h"

        typedef enum {
            MODE_NORMAL,
            MODE_MODIFY_RED,
            MODE_MODIFY_AMBER,
            MODE_MODIFY_GREEN,
            MODE_COUNT  // Add a mode count for cycling through modes
        } TrafficLightMode;

        TrafficLightMode currentMode = MODE_NORMAL;
        uint8_t redDuration = 1;
        uint8_t amberDuration = 1;
        uint8_t greenDuration = 1;

        void increaseMode(void) {
            currentMode = (TrafficLightMode)((currentMode + 1) % MODE_COUNT);
        }

        void fsm_for_input_processing(void) {
            button_reading();  // Call the button reading function

            switch (currentMode) {
            case MODE_NORMAL:
                       setRedLEDState(GPIO_PIN_SET);    // Turn on red LEDs
                       setAmberLEDState(GPIO_PIN_RESET); // Turn off amber LEDs
                       setGreenLEDState(GPIO_PIN_RESET); // Turn off green LEDs
            case MODE_MODIFY_RED:
                        if (is_button_pressed(1)) {
                            redDuration++; // Increase red duration
                            if (redDuration > 99) {
                                redDuration = 1; // Wrap around if it exceeds 99
                            }
                        } else if (is_button_pressed_1s(1)) {
                            increaseMode(); // Move to the next mode
                        }

                        // Check for second button press to increase red duration
                        if (is_button_pressed(2)) {
                            redDuration++; // Increase red duration
                            if (redDuration > 99) {
                                redDuration = 1; // Wrap around if it exceeds 99
                            }
                        }

                        // Check for third button press to set red duration
                        if (is_button_pressed_1s(2)) {
                            // Set the red duration value
                         setRedDuration(redDuration);
                        }
                        break;

              case MODE_MODIFY_AMBER:
                        if (is_button_pressed(1)) {
                            amberDuration++; // Increase amber duration
                            if (amberDuration > 99) {
                                amberDuration = 1; // Wrap around if it exceeds 99
                            }
                        } else if (is_button_pressed_1s(1)) {
                            increaseMode(); // Move to the next mode
                        }

                        // Handle the second and third button for amber (similar to the red case)
                        break;

                    case MODE_MODIFY_GREEN:
                        if (is_button_pressed(1)) {
                            greenDuration++; // Increase green duration
                            if (greenDuration > 99) {
                                greenDuration = 1; // Wrap around if it exceeds 99
                            }
                        } else if (is_button_pressed_1s(1)) {
                            increaseMode(); // Move to the next mode
                        }

                        break;
                }

                displayMode(currentMode);  // Display the current mode on seven-segment LEDs
                blinkLEDs(currentMode);    // Blink LEDs based on the selected mode
            }
 //lab3ex8
#include "main.h"
#include "input_reading.h"
#include "output_display.h"

typedef enum {
    MODE_NORMAL,
    MODE_MODIFY_RED,
    MODE_MODIFY_AMBER,
    MODE_MODIFY_GREEN,
    MODE_COUNT  // Add a mode count for cycling through modes
} TrafficLightMode;

TrafficLightMode currentMode = MODE_NORMAL;
uint8_t redDuration = 1;
uint8_t amberDuration = 1;
uint8_t greenDuration = 1;

void increaseMode(void) {
    currentMode = (TrafficLightMode)((currentMode + 1) % MODE_COUNT);
}

void fsm_for_input_processing(void) {
    button_reading();  // Call the button reading function

    switch (currentMode) {
        // ... (Other cases remain unchanged)

        case MODE_MODIFY_AMBER:
            // Implement your code for modifying amber duration
            if (is_button_pressed(1)) {
                amberDuration++; // Increase amber duration
                if (amberDuration > 99) {
                    amberDuration = 1; // Wrap around if it exceeds 99
                }
            } else if (is_button_pressed_1s(1)) {
                increaseMode(); // Move to the next mode
            }

            // Check for second button press to increase amber duration
            if (is_button_pressed(2)) {
                amberDuration++; // Increase amber duration
                if (amberDuration > 99) {
                    amberDuration = 1; // Wrap around if it exceeds 99
                }
            }

            // Check for third button press to set amber duration
            if (is_button_pressed_1s(2)) {
                // Set the amber duration value
                 setAmberDuration(amberDuration);
            }
            break;

        case MODE_MODIFY_AMBER:
                              if (is_button_pressed(1)) {
                                  amberDuration++; // Increase amber duration
                                  if (amberDuration > 99) {
                                      amberDuration = 1; // Wrap around if it exceeds 99
                                  }
                              } else if (is_button_pressed_1s(1)) {
                                  increaseMode(); // Move to the next mode
                              }

                              // Handle the second and third button for amber (similar to the red case)
                              break;

         case MODE_MODIFY_GREEN:
                              if (is_button_pressed(1)) {
                                  greenDuration++; // Increase green duration
                                  if (greenDuration > 99) {
                                      greenDuration = 1; // Wrap around if it exceeds 99
                                  }
                              } else if (is_button_pressed_1s(1)) {
                                  increaseMode(); // Move to the next mode
                              }

                              break;
    }

    displayMode(currentMode);  // Display the current mode on seven-segment LEDs
    blinkLEDs(currentMode);    // Blink LEDs based on the selected mode
}
//lab3ex9
#include "main.h"
#include "input_reading.h"
#include "output_display.h"

typedef enum {
    MODE_NORMAL,
    MODE_MODIFY_RED,
    MODE_MODIFY_AMBER,
    MODE_MODIFY_GREEN,
    MODE_COUNT  // Add a mode count for cycling through modes
} TrafficLightMode;

TrafficLightMode currentMode = MODE_NORMAL;
uint8_t redDuration = 1;
uint8_t amberDuration = 1;
uint8_t greenDuration = 1;

void increaseMode(void) {
    currentMode = (TrafficLightMode)((currentMode + 1) % MODE_COUNT);
}

void fsm_for_input_processing(void) {
    button_reading();  // Call the button reading function

    switch (currentMode) {
        // ... (Other cases remain unchanged)

        case MODE_MODIFY_AMBER:
            // Implement your code for modifying amber duration

            if (is_button_pressed(1)) {
                amberDuration++; // Increase amber duration
                if (amberDuration > 99) {
                    amberDuration = 1; // Wrap around if it exceeds 99
                }
            } else if (is_button_pressed_1s(1)) {
                increaseMode(); // Move to the next mode
            }

            // Check for second button press to increase amber duration
            if (is_button_pressed(2)) {
                amberDuration++; // Increase amber duration
                if (amberDuration > 99) {
                    amberDuration = 1; // Wrap around if it exceeds 99
                }
            }

            // Check for third button press to set amber duration
            if (is_button_pressed_1s(2)) {
                // Set the amber duration value
              setAmberDuration(amberDuration);
            }
            break;

        case MODE_MODIFY_AMBER:
                                     if (is_button_pressed(1)) {
                                         amberDuration++; // Increase amber duration
                                         if (amberDuration > 99) {
                                             amberDuration = 1; // Wrap around if it exceeds 99
                                         }
                                     } else if (is_button_pressed_1s(1)) {
                                         increaseMode(); // Move to the next mode
                                     }

                                     // Handle the second and third button for amber (similar to the red case)
                                     break;

          case MODE_MODIFY_GREEN:
                                     if (is_button_pressed(1)) {
                                         greenDuration++; // Increase green duration
                                         if (greenDuration > 99) {
                                             greenDuration = 1; // Wrap around if it exceeds 99
                                         }
                                     } else if (is_button_pressed_1s(1)) {
                                         increaseMode(); // Move to the next mode
                                     }

                                     break;
    }

    displayMode(currentMode);  // Display the current mode on seven-segment LEDs
    blinkLEDs(currentMode);    // Blink LEDs based on the selected mode
}

