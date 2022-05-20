//###############################################################################################################
// 파일명      : pwm_ctrl.c
// 회사명      : G-Philos
// 작성날짜  : 2009.12.02
// 작성자      : S.H.Moon
// 수정날짜  : 2021.01.04ad
// 수정자      : Lee Sang Cheolas
// 설명         : subroutines of pwm_ctrl.c
//###############################################################################################################

#include "Define.h"

void rout_cntl()
{
    if(time_check_cnt == 2)   LED1_ON;
//  if(time_check_cnt == 2)   LED1_OFF;

/*--------------------------------------*/
/*  A/D reading [Digital]               */
/*--------------------------------------*/
    Get_Adc();   //66.6us x 0.7% = 0.46us

/*--------------------------------------*/
/*  A/D reading [Analog]                */
/*--------------------------------------*/
    Get_Adc_Sensor();   //66.6us x 1.44% = 0.95us

/*--------------------------------------*/
/*  A/D Filter [Analog]                 */
/*--------------------------------------*/
    Get_Adc_Filter();   //66.6us x 6.12% = 4.07us

/*--------------------------------------*/
/*  Grid PLL [Analog]                   */
/*--------------------------------------*/
    if(Flag_Va_PLL3 == 1)
    {
        Va_PLL3_harmonic(); //66.6us x 15.8% = 10.52us
    }
    else
    {
        Va_PLL3();          //66.6us x 8.2% = 5.46us
    }

/*--------------------------------------*/
/*  Ia_PLL3_harmonic [Analog]           */
/*--------------------------------------*/
    if((Flag_gating_inv == 1) && (flag_voltage_control_inv3 == 1))
    {
        if(Flag_Ia_PLL3 == 1)
        {
            Ia_PLL3_harmonic(); // new
        }
        else
        {
            Ia_PLL3_harmonic_init(); // new
        }
    }
    else
    {
        Ia_PLL3_harmonic_init(); // new
    }


/*------------------------------------------*/
/*  Grid Power output & factor [Analog]     */
/*------------------------------------------*/
    Power_cal();    //66.6us x 0.4% = 0.26us

/*--------------------------------------*/
/*  system fault check                  */
/*--------------------------------------*/
    if(Mode_system == TEST_MODE)
    {
        fault_check_test();
    }
    else
    {
        fault_check();  //66.6us x 3.9% = 2.59us
    }


/*-----------------------------------------*/
/*  system normal/fault check & data save  */
/*-----------------------------------------*/
    if(System_fault == NORMAL)
    {
        if((Fault_SW != 0) || (Fault_HW != 0))
        {
            System_fault_latch |= 0x02;
            inv_fault();    //66.6us x 0.27% = 0.18us   // Fault.c
        }
    }

/*----------------------------------------------*/
/*  system fault reset process & data initial   */
/*----------------------------------------------*/
    if((System_fault == FAULT) && (Fault_reset == 1))
    {
        system_restart();   //66.6us x 0.18% = 0.12us
    }


/*----------------------------------------------*/
/*  Converter Control Run/Stop                  */
/*----------------------------------------------*/
    Control_Run_Stop();

/*----------------------------------------------*/
/*  Converter Control C.C                       */
/*----------------------------------------------*/
    if((Flag_gating == 1) && (Flag_charge == 1))
    {
        current_control_con();              // con current control
    }

/*--------------------------------------------------*/
/*  Inverter Control voltage reference generation   */
/*--------------------------------------------------*/
// TEST_MODE = 1
    if(Mode_system == TEST_MODE)
    {
        if(Mode_test == TEST_MODE)
        {
            if(Flag_gating_VF == 1)
            {
                VF_test3_SVPWM();
            }
        }
    }
    else
    {
        if((Flag_gating_inv == 1) && (flag_voltage_control_inv3 == 1))
        {
            if(Flag_current_control_inv3 == 1)
            {
                current_control_inv3_harmonic();
            }
            else
            {
                current_control_inv3();         // current control
            }
        }
        else
        {
            Vds_ref = Vds;
            Vqs_ref = Vqs;
        }
    }

#if 1
// TEST_MODE = 1
    if(Mode_system == TEST_MODE)
    {
        if(Mode_test == 1)
        {
            //phase pulse test
            pwm_test_con1();
            pwm_load_inv3();
        }
        else
        {
            pwm_test_con1();
//          pwm_test_inv1();
            pwm_test_inv2();
            pwm_test_inv3();
            pwm_test_inv4();
        }
    }

    else
    {
        pwm_load_con();        //66.6us x 0.94% = 0.62us
        pwm_load_inv3();       //66.6us x 3.2% = 2.21us
    }

#endif

/*----------------------------------------------*/
/*  call time fuction                           */
/*  Tsamp = (?) check need                      */
/*  250us, 500us, 1ms, 2ms, 10ms                */
/*----------------------------------------------*/
    if ((Cnt_T_250us--) == 0)
    {
        Flag_T_250us    = 1;
        Cnt_T_250us     = Set_T_250us - 1;
    }
    if ((Cnt_T_500us--) == 0)
    {
        Flag_T_500us    = 1;
        Cnt_T_500us     = Set_T_500us - 1;
    }
    if ((Cnt_T_1ms--) == 0)
    {
        Flag_T_1ms      = 1;
        Cnt_T_1ms       = Set_T_1ms - 1;
    }
    if ((Cnt_T_2ms--) == 0)
    {
        Flag_T_2ms      = 1;
        Cnt_T_2ms       = Set_T_2ms - 1;
    }
    if ((Cnt_T_10ms--) == 0)
    {
        Flag_T_10ms     = 1;
        Cnt_T_10ms      = Set_T_10ms - 1;
    }
    //66.6us x 0.68% = 0.45us
    //66.6us x 33.8% = 22.51us

//  if(time_check_cnt == 2)   LED1_ON;
    if(time_check_cnt == 2)   LED1_OFF;
}
