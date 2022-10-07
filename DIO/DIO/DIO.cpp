/*
 * DIO.cpp
 *
 * Created: 10/7/2022 3:33:09 AM
 *  Author: W&N
 */ 


#include <avr/io.h>

#include "types.h"
#include "util.h"
#include "DIO_Interface.h"
#include "DIO_Compiler.h"
#include "DIO_Config.h"
#include "DELAY.h"


void delay100ms(void){ 	// try different numbers on your
volatile unsigned int i;	// compiler and examine
for(i=0; i<42150; i++);	// result.
}


int main(void)
{
	
	u8 Local_u8Counter, Local_u8Status, Local_u8Shift = 0x01,
	Local_u8ShiftLeft = 0x00, Local_u8CounterRight;
	u8 Local_u8NameArr[NAMESIZE] = "BELAL";

	DIO_voidInit();
	
    while(1)
    {
        
        for (Local_u8Counter = 0; Local_u8Counter < 7; Local_u8Counter++) {
	        //   2	, 00000001 << 1
	        DIO_u8WritePortVal(LEDS, 0x01 << Local_u8Counter);
	        delay_ms(100);

        }
        for (Local_u8Counter = 0; Local_u8Counter < 7; Local_u8Counter++) {
	        DIO_u8WritePortVal(LEDS, 0x80 >> Local_u8Counter);
	        delay_ms(100);
        }
        for (Local_u8Counter = 0; Local_u8Counter < 3; Local_u8Counter++) {
	        DIO_u8WritePortVal(LEDS, 0xFF);//1111 1111
	        delay_ms(100);
	        DIO_u8WritePortVal(LEDS, 0x00);
	        delay_ms(100);
        }
        for (Local_u8Counter = 0; Local_u8Counter < 3; Local_u8Counter++) {
	        DIO_u8WritePortVal(LEDS, 0xAA);//1010 1010
	        delay_ms(100);
	        DIO_u8WritePortVal(LEDS, 0x55);
	        delay_ms(100);
        }
        for (Local_u8Counter = 0; Local_u8Counter < 3; Local_u8Counter++) {
	        DIO_u8WritePortVal(LEDS, 0x33);//00110011
	        delay_ms(100);
	        DIO_u8WritePortVal(LEDS, 0xCC);
	        delay_ms(100);
        }
        for (Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++) {
	        Local_u8Shift |= 1 << Local_u8Counter; // odd
	        DIO_u8WritePortVal(LEDS, Local_u8Shift);
	        delay_ms(100);

        }
    }
}

