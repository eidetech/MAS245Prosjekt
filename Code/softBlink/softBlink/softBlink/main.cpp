/*
 * softBlink.cpp
 *
 * Created: 14/10/2021 13:23:19
 * Author : marcu
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN      6U
#define DELAY_MAX    5120
#define DELAY_MIN    100

int main(void)
{
    /* set LED pin as OUTPUT */
    DDRD |= (1 << LED_PIN);
    int step = -1;
    uint16_t delay = DELAY_MIN;
	
    while (1) 
    {
		/* changing duty cycle */
		if (delay <= DELAY_MIN || delay>=DELAY_MAX) {
			step  = -step;
		}
		delay += step;
		
		/* LED off */
		PORTD &= ~(1<<LED_PIN);
		_delay_loop_2(delay);
		
		/* LED on */
		PORTD |= (1<<LED_PIN);
		_delay_loop_2(DELAY_MAX - delay);
    }
}

