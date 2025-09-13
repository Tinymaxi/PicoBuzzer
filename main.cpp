#include "pico/stdlib.h"
#include "Buzzer.hpp"

int main() {
    stdio_init_all();

    constexpr uint BUZZER_PIN = 2;
    constexpr uint BUTTON_PIN = 15; // adjust if needed
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN); // active-low button to GND

    Buzzer bz(BUZZER_PIN);

    bz.beep(); // startup chirp

    absolute_time_t press_start = 0;
    bool was_pressed = false;

    while (true) {
        bool pressed = (gpio_get(BUTTON_PIN) == 0); // active-low
        if (pressed && !was_pressed) {
            press_start = get_absolute_time();
            bz.beep(50, 0.7f); // immediate feedback
        }
        if (!pressed && was_pressed) {
            int64_t held_ms = absolute_time_diff_us(press_start, get_absolute_time()) / 1000;
            if (held_ms > 1000) {
                // long press: play Ode to Joy
                bz.playMelody(Buzzer::melodyOdeToJoy(120), 10, 0.7f);
            }
        }
        was_pressed = pressed;
        sleep_ms(5);
    }
}