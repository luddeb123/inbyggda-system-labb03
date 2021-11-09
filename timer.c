#include <avr/io.h>

#include "timer.h"

uint16_t OCRvalue(uint16_t prescaler, uint8_t milliseconds){
    uint16_t freq_scaled = F_CPU/prescaler; // 15625
    uint16_t seconds = milliseconds/1000;   // 0,010
    uint16_t ticks = freq_scaled*seconds;   // 156
    ticks = ticks - 1;                      // Correct since starting at 0

    return ticks;
}

void timer_init() {
    // timer0 
    // CTC-mod
    TCCR0A &= ~(1 << WGM00);
    TCCR0A |= (1 << WGM01);
    TCCR0A &= ~(1 << WGM02);
    

    // sets prescaler to 1024 
    TCCR0B |= (1 << CS00);
    TCCR0B &= ~(1 << CS01);
    TCCR0B |= (1 << CS02);

    // Frequency
    OCR0A = OCRvalue(1024, 10);

    TIMSK0 |= (1 << OCIE0A); 
}

