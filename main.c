#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"
#include "button.h"
#include "adc.h"

volatile int adcValue = 0; 

ISR(ADC_vect){
    // read 8 highest out of 10 bits from ADC data register
    adcValue = ADCH;
}

ISR(TIMER2_COMPA_vect) {
    // single conversion
    ADCSRA |= (1 << ADSC);

    // set red PWM value to potentiometer reading
    OCR0A = adcValue;
}

void main (void) {

	LED_init();
	//uart_init();
	timer_init();
    //button_init();
    adc_init();
    sei(); // enable interrupts


	while (1) {

	}

}



