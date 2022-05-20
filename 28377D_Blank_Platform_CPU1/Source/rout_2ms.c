//###############################################################################################################
// 파일명      : rout_2ms.c
// 회사명      : G-Philos
// 작성날짜  : 2020.12.17
// 작성자      : KYJ-PC
// 수정날짜  : 2021.01.04
// 수정자      : Lee Sang Cheol
// 설명         : 2ms routine
//###############################################################################################################

#include "Define.h"

void rout_2ms()
{
    if(time_check_cnt == 6)   LED1_ON;

    rout_2ms_count++;

/*--------------------------------------*/
/*  Converter Control V.C               */
/*--------------------------------------*/
// TEST_MODE = 1
#if 1
    if(Mode_system == TEST_MODE)
    {
        if(Flag_gating == 1)
        {
            making_Vdc_ref();
            soft_Idc_ref();
            voltage_control_con();
        }
        else
        {
            Vdc_ref_con_temp = Vdc_flt;
        }
    }

    else
    {
        if(Flag_gating == 1)
        {
            making_Vdc_ref();

            if(Flag_buildup == 1)
            {
//                Vdc_con_real_max = 4.;
                Vdc_con_real_max = 2.;
            }
            else
            {
                Cnt_buildup = 20;
                soft_Idc_ref();
            }

            voltage_control_con();
        }
        else
        {
            Vdc_ref_con_temp = Vdc_flt;
        }
    }
#endif

/*--------------------------------------*/
/*  Inverter Control V.C                */
/*--------------------------------------*/
    voltage_control_inv3_cnt++;
    if(voltage_control_inv3_cnt >= voltage_control_inv3_cnt_max)
    {
        if(Flag_gating_inv == 1)
        {
            voltage_control_inv3();
        }
        else
        {
            Ip_ref_integ    = Kp_VC  * Vdc_flt;     //IP 제어기

            flag_voltage_control_inv3 = 0;
        }
        voltage_control_inv3_cnt = 0;
    }

/*--------------------------------------*/
/*  Inverter Control Ref                */
/*--------------------------------------*/
    if(Flag_current_control_inv3 == 1)
    {
        making_current_ref_harmonic();
    }
    else
    {
        making_current_ref();
    }




    if(time_check_cnt == 6)   LED1_OFF;
}

void making_Vdc_ref()
{
    float   Temp;

    Temp = Vdc_ref_con_set - Vdc_ref_con_temp;

    if(Temp < 10)
    {
        Vdc_ref_con_temp    = Vdc_ref_con_set;
    }
    Temp = (Vdc_ref_con_set - Vdc_ref_con_temp) * Vdc_soft_ratio    + Vdc_ref_con_temp;
    Vdc_ref_con_temp    = Temp;
    Vdc_ref_con         = Vdc_ref_con_temp;
}


void soft_Idc_ref()
{
    float   Idc_ref_temp;
    float   Idc_limit_max;

    Idc_limit_max = Idc_ref_comp - Idc_flt_avg;

    if(Idc_limit_max        > Idc_ref_step)
    {
//     Idc_ref_temp = Idc_flt_avg + Idc_ref_step;
       Idc_ref_temp = Idc_flt_avg + 1;
    }
    else if(Idc_limit_max   < -Idc_ref_step)
    {
//      Idc_ref_temp = Idc_flt_avg - Idc_ref_step;
        Idc_ref_temp = Idc_flt_avg - 1;
    }
    else
    {
        Idc_ref_temp = Idc_ref_comp;
    }

    Vdc_con_real_max = Idc_ref_temp;

    if(Vdc_con_real_max         <= 0.1)
    {
        Vdc_con_real_max    = 0.1;
    }
    else if(Vdc_con_real_max    >= Idc_limit_con)
    {
        Vdc_con_real_max    = Idc_limit_con;
    }
}


void voltage_control_con()
{
    float   a;

    Vdc_con_ff  = 0.;
    Err_Vdc_con = Vdc_ref_con   - Vdc_flt;

    Vdc_con_integ   += Ki_Vdc_con   * T_2ms * (Err_Vdc_con - Ka_Vdc_con * (Vdc_con_out - Vdc_con_real) );
//  Vdc_con_out     = Vdc_con_integ - Kp_Vdc_con    * Vdc_flt   + Vdc_con_ff;   //IP 제어기
    Vdc_con_out     = Vdc_con_integ + Kp_Vdc_con    * Err_Vdc_con;              //PI 제어기

    a = Vdc_con_real_max;
    Vdc_con_real = ((Vdc_con_out > a) ? a : (Vdc_con_out < 0) ? 0 : Vdc_con_out);
    Idc_ref = Vdc_con_real;
}


void voltage_control_inv3()
{
    float   a;

    Ip_ref_ff   = 0.;
    Err_Vdc_inv = Vdc_ref_inv   - Vdc_flt;

    Ip_ref_integ    += Ki_VC    * T_2ms * (Err_Vdc_inv - Ka_VC  * (Ip_ref_out - Ip_ref_real) );
    Ip_ref_out      = Ip_ref_integ - Kp_VC  * Vdc_flt  + Ip_ref_ff;                 //IP 제어기
//    Ip_ref_out      = Ip_ref_integ - Kp_VC  * Vdc_flt  + Iqe;                 //IP 제어기
//  Ip_ref_out      = Ip_ref_integ + Kp_VC  * Err_Vdc_inv  + Ip_ref_ff;              //PI 제어기

    a = Ip_ref_real_max;
    Ip_ref_real = ((Ip_ref_out > a) ? a : (Ip_ref_out < -a) ? -a : Ip_ref_out);

#if 1
    Ip_ref = Ip_ref_real;
#endif

#if 0
    Ip_ref = - Ip_ref_real;
#endif

#if 0
    //only test mode
    Ip_ref = Ip_ref_real_max;
#endif

    flag_voltage_control_inv3 = 1;

}

void making_current_ref()
{
    if(Flag_gating_inv == 1)
    {
        Iqe_ref = Ip_ref;                 // real power
    }
    else
    {
        Iqe_ref = 0.;
    }

    if(Flag_buildup == 1)
    {
        Ide_ref = Ide_ref_input;          //reactive power
    }
    else
    {
        Ide_ref = 0.;
    }
}

void making_current_ref_harmonic()
{
    if(Flag_gating_inv == 1)
    {
        Iqe_ref = Ip_ref;                 // real power
    }
    else
    {
        Iqe_ref = 0.;
    }


    if(Flag_buildup == 1)
    {
        Ide_ref = Ide_ref_input;          //reactive power
    }
    else
    {
        Ide_ref = 0.;
    }

    Ide_ref_n   = 0;
    Iqe_ref_n   = 0;
}



/*--------------------------------------*/
/*  call soft_Ip_ref_real_max()         */
/*--------------------------------------*/
void soft_Ip_ref_real_max(void)
{
    float   Ip_ref_real_max_ref_temp;
    float   Ip_ref_real_max_limit_max;

    //0.5s 설정으로 구현 목표.
    //1차 지연 check = 100ms 이후 진행 AC_MC_On seq
    if(Flag_gating_inv == 1)
//  if(Flag_gating_inv_test == 1)   //only test mode
    {
        //2차 지연 check = 100ms 이후 진행
        //0.1s Ip_ref_init
        Ip_ref_real_max_init                = Ip_ref_real_max_init_input;   //init setting

        Ip_ref_real_max_cnt++;
        if(Ip_ref_real_max_cnt >= 50)
        {
            Ip_ref_real_max_cnt = 50;

            Ip_ref_real_max_limit_max       = Ip_ref_real_max_input - Ip_ref_real_max;

            //3차 지연 = soft 진행
            //5A,   280A, 56, 2ms x 56 = 112ms
            if(Ip_ref_real_max_limit_max        == 0)
            {
                Ip_ref_real_max_ref_temp    = Ip_ref_real_max_input;
            }
            else if(Ip_ref_real_max_limit_max   >= Ip_ref_real_max_step)
            {
                Ip_ref_real_max_ref_temp    = Ip_ref_real_max + Ip_ref_real_max_step;
            }
            else if(Ip_ref_real_max_limit_max   <= -Ip_ref_real_max_step)
            {
                Ip_ref_real_max_ref_temp    = Ip_ref_real_max - Ip_ref_real_max_step;
            }
            else
            {
                Ip_ref_real_max_ref_temp    = Ip_ref_real_max;
            }

            Ip_ref_real_max                 = Ip_ref_real_max_ref_temp;

            if(Ip_ref_real_max          <= Ip_ref_real_max_min)
            {
                Ip_ref_real_max             = Ip_ref_real_max_min;
            }
            else if(Ip_ref_real_max     >= Ip_ref_real_max_max)
            {
                Ip_ref_real_max             = Ip_ref_real_max_max;
            }
        }
        else
        {
            Ip_ref_real_max                 = Ip_ref_real_max_init; //init setting
        }
    }
    else
    {
        Ip_ref_real_max_init                = Ip_ref_real_max_init_input;
        Ip_ref_real_max                     = Ip_ref_real_max_input;
        Ip_ref_real_max_cnt                 = 0;
    }
}
