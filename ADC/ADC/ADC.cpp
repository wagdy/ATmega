/*
 * ADC.cpp
 *
 * Created: 10/6/2020 4:32:33 AM
 *  Author: Wagdy
 */ 


#define F_CPU 8000000UL 
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "LCD_16x2_H_file.h"
#include "LCD_16x2_H_file.c"
#include "types.h"
#include "util.h"
#include "ADC_interface.h"
#include "DIO_interface.h"
#include "DIO_prog.c"
#include "ADC_p.c"

int main()
{
	char String[5];
	int value;
	u16 Local_u8AdcResult=0;


//	LCD_Init();			/* Initialization of LCD */
	//LCD_String("ADC value");	/* Write string on 1st line of LCD */
	DIO_voidInit();
	//DIO_u8WritePortDir(DIO_u8PORT0,DIO_u8INPUT);
	ADC_Config();
	ADCEnable();
	while(1)
	{
	
	//	LCD_Command(0xc4);	/* LCD16x2 cursor position */
		//value=ADC_Read(0);	/* Read ADC channel 0 */
		ADC_ReadOneTime(&Local_u8AdcResult);
		DIO_u8WritePortVal(1,Local_u8AdcResult);
		DIO_u8WritePortVal(3,Local_u8AdcResult>>8);
	//	itoa(Local_u8AdcResult,String,10);	/* Integer to string conversion */ 
		//LCD_String(String);						
		//LCD_String("  ");			
	}
	return 0;
}