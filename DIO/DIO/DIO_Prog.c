/*
 * DIO_Prog.c
 *
 * Created: 10/7/2022 4:10:40 AM
 *  Author: W&N
 */ 

#include "types.h"
#include "util.h"
#include "DIO_Interface.h"
#include "DIO_Compiler.h"
#include "DIO_Config.h"


static volatile u8* const DIO_u8RWDirArr[DIO_u8PORTNUMBERS] = { DDRA, DDRB,
DDRC, DDRD };
static volatile u8* const DIO_u8ReadPortArr[DIO_u8PORTNUMBERS] = { PINA, PINB,
PINC, PIND };
static volatile u8* const DIO_u8WritePortArr[DIO_u8PORTNUMBERS] = { PORTA,
PORTB, PORTC, PORTD };

void DIO_voidInit(void) {
	*DDRA |= DIO_u8PORTA_DIR;
	*DDRB |= DIO_u8PORTB_DIR;
	*DDRC |= DIO_u8PORTC_DIR;
	*DDRD |= DIO_u8PORTD_DIR;

	*PORTA = (*PORTA & ~DIO_u8PORTA_DIR) | (DIO_u8PORTA_DIR & DIO_u8PORTA_VAL);
	*PORTB = (*PORTB & ~DIO_u8PORTB_DIR) | (DIO_u8PORTB_DIR & DIO_u8PORTB_VAL);
	*PORTC = (*PORTC & ~DIO_u8PORTC_DIR) | (DIO_u8PORTC_DIR & DIO_u8PORTC_VAL);
	*PORTD = (*PORTD & ~DIO_u8PORTD_DIR) | (DIO_u8PORTD_DIR & DIO_u8PORTD_VAL);

	return;
}


					//   		2		, 00000001 << 0
u8 DIO_u8WritePortVal(u8 Copy_u8PortIdx, u8 Copy_u8PortVal) {

	u8 Local_u8ReturnFlag = OK;
	if (Copy_u8PortIdx > DIO_u8PORTNUMBERS - 1 || Copy_u8PortIdx < 0) {
		Local_u8ReturnFlag = ERROR;
	} else {
		// PORTB=
		*DIO_u8WritePortArr[Copy_u8PortIdx] = Copy_u8PortVal;
		Local_u8ReturnFlag = OK;
	}
	return Local_u8ReturnFlag;
}
