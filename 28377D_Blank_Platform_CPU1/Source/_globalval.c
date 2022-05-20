//###############################################################################################################
// 파일명      : _globalval.c
// 회사명      : G-Philos
// 작성날짜  : 2020.12.17
// 작성자      : KYJ-PC
// 수정날짜  : 2021.01.04
// 수정자      : Lee Sang Cheol
// 설명         : 전역 변수 (extern포함) 초기화
//###############################################################################################################

#include "Define.h"




union   bytecode     w2b, b2w;              /* EEPROM access variables      */

int     Eum_enable          = 1;   // only test
//int     Eum_enable          = 0;     // real setting

int lsc_build_check = 0;

int download_check = 0;     // 0 : init, 0x77 : download run, 0x88 : download run check



/*--------------------------------------*/
/*  signal generator                    */
/*--------------------------------------*/
float Esa_gen = 0.0;
float Esb_gen = 0.0;
float Esc_gen = 0.0;

float Ia_gen = 0.0;
float Ib_gen = 0.0;
float Ic_gen = 0.0;

float f_gen_target = 60.0; /* external control variable : frequency */
float i_gen_target = 0.0; /* external control variable : current */
float A_ref_target = 1.5;

float Vin_max_gen = 110.0;
float Vdc_max_gen = 47.0;
float Vac_max_gen = 305.0;
float Iac_max_gen = 165.0;
float Peff_gen = 0.95;

float t_gen = 0.0;

float Ta_inv_float = 0;
float Tb_inv_float = 0;
float Tc_inv_float = 0;

long  ERR_mask = ((1 << 7) | (1 << 9) | (1 << 10)); /* ERR8, ERR10, ERR11 */

float sig_test0 = 0;
float sig_test1 = 0;
float sig_test2 = 0;
float sig_test3 = 0;
float sig_test4 = 0;
float sig_test5 = 0;

/*--------------------------------------*/
/*  serial communication                */
/*--------------------------------------*/
float   dummy           = 0.0f;
int     idummy          = 0;
void    *data_ptr[DATA_PTR_MAX];

int     Ptr_byte                = 0;       // code pointer
int     Ptr_code_EEPROM         = 0;       // code pointer
int     Ptr_code_EEPROM2        = 120;     // code pointer
int     Enable_EEPROM_write     = 0;       // code pointer
int     Enable_EEPROM_write2    = 0;       // code pointer
int     Enable_EEPROM_read      = 0;
int     init_EEPROM_write       = 0;
int     Init_scale              = 0;
int     Init_offset             = 0;
int     Init_gain               = 0;
int     Err_EEPROM              = 0;
int     Flag_Read_eeprom        = 0;
int     Wait_cnt[8] = {0, 0, 0, 0, 0, 0, 0, 0};


int     Flag_EEPROM_init_cnt    = 0;

/*----------------------------*/
/*    com commands            */
/*----------------------------*/
float   Fault_reset_com = 99.;
float   Run_Stop_com    = 99.;

float   Idc_ref_com     = 0.;
float   OP_MODE_com     = 1.;

//int     OP_MODE         = 1;  //Analog setting
//int     OP_MODE         = 3;  //Com setting
float     OP_MODE         = 1;  //Analog setting
//float     OP_MODE         = 3;  //Com setting

/*----------------------------*/
/*    commands                */
/*----------------------------*/
//int     INV_SW_VER       = 100;
int     INV_SW_VER       = 101;

//int     INV_status       = 0;
int     INV_status       = 5;

int     Index_user_input = 0;


/*----------------------------*/
/*    sci commands            */
/*----------------------------*/
//int     Flag_scia_cpu1_cpu2 = 2;        //CPU2 : default
//int     Flag_scia_cpu1_cpu2 = 1;        //CPU1 : RS232A FC HMI define
//float     Flag_scia_cpu1_cpu2 = 2;      //CPU2 : default
float     Flag_scia_cpu1_cpu2 = 1;        //CPU1 : RS232A FC HMI define
int     Flag_scia = 1;        //CPU1 : RS232A FC HMI define



/*--------------------------------------*/
/*  test count                          */
/*--------------------------------------*/
int     m_cnt       = 0;

/*--------------------------------------*/
/*  Digital Input                       */
/*--------------------------------------*/
int     DI1_input       = 1;
int     DI2_input       = 1;
int     DI3_input       = 1;
int     DI4_input       = 1;
int     DI5_input       = 1;
//int     DI5_input       = 0;        //NC - normal, NO - Over Temp Fault
int     DI6_input       = 1;
//int     DI6_input       = 0;        //NC - normal, NO - Over Temp Fault
int     DI7_input       = 1;
int     DI8_input       = 1;
int     DI9_input       = 1;
int     DI10_input      = 1;
int     DI11_input      = 1;
int     DI12_input      = 1;

int     Conector_1_2_3_input      = 1;

int     DI_input        = 0;
int     DI_Run_Stop     = 0;
int     DI_Run_Stop_cnt = 0;
int     Cnt_DI1         = 0;



/*--------------------------------------*/
/*  Digital Output                      */
/*--------------------------------------*/
int     DO1_output      = 0;
int     DO2_output      = 0;
int     DO3_output      = 0;
int     DO4_output      = 0;
int     DO5_output      = 0;
int     DO6_output      = 0;
int     DO7_output      = 0;
int     DO8_output      = 0;
int     DO9_output      = 0;
int     DO10_output     = 0;
int     DO11_output     = 0;
int     DO12_output     = 0;
int     DO13_output     = 0;
int     DO14_output     = 0;
int     DO15_output     = 0;
int     DO16_output     = 0;

int     LED1_output     = 0;
int     LED2_output     = 0;

/*--------------------------------------*/
/*  Digital Output Flag                 */
/*--------------------------------------*/
int     Mode_system                 = 0;
int     Mode_system_input           = 0;
//int     Mode_system_input           = 1;

int     Mode_pwm                    = 0;    // (1)SVPWM,(0)SPWM
int     Mode_pwm_input              = 0;
//int     Mode_pwm_input              = 1;



int     Mode_test                   = 0;

int     Flag_charge_test            = 0;
int     Flag_charge_inv_test        = 0;
int     Flag_Fan_test               = 0;
int     Flag_EX24V_test             = 0;
int     Flag_Fault_test             = 0;
int     Flag_Run_Stop_test          = 0;
int     Flag_Power_test             = 0;
int     Flag_Ch_Vdc_test            = 0;

int     Flag_charge                 = 0;
int     Flag_charge_inv             = 0;
int     Flag_Fan                    = 0;
int     Flag_EX24V                  = 0;
int     Flag_Fault                  = 0;
int     Flag_Run_Stop               = 0;
int     Flag_Ready                  = 0;
int     Flag_Power                  = 0;
int     Flag_Ch_Vdc                 = 0;

float   Flag_charge_float           = 0;
float   MC_on_cnt_float             = 0;

int     MC_on_cnt                   = 0;
int     Cnt_Fan1_OFF                = 0;

int     control_power_check_flag    = 0;
int     control_power_check_cnt     = 0;

/*--------------------------------------*/
/*  Fault check                         */
/*--------------------------------------*/
int     System_fault                = 0;
int     System_fault_latch          = 0;

int     Fault_HW                    = 0;
int     Fault_HW_new                = 0;
int     Fault_HW_old                = 0;
int     Fault_HW_latch              = 0;

int     Fault_TZ                    = 0;

int     Fault_EPWM1_TZ1             = 0;
int     Fault_EPWM2_TZ1             = 0;
int     Fault_EPWM3_TZ1             = 0;
int     Fault_EPWM4_TZ2             = 0;
int     Fault_EPWM5_TZ2             = 0;
int     Fault_EPWM6_TZ2             = 0;
int     Fault_EPWM7_TZ3             = 0;
int     Fault_EPWM8_TZ3             = 0;
int     Fault_EPWM9_TZ3             = 0;
int     Fault_EPWM10_TZ4            = 0;
int     Fault_EPWM11_TZ4            = 0;
int     Fault_EPWM12_TZ4            = 0;

long    Fault_SW                    = 0;
int     Fault_check_cnt             = 0;
long    Fault_SW_latch              = 0;

int     Fault_history[3]    = {0, 0, 0};

int     History[10][20]     = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int     EnbReturnTime       = 5;
int     CNT_Reset           = 0;

int     Fault_reset         = 0;                  // S/W reset command
int     Fault_save          = 1;

int     Fault_reset_DI_cnt         = 0;                  // S/W reset command
int     Fault_reset_com_cnt        = 0;                  // S/W reset command


/*--------------------------------------*/
/*  PWM Output                          */
/*--------------------------------------*/
int     DRV2_ADC_EPWM_ADCSOCA        = 0;
int     DRV2_ADC_EPWM_ADCSOCB        = 0;

int     Flag_pwm_1P                  = 0;
int     Flag_pwm_1N                  = 0;
int     Flag_pwm_2P                  = 0;
int     Flag_pwm_2N                  = 0;
int     Flag_pwm_3P                  = 0;
int     Flag_pwm_3N                  = 0;

#if 1
int     Flag_pwm_con_test1           = 0;
int     Flag_pwm_inv_test1           = 0;
int     Flag_pwm_inv_test2           = 0;
int     Flag_pwm_inv_test3           = 0;
int     Flag_pwm_inv_test4           = 0;
#endif

#if 0
int     Flag_pwm_con_test1           = 1;
int     Flag_pwm_inv_test1           = 1;
int     Flag_pwm_inv_test2           = 1;
int     Flag_pwm_inv_test3           = 1;
int     Flag_pwm_inv_test4           = 1;
#endif


int     Flag_gating                 = 0;
int     Flag_gating_con             = 0;
int     Flag_gating_inv             = 0;  // (1)gate-on,(1)gate-off internal command

int     Flag_gating_inv_VF          = 0;  // (1)gate-on,(1)gate-off internal command



int     Flag_gating_test_cnt_max    = 4;

int     Flag_gating_test_cnt        = 0;
int     Flag_gating_test            = 0;
int     Flag_gating_con_test        = 0;
int     Flag_gating_inv_test        = 0;

int     Flag_gating_VF_TEST         = 0;
int     Flag_gating_VF              = 0;

int     Flag_buildup                = 0;

//int     Flag_current_control_inv3   = 0;
int     Flag_current_control_inv3   = 1;

int     Cnt_gating_inv              = 0;

int   Ta_con_test1                 = 50;
//int   Ta_con_test1                 = 100;
//int   Ta_con_test1                 = 150;
//int     Ta_con_test1                 = 200;
//int   Ta_con_test1                 = 300;
//int   Ta_con_test1                 = 350;

int     Tb_con_test1                 = 400;
int     Tc_con_test1                 = 500;

//int   EPwm1_CMP_test               = 0;

#if 1
//int     EPwm1_CMP_test               = 4;   //시험 후 적용 필요 : 6.5kW DCDC 저항 부하(1.2kW 시험 효율 0.4% 개선 시험)
int     EPwm1_CMP_test               = 1;   //시험 후 적용 필요 : 6.5kW 포화전류 언발란스 조정
//int     EPwm1_CMP_test               = 0;   //시험 후 적용 필요 : 6.5kW DCDC 저항 부하(1.2kW 시험 효율 0.4% 개선 시험)
int     EPwm2_CMP_test               = 0;
#endif

#if 0
int     EPwm1_CMP_test               = 0;   //시험 후 적용 필요 : 6.5kW DCDC 저항 부하(1.2kW 시험 효율 0.4% 개선 시험)
int     EPwm2_CMP_test               = 140;
#endif


int     EPwm3_CMP_test               = 0;

int     Ta_inv_test1                 = 300;
int     Tb_inv_test1                 = 400;
int     Tc_inv_test1                 = 500;

int     Ta_inv_test2                 = 300;
int     Tb_inv_test2                 = 400;
int     Tc_inv_test2                 = 500;

int     Ta_inv_test3                 = 300;
int     Tb_inv_test3                 = 400;
int     Tc_inv_test3                 = 500;

int     Ta_inv_test4                 = 300;
int     Tb_inv_test4                 = 400;
int     Tc_inv_test4                 = 500;


/*--------------------------------------*/
/*  gating control(svpwm)               */
/*--------------------------------------*/
#if 1
int     Mode_gating_input   = 1;        // (0)half gate,(1)full gate
int     Mode_gating         = 1;
#endif

int     Mode_SOCAPRD   = 1;        // 1 = 1번 1회 epwm adc event
//int     Mode_SOCAPRD   = 2;        // 2 = 2번 1회 epwm adc event

#if 0
int     Mode_gating_input   = 0;        // (0)half gate,(1)full gate
int     Mode_gating         = 0;
#endif

int     Mode_gating_con_input   = 0;     // (0)half gate,(1)full gate
int     Mode_gating_con         = 0;

float   T_dead_input        = 1.;    // generated dead-time[usec]

//float   T_dead_con_input    = 0.1;    // generated dead-time[usec]
float   T_dead_con_input    = 0.4;    // generated dead-time[usec]
//float   T_dead_con_input    = 1.;    // generated dead-time[usec]
//float   T_dead_con_input    = 3.;    // generated dead-time[usec]

float   T_dead_comp_input   = 1.;    // compensated dead-time[usec]
float   T_dead_onoff_input  = 1.;    // gate-drive off-delay comp.[usec]

float   T_dead              = 0;     // generated dead-time[sec]
float   T_dead_con          = 0;     // generated dead-time[sec]
float   T_dead_comp         = 0;     // compensated dead-time[sec]
float   T_dead_onoff        = 0;     // gate-drive off-delay comp.[sec]

int     T_dead_CNT          = 0;     // generated dead-time[count]
int     T_dead_con_CNT      = 0;     // generated dead-time[count]
int     T_dead_comp_CNT     = 0;     // compensated dead-time[count]
int     T_dead_onoff_CNT    = 0;     // gate-drive off-delay comp.[count]

/*--------------------------------------*/
/*  gating control(svpwm)               */
/*--------------------------------------*/
int     CNT_max             = 0;
int     CNT_max_2           = 0;
int     CNT_max_5           = 0;
int     CNT_max_10          = 0;
int     CNT_max_20          = 0;
int     CNT_max_30          = 0;
int     CNT_max_40          = 0;

int     CNT_max_50          = 0;
int     CNT_max_60          = 0;
int     CNT_max_70          = 0;
int     CNT_max_80          = 0;
int     CNT_max_90          = 0;
int     CNT_max_95          = 0;
int     CNT_max_98          = 0;

int     CNT_max_con         = 0;
int     CNT_max_con_2       = 0;
int     CNT_max_con_5       = 0;
int     CNT_max_con_10      = 0;
int     CNT_max_con_20      = 0;
int     CNT_max_con_30      = 0;
int     CNT_max_con_40      = 0;
int     CNT_max_con_49_5    = 0;
int     CNT_max_con_50      = 0;
int     CNT_max_con_60      = 0;
int     CNT_max_con_70      = 0;
int     CNT_max_con_80      = 0;
int     CNT_max_con_90      = 0;
int     CNT_max_con_95      = 0;
int     CNT_max_con_98      = 0;

int     CNT_max_con_dead_50     = 0;
int     T_dead_con_CNT_50       = 0;

/*--------------------------------------*/
/*  ERR Intput                          */
/*--------------------------------------*/
int     EPwm_TZ1_IntCount            = 0;
int     EPwm_TZ2_IntCount            = 0;
int     EPwm_TZ3_IntCount            = 0;

int     EPwm1_TZ1_IntCount           = 0;
int     EPwm2_TZ1_IntCount           = 0;
int     EPwm3_TZ1_IntCount           = 0;
int     EPwm4_TZ2_IntCount           = 0;
int     EPwm5_TZ2_IntCount           = 0;
int     EPwm6_TZ2_IntCount           = 0;
int     EPwm7_TZ3_IntCount           = 0;
int     EPwm8_TZ3_IntCount           = 0;
int     EPwm9_TZ3_IntCount           = 0;
int     EPwm10_TZ4_IntCount          = 0;
int     EPwm11_TZ4_IntCount          = 0;
int     EPwm12_TZ4_IntCount          = 0;

/*--------------------------------------*/
/*  ADC Intput                          */
/*--------------------------------------*/
#if 1
//test ADC1 ~ ADC18
float   ADC1                     = 0.;
float   ADC1_flt                 = 0.;
float   ADC1_old                 = 0.;
float   ADC1_flt_sum             = 0.;
float   ADC1_flt_avg             = 0.;
float   ADC1_flt_avg_sum         = 0.;
float   ADC1_flt_avg_avg         = 0.;
float   ADC1_offset_input        = 0.;
float   ADC1_offset              = 0.;
float   Scale_12bit_ADC1_input   = 2048.;
float   Scale_12bit_ADC1_ratio   = 100.;
float   Scale_12bit_ADC1         = 0.;

float   ADC2                     = 0.;
float   ADC2_flt                 = 0.;
float   ADC2_old                 = 0.;
float   ADC2_flt_sum             = 0.;
float   ADC2_flt_avg             = 0.;
float   ADC2_flt_avg_sum         = 0.;
float   ADC2_flt_avg_avg         = 0.;
float   ADC2_offset_input        = 0.;
float   ADC2_offset              = 0.;
float   Scale_12bit_ADC2_input   = 2048.;
float   Scale_12bit_ADC2_ratio   = 100.;
float   Scale_12bit_ADC2         = 0.;

float   ADC3                     = 0.;
float   ADC3_flt                 = 0.;
float   ADC3_old                 = 0.;
float   ADC3_flt_sum             = 0.;
float   ADC3_flt_avg             = 0.;
float   ADC3_flt_avg_sum         = 0.;
float   ADC3_flt_avg_avg         = 0.;
float   ADC3_offset_input        = 0.;
float   ADC3_offset              = 0.;
float   Scale_12bit_ADC3_input   = 2048.;
float   Scale_12bit_ADC3_ratio   = 100.;
float   Scale_12bit_ADC3         = 0.;

float   ADC4                     = 0.;
float   ADC4_flt                 = 0.;
float   ADC4_old                 = 0.;
float   ADC4_flt_sum             = 0.;
float   ADC4_flt_avg             = 0.;
float   ADC4_flt_avg_sum         = 0.;
float   ADC4_flt_avg_avg         = 0.;
float   ADC4_offset_input        = 0.;
float   ADC4_offset              = 0.;
float   Scale_12bit_ADC4_input   = 2048.;
float   Scale_12bit_ADC4_ratio   = 100.;
float   Scale_12bit_ADC4         = 0.;

float   ADC5                     = 0.;
float   ADC5_flt                 = 0.;
float   ADC5_old                 = 0.;
float   ADC5_flt_sum             = 0.;
float   ADC5_flt_avg             = 0.;
float   ADC5_flt_avg_sum         = 0.;
float   ADC5_flt_avg_avg         = 0.;
float   ADC5_offset_input        = 0.;
float   ADC5_offset              = 0.;
float   Scale_12bit_ADC5_input   = 2048.;
float   Scale_12bit_ADC5_ratio   = 100.;
float   Scale_12bit_ADC5         = 0.;

float   ADC6                     = 0.;
float   ADC6_flt                 = 0.;
float   ADC6_old                 = 0.;
float   ADC6_flt_sum             = 0.;
float   ADC6_flt_avg             = 0.;
float   ADC6_flt_avg_sum         = 0.;
float   ADC6_flt_avg_avg         = 0.;
float   ADC6_offset_input        = 0.;
float   ADC6_offset              = 0.;
float   Scale_12bit_ADC6_input   = 2048.;
float   Scale_12bit_ADC6_ratio   = 100.;
float   Scale_12bit_ADC6         = 0.;

float   ADC7                     = 0.;
float   ADC7_flt                 = 0.;
float   ADC7_old                 = 0.;
float   ADC7_flt_sum             = 0.;
float   ADC7_flt_avg             = 0.;
float   ADC7_flt_avg_sum         = 0.;
float   ADC7_flt_avg_avg         = 0.;
float   ADC7_offset_input        = 0.;
float   ADC7_offset              = 0.;
float   Scale_12bit_ADC7_input   = 2048.;
float   Scale_12bit_ADC7_ratio   = 100.;
float   Scale_12bit_ADC7         = 0.;

float   ADC8                     = 0.;
float   ADC8_flt                 = 0.;
float   ADC8_old                 = 0.;
float   ADC8_flt_sum             = 0.;
float   ADC8_flt_avg             = 0.;
float   ADC8_flt_avg_sum         = 0.;
float   ADC8_flt_avg_avg         = 0.;
float   ADC8_offset_input        = 0.;
float   ADC8_offset              = 0.;
float   Scale_12bit_ADC8_input   = 2048.;
float   Scale_12bit_ADC8_ratio   = 100.;
float   Scale_12bit_ADC8         = 0.;

float   ADC9                     = 0.;
float   ADC9_flt                 = 0.;
float   ADC9_old                 = 0.;
float   ADC9_flt_sum             = 0.;
float   ADC9_flt_avg             = 0.;
float   ADC9_flt_avg_sum         = 0.;
float   ADC9_flt_avg_avg         = 0.;
float   ADC9_offset_input        = 0.;
float   ADC9_offset              = 0.;
float   Scale_12bit_ADC9_input   = 2048.;
float   Scale_12bit_ADC9_ratio   = 100.;
float   Scale_12bit_ADC9         = 0.;

float   ADC10                    = 0.;
float   ADC10_flt                = 0.;
float   ADC10_old                = 0.;
float   ADC10_flt_sum            = 0.;
float   ADC10_flt_avg            = 0.;
float   ADC10_flt_avg_sum        = 0.;
float   ADC10_flt_avg_avg        = 0.;
float   ADC10_offset_input       = 0.;
float   ADC10_offset             = 0.;
float   Scale_12bit_ADC10_input  = 2048.;
float   Scale_12bit_ADC10_ratio  = 100.;
float   Scale_12bit_ADC10        = 0.;

float   ADC11                    = 0.;
float   ADC11_flt                = 0.;
float   ADC11_old                = 0.;
float   ADC11_flt_sum            = 0.;
float   ADC11_flt_avg            = 0.;
float   ADC11_flt_avg_sum        = 0.;
float   ADC11_flt_avg_avg        = 0.;
float   ADC11_offset_input       = 0.;
float   ADC11_offset             = 0.;
float   Scale_12bit_ADC11_input  = 2048.;
float   Scale_12bit_ADC11_ratio  = 100.;
float   Scale_12bit_ADC11        = 0.;

float   ADC12                    = 0.;
float   ADC12_flt                = 0.;
float   ADC12_old                = 0.;
float   ADC12_flt_sum            = 0.;
float   ADC12_flt_avg            = 0.;
float   ADC12_flt_avg_sum        = 0.;
float   ADC12_flt_avg_avg        = 0.;
float   ADC12_offset_input       = 0.;
float   ADC12_offset             = 0.;
float   Scale_12bit_ADC12_input  = 2048.;
float   Scale_12bit_ADC12_ratio  = 100.;
float   Scale_12bit_ADC12        = 0.;

float   ADC13                    = 0.;
float   ADC13_flt                = 0.;
float   ADC13_old                = 0.;
float   ADC13_flt_sum            = 0.;
float   ADC13_flt_avg            = 0.;
float   ADC13_flt_avg_sum        = 0.;
float   ADC13_flt_avg_avg        = 0.;
float   ADC13_offset_input       = 0.;
float   ADC13_offset             = 0.;
float   Scale_12bit_ADC13_input  = 2048.;
float   Scale_12bit_ADC13_ratio  = 100.;
float   Scale_12bit_ADC13        = 0.;

float   ADC14                    = 0.;
float   ADC14_flt                = 0.;
float   ADC14_old                = 0.;
float   ADC14_flt_sum            = 0.;
float   ADC14_flt_avg            = 0.;
float   ADC14_flt_avg_sum        = 0.;
float   ADC14_flt_avg_avg        = 0.;
float   ADC14_offset_input       = 0.;
float   ADC14_offset             = 0.;
float   Scale_12bit_ADC14_input  = 2048.;
float   Scale_12bit_ADC14_ratio  = 100.;
float   Scale_12bit_ADC14        = 0.;

float   ADC15                    = 0.;
float   ADC15_flt                = 0.;
float   ADC15_old                = 0.;
float   ADC15_flt_sum            = 0.;
float   ADC15_flt_avg            = 0.;
float   ADC15_flt_avg_sum        = 0.;
float   ADC15_flt_avg_avg        = 0.;
float   ADC15_offset_input       = 0.;
float   ADC15_offset             = 0.;
float   Scale_12bit_ADC15_input  = 2048.;
float   Scale_12bit_ADC15_ratio  = 100.;
float   Scale_12bit_ADC15        = 0.;

float   ADC16                    = 0.;
float   ADC16_flt                = 0.;
float   ADC16_old                = 0.;
float   ADC16_flt_sum            = 0.;
float   ADC16_flt_avg            = 0.;
float   ADC16_flt_avg_sum        = 0.;
float   ADC16_flt_avg_avg        = 0.;
float   ADC16_offset_input       = 0.;
float   ADC16_offset             = 0.;
float   Scale_12bit_ADC16_input  = 2048.;
float   Scale_12bit_ADC16_ratio  = 100.;
float   Scale_12bit_ADC16        = 0.;

float   ADC17                    = 0.;
float   ADC17_flt                = 0.;
float   ADC17_old                = 0.;
float   ADC17_flt_sum            = 0.;
float   ADC17_flt_avg            = 0.;
float   ADC17_flt_avg_sum        = 0.;
float   ADC17_flt_avg_avg        = 0.;
float   ADC17_offset_input       = 0.;
float   ADC17_offset             = 0.;
float   Scale_16bit_ADC17_input  = 32768.;
float   Scale_16bit_ADC17_ratio  = 100.;
float   Scale_16bit_ADC17        = 0.;

float   ADC18                    = 0.;
float   ADC18_flt                = 0.;
float   ADC18_old                = 0.;
float   ADC18_flt_sum            = 0.;
float   ADC18_flt_avg            = 0.;
float   ADC18_flt_avg_sum        = 0.;
float   ADC18_flt_avg_avg        = 0.;
float   ADC18_offset_input       = 0.;
float   ADC18_offset             = 0.;
float   Scale_16bit_ADC18_input  = 32768.;
float   Scale_16bit_ADC18_ratio  = 100.;
float   Scale_16bit_ADC18        = 0.;
#endif

#if 1
float   Vin                     = 0.;
float   Vin_flt                 = 0.;
float   Vin_old                 = 0.;
float   Vin_flt_sum             = 0.;
float   Vin_flt_avg             = 0.;
float   Vin_flt_avg_sum         = 0.;
float   Vin_flt_avg_avg         = 0.;
float   Vin_offset_input        = 0.;
float   Vin_offset              = 0.;
// Sensor : SV-VER2.1 (12.11.02), Rs = 200k, Rm = 200 ohm, Vs_max = 15V, V_max = 300.3, V_max real Sensing = 300.3
float   Scale_Vin_input         = 300.3;
float   Scale_Vin_ratio         = 100.;
float   Scale_Vin               = 0.;

float   Idc                     = 0.;
float   Idc_flt                 = 0.;
float   Idc_old                 = 0.;
float   Idc_flt_sum             = 0.;
float   Idc_flt_avg             = 0.;
float   Idc_flt_avg_sum         = 0.;
float   Idc_flt_avg_avg         = 0.;
float   Idc_offset_input        = 0.;
float   Idc_offset              = 0.;
// Sensor : STB-150LA(2000 : 1, 100ohm[150A]), Vs_max = 7.5V, I_max = 150, I_max setting = 150
float   Scale_Idc_input         = 150.;
float   Scale_Idc_ratio         = 100.;
float   Scale_Idc               = 0.;

float   Pin                     = 0.;

float   Vin_flt_avg_avg_abs = 0;
float   Idc_flt_avg_avg_abs = 0;
float   Pin_abs = 0;



float   A_ref                    = 0.;
float   A_ref_flt                = 0.;
float   A_ref_old                = 0.;
float   A_ref_flt_sum            = 0.;
float   A_ref_flt_avg            = 0.;
float   A_ref_flt_avg_sum        = 0.;
float   A_ref_flt_avg_avg        = 0.;
float   A_ref_offset_input       = 0.;
float   A_ref_offset             = 0.;
float   Scale_A_ref_input        = 7.5;
float   Scale_A_ref_ratio        = 100.;
float   Scale_A_ref              = 0.;

float   Vdc                     = 0.;
float   Vdc_flt                 = 0.;
float   Vdc_old                 = 0.;
float   Vdc_flt_sum             = 0.;
float   Vdc_flt_avg             = 0.;
float   Vdc_flt_avg_sum         = 0.;
float   Vdc_flt_avg_avg         = 0.;
float   Vdc_offset_input        = 0.;
float   Vdc_offset              = 0.;
// Sensor : SV-VER2.1 (12.11.02), Rs = 400k, Rm = 100 ohm, Vs_max = 15V, V_max = 1200.3, V_max real Sensing = 1200.3
float   Scale_Vdc_input         = 1200.3;
float   Scale_Vdc_ratio         = 100.;
float   Scale_Vdc               = 0.;

float   Esa                     = 0.;
float   Esa_flt                 = 0.;
float   Esa_old                 = 0.;
float   Esa_rms                 = 0.;
float   Esa_rms_sum             = 0.;
float   Esa_rms_avg             = 0.;
float   Esa_rms_avg_sum         = 0.;
float   Esa_rms_avg_avg         = 0.;
float   Esa_offset_input        = 0.;
float   Esa_offset              = 0.;
float   Esa_offset_sum          = 0.;
float   Esa_offset_comp_input   = 0.;
float   Esa_offset_comp         = 0.;
// Sensor : 380V/6V, Vs_max = 7.5V, V_max = 475, V_max real Sensing = 460.8

float   Scale_Esa_input         = 460.8;
//float   Scale_Esa_input         = -460.8;


float   Scale_Esa_ratio         = 100.;
float   Scale_Esa               = 0.;

float   Esb                     = 0.;
float   Esb_flt                 = 0.;
float   Esb_old                 = 0.;
float   Esb_rms                 = 0.;
float   Esb_rms_sum             = 0.;
float   Esb_rms_avg             = 0.;
float   Esb_rms_avg_sum         = 0.;
float   Esb_rms_avg_avg         = 0.;
float   Esb_offset_input        = 0.;
float   Esb_offset              = 0.;
float   Esb_offset_sum          = 0.;
float   Esb_offset_comp_input   = 0.;
float   Esb_offset_comp         = 0.;
// Sensor : 380V/6V, Vs_max = 7.5V, V_max = 475, V_max real Sensing = 460.8
float   Scale_Esb_input         = 460.8;
//float   Scale_Esb_input         = -460.8;


float   Scale_Esb_ratio         = 100.;
float   Scale_Esb               = 0.;

float   Esc                     = 0.;
float   Esc_flt                 = 0.;
float   Esc_old                 = 0.;
float   Esc_rms                 = 0.;
float   Esc_rms_sum             = 0.;
float   Esc_rms_avg             = 0.;
float   Esc_rms_avg_sum         = 0.;
float   Esc_rms_avg_avg         = 0.;
float   Esc_offset_input        = 0.;
float   Esc_offset              = 0.;
float   Esc_offset_sum          = 0.;
float   Esc_offset_comp_input   = 0.;
float   Esc_offset_comp         = 0.;
// Sensor : 380V/6V, Vs_max = 7.5V, V_max = 475, V_max setting = 460.8
float   Scale_Esc_input         = 460.8;
//float   Scale_Esc_input         = -460.8;



float   Scale_Esc_ratio         = 100.;
float   Scale_Esc               = 0.;

float   Eab                     = 0.;
float   Eab_flt                 = 0.;
float   Eab_old                 = 0.;
float   Eab_rms                 = 0.;
float   Eab_rms_sum             = 0.;
float   Eab_rms_avg             = 0.;
float   Eab_rms_avg_sum         = 0.;
float   Eab_rms_avg_avg         = 0.;
float   Eab_offset_input        = 0.;
float   Eab_offset              = 0.;
float   Eab_offset_sum          = 0.;
float   Eab_offset_comp_input   = 0.;
float   Eab_offset_comp         = 0.;
float   Scale_Eab_input         = 7.5;
float   Scale_Eab_ratio         = 100.;
float   Scale_Eab               = 0.;

float   Ebc                     = 0.;
float   Ebc_flt                 = 0.;
float   Ebc_old                 = 0.;
float   Ebc_rms                 = 0.;
float   Ebc_rms_sum             = 0.;
float   Ebc_rms_avg             = 0.;
float   Ebc_rms_avg_sum         = 0.;
float   Ebc_rms_avg_avg         = 0.;
float   Ebc_offset_input        = 0.;
float   Ebc_offset              = 0.;
float   Ebc_offset_sum          = 0.;
float   Ebc_offset_comp_input   = 0.;
float   Ebc_offset_comp         = 0.;
float   Scale_Ebc_input         = 7.5;
float   Scale_Ebc_ratio         = 100.;
float   Scale_Ebc               = 0.;

float   Eca                     = 0.;
float   Eca_flt                 = 0.;
float   Eca_old                 = 0.;
float   Eca_rms                 = 0.;
float   Eca_rms_sum             = 0.;
float   Eca_rms_avg             = 0.;
float   Eca_rms_avg_sum         = 0.;
float   Eca_rms_avg_avg         = 0.;
float   Eca_offset_input        = 0.;
float   Eca_offset              = 0.;
float   Eca_offset_sum          = 0.;
float   Eca_offset_comp_input   = 0.;
float   Eca_offset_comp         = 0.;
float   Scale_Eca_input         = 7.5;
float   Scale_Eca_ratio         = 100.;
float   Scale_Eca               = 0.;

float   Eabc_rms                = 0.;


float   Ia                      = 0.;
float   Ia_abs                  = 0.;
float   Ia_flt                  = 0.;
float   Ia_old                  = 0.;
float   Ia_rms                  = 0.;
float   Ia_rms_sum              = 0.;
float   Ia_rms_avg              = 0.;
float   Ia_rms_avg_sum          = 0.;
float   Ia_rms_avg_avg          = 0.;
float   Ia_offset_input         = 0.;
float   Ia_offset               = 0.;
float   Ia_offset_sum           = 0.;
float   Ia_offset_comp_input    = 0.;
float   Ia_offset_comp          = 0.;
// Sensor : STB-50HA(50A/4V), Vs_max = 7.5V, I_max = 93.75, I_max setting = -93.75
//float   Scale_Ia_input          = -93.75;       //100k
float   Scale_Ia_input          = -31.25;       //300k
//float   Scale_Ia_input          = 93.75;

float   Scale_Ia_ratio          = 100.;
float   Scale_Ia                = 0.;

float   Ib                      = 0.;
float   Ib_abs                  = 0.;
float   Ib_flt                  = 0.;
float   Ib_old                  = 0.;
float   Ib_rms                  = 0.;
float   Ib_rms_sum              = 0.;
float   Ib_rms_avg              = 0.;
float   Ib_rms_avg_sum          = 0.;
float   Ib_rms_avg_avg          = 0.;
float   Ib_offset_input         = 0.;
float   Ib_offset               = 0.;
float   Ib_offset_sum           = 0.;
float   Ib_offset_comp_input    = 0.;
float   Ib_offset_comp          = 0.;
// Sensor : STB-50HA(50A/4V), Vs_max = 7.5V, I_max = 93.75, I_max setting = -93.75
//float   Scale_Ib_input          = -93.75;   //100k
float   Scale_Ib_input          = -31.25;   //300k
//float   Scale_Ib_input          = 93.75;

float   Scale_Ib_ratio          = 100.;
float   Scale_Ib                = 0.;

float   Ic                      = 0.;
float   Ic_abs                  = 0.;
float   Ic_flt                  = 0.;
float   Ic_old                  = 0.;
float   Ic_rms                  = 0.;
float   Ic_rms_sum              = 0.;
float   Ic_rms_avg              = 0.;
float   Ic_rms_avg_sum          = 0.;
float   Ic_rms_avg_avg          = 0.;
float   Ic_offset_input         = 0.;
float   Ic_offset               = 0.;
float   Ic_offset_sum           = 0.;
float   Ic_offset_comp_input    = 0.;
float   Ic_offset_comp          = 0.;
// Sensor : STB-50HA(50A/4V), Vs_max = 7.5V, I_max = 93.75, I_max setting = -93.75
//float   Scale_Ic_input          = -93.75; //100k
float   Scale_Ic_input          = -31.25;   //300K
//float   Scale_Ic_input          = 93.75;

float   Scale_Ic_ratio          = 100.;
float   Scale_Ic                = 0.;

int     Cnt_rms                 = 0;
int     Cnt_rms_avg             = 0;
int     Cnt_rms_avg2            = 0;
#endif

float   INV_Vin                 = 0.;
float   INV_Vdc                 = 0.;
float   INV_Vdc_2               = 0.;

float   Tsamp_Inv_Vdc           = 0.;
//float   Tsamp_Inv_Vdc_gain      = 0.5;
float   Tsamp_Inv_Vdc_gain      = 1.;



/*--------------------------------------*/
/*  system parameters                   */
/*--------------------------------------*/
//6.5kW FC new setting
float   Pin_rate        = 7040.;
float   Vin_rate        = 110.;
float   Vin_max         = 160.;
float   Vin_max_80      = 0.;
float   Vin_min         = 82.;
float   Vin_min_2       = 2.;

float   Idc_rate        = 64.;
float   Idc_max         = 75.;
float   Idc_min         = 0.1;


float   Vdc_max         = 700.;

float   Pout_rate       = 6.5;             // rated power[KVA]
float   Va_rate         = 220.;            // single phase Voltage[Vrms]
float   Ia_rate         = 29.55;
float   Va_rate_peak    = 0.;              // peak of Va_rage[V]
float   Ia_rate_peak    = 0.;
float   Vl_rate         = 380.;            // line-to-line [Vrms]
float   Vl_rate_peak    = 0.;              // peak of Vl_rate[V]
float   Vs_rate         = 0.;              // phase[Vrms]
float   Vs_rate_peak    = 0.;              // peak of Vs_rate[V]
float   INV_Vs_rate_peak    = 0.;

float   Ic_rate         = 9.88;            // rated current[Arms] 3p 380V 10k
float   Ic_rate_peak    = 0.;              // peak of Is_rate[A]

//---- Setting value of Ratio (S/W Protection)-----//
float   OV_Vin_level    = 1.;
float   UV_Vin_level    = 1.;
float   OC_Idc_ratio    = 112.;            // over-current[%](of Idc_max)

float   OV_Vdc_level    = 0.;

float   OC_ratio        = 150.;            // over-current[%](of Ic_rate.peak)
float   OV_ratio_src    = 112.;            // source over voltage[%]
float   UV_ratio_src    = 87.;             // source under voltage[%]
float   INTER_ratio_src = 10.;             // source interruption[%]

float   OV_ratio_src_rms    = 112.;        // source over voltage[%]
float   UV_ratio_src_rms    = 87.;         // source under voltage[%]

//float   OL_ratio        = 110.;
float   OL_ratio        = 105.;

//-------- Setting value (S/W Protection)-------//
float   OV_set_Vin_test      = 0.;
float   UV_set_Vin_test      = 0.;
float   OC_Idc_set_test      = 0.;

float   OV_set_Vdc_test      = 0.;            // DC-link over voltage[V]
float   UV_set_Vdc_test      = 0.;              // DC-link under voltage[V]

float   OV_set_src_test      = 0.;
float   UV_set_src_test      = 0.;
float   INTER_set_src_test   = 0.;

float   OV_set_src_rms_test  = 0.;
float   UV_set_src_rms_test  = 0.;
float   OC_set_test          = 0.;


float   OV_set_Vin      = 0.;
float   UV_set_Vin      = 0.;
float   OC_Idc_set      = 0.;

float   OV_set_Vdc      = 700.;            // DC-link over voltage[V]
float   UV_set_Vdc      = 0.;              // DC-link under voltage[V]




float   OV_set_src      = 0.;              // source over voltage[V]
float   UV_set_src      = 0.;              // source under voltage[V]
float   INTER_set_src   = 0.;              // source0 interruption[V]
float   OV_set_src_rms  = 0.;              // source over voltage[V]
float   UV_set_src_rms  = 0.;              // source under voltage[V]

float   OV_set_Va       = 0.;
float   UV_set_Va       = 0.;

float   OC_set          = 0.;              // over-current[A]
float   OC_dc_set       = 0.5;
float   Overload_Pout   = 0.;

int     Cnt_OC_Ia       = 0;
int     Cnt_OC_Ib       = 0;
int     Cnt_OC_Ic       = 0;


int     Cnt_OC_Idc      = 0;
int     Cnt_OV_Vdc      = 0;
int     Cnt_UV_Vdc      = 0;
int     Cnt_OV_Vin      = 0;
int     Cnt_UV_Vin      = 0;
int     Cnt_OV_Va       = 0;
int     Cnt_UV_Va       = 0;

//int     Cnt_Freq_high   = 0;
//int     Cnt_Freq_low    = 0;

int     Cnt_source_check1   = 400;
int     Cnt_source_check2   = 0;
int     Cnt_source_check3   = 0;

float   OL_time_set     = 60.;
int     Cnt_overload    = 0;

//---- Setting value of Ratio (S/W operation)-----//

float   Vin_MC_ON_level     = 0.;
float   Vin_MC_OFF_level    = 0.;
float   AC_MC_ON_level      = 0.;
float   AC_MC_OFF_level     = 0.;

float   AC_MC_ON_ratio      = 110.;
float   AC_MC_OFF_ratio     = 85.;

/*--------------------------------------*/
/*  Converter controller variable       */
/*--------------------------------------*/
float   Kp_Vdc_con_input    = 1.5;
float   Ki_Vdc_con_input    = 3.;    //voltage control

//float   Kp_Idc_con_input    = 0.002;
//float   Ki_Idc_con_input    = 0.006; //current control

float   Kp_Idc_con_input    = 0.006;
float   Ki_Idc_con_input    = 0.0054; //current control

float   Kp_Vdc_con_ratio    = 100.;
float   Ki_Vdc_con_ratio    = 100.; //voltage control
float   Kp_Idc_con_ratio    = 100.;
float   Ki_Idc_con_ratio    = 100.; //current control

float   Kp_Vdc_con          = 0.;
float   Ki_Vdc_con          = 0.;
float   Ka_Vdc_con          = 1.;   //voltage control

float   Kp_Idc              = 0.;
float   Ki_Idc              = 0.;
float   Ka_Idc              = 1.;   //current control

int     Cnt_buildup             = 0;
float   Vdc_soft_ratio          = 0.003;
float   Vdc_ref_con_temp        = 0.;
float   Vdc_ref_con_set         = 670.;   //voltage control
float   Vdc_ref_con_set_input   = 670.;   //voltage control
float   Vdc_ref_con_set_level   = 30.;   //voltage control




float   Err_Vdc_con         = 0.;
float   Vdc_ref_con         = 0.;
float   Vdc_con_integ       = 0.;
float   Vdc_con_pro         = 0.;
float   Vdc_con_out         = 0.;
float   Vdc_con_ff          = 0.;
float   Vdc_con_real        = 0.;
float   Vdc_con_real_max    = 2.;   //voltage control

float   Idc_limit_con       = 0.;   //6741
float   Idc_ref_factor      = 20.;
float   Idc_ref_offset      = 0.;
float   Idc_ref_step        = 2.;

float   Idc_ref_Aref        = 0.;

float   Idc_ref_comp        = 0.;
float   Idc_ref_comp_input  = 0.;

float   Idc_ref_mode        = 0.;    //A_ref지령모드:0, Idc_ref통신모드:1
float   Idc_ref_mode_input  = 0.;    //A_ref지령모드:0, Idc_ref통신모드:1


int     CNT_ref_Err         = 0;

float   Kp_Idc_ref_Cf       = 0.;
//float   Kp_Idc_ref_Cf       = 0.5;
float   Idc_ref_Cf          = 0.;

float   Err_Idc             = 0.;
float   Idc_ref             = 0.;
float   Idc_integ           = 0.;
float   Idc_pro             = 0.;
float   Idc_out             = 0.;
float   Idc_real            = 0.;   //current control


//float   INV_Vin             = 0.;
float   Tsamp_INV_Vin       = 0.;   //current control

int     Ta_real_con         = 0;
int     Ta_con              = 0;

float   Ta_real_con_float   = 0;
float   Ta_con_float        = 0;

float   Ta_real_inv_float   = 0;
float   Tb_real_inv_float   = 0;
float   Tc_real_inv_float   = 0;


float   Fault_SW_float   = 0;

float   Imax_norm_float     = 333.0; /* A */
float   Vmax_norm_float     = 900.0; /* V */
float   Pmax_norm_float     = 300.0; /* kW */
float   Vref_target_float   = 0.0;
int     RunStopReset        = 0;


/*--------------------------------------*/
/*           V/F Operation              */
/*--------------------------------------*/
float   VF_vtg_max          = 311.;
float   VF_vtg_max_no_Vdc   = 0.8;

float   VF_time             = 20.; // Check!

float   VF_vtg              = 0.;
float   VF_vtg_off          = 0.;

float   VF_freq             = 0.;
float   VF_freq_off         = 60.;

float   VF_vtg_max_set      = 0.;
float   VF_freq_max         = 0.;

float   theta_VF            = 0.;

float   Sin_Theta_VF        = 0.;
float   Cos_Theta_VF        = 0.;


float   VF_freq2            = 0.;
float   VF_freq_off2        = 60.;
float   theta_VF2           = 0.;
float   Sin_Theta_VF2       = 0.;
float   Cos_Theta_VF2       = 0.;


/*--------------------------------------*/
/*  Inverter controller variable        */
/*--------------------------------------*/
//float   Lc_input        = 3.;              // inductance(input-side)[mH]:user
float   Lc_input        = 1.;              // inductance(input-side)[mH]:user

float   Lc              = 0.;              // inductance[H]
float   Rc              = 0.;

//float   Cdc_input       = 2350.;           // capacitance(DC-link)[uF]:user
float   Cdc_input       = 1700.;           // capacitance(DC-link)[uF]:user

float   Cdc             = 0.;              // capacitance(DC-link)[F]

float   Kp_VC           = 0.;
float   Ki_VC           = 0.;
float   Ka_VC           = 0.;           // voltage controller

float   Zeta_VC         = 1.;
float   Wn_VC           = 50.;

//float   Vdc_ref_set_init    = 300.;           // reference

float   Kp_Vdc_ratio        = 100.;
float   Ki_Vdc_inv_ratio    = 100.; //voltage control

//float   Wc_CC               = 2400.;          // current controller
//float   Wc_CC               = 1800.;          // current controller
//float   Wc_CC               = 1200.;          // current controller
float   Wc_CC                 = 800.;          // current controller
float   Wc_CC_D               = 800.;          // current controller


float   Alpha_CC            = 0.5;            // current controller
float   INV_Alpha_CC        = 2.;             // current controller

//float   K_cc[3]={0.,};
float   K_cc[6]={0.,};


float   Kp_ide_p            = 0.;
float   Ki_ide_p            = 0.;
float   Ka_ide_p            = 0.;

float   Kp_iqe_p            = 0.;
float   Ki_iqe_p            = 0.;
float   Ka_iqe_p            = 0.;

float   Kp_ide_n            = 0.;
float   Ki_ide_n            = 0.;
float   Ka_ide_n            = 0.;

float   Kp_iqe_n            = 0.;
float   Ki_iqe_n            = 0.;
float   Ka_iqe_n            = 0.;

//float   K_cc_ratio[3]       = {800., 0.1, 1.};         // 2008.01.31
//float   K_cc_ratio[3]       = {400., 10., 1.};         // 2008.01.31
//float   K_cc_ratio[3]       = {400., 10., 10.};         // 2008.01.31
//float   K_cc_ratio[3]       = {500., 10., 10.};         // 2008.01.31
//float   K_cc_ratio[3]       = {100., 100., 100.};         // 2008.01.31
float   K_cc_ratio[6]       = {100., 100., 100.,100., 100., 100.};         // 2008.01.31

float   Kp_ide_d_p          = 800.;
float   Ki_ide_d_p          = 0.1;
float   Ka_ide_d_p          = 1.;

float   Kp_iqe_q_p          = 800.;
float   Ki_iqe_q_p          = 0.1;
float   Ka_iqe_q_p          = 1.;

float   Kp_ide_d_n          = 800.;
float   Ki_ide_d_n          = 0.1;
float   Ka_ide_d_n          = 1.;

float   Kp_iqe_q_n          = 800.;
float   Ki_iqe_q_n          = 0.1;
float   Ka_iqe_q_n          = 1.;


float   Kp_Ia_ratio         = 100.;
float   Ki_Ia_ratio         = 100.;
//float   Ki_Ia_ratio         = 10.;

float   Kp_Ia_ratio_D       = 100.;
float   Ki_Ia_ratio_D       = 100.;
//float   Ki_Ia_ratio         = 10.;

float   Kp_ide_ratio_d_p    = 100.;
float   Ki_ide_ratio_d_p    = 100.;

float   Kp_iqe_ratio_q_p    = 100.;
float   Ki_iqe_ratio_q_p    = 100.;

float   Kp_ide_ratio_d_n    = 100.;
float   Ki_ide_ratio_d_n    = 100.;

float   Kp_iqe_ratio_q_n    = 100.;
float   Ki_iqe_ratio_q_n    = 100.;



float   Kp_iqe              = 0.;
float   Ki_iqe              = 0.;
float   Ka_iqe              = 0.;
float   Kp_ide              = 0.;
float   Ki_ide              = 0.;
float   Ka_ide              = 0.;

float   Kp_Vde_ff           = 1.;
float   Kp_Vqe_ff           = 1.;
//float   Kp_Vqe_ff           = 1.5;
//float   Kp_Vqe_ff           = 2.0;

float   Kp_Ide_ff           = 1.;
float   Kp_Iqe_ff           = -1.;

float   Ide_ref_Cf          = 0.;
float   Iqe_ref_Cf          = 0.;

float   Iqe_ref_Cf_add      = 0.;


float   Kp_Vde_ff_flt      = 0.;
float   Kp_Vqe_ff_flt      = 0.;
float   Kp_Iqe_ff_flt      = 0.;
float   Kp_Ide_ff_flt      = 0.;

float   K_cc_DX_CKIT_Err_Ide      = 0.;
float   K_cc_DX_CKIT_K_cc_CKA      = 0.;
float   K_cc_QX_CKIT_Err_Iqe      = 0.;
float   K_cc_QX_CKIT_K_cc_CKA      = 0.;

int   flag_voltage_control_inv3   = 0.;

int     voltage_control_inv3_cnt                 = 0;
int     voltage_control_inv3_cnt_max                 = 0;

float   Err_Vdc_inv         = 0.;
float   Vdc_ref_inv         = 640.;

int     Ref_con_inv_flag     = 0;

int     Vdc_ref_inv_flag     = 0;
//int     Vdc_ref_inv_flag     = 1;

float   Vdc_ref_inv_test     = 20.;

float   Vdc_ref_inv_input    = 640.;



float   Vdc_ref_set_inv     = 640.; //voltage control
float   Vdc_ref_inv_max     = 640.;

float   Vdc_ref_inv_ratio   = 120.; //voltage control

float   Vdc_inv_integ       = 0.;
float   Vdc_inv_pro         = 0.;
float   Vdc_inv_out         = 0.;
float   Vdc_inv_ff          = 0.;
float   Vdc_inv_real        = 0.;

float   Vdc_ref_set         = 640.;
//float   Vdc_ref_set_init    = 300.;           // reference
float   Vdc_ref_set_init    = 640.;           // reference

float   Ip_ref              = 0.;
float   Ip_ref_out          = 0.;
float   Ip_ref_real         = 0.;
float   Ip_ref_integ        = 0.;
float   Ip_ref_ff           = 0.;
float   Ip_ref_real_max     = 0.;
float   Ip_ref_ratio        = 115.;

float   Ip_ref_real_max_test    = 1.;
float   Ip_ref_real_max_input   = 1.;

float   Ip_ref_real_max_step    = 0.5;

float   Ip_ref_real_max_min = 1.;
float   Ip_ref_real_max_max = 20.;

float   Ip_ref_real_max_init_input = 1.;
float   Ip_ref_real_max_init = 1.;
int     Ip_ref_real_max_cnt = 0;
int     Flag_gating_inv_Ip_ref_real_max = 0;

float   Ip_ref_real_min=1.;
float   Ip_ref_real_min_input=1;

float   Ide_ref_real_max_input=0;
float   Ide_ref_real_max_input_inv=0;


float   pVfe1[3][M_CC]      = { {0.,}, };      // current controller

float   Vds_ref             = 0.;
float   Vqs_ref             = 0.;
float   Vde_ref             = 0.;
float   Vqe_ref             = 0.;

float   Va_ref              = 0.;
float   Vb_ref              = 0.;
float   Vc_ref              = 0.;

float   Vfds_ref            = 0.;
float   Vfqs_ref            = 0.;     // voltage limit of CC
float   Vfde_ref            = 0.;
float   Vfqe_ref            = 0.;

float   Vmax                = 0.;
float   Vmin                = 0.;
float   Vmax2               = 0.;
float   Vf_mag              = 0.;
float   Vf_mag2             = 0.;
int     Flag_volt_limit     = 0;
float   Pout                = 0.;

float   Vcon_alpha_p        = 0.;
float   Vcon_beta_p         = 0.;

float   Vcon_alpha_n        = 0.;
float   Vcon_beta_n         = 0.;

float   Vas_ref_p           = 0.;
float   Vbs_ref_p           = 0.;
float   Vcs_ref_p           = 0.;

float   Vas_ref_n           = 0.;
float   Vbs_ref_n           = 0.;
float   Vcs_ref_n           = 0.;

float   Van_ref             = 0.;
float   Vbn_ref             = 0.;
float   Vcn_ref             = 0.;

float   Vas_ref_SV          = 0;
float   Vbs_ref_SV          = 0;
float   Vcs_ref_SV          = 0;

float   Vmax_SV = 0;
float   Vmin_SV = 0;

float   Vsn_SV = 0;

//float   Van_ref = 0;
//float   Vbn_ref = 0;
//float   Vcn_ref = 0;

float   T0_check = 0;




float   Err_Ide             = 0.;
float   Err_Iqe             = 0.;

float   Ide_ref             = 0.;
float   Iqe_ref             = 0.;

float   Iqe_ref_old         = 0.;
float   Iqe_ref_flt         = 0.;

int     flag_Iqe_ref_flt    = 0;

//float   Iqe_ref_input_test  = 0.;
float   Iqe_ref_input_test  = -1.;

float   Iqe_ref_input       = 0.;
float   Ide_ref_input       = 0.;
//float   Ide_ref_Cf          = 0.;   // references

float   Ide_err_p           = 0.;
float   Ide_ref_integ_p     = 0.;
float   Ide_out_p           = 0.;
float   Ide_ref_p           = 0.;
float   Ide_cff_p           = 0.;
float   Ide_ref_out_p       = 0.;

float   Iqe_err_p           = 0.;
float   Iqe_ref_integ_p     = 0.;
float   Iqe_out_p           = 0.;
float   Iqe_ref_p           = 0.;
float   Iqe_cff_p           = 0.;
float   Iqe_ref_out_p       = 0.;

float   Ide_err_n           = 0.;
float   Ide_ref_integ_n     = 0.;
float   Ide_out_n           = 0.;
float   Ide_ref_n           = 0.;
float   Ide_ref_p_n         = 0.;
float   Ide_cff_n           = 0.;
float   Ide_ref_out_n       = 0.;

float   Iqe_err_n           = 0.;
float   Iqe_ref_integ_n     = 0.;
float   Iqe_out_n           = 0.;
float   Iqe_ref_n           = 0.;
float   Iqe_ref_p_n         = 0.;
float   Iqe_cff_n           = 0.;
float   Iqe_ref_out_n       = 0.;

float   Ide_ref_Cf_p        = 0.;
float   Ide_ref_Cf_n        = 0.;

float   Ka_ide_fb_p        = 0.;
float   Ka_iqe_fb_p        = 0.;
float   Ka_ide_fb_n        = 0.;
float   Ka_iqe_fb_n        = 0.;


int     Ta_inv              = 0;
int     Tb_inv              = 0;
int     Tc_inv              = 0;
int     Ta_real_inv         = 0;
int     Tb_real_inv         = 0;
int     Tc_real_inv         = 0;


float   Ta                  = 0.;
float   Tb                  = 0.;
float   Tc                  = 0.;

//int     Flag_over_modu      = 0;
float     Flag_over_modu      = 0;

int         Flag_over_check     = 0;
//int         Flag_over_check     = 1;



//float   Err_Ia=0.,Ia_ref=0.,Ip_ref=0.;//current control
float   Err_Ia=0.,Ia_ref=0.;//current control
float   Ia_pro=0.,Ia_integ=0., Ia_out=0.,Ia_real=0.;//current control

/*--------------------------------------*/
/*  Theta & sine/cosine variables       */
/*--------------------------------------*/
//int     mode_Va_PLL3        = 0;      //old
int     mode_Va_PLL3        = 1;        //new

float   Theta               = 0.;
float   Theta_n             = 0.;
float   Theta_C             = 0.;
float   Theta_C_n           = 0.;

float   Theta_old           = 0.;
float   Theta_comp3         = 0.;

float   Theta_comp_out      = 0.;
float   Err_theta_comp      = 0.;
float   Err_Vde_C           = 0.;

float   Sin_theta           = 0.;
float   Sin_theta_n         = 0.;
float   Sin_thetaT          = 0.;
float   Sin_theta_C         = 0.;
float   Sin_theta_C_n       = 0.;

float   Cos_theta           = 0.;
float   Cos_theta_n         = 0.;
float   Cos_thetaT          = 0.;
float   Cos_theta_C         = 0.;
float   Cos_theta_C_n       = 0.;

float   DA_Test1              = 0.;
float   DA_Test_K1            = 0.;

float   DA_Test2              = 0.;
float   DA_Test_K2            = 3.;

float   Sin_theta_90        = 0.;
float   Cos_theta_90        = 0.;
float   Sin_theta_C_90      = 0.;
float   Cos_theta_C_90      = 0.;

float   Sin_theta_k1        = 0.;
float   Cos_theta_k1        = 0.;
float   Sin_theta_n_k1      = 0.;
float   Cos_theta_n_k1      = 0.;

float   Sin_theta_k2        = 0.;
float   Cos_theta_k2        = 0.;
float   Sin_theta_n_k2      = 0.;
float   Cos_theta_n_k2      = 0.;

float   Sin_theta_k3        = 0.;
float   Cos_theta_k3        = 0.;
float   Sin_theta_n_k3      = 0.;
float   Cos_theta_n_k3      = 0.;


// 10kW 기존 동작 환경
#if 1
float   Kp_ang            = 0.0005;
float   Ki_ang            = 0.01;
#endif
// 6.5kW 신규 동작 환경
// 동작 시 문제 발생으로 인하여 게인 변경 진행함.
#if 0
float   Kp_ang              = 0.01;
float   Ki_ang              = 0.0011;
#endif

float   Err_Vde             = 0.;


/*--------------------------------------*/
/*  first order filters                 */
/*--------------------------------------*/
float   Freq_rate_init      = 60.;
float   We_rate_init        = 0.;

float   Freq_rate           = 60.;     // rated frequency[Hz]
float   We_rate             = 0.;      // angular frequency[rad/s]

float   We                  = 0.;      // angular frequency[rad/s]

float   Wgrid               = 0.;

float   La_APF_FRI          = 0.;
float   Lb_APF_FRI          = 0.;

//float   FL_ADC                  = 5000.;
float   FL_ADC              = 20.;
float   La_ADC              = 0.;
float   Lb_ADC              = 0.;

//float   FL_Vin              = 20.;
float   FL_Vin              = 5.;
float   La_Vin              = 0.;
float   Lb_Vin              = 0.;

float   FL_Idc              = 20.;
float   La_Idc              = 0.;
float   Lb_Idc              = 0.;

float   FL_A_ref            = 20.;
float   La_A_ref            = 0.;
float   Lb_A_ref            = 0.;

float   FL_Vdc              = 20.;
float   La_Vdc              = 0.;
float   Lb_Vdc              = 0.;

float   FL_Va               = 5000.;
float   La_Va               = 0.;
float   Lb_Va               = 0.;

float   FL_Ia               = 5000.;
float   La_Ia               = 0.;
float   Lb_Ia               = 0.;

float   FL_Iqe_ref          = 5000.;
float   La_Iqe_ref          = 0.;
float   Lb_Iqe_ref          = 0.;

float   FL_s_volt           = 360.;  // stationary source-voltage[Hz]
float   La_s_volt           = 0.;
float   Lb_s_volt           = 0.;

float   FL_e_volt           = 20.;   // Vdqe voltage[Hz]
float   La_e_volt           = 0.;
float   Lb_e_volt           = 0.;


/*--------------------------------------*/
/*  Overload                            */
/*--------------------------------------*/
float   Pinv_DQ         = 0.;
float   Pinv_DQ_sum     = 0.;
float   Pinv_DQ_avg     = 0.;
float   Pinv_DQ_avg_abs     = 0.;
float   PF_util         = 0.;
float   PF_util_avg     = 0.;
int     Cnt_OL          = 0;

/*--------------------------------------*/
/*  source voltages                     */
/*--------------------------------------*/
float   Vds                     = 0.;
//float   Vds_ref                 = 0.;
float   Vds_old                 = 0.;
float   Vds_flt                 = 0.;

float   Vqs                     = 0.;
//float   Vqs_ref                 = 0.;
float   Vqs_old                 = 0.;
float   Vqs_flt                 = 0.;

float   Vde                     = 0.;
float   Vde_C                   = 0.;
float   Vde_old                 = 0.;
float   Vde_old1                = 0.;
float   Vde_old_C               = 0.;
float   Vde_flt                 = 0.;
float   Vde_flt1                = 0.;
float   Vde_flt_C               = 0.;
float   Vde_sum                 = 0.;
float   Vde_avg                 = 0.;

float   Vqe                     = 0.;
float   Vqe_old                 = 0.;
float   Vqe_old1                = 0.;
float   Vqe_old_C               = 0.;
float   Vqe_flt                 = 0.;
float   Vqe_flt1                = 0.;
float   Vqe_flt_C               = 0.;
float   Vqe_sum                 = 0.;
float   Vqe_avg                 = 0.;

float   Vds_p                   = 0.;
float   Vds_n                   = 0.;
float   Vds_apf                 = 0.;

float   Vqs_p                   = 0.;
float   Vqs_n                   = 0.;
float   Vqs_apf                 = 0.;

float   Vde_p                   = 0.;
float   Vde_n                   = 0.;
float   Vde_L                   = 0.;

float   Vqe_p                   = 0.;
float   Vqe_n                   = 0.;
float   Vqe_L                   = 0.;

float   Vde_p_old                   = 0.;
float   Vde_n_old                   = 0.;
float   Vqe_p_old                   = 0.;
float   Vqe_n_old                   = 0.;

float   Vde_p_flt                   = 0.;
float   Vde_n_flt                   = 0.;
float   Vqe_p_flt                   = 0.;
float   Vqe_n_flt                   = 0.;

float   Vde_dc                  = 0.;
float   Vqe_dc                  = 0.;
float   Vde_dc_sum              = 0.;

float   Vsrc_dz                 = 1.;  // DZ[%] for polarity checking

int     Cnt_SEQ                 = 0;
int     POL_Vds                 = -1;
int     POL_Vqs                 = 1;    // polarity of Eds, Eqs
int     SEQ_Vsrc                = 1;    // Sequence : (1)pos, (-1)neg

float   Ids                     = 0.;
float   Ids_p                   = 0.;
float   Ids_n                   = 0.;
float   Ids_old                 = 0.;
float   Ids_apf                 = 0.;

float   Iqs                     = 0.;
float   Iqs_p                   = 0.;
float   Iqs_n                   = 0.;
float   Iqs_old                 = 0.;
float   Iqs_apf                 = 0.;

float   Ide                     = 0.;
float   Ide_p                   = 0.;
float   Ide_n                   = 0.;

float   Iqe                     = 0.;
float   Iqe_p                   = 0.;
float   Iqe_n                   = 0.;


float   Ide_p_old                   = 0.;
float   Ide_n_old                   = 0.;
float   Iqe_p_old                   = 0.;
float   Iqe_n_old                   = 0.;

float   Ide_p_flt                   = 0.;
float   Ide_n_flt                   = 0.;
float   Iqe_p_flt                   = 0.;
float   Iqe_n_flt                   = 0.;

float   Em                      = 0.;

float   Kp_PLL                  = 0.;
float   Ki_PLL                  = 0.;

float   Vde_err                 = 0.;
float   W_delta_intg            = 0.;
float   W_delta                 = 0.;

float   Theta_h                 = 0.;
//float   Wgrid                   = 0.;


float Ide_5th_p = 0., Iqe_5th_p = 0., Ide_5th_old_p = 0.,  Iqe_5th_old_p = 0.;
float Angle_Grid_p = 0., Ide_5th_flt_p = 0., Iqe_5th_flt_p = 0.;
float Ide_5th_n = 0., Iqe_5th_n = 0., Ide_5th_old_n = 0.,  Iqe_5th_old_n = 0.;
float Angle_Grid_n = 0., Ide_5th_flt_n = 0., Iqe_5th_flt_n = 0.;
float Idsp = 0., Iqsp = 0., Idsn = 0., Iqsn = 0.;


//float Fc_I_5th = 50., Wc_I_5th = 0., La_I_5th = 0., Lb_I_5th = 0.;
float Fc_I_5th = 60., Wc_I_5th = 0., La_I_5th = 0., Lb_I_5th = 0.;
//float Fc_I_5th = 1000., Wc_I_5th = 0., La_I_5th = 0., Lb_I_5th = 0.;

float  Ide_5th_err_p = 0.,  Iqe_5th_err_p = 0.;
float  Vde_5th_ref_fb_p = 0.,  Vqe_5th_ref_fb_p = 0.;
float  Vqe_5th_integ_p = 0.,   Vde_5th_integ_p = 0.;
float  Vqe_5th_ref_p = 0.,   Vde_5th_ref_p  = 0.;
float  Vqs_5th_ref_p = 0.,   Vds_5th_ref_p = 0.;

float  Ide_5th_err_n = 0.,  Iqe_5th_err_n = 0.;
float  Vde_5th_ref_fb_n = 0.,  Vqe_5th_ref_fb_n = 0.;
float  Vqe_5th_integ_n = 0.,   Vde_5th_integ_n = 0.;
float  Vqe_5th_ref_n = 0.,   Vde_5th_ref_n  = 0.;
float  Vqs_5th_ref_n = 0.,   Vds_5th_ref_n = 0.;

//float Kp_CC_Grid_comp_5th = 1., Ki_CC_Grid_comp_5th = 10;
float Kp_CC_Grid_comp_5th = 1., Ki_CC_Grid_comp_5th = 20;
//float Kp_CC_Grid_comp_5th = 1., Ki_CC_Grid_comp_5th = 1000;

float Va=0., Vb=0., Vc=0. ;
//float Ia_PLL3_harmonic_k = 2.;
//float Ia_PLL3_harmonic_k = 6.;
float Ia_PLL3_harmonic_k = 8.;



float Ide_5th_p1 = 0., Iqe_5th_p1 = 0., Ide_5th_old_p1 = 0.,  Iqe_5th_old_p1 = 0.;
float Angle_Grid_p1 = 0., Ide_5th_flt_p1 = 0., Iqe_5th_flt_p1 = 0.;
float Ide_5th_n1 = 0., Iqe_5th_n1 = 0., Ide_5th_old_n1 = 0.,  Iqe_5th_old_n1 = 0.;
float Angle_Grid_n1 = 0., Ide_5th_flt_n1 = 0., Iqe_5th_flt_n1 = 0.;
//float Idsp = 0., Iqsp = 0., Idsn = 0., Iqsn = 0.;
//float Fc_I_5th = 1000., Wc_I_5th = 0., La_I_5th = 0., Lb_I_5th = 0.;

float  Ide_5th_err_p1 = 0.,  Iqe_5th_err_p1 = 0.;
float  Vde_5th_ref_fb_p1 = 0.,  Vqe_5th_ref_fb_p1 = 0.;
float  Vqe_5th_integ_p1 = 0.,   Vde_5th_integ_p1 = 0.;
float  Vqe_5th_ref_p1 = 0.,   Vde_5th_ref_p1  = 0.;
float  Vqs_5th_ref_p1 = 0.,   Vds_5th_ref_p1 = 0.;

float  Ide_5th_err_n1 = 0.,  Iqe_5th_err_n1 = 0.;
float  Vde_5th_ref_fb_n1 = 0.,  Vqe_5th_ref_fb_n1 = 0.;
float  Vqe_5th_integ_n1 = 0.,   Vde_5th_integ_n1 = 0.;
float  Vqe_5th_ref_n1 = 0.,   Vde_5th_ref_n1  = 0.;
float  Vqs_5th_ref_n1 = 0.,   Vds_5th_ref_n1 = 0.;

//float Kp_CC_Grid_comp_5th1 = 1., Ki_CC_Grid_comp_5th1 = 10;
//float Kp_CC_Grid_comp_5th1 = 1., Ki_CC_Grid_comp_5th1 = 100;
float Kp_CC_Grid_comp_5th1 = 1., Ki_CC_Grid_comp_5th1 = 1000;
float Va1=0., Vb1=0., Vc1=0. ;
//float Ia_PLL3_harmonic_k1 = 2.;
float Ia_PLL3_harmonic_k1 = 5.;
//float Ia_PLL3_harmonic_k1 = 6.;
//float Ia_PLL3_harmonic_k1 = 8.;

float Ide_5th_p2 = 0., Iqe_5th_p2 = 0., Ide_5th_old_p2 = 0.,  Iqe_5th_old_p2 = 0.;
float Angle_Grid_p2 = 0., Ide_5th_flt_p2 = 0., Iqe_5th_flt_p2 = 0.;
float Ide_5th_n2 = 0., Iqe_5th_n2 = 0., Ide_5th_old_n2 = 0.,  Iqe_5th_old_n2 = 0.;
float Angle_Grid_n2 = 0., Ide_5th_flt_n2 = 0., Iqe_5th_flt_n2 = 0.;
//float Idsp = 0., Iqsp = 0., Idsn = 0., Iqsn = 0.;
//float Fc_I_5th = 1000., Wc_I_5th = 0., La_I_5th = 0., Lb_I_5th = 0.;

float  Ide_5th_err_p2 = 0.,  Iqe_5th_err_p2 = 0.;
float  Vde_5th_ref_fb_p2 = 0.,  Vqe_5th_ref_fb_p2 = 0.;
float  Vqe_5th_integ_p2 = 0.,   Vde_5th_integ_p2 = 0.;
float  Vqe_5th_ref_p2 = 0.,   Vde_5th_ref_p2  = 0.;
float  Vqs_5th_ref_p2 = 0.,   Vds_5th_ref_p2 = 0.;

float  Ide_5th_err_n2 = 0.,  Iqe_5th_err_n2 = 0.;
float  Vde_5th_ref_fb_n2 = 0.,  Vqe_5th_ref_fb_n2 = 0.;
float  Vqe_5th_integ_n2 = 0.,   Vde_5th_integ_n2 = 0.;
float  Vqe_5th_ref_n2 = 0.,   Vde_5th_ref_n2  = 0.;
float  Vqs_5th_ref_n2 = 0.,   Vds_5th_ref_n2 = 0.;

//float Kp_CC_Grid_comp_5th2 = 1., Ki_CC_Grid_comp_5th2 = 10;
//float Kp_CC_Grid_comp_5th2 = 1., Ki_CC_Grid_comp_5th2 = 100;
float Kp_CC_Grid_comp_5th2 = 1., Ki_CC_Grid_comp_5th2 = 1000;
float Va2=0., Vb2=0., Vc2=0. ;
float Ia_PLL3_harmonic_k2 = 7.;
//float Ia_PLL3_harmonic_k2 = 18.;



float Ide_5th_p3 = 0., Iqe_5th_p3 = 0., Ide_5th_old_p3 = 0.,  Iqe_5th_old_p3 = 0.;
float Angle_Grid_p3 = 0., Ide_5th_flt_p3 = 0., Iqe_5th_flt_p3 = 0.;
float Ide_5th_n3 = 0., Iqe_5th_n3 = 0., Ide_5th_old_n3 = 0.,  Iqe_5th_old_n3 = 0.;
float Angle_Grid_n3 = 0., Ide_5th_flt_n3 = 0., Iqe_5th_flt_n3 = 0.;
//float Idsp = 0., Iqsp = 0., Idsn = 0., Iqsn = 0.;
//float Fc_I_5th = 1000., Wc_I_5th = 0., La_I_5th = 0., Lb_I_5th = 0.;

float  Ide_5th_err_p3 = 0.,  Iqe_5th_err_p3 = 0.;
float  Vde_5th_ref_fb_p3 = 0.,  Vqe_5th_ref_fb_p3 = 0.;
float  Vqe_5th_integ_p3 = 0.,   Vde_5th_integ_p3 = 0.;
float  Vqe_5th_ref_p3 = 0.,   Vde_5th_ref_p3  = 0.;
float  Vqs_5th_ref_p3 = 0.,   Vds_5th_ref_p3 = 0.;

float  Ide_5th_err_n3 = 0.,  Iqe_5th_err_n3 = 0.;
float  Vde_5th_ref_fb_n3 = 0.,  Vqe_5th_ref_fb_n3 = 0.;
float  Vqe_5th_integ_n3 = 0.,   Vde_5th_integ_n3 = 0.;
float  Vqe_5th_ref_n3 = 0.,   Vde_5th_ref_n3  = 0.;
float  Vqs_5th_ref_n3 = 0.,   Vds_5th_ref_n3 = 0.;

//float Kp_CC_Grid_comp_5th3 = 1., Ki_CC_Grid_comp_5th3 = 10;
//float Kp_CC_Grid_comp_5th3 = 1., Ki_CC_Grid_comp_5th3 = 100;
float Kp_CC_Grid_comp_5th3 = 1., Ki_CC_Grid_comp_5th3 = 1000;
float Va3=0., Vb3=0., Vc3=0. ;
float Ia_PLL3_harmonic_k3 = 13.;
//float Ia_PLL3_harmonic_k2 = 18.;


float Kp_5th_ref = 1.;


/*--------------------------------------*/
/*  source Frequence                    */
/*--------------------------------------*/
int     Flag_FreqLowHigh        = 0;
int     Count_freq1             = 0;
int     Count_freq2             = 0;

int     Cnt_freq_max            = 500;
int     Cnt_freq1_max           = 250;
int     Cnt_freq2_max           = 250;

int     Cnt_freq_max_sum        = 1000;

int     Cnt_freq_max_old1       = 500;
int     Cnt_freq_max_old2       = 500;
int     Cnt_freq_max_old3       = 500;
int     Cnt_freq_max_old4       = 500;
int     Cnt_freq_max_old5       = 500;
int     Cnt_freq_max_old6       = 500;
int     Cnt_freq_max_old7       = 500;
int     Cnt_freq_max_old8       = 500;

int     Cnt_freq1_old           = 250;
int     Cnt_freq2_old           = 250;

int     Cnt_freq_high           = 0;
int     Cnt_freq_low            = 0;
int     Cnt_freq_time           = 0;

int     Detec_range_Freq        = 4;
int     FreqDetec_time          = 1;

int     Cnt_freqDetec_time      = 10;

float   Freq_out                = 60.;
float   Freq_source_period      = 0.;
float   Freq_out_avg            = 0.;
float   Freq_out_sum            = 0.;

float   Freq_out_old            = 0.;
float   Freq_out_old1           = 0.;
float   Freq_out_old2           = 0.;
float   Freq_out_old3           = 0.;
float   Freq_out_old4           = 0.;
float   Freq_out_old5           = 0.;

float   Freq_high               = 60.19;
//float   Freq_high               = 62.;
float   Freq_low                = 59.7;
//float   Freq_low                = 57.5;

//float   Flag_Act_islanding_input    = 77.;  //(active1(77=납품), active2(88=인증), passive(99=시험)
//float   Flag_Act_islanding          = 77.;
float   Flag_Act_islanding_input    = 88.;  //(active1(77=납품), active2(88=인증), passive(99=시험)
float   Flag_Act_islanding          = 88.;
float   Cnt_Act_islanding           = 0.;

float   Freq_shift_max              = 85.;
float   Freq_shift_low              = 60.;
float   Freq_shift_init             = 60.;

float   Freq_jump                   = 0.;
int     Freq_jump_cnt               = 0.;

float   Freq_shift_ratio_input      = 2.5;
//float   Freq_shift_ratio_input      = 0;
float   Freq_shift_ratio            = 0;

int     Cnt_Freq_out                = 0;
int     Cnt_Freq_high               = 0;
int     Cnt_Freq_low                = 0;

/*--------------------------------------*/
/*  source PLL                          */
/*--------------------------------------*/
//int       Flag_Va_PLL3 = 0;
int     Flag_Va_PLL3 = 1;

//int       Flag_Ia_PLL3 = 0;
int     Flag_Ia_PLL3 = 1;


int     flag_control_parameter = 1;     //NEW
//int     flag_control_parameter = 2;   //OLD

/*--------------------------------------*/
/*  source err                          */
/*--------------------------------------*/
int     Flag_Grid_err = 1;

/*--------------------------------------*/
/*  time check                          */
/*--------------------------------------*/
//int     time_check_cnt = 0;
//int     time_check_cnt = 2;
int     time_check_cnt = 100;   //operation time led check

/*--------------------------------------*/
/*  RTC check                          */
/*--------------------------------------*/
int      Enb_RTC_mode       = 0;
int      Enb_RTC_init       = 0;
int      Flag_RTC_init      = 0;
int      Flag_RTC_init_cnt  = 0;

int      rtc_write_data2[6] = {0, 0, 0, 0, 0, 0};

int     time_Read_year      = 0;
int     time_Read_mon_day   = 0;
int     time_Read_hour_min  = 0;
int     time_Read_sec       = 0;

int     wr_time_Sel_Wr      = 0;
int     wr_time_Set_year    = 0;
int     wr_time_Set_mon_day = 0;
int     wr_time_Set_hour_min= 0;
int     wr_time_Set_sec     = 0;
