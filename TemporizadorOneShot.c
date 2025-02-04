#include <stdio.h>
#include "pico/stdlib.h"

#define PIN_BLUE 11
#define PIN_RED 12
#define PIN_GREEN 13
#define BUTTON 5

bool led_ativado = false;
volatile int estado = 0;

void initialze_gpio_pin() {
    gpio_init(PIN_RED);
    gpio_set_dir(PIN_RED, GPIO_OUT);

    gpio_init(PIN_GREEN);
    gpio_set_dir(PIN_GREEN, GPIO_OUT);

    gpio_init(PIN_BLUE);
    gpio_set_dir(PIN_BLUE, GPIO_OUT);

    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);
}

int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    if(estado == 1) {
        gpio_put(PIN_BLUE, false);
        estado = 2;
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    } else if(estado == 2) {
        gpio_put(PIN_RED, false);
        estado = 3;
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    } else if(estado == 3) {
        gpio_put(PIN_GREEN, false);
        estado = 0;
        led_ativado = false;
    }

    return 0;
}

int main() {
    stdio_init_all();
    initialze_gpio_pin();

    while (true) {
        if(gpio_get(BUTTON) == 0 && !led_ativado) {
            sleep_ms(50);

            if(gpio_get(BUTTON) == 0) {
                gpio_put(PIN_RED, true);
                gpio_put(PIN_GREEN, true);
                gpio_put(PIN_BLUE, true);

                led_ativado = true;
                estado = 1;
                add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            }
        }

        sleep_ms(10);
    }
}
