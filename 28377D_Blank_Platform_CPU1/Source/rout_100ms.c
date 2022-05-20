//###############################################################################################################
// 파일명      : rout_100ms.c
// 회사명      : G-Philos
// 작성날짜  : 2020.12.17
// 작성자      : KYJ-PC
// 수정날짜  : 2021.01.04
// 수정자      : Lee Sang Cheol
// 설명         : 100ms routine
//###############################################################################################################

#include "Define.h"

void rout_100ms()
{
    if(time_check_cnt == 8)   LED1_ON;

    rout_100ms_count++;

/*--------------------------------------*/
/*  AC-DC rms & avg [Analog]            */
/*--------------------------------------*/
    rms_avg();

/*--------------------------------------*/
/*  system fault check                  */
/*--------------------------------------*/
    if(Mode_system == TEST_MODE)
    {
        if(DI5_input == 0 )   //NO
//        if(DI5_input == 1 )     //NC
        {
//            Fault_SW |= SFT_overheat_con;
            Fault_SW |= SFT_overheat_inv;
        }
        if(DI6_input == 0 )   //NO
//        if(DI6_input == 1 )     //NC
        {
            Fault_SW |= SFT_overheat_inv;
        }
    }
    else
    {
        if((Flag_offset == 3) && (Fault_check_cnt++ >= 5))
        {
            Fault_check_cnt     = 5;
            if(Eum_enable == 0)
            {
                Fault_check_100ms();
                check_overload();
            }
        }
    }

    if((Flag_offset == 3) && (control_power_check_cnt++ >= 50))
//    if((Flag_offset == 3) && (control_power_check_cnt++ >= 100))
    {
        control_power_check_cnt     = 50;
        control_power_check_flag    = 1;
    }

/*------------------------------------------*/
/*  system Grid auto fault reset command    */
/*------------------------------------------*/
//    if((System_fault == FAULT) && ((Vqe_flt < OV_set_src) && (Vqe_flt > UV_set_src)))
    if((System_fault == FAULT) && ((Eabc_rms < OV_set_src_rms) && (Eabc_rms > UV_set_src_rms)))
    {
        Fault_reset_100ms();
    }
    else
    {
        CNT_Reset = 0;
    }

/*------------------------------------------*/
/*  system user setting input process       */
/*------------------------------------------*/
    process_user_input();


    if ((Cnt_T_500ms--) == 0)
    {
        Flag_T_500ms = 1;
        Cnt_T_500ms = Set_T_500ms - 1;
    }


    if(time_check_cnt == 8)   LED1_OFF;
}

void rms_avg()
{

#if 1
    float   INV_Cnt_rms;
    float   INV_Cnt_rms_avg;

    INV_Cnt_rms = 1.0 / Cnt_rms;

    Vin_flt_avg     = Vin_flt_sum       * INV_Cnt_rms;      Vin_flt_sum     = 0.;
    A_ref_flt_avg   = A_ref_flt_sum     * INV_Cnt_rms;      A_ref_flt_sum   = 0.;

    Idc_ref_Aref    = (A_ref_flt_avg - Idc_ref_offset) * Idc_ref_factor;

    if(OP_MODE == 1)
    {
        Idc_ref_comp = Idc_ref_Aref;        //Analog mode
    }
    else if(OP_MODE ==3)
    {
//      Idc_ref_comp = Idc_ref_comp_input;  //com mode

        if(Idc_ref_comp_input >= Idc_limit_con)
        {
            Idc_ref_comp_input  = Idc_limit_con;
            Idc_ref_comp        = Idc_ref_comp_input;
        }
        else if(Idc_ref_comp_input < 0)
        {
            Idc_ref_comp_input  = 0;
            Idc_ref_comp        = Idc_ref_comp_input;
        }
        else
        {
            Idc_ref_comp        = Idc_ref_comp_input;
        }
    }

    Idc_flt_avg     = Idc_flt_sum       * INV_Cnt_rms;      Idc_flt_sum     = 0.;
    Vdc_flt_avg     = Vdc_flt_sum       * INV_Cnt_rms;      Vdc_flt_sum     = 0.;

    Esa_rms         = sqrt(Esa_rms_sum  * INV_Cnt_rms);     Esa_rms_sum     = 0.;
    Esb_rms         = sqrt(Esb_rms_sum  * INV_Cnt_rms);     Esb_rms_sum     = 0.;
    Esc_rms         = sqrt(Esc_rms_sum  * INV_Cnt_rms);     Esc_rms_sum     = 0.;

    Ia_rms          = sqrt(Ia_rms_sum   * INV_Cnt_rms);     Ia_rms_sum      = 0.;
    Ib_rms          = sqrt(Ib_rms_sum   * INV_Cnt_rms);     Ib_rms_sum      = 0.;
    Ic_rms          = sqrt(Ic_rms_sum   * INV_Cnt_rms);     Ic_rms_sum      = 0.;

/************** To reduce control time ****************/
    Eabc_rms = (Esa_rms + Esb_rms + Esc_rms) * INV_3;

    Cnt_rms = 0;

    Vin_flt_avg_sum     += Vin_flt_avg;
    A_ref_flt_avg_sum   += A_ref_flt_avg;
    Vdc_flt_avg_sum     += Vdc_flt_avg;
    Idc_flt_avg_sum     += Idc_flt_avg;

    Esa_rms_avg_sum     += Esa_rms;
    Esb_rms_avg_sum     += Esb_rms;
    Esc_rms_avg_sum     += Esc_rms;

    Ia_rms_avg_sum      += Ia_rms;
    Ib_rms_avg_sum      += Ib_rms;
    Ic_rms_avg_sum      += Ic_rms;

    if(Cnt_rms_avg++ == 8)
    {
        INV_Cnt_rms_avg = 1.0 / Cnt_rms_avg;

        Vin_flt_avg_avg     = Vin_flt_avg_sum       * INV_Cnt_rms_avg;      Vin_flt_avg_sum     = 0.;
        A_ref_flt_avg_avg   = A_ref_flt_avg_sum     * INV_Cnt_rms_avg;      A_ref_flt_avg_sum   = 0.;
        Vdc_flt_avg_avg     = Vdc_flt_avg_sum       * INV_Cnt_rms_avg;      Vdc_flt_avg_sum     = 0.;
        Idc_flt_avg_avg     = Idc_flt_avg_sum       * INV_Cnt_rms_avg;      Idc_flt_avg_sum     = 0.;

        Pin                 = Vin_flt_avg_avg       * Idc_flt_avg_avg   * 0.001;

        Esa_rms_avg         = Esa_rms_avg_sum       * INV_Cnt_rms_avg;      Esa_rms_avg_sum     = 0.;
        Esb_rms_avg         = Esb_rms_avg_sum       * INV_Cnt_rms_avg;      Esb_rms_avg_sum     = 0.;
        Esc_rms_avg         = Esc_rms_avg_sum       * INV_Cnt_rms_avg;      Esc_rms_avg_sum     = 0.;

        Ia_rms_avg          = Ia_rms_avg_sum        * INV_Cnt_rms_avg;      Ia_rms_avg_sum       = 0.;
        Ib_rms_avg          = Ib_rms_avg_sum        * INV_Cnt_rms_avg;      Ib_rms_avg_sum       = 0.;
        Ic_rms_avg          = Ic_rms_avg_sum        * INV_Cnt_rms_avg;      Ic_rms_avg_sum       = 0.;

        Cnt_rms_avg = 0.;

        if(Vin_flt_avg_avg < 0) Vin_flt_avg_avg_abs = 0;
        else    Vin_flt_avg_avg_abs = Vin_flt_avg_avg;

        if(Idc_flt_avg_avg < 0) Idc_flt_avg_avg_abs = 0;
        else    Idc_flt_avg_avg_abs = Idc_flt_avg_avg;

        if(Pin < 0) Pin_abs = 0;
        else    Pin_abs = Pin;
    }
#endif
}


void process_user_input()
{
    float   a   = 0.;

    Index_user_input++;

//    if((Flag_charge == 1) && (Flag_gating==1) && (Flag_buildup == 1))   Run_TOGGLE;

    if(Index_user_input == 1)
    {
#if 1
/*--------------------------------------*/
/*  control variables initialize        */
/*--------------------------------------*/
        Mode_system         = Mode_system_input;
        Mode_pwm            = Mode_pwm_input;    // (1)SVPWM,(0)SPWM

        Vs_rate             = INV_SQRT3 * Vl_rate;
        Vs_rate_peak        = SQRT2 * Vs_rate;
        INV_Vs_rate_peak    = 1. / (Vs_rate_peak + 1.e-30);
        Ic_rate_peak        = SQRT2 * Ic_rate;

        OV_set_Vin          = Vin_max   + OV_Vin_level;
        UV_set_Vin          = Vin_min   - UV_Vin_level;
        OC_Idc_set          = Idc_max   * (OC_Idc_ratio * 0.01);

        OV_set_Vdc          = Vdc_max   + OV_Vdc_level;

        OV_set_src          = Vs_rate_peak  * (OV_ratio_src     * 0.01);   // source over-voltage
        UV_set_src          = Vs_rate_peak  * (UV_ratio_src     * 0.01);   // source under-voltage
        INTER_set_src       = Vs_rate_peak  * (INTER_ratio_src  * 0.01);   // source interruption

        OV_set_src_rms      = Vs_rate       * (OV_ratio_src_rms * 0.01);   // source over-voltage
        UV_set_src_rms      = Vs_rate       * (UV_ratio_src_rms * 0.01);   // source under-voltage

        OC_set              = Ic_rate_peak  * (OC_ratio         * 0.01);   // over-current
        Ip_ref_real_max_max = OC_set;

        Overload_Pout       = Pout_rate     * (OL_ratio         * 0.01);

        Vin_MC_ON_level     = Vin_min   + 1;
        Vin_MC_OFF_level    = Vin_min   - 1;

        Vin_max_80          = Vin_max * 0.8;
        Vin_min_2           = Vin_min + 2;

        AC_MC_ON_level      = Vl_rate       * SQRT2 * (AC_MC_ON_ratio     * 0.01);
        AC_MC_OFF_level     = Vl_rate       * SQRT2 * (AC_MC_OFF_ratio    * 0.01);

//      Ip_ref_real_max     = Ic_rate_peak  * (Ip_ref_ratio     * 0.01);   // over-current

        //Mode_system 0: Real control
        //Mode_system 1: MC on/off test
        //Mode_system 2: AC/DC Converter test control seq
        if(Mode_system == TEST_MODE2)
        {
            AC_MC_ON_level  = Esa_rms_avg * SQRT2_SQRT3 - 30;
            AC_MC_OFF_level = Esa_rms_avg * SQRT2_SQRT3 - 100;

            if(Ref_con_inv_flag == 1)
            {
                Vdc_ref_inv_input       = Vl_rate * SQRT2_SQRT3 * 0.01 * Vdc_ref_inv_ratio;
                Vdc_ref_inv             = Vdc_ref_inv_input;

                Ip_ref_real_max_input   = Ic_rate_peak  * (Ip_ref_ratio     * 0.01);    // over-current
//                Ip_ref_real_max         = Ip_ref_real_max_input;                         // over-current

                Vdc_ref_con_set_input   = Vdc_ref_inv + Vdc_ref_con_set_level;
                Vdc_ref_con_set         = Vdc_ref_con_set_input;
//                Idc_ref_comp            = Idc_ref_comp_input;
            }
            else
            {
                Vdc_ref_inv         = Vdc_ref_inv_input;
//                Ip_ref_real_max     = Ip_ref_real_max_input;

                Vdc_ref_con_set     = Vdc_ref_con_set_input;
//                Idc_ref_comp        = Idc_ref_comp_input;
            }
        }
        else
        {
            if(Ref_con_inv_flag == 1)
            {
                Vdc_ref_inv_input       = Vl_rate * SQRT2_SQRT3 * 0.01 * Vdc_ref_inv_ratio;
                Vdc_ref_inv             = Vdc_ref_inv_input;

                Ip_ref_real_max_input   = Ic_rate_peak  * (Ip_ref_ratio     * 0.01);    // over-current
//                Ip_ref_real_max         = Ip_ref_real_max_input;                         // over-current

                Vdc_ref_con_set_input   = Vdc_ref_inv + Vdc_ref_con_set_level;
                Vdc_ref_con_set         = Vdc_ref_con_set_input;
//                Idc_ref_comp            = Idc_ref_comp_input;
            }
            else
            {
                Vdc_ref_inv         = Vdc_ref_inv_input;
//                Ip_ref_real_max     = Ip_ref_real_max_input;

                Vdc_ref_con_set     = Vdc_ref_con_set_input;
//                Idc_ref_comp        = Idc_ref_comp_input;
            }
        }
#endif


        // 1 = 27Vdc, 55Vac
        if(SCI_WR_setting == 1)
        {
            Vin_min = 15;
            Idc_max = 20;
            Vdc_max = 300;

            Vl_rate = 95;

            Vdc_ref_inv_input = 160;
            Ip_ref_real_max_input   = 5;
            Vdc_ref_con_set_input   = 180;
            Idc_ref_comp_input      = 2;

            Vdc_ref_set_init = Vdc_ref_inv_input;

            Flag_Grid_err = 0;
        }

        // 2 = 55Vdc, 110Vac
        else if(SCI_WR_setting == 2)
        {
            Vin_min = 15;
            Idc_max = 20;
            Vdc_max = 400;
            Vl_rate = 190;
            Vdc_ref_inv_input = 320;
            Ip_ref_real_max_input   = 5;
            Vdc_ref_con_set_input   = 360;
            Idc_ref_comp_input      = 2;

            Vdc_ref_set_init = Vdc_ref_inv_input;

            Flag_Grid_err = 0;
        }

        // 2 = 82Vdc, 165Vac
        else if(SCI_WR_setting == 3)
        {
            Vin_min = 15;
            Idc_max = 20;
            Vdc_max = 600;
            Vl_rate = 285;
            Vdc_ref_inv_input = 480;
            Ip_ref_real_max_input   = 5;
            Vdc_ref_con_set_input   = 540;
            Idc_ref_comp_input      = 2;

            Vdc_ref_set_init = Vdc_ref_inv_input;

            Flag_Grid_err = 0;
        }

        // 2 = 110Vdc, 220Vac
        else if(SCI_WR_setting == 4)
        {
            Vin_min = 15;
            Idc_max = 75;
            Vdc_max = 700;
            Vl_rate = 380;
            Vdc_ref_inv_input = 640;
            Ip_ref_real_max_input   = 16.6;
            Vdc_ref_con_set_input   = 670;
 //         Idc_ref_comp_input      = 2;


            Vdc_ref_set_init = Vdc_ref_inv_input;

            Flag_Grid_err = 1;

        }

        // 2 = 110Vdc, 220Vac
        else if(SCI_WR_setting == 5)
        {
            Vin_min = 82;
            Idc_max = 20;
            Vdc_max = 700;
            Vl_rate = 380;
            Vdc_ref_inv_input = 640;
            Ip_ref_real_max_input   = 5;
            Vdc_ref_con_set_input   = 670;
            Idc_ref_comp_input      = 2;


            Vdc_ref_set_init = Vdc_ref_inv_input;
            Flag_Grid_err = 1;

        }

        // 22 = 13Vdc, 27Vac = only DC/AC inverter test
        else if(SCI_WR_setting == 22)
        {
            Mode_system_input = 2;
            Vin_min = -10;
            Idc_max = 20;
            Vdc_max = 150;
            Vl_rate = 50;
            Vdc_ref_inv_input = 80;
            Ip_ref_real_max_input   = 5;
            Vdc_ref_con_set_input   = 100;
            Idc_ref_comp_input      = 2;

            Vdc_ref_set_init = Vdc_ref_inv_input;

            Flag_Grid_err = 0;
        }

        else
        {
            //don't user setting
            Flag_Grid_err = 1;
        }
    }

    else if(Index_user_input == 2)
    {
#if 1
//        if((fabs(Scale_Vin_ratio - 100) < 50) && (fabs(Scale_Idc_ratio - 100) < 20) && (fabs(Scale_A_ref_ratio - 100) < 20)
//        && (fabs(Scale_Vdc_ratio - 100) < 50) && (fabs(Scale_Esa_ratio - 100) < 20) && (fabs(Scale_Esb_ratio   - 100) < 20)
//        && (fabs(Scale_Esc_ratio - 100) < 50) && (fabs(Scale_Ia_ratio  - 100) < 20) && (fabs(Scale_Ib_ratio   - 100) < 20)
//        && (fabs(Scale_Ic_ratio  - 100) < 20))
        if((fabs(Scale_Vin_ratio - 100) < 50) && (fabs(Scale_Idc_ratio - 100) < 50) && (fabs(Scale_A_ref_ratio - 100) < 50)
        && (fabs(Scale_Vdc_ratio - 100) < 50) && (fabs(Scale_Esa_ratio - 100) < 50) && (fabs(Scale_Esb_ratio   - 100) < 50)
        && (fabs(Scale_Esc_ratio - 100) < 50) && (fabs(Scale_Ia_ratio  - 100) < 50) && (fabs(Scale_Ib_ratio   - 100) < 50)
        && (fabs(Scale_Ic_ratio  - 100) < 50))

        {
            Scale_Vin           =   Scale_Vin_input         * Scale_Vin_ratio           * INV_12bit_AD_SCALE;
            Scale_Idc           =   Scale_Idc_input         * Scale_Idc_ratio           * INV_12bit_AD_SCALE;
            Scale_A_ref         =   Scale_A_ref_input       * Scale_A_ref_ratio         * INV_12bit_AD_SCALE;
            Scale_Vdc           =   Scale_Vdc_input         * Scale_Vdc_ratio           * INV_12bit_AD_SCALE;

            Scale_Esa           =   Scale_Esa_input         * Scale_Esa_ratio           * INV_12bit_AD_SCALE;
            Scale_Esb           =   Scale_Esb_input         * Scale_Esb_ratio           * INV_12bit_AD_SCALE;
            Scale_Esc           =   Scale_Esc_input         * Scale_Esc_ratio           * INV_12bit_AD_SCALE;

            Scale_Ia            =   Scale_Ia_input          * Scale_Ia_ratio            * INV_12bit_AD_SCALE;
            Scale_Ib            =   Scale_Ib_input          * Scale_Ib_ratio            * INV_12bit_AD_SCALE;
            Scale_Ic            =   Scale_Ic_input          * Scale_Ic_ratio            * INV_12bit_AD_SCALE;
        }

//        if((fabs(Vin_offset_input) < 100) && (fabs(Idc_offset_input) < 100) && (fabs(A_ref_offset_input) < 100)
//        && (fabs(Vdc_offset_input) < 100))
        if((fabs(Vin_offset_input) < 1000) && (fabs(Idc_offset_input) < 1000) && (fabs(A_ref_offset_input) < 1000)
        && (fabs(Vdc_offset_input) < 1000))
        {
            Vin_offset      =   Vin_offset_input;
            Idc_offset      =   Idc_offset_input;
            A_ref_offset    =   A_ref_offset_input;
            Vdc_offset      =   Vdc_offset_input;
        }

        if((fabs(Ia_offset_comp_input) < 5) && (fabs(Ib_offset_comp_input) < 5) && (fabs(Ic_offset_comp_input) < 5))
        {
            Ia_offset_comp  =   Ia_offset_comp_input;
            Ib_offset_comp  =   Ib_offset_comp_input;
            Ic_offset_comp  =   Ic_offset_comp_input;
        }
        else
        {
            Ia_offset_comp_input    = 0;
            Ib_offset_comp_input    = 0;
            Ic_offset_comp_input    = 0;

            Ia_offset_comp  =   Ia_offset_comp_input;
            Ib_offset_comp  =   Ib_offset_comp_input;
            Ic_offset_comp  =   Ic_offset_comp_input;
        }

        if((fabs(Esa_offset_comp_input) < 50) && (fabs(Esb_offset_comp_input) < 50) && (fabs(Esc_offset_comp_input) < 50))
        {
            Esa_offset_comp  =   Esa_offset_comp_input;
            Esb_offset_comp  =   Esb_offset_comp_input;
            Esc_offset_comp  =   Esc_offset_comp_input;
        }
        else
        {
            Esa_offset_comp_input    = 0;
            Esb_offset_comp_input    = 0;
            Esc_offset_comp_input    = 0;

            Esa_offset_comp  =   Esa_offset_comp_input;
            Esb_offset_comp  =   Esb_offset_comp_input;
            Esc_offset_comp  =   Esc_offset_comp_input;
        }

        Init_scale_offset();


        Set_offset_wait=(int)(Time_offset_wait*INV_Tsamp+0.5);
#endif
    }

    else if(Index_user_input == 3)
    {
#if 1
        We_rate_init    = PI_MPY_2    * Freq_rate_init;

        //all pass filter
        Wgrid           = We_rate_init;
        a=We_rate_init; // APF(Freq_rate_init)
        La_APF_FRI      = a ;
        Lb_APF_FRI      = ( 1 - 0.5 * a * Tsamp) / (1. + 0.5 * a * Tsamp);

        //low pass filter
        a = PI_MPY_2 * Tsamp * FL_ADC;       La_ADC      = (2. - a) / (2. + a);    Lb_ADC    = a / (2. + a);

        a = PI_MPY_2 * Tsamp * FL_Vin;       La_Vin      = (2. - a) / (2. + a);    Lb_Vin    = a / (2. + a);
        a = PI_MPY_2 * Tsamp * FL_Idc;       La_Idc      = (2. - a) / (2. + a);    Lb_Idc    = a / (2. + a);
        a = PI_MPY_2 * Tsamp * FL_A_ref;     La_A_ref    = (2. - a) / (2. + a);    Lb_A_ref  = a / (2. + a);
        a = PI_MPY_2 * Tsamp * FL_Vdc;       La_Vdc      = (2. - a) / (2. + a);    Lb_Vdc    = a / (2. + a);

        a = PI_MPY_2 * Tsamp * FL_Va;        La_Va       = (2. - a) / (2. + a);    Lb_Va     = a / (2. + a);
        a = PI_MPY_2 * Tsamp * FL_Ia;        La_Ia       = (2. - a) / (2. + a);    Lb_Ia     = a / (2. + a);
        a = PI_MPY_2 * Tsamp * FL_Iqe_ref;        La_Iqe_ref       = (2. - a) / (2. + a);    Lb_Iqe_ref     = a / (2. + a);

        a = PI_MPY_2 * Tsamp * FL_s_volt;    La_s_volt   = (2. - a) / (2. + a);    Lb_s_volt = a / (2. + a);
        a = PI_MPY_2 * Tsamp * FL_e_volt;    La_e_volt   = (2. - a) / (2. + a);    Lb_e_volt = a / (2. + a);

        Wc_I_5th = 2. * PI * Fc_I_5th;
        La_I_5th = (2. - Wc_I_5th * Tsamp) / (2. + Wc_I_5th * Tsamp);
        Lb_I_5th = (Wc_I_5th * Tsamp) / (2. + Wc_I_5th * Tsamp);
#endif
        if(Flag_gating == 0)
        {
            Freq_shift_ratio    = Freq_shift_ratio_input;
            if((Flag_Act_islanding_input == 77) || (Flag_Act_islanding_input == 88) || (Flag_Act_islanding_input == 99))
            {
                Flag_Act_islanding = Flag_Act_islanding_input;
                if(Flag_Act_islanding == 77.)
                {
                    Freq_high   = 62.0;
                    Freq_low    = 57.5;
                }
                else if(Flag_Act_islanding == 88.)
                {
//                    Freq_high   = 60.28;
//                    Freq_low    = 59.70;
                      Freq_high   = 60.25;
                      Freq_low    = 59.75;
                }
                else if(Flag_Act_islanding == 99.)
                {   Freq_high   = 62.0;
                    Freq_low    = 57.5;
                }
                else if(Flag_Act_islanding == 66.)
                {
//                    Freq_high   = 62.0;
//                    Freq_low    = 57.5;
                }
            }
            else
            {
                Flag_Act_islanding_input    = 77.;
                Flag_Act_islanding          = Flag_Act_islanding_input;
            }
        }
    }

    else if(Index_user_input == 4)
    {
#if 1
/*--------------------------------------*/
/*  Gain variables initialize           */
/*--------------------------------------*/
        Kp_Vdc_con  = Kp_Vdc_con_input  * Kp_Vdc_con_ratio  * 0.01;
        Ki_Vdc_con  = Ki_Vdc_con_input  * Ki_Vdc_con_ratio  * 0.01;

        Kp_Idc      = Kp_Idc_con_input  * Kp_Idc_con_ratio  * 0.01;
        Ki_Idc      = Ki_Idc_con_input  * Ki_Idc_con_ratio  * 0.01;

        Lc      = Lc_input  * 1.e-3;   // user-input[mH] -> real[H]
        Cdc     = Cdc_input * 1.e-6;   // user-input[uF] -> real[F]

        Kp_VC   = 2.    * Zeta_VC   * Wn_VC * Cdc   * Vdc_ref_set_init  * (INV2_3   * INV_Vs_rate_peak) * (Kp_Vdc_ratio     * 0.01); // Zeta_VC=1, Wn_VC=20
        Ki_VC   = Wn_VC * Wn_VC     * Cdc   * Vdc_ref_set_init  * (INV2_3   * INV_Vs_rate_peak)         * (Ki_Vdc_inv_ratio * 0.01);      // Vdc_ref_set_init='300' 으로 고정!
        Ka_VC   = 1.2 / Kp_VC;


        if(flag_control_parameter == 1)
        {
//            K_cc_ratio[CKP]   = 800;
//            K_cc_ratio[CKIT]  = 0.1;
//            K_cc_ratio[CKA]   = 1;

//            K_cc_ratio[CKP]     = 400;
//            K_cc_ratio[CKIT]    = 10;
//            K_cc_ratio[CKA]     = 10;
//            K_cc_ratio[CKPD]    = 400;
//            K_cc_ratio[CKITD]   = 10;
//            K_cc_ratio[CKAD]    = 10;
//            Wc_CC               = 1200.;

//            K_cc_ratio[CKP]     = 400;
//            K_cc_ratio[CKIT]    = 5;
//            K_cc_ratio[CKA]     = 100;
//            K_cc_ratio[CKPD]    = 100;
//            K_cc_ratio[CKITD]   = 5;
//            K_cc_ratio[CKAD]    = 100;
//            Wc_CC               = 1200.;

//기동 게인 설정
//            K_cc_ratio[CKP]     = 300;
//            K_cc_ratio[CKIT]    = 10;
//            K_cc_ratio[CKA]     = 10;
//            K_cc_ratio[CKPD]    = 300;
//            K_cc_ratio[CKITD]   = 10;
//            K_cc_ratio[CKAD]    = 10;
//            Wc_CC               = 1200.;

//            K_cc_ratio[CKP]     = 300;
//            K_cc_ratio[CKIT]    = 1;
//            K_cc_ratio[CKA]     = 1;
//            K_cc_ratio[CKPD]    = 300;
//            K_cc_ratio[CKITD]   = 1;
//            K_cc_ratio[CKAD]    = 1;
//            Wc_CC               = 1400.;

            K_cc_ratio[CKP]     = 400;
            K_cc_ratio[CKIT]    = 0.5;
            K_cc_ratio[CKA]     = 1;
            K_cc_ratio[CKPD]    = 400;
            K_cc_ratio[CKITD]   = 0.5;
            K_cc_ratio[CKAD]    = 1;
            Wc_CC               = 1400.;

//            K_cc_ratio[CKP]     = 100;
//            K_cc_ratio[CKIT]    = 10;
//            K_cc_ratio[CKA]     = 100;
//            K_cc_ratio[CKPD]    = 100;
//            K_cc_ratio[CKITD]   = 10;
//            K_cc_ratio[CKAD]    = 100;
//            Wc_CC               = 1200.;

//            K_cc_ratio[CKP]     = 100;
//            K_cc_ratio[CKIT]    = 10;
//            K_cc_ratio[CKA]     = 100;
//            K_cc_ratio[CKPD]    = 100;
//            K_cc_ratio[CKITD]   = 10;
//            K_cc_ratio[CKAD]    = 100;
//            Wc_CC               = 1000.;

//            K_cc_ratio[CKP]     = 300;
//            K_cc_ratio[CKIT]    = 20;
//            K_cc_ratio[CKA]     = 100;
//            K_cc_ratio[CKPD]    = 300;
//            K_cc_ratio[CKITD]   = 20;
//            K_cc_ratio[CKAD]    = 100;
//            Wc_CC               = 1000.;

//            K_cc_ratio[CKP]     = 300;
//            K_cc_ratio[CKIT]    = 10;
//            K_cc_ratio[CKA]     = 100;
//            K_cc_ratio[CKPD]    = 300;
//            K_cc_ratio[CKITD]   = 10;
//            K_cc_ratio[CKAD]    = 100;
//            Wc_CC               = 1000.;

//            K_cc_ratio[CKP]     = 300;
//            K_cc_ratio[CKIT]    = 10;
//            K_cc_ratio[CKA]     = 100;
//            K_cc_ratio[CKPD]    = 300;
//            K_cc_ratio[CKITD]   = 10;
//            K_cc_ratio[CKAD]    = 100;
//            Wc_CC               = 1300.;

//            K_cc_ratio[CKP]     = 100;
//            K_cc_ratio[CKIT]    = 5;
//            K_cc_ratio[CKA]     = 100;
//            K_cc_ratio[CKPD]    = 100;
//            K_cc_ratio[CKITD]   = 5;
//            K_cc_ratio[CKAD]    = 100;
//            Wc_CC               = 1000.;

//            K_cc_ratio[CKP]     = 500;
//            K_cc_ratio[CKIT]    = 10;
//            K_cc_ratio[CKA]     = 10;
//
//            Wc_CC               = 1200.;


//            K_cc_ratio[CKP]     = 100;
//            K_cc_ratio[CKIT]    = 100;
//            K_cc_ratio[CKA]     = 100;
//
//            Wc_CC               = 1200.;

//            K_cc_ratio[CKP]     = 100;
//            K_cc_ratio[CKIT]    = 100;
//            K_cc_ratio[CKA]     = 100;
//
//            K_cc_ratio[CKPD]    = 100;
//            K_cc_ratio[CKITD]   = 100;
//            K_cc_ratio[CKAD]    = 100;
//
//            Wc_CC               = 800.;
//            Wc_CC_D             = 800.;

            Flag_current_control_inv3 = 1;
            Flag_Va_PLL3 = 1;
//            Flag_Ia_PLL3 = 1;
            Flag_Ia_PLL3 = 0;
            voltage_control_inv3_cnt_max = 0;
        }
        else if(flag_control_parameter == 2)
        {
            K_cc_ratio[CKP]     = 100;
            K_cc_ratio[CKIT]    = 100;
            K_cc_ratio[CKA]     = 100;

//            K_cc_ratio[CKPD]    = 25;
//            K_cc_ratio[CKITD]   = 25;
//            K_cc_ratio[CKAD]    = 100;

            K_cc_ratio[CKPD]    = 100;
            K_cc_ratio[CKITD]   = 100;
            K_cc_ratio[CKAD]    = 100;

            Kp_Ia_ratio         = 100;
            Ki_Ia_ratio         = 100;

            Kp_Ia_ratio_D       = 100;
            Ki_Ia_ratio_D       = 100;

            Wc_CC               = 1800.;
//            Wc_CC               = 2000.;
//            Wc_CC_D             = 2000.;

            Flag_current_control_inv3 = 0;
            Flag_Va_PLL3 = 0;
            Flag_Ia_PLL3 = 0;
            Flag_over_check = 0;

//            voltage_control_inv3_cnt_max = 3;
            voltage_control_inv3_cnt_max = 0;
        }

        K_cc[CKP]   = Lc        * Wc_CC     * INV_Alpha_CC                          * (K_cc_ratio[CKP]      * 0.01) * (Kp_Ia_ratio       * 0.01);
        K_cc[CKIT]  = (Wc_CC    * ((1. - Alpha_CC)  * K_cc[CKP] + Rc)   * Tsamp)    * (K_cc_ratio[CKIT]     * 0.01) * (Ki_Ia_ratio       * 0.01);
        K_cc[CKA]   = 1. / K_cc[CKP]                                                * (K_cc_ratio[CKA]      * 0.01);

        K_cc[CKPD]   = Lc        * Wc_CC     * INV_Alpha_CC                         * (K_cc_ratio[CKPD]     * 0.01) * (Kp_Ia_ratio_D     * 0.01);
        K_cc[CKITD]  = (Wc_CC    * ((1. - Alpha_CC) * K_cc[CKPD] + Rc)   * Tsamp)   * (K_cc_ratio[CKITD]    * 0.01) * (Ki_Ia_ratio_D     * 0.01);
        K_cc[CKAD]   = 1. / K_cc[CKPD]                                              * (K_cc_ratio[CKAD]     * 0.01);

//        K_cc[CKP]   = Lc        * Wc_CC                                               * (K_cc_ratio[CKP]      * 0.01) * (Kp_Ia_ratio       * 0.01);
//        K_cc[CKIT]  = (Wc_CC                         * (K_cc[CKP] + Rc)   * Tsamp)    * (K_cc_ratio[CKIT]     * 0.01) * (Ki_Ia_ratio       * 0.01);
//        K_cc[CKA]   = 1. / K_cc[CKP]                                                  * (K_cc_ratio[CKA]      * 0.01);
//
//        K_cc[CKPD]   = Lc        * Wc_CC                                              * (K_cc_ratio[CKPD]     * 0.01) * (Kp_Ia_ratio_D     * 0.01);
//        K_cc[CKITD]  = (Wc_CC                      * (K_cc[CKPD] + Rc)   * Tsamp)     * (K_cc_ratio[CKITD]    * 0.01) * (Ki_Ia_ratio_D     * 0.01);
//        K_cc[CKAD]   = 1. / K_cc[CKPD]                                                * (K_cc_ratio[CKAD]     * 0.01);

//
//        Kp_ide_p   = Lc         * Wc_CC_d_p * INV_Alpha_CC                          * (Kp_ide_d_p           * 0.01) * (Kp_ide_ratio_d_p  * 0.01);
//        Ki_ide_p  = (Wc_CC_d_p  * ((1. - Alpha_CC)  * Kp_ide_p + Rc)  * Tsamp)      * (Ki_ide_d_p           * 0.01) * (Kp_ide_ratio_d_p  * 0.01);
//        Ka_ide_p   = 1. / Kp_ide_p                                                  * (Ka_ide_d_p           * 0.01);
//
//        Kp_iqe_p   = Lc         * Wc_CC_q_p * INV_Alpha_CC                          * (Kp_iqe_q_p           * 0.01) * (Kp_iqe_ratio_q_p  * 0.01);
//        Ki_iqe_p  = (Wc_CC_q_p  * ((1. - Alpha_CC)  * Kp_iqe_p + Rc)  * Tsamp)      * (Ki_iqe_q_p           * 0.01) * (Ki_iqe_ratio_q_p  * 0.01);
//        Ka_iqe_p   = 1. / Kp_iqe_p                                                  * (Ka_ide_q_p           * 0.01);
//
//        Kp_ide_n   = Lc         * Wc_CC_d_n * INV_Alpha_CC                          * (Kp_ide_d_n           * 0.01) * (Kp_ide_ratio_q_n  * 0.01);
//        Ki_ide_n  = (Wc_CC_d_n  * ((1. - Alpha_CC)  * Kp_ide_n + Rc)  * Tsamp)      * (Ki_ide_d_n           * 0.01) * (Kp_ide_ratio_q_n  * 0.01);
//        Ka_ide_n   = 1. / Kp_ide_p                                                  * (Ka_ide_d_p           * 0.01);
//
//        Kp_iqe_n   = Lc         * Wc_CC_q_n * INV_Alpha_CC                          * (Kp_iqe_q_n           * 0.01) * (Kp_iqe_ratio_q_n  * 0.01);
//        Ki_iqe_n  = (Wc_CC_q_n  * ((1. - Alpha_CC)  * Kp_iqe_n + Rc)  * Tsamp)      * (Ki_iqe_q_n           * 0.01) * (Ki_iqe_ratio_q_n  * 0.01);
//        Ka_iqe_n   = 1. / Kp_iqe_n                                                  * (Ka_ide_q_n           * 0.01);

        // 20.12.14.lsc harmonic 변수 추가
//        Kp_iqe  = Kp_ide = K_cc[CKP];
//        Ki_iqe  = Ki_ide = K_cc[CKIT];
//        Ka_iqe  = Ka_ide = K_cc[CKA];
        Kp_iqe  = K_cc[CKP];
        Ki_iqe  = K_cc[CKIT];
        Ka_iqe  = K_cc[CKA];

        Kp_ide = K_cc[CKPD];
        Ki_ide = K_cc[CKITD];
        Ka_ide = K_cc[CKAD];


#endif
    }


    else if(Index_user_input == 5)
    {
#if 0
        if((System_fault == FAULT) && (DI_input == 0))
        {
            Fault_reset     = 1;
        }
#endif



        if(download_check == 0) //21.05.24 jyp
        {

            if(OP_MODE == 1)
            {
                //power on seq. gating error fault reset
                if((System_fault == FAULT) && (control_power_check_flag == 0))
                {
                    Fault_reset     = 1;
                }

                //system error fault reset com command
                if((System_fault == FAULT) && (DI_input == 0))
                {
                    Fault_reset_DI_cnt++;
                    if(Fault_reset_DI_cnt >= 10)
                    {
                        Fault_reset     = 1;
                        Fault_reset_DI_cnt = 0;
                    }
                }
                else
                {
                    Fault_reset_DI_cnt = 0;
                }
            }
            else if(OP_MODE == 3)
            {
                //power on seq. gating error fault reset
                if((System_fault == FAULT) && (control_power_check_flag == 0))
                {
                    Fault_reset     = 1;
                }

                //system error fault reset com command
                if((System_fault == FAULT) && (Fault_reset_com == 55))
                {
                    Fault_reset_com_cnt++;
                    if(Fault_reset_com_cnt >= 2)
                    {
                        Fault_reset     = 1;
                        Fault_reset_com_cnt = 0;
                    }
    //              Fault_reset     = 1;
    //              Fault_reset_com = 99;
                }
                else
                {
                    Fault_reset_com = 99;
                    Fault_reset_com_cnt = 0;
                }
            }

        }



    }

    else if(Index_user_input == 6)
    {
#if 1
        T_dead_comp_input     = T_dead_input;     // DT comp. time[sec]

        T_dead          = T_dead_input          * 1.e-6;     // dead-time[sec]
        T_dead_con      = T_dead_con_input      * 1.e-6;     // dead-time[sec]
        T_dead_comp     = T_dead_comp_input     * 1.e-6;     // DT comp. time[sec]
        T_dead_onoff    = T_dead_onoff_input    * 1.e-6;     // gating off-delay[sec]

        T_dead_CNT          = (int)(T_dead          * Scale_gating);
        T_dead_con_CNT      = (int)(T_dead_con      * Scale_gating_con);
        T_dead_comp_CNT     = (int)(T_dead_comp     * Scale_gating);
        T_dead_onoff_CNT    = (int)(T_dead_onoff    * Scale_gating);

        T_dead_con_CNT_50 = T_dead_con_CNT + 50;

        EPwm1Regs.CMPA.bit.CMPA = (CNT_max_con_50 - EPwm1_CMP_test);     // Set compare A value
        EPwm1Regs.CMPB.bit.CMPB = (CNT_max_con_50 - EPwm1_CMP_test);     // Set Compare B value

        EPwm2Regs.CMPA.bit.CMPA = (CNT_max_con_50 - EPwm2_CMP_test);     // Set compare A value
        EPwm2Regs.CMPB.bit.CMPB = (CNT_max_con_50 - EPwm2_CMP_test);     // Set Compare B value

        EPwm3Regs.CMPA.bit.CMPA = (CNT_max_con_50 - EPwm3_CMP_test);     // Set compare A value
        EPwm3Regs.CMPB.bit.CMPB = (CNT_max_con_50 - EPwm3_CMP_test);     // Set Compare B value

        EPwm1Regs.DBRED.bit.DBRED = T_dead_con_CNT;
        EPwm1Regs.DBFED.bit.DBFED = T_dead_con_CNT;

        EPwm2Regs.DBRED.bit.DBRED = T_dead_con_CNT;
        EPwm2Regs.DBFED.bit.DBFED = T_dead_con_CNT;

        EPwm3Regs.DBRED.bit.DBRED = T_dead_con_CNT;
        EPwm3Regs.DBFED.bit.DBFED = T_dead_con_CNT;
#endif
    }

    else
    {
#if 1
        Index_user_input    = 0;
#endif
    }
}

