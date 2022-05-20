#ifndef ADC_H_
#define ADC_H_

#include "F28x_Project.h"
#include "Define.h"
#include "time.h"
#include "ipc.h"
#include "index.h"

#pragma CODE_SECTION(adcb1_isr, ".TI.ramfunc");

//ADC (16bit ADC)
#define DRV2_ADC_ADCIN_0_1 (0x00)
#define DRV2_ADC_ADCIN_2_3 (0x02)
#define DRV2_ADC_ADCIN_4_5 (0x04)
#define DRV2_ADC_ADCIN_6_7 (0x06)
#define DRV2_ADC_ADCIN_8_9 (0x08)
#define DRV2_ADC_ADCIN_10_11 (0x0A)
#define DRV2_ADC_ADCIN_12_13 (0x0C)
#define DRV2_ADC_ADCIN_14_15 (0x0F)



//ADC (12bit ADC)
#define DRV2_ADC_ADCIN_0 (0x00)
#define DRV2_ADC_ADCIN_1 (0x01)
#define DRV2_ADC_ADCIN_2 (0x02)
#define DRV2_ADC_ADCIN_3 (0x03)
#define DRV2_ADC_ADCIN_4 (0x04)
#define DRV2_ADC_ADCIN_5 (0x05)
#define DRV2_ADC_ADCIN_6 (0x06)
#define DRV2_ADC_ADCIN_7 (0x07)
#define DRV2_ADC_ADCIN_8 (0x08)
#define DRV2_ADC_ADCIN_9 (0x09)
#define DRV2_ADC_ADCIN_10 (0x0A)
#define DRV2_ADC_ADCIN_11 (0x0B)
#define DRV2_ADC_ADCIN_12 (0x0C)
#define DRV2_ADC_ADCIN_13 (0x0D)
#define DRV2_ADC_ADCIN_14 (0x0E)
#define DRV2_ADC_ADCIN_15 (0x0F)



#define DRV2_ADC_PRESCALE_50MHZ (6)
#define DRV2_ADC_PRESCALE_25MHZ (14)

#define DRV2_ADC_CALL_INT_EOC0 (0)
#define DRV2_ADC_CALL_INT_EOC1 (1)
#define DRV2_ADC_CALL_INT_EOC2 (2)
#define DRV2_ADC_CALL_INT_EOC3 (3)
#define DRV2_ADC_CALL_INT_EOC4 (4)
#define DRV2_ADC_CALL_INT_EOC5 (5)
#define DRV2_ADC_CALL_INT_EOC6 (6)
#define DRV2_ADC_CALL_INT_EOC7 (7)
#define DRV2_ADC_CALL_INT_EOC8 (8)
#define DRV2_ADC_CALL_INT_EOC9 (9)
#define DRV2_ADC_CALL_INT_EOC10 (10)
#define DRV2_ADC_CALL_INT_EOC11 (11)
#define DRV2_ADC_CALL_INT_EOC12 (12)
#define DRV2_ADC_CALL_INT_EOC13 (13)
#define DRV2_ADC_CALL_INT_EOC14 (14)
#define DRV2_ADC_CALL_INT_EOC15 (15)

#define DRV2_ADC_INTEN (1)
#define DRV2_ADC_INTDIS (0)

#define DRV2_ADC_PWR_UP (1)
#define DRV2_ADC_PWR_DOWN (0)

#define DRV2_ADC_AFTER_CONV_CALL_INT (1)
#define DRV2_ADC_BEFORE_CONV_CALL_INT (0)

#define DRV2_ADC_CLEAR_INTFLG_N (0)
#define DRV2_ADC_CLEAR_INTFLG_Y (1)
//
//definitions for specifying an ADC
//
#define ADC_ADCA 0
#define ADC_ADCB 1
#define ADC_ADCC 2
#define ADC_ADCD 3

//
//definitions for selecting ADC resolution
//

#define ADC_RESOLUTION_12BIT 0
#define ADC_RESOLUTION_16BIT 1

//
//definitions for selecting ADC signal mode
//(single-ended mode is only a valid mode for 12-bit resolution)
//
#define ADC_SIGNALMODE_SINGLE 0
#define ADC_SIGNALMODE_DIFFERENTIAL 1

#define DRV2_ADC_SW_ONLY (0x00)
#define DRV2_ADC_CPU1_TIMER0 (0x01)
#define DRV2_ADC_CPU1_TIMER1 (0x02)
#define DRV2_ADC_CPU1_TIMER2 (0x03)
#define DRV2_ADC_GPIO_ADCEXTSOC (0x04)
#define DRV2_ADC_EPWM1_ADCSOCA (0x05)
#define DRV2_ADC_EPWM1_ADCSOCB (0x06)
#define DRV2_ADC_EPWM2_ADCSOCA (0x07)
#define DRV2_ADC_EPWM2_ADCSOCB (0x08)
#define DRV2_ADC_EPWM3_ADCSOCA (0x09)
#define DRV2_ADC_EPWM3_ADCSOCB (0x0A)
#define DRV2_ADC_EPWM4_ADCSOCA (0x0B)
#define DRV2_ADC_EPWM4_ADCSOCB (0x0C)
#define DRV2_ADC_EPWM5_ADCSOCA (0x0D)
#define DRV2_ADC_EPWM5_ADCSOCB (0x0E)
#define DRV2_ADC_EPWM6_ADCSOCA (0x0F)
#define DRV2_ADC_EPWM6_ADCSOCB (0x10)
#define DRV2_ADC_EPWM7_ADCSOCA (0x11)
#define DRV2_ADC_EPWM7_ADCSOCB (0x12)
#define DRV2_ADC_EPWM8_ADCSOCA (0x13)
#define DRV2_ADC_EPWM8_ADCSOCB (0x14)
#define DRV2_ADC_EPWM9_ADCSOCA (0x15)
#define DRV2_ADC_EPWM9_ADCSOCB (0x16)
#define DRV2_ADC_EPWM10_ADCSOCA (0x17)
#define DRV2_ADC_EPWM10_ADCSOCB (0x18)
#define DRV2_ADC_EPWM11_ADCSOCA (0x19)
#define DRV2_ADC_EPWM11_ADCSOCB (0x1A)
#define DRV2_ADC_EPWM12_ADCSOCA (0x1B)
#define DRV2_ADC_EPWM12_ADCSOCB (0x1C)
#define DRV2_ADC_CPU2_TIMER0 (0x1D)
#define DRV2_ADC_CPU2_TIMER1 (0x1E)
#define DRV2_ADC_CPU2_TIMER2 (0x1F)

#if 0
#define DRV2_ADC_ACQPS_16BIT (63)
#define DRV2_ADC_ACQPS_12BIT (63)
#endif

#if 1
#define DRV2_ADC_ACQPS_16BIT (127)
#define DRV2_ADC_ACQPS_12BIT (127)
#endif

//Max 511   -> time 1 add 5ns
//Min 0     -> time 1 add 5ns
// (63)15 x 5 [ns] = 0.075 [us]
// (63)64 x 5 [ns] = 0.315 [us]
// (63)127 x 5 [ns] = 0.630 [us]

#define ADC_RESULTS_BUFFER_SIZE (10)
#define ADC_RESULTS_CHANNEL_SIZE (16)


#define SET_12BIT     0
#define SET_16BIT     1



void Init_Adc(char module_a_status, char module_b_status, char module_c_status, char module_d_status);

interrupt void adcb1_isr(void);

void Get_Adc();
void Get_Adc_Sensor_AC();
void Get_Adc_Sensor();
void Get_Adc_Filter_AC();
void Get_Adc_Filter();
void Power_cal();
void Init_scale_offset();
void EEPROM_list_init();

#endif /* SOURCE_ADC_H_ */
