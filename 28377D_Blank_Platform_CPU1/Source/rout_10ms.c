//###############################################################################################################
// 파일명      : rout_10ms.c
// 회사명      : G-Philos
// 작성날짜  : 2020.12.17
// 작성자      : KYJ-PC
// 수정날짜  : 2021.01.04
// 수정자      : Lee Sang Cheol
// 설명         : 10ms routine
//###############################################################################################################

#include "Define.h"

void rout_10ms()
{
    if(time_check_cnt == 7)   LED1_ON;

//    Send_Dac_Data((char)_ch, Esa, (char)_on_off, (int)_ofs, (int)_max);
    rout_10ms_count++;
#ifdef _BLACKBOX

    Check_bootloader_wake();
    //Get_Edit_Addr_Info();

    if (IPCRtoLFlagBusy(IPC_FLAG17) == 1)
    {
        BB_List_ctrl_select();
        IPCRtoLFlagAcknowledge(IPC_FLAG17);
    }

    Get_Scipermisson_fromcpu2();
    Check_Log_Eeprom();
#endif
    if(rout_10ms_count >= 1000)
    {
        rout_10ms_count = 0;
    }

/*--------------------------------------*/
/*  Digital Input                       */
/*--------------------------------------*/
    digital_input();

/*--------------------------------------*/
/*  command process                     */
/*--------------------------------------*/
    command_process();          // commands from C_SELF

/*--------------------------------------*/
/*  Digital Ounput                      */
/*--------------------------------------*/
    digital_output();

/*--------------------------------------*/
/*  RS232 A port TX                     */
/*--------------------------------------*/
    serial_modbus_10ms_a();

/*--------------------------------------*/
/*  RS232 B port TX                     */
/*--------------------------------------*/
    serial_modbus_10ms();

/*--------------------------------------*/
/*  EEPROM write                        */
/*--------------------------------------*/
    Write_EEPROM_code();

/*--------------------------------------*/
/*  Freq out, low, high check           */
/*--------------------------------------*/
    if(Mode_system == TEST_MODE)
    {
        Freq_low_high_test();
    }
    else
    {
        Freq_low_high();
    }



/*----------------------------------------------*/
/*  call time fuction                           */
/*  T_10ms = (?) check need                     */
/*  100ms                                       */
/*----------------------------------------------*/
    if ((Cnt_T_100ms--) == 0)
    {
        Flag_T_100ms = 1;
        Cnt_T_100ms = Set_T_100ms - 1;
    }

    if(time_check_cnt == 7)   LED1_OFF;

}


void digital_input()
{

// check #1 : redefine need
// lsc_step 1 DI output basic test
// EX_DI check, no action(open) = 1, action(short) = 0
// 1.   빌드 및 예뮬레이터 연결 후 다운로딩
// 2.   DI1_input   = 0(short)    -> 1(open)
// 3.   DI2_input   = 0(short)    -> 1(open)
// 4.   DI3_input   = 0(short)    -> 1(open)
// 5.   DI4_input   = 0(short)    -> 1(open)
// 6.   DI5_input   = 0(short)    -> 1(open)
// 7.   DI6_input   = 0(short)    -> 1(open)
// 8.   DI7_input   = 0(short)    -> 1(open)
// 9.   DI8_input   = 0(short)    -> 1(open)
// 6.   DI9_input   = 0(short)    -> 1(open)
// 7.   DI10_input  = 0(short)    -> 1(open)
// 8.   DI11_input  = 0(short)    -> 1(open)
// 9.   DI12_input  = 0(short)    -> 1(open)

// 10.   Conector_1_2_3_input  = 0(connection)    -> 1(disconnection)

// DI1  = Run/stop
// DI2  = not
// DI3  = not
// DI4  = Over Temp err
// DI5  = Over Temp err
// DI6  = not
// DI7  = not
// DI8  = not
// DI9  = not
// DI10 = not
// DI11 = not
// DI12 = not

// Conector_1_2_3 = DSP & INF Connector Connection check


    DI1_input   = DI_1;
    DI2_input   = DI_2;
    DI3_input   = DI_3;
    DI4_input   = DI_4;
    DI5_input   = DI_5;
    DI6_input   = DI_6;
    DI7_input   = DI_7;
    DI8_input   = DI_8;
    DI9_input   = DI_9;
    DI10_input  = DI_10;
    DI11_input  = DI_11;
    DI12_input  = DI_12;

    Conector_1_2_3_input  = Conector_1_2_3;

// DI1 = Run/stop
    if(OP_MODE == 1)
    {
        if(DI1_input == 0)
        {
            DI_input    = 1;
            Cnt_DI1     = 0;

//            if(Flag_charge == 1)
//            {
//                DI_Run_Stop = 1;
//            }
//            else
//            {
//                DI_Run_Stop = 0;
//            }

            if(Flag_charge==1)
            {
                if(DI_Run_Stop_cnt++ >= 5)  //50ms delay
                {
                    DI_Run_Stop_cnt = 0;
                    DI_Run_Stop = 1;
                }
            }
            else
            {
                DI_Run_Stop = 0;
                DI_Run_Stop_cnt = 0;
            }

        }

        else
        {
            Cnt_DI1++;
            DI_input = 0;
            if(Cnt_DI1 >= 3)
            {
                DI_Run_Stop = 0;
                Cnt_DI1     = 0;
            }
            DI_Run_Stop_cnt = 0;
        }
    }
    else if(OP_MODE == 3)
    {
        if(DI1_input == 0)
        {
            DI_input    = 1;
            Cnt_DI1     = 0;
#if 0
            if(Flag_charge == 1)
            {
                DI_Run_Stop = 1;
            }
            else
            {
                DI_Run_Stop = 0;
            }
#endif
        }
        else
        {
            Cnt_DI1++;
            DI_input = 0;
            if(Cnt_DI1 >= 3)
            {
//              DI_Run_Stop = 0;
                Cnt_DI1     = 0;
            }

//            Idc_ref_com     = 0.;
//            Idc_ref_comp_input = 0;
        }


#if 1
        if((Flag_charge == 1) && (Run_Stop_com == 55))
        {
//            DI_Run_Stop = 1;

            if(DI_Run_Stop_cnt++ >= 5)  //50ms delay
            {
                DI_Run_Stop_cnt = 0;
                DI_Run_Stop = 1;
            }
//            Idc_ref_comp = Idc_ref_comp_input;
        }

        else if(Run_Stop_com == 99)
        {
            DI_Run_Stop = 0;
//            Idc_ref_com = 0.;
//            Idc_ref_comp_input = 0;
//            Idc_ref_comp = Idc_ref_comp_input;
        }
        else
        {
            DI_Run_Stop = 0;
            DI_Run_Stop_cnt = 0;
//            Idc_ref_com = 0.;
            Idc_ref_comp_input = 0;
//            Idc_ref_comp = Idc_ref_comp_input;
            Run_Stop_com = 99;
        }
#endif
    }
    else
    {
//        OP_MODE         = 1;
        OP_MODE         = 3;
        DI_input        = 0;
        DI_Run_Stop     = 0;
        DI_Run_Stop_cnt = 0;
        Run_Stop_com    = 99;
//      Idc_ref_com     = 0.;
//      Idc_ref_comp_input = 0;
        Idc_ref_comp_input = 0;
//        Idc_ref_comp = Idc_ref_comp_input;
    }
}


void digital_output()
{

// check #1 : redefine need
// lsc_step 1 DO output basic test
// 1.   빌드 및 예뮬레이터 연결 후 다운로딩
// 2.   Mode_system_input                   = 0         -> 1
// 3.   DO1_output(DC_MC)                   = 0(off)    -> 1(on)
// 4.   DO2_output(AC_MC)                   = 0(off)    -> 1(on)
// 5.   DO3_output(FAN_MC)                  = 0(off)    -> 1(on)
// 6.   DO4_output(EX_24V)                  = 0(off)    -> 1(on)
// 7.   DO5_output(Fault)(Red/위)           = 0(off)    -> 1(on)
// 8.   DO6_output(Run/Stop)(Green/아래)    = 0(off)    -> 1(on)
// 9.   DO7_output(Relay)(주황/위)          = 0(off)    -> 1(on)
// 10.  DO8_output(Power)(주황/아래)        = 0(off)    -> 1(on)
// 11.  DO9_output(Not)                     = 0(off)    -> 1(on)
// 12.  DO10_output(Not)                    = 0(off)    -> 1(on)
// 13.  DO11_output(Not)                    = 0(off)    -> 1(on)
// 14.  DO12_output(Not)                    = 0(off)    -> 1(on)

// 15.  DO13_output(Not)                    = 0(no check)    -> 1(no check)
// 16.  DO14_output(Not)                    = 0(no check)    -> 1(no check)
// 17.  DO15_output(Not)                    = 0(no check)    -> 1(no check)
// 18.  DO16_output(Not)                    = 0(no check)    -> 1(no check)

// 19.  LED1_output(CPU1 check)             = 0(off)    -> 1(on)
// 20.  LED2_output(CPU2 check)             = 0(off)    -> 1(on)


// TEST_MODE = 1
    if(Mode_system == TEST_MODE)
    {
        if(DO1_output == 1)         DO_1_ON;
        else                        DO_1_OFF;

        if(DO2_output == 1)         DO_2_ON;
        else                        DO_2_OFF;

        if(DO3_output == 1)         DO_3_ON;
        else                        DO_3_OFF;

       //EX24V ON/OFF 테스트 진행하지 않음.
       //테스트 진행 시 제어전원 on/off 진행됨.
#if 0
        if(DO4_output == 1)         DO_4_ON;
        else                        DO_4_OFF;
#endif

        if(DO5_output == 1)         DO_5_ON;
        else                        DO_5_OFF;

        if(DO6_output == 1)         DO_6_ON;
        else                        DO_6_OFF;

        if(DO7_output == 1)         DO_7_ON;
        else                        DO_7_OFF;

        if(DO8_output == 1)         DO_8_ON;
        else                        DO_8_OFF;

        if(DO9_output == 1)         DO_9_ON;
        else                        DO_9_OFF;

        if(DO10_output == 1)        DO_10_ON;
        else                        DO_10_OFF;

        if(DO11_output == 1)        DO_11_ON;
        else                        DO_11_OFF;

        if(DO12_output == 1)        DO_12_ON;
        else                        DO_12_OFF;

        if(DO13_output == 1)        DO_13_ON;
        else                        DO_13_OFF;

        if(DO14_output == 1)        DO_14_ON;
        else                        DO_14_OFF;

        if(DO15_output == 1)        DO_15_ON;
        else                        DO_15_OFF;

        if(DO16_output == 1)        DO_16_ON;
        else                        DO_16_OFF;

#if 0
        //CPU1 = CPU1 test LED
        if(LED1_output == 1)        LED_1_ON;
        else                        LED_1_OFF;
#endif

#if 0
        //CPU2 = CPU2 test LED
        if(LED2_output == 1)        LED_2_ON;
        else                        LED_2_OFF;
#endif
    }

    else
    {
        //DC_MC
        if(Flag_charge == 1)        DO_1_ON;
        else                        DO_1_OFF;

        //AC_MC
        if(Flag_charge_inv == 1)    DO_2_ON;
        else                        DO_2_OFF;

        //FAN_MC
        if(Flag_Fan == 1)           DO_3_ON;
        else                        DO_3_OFF;

        //EX24V_MC
//        if(Flag_EX24V == 1)         DO_4_ON;
//        else                        DO_4_OFF;

        //Faut_Lamp
        if(Flag_Fault == 1)         DO_5_ON;
        else                        DO_5_OFF;

        //Run_Stop_Lamp
        if(Flag_Run_Stop == 1)      DO_6_ON;
        else                        DO_6_OFF;

        //Ready_Lamp
//        if(Flag_Ready == 1)         DO_7_ON;
//        else                        DO_7_OFF;

        //Power_Lamp
 //       if(Flag_Power == 1)         DO_8_ON;
        if(control_power_check_flag == 1)         DO_8_ON;
        else                        DO_8_OFF;

#if 0
        //Test DO9
        if(DO9_output == 1)         DO_9_ON;
        else                        DO_9_OFF;

        //Test DO10
        if(DO10_output == 1)        DO_10_ON;
        else                        DO_10_OFF;

        //Test DO11
        if(DO11_output == 1)        DO_11_ON;
        else                        DO_11_OFF;

        //Test DO12
        if(DO12_output == 1)        DO_12_ON;
        else                        DO_12_OFF;

        //Test DO13
        if(DO13_output == 1)        DO_13_ON;
        else                        DO_13_OFF;

        //Test DO14
        if(DO14_output == 1)        DO_14_ON;
        else                        DO_14_OFF;

        //Test DO15
        if(DO15_output == 1)        DO_15_ON;
        else                        DO_15_OFF;

        //Test DO16
        if(DO16_output == 1)        DO_16_ON;
        else                        DO_16_OFF;

        //Test LED1
        if(LED1_output == 1)        LED_1_ON;
        else                        LED_1_OFF;

        //Test LED2
        if(LED2_output == 1)        LED_2_ON;
        else                        LED_2_OFF;
#endif
    }
}


void command_process()
{
    //Mode_system 0: Real control
    //Mode_system 1: MC on/off test
    //Mode_system 2: AC/DC Converter test control seq

//  if(Vin_flt <= Vin_MC_OFF_level)
    if(Vin_flt <= Vin_min)
    {
        DO_4_OFF;         //Flag_EX24V - off = 외부 제어전원 공급 가능
// DC/DC SMPS 입력/출력 = 110V(40~160V) Input / 24V output
    }


// TEST_MODE2 = 2
    if(Mode_system == TEST_MODE2)
    {
        if( (System_fault == NORMAL) && (Flag_offset == 3) )
        {
            if(DI_input == 1)
            {
                Flag_charge_test        = 1;
                Flag_charge_inv_test    = 1;
                Flag_gating_inv_test    = 1;
                Flag_charge = Flag_charge_test;
            }
            else
            {
                Flag_charge_test        = 0;
                Flag_charge_inv_test    = 0;
                Flag_gating_inv_test    = 0;
                Flag_charge = Flag_charge_test;
            }

            if(Vin_flt >= Vin_MC_ON_level)
            {
                if(MC_on_cnt++ >= 600)
                {
                    MC_on_cnt = 0;
                    //Flag_charge_test = test mode
                    Flag_charge = Flag_charge_test;
                }
            }
            else if(Vin_flt <= Vin_MC_OFF_level)
            {
                MC_on_cnt = 0;
                if(Vin_flt <= (Vin_MC_OFF_level - 1))
                {
                    Flag_charge =0;
                }
            }
            else
            {
                MC_on_cnt = 0;
            }

            if((Vdc_flt >= AC_MC_ON_level) && (Flag_charge_inv_test == 1))
            {
                Flag_charge_inv = 1;
            }
            else
            {
                Flag_charge_inv = 0;
                Cnt_gating_inv  = 0;
            }

            if(Flag_gating_inv_test == 1)
            {
                if((Cnt_gating_inv++ >= 20) && (Flag_charge_inv == 1))
                {
                    Flag_gating_inv = 1;
                    Cnt_gating_inv = 0;
                    Flag_Fan = 1;
                    Cnt_Fan1_OFF=0;

                    if(++Cnt_buildup>2&&(Vdc_ref_con >= Vdc_ref_con_set))
                    {
                        Flag_buildup=0;
                        Fault_save =1;
                    }
                    else
                    {
                        Flag_buildup=1;
                        //Flag_Fan =0;
                    }
                }
            }

            else
            {
                Flag_gating_inv=0;
                Flag_buildup=1;
                Cnt_buildup=0;
                //Flag_Fan=0;
                if(Cnt_Fan1_OFF++ >= 100)
                {
                    Flag_Fan        = 0;
                    Cnt_Fan1_OFF    = 0;
                }
            }

        }

        else
        {

            Flag_gating_test    = 0;
            Flag_gating_con_test = 0;
            Flag_gating_inv_test = 0;

            Flag_gating         = 0;
            Flag_gating_inv     = 0;

//          Flag_gating_inv_VF  = 0;

            Flag_charge         = 0;
            Flag_charge_inv     = 0;
            Flag_Fan            = 0;
            Flag_Ch_Vdc         = 0;

            MC_on_cnt           = 0;
            Cnt_Fan1_OFF        = 0;
            Cnt_gating_inv      = 0;
        }

        if((System_fault == NORMAL) && (control_power_check_flag == 1))
        {
//            INV_status = 5;
            INV_status = 6;
        }
        else if((Flag_gating_inv == 1) && (Flag_buildup == 0))
        {
//            INV_status = 3;
            INV_status = 1;
        }
        else if((Flag_gating_inv == 1) && (Flag_buildup == 1))
        {
//            INV_status = 2;
            INV_status = 7;
        }
        else if((Flag_charge_inv == 1) && (Flag_gating_inv==0))
        {
//            INV_status = 1;
            INV_status = 0;
        }
        else if(System_fault == FAULT)
        {
            INV_status = 3;
            INV_status = 4;
        }
        else
        {
 //           INV_status = 0;
            INV_status = 5;
        }
    }
    else
    {
        if( (System_fault==NORMAL)&&(Flag_offset==3) )
        {

            if(Vin_flt >= Vin_MC_ON_level)
            {
                if(MC_on_cnt++ >= 600)
                {
                    MC_on_cnt   = 0;
                    Flag_charge = 1;

#if 0
                    if(Flag_Grid_err == 1)
                    {
                        DO_4_ON;         //Flag_EX24V - on = 외부 제어전원 공급 차단
                    }
#endif

                }
            }
            else if(Vin_flt <= Vin_MC_OFF_level)
            {
                MC_on_cnt   = 0;

                if(Vin_flt <= (Vin_MC_OFF_level - 1))
                {
                    Flag_charge =0;
                }
            }


            if((Vdc_flt >= AC_MC_ON_level) && (Flag_gating == 1))
            {
                Flag_charge_inv = 1;
            }

            else if(Vdc_flt <= AC_MC_OFF_level)
            {
                Flag_charge_inv = 0;
                Cnt_gating_inv  = 0;
            }
#if 0
            else if(Flag_gating == 0)
            {
                Flag_charge_inv = 0;
                Cnt_gating_inv  = 0;
            }
#endif
            else
            {
                Cnt_gating_inv = 0;
            }

            if((Cnt_gating_inv++ >= 20) && (Flag_charge_inv==1))
            {
                Flag_gating_inv = 1;
                Cnt_gating_inv  = 0;
                Flag_Fan        = 1;

                if((++Cnt_buildup > 2) && (Vdc_ref_con >= Vdc_ref_con_set))
                {
                    Flag_buildup    = 0;
//                    Fault_save      = 1;
                }
                else
                {
                    Flag_buildup    = 1;
                    Flag_Fan        = 0;
                }
            }

            else if(DI_Run_Stop == 0)
            {
                Flag_gating_inv = 0;
                Flag_buildup    = 1;
                Cnt_buildup     = 0;
                Flag_Fan        = 0;
            }
        }

        else
        {
            Flag_gating         = 0;
            Flag_gating_inv     = 0;

//          Flag_gating_inv_VF  = 0;

            Flag_charge         = 0;
            Flag_charge_inv     = 0;
            Flag_Fan            = 0;
            Flag_Ch_Vdc         = 0;

            MC_on_cnt           = 0;
            Cnt_Fan1_OFF        = 0;
            Cnt_gating_inv      = 0;
        }

        if((Flag_charge == 0) && (System_fault == NORMAL) && (control_power_check_flag == 1))
        {
//            INV_status = 5;
            INV_status = 6;
        }
        else if((Flag_charge == 1) && (Flag_gating_inv == 1) && (Flag_buildup == 0))
        {
//            INV_status = 3;
//            INV_status = 6;
            INV_status = 1;
        }
        else if((Flag_charge == 1) && (Flag_gating == 1))
        {
//            INV_status = 2;
            INV_status = 7;

        }
        else if((Flag_charge == 1) && (Flag_gating == 0))
        {
//            INV_status = 1;
            INV_status = 0;
        }
        else if(System_fault == FAULT)
        {
            INV_status = 3;
            INV_status = 4;
        }
        else
        {
//          INV_status = 0;
            INV_status = 5;

        }
    }

    if(System_fault == FAULT)
    {
        if(control_power_check_flag == 1)
        {
            Flag_Fault = 1;
        }
    }
    else
    {
        Flag_Fault = 0;
    }

//    if(INV_status == 3)
//    if(INV_status == 6)
    if(INV_status == 1)
    {
        Flag_Run_Stop = 1;
    }
    else
    {
        Flag_Run_Stop = 0;
    }
}



void Freq_low_high()
{

    if(Flag_Grid_err == 1)
    {
        if((Cnt_freq1_max == 0) && (Cnt_freq2_max == 0))
        {
            Fault_SW    |= SFT_FREQ_HIGH;
        }
    }

    Cnt_freq_max        = Cnt_freq1_max + Cnt_freq2_max;
//  Cnt_freq_max_sum    = Cnt_freq_max  + Cnt_freq_max_old1 + Cnt_freq_max_old2 + Cnt_freq_max_old3 + Cnt_freq_max_old4 + Cnt_freq_max_old5;
    Cnt_freq_max_sum    = Cnt_freq_max  + Cnt_freq_max_old1 + Cnt_freq_max_old2 + Cnt_freq_max_old3 + Cnt_freq_max_old4 + Cnt_freq_max_old5 + Cnt_freq_max_old6 + Cnt_freq_max_old7;

    Cnt_freq_max_old7   = Cnt_freq_max_old6;
    Cnt_freq_max_old6   = Cnt_freq_max_old5;
    Cnt_freq_max_old5   = Cnt_freq_max_old4;
    Cnt_freq_max_old4   = Cnt_freq_max_old3;
    Cnt_freq_max_old3   = Cnt_freq_max_old2;
    Cnt_freq_max_old2   = Cnt_freq_max_old1;
    Cnt_freq_max_old1   = Cnt_freq_max;

//  Freq_source_period =  0.083333333   * (Cnt_freq_max_sum + 0.5)  * Tsamp;
    Freq_source_period =  0.0625        * (Cnt_freq_max_sum + 0.5)  * Tsamp;

    Freq_out            = 1. / Freq_source_period;

    if(Freq_out >= 80)
    {
        if(Cnt_Freq_out++ > 500)
        {
            Theta_old       = 0;
            Err_Vde         = 0;
            Cnt_Freq_out    = 0;
            Theta_comp_out  = 0;
        }
    }
    else
    {
        Cnt_Freq_out    = 0;
    }


    if(Flag_Grid_err == 1)
    {
        if(Flag_charge == 1)
        {
            if(Freq_out > Freq_high)
            {
                if(Freq_out > (Freq_high + 0.2))
                {
                    Fault_SW    |= SFT_FREQ_HIGH;
                }
                else if(++Cnt_Freq_high >= 10)
                {
                    Fault_SW    |= SFT_FREQ_HIGH;
                }
            }
            else if(Freq_out < Freq_low)
            {
                if(Freq_out < (Freq_low - 0.2))
                {
                    Fault_SW    |= SFT_FREQ_LOW;
                }
                else if(++Cnt_Freq_low >= 10)
                {
                    Fault_SW|=SFT_FREQ_LOW;
                }
            }
            else
            {
                Cnt_Freq_high   = 0;
                Cnt_Freq_low    = 0;
            }
        }
    }


    if(Flag_Act_islanding == 88)
    {
        Freq_rate = Freq_out + (Freq_out    - Freq_rate_init)   * (Freq_shift_ratio + Freq_jump);
        Freq_rate = ((Freq_rate > 64.0) ? 64.0 : (Freq_rate < 56.0) ? 56.0 : Freq_rate);

        if(Freq_jump_cnt++ >= 4)
        {
            Freq_jump       = 0.;
            Freq_jump_cnt   = 0.;
        }
    }

    else if(Flag_Act_islanding == 77)
    {
        Freq_rate = Freq_out + (Freq_out    - Freq_rate_init)   * (Freq_shift_ratio + Freq_jump);
        Freq_rate = ((Freq_rate > 64.0) ? 64.0 : (Freq_rate < 56.0) ? 56.0 : Freq_rate);

        if(Freq_jump_cnt++ >= 4)
        {
            Freq_jump       = 0.;
            Freq_jump_cnt   = 0.;
        }
    }

    else
    {
        Freq_rate   = Freq_shift_init;
    }


    We_rate = PI_MPY_2 * Freq_rate;
    We      = PI_MPY_2 * Freq_rate;

}



void Freq_low_high_test()
{
    if(Flag_Grid_err == 1)
    {
        if((Cnt_freq1_max == 0) && (Cnt_freq2_max == 0))
        {
            Fault_SW    |= SFT_FREQ_HIGH;
        }
    }

    Cnt_freq_max        = Cnt_freq1_max + Cnt_freq2_max;
//  Cnt_freq_max_sum    = Cnt_freq_max  + Cnt_freq_max_old1 + Cnt_freq_max_old2 + Cnt_freq_max_old3 + Cnt_freq_max_old4 + Cnt_freq_max_old5;
    Cnt_freq_max_sum    = Cnt_freq_max  + Cnt_freq_max_old1 + Cnt_freq_max_old2 + Cnt_freq_max_old3 + Cnt_freq_max_old4 + Cnt_freq_max_old5 + Cnt_freq_max_old6 + Cnt_freq_max_old7;

    Cnt_freq_max_old7   = Cnt_freq_max_old6;
    Cnt_freq_max_old6   = Cnt_freq_max_old5;
    Cnt_freq_max_old5   = Cnt_freq_max_old4;
    Cnt_freq_max_old4   = Cnt_freq_max_old3;
    Cnt_freq_max_old3   = Cnt_freq_max_old2;
    Cnt_freq_max_old2   = Cnt_freq_max_old1;
    Cnt_freq_max_old1   = Cnt_freq_max;

//  Freq_source_period =  0.083333333   * (Cnt_freq_max_sum + 0.5)  * Tsamp;
    Freq_source_period =  0.0625        * (Cnt_freq_max_sum + 0.5)  * Tsamp;

    Freq_out            = 1. / Freq_source_period;

    if(Freq_out >= 80)
    {
        if(Cnt_Freq_out++ > 500)
        {
            Theta_old       = 0;
            Err_Vde         = 0;
            Cnt_Freq_out    = 0;
            Theta_comp_out  = 0;
        }
    }
    else
    {
        Cnt_Freq_out    = 0;
    }

#if 0
    //test mode no define
    if(Flag_charge == 1)
    {
        if(Freq_out > Freq_high)
        {
            if(Freq_out > (Freq_high + 0.2))
            {
                Fault_SW    |= SFT_FREQ_HIGH;
            }
            else if(++Cnt_Freq_high >= 10)
            {
                Fault_SW    |= SFT_FREQ_HIGH;
            }
        }
        else if(Freq_out < Freq_low)
        {
            if(Freq_out < (Freq_low - 0.2))
            {
                Fault_SW    |= SFT_FREQ_LOW;
            }
            else if(++Cnt_Freq_low >= 10)
            {
                Fault_SW|=SFT_FREQ_LOW;
            }
        }
        else
        {
            Cnt_Freq_high   = 0;
            Cnt_Freq_low    = 0;
        }
    }
#endif

    if(Flag_Act_islanding == 88)
    {
        Freq_rate = Freq_out + (Freq_out    - Freq_rate_init)   * (Freq_shift_ratio + Freq_jump);
        Freq_rate = ((Freq_rate > 64.0) ? 64.0 : (Freq_rate < 56.0) ? 56.0 : Freq_rate);

        if(Freq_jump_cnt++ >= 4)
        {
            Freq_jump       = 0.;
            Freq_jump_cnt   = 0.;
        }
    }

    else if(Flag_Act_islanding == 77)
    {
        Freq_rate = Freq_out + (Freq_out    - Freq_rate_init)   * (Freq_shift_ratio + Freq_jump);
        Freq_rate = ((Freq_rate > 64.0) ? 64.0 : (Freq_rate < 56.0) ? 56.0 : Freq_rate);

        if(Freq_jump_cnt++ >= 4)
        {
            Freq_jump       = 0.;
            Freq_jump_cnt   = 0.;
        }
    }

    else
    {
        Freq_rate   = Freq_shift_init;
    }


    We_rate = PI_MPY_2 * Freq_rate;
    We      = PI_MPY_2 * Freq_rate;

}
