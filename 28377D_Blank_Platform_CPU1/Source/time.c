
#include "Define.h"

//#define CTRL_TIME (100.0e-6);   // timer0 : 10KHz
//#define CTRL_TIME (50.e-6);     // timer0 : 20KHz
//#define CTRL_TIME (33.3e-6);    // timer0 : 30KHz
//#define CTRL_TIME (25.0e-6);    // timer0 : 40KHz

//new setting : 28335 ref view
/*--------------------------------------*/
/*  control B/D setting & period        */
/*--------------------------------------*/
float   System_clock        = 200.e6;   // TMS320F28377D system clock : 200[MHz]
float   Scale_gating        = 0.;       // gating clock 100MHz-> H1
float   Scale_gating_con    = 0.;       // gating clock 100MHz-> H1

//float   Freq_ctrl           = 4.;      // control frequency[KHz] : 16 -> Tsamp = 66.6[usec]
//float   Freq_ctrl           = 15.;      // control frequency[KHz] : 16 -> Tsamp = 66.6[usec]
//float   Freq_ctrl           = 16.2;      // control frequency[KHz] : 16 -> Tsamp = 66.6[usec]
//float   Freq_ctrl           = 16.5;      // control frequency[KHz] : 16 -> Tsamp = 66.6[usec]
float   Freq_ctrl           = 17.4;      // control frequency[KHz] : 16 -> Tsamp = 66.6[usec]
//float   Freq_ctrl           = 17.5;      // control frequency[KHz] : 16 -> Tsamp = 66.6[usec]
//float   Freq_ctrl           = 18.;      // control frequency[KHz] : 16 -> Tsamp = 66.6[usec]
//float   Freq_ctrl           = 20.;      // control frequency[KHz] : 16 -> Tsamp = 66.6[usec]
//float   Freq_ctrl           = 25.;      // control frequency[KHz] : 16 -> Tsamp = 66.6[usec]
//float   Freq_ctrl           = 30.;      // control frequency[KHz] : 16 -> Tsamp = 66.6[usec]

//15kHz = Relay = 674mA, Gating 760mA, 5V -> 3.8W




//float   Freq_ctrl_con       = 15.;      // control frequency[KHz] : 16 -> Tsamp = 66.6[usec]
//15kHz = Relay 160mA, Gating 630mA, 5V -> 3.15W -> 6.3W

float   Freq_ctrl_con       = 17.4;      // control frequency[KHz] : 16 -> Tsamp = 66.6[usec]
//float   Freq_ctrl_con       = 17.5;      // control frequency[KHz] : 16 -> Tsamp = 66.6[usec]
//17.5kHz = Relay 160mA, Gating 702mA, 5V -> 3.5W -> 7.0W

//float   Freq_ctrl_con       = 20.;      // control frequency[KHz] : 16 -> Tsamp = 66.6[usec]
//17.5kHz = Relay 160mA, Gating 772mA, 5V -> 3.86W -> 7.72W



float   Tsamp               = 0.;       // timer0 : 15KHz
float   Tsamp_con           = 0.;       // timer0 : 15KHz

int     rout_cntl_count     = 0;
int     rout_1000ms_count   = 0;
int     rout_100ms_count    = 0;
int     rout_10ms_count     = 0;
int     rout_1ms_count      = 0;
int     rout_250us_count    = 0;
int     rout_2ms_count      = 0;
int     rout_500ms_count    = 0;
int     rout_500us_count    = 0;

float   rout_10ms_count_float = 0;

float   Timer_clock         = 0.; // timer clk period[sec]
int     Timer_Tsamp         = 0;    // timer0 period
int     Timer_Tsamp2        = 0;   // timer1 period

float   T_250us             = 250.0e-6;
float   T_500us             = 500.0e-6;
float   T_1ms               = 1.e-3;
float   T_2ms               = 2.e-3;       // rout2m.c
float   T_10ms              = 10.e-3;     // rofut10m.c
float   T_100ms             = 100.e-3;   // rout100m.c
float   T_500ms             = 500.e-3;   // rout500m.c
float   T_1000ms            = 1000.e-3; // rout500m.c

float   INV_Tsamp           = 0.;
float   INV_T_250us         = 0.;
float   INV_T_500us         = 0.;
float   INV_T_1ms           = 0.;
float   INV_T_2ms           = 0.;
float   INV_T_10ms          = 0.;
float   INV_T_100ms         = 0.;
float   INV_T_500ms         = 0.;
float   INV_T_1000ms        = 0.;

float   Tsamp_INV_T_2ms     = 0.;
float   T_2ms_INV_T_100ms   = 0.;
float   Tsamp_INV_T_100ms   = 0.;


int     Set_T_250us         = 0;
int     Cnt_T_250us         = 0;
int     Flag_T_250us        = 0;

int     Set_T_500us         = 0;
int     Cnt_T_500us         = 0;
int     Flag_T_500us        = 0;

int     Set_T_1ms           = 0;
int     Cnt_T_1ms           = 0;
int     Flag_T_1ms          = 0;

int     Set_T_2ms           = 0;
int     Cnt_T_2ms           = 0;
int     Flag_T_2ms          = 0;

int     Set_T_10ms          = 0;
int     Cnt_T_10ms          = 0;
int     Flag_T_10ms         = 0;

int     Set_T_100ms         = 0;
int     Cnt_T_100ms         = 0;
int     Flag_T_100ms        = 0;

int     Set_T_500ms         = 0;
int     Cnt_T_500ms         = 0;
int     Flag_T_500ms        = 0;

int     Set_T_1000ms        = 0;
int     Cnt_T_1000ms        = 0;
int     Flag_T_1000ms       = 0;

/*--------------------------------------*/
/*  sequence(time, counter,...)         */
/*--------------------------------------*/
int     Flag_offset         = 0;     // program stage : (0~2)offset,(3)control
int     Offset_cnt          = 0;

float   TOL_offset          = 30.;   // [%] of max. scale


float   Time_offset_wait    = 0.5;   //  waiting time after offset routine
int     Cnt_offset_wait     = 0;
int     Set_offset_wait     = 0;


void Init_Variables()
{
    float   a=0.,b=0.;

#if 0
    #ifdef _BLACKBOX
    Tsamp = init_blackbox.ctrl_period;
    #endif
#endif

/*--------------------------------------*/
/*  system variables initialize         */
/*--------------------------------------*/
//Control Freq, time, count
#if 1
    if( (Freq_ctrl <= 30.) && (Freq_ctrl >= 4.) )
    {
//        Tsamp = 1. / (Freq_ctrl * 1000.);
//        Tsamp = (1. / (Freq_ctrl * 1000.)) * 0.5;   //epwm = 3, 2cnt = * 0.5
        Tsamp = (1. / (Freq_ctrl * 1000.)) * Mode_SOCAPRD;   //2번 1회 2cnt = * 2(Mode_SOCAPRD)
    }
#endif



    if( (Freq_ctrl_con <= 20.) && (Freq_ctrl_con >= 4.) )
    {
        Tsamp_con   = 1. / (Freq_ctrl_con * 1000.);
    }

    Timer_Tsamp     = (int)(Tsamp * 1.e6 + 0.5);        // timer0(Tsamp)
    Timer_Tsamp2    = (int)(Tsamp * 1.e6 * 0.5 + 0.5); // timer1(Tsamp/2 =  125usec)

    INV_Tsamp       = 1. / Tsamp;
    INV_T_250us     = 1. / T_250us;
    INV_T_500us     = 1. / T_500us;
    INV_T_1ms       = 1. / T_1ms;
    INV_T_2ms       = 1. / T_2ms;
    INV_T_10ms      = 1. / T_10ms;
    INV_T_100ms     = 1. / T_100ms;
    INV_T_500ms     = 1. / T_500ms;
    INV_T_1000ms    = 1. / T_1000ms;

    Tsamp_INV_T_2ms     = Tsamp / T_2ms;
    T_2ms_INV_T_100ms   = T_2ms / T_100ms;
    Tsamp_INV_T_100ms   = Tsamp / T_100ms;

    Cnt_T_250us     = Set_T_250us   = (int)(T_250us     * INV_Tsamp     + 0.5);
    Cnt_T_500us     = Set_T_500us   = (int)(T_500us     * INV_Tsamp     + 0.5);
    Cnt_T_1ms       = Set_T_1ms     = (int)(T_1ms       * INV_Tsamp     + 0.5);
    Cnt_T_2ms       = Set_T_2ms     = (int)(T_2ms       * INV_Tsamp     + 0.5);
    Cnt_T_10ms      = Set_T_10ms    = (int)(T_10ms      * INV_Tsamp     + 0.5);
    Cnt_T_100ms     = Set_T_100ms   = (int)(T_100ms     * INV_T_10ms    + 0.5);
    Cnt_T_500ms     = Set_T_500ms   = (int)(T_500ms     * INV_T_100ms   + 0.5);
    Cnt_T_1000ms    = Set_T_1000ms  = (int)(T_1000ms    * INV_T_500ms   + 0.5);

    Cnt_offset_wait = Set_offset_wait = (int)(Time_offset_wait * INV_Tsamp + 0.5);

/*--------------------------------------*/
/*  PWM count, dead time initialize     */
/*--------------------------------------*/
    // pwm inv clock setting = 50MHz -> (200MHz * 0.5), HSPCLKDIV(0.5), CLKDIV(1)
//    Scale_gating        = System_clock * 0.25;           // gating clock : H1
    Scale_gating        = System_clock * 0.5;           // gating clock : H1

    // pwm con clock setting = 50MHz -> (200MHz * 0.5), HSPCLKDIV(0.5), CLKDIV(1)
    Scale_gating_con    = System_clock * 0.25;           // gating clock : H1

    Mode_gating     = Mode_gating_input;                 // only update at initial routine
    Mode_gating_con = Mode_gating_con_input;             // only update at initial routine

    //CNT_max, CNT_max_con = 4095 이하로 설계되어야 함. PWM 비교 max 0xfff
    if(Mode_gating == 1)
    {
//        CNT_max = (int)( (Tsamp * 0.5) * Scale_gating);    // full gate mode
//        CNT_max = (int)( (Tsamp * 0.5) * Scale_gating)  * 2;    // full gate mode, //epwm = 3, 2cnt = * 0.5 -> * 2
        CNT_max = (int)( ((Tsamp * 0.5) * Scale_gating)  * (1. / Mode_SOCAPRD));    //2번 1회 2cnt = * 2 = * 2 -> * 0.5 -> 1 / Mode_SOCAPRD
    }
    else
    {
//        CNT_max = (int)( (Tsamp) * Scale_gating);           // half-gate mode
//        CNT_max = (int)( (Tsamp) * Scale_gating) * 2;           // half-gate mode, //epwm = 3, 2cnt = * 0.5 -> * 2
        CNT_max = (int)( ((Tsamp) * Scale_gating)  * (1 / Mode_SOCAPRD));    //2번 1회 2cnt = * 2 = * 2 -> * 0.5 -> 1 / Mode_SOCAPRD
    }

    if(Mode_gating_con == 1)
    {
        CNT_max_con = (int)( (Tsamp_con * 0.5) * Scale_gating_con);    // full gate mode
    }
    else
    {
        CNT_max_con = (int)( (Tsamp_con) * Scale_gating_con);           // half-gate mode
    }

    CNT_max_98      = (int)(CNT_max     * 0.98);
    CNT_max_95      = (int)(CNT_max     * 0.95);
    CNT_max_90      = (int)(CNT_max     * 0.9);
    CNT_max_80      = (int)(CNT_max     * 0.8);
    CNT_max_70      = (int)(CNT_max     * 0.7);
    CNT_max_60      = (int)(CNT_max     * 0.6);
    CNT_max_50      = (int)(CNT_max     * 0.5);

    CNT_max_40      = (int)(CNT_max     * 0.4);
    CNT_max_30      = (int)(CNT_max     * 0.3);
    CNT_max_20      = (int)(CNT_max     * 0.2);
    CNT_max_10      = (int)(CNT_max     * 0.1);
    CNT_max_5       = (int)(CNT_max     * 0.05);
    CNT_max_2       = (int)(CNT_max     * 0.02);

    CNT_max_con_98      = (int)(CNT_max_con * 0.98);
    CNT_max_con_95      = (int)(CNT_max_con * 0.95);
    CNT_max_con_90      = (int)(CNT_max_con * 0.9);
    CNT_max_con_80      = (int)(CNT_max_con * 0.8);
    CNT_max_con_70      = (int)(CNT_max_con * 0.7);
    CNT_max_con_60      = (int)(CNT_max_con * 0.6);
    CNT_max_con_50      = (int)(CNT_max_con * 0.5);
    CNT_max_con_49_5    = (int)(CNT_max_con * 0.495);
    CNT_max_con_40      = (int)(CNT_max_con * 0.4);
    CNT_max_con_30      = (int)(CNT_max_con * 0.3);
    CNT_max_con_20      = (int)(CNT_max_con * 0.2);
    CNT_max_con_10      = (int)(CNT_max_con * 0.1);
    CNT_max_con_5       = (int)(CNT_max_con * 0.05);
    CNT_max_con_2       = (int)(CNT_max_con * 0.02);

    T_dead_comp_input     = T_dead_input;     // DT comp. time[sec]

    T_dead          = T_dead_input          * 1.e-6;     // dead-time[sec]
    T_dead_con      = T_dead_con_input      * 1.e-6;     // dead-time[sec]
    T_dead_comp     = T_dead_comp_input     * 1.e-6;     // DT comp. time[sec]
    T_dead_onoff    = T_dead_onoff_input    * 1.e-6;     // gating off-delay[sec]

    T_dead_CNT          = (int)(T_dead          * Scale_gating);
    T_dead_con_CNT      = (int)(T_dead_con      * Scale_gating_con);
    T_dead_comp_CNT     = (int)(T_dead_comp     * Scale_gating);
    T_dead_onoff_CNT    = (int)(T_dead_onoff    * Scale_gating);

//    CNT_max_con_dead_50 = T_dead_con_CNT + 50;
    T_dead_con_CNT_50 = T_dead_con_CNT + 50;

/*--------------------------------------*/
/*  control variables initialize        */
/*--------------------------------------*/
    Mode_system         = Mode_system_input;

    Mode_pwm            = Mode_pwm_input;    // (1)SVPWM,(0)SPWM
    Idc_ref_mode        = Idc_ref_mode_input;

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
    Overload_Pout       = Pout_rate     * (OL_ratio         * 0.01);

    OV_set_Vin_test     = OV_set_Vin;
    UV_set_Vin_test     = UV_set_Vin;
    OC_Idc_set_test     = OC_Idc_set;

    OV_set_Vdc_test     = OV_set_Vdc;
    UV_set_Vdc_test     = UV_set_Vdc;

    OV_set_src_test     = OV_set_src;
    UV_set_src_test     = UV_set_src;
    INTER_set_src_test  = INTER_set_src;

    OV_set_src_rms_test  = OV_set_src_rms;
    UV_set_src_rms_test  = UV_set_src_rms;

    OC_set_test         = OC_set;


    Vin_MC_ON_level     = Vin_min   + 1;
    Vin_MC_OFF_level    = Vin_min   - 1;

    Vin_max_80          = Vin_max * 0.8;
    Vin_min_2           = Vin_min + 2;

    Idc_limit_con       = Idc_max;


    AC_MC_ON_level      = Vl_rate       * SQRT2 * (AC_MC_ON_ratio     * 0.01);
    AC_MC_OFF_level     = Vl_rate       * SQRT2 * (AC_MC_OFF_ratio    * 0.01);


//  Vdc_ref_inv_input       = Vl_rate * SQRT2_SQRT3 * 0.01 * Vdc_ref_inv_ratio; //test mode
    Vdc_ref_inv             = Vdc_ref_inv_input;
    Ip_ref_real_max_input   = Ic_rate_peak  * (Ip_ref_ratio     * 0.01);    // over-current
    Ip_ref_real_max         = Ip_ref_real_max_input;                         // over-current

    Vdc_ref_con_set_input   = Vdc_ref_inv + Vdc_ref_con_set_level;
    Vdc_ref_con_set         = Vdc_ref_con_set_input;
    Idc_ref_comp            = Idc_ref_comp_input;

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

    K_cc[CKP]   = Lc        * Wc_CC     * INV_Alpha_CC                          * (K_cc_ratio[CKP]      * 0.01) * (Kp_Ia_ratio       * 0.01);
    K_cc[CKIT]  = (Wc_CC    * ((1. - Alpha_CC)  * K_cc[CKP] + Rc)   * Tsamp)    * (K_cc_ratio[CKIT]     * 0.01) * (Ki_Ia_ratio       * 0.01);
    K_cc[CKA]   = 1. / K_cc[CKP]                                                * (K_cc_ratio[CKA]      * 0.01);

    K_cc[CKPD]   = Lc        * Wc_CC     * INV_Alpha_CC                         * (K_cc_ratio[CKPD]     * 0.01) * (Kp_Ia_ratio_D     * 0.01);
    K_cc[CKITD]  = (Wc_CC    * ((1. - Alpha_CC) * K_cc[CKPD] + Rc)   * Tsamp)   * (K_cc_ratio[CKITD]    * 0.01) * (Ki_Ia_ratio_D     * 0.01);
    K_cc[CKAD]   = 1. / K_cc[CKPD]                                              * (K_cc_ratio[CKAD]     * 0.01);

    Kp_iqe  = K_cc[CKP];
    Ki_iqe  = K_cc[CKIT];
    Ka_iqe  = K_cc[CKA];

    Kp_ide = K_cc[CKPD];
    Ki_ide = K_cc[CKITD];
    Ka_ide = K_cc[CKAD];


/*--------------------------------------*/
/*  multi-controller initialize         */
/*--------------------------------------*/
    Sin_theta   = Cos_theta = 0.;

    b   = We    * (0.7  * Tsamp);
    a   = b * b;

    Sin_thetaT  = SIN(b, a);
    Cos_thetaT  = COS(a);


/*--------------------------------------*/
/*  first-order filter(LPF)             */
/*--------------------------------------*/
    We_rate         = PI_MPY_2    * Freq_rate;
    We              = PI_MPY_2    * Freq_rate;
    We_rate_init    = PI_MPY_2    * Freq_rate_init;

    //all pass filter
    Wgrid           = We_rate_init;
    a               = We_rate_init; // APF(Freq_rate_init)
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

/*--------------------------------------*/
/*  A/D scale initialize                */
/*--------------------------------------*/
#if 0
    Scale_12bit_ADC1    =   Scale_12bit_ADC1_input  * Scale_12bit_ADC1_ratio    * INV_12bit_AD_SCALE;
    Scale_12bit_ADC2    =   Scale_12bit_ADC2_input  * Scale_12bit_ADC2_ratio    * INV_12bit_AD_SCALE;
    Scale_12bit_ADC3    =   Scale_12bit_ADC3_input  * Scale_12bit_ADC3_ratio    * INV_12bit_AD_SCALE;
    Scale_12bit_ADC4    =   Scale_12bit_ADC4_input  * Scale_12bit_ADC4_ratio    * INV_12bit_AD_SCALE;
    Scale_12bit_ADC5    =   Scale_12bit_ADC5_input  * Scale_12bit_ADC5_ratio    * INV_12bit_AD_SCALE;
    Scale_12bit_ADC6    =   Scale_12bit_ADC6_input  * Scale_12bit_ADC6_ratio    * INV_12bit_AD_SCALE;
    Scale_12bit_ADC7    =   Scale_12bit_ADC7_input  * Scale_12bit_ADC7_ratio    * INV_12bit_AD_SCALE;
    Scale_12bit_ADC8    =   Scale_12bit_ADC8_input  * Scale_12bit_ADC8_ratio    * INV_12bit_AD_SCALE;
    Scale_12bit_ADC9    =   Scale_12bit_ADC9_input  * Scale_12bit_ADC9_ratio    * INV_12bit_AD_SCALE;
    Scale_12bit_ADC10   =   Scale_12bit_ADC10_input * Scale_12bit_ADC10_ratio   * INV_12bit_AD_SCALE;
    Scale_12bit_ADC11   =   Scale_12bit_ADC11_input * Scale_12bit_ADC11_ratio   * INV_12bit_AD_SCALE;
    Scale_12bit_ADC12   =   Scale_12bit_ADC12_input * Scale_12bit_ADC12_ratio   * INV_12bit_AD_SCALE;
    Scale_12bit_ADC13   =   Scale_12bit_ADC13_input * Scale_12bit_ADC13_ratio   * INV_12bit_AD_SCALE;
    Scale_12bit_ADC14   =   Scale_12bit_ADC14_input * Scale_12bit_ADC14_ratio   * INV_12bit_AD_SCALE;
    Scale_12bit_ADC15   =   Scale_12bit_ADC15_input * Scale_12bit_ADC15_ratio   * INV_12bit_AD_SCALE;
    Scale_12bit_ADC16   =   Scale_12bit_ADC16_input * Scale_12bit_ADC16_ratio   * INV_12bit_AD_SCALE;

    Scale_16bit_ADC17   =   Scale_16bit_ADC17_input * Scale_16bit_ADC17_ratio    * INV_16bit_AD_SCALE;
    Scale_16bit_ADC18   =   Scale_16bit_ADC18_input * Scale_16bit_ADC18_ratio    * INV_16bit_AD_SCALE;
#endif

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

//------------------------------------------------------------------------------------------------//
