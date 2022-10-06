/*
 * ADC_p.c
 *
 * Created: 10/6/2020 4:32:33 AM
 *  Author: Wagdy
 */ 

#include "types.h"
#include "ADC_Compiler_.h"
#include "ADC_Config.h"
#include "ADC_interface.h"
#include "util.h"

const static u8 ADC_channel_select[ADC_u8CHANNELSNUMBER][CHANNEL_SELECTION_BITS] =
 { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 1 }, { 0, 0, 0, 1, 0 }, { 0, 0, 0, 1,
				1 }, { 0, 0, 1, 0, 0 }, { 0, 0, 1, 0, 1 }, { 0, 0, 1, 1, 0 }, {
				0, 0, 1, 1, 1 } };
				
const static u8 ADC_Ref_selectin[REFERENCE_SELECTION_OPTIONS][REFERENCE_SELECTION_BITS]=
{ { 0, 0 },
		{ 0, 1 }, 
		{ 1, 1 } };
			
const static u8 ADC_prescaler_selection[ADC_PRESCALER_OPTIONS][ADC_PRESCALER_BITS]=
{ { 0, 0, 0 }, { 0, 0, 1 }, { 0, 1, 0 }, { 0, 1, 1 }, { 1, 0, 0 }, { 1,
				0, 1 }, { 1, 1, 0 }, { 1, 1, 1 } };
					
extern void ADCEnable(){
	SET_BIT(*ADCSRA,7);
	//*ADCSRA|=(1<<7);
	return;
}

extern void ADCDisAble()
{
	CLR_BIT(*ADCSRA,7);
	return;
}

extern void ADC_Config()
{
	s8 Counter ;
	//Channel select
	for (Counter = CHANNEL_SELECTION_BITS-1;Counter>=0;Counter--)
	{
		ASSIGN_BIT(*ADMUX,Counter,ADC_channel_select[ADC_CHANNEL][4-Counter]);
	}
	
	//adjstment
	ASSIGN_BIT(*ADMUX,5,ADC_RESULT);
	
	//PreScaler Selector
	for (Counter=ADC_PRESCALER_BITS-1;Counter>=0;Counter--)
	{
		ASSIGN_BIT(*ADCSRA,Counter,ADC_prescaler_selection[ADC_PRESCALER][2-Counter]);
	}
	
	//ADC INT Enable
	ASSIGN_BIT(*ADCSRA,ADIE,ADC_INTERRUPT_ED);
	
	//ADC_AUTO TRIGGER
	ASSIGN_BIT(*ADCSRA,ADATE,ADC_AUTOTRIGGER_ED);
	
	return;
	
}

extern void ADC_ReadOneTime(u16 *PtrToVal)
{
	//step 1 : Start Conversion
	SET_BIT(*ADCSRA,ADSC);
	//step 2 : Wait for comersion to complete 
	while(GET_BIT(*ADCSRA,ADIF)==0);
	//Step 3 : Read Result From ADC register
	*PtrToVal = *ADC;
	//step 4 : Clear Flag
	SET_BIT(*ADCSRA,ADIF);
	
	return;
}

