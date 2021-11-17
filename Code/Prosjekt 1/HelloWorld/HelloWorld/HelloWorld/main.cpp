/*
 * HelloWorld.cpp
 *
 * Created: 07/10/2021 16:54:04
 * Author : Marcus Eide
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL // Set clock frequency to 8MHz
#include <util/delay.h>


int main(void)
{
    DDRD = (1U << 6U); // Data port direction register, set pin 6 of DDRD to output.
	PORTD &= ~(1U << 6U); // Setting pin 6 of PORT D register to LOW.
    while (1) 
    {
		_delay_ms(1000);
		PORTD &= ~(1U << 6U); // Turn LED off
		
		_delay_ms(1000);
		PORTD |= (1U << 6U);  // Turn LED on
    }
}

