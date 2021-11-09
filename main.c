#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"
#include "button.h"


void main (void) {

	LED_init();
	uart_init();
	timer_init();
    button_init();
    sei(); // enable interrupts


	while (1) {
        button_state();
        button_print();
	}

}



