#include <avr/io.h> // https://www.nongnu.org/avr-libc/user-manual/group__avr__io.html
#define F_CPU 1000000UL // Set CPU speed of 1 MHz
#include <util/delay_basic.h> // https://www.nongnu.org/avr-libc/user-manual/group__util__delay__basic.html

// Datasheet: Microchip ATmega48/V/88/V/168/V - DS40002074A


	



/* Function for setting duty cycle on OCR0A pin (PD6)
   How to calculate PWM percentage (not 0-255 value):
   x = 100/255 = 0.392157
   y = 0-255 value
   dutyCycle% = x*y
*/
int main()
{
		DDRD = (1U << 4U);
		DDRD &= ~(1U << 4U); // Set PD4 pin as input
		
		
		DDRD = (1U << 6U);
		PORTD &= ~(1U << 6U);
	
	while(1)
	{
		if (PIND & (1<<4))
		PORTD |= (1U << 6U);
		else
		PORTD &= ~(1U << 6U);
	}
	}
