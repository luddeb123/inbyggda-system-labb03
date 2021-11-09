#include <avr/io.h>
#include "adc.h"

void adc_init(){

    DDRC &= ~(1 << PC0);

    //ADC Left Adjust Result
    ADMUX |= (1 << ADLAR);

    //AVCC with external capacitor at AREF pin
    ADMUX |= (1 << REFS0);

    //ADC Prescaler 8
    ADCSRA |= (1 << ADPS1);
    ADCSRA |= (1 << ADPS0);

    //enables the ADC
    ADCSRA |= (1 << ADEN);

    //enbles interrupt ADC
    ADCSRA |= (1 << ADIE);
}