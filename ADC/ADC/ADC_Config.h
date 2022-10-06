/*
* ADC_Config.h
*
* Created: 10/6/2020 4:32:33 AM
*  Author: Wagdy
*/


/*
 ADMUX: 
(Reference Selection bits) 
REFS1-> 0, REFSO -> 0 (AREF) 
REFS1-> 0, REFSO -> 1 (AVCC) 
REFS1-> 1, REFSO -> 0 (----) 
REFS1-> 1, REFSO -> 1 (2.56V) 
.............................................
(Left Adjust) 
ADALR -> 0 (Right Adj) 
ADALR -> 1 (Left Adj) 
.................................................
(MUX4:0) 
MUX3:0 select single ended channel 

 ............................................
 ADCSRA: 
ADEN -> 1 (Enable ADC)
ADSC -> 1 (Start Conversion) 
ADATE ->0 Free Running Mode ADIF (Interrupt Flag) set when conversion is complete 
ADIE (Interrupt Enable) 
ADPS2:0 ( Prescaler Selection) Freq/128 (111) 

 */


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_


#define ADC_REFERENCE AVCC

#define ADC_RESULT	LEFT_ADJSUTED

#define ADC_CHANNEL ADC0

#define ADC_CHANNELMODE SINGLE_ENDED_INPUT

#define ADC_PRESCALER         ADC_PRESCAL16

#define ADC_INTERRUPT_ED         DISABLE

#define ADC_AUTOTRIGGER_ED   	   DISABLE


#endif /* ADC_CONFIG_H_ */