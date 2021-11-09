#include <avr/io.h>
#include "led.h"

void LED_init() {
	DDRD |= (1 << PD6); // Pin 9 och 6 är kopplade med en kabel på skölden.
}

uint8_t simple_ramp() {
	// ...
}
