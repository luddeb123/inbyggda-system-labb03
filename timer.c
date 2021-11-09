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
    // fast pwm
    TCCR0A |= (1 << WGM01);
    TCCR0A |= (1 << WGM00);

    // prescaler = 64
    TCCR0B |= (1 << CS00);
    TCCR0B |= (1 << CS01);

    // non-inverting mode, clear OC2A on compare match and set OC2A at bottom
    TCCR0A |= (1 << COM0A1);


    // timer2
    // CTC mode
    TCCR2A |= (1 << WGM21);

    TCNT2 = 0;

    // prescaler = 1024
    TCCR2B |= (1 << CS22);
    TCCR2B |= (1 << CS21);
    TCCR2B |= (1 << CS20);

    OCR2A = OCRvalue(1024, 10);

    TIMSK2 |= (1 << OCIE2A); 
}

