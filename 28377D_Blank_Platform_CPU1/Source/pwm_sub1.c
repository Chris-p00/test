//###############################################################################################################
// 파일명      : pwm_sub1.c
// 회사명      : G-Philos
// 작성날짜  : 2009.12.02
// 작성자      : S.H.Moon
// 수정날짜  : 2021.01.04
// 수정자      : Lee Sang Cheol
// 설명         : subroutines of pwm_ctrl.c
//###############################################################################################################

#include "Define.h"



void pwm_test_con1_one()
{
//    if((Fault_HW == 0) && (Fault_SW == 0) && (Flag_pwm_inv_test1 == 1))
    if((System_fault == NORMAL) && (Flag_pwm_con_test1 == 1))
//    if(Flag_pwm_con_test1 == 1)
    {
        if(Ta_con_test1 >= CNT_max_con_98)  Ta_con_test1 = CNT_max_con_98;
        if(Tb_con_test1 >= CNT_max_con_98)  Tb_con_test1 = CNT_max_con_98;
        if(Tc_con_test1 >= CNT_max_con_98)  Tc_con_test1 = CNT_max_con_98;

        if(Ta_con_test1 <= T_dead_con_CNT)  Ta_con_test1 = T_dead_con_CNT + 10;
        if(Tb_con_test1 <= T_dead_con_CNT)  Tb_con_test1 = T_dead_con_CNT + 10;
        if(Tc_con_test1 <= T_dead_con_CNT)  Tc_con_test1 = T_dead_con_CNT + 10;

#if 1
//      1P Test
        EPwm1Regs.CMPA.bit.CMPA = Ta_con_test1 & 0xfff;
        EPwm1Regs.CMPB.bit.CMPB = Ta_con_test1 & 0xfff; // Set Compare B value
        EPwm2Regs.CMPA.bit.CMPA = Tb_con_test1 & 0xfff;
        EPwm2Regs.CMPB.bit.CMPB = Tb_con_test1 & 0xfff; // Set Compare B value
        EPwm3Regs.CMPA.bit.CMPA = Tc_con_test1 & 0xfff;
        EPwm3Regs.CMPB.bit.CMPB = Tc_con_test1 & 0xfff; // Set Compare B value

        if(Flag_pwm_1P == 1)    EPwm1Regs.AQCSFRC.bit.CSFA = 0x03;      // has no effect. Continuous Software Force on output A
        else                    EPwm1Regs.AQCSFRC.bit.CSFA = 0x01;      // has no effect. Continuous Software Force on output A

        if(Flag_pwm_2P == 1)    EPwm2Regs.AQCSFRC.bit.CSFA = 0x03;      // has no effect. Continuous Software Force on output A
        else                    EPwm2Regs.AQCSFRC.bit.CSFA = 0x01;      // has no effect. Continuous Software Force on output A

        if(Flag_pwm_3P == 1)    EPwm3Regs.AQCSFRC.bit.CSFA = 0x03;      // has no effect. Continuous Software Force on output A
        else                    EPwm3Regs.AQCSFRC.bit.CSFA = 0x01;      // has no effect. Continuous Software Force on output A

#endif

#if 0
//      1N Test
        EPwm1Regs.CMPA.bit.CMPA = (CNT_max_con - Ta_con_test1) & 0xfff;
        EPwm1Regs.CMPB.bit.CMPB = (CNT_max_con - Ta_con_test1) & 0xfff; // Set Compare B value
        EPwm2Regs.CMPA.bit.CMPA = (CNT_max_con - Tb_con_test1) & 0xfff;
        EPwm2Regs.CMPB.bit.CMPB = (CNT_max_con - Tb_con_test1) & 0xfff; // Set Compare B value
        EPwm3Regs.CMPA.bit.CMPA = (CNT_max_con - Tc_con_test1) & 0xfff;
        EPwm3Regs.CMPB.bit.CMPB = (CNT_max_con - Tc_con_test1) & 0xfff; // Set Compare B value

        if(Flag_pwm_1N == 1)    EPwm1Regs.AQCSFRC.bit.CSFB = 0x03;      // has no effect. Continuous Software Force on output A
        else                    EPwm1Regs.AQCSFRC.bit.CSFB = 0x02;      // has no effect. Continuous Software Force on output A

        if(Flag_pwm_2N == 1)    EPwm2Regs.AQCSFRC.bit.CSFB = 0x03;      // has no effect. Continuous Software Force on output A
        else                    EPwm2Regs.AQCSFRC.bit.CSFB = 0x02;      // has no effect. Continuous Software Force on output A

        if(Flag_pwm_3N == 1)    EPwm3Regs.AQCSFRC.bit.CSFB = 0x03;      // has no effect. Continuous Software Force on output A
        else                    EPwm3Regs.AQCSFRC.bit.CSFB = 0x02;      // has no effect. Continuous Software Force on output A

#endif

        Flag_gating_test_cnt++;

        if(Flag_gating_test_cnt >= Flag_gating_test_cnt_max)
        {
            Flag_gating_test_cnt = 0;
            Flag_gating_test = 0;
        }

    }
    else
    {
        EPwm1Regs.AQCSFRC.bit.CSFA = 0x01;      // Continuous Software Force on output A
        EPwm1Regs.AQCSFRC.bit.CSFB = 0x02;      // Continuous Software Force on output B
        EPwm2Regs.AQCSFRC.bit.CSFA = 0x01;      // Continuous Software Force on output A
        EPwm2Regs.AQCSFRC.bit.CSFB = 0x02;      // Continuous Software Force on output B
        EPwm3Regs.AQCSFRC.bit.CSFA = 0x01;      // Continuous Software Force on output A
        EPwm3Regs.AQCSFRC.bit.CSFB = 0x02;      // Continuous Software Force on output B

        EPwm1Regs.CMPA.bit.CMPA = 0;
        EPwm1Regs.CMPB.bit.CMPB = 0;    // Set Compare B value
        EPwm2Regs.CMPA.bit.CMPA = 0;
        EPwm2Regs.CMPB.bit.CMPB = 0;    // Set Compare B value
        EPwm3Regs.CMPA.bit.CMPA = 0;
        EPwm3Regs.CMPB.bit.CMPB = 0;    // Set Compare B value

        Flag_gating_test_cnt = 0;
    }
}


void pwm_test_con1()
{
// check #1 : redefine need
// lsc_step 1 PWM output basic test
// PWM Pulse check, freq, duty, deadtime, err stop, tz stop
// 1.   빌드 및 예뮬레이터 연결 후 다운로딩
// 2.   Mode_system_input       = 0         -> 1
// 3.   Mode_test               = 0         -> no action
// 4.   Flag_pwm_con_test1      = 0         -> 1

// 5.   EPwm1_CMP_test          = 0         -> 4 (review setting)
// 6.   1P                      = on        -> off    [duty : 50% +/- setting : EPwm1_CMP_test]
// 7.   1N                      = on        -> off    [duty : 50% +/- setting : EPwm1_CMP_test]

// 8.   EPwm2_CMP_test          = 0         -> 8 (review setting)
// 9.   2P                      = on        -> off    [duty : 50% +/- setting : EPwm1_CMP_test]
// 10.  2N                      = on        -> off    [duty : 50% +/- setting : EPwm1_CMP_test]

// 11.  EPwm2_CMP_test          = 0         -> 12 (review setting)
// 12.  3P                      = on        -> off    [duty : 50% +/- setting : EPwm1_CMP_test]
// 13.  3N                      = on        -> off    [duty : 50% +/- setting : EPwm1_CMP_test]

// 14.  T_dead_con_CNT          = ? (data review check)
// 15.  1P, 1N                  = deadtime check1
// 16.  2P, 2N                  = deadtime check2
// 17.  3P, 3N                  = deadtime check3

// 18.  Ta_con_test1            = 200       -> 300 (review setting)
// 19.  1P, 2P  = phase setting review check1
// 20.  1N, 2N  = phase setting review check2

// 21.  1P, 2N  = full-bridge power on/off check1
// 22.  2P, 1N  = full-bridge power on/off check2


//  if((Fault_HW == 0) && (Fault_SW == 0) && (Flag_pwm_con_test1 == 1))
    if((System_fault == NORMAL) && (Flag_pwm_con_test1 == 1))
    {
#if 0
        EPwm1Regs.CMPA.bit.CMPA = (CNT_max_con_50 - EPwm1_CMP_test);     // Set compare A value
        EPwm1Regs.CMPB.bit.CMPB = (CNT_max_con_50 - EPwm1_CMP_test);     // Set Compare B value

        EPwm2Regs.CMPA.bit.CMPA = (CNT_max_con_50 - EPwm2_CMP_test);     // Set compare A value
        EPwm2Regs.CMPB.bit.CMPB = (CNT_max_con_50 - EPwm2_CMP_test);     // Set Compare B value

        EPwm3Regs.CMPA.bit.CMPA = (CNT_max_con_50 - EPwm3_CMP_test);     // Set compare A value
        EPwm3Regs.CMPB.bit.CMPB = (CNT_max_con_50 - EPwm3_CMP_test);     // Set Compare B value
#endif

        EPwm1Regs.AQCSFRC.bit.CSFA = 0x03;      // has no effect. Continuous Software Force on output A
        EPwm1Regs.AQCSFRC.bit.CSFB = 0x03;      // has no effect. Continuous Software Force on output B
        EPwm2Regs.AQCSFRC.bit.CSFA = 0x03;      // has no effect. Continuous Software Force on output A
        EPwm2Regs.AQCSFRC.bit.CSFB = 0x03;      // has no effect. Continuous Software Force on output B
        EPwm3Regs.AQCSFRC.bit.CSFA = 0x03;      // has no effect. Continuous Software Force on output A
        EPwm3Regs.AQCSFRC.bit.CSFB = 0x03;      // has no effect. Continuous Software Force on output B

        EALLOW;
        EPwm2Regs.TBPHS.bit.TBPHS = Ta_con_test1;         // Phase is 0
        EPwm3Regs.TBPHS.bit.TBPHS = Tb_con_test1;         // Phase is 0
        EDIS;
    }
    else
    {
        EPwm1Regs.AQCSFRC.bit.CSFA = 0x01;      // Continuous Software Force on output A
        EPwm1Regs.AQCSFRC.bit.CSFB = 0x02;      // Continuous Software Force on output B
        EPwm2Regs.AQCSFRC.bit.CSFA = 0x01;      // Continuous Software Force on output A
        EPwm2Regs.AQCSFRC.bit.CSFB = 0x02;      // Continuous Software Force on output B
        EPwm3Regs.AQCSFRC.bit.CSFA = 0x01;      // Continuous Software Force on output A
        EPwm3Regs.AQCSFRC.bit.CSFB = 0x02;      // Continuous Software Force on output B

        EALLOW;
        EPwm2Regs.TBPHS.bit.TBPHS = 0;         // Phase is 0
        EPwm3Regs.TBPHS.bit.TBPHS = 0;         // Phase is 0
        EDIS;

#if 0
        EPwm1Regs.CMPA.bit.CMPA = (CNT_max_con_50 - EPwm1_CMP_test);     // Set compare A value
        EPwm1Regs.CMPB.bit.CMPB = (CNT_max_con_50 - EPwm1_CMP_test);     // Set Compare B value

        EPwm2Regs.CMPA.bit.CMPA = (CNT_max_con_50 - EPwm2_CMP_test);     // Set compare A value
        EPwm2Regs.CMPB.bit.CMPB = (CNT_max_con_50 - EPwm2_CMP_test);     // Set Compare B value

        EPwm3Regs.CMPA.bit.CMPA = (CNT_max_con_50 - EPwm3_CMP_test);     // Set compare A value
        EPwm3Regs.CMPB.bit.CMPB = (CNT_max_con_50 - EPwm3_CMP_test);     // Set Compare B value
#endif

//      EPwm1_CMP_test = 0;
//      EPwm2_CMP_test = 0;

    }
}


void pwm_test_inv1()
{
//    if((Fault_HW == 0) && (Fault_SW == 0) && (Flag_pwm_inv_test1 == 1))
    if((System_fault == NORMAL) && (Flag_pwm_inv_test1 == 1))
    {
        EPwm1Regs.CMPA.bit.CMPA = Ta_inv_test1 & 0xfff;
        EPwm1Regs.CMPB.bit.CMPB = Ta_inv_test1 & 0xfff; // Set Compare B value
        EPwm2Regs.CMPA.bit.CMPA = Tb_inv_test1 & 0xfff;
        EPwm2Regs.CMPB.bit.CMPB = Tb_inv_test1 & 0xfff; // Set Compare B value
        EPwm3Regs.CMPA.bit.CMPA = Tc_inv_test1 & 0xfff;
        EPwm3Regs.CMPB.bit.CMPB = Tc_inv_test1 & 0xfff; // Set Compare B value

        EPwm1Regs.AQCSFRC.bit.CSFA = 0x03;      // has no effect. Continuous Software Force on output A
        EPwm1Regs.AQCSFRC.bit.CSFB = 0x03;      // has no effect. Continuous Software Force on output B
        EPwm2Regs.AQCSFRC.bit.CSFA = 0x03;      // has no effect. Continuous Software Force on output A
        EPwm2Regs.AQCSFRC.bit.CSFB = 0x03;      // has no effect. Continuous Software Force on output B
        EPwm3Regs.AQCSFRC.bit.CSFA = 0x03;      // has no effect. Continuous Software Force on output A
        EPwm3Regs.AQCSFRC.bit.CSFB = 0x03;      // has no effect. Continuous Software Force on output B
    }
    else
    {
        EPwm1Regs.AQCSFRC.bit.CSFA = 0x01;      // Continuous Software Force on output A
        EPwm1Regs.AQCSFRC.bit.CSFB = 0x02;      // Continuous Software Force on output B
        EPwm2Regs.AQCSFRC.bit.CSFA = 0x01;      // Continuous Software Force on output A
        EPwm2Regs.AQCSFRC.bit.CSFB = 0x02;      // Continuous Software Force on output B
        EPwm3Regs.AQCSFRC.bit.CSFA = 0x01;      // Continuous Software Force on output A
        EPwm3Regs.AQCSFRC.bit.CSFB = 0x02;      // Continuous Software Force on output B

        EPwm1Regs.CMPA.bit.CMPA = 0;
        EPwm1Regs.CMPB.bit.CMPB = 0;    // Set Compare B value
        EPwm2Regs.CMPA.bit.CMPA = 0;
        EPwm2Regs.CMPB.bit.CMPB = 0;    // Set Compare B value
        EPwm3Regs.CMPA.bit.CMPA = 0;
        EPwm3Regs.CMPB.bit.CMPB = 0;    // Set Compare B value
    }
}


void pwm_test_inv2()
{
// check #1 : redefine need
// lsc_step 1 PWM output basic test
// PWM Pulse check, freq, duty, deadtime, err stop, tz stop
// 1.   빌드 및 예뮬레이터 연결 후 다운로딩
// 2.   Mode_system_input       = 0         -> 1
// 3.   Mode_test               = 0         -> no action
// 4.   Flag_pwm_inv_test2      = 0         -> 1
// 5.   Ta_inv_test2            = 0         -> 1
// 6.   Tb_inv_test2            = 0         -> 1
// 7.   Tc_inv_test2            = 0         -> 1


//  if((Fault_HW == 0) && (Fault_SW == 0) && (Flag_pwm_inv_test2 == 1))
    if((System_fault == NORMAL) && (Flag_pwm_inv_test2 == 1))
    {
        EPwm4Regs.CMPA.bit.CMPA = Ta_inv_test2 & 0xfff;
        EPwm4Regs.CMPB.bit.CMPB = Ta_inv_test2 & 0xfff; // Set Compare B value
        EPwm5Regs.CMPA.bit.CMPA = Tb_inv_test2 & 0xfff;
        EPwm5Regs.CMPB.bit.CMPB = Tb_inv_test2 & 0xfff; // Set Compare B value
        EPwm6Regs.CMPA.bit.CMPA = Tc_inv_test2 & 0xfff;
        EPwm6Regs.CMPB.bit.CMPB = Tc_inv_test2 & 0xfff; // Set Compare B value

        EPwm4Regs.AQCSFRC.bit.CSFA = 0x03;      // has no effect. Continuous Software Force on output A
        EPwm4Regs.AQCSFRC.bit.CSFB = 0x03;      // has no effect. Continuous Software Force on output B
        EPwm5Regs.AQCSFRC.bit.CSFA = 0x03;      // has no effect. Continuous Software Force on output A
        EPwm5Regs.AQCSFRC.bit.CSFB = 0x03;      // has no effect. Continuous Software Force on output B
        EPwm6Regs.AQCSFRC.bit.CSFA = 0x03;      // has no effect. Continuous Software Force on output A
        EPwm6Regs.AQCSFRC.bit.CSFB = 0x03;      // has no effect. Continuous Software Force on output B
    }
    else
    {
        EPwm4Regs.AQCSFRC.bit.CSFA = 0x01;      // Continuous Software Force on output A
        EPwm4Regs.AQCSFRC.bit.CSFB = 0x02;      // Continuous Software Force on output B
        EPwm5Regs.AQCSFRC.bit.CSFA = 0x01;      // Continuous Software Force on output A
        EPwm5Regs.AQCSFRC.bit.CSFB = 0x02;      // Continuous Software Force on output B
        EPwm6Regs.AQCSFRC.bit.CSFA = 0x01;      // Continuous Software Force on output A
        EPwm6Regs.AQCSFRC.bit.CSFB = 0x02;      // Continuous Software Force on output B

        EPwm4Regs.CMPA.bit.CMPA = 0;
        EPwm4Regs.CMPB.bit.CMPB = 0;    // Set Compare B value
        EPwm5Regs.CMPA.bit.CMPA = 0;
        EPwm5Regs.CMPB.bit.CMPB = 0;    // Set Compare B value
        EPwm6Regs.CMPA.bit.CMPA = 0;
        EPwm6Regs.CMPB.bit.CMPB = 0;    // Set Compare B value
    }
}

void pwm_test_inv3()
{
//    if((Fault_HW == 0) && (Fault_SW == 0) && (Flag_pwm_inv_test3 == 1))
    if((System_fault == NORMAL) && (Flag_pwm_inv_test3 == 1))
    {
        EPwm7Regs.CMPA.bit.CMPA = Ta_inv_test3 & 0xfff;
        EPwm7Regs.CMPB.bit.CMPB = Ta_inv_test3 & 0xfff; // Set Compare B value
        EPwm8Regs.CMPA.bit.CMPA = Tb_inv_test3 & 0xfff;
        EPwm8Regs.CMPB.bit.CMPB = Tb_inv_test3 & 0xfff; // Set Compare B value
        EPwm9Regs.CMPA.bit.CMPA = Tc_inv_test3 & 0xfff;
        EPwm9Regs.CMPB.bit.CMPB = Tc_inv_test3 & 0xfff; // Set Compare B value

        EPwm7Regs.AQCSFRC.bit.CSFA = 0x03;      // has no effect. Continuous Software Force on output A
        EPwm7Regs.AQCSFRC.bit.CSFB = 0x03;      // has no effect. Continuous Software Force on output B
        EPwm8Regs.AQCSFRC.bit.CSFA = 0x03;      // has no effect. Continuous Software Force on output A
        EPwm8Regs.AQCSFRC.bit.CSFB = 0x03;      // has no effect. Continuous Software Force on output B
        EPwm9Regs.AQCSFRC.bit.CSFA = 0x03;      // has no effect. Continuous Software Force on output A
        EPwm9Regs.AQCSFRC.bit.CSFB = 0x03;      // has no effect. Continuous Software Force on output B
    }
    else
    {
        EPwm7Regs.AQCSFRC.bit.CSFA = 0x01;      // Continuous Software Force on output A
        EPwm7Regs.AQCSFRC.bit.CSFB = 0x02;      // Continuous Software Force on output B
        EPwm8Regs.AQCSFRC.bit.CSFA = 0x01;      // Continuous Software Force on output A
        EPwm8Regs.AQCSFRC.bit.CSFB = 0x02;      // Continuous Software Force on output B
        EPwm9Regs.AQCSFRC.bit.CSFA = 0x01;      // Continuous Software Force on output A
        EPwm9Regs.AQCSFRC.bit.CSFB = 0x02;      // Continuous Software Force on output B

        EPwm7Regs.CMPA.bit.CMPA = 0;
        EPwm7Regs.CMPB.bit.CMPB = 0;    // Set Compare B value
        EPwm8Regs.CMPA.bit.CMPA = 0;
        EPwm8Regs.CMPB.bit.CMPB = 0;    // Set Compare B value
        EPwm9Regs.CMPA.bit.CMPA = 0;
        EPwm9Regs.CMPB.bit.CMPB = 0;    // Set Compare B value
    }
}


void pwm_test_inv4()
{
//    if((Fault_HW == 0) && (Fault_SW == 0) && (Flag_pwm_inv_test4 == 1))
    if((System_fault == NORMAL) && (Flag_pwm_inv_test4 == 1))
    {
        EPwm10Regs.CMPA.bit.CMPA = Ta_inv_test4 & 0xfff;
        EPwm10Regs.CMPB.bit.CMPB = Ta_inv_test4 & 0xfff; // Set Compare B value
        EPwm11Regs.CMPA.bit.CMPA = Tb_inv_test4 & 0xfff;
        EPwm11Regs.CMPB.bit.CMPB = Tb_inv_test4 & 0xfff; // Set Compare B value
        EPwm12Regs.CMPA.bit.CMPA = Tc_inv_test4 & 0xfff;
        EPwm12Regs.CMPB.bit.CMPB = Tc_inv_test4 & 0xfff; // Set Compare B value

        EPwm10Regs.AQCSFRC.bit.CSFA = 0x03;      // has no effect. Continuous Software Force on output A
        EPwm10Regs.AQCSFRC.bit.CSFB = 0x03;      // has no effect. Continuous Software Force on output B
        EPwm11Regs.AQCSFRC.bit.CSFA = 0x03;      // has no effect. Continuous Software Force on output A
        EPwm11Regs.AQCSFRC.bit.CSFB = 0x03;      // has no effect. Continuous Software Force on output B
        EPwm12Regs.AQCSFRC.bit.CSFA = 0x03;      // has no effect. Continuous Software Force on output A
        EPwm12Regs.AQCSFRC.bit.CSFB = 0x03;      // has no effect. Continuous Software Force on output B
    }
    else
    {
        EPwm10Regs.AQCSFRC.bit.CSFA = 0x01;      // Continuous Software Force on output A
        EPwm10Regs.AQCSFRC.bit.CSFB = 0x02;      // Continuous Software Force on output B
        EPwm11Regs.AQCSFRC.bit.CSFA = 0x01;      // Continuous Software Force on output A
        EPwm11Regs.AQCSFRC.bit.CSFB = 0x02;      // Continuous Software Force on output B
        EPwm12Regs.AQCSFRC.bit.CSFA = 0x01;      // Continuous Software Force on output A
        EPwm12Regs.AQCSFRC.bit.CSFB = 0x02;      // Continuous Software Force on output B

        EPwm10Regs.CMPA.bit.CMPA = 0;
        EPwm10Regs.CMPB.bit.CMPB = 0;    // Set Compare B value
        EPwm11Regs.CMPA.bit.CMPA = 0;
        EPwm11Regs.CMPB.bit.CMPB = 0;    // Set Compare B value
        EPwm12Regs.CMPA.bit.CMPA = 0;
        EPwm12Regs.CMPB.bit.CMPB = 0;    // Set Compare B value
    }
}



void pwm_load_con()
{

    if((System_fault == NORMAL) && (Flag_gating == 1))
    {
        EALLOW;
        EPwm2Regs.TBPHS.bit.TBPHS = Ta_con;     // Phase is 0
        EDIS;

        EPwm1Regs.AQCSFRC.bit.CSFA = 0x03;      // has no effect. Continuous Software Force on output A
        EPwm1Regs.AQCSFRC.bit.CSFB = 0x03;      // has no effect. Continuous Software Force on output B
        EPwm2Regs.AQCSFRC.bit.CSFA = 0x03;      // has no effect. Continuous Software Force on output A
        EPwm2Regs.AQCSFRC.bit.CSFB = 0x03;      // has no effect. Continuous Software Force on output B

    }
    else
    {
        EPwm1Regs.AQCSFRC.bit.CSFA = 0x01;      // Continuous Software Force on output A
        EPwm1Regs.AQCSFRC.bit.CSFB = 0x02;      // Continuous Software Force on output B
        EPwm2Regs.AQCSFRC.bit.CSFA = 0x01;      // Continuous Software Force on output A
        EPwm2Regs.AQCSFRC.bit.CSFB = 0x02;      // Continuous Software Force on output B

        EALLOW;
        EPwm2Regs.TBPHS.bit.TBPHS = 0;     // Phase is 0
        EDIS;

        Vdc_con_out     = 0.;
        Vdc_con_pro     = 0.;
        Vdc_con_integ   = 0.;       //PI 제어기
        Vdc_con_real    = 0.;

        Idc_ref         = 0.;
        Err_Idc         = 0.;
        Err_Vdc_con     = 0.;

        Idc_out         = 0.;
        Idc_pro         = 0.;
        Idc_integ       = 0.;

        Ta_con          = 0;
        Ta_real_con     = 0;

        Flag_buildup    = 1;
        Vdc_con_real_max    = 0;
    }
}

void pwm_load_inv3()
{
//  if( (System_fault == NORMAL) && ((Flag_gating_inv == 1) || (Flag_gating_VF_TEST == 1)) )
//  if( (System_fault == NORMAL) && ((Flag_gating_inv == 1) || (Flag_gating_VF == 1)) )
    if( (System_fault == NORMAL) && (((Flag_gating_inv == 1) && (flag_voltage_control_inv3 == 1)) || (Flag_gating_VF == 1)) )
    {

        EPwm4Regs.CMPA.bit.CMPA = Ta_inv & 0xfff;
        EPwm4Regs.CMPB.bit.CMPB = Ta_inv & 0xfff; // Set Compare B value
        EPwm5Regs.CMPA.bit.CMPA = Tb_inv & 0xfff;
        EPwm5Regs.CMPB.bit.CMPB = Tb_inv & 0xfff; // Set Compare B value
        EPwm6Regs.CMPA.bit.CMPA = Tc_inv & 0xfff;
        EPwm6Regs.CMPB.bit.CMPB = Tc_inv & 0xfff; // Set Compare B value

        EPwm4Regs.AQCSFRC.bit.CSFA = 0x03;      // has no effect. Continuous Software Force on output A
        EPwm4Regs.AQCSFRC.bit.CSFB = 0x03;      // has no effect. Continuous Software Force on output B
        EPwm5Regs.AQCSFRC.bit.CSFA = 0x03;      // has no effect. Continuous Software Force on output A
        EPwm5Regs.AQCSFRC.bit.CSFB = 0x03;      // has no effect. Continuous Software Force on output B
        EPwm6Regs.AQCSFRC.bit.CSFA = 0x03;      // has no effect. Continuous Software Force on output A
        EPwm6Regs.AQCSFRC.bit.CSFB = 0x03;      // has no effect. Continuous Software Force on output B
    }

    else
    {
        EPwm4Regs.AQCSFRC.bit.CSFA = 0x01;      // Continuous Software Force on output A
        EPwm4Regs.AQCSFRC.bit.CSFB = 0x02;      // Continuous Software Force on output B
        EPwm5Regs.AQCSFRC.bit.CSFA = 0x01;      // Continuous Software Force on output A
        EPwm5Regs.AQCSFRC.bit.CSFB = 0x02;      // Continuous Software Force on output B
        EPwm6Regs.AQCSFRC.bit.CSFA = 0x01;      // Continuous Software Force on output A
        EPwm6Regs.AQCSFRC.bit.CSFB = 0x02;      // Continuous Software Force on output B

        EPwm4Regs.CMPA.bit.CMPA = 0;
        EPwm4Regs.CMPB.bit.CMPB = 0;            // Set Compare B value
        EPwm5Regs.CMPA.bit.CMPA = 0;
        EPwm5Regs.CMPB.bit.CMPB = 0;            // Set Compare B value
        EPwm6Regs.CMPA.bit.CMPA = 0;
        EPwm6Regs.CMPB.bit.CMPB = 0;            // Set Compare B value

        Err_Vdc_inv     = 0.;
        Vdc_inv_integ   = 0.;
        Vdc_inv_out     = 0.;
        Vdc_inv_real    = 0.;
        Vdc_inv_integ   = 0.;

        Ta_inv          = 0;
        Tb_inv          = 0;
        Tc_inv          = 0;

        Ta_real_inv     = 0;
        Tb_real_inv     = 0;
        Tc_real_inv     = 0;

//        Flag_gating_inv = 0;

        VF_vtg          = 0.;
        VF_freq         = 0.;
        theta_VF        = 0.;
        Va_ref          = 0.;
        Vb_ref          = 0.;
        Vc_ref          = 0.;
        Ip_ref_out      = 0.;

        pVfe1[DX][CREF] = 0.;
        pVfe1[DX][CINT] = 0.;
        pVfe1[DX][CACT] = 0.;
        pVfe1[DX][CFB]  = 0.;
        pVfe1[DX][CFF]  = 0.;                   // F/F

        pVfe1[QX][CREF] = 0.;
        pVfe1[QX][CINT] = 0.;
        pVfe1[QX][CACT] = 0.;
        pVfe1[QX][CFB]  = 0.;
        pVfe1[QX][CFF]  = 0.;

        Vf_mag2         = 0.;

        Vde_ref         = 0.;
        Vqe_ref         = 0.;

        Err_Ide         = 0.;
        Err_Iqe         = 0.;

        Ip_ref_real     = 0.;

//      Ip_ref_integ    = 0.;                   //PI 제어기
        Ip_ref_integ    = Kp_VC  * Vdc_flt;     //IP 제어기

//      flag_voltage_control_inv3 = 0;


        Ide_cff_p = 0;
        Iqe_cff_p = 0;

        Ide_cff_n = 0;
        Iqe_cff_n = 0;

        //Ide_ref, Ide_ref_p 다름
        Ide_err_p = 0;
        Ide_ref_integ_p = 0;
        Ide_out_p = 0;
        Ide_ref_p = 0;
        Ide_ref_out_p = 0;

        //Iqe_ref, Iqe_ref_p 다름
        Iqe_err_p = 0;
        Iqe_ref_integ_p = 0;
        Iqe_out_p = 0;
        Iqe_ref_p = 0;
        Iqe_ref_out_p = 0;

        Ide_err_n = 0;
        Ide_ref_integ_n = 0;
        Ide_out_n = 0;
        Ide_ref_p_n = 0;
        Ide_ref_out_n = 0;

        Iqe_err_n = 0;
        Iqe_ref_integ_n = 0;
        Iqe_out_n = 0;
        Iqe_ref_p_n = 0;
        Iqe_ref_out_n = 0;

        Vcon_alpha_p =  0;
        Vcon_beta_p =   0;

        Vcon_alpha_n =  0;
        Vcon_beta_n =   0;

        Vas_ref_p = 0;
        Vbs_ref_p = 0;
        Vcs_ref_p = 0;

        Vas_ref_n = 0;
        Vbs_ref_n = 0;
        Vcs_ref_n = 0;


        Err_Vdc_inv=Vdc_inv_integ=Vdc_inv_out=Vdc_inv_real=Vdc_inv_integ=0.;
        Ia_ref=Ip_ref=Err_Ia=Ia_integ=Ia_out=Ia_real=Va_ref=Vb_ref=Vc_ref=0.;
//        Ta_inv=Tb_inv=Tc_inv=Ta_real_inv=Tb_real_inv=Flag_gating_inv=Flag_gating_inv_VF=0;
        Ta_inv=Tb_inv=Tc_inv=Ta_real_inv=Tb_real_inv=0;
        VF_vtg=Ip_ref_out=0.;

        pVfe1[DX][CREF]=pVfe1[QX][CREF]=pVfe1[DX][CINT]=pVfe1[QX][CINT]=0.;
        pVfe1[DX][CACT]=pVfe1[QX][CACT]=0.;
        Vf_mag2=0.;
        Vde_ref=Vqe_ref=0.;
        Err_Ide=Err_Iqe=0.;
//        Ip_ref_integ= Ip_ref_real =0.;
        Ip_ref_real =0.;
//      Ip_ref_integ    = 0.;                   //PI 제어기
        Ip_ref_integ    = Kp_VC  * Vdc_flt;     //IP 제어기

        Ide_err_p= Ide_ref_integ_p= Ide_out_p = Ide_ref_p = Ide_cff_p = Ide_ref_out_p=0.;
        Iqe_err_p= Iqe_ref_integ_p=Iqe_out_p = Iqe_ref_p = Iqe_cff_p = Iqe_ref_out_p=0.;
        Ide_err_n= Ide_ref_integ_n=Ide_out_n=Ide_ref_n=Ide_ref_p_n=Ide_cff_n=Ide_ref_out_n=0.;
        Iqe_err_n=Iqe_ref_integ_n=Iqe_out_n=Iqe_ref_n=Iqe_ref_p_n=Iqe_cff_n=Iqe_ref_out_n=0.;
        Vcon_alpha_p=Vcon_beta_p=Vcon_alpha_n=Vcon_beta_n=0.;
        Vas_ref_p=Vbs_ref_p=Vcs_ref_p=0.;
        Vas_ref_n=Vbs_ref_n=Vcs_ref_n=0.;
        Van_ref=Vbn_ref=Vcn_ref=0.;

        Vas_ref_SV= 0;
        Vbs_ref_SV= 0;
        Vcs_ref_SV= 0;

        ///////////////////////////////////////////////////////////////////////////////////////////////
        //100kW T-npc DC Link balance controll code 추가 부분///
        Vmax_SV = 0;
        Vmin_SV = 0;

        // Vmax -> Vmax_SV
        // Vmin -> Vmin_SV
        // Vsn -> Vsn_SV
        Vsn_SV = 0;

        Van_ref = 0;
        Vbn_ref = 0;
        Vcn_ref = 0;

        Kp_Vde_ff_flt = 0;
        Kp_Vqe_ff_flt = 0;
        Kp_Iqe_ff_flt = 0;
        Kp_Ide_ff_flt = 0;

        K_cc_DX_CKIT_Err_Ide = 0;
        K_cc_DX_CKIT_K_cc_CKA = 0;
        K_cc_QX_CKIT_Err_Iqe = 0;
        K_cc_QX_CKIT_K_cc_CKA = 0;
    }
}
