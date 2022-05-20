//###############################################################################################################
// 파일명      : fault.c
// 회사명      : G-Philos
// 작성날짜  : 2009.12.02
// 작성자      : K.Y.J
// 수정날짜  : 2021.01.04
// 수정자      : Lee Sang Cheol
// 설명         : fault process
//###############################################################################################################

#include "Define.h"
 

void fault_HW_check()
{
    Fault_HW |=  ( (!ERR_1)       | (!ERR_2 << 1) | (!ERR_3 << 2) | (!ERR_4  << 3)  | (!ERR_5  << 4)   | (!ERR_6  << 5)   |
                  (!ERR_7 << 6)   | (!ERR_8 << 7) | (!ERR_9 << 8) | (!ERR_10 << 9)  | (!ERR_11 << 10)  | (!ERR_12 << 11) ) ;    // ERR1~ERR12

    /* ERR mask, 2021. 9. 27, J.G.Choe */
    Fault_HW &= ~ERR_mask;
    Fault_HW_latch |= Fault_HW;

    if(Fault_HW != 0)
    {
        Fault_SW        |= SFT_gate;
        Fault_HW_new    = Fault_HW;
        Fault_HW        = Fault_HW_new | Fault_HW_old;
        Fault_HW_old    = Fault_HW;
    }
    else
    {
        Fault_HW_new    = Fault_HW;
        Fault_HW        = Fault_HW_new | Fault_HW_old;
        Fault_HW_old    = Fault_HW;
    }

    Fault_SW_latch |= Fault_SW;
}

void fault_check_test()
{

    if( Vin_flt > OV_set_Vin_test )
    {
        Fault_SW    |=SFT_OV_Vin_con;
    }

#if 0
    //test mode no define
    if((Flag_gating == 1) && (Vin_flt < UV_set_Vin_test))
    {
        Fault_SW    |=SFT_UV_Vin_con;
    }
#endif

    if(Idc_flt > OC_Idc_set_test)
    {
        Fault_SW    |=SFT_OC_Idc_con;
    }

    if( Vdc_flt > OV_set_Vdc_test )
    {
        Fault_SW    |=SFT_OV_Vdc_con;
    }

#if 0
    if(Flag_charge == 1)
    {
        if(Vqe_flt < UV_set_src_test)
        {
            Fault_SW|=SFT_UV_Src;
        }

        else if(Vqe_flt > OV_set_src_test)
        {
            Fault_SW|=SFT_OV_Src;
        }

        if(Vqe_flt < INTER_set_src_test)
        {                           // Source Interruption
            Cnt_source_check1--;

            if(Cnt_source_check1    <= 0)
            {
                Cnt_source_check1   = 400;
                Fault_SW    |= SFT_INTER_Src;
//              Fault_SW    |= SFT_FREQ_LOW;
                Freq_out    = 0;
            }
        }
        else
        {
            Cnt_source_check1   = 400;
        }
    }
#endif

    if(Ia_abs > OC_set_test)
    {
        if(++Cnt_OC_Ia >= 1)
        {
            Cnt_OC_Ia   = 0;
            Fault_SW    |= SFT_OC_Ia;                                // check over-current check
        }
    }
    else
    {
        Cnt_OC_Ia   = 0;
    }

    if(Ib_abs > OC_set_test)
    {
        if(++Cnt_OC_Ib >= 1)
        {
            Cnt_OC_Ib   = 0;
            Fault_SW    |= SFT_OC_Ib;                                // check over-current check
        }
    }
    else
    {
        Cnt_OC_Ib   = 0;
    }

    if(Ic_abs > OC_set_test)
    {
        if(++Cnt_OC_Ic >= 1)
        {
            Cnt_OC_Ic   = 0;
            Fault_SW    |= SFT_OC_Ic;                                // check over-current check
        }
    }
    else
    {
        Cnt_OC_Ic   = 0;
    }

    fault_HW_check();
}

void fault_check()
{
    if( Vin_flt > OV_set_Vin )
    {
        if(++Cnt_OV_Vin >= 2)
         {
            Fault_SW|=SFT_OV_Vin_con;
            Cnt_OV_Vin = 0;
         }
    }
    else
    {
        Cnt_OV_Vin = 0;
    }

    if((Flag_gating == 1) && (Vin_flt < UV_set_Vin))
    {
        if(++Cnt_UV_Vin >= 2)
         {
            Fault_SW|=SFT_UV_Vin_con;
            Cnt_UV_Vin = 0;
         }
    }
    else
    {
        Cnt_UV_Vin = 0;
    }


    if(Idc_flt > OC_Idc_set)
    {
        if(++Cnt_OC_Idc >= 2)
         {
            Fault_SW|=SFT_OC_Idc_con;
            Cnt_OC_Idc = 0;
         }
    }
    else
    {
        Cnt_OC_Idc = 0;
    }

    if( Vdc_flt > OV_set_Vdc )
    {
        if(++Cnt_OV_Vdc >= 2)
         {
            Fault_SW|=SFT_OV_Vdc_con;
            Cnt_OV_Vdc = 0;
         }
    }
    else
    {
        Cnt_OV_Vdc = 0;
    }

    if(Flag_Grid_err == 1)
    {
        if(Flag_charge == 1)
        {
            if(Vqe_flt < UV_set_src)
            {
                if(++Cnt_source_check2 >= 20)
                {
                    Fault_SW    |=SFT_UV_Src;
                    Cnt_source_check2   = 0;
                }
            }
            else
            {
                Cnt_source_check2   = 0;
            }

            if(Vqe_flt > OV_set_src)
            {
                if(++Cnt_source_check3 >= 20)
                {
                    Fault_SW|=SFT_OV_Src;
                    Cnt_source_check3   = 0;
                }
            }
            else
            {
                Cnt_source_check3   = 0;
            }


            if(Vqe_flt < INTER_set_src)
            {                           // Source Interruption
                Cnt_source_check1--;

                if(Cnt_source_check1    <= 0)
                {
                    Cnt_source_check1   = 400;
//                  Fault_SW    |= SFT_INTER_Src;
                    Fault_SW    |= SFT_FREQ_LOW;
                    Freq_out    = 0;
                }
            }
            else
            {
                Cnt_source_check1   = 400;
            }
        }
    }

    if(Ia_abs > OC_set)
    {
        if(++Cnt_OC_Ia >= 4)
        {
            Cnt_OC_Ia   = 0;
            Fault_SW    |= SFT_OC_Ia;                                // check over-current check
        }
    }
    else
    {
        Cnt_OC_Ia   = 0;
    }

    if(Ib_abs > OC_set)
    {
        if(++Cnt_OC_Ib >= 4)
        {
            Cnt_OC_Ib   = 0;
            Fault_SW    |= SFT_OC_Ib;                                // check over-current check
        }
    }
    else
    {
        Cnt_OC_Ib   = 0;
    }

    if(Ic_abs > OC_set)
    {
        if(++Cnt_OC_Ic >= 4)
        {
            Cnt_OC_Ic   = 0;
            Fault_SW    |= SFT_OC_Ic;                                // check over-current check
        }
    }
    else
    {
        Cnt_OC_Ic  = 0;
    }

    fault_HW_check();
}

void Fault_check_100ms()
{

    if(Flag_Grid_err == 1)
    {
        if(Flag_charge == 1)
        {
#if 0
            if(Vqe_flt > OV_set_src)
            {
//                Fault_SW    |= SFT_SOV_Va;
                Fault_SW    |= SFT_OV_Src;
            }
            else if(Vqe_flt < UV_set_src)
            {
//                Fault_SW    |= SFT_SUV_Va;
                Fault_SW    |= SFT_UV_Src;
            }
#endif

            if(Eabc_rms > OV_set_src_rms)
            {
//                Fault_SW    |= SFT_SOV_Va;
                Fault_SW    |= SFT_OV_Src;
            }
            else if(Eabc_rms < UV_set_src_rms)
            {
//                Fault_SW    |= SFT_SUV_Va;
                Fault_SW    |= SFT_UV_Src;
            }
        }
    }

    if(Flag_gating ==1)
    {
        if(((Vdc_con_real_max-Idc_flt_avg) > 20) && (Vin_flt_avg > Vin_min_2))
        {
            if(CNT_ref_Err++ > 10)
            {
//                Fault_SW |= SFT_under_ref;
                CNT_ref_Err = 0;
            }
        }
        else
        {
            CNT_ref_Err = 0;
        }
    }

    if(DI5_input == 0 )     //NO
//    if(DI5_input == 1 )   //NC
    {
//        Fault_SW |= SFT_overheat_con;
        Fault_SW |= SFT_overheat_inv;
    }
    if(DI6_input == 0 )   //NO
//    if(DI6_input == 1 )     //NC
    {
        Fault_SW |= SFT_overheat_inv;
    }
}

void check_overload()
{
    float tempP;

    Pinv_DQ_avg = -Pinv_DQ_sum  / Cnt_OL;
    Pinv_DQ_sum = 0.;
    Cnt_OL      = 0;

    tempP       = fabs(Pinv_DQ_avg);
    Pinv_DQ_avg_abs = fabs(Pinv_DQ_avg);

    if(tempP >= Overload_Pout)
    {
        if(Cnt_overload++ >= (OL_time_set * 10))
        {
            Fault_SW    |= SFT_OVERLOAD;
        }
    }
    else
    {
        Cnt_overload = 0;
    }
}


void inv_fault()
{
    int i       = 0;
    int n       = 0;

    if(System_fault == FAULT)       return;     // if fault is detected again, just return

    History[0][0]   = (Fault_HW         & 0xffff);
    History[0][1]   = (Fault_SW         & 0xffff);
    History[0][2]   = ((Fault_SW >> 16) & 0xffff);

    History[0][3]   = (int)(Vin_flt     * 100);
    History[0][4]   = (int)(Idc_flt     * 100);
    History[0][5]   = (int)(Vdc_flt     * 10);
    History[0][6]   = (int)(Vqe_flt     * 10);
    History[0][7]   = (int)(Ia_flt      * 100);

    // define review need, 디버깅이 안됨.
/*****************************************************************************************************/
// check #2 : redefine need
    History[0][8]   = (int)(time.Read_year);
    History[0][9]   = (int)(time.Read_mon_day);
    History[0][10]  = (int)(time.Read_hour_min);
    History[0][11]  = (int)(time.Read_sec);
/*****************************************************************************************************/

    History[0][12]  = (int)(Freq_out            * 100);
    History[0][13]  = (int)(Esa_rms             * 10);
    History[0][14]  = (int)(Esb_rms             * 10);
    History[0][15]  = (int)(Ia                  * 100);
    History[0][16]  = (int)(Ib                  * 100);
    History[0][17]  = (int)(Ia_rms              * 100);
    History[0][18]  = (int)(Vdc_con_real_max    * 100);
//    History[0][19]  = (int)(A_ref_flt           * 100);
    History[0][19]  = (int)(Idc_ref_comp        * 100);


    if(Fault_save == 1)
    {

        for(i = 1 ; i<10 ; i++){

            for(n = 0; n < 20; n++){

                History[10-i][n] = History[9-i][n];
            }
        }
        Enable_EEPROM_write2 = 1;
        Fault_save = 0;
    }

//========================================================================================================================

    Fault_history[0]    = (Fault_HW & 0xffff);
    Fault_history[1]    = (Fault_SW & 0xffff);
    Fault_history[2]    = ((Fault_SW >> 16) & 0xffff);

    System_fault    = FAULT;    // fault process(flag setting)
    System_fault_latch |= System_fault;

    Flag_gating_test = 0;
    Flag_gating_con_test = 0;
    Flag_gating_inv_test = 0;
    Flag_gating_VF_TEST  = 0;
    Flag_pwm_con_test1  = 0;

    Flag_gating     = 0;
    Flag_gating_inv = 0;
    Flag_gating_VF  = 0;

    Cnt_gating_inv  = 0;

    Flag_charge     = 0;
    Flag_charge_inv = 0;
    Flag_Ch_Vdc     = 0;

    DO1_output      = 0;
    DO2_output      = 0;
    DO3_output      = 0;
    DO4_output      = 0;
    DO5_output      = 0;
    DO6_output      = 0;
    DO7_output      = 0;
    DO8_output      = 0;
    DO9_output      = 0;
    DO10_output      = 0;
    DO11_output      = 0;
    DO12_output      = 0;
    DO13_output      = 0;
    DO14_output      = 0;
    DO15_output      = 0;
    DO16_output      = 0;

//  Flag_buildup    = 0;
    Flag_buildup    = 1;
    Cnt_buildup     = 0;
    Cnt_gating_inv  = 0;

    MC_on_cnt       = 0;
    Cnt_Fan1_OFF    = 0;

    Fault_reset         = 0;
    Fault_reset_DI_cnt  = 0;
    Fault_reset_com     = 99;

    DI_Run_Stop = 0;
}


void Fault_reset_100ms()
{
    if(EnbReturnTime == 1)
    {
        if(++CNT_Reset >= 600)
        {
            Fault_reset     = 1;
            CNT_Reset       = 0;
        }// 60sec
    }
    else if(EnbReturnTime == 2)
    {
        if(++CNT_Reset >= 1200)
        {
            Fault_reset     = 1;
            CNT_Reset       = 0;
        }// 120sec
    }
    else if(EnbReturnTime == 3)
    {
        if(++CNT_Reset >= 1800)
        {
            Fault_reset     = 1;
            CNT_Reset       = 0;
        }// 180sec
    }
    else if(EnbReturnTime == 4)
    {
        if(++CNT_Reset >= 2400)
        {
            Fault_reset     = 1;
            CNT_Reset       = 0;
        }// 240sec
    }
    else if(EnbReturnTime == 5)
    {
        if(++CNT_Reset >= 3050)
        {
            Fault_reset     = 1;
            CNT_Reset       = 0;
        }// 305sec
    }
}


void system_restart()
{

    System_fault    = NORMAL;

    EALLOW;
    EPwm1Regs.TZCLR.bit.OST     = 1;
    EPwm2Regs.TZCLR.bit.OST     = 1;
    EPwm3Regs.TZCLR.bit.OST     = 1;
    EPwm4Regs.TZCLR.bit.OST     = 1;
    EPwm5Regs.TZCLR.bit.OST     = 1;
    EPwm6Regs.TZCLR.bit.OST     = 1;
    EPwm7Regs.TZCLR.bit.OST     = 1;
    EPwm8Regs.TZCLR.bit.OST     = 1;
    EPwm9Regs.TZCLR.bit.OST     = 1;
    EPwm10Regs.TZCLR.bit.OST    = 1;
    EPwm11Regs.TZCLR.bit.OST    = 1;
    EPwm12Regs.TZCLR.bit.OST    = 1;

    EPwm1Regs.TZCLR.bit.DCAEVT1     = 1;
    EPwm2Regs.TZCLR.bit.DCAEVT1     = 1;
    EPwm3Regs.TZCLR.bit.DCAEVT1     = 1;
    EPwm4Regs.TZCLR.bit.DCAEVT1     = 1;
    EPwm5Regs.TZCLR.bit.DCAEVT1     = 1;
    EPwm6Regs.TZCLR.bit.DCAEVT1     = 1;
    EPwm7Regs.TZCLR.bit.DCAEVT1     = 1;
    EPwm8Regs.TZCLR.bit.DCAEVT1     = 1;
    EPwm9Regs.TZCLR.bit.DCAEVT1     = 1;
    EPwm10Regs.TZCLR.bit.DCAEVT1    = 1;
    EPwm11Regs.TZCLR.bit.DCAEVT1    = 1;
    EPwm12Regs.TZCLR.bit.DCAEVT1    = 1;

    EPwm1Regs.TZCLR.bit.INT     = 1;    // Trip interrupt Flag Clear
    EPwm2Regs.TZCLR.bit.INT     = 1;    // Trip interrupt Flag Clear
    EPwm3Regs.TZCLR.bit.INT     = 1;    // Trip interrupt Flag Clear
    EPwm4Regs.TZCLR.bit.INT     = 1;    // Trip interrupt Flag Clear
    EPwm5Regs.TZCLR.bit.INT     = 1;    // Trip interrupt Flag Clear
    EPwm6Regs.TZCLR.bit.INT     = 1;    // Trip interrupt Flag Clear
    EPwm7Regs.TZCLR.bit.INT     = 1;    // Trip interrupt Flag Clear
    EPwm8Regs.TZCLR.bit.INT     = 1;    // Trip interrupt Flag Clear
    EPwm9Regs.TZCLR.bit.INT     = 1;    // Trip interrupt Flag Clear
    EPwm10Regs.TZCLR.bit.INT    = 1;    // Trip interrupt Flag Clear
    EPwm11Regs.TZCLR.bit.INT    = 1;    // Trip interrupt Flag Clear
    EPwm12Regs.TZCLR.bit.INT    = 1;    // Trip interrupt Flag Clear
    EDIS;
//----------------------------------------
    Vde_ref     = 0.;
    Vqe_ref     = 0.;

    Fault_SW    = 0;
    Fault_HW    = 0;
    Fault_HW_new    = 0;
    Fault_HW_old    = 0;
    Fault_TZ        = 0;

    Fault_EPWM1_TZ1  = 0;
    Fault_EPWM2_TZ1  = 0;
    Fault_EPWM3_TZ1  = 0;
    Fault_EPWM4_TZ2  = 0;
    Fault_EPWM5_TZ2  = 0;
    Fault_EPWM6_TZ2  = 0;
    Fault_EPWM7_TZ3  = 0;
    Fault_EPWM8_TZ3  = 0;
    Fault_EPWM9_TZ3  = 0;
    Fault_EPWM10_TZ4 = 0;
    Fault_EPWM11_TZ4 = 0;
    Fault_EPWM12_TZ4 = 0;

    Offset_cnt = 0;
    Flag_offset = 0;
    Flag_gating_test    = 0;
    Flag_gating_con_test = 0;
    Flag_gating_inv_test = 0;

    Flag_gating = 0;
    Flag_gating_inv = 0;

    Fault_reset         = 0;
    Fault_reset_DI_cnt  = 0;
    Fault_reset_com     = 99;

    Count_freq1     = 0;
    Count_freq2     = 0;
    Cnt_freq_max    = 0;

    Theta_old       = 0;

//  INV_status      = 0;
    CNT_Reset       = 0;
    Cnt_SEQ         = 0;

    Flag_Fault      = 0;

    Cnt_gating_inv  = 0;
    MC_on_cnt       = 0;
    Cnt_Fan1_OFF    = 0;

    DI_Run_Stop = 0;
}
