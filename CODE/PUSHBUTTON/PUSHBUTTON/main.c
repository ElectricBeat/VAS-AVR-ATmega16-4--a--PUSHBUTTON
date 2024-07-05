/*
 * PUSHBUTTON.c
 *
 * Created: 04-07-2024 12:55:04
 * Author : SRIDHAR
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB	=	DDRB | (1<<6);
	DDRB	=	DDRB | (1<<7);

	DDRB	=	DDRB & (~(1<<0));
	DDRB	=	DDRB & (~(1<<1));

	PORTB	=	PORTB | (1<<0);
	PORTB	=	PORTB | (1<<1);

	int pin_status1;
	int pin_status2;

    while (1) 
    {
		pin_status1	=	PINB & (1<<0);
		pin_status2	=	PINB & (1<<1);

		if (pin_status1)
		{
			PORTB	=	PORTB | (1<<6);
		}
		else
		{
			PORTB	=	PORTB & (~(1<<6));
		}

		if (pin_status2)
		{
			PORTB	=	PORTB | (1<<7);
		}
		else
		{
			PORTB	=	PORTB & (~(1<<7));
		}
    }
}