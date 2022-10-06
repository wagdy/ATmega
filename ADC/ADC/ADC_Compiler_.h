/*
 * ADC_Compiler_.h
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

#ifndef ADC_COMPILER__H_
#define ADC_COMPILER__H_

#define ADEN  7
#define ADSC  6
#define ADATE 5
#define ADIF  4
#define ADIE  3
#define ADPS2 2
#define ADPS1 1
#define ADPS0 0



#define ADMUX  ((volatile u8 *)0x27)
#define ADCSRA ((volatile u8 *)0x26)
#define ADCH   ((volatile u8 *)0x25)
#define ADCL   ((volatile u8 *)0x24)
#define ADC 	((volatile u16 *)0x24)
#define SFIOR   ((volatile u8 *)0x50)



#define REFERENCE_SELECTION_OPTIONS    3
#define REFERENCE_SELECTION_BITS       2

#define ADC_PRESCAL2ADC_PRESCAL2	0
#define ADC_PRESCAL2_1	1
#define ADC_PRESCAL4	2
#define ADC_PRESCAL8	3
#define ADC_PRESCAL16	4
#define ADC_PRESCAL32	5
#define ADC_PRESCAL64	6
#define ADC_PRESCAL128	7
#define ADC_PRESCALER_OPTIONS  8
#define ADC_PRESCALER_BITS     3


/*SFIOR Special FunctionIO Register */
#define ADTS2 7
#define ADTS1 6
#define ADTS0 5


/*:Number of channels */
#define ADC_u8CHANNELSNUMBER 8


/*ADC voltage references */
#define AREF      0
#define AVCC      1
#define INRERNAL  2


/*ADC result adjusting  */
#define RIGHT_ADJSUTED 0
#define LEFT_ADJSUTED  1

/*ADC Channel MUX */

/*Comment!: ADC Channel */
#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7
#define CHANNEL_SELECTION_BITS         5


/* ADC Channel Mode */
#define SINGLE_ENDED_INPUT 0
#define DIFFERENTIAL_INPUT 1


#define ENABLE  1
#define DISABLE 0






#endif /* ADC_COMPILER__H_ */