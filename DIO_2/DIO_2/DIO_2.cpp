/*
 * ADC_p.c
 *
 * Created: 05/6/2020 4:32:33 AM
 *  Author: Wagdy
 */ 
#include "types.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DELAY.h"
#include "DIO_config.h"
#include "util.h"
#include "DIO_prog.c"

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#define NAMESIZE 5
#define LEDS DIO_u8PIN16
#define BUTTON	DIO_u8PIN24 




#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	u8 status;
	DIO_voidInit();
	
	DIO_u8WritePinDir(LEDS,DIO_u8OUTPUT);
	DIO_u8WritePortDir(DIO_u8PORT1,DIO_u8OUTPUT);
	
	DIO_u8WritePinDir(BUTTON,DIO_u8INPUT);
	DIO_u8WritePinVal(BUTTON,1);
	u8 pin_status;
while(1)
	{
		DIO_u8ReadPinVal(BUTTON,&status);
		if(status)			/* Transmit status of pin PD2 on to pin PD3 to drive LED. */
		{
			DIO_u8WritePortVal(DIO_u8PORT1,0xAA);	
			DIO_u8WritePinVal(DIO_u8PIN1,DIO_u8HIGH);
			PORTC = PORTC | (1<<0);		
		}
		else
		{
			DIO_u8WritePortVal(DIO_u8PORT1,0x55);
			PORTC = PORTC & (~(1<<0));	
			DIO_u8WritePinVal(DIO_u8PIN1,DIO_u8LOW);
			
		}
	}
	return 0;
}

