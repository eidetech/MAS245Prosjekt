#include <avr/io.h> // https://www.nongnu.org/avr-libc/user-manual/group__avr__io.html
#define F_CPU 1000000UL // Set CPU speed of 1 MHz
#include <util/delay_basic.h> // https://www.nongnu.org/avr-libc/user-manual/group__util__delay__basic.html

// Datasheet: Microchip ATmega48/V/88/V/168/V - DS40002074A

// Function to configure PWM output on OC0A (pin PD6/12) in TCCR0A and TCCR0B registers
void setupPWM()
{
	/*
	Register operations:
	TCCR0A: Table 15-3: Compare output mode, fast PWM mode: COM0A1 = 1 -> Clear OC0A on compare match, set OC0A at BOTTOM, (non-inverting mode)
	TCCR0A: Table 15-8: Waveform generation mode bit description: WGM00 = 1 -> Fast PWM
	TCCR0A: Table 15-8: Waveform generation mode bit description: WGM01 = 1 -> Fast PWM
	
	TCCR0B: Table 15-9: Clock source select bit description: CS00 = 1 -> clk I/O / (no prescaling)
	
	Data direction register operations:
	DDRD - The port D data direction register: DDD6 = 1 (DDRD |= (1U << 6U);) -> Set direction of PD6 to output.
	*/
	
	TCCR0A |= (1U << COM0A1) | (1U << WGM01) | (1U << WGM00); // Configure all bits for TCCR0A
	TCCR0B |= (1U << CS00); // Configure all bits for TCCR0B
	
	DDRD |= (1U << 6U); // Set PD6 pin as output
}

/* Function for setting duty cycle on OCR0A pin (PD6)
   How to calculate PWM percentage (not 0-255 value):
   x = 100/255 = 0.392157
   y = 0-255 value
   dutyCycle% = x*y
*/
void outputPWM(uint8_t dutyCycle)
{
	OCR0A = dutyCycle;
}
int main()
{
	setupPWM();
	while(1)
	{
		// Increase brightness of LED
		for(int i = 0;i <= 255;i++)
		{
			outputPWM(i);
			_delay_loop_2(500);
		}
		
		// Decrease brightness of LED
		for(int i = 255; i >= 0; i--)
		{
			outputPWM(i);
			_delay_loop_2(500);
		}
	}
}