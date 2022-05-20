//###############################################################################################################
// 파일명      : offset.c
// 회사명      : G-Philos
// 작성날짜  : 2009.12.02
// 작성자      : S.H.Moon
// 수정날짜  : 2021.01.04
// 수정자      : Lee Sang Cheol
// 설명         : initial process
//###############################################################################################################

#include "Define.h"


void rout_offset()
{
/*--------------------------------------*/
/*  A/D reading [Digital]               */
/*--------------------------------------*/
    Get_Adc();

/*--------------------------------------*/
/*  A/D reading [Analog]                */
/*--------------------------------------*/
    Get_Adc_Sensor_AC();

/*--------------------------------------*/
/*  A/D Filter [Analog]                 */
/*--------------------------------------*/
//    Get_Adc_Filter_AC();
    Get_Adc_Filter();


/*--------------------------------------*/
/*  A/D AC offset [Analog]              */
/*--------------------------------------*/
    AC_offset();

/*--------------------------------------*/
/*  Grid PLL [Analog]                   */
/*--------------------------------------*/
//    if(time_check_cnt == 2)   LED1_ON;
    if(Flag_Va_PLL3 == 1)
    {
        Va_PLL3_harmonic(); // power run err, review need
        //66.6us x 15.8% = 10.52us
    }
    else
    {
        Va_PLL3();
        //66.6us x 8.2% = 5.46us
    }
//    if(time_check_cnt == 2)   LED1_OFF;

/*--------------------------------------*/
/*  fault_HW_check                      */
/*--------------------------------------*/
    fault_HW_check();   // H/W fault reading

/*-----------------------------------------*/
/*  system normal/fault check & data save  */
/*-----------------------------------------*/
#if 1
    if(System_fault == NORMAL)
    {
        if((Fault_SW != 0) || (Fault_HW != 0))
        {
            if(Fault_SW != 0)
            {
                Fault_SW_latch |= Fault_SW;
                System_fault_latch |= 0x10;
            }
            if(Fault_HW != 0)
            {
                System_fault_latch |= 0x20;
            }
            System_fault_latch |= 0x04;
            inv_fault();    // Fault.c
            if(control_power_check_flag == 1)   inv_fault();    // Fault.c
            else                                Fault_reset = 1;
        }
        //66.6us x 0.27% = 0.18us
    }
#endif

/*----------------------------------------------*/
/*  system fault reset process & data initial   */
/*----------------------------------------------*/
    if((System_fault == FAULT) && (Fault_reset == 1))
    {
        system_restart();
    }

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

    if(time_check_cnt == 1)   LED1_OFF;
}


void AC_offset()
{
    float   a   = 0.;

    if(Flag_offset == 0)
    {
        Esa_offset_sum  += Esa;
        Esb_offset_sum  += Esb;
        Esc_offset_sum  += Esc;

        Ia_offset_sum   += Ia;
        Ib_offset_sum   += Ib;
        Ic_offset_sum   += Ic;

        Offset_cnt++;

        if(Offset_cnt == 10000)
        {

            Esa_offset_sum  = 0.;
            Esb_offset_sum  = 0.;
            Esc_offset_sum  = 0.;

            Ia_offset_sum   = 0.;
            Ib_offset_sum   = 0.;
            Ic_offset_sum   = 0.;
        }

        else if(Offset_cnt >= 20000)
        {
            a   = 1./(float)(Offset_cnt-10000);

            Cnt_offset_wait = Set_offset_wait;    // 1[sec] waiting

            Esa_offset  =   Esa_offset_sum  * a;
            Esb_offset  =   Esb_offset_sum  * a;
            Esc_offset  =   Esc_offset_sum  * a;
            Ia_offset   =   Ia_offset_sum   * a;
            Ib_offset   =   Ib_offset_sum   * a;
            Ic_offset   =   Ic_offset_sum   * a;

            Esa_offset_sum  = 0.;
            Esb_offset_sum  = 0.;
            Esc_offset_sum  = 0.;

            Ia_offset_sum   = 0.;
            Ib_offset_sum   = 0.;
            Ic_offset_sum   = 0.;

            Offset_cnt      = 0;
            Flag_offset     = 1;

#if 0
            a   = TOL_offset * 0.01;                  // [%] of max. scale

            if( fabs(Ia_offset) > fabs(Scale_Ia_input   * a) )  Fault_SW    |= SFT_offs_Ia;
            if( fabs(Ib_offset) > fabs(Scale_Ib_input   * a) )  Fault_SW    |= SFT_offs_Ib;
            if( fabs(Ic_offset) > fabs(Scale_Ic_input   * a) )  Fault_SW    |= SFT_offs_Ic;
#endif
        }

    }
    else if(Flag_offset == 1)
    {
        if(System_fault == NORMAL)
//      if((System_fault == NORMAL) && (Conector_1_2_3_input == 0))
        {
            Flag_offset = 2;
        }
    }
    else if(Flag_offset == 2)
    {
        --Cnt_offset_wait;  // wait for 2.5sec, after DC-voltage charged

// TZ err -> system restart setting
        Fault_check_cnt = 0;

// sci init -> sci 5s communication init setting
//      Init_Scia();
//      Init_Scib();
    }
}
