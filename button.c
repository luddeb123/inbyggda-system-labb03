#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include "button.h"

bool pushed = false;
bool released = false;
volatile bool timerInterrupted = false;
volatile bool btnInterrupted = false;

void button_init() {
    DDRB |= (1 << PB0);
    PCICR |= (1 << PCIE0); // Interrupt on change
    PCMSK0 |= (1 << PCINT0);
}
// button interrupt
ISR(PCINT0_vect) {
    btnInterrupted = true;
}

// timer0 interrupt
ISR(TIMER0_COMPA_vect) {
    timerInterrupted = true;
}

void button_state() {
    if (btnInterrupted) {
        if (PINB & (1 << PB0)) {
            pushed = true;
        }
        else if (!(PINB & (1 << PB0))) {
            released = true;
        }
        TCNT0 = 0;
        btnInterrupted = false;
    }
}

void button_print() {
    if (timerInterrupted) {
        if (pushed) {
            if (PINB & (1 << PB0)) {
                printf_P(PSTR("pushed\r\n"));
            }
            pushed = false;
        }
        else if (released) {
            if (!(PINB & (1 << PB0))) {
                printf_P(PSTR("released\r\n"));
            }
            released = false;
        }
    }
}
