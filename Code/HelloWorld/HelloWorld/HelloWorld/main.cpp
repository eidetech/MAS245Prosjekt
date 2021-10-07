/*
 * HelloWorld.cpp
 *
 * Created: 07/10/2021 16:54:04
 * Author : marcu
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>


int main(void)
{
    DDRD = (1U << 6U);
	PORTD &= ~(1U << 6U);
    while (1) 
    {
		_delay_ms(150);
		PORTD &= ~(1U << 6U);
		
		_delay_ms(150);
		PORTD |= (1U << 6U);
    }
}

