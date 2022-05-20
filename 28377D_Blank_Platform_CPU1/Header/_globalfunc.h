/*
 * Globalfunc.h
 *
 *  Created on: 2020. 12. 17.
 *      Author: KYJ-PC
 */

#ifndef GLOBALFUNC_H_
#define GLOBALFUNC_H_

/*--------------------------------------*/
/*  initial-routine functions           */
/*--------------------------------------*/
extern void serial_code_init();

extern void init_code_rw1();
extern void init_code_rw2();
extern void init_code_r11();
extern void init_code_r12();
extern void init_code_r21();
extern void init_code_r22();

extern void Read_EEPROM_code();

/*--------------------------------------*/
/*  period3(250us)-routine functions    */
/*--------------------------------------*/

/*--------------------------------------*/
/*  period4(500us)-routine functions    */
/*--------------------------------------*/

/*--------------------------------------*/
/*  period5(1ms)-routine functions      */
/*--------------------------------------*/

/*--------------------------------------*/
/*  period6(2ms)-routine functions      */
/*--------------------------------------*/
extern void making_Vdc_ref();
extern void soft_Idc_ref();
extern void voltage_control_con();
extern void voltage_control_inv3();
extern void making_current_ref();
extern void making_current_ref_harmonic();
extern void soft_Ip_ref_real_max();

/*--------------------------------------*/
/*  period7(10ms)-routine functions     */
/*--------------------------------------*/
extern void digital_input();
extern void digital_output();
extern void command_process();
extern void Write_EEPROM_code();
extern void Freq_low_high();
extern void Freq_low_high_test();

/*--------------------------------------*/
/*  period8(100ms)-routine functions    */
/*--------------------------------------*/
extern void rms_avg();
extern void process_user_input();

#endif /* GLOBALFUNC_H_ */
