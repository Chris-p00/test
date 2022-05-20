/*
 * epwm.h
 *
 *  Created on: 2020. 8. 26.
 *      Author: GP01
 */

#ifndef HEADER_EPWM_H_
#define HEADER_EPWM_H_



// ePWM1/2/3/4 Interrupt Service Function ¼±¾ð
//#pragma CODE_SECTION(epwm1_timer_isr, ".TI.ramfunc");
//#pragma CODE_SECTION(epwm2_timer_isr, ".TI.ramfunc");
//#pragma CODE_SECTION(epwm3_timer_isr, ".TI.ramfunc");
//#pragma CODE_SECTION(epwm4_timer_isr, ".TI.ramfunc");
//#pragma CODE_SECTION(epwm5_timer_isr, ".TI.ramfunc");
//#pragma CODE_SECTION(epwm6_timer_isr, ".TI.ramfunc");
//#pragma CODE_SECTION(epwm7_timer_isr, ".TI.ramfunc");
//#pragma CODE_SECTION(epwm8_timer_isr, ".TI.ramfunc");
//#pragma CODE_SECTION(epwm9_timer_isr, ".TI.ramfunc");
//#pragma CODE_SECTION(epwm10_timer_isr, ".TI.ramfunc");
//#pragma CODE_SECTION(epwm11_timer_isr, ".TI.ramfunc");
//#pragma CODE_SECTION(epwm12_timer_isr, ".TI.ramfunc");
//
//#pragma CODE_SECTION(epwm1_tz1_isr, ".TI.ramfunc");
//#pragma CODE_SECTION(epwm2_tz1_isr, ".TI.ramfunc");
//#pragma CODE_SECTION(epwm3_tz1_isr, ".TI.ramfunc");
//#pragma CODE_SECTION(epwm4_tz2_isr, ".TI.ramfunc");
//#pragma CODE_SECTION(epwm5_tz2_isr, ".TI.ramfunc");
//#pragma CODE_SECTION(epwm6_tz2_isr, ".TI.ramfunc");
//#pragma CODE_SECTION(epwm7_tz3_isr, ".TI.ramfunc");
//#pragma CODE_SECTION(epwm8_tz3_isr, ".TI.ramfunc");
//#pragma CODE_SECTION(epwm9_tz3_isr, ".TI.ramfunc");
//#pragma CODE_SECTION(epwm10_tz4_isr, ".TI.ramfunc");
//#pragma CODE_SECTION(epwm11_tz4_isr, ".TI.ramfunc");
//#pragma CODE_SECTION(epwm12_tz4_isr, ".TI.ramfunc");

#define EPWM_TIMER_TBPRD 2500

//#define DEADTIME_GAP 20
//#define DEADTIME_GAP 30
//#define DEADTIME_GAP 60
//#define DEADTIME_GAP 100
//#define DEADTIME_GAP 120
#define DEADTIME_GAP 150
//#define DEADTIME_GAP 300

//#define DEADTIME_GAP_inv 30
//#define DEADTIME_GAP_inv 80
#define DEADTIME_GAP_inv 100


#define ERR_1    (GpioDataRegs.GPCDAT.bit.GPIO94)
#define ERR_2    (GpioDataRegs.GPCDAT.bit.GPIO95)
#define ERR_3    (GpioDataRegs.GPDDAT.bit.GPIO96)
#define ERR_4    (GpioDataRegs.GPDDAT.bit.GPIO97)
#define ERR_5    (GpioDataRegs.GPDDAT.bit.GPIO98)
#define ERR_6    (GpioDataRegs.GPDDAT.bit.GPIO99)

#define ERR_7    (GpioDataRegs.GPDDAT.bit.GPIO112)
#define ERR_8    (GpioDataRegs.GPDDAT.bit.GPIO113)
#define ERR_9    (GpioDataRegs.GPDDAT.bit.GPIO114)
#define ERR_10   (GpioDataRegs.GPDDAT.bit.GPIO115)
#define ERR_11   (GpioDataRegs.GPDDAT.bit.GPIO116)
#define ERR_12   (GpioDataRegs.GPDDAT.bit.GPIO117)

void Init_Epwm(void);
void Init_ePwm1(void);
void Init_ePwm2(void);
void Init_ePwm3(void);
void Init_ePwm4(void);
void Init_ePwm5(void);
void Init_ePwm6(void);
void Init_ePwm7(void);
void Init_ePwm8(void);
void Init_ePwm9(void);
void Init_ePwm10(void);
void Init_ePwm11(void);
void Init_ePwm12(void);

interrupt void epwm1_timer_isr(void);
interrupt void epwm2_timer_isr(void);
interrupt void epwm3_timer_isr(void);
interrupt void epwm4_timer_isr(void);
interrupt void epwm5_timer_isr(void);
interrupt void epwm6_timer_isr(void);
interrupt void epwm7_timer_isr(void);
interrupt void epwm8_timer_isr(void);
interrupt void epwm9_timer_isr(void);
interrupt void epwm10_timer_isr(void);
interrupt void epwm11_timer_isr(void);
interrupt void epwm12_timer_isr(void);

interrupt void epwm1_tz1_isr(void);
interrupt void epwm2_tz1_isr(void);
interrupt void epwm3_tz1_isr(void);
interrupt void epwm4_tz2_isr(void);
interrupt void epwm5_tz2_isr(void);
interrupt void epwm6_tz2_isr(void);
interrupt void epwm7_tz3_isr(void);
interrupt void epwm8_tz3_isr(void);
interrupt void epwm9_tz3_isr(void);
interrupt void epwm10_tz4_isr(void);
interrupt void epwm11_tz4_isr(void);
interrupt void epwm12_tz4_isr(void);

#endif /* HEADER_EPWM_H_ */
