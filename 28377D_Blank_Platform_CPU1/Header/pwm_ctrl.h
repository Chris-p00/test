/*
 * pwm_ctrl.h
 *
 *  Created on: 2021. 1. 4.
 *      Author: USER
 */

#ifndef HEADER_PWM_CTRL_H_
#define HEADER_PWM_CTRL_H_


#pragma CODE_SECTION(rout_cntl,             ".TI.ramfunc");
#pragma CODE_SECTION(Va_PLL3_harmonic,      ".TI.ramfunc");
//#pragma CODE_SECTION(Va_PLL3,               ".TI.ramfunc");
#pragma CODE_SECTION(Ia_PLL3_harmonic,      ".TI.ramfunc");
//#pragma CODE_SECTION(Ia_PLL3_harmonic_init, ".TI.ramfunc");
#pragma CODE_SECTION(Power_cal,             ".TI.ramfunc");

#pragma CODE_SECTION(Control_Run_Stop,      ".TI.ramfunc");
#pragma CODE_SECTION(current_control_con,   ".TI.ramfunc");
//#pragma CODE_SECTION(VF_test3_SVPWM,        ".TI.ramfunc");
//#pragma CODE_SECTION(current_control_inv3_harmonic, ".TI.ramfunc");
//#pragma CODE_SECTION(current_control_inv3,  ".TI.ramfunc");
//#pragma CODE_SECTION(pwm_load_con,          ".TI.ramfunc");
//#pragma CODE_SECTION(pwm_load_inv3,         ".TI.ramfunc");

void rout_cntl();

/*----------------------------------------------*/
/*  period1(Control time)-routine functions     */
/*----------------------------------------------*/
void pwm_test_con1_one();
void pwm_test_con1();

void pwm_test_inv1();
void pwm_test_inv2();
void pwm_test_inv3();
void pwm_test_inv4();

void pwm_load_con();
void pwm_load_inv3();

/*----------------------------------------------*/
/*  period2(Control time)-routine functions     */
/*----------------------------------------------*/
void Va_PLL3();
void Va_PLL3_harmonic();
void Ia_PLL3_harmonic();
void Ia_PLL3_harmonic_init();

void Control_Run_Stop();
void current_control_con();

void VF_test3();
void VF_test3_no_Vdc();
void VF_test3_SVPWM();
void current_control_inv3();
void current_control_inv3_harmonic();

void spwm();
void svpwm();


void LIMIT_i(int variable, int positive, int negative, int *limit);


#endif /* HEADER_PWM_CTRL_H_ */
