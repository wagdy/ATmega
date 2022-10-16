/*
 * ADC_interface.h
 *
 * Created: 10/6/2020 4:32:33 AM
 *  Author: Wagdy
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

extern void ADCEnable();
extern void	ADCDisAble();
extern void ADC_Config();
extern void ADC_ReadOneTime(u16 *Copy_ptrToVal);
extern void	ADC_voidReadMulShot(u16 *Copy_ptrToVal);





#endif /* ADC_INTERFACE_H_ */