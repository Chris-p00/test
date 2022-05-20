/*
 * Globalval.h
 *
 *  Created on: 2020. 12. 17.
 *      Author: KYJ-PC
 */

#ifndef HEADER__GLOBALVAL_H_
#define HEADER__GLOBALVAL_H_

#include <math.h>
#include <stdlib.h>
#include <string.h>

union bytecode {
    float   w;
    struct {
        unsigned by0: 8;
        unsigned by1: 8;
        unsigned by2: 8;
        unsigned by3: 8;
    } bycode;
};

/*--------------------------------------*/
/*  signal generator                    */
/*--------------------------------------*/
extern float Esa_gen;
extern float Esb_gen;
extern float Esc_gen;

extern float Ia_gen;
extern float Ib_gen;
extern float Ic_gen;

extern float f_gen_target;
extern float i_gen_target;
extern float A_ref_target;

extern float Vin_max_gen;
extern float Vdc_max_gen;
extern float Vac_max_gen;
extern float Iac_max_gen;
extern float Peff_gen;

extern float t_gen;

extern long  ERR_mask;

extern float sig_test0;
extern float sig_test1;
extern float sig_test2;
extern float sig_test3;
extern float sig_test4;
extern float sig_test5;


extern union bytecode w2b, b2w;

#define DATA_PTR_MAX                3000          /* (1000)read/write + (2000)only read   */

#define SIZE_EEPROM_CODE            300
#define INIT_EEPROM_CODE            401
#define SIZE_EEPROM_CODE1           100
#define INIT_EEPROM_CODE1           401
#define SIZE_EEPROM_CODE2           200
#define INIT_EEPROM_CODE2           501

#define INV_12bit_AD_SCALE          0.01/2048           /* 12bit AD INPUT SCALE COMP  */
#define INV_16bit_AD_SCALE          0.01/32768          /* 16bit AD INPUT SCALE COMP  */

#define INV_12bit_AD_OFFSET         2048                /* 12bit AD INPUT OFFSET COMP  */
#define INV_16bit_AD_OFFSET         32768               /* 16bit AD INPUT OFFSET COMP  */

#if 0
//설계 수치값에서 실제 측정값 오차에 대한 보정 작업 진행 (only 제어전원 인가)
#define INV_12bit_AD1_OFFSET        (INV_12bit_AD_OFFSET + 133)
#define INV_12bit_AD2_OFFSET        (INV_12bit_AD_OFFSET + 144)
#define INV_12bit_AD3_OFFSET        (INV_12bit_AD_OFFSET + 133)
#define INV_12bit_AD4_OFFSET        (INV_12bit_AD_OFFSET + 144)
#define INV_12bit_AD5_OFFSET        (INV_12bit_AD_OFFSET + 92)
#define INV_12bit_AD6_OFFSET        (INV_12bit_AD_OFFSET + 92)
#define INV_12bit_AD7_OFFSET        (INV_12bit_AD_OFFSET + 126)
#define INV_12bit_AD8_OFFSET        (INV_12bit_AD_OFFSET + 143)
#define INV_12bit_AD9_OFFSET        (INV_12bit_AD_OFFSET + 133)
#define INV_12bit_AD10_OFFSET       (INV_12bit_AD_OFFSET + 118)
#define INV_12bit_AD11_OFFSET       (INV_12bit_AD_OFFSET + 133)
#define INV_12bit_AD12_OFFSET       (INV_12bit_AD_OFFSET + 131)
#define INV_12bit_AD13_OFFSET       (INV_12bit_AD_OFFSET + 129)
#define INV_12bit_AD14_OFFSET       (INV_12bit_AD_OFFSET + 140)
#define INV_12bit_AD15_OFFSET       (INV_12bit_AD_OFFSET + 134)
#define INV_12bit_AD16_OFFSET       (INV_12bit_AD_OFFSET + 128)
#define INV_16bit_AD17_OFFSET       (INV_16bit_AD_OFFSET - 15)
#define INV_16bit_AD18_OFFSET       (INV_16bit_AD_OFFSET - 19)
#endif

#if 1
#define INV_12bit_AD1_OFFSET        (INV_12bit_AD_OFFSET + 0)
#define INV_12bit_AD2_OFFSET        (INV_12bit_AD_OFFSET + 0)
#define INV_12bit_AD3_OFFSET        (INV_12bit_AD_OFFSET + 0)
#define INV_12bit_AD4_OFFSET        (INV_12bit_AD_OFFSET + 0)
#define INV_12bit_AD5_OFFSET        (INV_12bit_AD_OFFSET + 0)
#define INV_12bit_AD6_OFFSET        (INV_12bit_AD_OFFSET + 0)
#define INV_12bit_AD7_OFFSET        (INV_12bit_AD_OFFSET + 0)
#define INV_12bit_AD8_OFFSET        (INV_12bit_AD_OFFSET + 0)
#define INV_12bit_AD9_OFFSET        (INV_12bit_AD_OFFSET + 0)
#define INV_12bit_AD10_OFFSET       (INV_12bit_AD_OFFSET + 0)
#define INV_12bit_AD11_OFFSET       (INV_12bit_AD_OFFSET + 0)
#define INV_12bit_AD12_OFFSET       (INV_12bit_AD_OFFSET + 0)
#define INV_12bit_AD13_OFFSET       (INV_12bit_AD_OFFSET + 0)
#define INV_12bit_AD14_OFFSET       (INV_12bit_AD_OFFSET + 0)
#define INV_12bit_AD15_OFFSET       (INV_12bit_AD_OFFSET + 0)
#define INV_12bit_AD16_OFFSET       (INV_12bit_AD_OFFSET + 0)
#define INV_16bit_AD17_OFFSET       (INV_16bit_AD_OFFSET - 0)
#define INV_16bit_AD18_OFFSET       (INV_16bit_AD_OFFSET - 0)
#endif

/* Macro functions  */
#define f2  (1./2.)                     /* inverse factorial                */
#define f3  (f2/3.)
#define f4  (f3/4.)
#define f5  (f4/5.)
#define f6  (f5/6.)
#define f7  (f6/7.)
#define f8  (f7/8.)
#define f9  (f8/9.)
#define f10 (f9/10.)
#define f11 (f10/11.)
#define f12 (f11/12.)
#define f13 (f12/13.)
#define f14 (f13/14.)
#define f15 (f14/15.)

#define BOUND_PI(x)                 ((x) + (((x)> PI) ? (-2.*PI) : ((x)< (-PI) ) ? (2.*PI) : 0.))
#define SIN(x,x2)                   ((x)*(1.-(x2)*(f3-(x2)*(f5-(x2)*(f7-(x2)*(f9-(x2)*(f11-(x2)*(f13-(x2)*f15))))))))
#define COS(x2)                     (1.-(x2)*(f2-(x2)*(f4-(x2)*(f6-(x2)*(f8-(x2)*(f10-(x2)*(f12-(x2)*f14)))))))

#define PI                          3.141592654         /* PI   */
#define PI_INV_2                    (PI / 2.)
#define MI_PI                       (-PI)
#define PI_MPY_2                    (PI * 2.)
#define MI_PI_MPY_2                 (-PI * 2.)
#define INV_PI                      (1. / PI)
#define INV_2PI                     (1. / (2 * PI))
#define INV_2                       (1. / 2.)
#define INV_3                       (1. / 3.)
#define INV2_3                      (2. / 3.)
#define SQRT2                       1.414213562         /* SQRT     */
#define SQRT3                       1.732050808

#define SQRT2_SQRT3                 (SQRT2 * SQRT3)

#define SQRT3_INV_2                 (SQRT3 / 2.)

#define INV_SQRT2                   (1. / SQRT2)
#define INV_SQRT3                   (1. / SQRT3)

#define CKP                 0               /* Kp[CC]               */
#define CKIT                1               /* Ki*TSAMP[CC]         */
#define CKA                 2               /* Ka[CC]               */

#define CKPD                3               /* Kp[CC]               */
#define CKITD               4               /* Ki*TSAMP[CC]         */
#define CKAD                5               /* Ka[CC]               */


#define NORMAL              0               /* inverter state normal    */
#define FAULT               1               /* inverter state fault     */

#define INV_MODE            0               /* PWM inverter mode        */
#define TEST_MODE           1               /* test mode                */
#define TEST_MODE2          2               /* test mode2               */

#define CPU1_MODE           1               /* CPU1 command mode        */
#define CPU2_MODE           2               /* CPU2 command mode        */

#define SPWM                0               /* PWM mode                 */
#define SVPWM               1               /* PWM mode                 */

#define DX                  0               /* D-aXis               */
#define QX                  1               /* Q-aXis               */
#define L1                  0
#define L2                  1
#define L3                  2

#define M_TH                50              /* # of Harm.           */

#define M_CC                5               /* size of CC Array     */
#define CREF                0               /* reference            */
#define CACT                1               /* actual               */
#define CFF                 2               /* feed-forward         */
#define CFB                 3               /* feed-back            */
#define CINT                4               /* integral             */

/*  software fault flags    */
#define SFT_gate            0x01            /* '0'bit   gate fault                  */
#define SFT_overheat_inv    0x02            /* '1'bit   INV Over Thermal(접점)      */
//#define SFT_overheat_con    0x04            /* '2'bit   CON Over Thermal(접점)      */
#define SFT_write_EEPROM    0x04         /* '2'bit  eeprom fault                */


#define SFT_OC_Idc_con      0x08            /* '3'bit   CON over current            */

#define SFT_OV_Vdc_con      0x10            /* '4'bit   DC-link Over Voltage        */
//#define SFT_UV_Vdc_con      0x20            /* '5'bit   DC-link Under voltage       */
#define SFT_OVERLOAD        0x20         /* '5'bit  Output Over-Load            */

#define SFT_OV_Vin_con      0x40            /* '6'bit   CON Vin Over Voltage        */
#define SFT_UV_Vin_con      0x80            /* '7'bit   CON Vin Under voltage       */

#define SFT_OC_Ia           0x100           /* '8'bit   A상 over peak current        */
#define SFT_OC_Ib           0x200           /* '9'bit   B상 over peak current        */
#define SFT_OC_Ic           0x400           /* '10'bit  C상 over peak current        */
#define SFT_OV_Src          0x800           /* '11'bit  Over Source  peak voltage   */

#define SFT_UV_Src          0x1000          /* '12'bit  Under Source peak voltage   */
#define SFT_SEQ_Src         0x2000          /* '13'bit  Src Seq.(Negative)    (S/W) */
//#define SFT_SRC_UNB         0x4000          /* '14'bit  Src unbalance       (S/W)   */
#define SFT_FREQ_HIGH       0x4000         /* '14'bit  INV high source frequency   */

//#define SFT_INTER_Src       0x8000          /* '15'bit  Source interruption         */
#define SFT_FREQ_LOW        0x8000         /* '15'bit  INV low source frequency    */

//#define SFT_FREQ_LOW        0x10000         /* '16'bit  INV low source frequency    */
//#define SFT_FREQ_HIGH       0x20000         /* '17'bit  INV high source frequency   */
//#define SFT_OVERLOAD        0x40000         /* '18'bit  Output Over-Load            */
//#define SFT_write_EEPROM    0x80000         /* '19'bit  eeprom fault                */

#define SFT_watch_dog       0x100000        /* '20'bit  28335 watch_dog             */
#define SFT_SOV_Va          0x200000        /* '21'bit  Over Source  rms voltage    */
#define SFT_SUV_Va          0x400000        /* '22'bit  Under Source rms voltage    */
#define SFT_under_ref       0x800000        /* '23'bit  under_ref                   */

#define SFT_fuse_inv_A      0x1000000       /* '24'bit  INN Fuse A Open(접점)       */
#define SFT_fuse_inv_B      0x2000000       /* '25'bit  INN Fuse B Open(접점)       */
#define SFT_fuse_inv_C      0x4000000       /* '26'bit  INN Fuse C Open(접점)       */
#define SFT_offs_Ib         0x8000000       /* '27'bit  Offset(Ib)                  */

#define SFT_offs_Ia         0x10000000      /* '28'bit  Offset(Ia)                  */
#define SFT_offs_Ic         0x20000000      /* '29'bit  Offset(Ic)                  */
#define SFT_offs_Va         0x40000000      /* '30'bit  Offset(Va)                  */
#define SFT_offs_Vb         0x80000000      /* '31'bit  Offset(Vb)                  */

extern int     Eum_enable;

extern int lsc_build_check;

extern int download_check;

/*--------------------------------------*/
/*  serial communication                */
/*--------------------------------------*/
extern float    dummy;
extern int      idummy;
extern void     *data_ptr[DATA_PTR_MAX];

extern int     Ptr_byte;
extern int     Ptr_code_EEPROM;
extern int     Ptr_code_EEPROM2;
extern int     Enable_EEPROM_write;
extern int     Enable_EEPROM_write2;
extern int     Enable_EEPROM_read;
extern int     init_EEPROM_write;
extern int     Init_scale;
extern int     Init_offset;
extern int     Init_gain;
extern int     Err_EEPROM;
extern int     Flag_Read_eeprom;
extern int     Wait_cnt[8];

extern int     Flag_EEPROM_init_cnt;


/*----------------------------*/
/*    com commands            */
/*----------------------------*/
extern float   Fault_reset_com;
extern float   Run_Stop_com;
extern float   Idc_ref_com;
extern float   OP_MODE_com;

//extern int     OP_MODE;
extern float     OP_MODE;

/*----------------------------*/
/*    commands                */
/*----------------------------*/
extern int     INV_SW_VER;

extern int     INV_status;
extern int     Index_user_input;


/*----------------------------*/
/*    sci commands            */
/*----------------------------*/
//extern int     Flag_scia_cpu1_cpu2;
extern float     Flag_scia_cpu1_cpu2;
extern int     Flag_scia;

/*--------------------------------------*/
/*  test count                          */
/*--------------------------------------*/
extern int      m_cnt;


/*--------------------------------------*/
/*  Digital Input                       */
/*--------------------------------------*/
extern int      DI1_input;
extern int      DI2_input;
extern int      DI3_input;
extern int      DI4_input;
extern int      DI5_input;
extern int      DI6_input;
extern int      DI7_input;
extern int      DI8_input;
extern int      DI9_input;
extern int      DI10_input;
extern int      DI11_input;
extern int      DI12_input;

extern int      Conector_1_2_3_input;

extern int      DI_input;
extern int      DI_Run_Stop;
extern int      DI_Run_Stop_cnt;
extern int      Cnt_DI1;


/*--------------------------------------*/
/*  Digital Output                      */
/*--------------------------------------*/
extern int      DO1_output;
extern int      DO2_output;
extern int      DO3_output;
extern int      DO4_output;
extern int      DO5_output;
extern int      DO6_output;
extern int      DO7_output;
extern int      DO8_output;
extern int      DO9_output;
extern int      DO10_output;
extern int      DO11_output;
extern int      DO12_output;
extern int      DO13_output;
extern int      DO14_output;
extern int      DO15_output;
extern int      DO16_output;

extern int      LED1_output;
extern int      LED2_output;


/*--------------------------------------*/
/*  Fault check                         */
/*--------------------------------------*/
extern int      System_fault;
extern int      System_fault_latch;
extern int      Fault_HW;
extern int      Fault_HW_new;
extern int      Fault_HW_old;
extern int      Fault_HW_latch;
extern int      Fault_TZ;

extern int      Fault_EPWM1_TZ1;
extern int      Fault_EPWM2_TZ1;
extern int      Fault_EPWM3_TZ1;
extern int      Fault_EPWM4_TZ2;
extern int      Fault_EPWM5_TZ2;
extern int      Fault_EPWM6_TZ2;
extern int      Fault_EPWM7_TZ3;
extern int      Fault_EPWM8_TZ3;
extern int      Fault_EPWM9_TZ3;
extern int      Fault_EPWM10_TZ4;
extern int      Fault_EPWM11_TZ4;
extern int      Fault_EPWM12_TZ4;


extern long     Fault_SW;
extern int      Fault_check_cnt;
extern long     Fault_SW_latch;

extern int      History[10][20];
extern int      Fault_history[3];

extern int      EnbReturnTime;
extern int      CNT_Reset;


extern int      Fault_reset;
extern int      Fault_save;

extern int     Fault_reset_DI_cnt;                  // S/W reset command
extern int     Fault_reset_com_cnt;                  // S/W reset command


/*--------------------------------------*/
/*  Digital Output Flag                 */
/*--------------------------------------*/
extern int      Mode_system;
extern int      Mode_system_input;

extern int      Mode_pwm;
extern int      Mode_pwm_input;

extern int      Mode_test;

extern int      Flag_charge_test;
extern int      Flag_charge_inv_test;
extern int      Flag_Fan_test;
extern int      Flag_EX24V_test;
extern int      Flag_Fault_test;
extern int      Flag_Run_Stop_test;
extern int      Flag_Power_test;
extern int      Flag_Ch_Vdc_test;

extern int      Flag_charge;
extern int      Flag_charge_inv;
extern int      Flag_Fan;
extern int      Flag_EX24V;
extern int      Flag_Fault;
extern int      Flag_Run_Stop;
extern int      Flag_Ready;
extern int      Flag_Power;
extern int      Flag_Ch_Vdc;

extern float   Flag_charge_float;
extern float   MC_on_cnt_float;

extern int      MC_on_cnt;
extern int      Cnt_Fan1_OFF;

extern int      control_power_check_flag;
extern int      control_power_check_cnt;

/*--------------------------------------*/
/*  PWM Output                          */
/*--------------------------------------*/
extern int      DRV2_ADC_EPWM_ADCSOCA;
extern int      DRV2_ADC_EPWM_ADCSOCB;

extern int     Flag_pwm_1P;
extern int     Flag_pwm_1N;
extern int     Flag_pwm_2P;
extern int     Flag_pwm_2N;
extern int     Flag_pwm_3P;
extern int     Flag_pwm_3N;

extern int      Flag_pwm_con_test1;
extern int      Flag_pwm_inv_test1;
extern int      Flag_pwm_inv_test2;
extern int      Flag_pwm_inv_test3;
extern int      Flag_pwm_inv_test4;

extern int      Flag_gating;
extern int      Flag_gating_con;
extern int      Flag_gating_inv;

extern int     Flag_gating_inv_VF;

extern int      Flag_gating_test_cnt_max;

extern int      Flag_gating_test_cnt;
extern int      Flag_gating_test;
extern int      Flag_gating_con_test;
extern int      Flag_gating_inv_test;

extern int      Flag_gating_VF_TEST;
extern int      Flag_gating_VF;
extern int      Flag_buildup;

extern int      Flag_current_control_inv3;

extern int      Cnt_gating_inv;


extern int      Ta_con_test1;
extern int      Tb_con_test1;
extern int      Tc_con_test1;

extern int      EPwm1_CMP_test;
extern int      EPwm2_CMP_test;
extern int      EPwm3_CMP_test;


extern int      Ta_inv_test1;
extern int      Tb_inv_test1;
extern int      Tc_inv_test1;

extern int      Ta_inv_test2;
extern int      Tb_inv_test2;
extern int      Tc_inv_test2;

extern int      Ta_inv_test3;
extern int      Tb_inv_test3;
extern int      Tc_inv_test3;

extern int      Ta_inv_test4;
extern int      Tb_inv_test4;
extern int      Tc_inv_test4;


/*--------------------------------------*/
/*  gating control(svpwm)               */
/*--------------------------------------*/
extern int     Mode_gating_input;
extern int     Mode_gating;

extern int     Mode_SOCAPRD;

extern int     Mode_gating_con_input;
extern int     Mode_gating_con;

extern float   T_dead_input;
extern float   T_dead_con_input;
extern float   T_dead_comp_input;
extern float   T_dead_onoff_input;

extern float   T_dead;
extern float   T_dead_con;
extern float   T_dead_comp;
extern float   T_dead_onoff;

extern int     T_dead_CNT;
extern int     T_dead_con_CNT;
extern int     T_dead_comp_CNT;
extern int     T_dead_onoff_CNT;

extern int     CNT_max;
extern int     CNT_max_2;
extern int     CNT_max_5;
extern int     CNT_max_10;
extern int     CNT_max_20;
extern int     CNT_max_30;
extern int     CNT_max_40;
extern int     CNT_max_49_5;
extern int     CNT_max_50;
extern int     CNT_max_60;
extern int     CNT_max_70;
extern int     CNT_max_80;
extern int     CNT_max_90;
extern int     CNT_max_95;
extern int     CNT_max_98;

extern int     CNT_max_con;
extern int     CNT_max_con_2;
extern int     CNT_max_con_5;
extern int     CNT_max_con_10;
extern int     CNT_max_con_20;
extern int     CNT_max_con_30;
extern int     CNT_max_con_40;
extern int     CNT_max_con_49_5;
extern int     CNT_max_con_50;
extern int     CNT_max_con_60;
extern int     CNT_max_con_70;
extern int     CNT_max_con_80;
extern int     CNT_max_con_90;
extern int     CNT_max_con_95;
extern int     CNT_max_con_98;

extern int     CNT_max_con_dead_50;
extern int     T_dead_con_CNT_50;

/*--------------------------------------*/
/*  ERR Intput                          */
/*--------------------------------------*/
extern int      EPwm_TZ1_IntCount;
extern int      EPwm_TZ2_IntCount;
extern int      EPwm_TZ3_IntCount;

extern int      EPwm1_TZ1_IntCount;
extern int      EPwm2_TZ1_IntCount;
extern int      EPwm3_TZ1_IntCount;
extern int      EPwm4_TZ2_IntCount;
extern int      EPwm5_TZ2_IntCount;
extern int      EPwm6_TZ2_IntCount;
extern int      EPwm7_TZ3_IntCount;
extern int      EPwm8_TZ3_IntCount;
extern int      EPwm9_TZ3_IntCount;
extern int      EPwm10_TZ4_IntCount;
extern int      EPwm11_TZ4_IntCount;
extern int      EPwm12_TZ4_IntCount;

/*--------------------------------------*/
/*  ADC Intput                          */
/*--------------------------------------*/
#if 1
//test ADC1 ~ ADC18
extern float   ADC1;
extern float   ADC1_flt;
extern float   ADC1_old;
extern float   ADC1_flt_sum;
extern float   ADC1_flt_avg;
extern float   ADC1_flt_avg_sum;
extern float   ADC1_flt_avg_avg;
extern float   ADC1_offset_input;
extern float   ADC1_offset;
extern float   Scale_12bit_ADC1_input;
extern float   Scale_12bit_ADC1_ratio;
extern float   Scale_12bit_ADC1;

extern float   ADC2;
extern float   ADC2_flt;
extern float   ADC2_old;
extern float   ADC2_flt_sum;
extern float   ADC2_flt_avg;
extern float   ADC2_flt_avg_sum;
extern float   ADC2_flt_avg_avg;
extern float   ADC2_offset_input;
extern float   ADC2_offset;
extern float   Scale_12bit_ADC2_input;
extern float   Scale_12bit_ADC2_ratio;
extern float   Scale_12bit_ADC2;

extern float   ADC3;
extern float   ADC3_flt;
extern float   ADC3_old;
extern float   ADC3_flt_sum;
extern float   ADC3_flt_avg;
extern float   ADC3_flt_avg_sum;
extern float   ADC3_flt_avg_avg;
extern float   ADC3_offset_input;
extern float   ADC3_offset;
extern float   Scale_12bit_ADC3_input;
extern float   Scale_12bit_ADC3_ratio;
extern float   Scale_12bit_ADC3;

extern float   ADC4;
extern float   ADC4_flt;
extern float   ADC4_old;
extern float   ADC4_flt_sum;
extern float   ADC4_flt_avg;
extern float   ADC4_flt_avg_sum;
extern float   ADC4_flt_avg_avg;
extern float   ADC4_offset_input;
extern float   ADC4_offset;
extern float   Scale_12bit_ADC4_input;
extern float   Scale_12bit_ADC4_ratio;
extern float   Scale_12bit_ADC4;

extern float   ADC5;
extern float   ADC5_flt;
extern float   ADC5_old;
extern float   ADC5_flt_sum;
extern float   ADC5_flt_avg;
extern float   ADC5_flt_avg_sum;
extern float   ADC5_flt_avg_avg;
extern float   ADC5_offset_input;
extern float   ADC5_offset;
extern float   Scale_12bit_ADC5_input;
extern float   Scale_12bit_ADC5_ratio;
extern float   Scale_12bit_ADC5;

extern float   ADC6;
extern float   ADC6_flt;
extern float   ADC6_old;
extern float   ADC6_flt_sum;
extern float   ADC6_flt_avg;
extern float   ADC6_flt_avg_sum;
extern float   ADC6_flt_avg_avg;
extern float   ADC6_offset_input;
extern float   ADC6_offset;
extern float   Scale_12bit_ADC6_input;
extern float   Scale_12bit_ADC6_ratio;
extern float   Scale_12bit_ADC6;

extern float   ADC7;
extern float   ADC7_flt;
extern float   ADC7_old;
extern float   ADC7_flt_sum;
extern float   ADC7_flt_avg;
extern float   ADC7_flt_avg_sum;
extern float   ADC7_flt_avg_avg;
extern float   ADC7_offset_input;
extern float   ADC7_offset;
extern float   Scale_12bit_ADC7_input;
extern float   Scale_12bit_ADC7_ratio;
extern float   Scale_12bit_ADC7;

extern float   ADC8;
extern float   ADC8_flt;
extern float   ADC8_old;
extern float   ADC8_flt_sum;
extern float   ADC8_flt_avg;
extern float   ADC8_flt_avg_sum;
extern float   ADC8_flt_avg_avg;
extern float   ADC8_offset_input;
extern float   ADC8_offset;
extern float   Scale_12bit_ADC8_input;
extern float   Scale_12bit_ADC8_ratio;
extern float   Scale_12bit_ADC8;

extern float   ADC9;
extern float   ADC9_flt;
extern float   ADC9_old;
extern float   ADC9_flt_sum;
extern float   ADC9_flt_avg;
extern float   ADC9_flt_avg_sum;
extern float   ADC9_flt_avg_avg;
extern float   ADC9_offset_input;
extern float   ADC9_offset;
extern float   Scale_12bit_ADC9_input;
extern float   Scale_12bit_ADC9_ratio;
extern float   Scale_12bit_ADC9;

extern float   ADC10;
extern float   ADC10_flt;
extern float   ADC10_old;
extern float   ADC10_flt_sum;
extern float   ADC10_flt_avg;
extern float   ADC10_flt_avg_sum;
extern float   ADC10_flt_avg_avg;
extern float   ADC10_offset_input;
extern float   ADC10_offset;
extern float   Scale_12bit_ADC10_input;
extern float   Scale_12bit_ADC10_ratio;
extern float   Scale_12bit_ADC10;

extern float   ADC11;
extern float   ADC11_flt;
extern float   ADC11_old;
extern float   ADC11_flt_sum;
extern float   ADC11_flt_avg;
extern float   ADC11_flt_avg_sum;
extern float   ADC11_flt_avg_avg;
extern float   ADC11_offset_input;
extern float   ADC11_offset;
extern float   Scale_12bit_ADC11_input;
extern float   Scale_12bit_ADC11_ratio;
extern float   Scale_12bit_ADC11;

extern float   ADC12;
extern float   ADC12_flt;
extern float   ADC12_old;
extern float   ADC12_flt_sum;
extern float   ADC12_flt_avg;
extern float   ADC12_flt_avg_sum;
extern float   ADC12_flt_avg_avg;
extern float   ADC12_offset_input;
extern float   ADC12_offset;
extern float   Scale_12bit_ADC12_input;
extern float   Scale_12bit_ADC12_ratio;
extern float   Scale_12bit_ADC12;

extern float   ADC13;
extern float   ADC13_flt;
extern float   ADC13_old;
extern float   ADC13_flt_sum;
extern float   ADC13_flt_avg;
extern float   ADC13_flt_avg_sum;
extern float   ADC13_flt_avg_avg;
extern float   ADC13_offset_input;
extern float   ADC13_offset;
extern float   Scale_12bit_ADC13_input;
extern float   Scale_12bit_ADC13_ratio;
extern float   Scale_12bit_ADC13;

extern float   ADC14;
extern float   ADC14_flt;
extern float   ADC14_old;
extern float   ADC14_flt_sum;
extern float   ADC14_flt_avg;
extern float   ADC14_flt_avg_sum;
extern float   ADC14_flt_avg_avg;
extern float   ADC14_offset_input;
extern float   ADC14_offset;
extern float   Scale_12bit_ADC14_input;
extern float   Scale_12bit_ADC14_ratio;
extern float   Scale_12bit_ADC14;

extern float   ADC15;
extern float   ADC15_flt;
extern float   ADC15_old;
extern float   ADC15_flt_sum;
extern float   ADC15_flt_avg;
extern float   ADC15_flt_avg_sum;
extern float   ADC15_flt_avg_avg;
extern float   ADC15_offset_input;
extern float   ADC15_offset;
extern float   Scale_12bit_ADC15_input;
extern float   Scale_12bit_ADC15_ratio;
extern float   Scale_12bit_ADC15;

extern float   ADC16;
extern float   ADC16_flt;
extern float   ADC16_old;
extern float   ADC16_flt_sum;
extern float   ADC16_flt_avg;
extern float   ADC16_flt_avg_sum;
extern float   ADC16_flt_avg_avg;
extern float   ADC16_offset_input;
extern float   ADC16_offset;
extern float   Scale_12bit_ADC16_input;
extern float   Scale_12bit_ADC16_ratio;
extern float   Scale_12bit_ADC16;

extern float   ADC17;
extern float   ADC17_flt;
extern float   ADC17_old;
extern float   ADC17_flt_sum;
extern float   ADC17_flt_avg;
extern float   ADC17_flt_avg_sum;
extern float   ADC17_flt_avg_avg;
extern float   ADC17_offset_input;
extern float   ADC17_offset;
extern float   Scale_16bit_ADC17_input;
extern float   Scale_16bit_ADC17_ratio;
extern float   Scale_16bit_ADC17;

extern float   ADC18;
extern float   ADC18_flt;
extern float   ADC18_old;
extern float   ADC18_flt_sum;
extern float   ADC18_flt_avg;
extern float   ADC18_flt_avg_sum;
extern float   ADC18_flt_avg_avg;
extern float   ADC18_offset_input;
extern float   ADC18_offset;
extern float   Scale_16bit_ADC18_input;
extern float   Scale_16bit_ADC18_ratio;
extern float   Scale_16bit_ADC18;
#endif


extern float   Vin;
extern float   Vin_flt;
extern float   Vin_old;
extern float   Vin_flt_sum;
extern float   Vin_flt_avg;
extern float   Vin_flt_avg_sum;
extern float   Vin_flt_avg_avg;
extern float   Vin_offset_input;
extern float   Vin_offset;
extern float   Scale_Vin_input;
extern float   Scale_Vin_ratio;
extern float   Scale_Vin;

extern float   Idc;
extern float   Idc_flt;
extern float   Idc_old;
extern float   Idc_flt_sum;
extern float   Idc_flt_avg;
extern float   Idc_flt_avg_sum;
extern float   Idc_flt_avg_avg;
extern float   Idc_offset_input;
extern float   Idc_offset;
extern float   Scale_Idc_input;
extern float   Scale_Idc_ratio;
extern float   Scale_Idc;

extern float   Pin;

extern float   Vin_flt_avg_avg_abs;
extern float   Idc_flt_avg_avg_abs;
extern float   Pin_abs;

extern float   A_ref;
extern float   A_ref_flt;
extern float   A_ref_old;
extern float   A_ref_flt_sum;
extern float   A_ref_flt_avg;
extern float   A_ref_flt_avg_sum;
extern float   A_ref_flt_avg_avg;
extern float   A_ref_offset_input;
extern float   A_ref_offset;
extern float   Scale_A_ref_input;
extern float   Scale_A_ref_ratio;
extern float   Scale_A_ref;

extern float   Vdc;
extern float   Vdc_flt;
extern float   Vdc_old;
extern float   Vdc_flt_sum;
extern float   Vdc_flt_avg;
extern float   Vdc_flt_avg_sum;
extern float   Vdc_flt_avg_avg;
extern float   Vdc_offset_input;
extern float   Vdc_offset;
extern float   Scale_Vdc_input;
extern float   Scale_Vdc_ratio;
extern float   Scale_Vdc;

extern float   Esa;
extern float   Esa_flt;
extern float   Esa_old;
extern float   Esa_rms;
extern float   Esa_rms_sum;
extern float   Esa_rms_avg;
extern float   Esa_rms_avg_sum;
extern float   Esa_rms_avg_avg;
extern float   Esa_offset_input;
extern float   Esa_offset;
extern float   Esa_offset_sum;
extern float   Esa_offset_comp_input;
extern float   Esa_offset_comp;
extern float   Scale_Esa_input;
extern float   Scale_Esa_ratio;
extern float   Scale_Esa;

extern float   Esb;
extern float   Esb_flt;
extern float   Esb_old;
extern float   Esb_rms;
extern float   Esb_rms_sum;
extern float   Esb_rms_avg;
extern float   Esb_rms_avg_sum;
extern float   Esb_rms_avg_avg;
extern float   Esb_offset_input;
extern float   Esb_offset;
extern float   Esb_offset_sum;
extern float   Esb_offset_comp_input;
extern float   Esb_offset_comp;
extern float   Scale_Esb_input;
extern float   Scale_Esb_ratio;
extern float   Scale_Esb;

extern float   Esc;
extern float   Esc_flt;
extern float   Esc_old;
extern float   Esc_rms;
extern float   Esc_rms_sum;
extern float   Esc_rms_avg;
extern float   Esc_rms_avg_sum;
extern float   Esc_rms_avg_avg;
extern float   Esc_offset_input;
extern float   Esc_offset;
extern float   Esc_offset_sum;
extern float   Esc_offset_comp_input;
extern float   Esc_offset_comp;
extern float   Scale_Esc_input;
extern float   Scale_Esc_ratio;
extern float   Scale_Esc;

extern float   Eab;
extern float   Eab_flt;
extern float   Eab_old;
extern float   Eab_rms;
extern float   Eab_rms_sum;
extern float   Eab_rms_avg;
extern float   Eab_rms_avg_sum;
extern float   Eab_rms_avg_avg;
extern float   Eab_offset_input;
extern float   Eab_offset;
extern float   Eab_offset_sum;
extern float   Eab_offset_comp_input;
extern float   Eab_offset_comp;
extern float   Scale_Eab_input;
extern float   Scale_Eab_ratio;
extern float   Scale_Eab;

extern float   Ebc;
extern float   Ebc_flt;
extern float   Ebc_old;
extern float   Ebc_rms;
extern float   Ebc_rms_sum;
extern float   Ebc_rms_avg;
extern float   Ebc_rms_avg_sum;
extern float   Ebc_rms_avg_avg;
extern float   Ebc_offset_input;
extern float   Ebc_offset;
extern float   Ebc_offset_sum;
extern float   Ebc_offset_comp_input;
extern float   Ebc_offset_comp;
extern float   Scale_Ebc_input;
extern float   Scale_Ebc_ratio;
extern float   Scale_Ebc;

extern float   Eca;
extern float   Eca_flt;
extern float   Eca_old;
extern float   Eca_rms;
extern float   Eca_rms_sum;
extern float   Eca_rms_avg;
extern float   Eca_rms_avg_sum;
extern float   Eca_rms_avg_avg;
extern float   Eca_offset_input;
extern float   Eca_offset;
extern float   Eca_offset_sum;
extern float   Eca_offset_comp_input;
extern float   Eca_offset_comp;
extern float   Scale_Eca_input;
extern float   Scale_Eca_ratio;
extern float   Scale_Eca;

extern float   Eabc_rms;


extern float   Ia;
extern float   Ia_abs;
extern float   Ia_flt;
extern float   Ia_old;
extern float   Ia_rms;
extern float   Ia_rms_sum;
extern float   Ia_rms_avg;
extern float   Ia_rms_avg_sum;
extern float   Ia_rms_avg_avg;
extern float   Ia_offset_input;
extern float   Ia_offset;
extern float   Ia_offset_sum;
extern float   Ia_offset_comp_input;
extern float   Ia_offset_comp;
extern float   Scale_Ia_input;
extern float   Scale_Ia_ratio;
extern float   Scale_Ia;

extern float   Ib;
extern float   Ib_abs;
extern float   Ib_flt;
extern float   Ib_old;
extern float   Ib_rms;
extern float   Ib_rms_sum;
extern float   Ib_rms_avg;
extern float   Ib_rms_avg_sum;
extern float   Ib_rms_avg_avg;
extern float   Ib_offset_input;
extern float   Ib_offset;
extern float   Ib_offset_sum;
extern float   Ib_offset_comp_input;
extern float   Ib_offset_comp;
extern float   Scale_Ib_input;
extern float   Scale_Ib_ratio;
extern float   Scale_Ib;

extern float   Ic;
extern float   Ic_abs;
extern float   Ic_flt;
extern float   Ic_old;
extern float   Ic_rms;
extern float   Ic_rms_sum;
extern float   Ic_rms_avg;
extern float   Ic_rms_avg_sum;
extern float   Ic_rms_avg_avg;
extern float   Ic_offset_input;
extern float   Ic_offset;
extern float   Ic_offset_sum;
extern float   Ic_offset_comp_input;
extern float   Ic_offset_comp;
extern float   Scale_Ic_input;
extern float   Scale_Ic_ratio;
extern float   Scale_Ic;

extern int     Cnt_rms;
extern int     Cnt_rms_avg;
extern int     Cnt_rms_avg2;

extern float   INV_Vin;
extern float   INV_Vdc;
extern float   INV_Vdc_2;

extern float   Tsamp_Inv_Vdc;

extern float   Tsamp_Inv_Vdc_gain;

/*--------------------------------------*/
/*  system parameters                   */
/*--------------------------------------*/
//6.5kW FC new setting
extern float   Pin_rate;
extern float   Vin_rate;
extern float   Vin_max;
extern float   Vin_max_80;
extern float   Vin_min;
extern float   Vin_min_2;

extern float   Idc_rate;
extern float   Idc_max;
extern float   Idc_min;

extern float   Vdc_max;

extern float   Pout_rate;
extern float   Vl_rate;
extern float   Vl_rate_peak;
extern float   Vs_rate;
extern float   Vs_rate_peak;
extern float   INV_Vs_rate_peak;

extern float   Ic_rate;
extern float   Ic_rate_peak;

//---- Setting value of Ratio (S/W Protection)-----//
extern float   OV_Vin_level;
extern float   UV_Vin_level;
extern float   OC_Idc_ratio;

extern float   OV_Vdc_level;

extern float   OC_ratio;
extern float   OV_ratio_src;
extern float   UV_ratio_src;
extern float   INTER_ratio_src;

extern float   OV_ratio_src_rms;
extern float   UV_ratio_src_rms;

extern float   OL_ratio;

//-------- Setting value (S/W Protection)-------//
extern float   OV_set_Vin_test;
extern float   UV_set_Vin_test;
extern float   OC_Idc_set_test;

extern float   OV_set_Vdc_test;
extern float   UV_set_Vdc_test;

extern float   OV_set_src_test;
extern float   UV_set_src_test;
extern float   INTER_set_src_test;

extern float   OV_set_src_rms_test;
extern float   UV_set_src_rms_test;
extern float   OC_set_test;

extern float   OV_set_Vin;
extern float   UV_set_Vin;
extern float   OC_Idc_set;

extern float   OV_set_Vdc;
extern float   UV_set_Vdc;

extern float   OV_set_src;
extern float   UV_set_src;
extern float   INTER_set_src;
extern float   OV_set_src_rms;
extern float   UV_set_src_rms;

extern float   OV_set_Va;
extern float   UV_set_Va;

extern float   OC_set;
extern float   OC_dc_set;

extern float   OV_set_Va_rms;
extern float   UV_set_Va_rms;
extern float   OC_set_Ia_rms;
extern float   Overload_Pout;

extern int     Cnt_OC_Ia;
extern int     Cnt_OC_Ib;
extern int     Cnt_OC_Ic;

extern int      Cnt_OC_Idc;
extern int      Cnt_OV_Vdc;
extern int      Cnt_UV_Vdc;
extern int      Cnt_OV_Vin;
extern int      Cnt_UV_Vin;
extern int      Cnt_OV_Va;
extern int      Cnt_UV_Va;
//extern int      Cnt_Freq_high;
//extern int      Cnt_Freq_low;

extern int     Cnt_source_check1;
extern int     Cnt_source_check2;
extern int     Cnt_source_check3;

extern float   OL_time_set;
extern int     Cnt_overload;


//---- Setting value of Ratio (S/W operation)-----//

extern float   Vin_MC_ON_level;
extern float   Vin_MC_OFF_level;
extern float   AC_MC_ON_level;
extern float   AC_MC_OFF_level;

extern float   AC_MC_ON_ratio;
extern float   AC_MC_OFF_ratio;

/*--------------------------------------*/
/*  Converter controller variable       */
/*--------------------------------------*/
extern float   Kp_Vdc_con_input;
extern float   Ki_Vdc_con_input;
extern float   Kp_Idc_con_input;
extern float   Ki_Idc_con_input;

extern float   Kp_Vdc_con_ratio;
extern float   Ki_Vdc_con_ratio;
extern float   Kp_Idc_con_ratio;
extern float   Ki_Idc_con_ratio;

extern float   Kp_Vdc_con;
extern float   Ki_Vdc_con;
extern float   Ka_Vdc_con;

extern float   Kp_Idc;
extern float   Ki_Idc;
extern float   Ka_Idc;

extern int     Cnt_buildup;
extern float   Vdc_soft_ratio;
extern float   Vdc_ref_con_temp;
extern float   Vdc_ref_con_set;
extern float   Vdc_ref_con_set_input;
extern float   Vdc_ref_con_set_level;

extern float   Err_Vdc_con;
extern float   Vdc_ref_con;
extern float   Vdc_con_integ;
extern float   Vdc_con_pro;
extern float   Vdc_con_out;
extern float   Vdc_con_ff;
extern float   Vdc_con_real;
extern float   Vdc_con_real_max;

extern float   Idc_limit_con;
extern float   Idc_ref_factor;
extern float   Idc_ref_offset;
extern float   Idc_ref_step;

extern float   Idc_ref_Aref;


extern float   Idc_ref_comp;
extern float   Idc_ref_comp_input;

extern float   Idc_ref_mode;
extern float   Idc_ref_mode_input;

extern int     CNT_ref_Err;

extern float   Kp_Idc_ref_Cf;
extern float   Idc_ref_Cf;

extern float   Err_Idc;
extern float   Idc_ref;
extern float   Idc_integ;
extern float   Idc_pro;
extern float   Idc_out;
extern float   Idc_real;

//extern float   INV_Vin;
extern float   Tsamp_INV_Vin;

extern int     Ta_real_con;
extern int     Ta_con;

extern float   Ta_real_con_float;
extern float   Ta_con_float;

extern float   Ta_real_inv_float;
extern float   Tb_real_inv_float;
extern float   Tc_real_inv_float;

extern float   Ta_inv_float;
extern float   Tb_inv_float;
extern float   Tc_inv_float;

extern float   Fault_SW_float;

extern float   Imax_norm_float;
extern float   Vmax_norm_float;
extern float   Pmax_norm_float;
extern float   Vref_target_float;
extern int     RunStopReset;

/*--------------------------------------*/
/*           V/F Operation              */
/*--------------------------------------*/
extern float   VF_vtg_max;
extern float   VF_vtg_max_no_Vdc;

extern float   VF_time;

extern float   VF_vtg;
extern float   VF_vtg_off;

extern float   VF_freq;
extern float   VF_freq_off;

extern float   VF_vtg_max_set;
extern float   VF_freq_max;

extern float   theta_VF;

extern float   Sin_Theta_VF;
extern float   Cos_Theta_VF;

extern float   VF_freq2;
extern float   VF_freq_off2;
extern float   theta_VF2;
extern float   Sin_Theta_VF2;
extern float   Cos_Theta_VF2;


/*--------------------------------------*/
/*  Converter Gain parameters           */
/*--------------------------------------*/
extern float   Kp_Vdc_con;
extern float   Ki_Vdc_con;
extern float   Ka_Vdc_con;

//extern float   Kp_Idc;
//extern float   Ki_Idc;
//extern float   Ka_Idc;

extern float   Kp_Vdc_con_input;
extern float   Ki_Vdc_con_input;
extern float   Kp_Idc_con_input;
extern float   Ki_Idc_con_input;

extern float   Kp_Vdc_con_ratio;
extern float   Ki_Vdc_con_ratio;
extern float   Kp_Idc_con_ratio;
extern float   Ki_Idc_con_ratio;







/*--------------------------------------*/
/* Inverter Gain parameters             */
/*--------------------------------------*/
extern float   Lc_input;
extern float   Lc;
extern float   Rc;
extern float   Cdc_input;
extern float   Cdc;

extern float   Kp_VC;
extern float   Ki_VC;
extern float   Ka_VC;

extern float   Zeta_VC;
extern float   Wn_VC;

//extern float   Vdc_ref_set_init;
extern float   Kp_Vdc_ratio;
extern float   Ki_Vdc_inv_ratio;

extern float   Wc_CC;
extern float   Wc_CC_D;

extern float   Alpha_CC;
extern float   INV_Alpha_CC;

//extern float   K_cc[3];
extern float   K_cc[6];

extern float   Kp_ide_p;
extern float   Ki_ide_p;
extern float   Ka_ide_p;

extern float   Kp_iqe_p;
extern float   Ki_iqe_p;
extern float   Ka_iqe_p;

extern float   Kp_ide_n;
extern float   Ki_ide_n;
extern float   Ka_ide_n;

extern float   Kp_iqe_n;
extern float   Ki_iqe_n;
extern float   Ka_iqe_n;

//extern float   K_cc_ratio[3];
extern float   K_cc_ratio[6];

extern float   Kp_ide_d_p;
extern float   Ki_ide_d_p;
extern float   Ka_ide_d_p;

extern float   Kp_iqe_d_p;
extern float   Ki_iqe_d_p;
extern float   Ka_iqe_d_p;

extern float   Kp_ide_d_n;
extern float   Ki_ide_d_n;
extern float   Ka_ide_d_n;

extern float   Kp_iqe_d_n;
extern float   Ki_iqe_d_n;
extern float   Ka_iqe_d_n;

extern float   Kp_Ia_ratio;
extern float   Ki_Ia_ratio;

extern float   Kp_Ia_ratio_D;
extern float   Ki_Ia_ratio_D;

extern float   Kp_ide_ratio_d_p;
extern float   Ki_ide_ratio_d_p;

extern float   Kp_iqe_ratio_q_p;
extern float   Ki_iqe_ratio_q_p;

extern float   Kp_ide_ratio_d_n;
extern float   Ki_ide_ratio_d_n;

extern float   Kp_iqe_ratio_q_n;
extern float   Ki_iqe_ratio_q_n;


extern float   Kp_iqe;
extern float   Ki_iqe;
extern float   Ka_iqe;
extern float   Kp_ide;
extern float   Ki_ide;
extern float   Ka_ide;

extern float   Kp_Vde_ff;
extern float   Kp_Vqe_ff;

extern float   Kp_Ide_ff;
extern float   Kp_Iqe_ff;

extern float   Ide_ref_Cf;
extern float   Iqe_ref_Cf;
extern float   Iqe_ref_Cf_add;

extern float   Kp_Vde_ff_flt;
extern float   Kp_Vqe_ff_flt;
extern float   Kp_Iqe_ff_flt;
extern float   Kp_Ide_ff_flt;

extern float   K_cc_DX_CKIT_Err_Ide;
extern float   K_cc_DX_CKIT_K_cc_CKA;
extern float   K_cc_QX_CKIT_Err_Iqe;
extern float   K_cc_QX_CKIT_K_cc_CKA;

extern int   flag_voltage_control_inv3;

extern int     voltage_control_inv3_cnt;
extern int     voltage_control_inv3_cnt_max;


extern float   Err_Vdc_inv;
extern float   Vdc_ref_inv;

extern int     Ref_con_inv_flag;
extern int     Vdc_ref_inv_flag;

extern float   Vdc_ref_inv_test;


extern float   Vdc_ref_inv_input;

extern float   Vdc_ref_set_inv;
extern float   Vdc_ref_inv_max;


extern float   Vdc_ref_inv_ratio;

extern float   Vdc_inv_integ;
extern float   Vdc_inv_pro;
extern float   Vdc_inv_out;
extern float   Vdc_inv_ff;
extern float   Vdc_inv_real;

extern float   Vdc_ref_set;
extern float   Vdc_ref_set_init;

extern float   Ip_ref;
extern float   Ip_ref_out;
extern float   Ip_ref_real;
extern float   Ip_ref_integ;
extern float   Ip_ref_ff;
extern float   Ip_ref_real_max;
extern float   Ip_ref_ratio;

extern float   Ip_ref_real_max_test;
extern float   Ip_ref_real_max_input;

extern float   Ip_ref_real_max_step;

extern float   Ip_ref_real_max_min;
extern float   Ip_ref_real_max_max;

extern float   Ip_ref_real_max_init_input;
extern float   Ip_ref_real_max_init;
extern int     Ip_ref_real_max_cnt;
extern int     Flag_gating_inv_Ip_ref_real_max;

extern float   Ip_ref_real_min;
extern float   Ip_ref_real_min_input;

extern float   Ide_ref_real_max_input;
extern float   Ide_ref_real_max_input_inv;

extern float   pVfe1[3][M_CC];

extern float   Vds_ref;
extern float   Vqs_ref;
extern float   Vde_ref;
extern float   Vqe_ref;

extern float   Va_ref;
extern float   Vb_ref;
extern float   Vc_ref;

extern float   Vfds_ref;
extern float   Vfqs_ref;
extern float   Vfde_ref;
extern float   Vfqe_ref;

extern float   Vmax;
extern float   Vmin;
extern float   Vmax2;
extern float   Vf_mag;
extern float   Vf_mag2;
extern int     Flag_volt_limit;
extern float   Pout;

extern float   Vcon_alpha_p;
extern float   Vcon_beta_p;

extern float   Vcon_alpha_n;
extern float   Vcon_beta_n;

extern float   Vas_ref_p;
extern float   Vbs_ref_p;
extern float   Vcs_ref_p;

extern float   Vas_ref_n;
extern float   Vbs_ref_n;
extern float   Vcs_ref_n;

extern float   Van_ref;
extern float   Vbn_ref;
extern float   Vcn_ref;

extern float   Vas_ref_SV;
extern float   Vbs_ref_SV;
extern float   Vcs_ref_SV;

extern float   Vmax_SV;
extern float   Vmin_SV;

extern float   Vsn_SV;

//extern float   Van_ref;
//extern float   Vbn_ref;
//extern float   Vcn_ref;



extern float   T0_check;


extern float   Err_Ide;
extern float   Err_Iqe;

extern float   Ide_ref;
extern float   Iqe_ref;

extern float   Iqe_ref_old;
extern float   Iqe_ref_flt;

extern int     flag_Iqe_ref_flt;

extern float   Iqe_ref_input_test;

extern float   Iqe_ref_input;
extern float   Ide_ref_input;
//extern float   Ide_ref_Cf;

extern float   Ide_err_p;
extern float   Ide_ref_integ_p;
extern float   Ide_out_p;
extern float   Ide_ref_p;
extern float   Ide_cff_p;
extern float   Ide_ref_out_p;

extern float   Iqe_err_p;
extern float   Iqe_ref_integ_p;
extern float   Iqe_out_p;
extern float   Iqe_ref_p;
extern float   Iqe_cff_p;
extern float   Iqe_ref_out_p;

extern float   Ide_err_n;
extern float   Ide_ref_integ_n;
extern float   Ide_out_n;
extern float   Ide_ref_n;
extern float   Ide_ref_p_n;
extern float   Ide_cff_n;
extern float   Ide_ref_out_n;

extern float   Iqe_err_n;
extern float   Iqe_ref_integ_n;
extern float   Iqe_out_n;
extern float   Iqe_ref_n;
extern float   Iqe_ref_p_n;
extern float   Iqe_cff_n;
extern float   Iqe_ref_out_n;

extern float   Ide_ref_Cf_p;
extern float   Ide_ref_Cf_n;

extern float   Ka_ide_fb_p;
extern float   Ka_iqe_fb_p;
extern float   Ka_ide_fb_n;
extern float   Ka_iqe_fb_n;


extern int     Ta_inv;
extern int     Tb_inv;
extern int     Tc_inv;
extern int     Ta_real_inv;
extern int     Tb_real_inv;
extern int     Tc_real_inv;

extern float   Ta;
extern float   Tb;
extern float   Tc;

//extern int     Flag_over_modu;
extern float     Flag_over_modu;


extern int         Flag_over_check;


//extern float   Err_Ia,Ia_ref,Ip_ref;//current control
extern float   Err_Ia,Ia_ref;//current control
extern float   Ia_pro,Ia_integ, Ia_out,Ia_real;//current control


/*--------------------------------------*/
/*  Theta & sine/cosine variables       */
/*--------------------------------------*/
extern int     mode_Va_PLL3;

extern float   Theta;
extern float   Theta_n;
extern float   Theta_C;
extern float   Theta_C_n;

extern float   Theta_old;
extern float   Theta_comp3;

extern float   Theta_comp_out;
extern float   Err_theta_comp;
extern float   Err_Vde_C;

extern float   Sin_theta;
extern float   Sin_theta_n;
extern float   Sin_thetaT;
extern float   Sin_theta_C;
extern float   Sin_theta_C_n;

extern float   Cos_theta;
extern float   Cos_theta_n;
extern float   Cos_thetaT;
extern float   Cos_theta_C;
extern float   Cos_theta_C_n;

extern float   DA_Test1;
extern float   DA_Test_K1;

extern float   DA_Test2;
extern float   DA_Test_K2;

extern float   Sin_theta_90;
extern float   Cos_theta_90;
extern float   Sin_theta_C_90;
extern float   Cos_theta_C_90;

extern float   Sin_theta_k1;
extern float   Cos_theta_k1;
extern float   Sin_theta_n_k1;
extern float   Cos_theta_n_k1;

extern float   Sin_theta_k2;
extern float   Cos_theta_k2;
extern float   Sin_theta_n_k2;
extern float   Cos_theta_n_k2;

extern float   Sin_theta_k2;
extern float   Cos_theta_k2;
extern float   Sin_theta_n_k2;
extern float   Cos_theta_n_k2;


extern float   Kp_ang;
extern float   Ki_ang;

extern float   Err_Vde;


/*--------------------------------------*/
/*  first order filters                 */
/*--------------------------------------*/
extern float   Freq_rate_init;
extern float   We_rate_init;

extern float   Freq_rate;
extern float   We_rate;

extern float   We;

extern float   Wgrid;

extern float   La_APF_FRI;
extern float   Lb_APF_FRI;

extern float   FL_ADC;
extern float   La_ADC;
extern float   Lb_ADC;

extern float   FL_Vin;
extern float   La_Vin;
extern float   Lb_Vin;

extern float   FL_Idc;
extern float   La_Idc;
extern float   Lb_Idc;

extern float   FL_A_ref;
extern float   La_A_ref;
extern float   Lb_A_ref;

extern float   FL_Vdc;
extern float   La_Vdc;
extern float   Lb_Vdc;

extern float   FL_Va;
extern float   La_Va;
extern float   Lb_Va;

extern float   FL_Ia;
extern float   La_Ia;
extern float   Lb_Ia;

extern float   FL_Iqe_ref;
extern float   La_Iqe_ref;
extern float   Lb_Iqe_ref;


extern float   FL_s_volt;
extern float   La_s_volt;
extern float   Lb_s_volt;

extern float   FL_e_volt;
extern float   La_e_volt;
extern float   Lb_e_volt;

/*--------------------------------------*/
/*  Overload                            */
/*--------------------------------------*/
extern float   Pinv_DQ;
extern float   Pinv_DQ_sum;
extern float   Pinv_DQ_avg;
extern float   Pinv_DQ_avg_abs;
extern float   PF_util;
extern float   PF_util_avg;
extern int     Cnt_OL;

/*--------------------------------------*/
/*  source voltages                     */
/*--------------------------------------*/
extern float   Vds;
//extern float   Vds_ref;
extern float   Vds_old;
extern float   Vds_flt;

extern float   Vqs;
//extern float   Vqs_ref;
extern float   Vqs_old;
extern float   Vqs_flt;

extern float   Vde;
extern float   Vde_C;
extern float   Vde_old;
extern float   Vde_old1;
extern float   Vde_old_C;
extern float   Vde_flt;
extern float   Vde_flt1;
extern float   Vde_flt_C;
extern float   Vde_sum;
extern float   Vde_avg;

extern float   Vqe;
extern float   Vqe_old;
extern float   Vqe_old1;
extern float   Vqe_old_C;
extern float   Vqe_flt;
extern float   Vqe_flt1;
extern float   Vqe_flt_C;
extern float   Vqe_sum;
extern float   Vqe_avg;

extern float   Vds_p;
extern float   Vds_n;
extern float   Vds_apf;

extern float   Vqs_p;
extern float   Vqs_n;
extern float   Vqs_apf;

extern float   Vde_p;
extern float   Vde_n;
extern float   Vde_L;

extern float   Vqe_p;
extern float   Vqe_n;
extern float   Vqe_L;

extern float   Vde_p_old;
extern float   Vde_n_old;
extern float   Vqe_p_old;
extern float   Vqe_n_old;

extern float   Vde_p_flt;
extern float   Vde_n_flt;
extern float   Vqe_p_flt;
extern float   Vqe_n_flt;


extern float   Vde_dc;
extern float   Vqe_dc;
extern float   Vde_dc_sum;


extern float   Vsrc_dz;

extern int     Cnt_SEQ;
extern int     POL_Vds;
extern int     POL_Vqs;
extern int     SEQ_Vsrc;

extern float   Ids;
extern float   Ids_p;
extern float   Ids_n;
extern float   Ids_old;
extern float   Ids_apf;

extern float   Iqs;
extern float   Iqs_p;
extern float   Iqs_n;
extern float   Iqs_old;
extern float   Iqs_apf;

extern float   Ide;
extern float   Ide_p;
extern float   Ide_n;

extern float   Iqe;
extern float   Iqe_p;
extern float   Iqe_n;

extern float   Ide_p_old;
extern float   Ide_n_old;
extern float   Iqe_p_old;
extern float   Iqe_n_old;

extern float   Ide_p_flt;
extern float   Ide_n_flt;
extern float   Iqe_p_flt;
extern float   Iqe_n_flt;

extern float   Em;

extern float   Kp_PLL;
extern float   Ki_PLL;

extern float   Vde_err;
extern float   W_delta_intg;
extern float   W_delta;

extern float   Theta_h;
//extern float   Wgrid;

extern float Ide_5th_p , Iqe_5th_p, Ide_5th_old_p ,  Iqe_5th_old_p ;
extern float Angle_Grid_p , Ide_5th_flt_p , Iqe_5th_flt_p ;
extern float Ide_5th_n , Iqe_5th_n , Ide_5th_old_n ,  Iqe_5th_old_n ;
extern float Angle_Grid_n , Ide_5th_flt_n , Iqe_5th_flt_n ;
extern float Idsp , Iqsp , Idsn , Iqsn ;
extern float Fc_I_5th , Wc_I_5th , La_I_5th , Lb_I_5th ;

extern float  Ide_5th_err_p ,  Iqe_5th_err_p ;
extern float  Vde_5th_ref_fb_p ,  Vqe_5th_ref_fb_p ;
extern float  Vqe_5th_integ_p ,   Vde_5th_integ_p ;
extern float  Vqe_5th_ref_p ,   Vde_5th_ref_p;
extern float  Vqs_5th_ref_p ,   Vds_5th_ref_p;

extern float  Ide_5th_err_n ,  Iqe_5th_err_n ;
extern float  Vde_5th_ref_fb_n ,  Vqe_5th_ref_fb_n ;
extern float  Vqe_5th_integ_n ,   Vde_5th_integ_n;
extern float  Vqe_5th_ref_n ,   Vde_5th_ref_n ;
extern float  Vqs_5th_ref_n ,   Vds_5th_ref_n ;

extern float Kp_CC_Grid_comp_5th , Ki_CC_Grid_comp_5th ;
extern float Va, Vb, Vc ;
extern float Ia_PLL3_harmonic_k;


extern float Ide_5th_p , Iqe_5th_p, Ide_5th_old_p ,  Iqe_5th_old_p ;
extern float Angle_Grid_p , Ide_5th_flt_p , Iqe_5th_flt_p ;
extern float Ide_5th_n , Iqe_5th_n , Ide_5th_old_n ,  Iqe_5th_old_n ;
extern float Angle_Grid_n , Ide_5th_flt_n , Iqe_5th_flt_n ;
extern float Idsp , Iqsp , Idsn , Iqsn ;
extern float Fc_I_5th , Wc_I_5th , La_I_5th , Lb_I_5th ;

extern float  Ide_5th_err_p ,  Iqe_5th_err_p ;
extern float  Vde_5th_ref_fb_p ,  Vqe_5th_ref_fb_p ;
extern float  Vqe_5th_integ_p ,   Vde_5th_integ_p ;
extern float  Vqe_5th_ref_p ,   Vde_5th_ref_p;
extern float  Vqs_5th_ref_p ,   Vds_5th_ref_p;

extern float  Ide_5th_err_n ,  Iqe_5th_err_n ;
extern float  Vde_5th_ref_fb_n ,  Vqe_5th_ref_fb_n ;
extern float  Vqe_5th_integ_n ,   Vde_5th_integ_n;
extern float  Vqe_5th_ref_n ,   Vde_5th_ref_n ;
extern float  Vqs_5th_ref_n ,   Vds_5th_ref_n ;

extern float Kp_CC_Grid_comp_5th , Ki_CC_Grid_comp_5th ;
extern float Va, Vb, Vc ;
extern float Ia_PLL3_harmonic_k;



extern float Ide_5th_p1 , Iqe_5th_p1, Ide_5th_old_p1 ,  Iqe_5th_old_p1 ;
extern float Angle_Grid_p1 , Ide_5th_flt_p1 , Iqe_5th_flt_p1 ;
extern float Ide_5th_n1 , Iqe_5th_n1 , Ide_5th_old_n1 ,  Iqe_5th_old_n1 ;
extern float Angle_Grid_n1 , Ide_5th_flt_n1 , Iqe_5th_flt_n1 ;
//extern float Idsp , Iqsp , Idsn , Iqsn ;
//extern float Fc_I_5th , Wc_I_5th , La_I_5th , Lb_I_5th ;

extern float  Ide_5th_err_p1 ,  Iqe_5th_err_p1 ;
extern float  Vde_5th_ref_fb_p1 ,  Vqe_5th_ref_fb_p1 ;
extern float  Vqe_5th_integ_p1 ,   Vde_5th_integ_p1 ;
extern float  Vqe_5th_ref_p1 ,   Vde_5th_ref_p1;
extern float  Vqs_5th_ref_p1 ,   Vds_5th_ref_p1;

extern float  Ide_5th_err_n1 ,  Iqe_5th_err_n1 ;
extern float  Vde_5th_ref_fb_n1 ,  Vqe_5th_ref_fb_n1 ;
extern float  Vqe_5th_integ_n1 ,   Vde_5th_integ_n1;
extern float  Vqe_5th_ref_n1 ,   Vde_5th_ref_n1 ;
extern float  Vqs_5th_ref_n1 ,   Vds_5th_ref_n1 ;

extern float Kp_CC_Grid_comp_5th1 , Ki_CC_Grid_comp_5th1 ;
extern float Va1, Vb1, Vc1 ;
extern float Ia_PLL3_harmonic_k1;



extern float Ide_5th_p2 , Iqe_5th_p2, Ide_5th_old_p2 ,  Iqe_5th_old_p2 ;
extern float Angle_Grid_p2 , Ide_5th_flt_p2 , Iqe_5th_flt_p2 ;
extern float Ide_5th_n2 , Iqe_5th_n2 , Ide_5th_old_n2 ,  Iqe_5th_old_n2 ;
extern float Angle_Grid_n2 , Ide_5th_flt_n2 , Iqe_5th_flt_n2 ;
//extern float Idsp , Iqsp , Idsn , Iqsn ;
//extern float Fc_I_5th , Wc_I_5th , La_I_5th , Lb_I_5th ;

extern float  Ide_5th_err_p2 ,  Iqe_5th_err_p2 ;
extern float  Vde_5th_ref_fb_p2 ,  Vqe_5th_ref_fb_p2 ;
extern float  Vqe_5th_integ_p2 ,   Vde_5th_integ_p2 ;
extern float  Vqe_5th_ref_p2 ,   Vde_5th_ref_p2;
extern float  Vqs_5th_ref_p2 ,   Vds_5th_ref_p2;

extern float  Ide_5th_err_n2 ,  Iqe_5th_err_n2 ;
extern float  Vde_5th_ref_fb_n2 ,  Vqe_5th_ref_fb_n2 ;
extern float  Vqe_5th_integ_n2 ,   Vde_5th_integ_n2;
extern float  Vqe_5th_ref_n2 ,   Vde_5th_ref_n2 ;
extern float  Vqs_5th_ref_n2 ,   Vds_5th_ref_n2 ;

extern float Kp_CC_Grid_comp_5th2 , Ki_CC_Grid_comp_5th2 ;
extern float Va2, Vb2, Vc2 ;
extern float Ia_PLL3_harmonic_k2;


extern float Ide_5th_p3 , Iqe_5th_p3, Ide_5th_old_p3 ,  Iqe_5th_old_p3 ;
extern float Angle_Grid_p3 , Ide_5th_flt_p3 , Iqe_5th_flt_p3 ;
extern float Ide_5th_n3 , Iqe_5th_n3 , Ide_5th_old_n3 ,  Iqe_5th_old_n3 ;
extern float Angle_Grid_n3 , Ide_5th_flt_n3 , Iqe_5th_flt_n3 ;
//extern float Idsp , Iqsp , Idsn , Iqsn ;
//extern float Fc_I_5th , Wc_I_5th , La_I_5th , Lb_I_5th ;

extern float  Ide_5th_err_p3 ,  Iqe_5th_err_p3 ;
extern float  Vde_5th_ref_fb_p3 ,  Vqe_5th_ref_fb_p3 ;
extern float  Vqe_5th_integ_p3 ,   Vde_5th_integ_p3 ;
extern float  Vqe_5th_ref_p3 ,   Vde_5th_ref_p3;
extern float  Vqs_5th_ref_p3 ,   Vds_5th_ref_p3;

extern float  Ide_5th_err_n3 ,  Iqe_5th_err_n3 ;
extern float  Vde_5th_ref_fb_n3 ,  Vqe_5th_ref_fb_n3 ;
extern float  Vqe_5th_integ_n3 ,   Vde_5th_integ_n3;
extern float  Vqe_5th_ref_n3 ,   Vde_5th_ref_n3 ;
extern float  Vqs_5th_ref_n3 ,   Vds_5th_ref_n3 ;

extern float Kp_CC_Grid_comp_5th3 , Ki_CC_Grid_comp_5th3 ;
extern float Va3, Vb3, Vc3 ;
extern float Ia_PLL3_harmonic_k3;


extern float Kp_5th_ref;

/*--------------------------------------*/
/*  source Frequence                    */
/*--------------------------------------*/
extern int     Flag_FreqLowHigh;
extern int     Count_freq1;
extern int     Count_freq2;

extern int     Cnt_freq_max;
extern int     Cnt_freq1_max;
extern int     Cnt_freq2_max;

extern int     Cnt_freq_max_sum;

extern int     Cnt_freq_max_old1;
extern int     Cnt_freq_max_old2;
extern int     Cnt_freq_max_old3;
extern int     Cnt_freq_max_old4;
extern int     Cnt_freq_max_old5;
extern int     Cnt_freq_max_old6;
extern int     Cnt_freq_max_old7;
extern int     Cnt_freq_max_old8;

extern int     Cnt_freq1_old;
extern int     Cnt_freq2_old;

extern int     Cnt_freq_high;
extern int     Cnt_freq_low;
extern int     Cnt_freq_time;

extern int     Detec_range_Freq;
extern int     FreqDetec_time;

extern int     Cnt_freqDetec_time;

extern float   Freq_out;
extern float   Freq_source_period;
extern float   Freq_out_avg;
extern float   Freq_out_sum;

extern float   Freq_out_old;
extern float   Freq_out_old1;
extern float   Freq_out_old2;
extern float   Freq_out_old3;
extern float   Freq_out_old4;
extern float   Freq_out_old5;

extern float   Freq_high;
extern float   Freq_low;

extern float   Flag_Act_islanding_input;
extern float   Flag_Act_islanding;
extern float   Cnt_Act_islanding;

extern float   Freq_shift_max;
extern float   Freq_shift_low;
extern float   Freq_shift_init;

extern float   Freq_jump;
extern int     Freq_jump_cnt;

extern float   Freq_shift_ratio_input;
extern float   Freq_shift_ratio;

extern int     Cnt_Freq_out;
extern int     Cnt_Freq_high;
extern int     Cnt_Freq_low;

/*--------------------------------------*/
/*  source PLL                          */
/*--------------------------------------*/
extern int     Flag_Va_PLL3;
extern int     Flag_Ia_PLL3;

extern int     flag_control_parameter;

/*--------------------------------------*/
/*  source err                          */
/*--------------------------------------*/
extern int     Flag_Grid_err;

/*--------------------------------------*/
/*  time check                          */
/*--------------------------------------*/
extern int     time_check_cnt;

/*--------------------------------------*/
/*  RTC check                          */
/*--------------------------------------*/
extern int      Enb_RTC_mode;
extern int      Enb_RTC_init;
extern int      Flag_RTC_init;
extern int      Flag_RTC_init_cnt;

extern int      rtc_write_data2[6];

extern int     time_Read_year;
extern int     time_Read_mon_day;
extern int     time_Read_hour_min;
extern int     time_Read_sec;

extern int     wr_time_Sel_Wr;
extern int     wr_time_Set_year;
extern int     wr_time_Set_mon_day;
extern int     wr_time_Set_hour_min;
extern int     wr_time_Set_sec;


#endif /* HEADER__GLOBALVAL_H_ */
