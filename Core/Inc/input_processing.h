#include "main.h"
#include "input_reading.h"

enum Mode {
    MODE_NORMAL,
    MODE_MODIFY_RED,
    MODE_MODIFY_AMBER,
    MODE_MODIFY_GREEN
};

enum Mode currentMode = MODE_NORMAL;
uint8_t redDuration = 1;    // Initial duration for red LEDs
uint8_t amberDuration = 1;  // Initial duration for amber LEDs
uint8_t greenDuration = 1;  // Initial duration for green LEDs

void fsm_for_input_processing(void) {
    switch (currentMode) {
        case MODE_NORMAL:
        case MODE_NORMAL:
            // Check the current time to determine which road should be active.
            if (your_current_time < redDuration) {
                // Red light is active.
                // Set amber and green LEDs for all roads to OFF.
                SetRedLightsOn(Road1);
                SetRedLightsOn(Road2);
                SetRedLightsOn(Road3);
                SetAmberLightsOff(Road1);
                SetAmberLightsOff(Road2);
                SetAmberLightsOff(Road3);
                SetGreenLightsOff(Road1);
                SetGreenLightsOff(Road2);
                SetGreenLightsOff(Road3);
            } else if (your_current_time < (redDuration + amberDuration)) {
                // Amber light is active.
                // Set red and green LEDs for all roads to OFF.
                SetAmberLightsOn(Road1);
                SetAmberLightsOn(Road2);
                SetAmberLightsOn(Road3);
                SetRedLightsOff(Road1);
                SetRedLightsOff(Road2);
                SetRedLightsOff(Road3);
                SetGreenLightsOff(Road1);
                SetGreenLightsOff(Road2);
                SetGreenLightsOff(Road3);
            } else {
                // Green light is active.
                // Set red and amber LEDs for all roads to OFF.

                SetGreenLightsOn(Road1);
                SetGreenLightsOn(Road2);
                SetGreenLightsOn(Road3);
                SetRedLightsOff(Road1);
                SetRedLightsOff(Road2);
                SetRedLightsOff(Road3);
                SetAmberLightsOff(Road1);
                SetAmberLightsOff(Road2);
                SetAmberLightsOff(Road3);
            }

            break;

        case MODE_MODIFY_RED:
            if (is_button_pressed(0)) {
                redDuration++;  // Increase the red LED duration
                if (redDuration > 99) {
                    redDuration = 1;  // Wrap around if it exceeds 99
                }
            } else if (is_button_pressed_1s(0)) {
                // Set the red LED duration and return to normal mode
                // You should implement the logic to set the duration here
                // For example, update your timer settings.
                currentMode = MODE_NORMAL;
            }
            break;

        case MODE_MODIFY_AMBER:
            // Similar logic for amber LED modification
            break;

        case MODE_MODIFY_GREEN:
            // Similar logic for green LED modification
            break;
    }
}
