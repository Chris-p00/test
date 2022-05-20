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


void Va_PLL3()
{
    register float  a;
    register float  a_comp;
    int     i   = 0;

/*--------------------------------------*/
/*  axis-transform of source voltage    */
/*--------------------------------------*/
// INV2_3 = 2/3, INV_2 = 1/2, INV_3 = 1/3;
    Vds = INV2_3    * (Esa  - Esb   * INV_2 - Esc * INV_2);
    Vqs = INV_SQRT3 * (Esb  - Esc);


    //check mode chage define need
    if(mode_Va_PLL3 == 1)
    {
//      Vde     =   Cos_theta           * Vds + Sin_theta   * Vqs   + (-sin(Theta+PI_INV_2) * Vds + cos(Theta+PI_INV_2) * Vqs)  * 0.9 ;//jyp
        Vde     =   Cos_theta           * Vds + Sin_theta   * Vqs   + (-Sin_theta_90        * Vds + Cos_theta_90        * Vqs)  * 0.9 ;//jyp

        Vqe     =  -Sin_theta           * Vds + Cos_theta   * Vqs;

//      Vde_C   =  Cos_theta_C          * Vds + Sin_theta_C * Vqs   + (-sin(Theta_C+PI_INV_2)   * Vds + cos(Theta_C+PI_INV_2)   * Vqs) * 0.9  ;//jy
        Vde_C   =  Cos_theta_C          * Vds + Sin_theta_C * Vqs   + (-Sin_theta_C_90          * Vds + Cos_theta_C_90          * Vqs) * 0.9  ;//jyp
    }
    else
    {
        Vde     =  Cos_theta            * Vds + Sin_theta   * Vqs;
        Vqe     =  -Sin_theta           * Vds + Cos_theta   * Vqs;
        Vde_C   =  Cos_theta_C          * Vds + Sin_theta_C * Vqs;
    }

    Vde_flt     = La_e_volt * Vde_flt   + Lb_e_volt * (Vde   + Vde_old);        Vde_old     = Vde;
    Vqe_flt     = La_e_volt * Vqe_flt   + Lb_e_volt * (Vqe   + Vqe_old);        Vqe_old     = Vqe;
    Vde_flt_C   = La_e_volt * Vde_flt_C + Lb_e_volt * (Vde_C + Vde_old_C);      Vde_old_C   = Vde_C;


/*--------------------------------------------------*/
/*  phase angle detecting & sine/cosine calculate   */
/*--------------------------------------------------*/
    Theta_old   = Theta;
    Theta_comp3 = Theta_comp3 + Kp_ang * (-Vde_flt - Err_Vde) + Tsamp * Ki_ang * (-Vde_flt);
    Err_Vde     = -Vde_flt;
    Theta       = Theta + We_rate_init * Tsamp + Theta_comp3;

    Theta       = BOUND_PI(Theta);                          // theta bound ( -PI ~ PI)
    a           = Theta * Theta;
    Sin_theta   = SIN(Theta, a);
    Cos_theta   = COS(a);

    a               = (Theta    + PI_INV_2) * (Theta    + PI_INV_2);
    Sin_theta_90    = SIN(Theta + PI_INV_2, a);
    Cos_theta_90    = COS(a);


    Theta_comp_out  = Theta_comp_out + Kp_ang * (-Vde_flt_C - Err_Vde_C) + Tsamp * Ki_ang * (-Vde_flt_C);
    Err_Vde_C       = -Vde_flt_C + Err_theta_comp;
    Theta_C         = Theta_C + We_rate*Tsamp+ Theta_comp_out;

    Theta_C     = BOUND_PI(Theta_C);                // theta bound ( -PI ~ PI)
    a_comp      = Theta_C * Theta_C;

#if 1
    //real test mode
    Sin_theta_C = SIN(Theta_C, a_comp);
    Cos_theta_C = COS(a_comp);
#endif

#if 0
    //only test mode
    Sin_theta_C = Sin_theta;
    Cos_theta_C = Cos_theta;
#endif

    a               = (Theta_C      + PI_INV_2) * (Theta_C  + PI_INV_2);
    Sin_theta_C_90  = SIN(Theta_C   + PI_INV_2, a);
    Cos_theta_C_90  = COS(a);

/*---- Frequence Low/High ----*/
    if(Theta * Theta_old < 0.)
    {
        if(Theta < 0.)
        {
            Flag_FreqLowHigh    ^= 1;
        }
    }

    if(Flag_FreqLowHigh == 1)
    {
        if(Cnt_freq2_old > 100)
        {
            Cnt_freq2_max   = Cnt_freq2_old;
            Count_freq2     = 0;

            Count_freq1++;
            Cnt_freq1_old   = Count_freq1;
        }
        else
        {
            Cnt_freq2_max = 0;
        }
    }
    else
    {
        if(Cnt_freq1_old > 100)
        {
            Cnt_freq1_max   = Cnt_freq1_old;
            Count_freq1     = 0;

            Count_freq2++;
            Cnt_freq2_old   = Count_freq2;
        }
        else
        {
            Cnt_freq1_max=0;
        }
    }

    Theta_old = Theta;

/*----------------------------*/

/*--------------------------------------*/
/*  detection of currents               */
/*--------------------------------------*/
    Ids = Ia;
    Iqs = INV_SQRT3 * (Ib   - Ic);

    Ide =  Cos_theta_C  * Ids + Sin_theta_C * Iqs;
    Iqe = -Sin_theta_C  * Ids + Cos_theta_C * Iqs;


    Vds_flt = La_s_volt * Vds_flt + Lb_s_volt   * (Vds + Vds_old);
    Vqs_flt = La_s_volt * Vqs_flt + Lb_s_volt   * (Vqs + Vqs_old);

    Vds_old = Vds;
    Vqs_old = Vqs;

    if(Flag_Grid_err == 1)
    {
        a   = Vsrc_dz   * (Vs_rate_peak * 0.01);     // Vsrc_dz=1

        i   = (Vds_flt >= a) ? 1 : (Vds_flt <= -a) ? -1 : i;

        if((i == 1) && (POL_Vds == -1))
        {
            SEQ_Vsrc    = (Vqs_flt >= 0.) ? -1 : 1;
        }

        POL_Vds = i;

        if(SEQ_Vsrc != 1)
        {
            if(++Cnt_SEQ >= 2000)
            {
                Fault_SW|=SFT_SEQ_Src;      // sequence error of source voltage
            }
        }
        else
        {
            Cnt_SEQ = 0;
        }
    }
}

void Va_PLL3_harmonic()
{
    register float  a;
    register float  a_n;
    register float  a_comp;
    register float  a_comp_n;
    int     i=0;

    /*--------------------------------------*/
    /*  axis-transform of source voltage    */
    /*--------------------------------------*/
    // INV2_3 = 2/3, INV_2 = 1/2, INV_3 = 1/3;

//  Vds = (2./3.)*(Esa-Esb/2.-Esc/2.);
//  Vds = (INV2_3)*(Esa-Esb*INV_2-Esc*INV_2);
//  Vqs = INV_SQRT3*(Esb-Esc);

    // 20.12.14.lsc harmonic 수식 변경 = 연산 결과는 동일
#if 1
    Vds = (2*Esa-Esb-Esc)*INV_3;
    Vqs = (Esb-Esc)*INV_SQRT3;
#endif

#if 0
    Vds = (2*Esa_flt-Esb_flt-Esc_flt)*INV_3;
    Vqs = (Esb_flt-Esc_flt)*INV_SQRT3;
#endif

#if 1
    // 20.12.14.lsc harmonic 수식 신규 추가
/*------------------------------------------------------------------------*/
    Vds_apf = Lb_APF_FRI * Vds_apf + Lb_APF_FRI * Vds  - Vds_old;
    Vqs_apf = Lb_APF_FRI * Vqs_apf + Lb_APF_FRI * Vqs  - Vqs_old;
/*------------------------------------------------------------------------*/

    Vds_flt=La_s_volt*Vds_flt + Lb_s_volt*(Vds + Vds_old);
    Vqs_flt=La_s_volt*Vqs_flt + Lb_s_volt*(Vqs + Vqs_old);

    Vds_old=Vds;
    Vqs_old=Vqs;
#endif

    // 20.12.14.lsc harmonic 수식 신규 추가
/*------------------------------------------------------------------------*/
    Vds_p = Vds + Vqs_apf;
    Vqs_p = Vqs - Vds_apf;
    Vds_n = Vds - Vqs_apf;
    Vqs_n = Vqs + Vds_apf;

    Vde_p = 0.5 * Cos_theta     * Vds_p + 0.5 * Sin_theta   * Vqs_p;
    Vqe_p = -0.5 * Sin_theta    * Vds_p + 0.5 * Cos_theta   * Vqs_p;
    Vde_n = 0.5 * Cos_theta_n   * Vds_n + 0.5 * Sin_theta_n * Vqs_n;
    Vqe_n = -0.5 * Sin_theta_n  * Vds_n + 0.5 * Cos_theta_n * Vqs_n;
/*------------------------------------------------------------------------*/

//  Vde = Cos_theta*Vds + Sin_theta*Vqs;
//  Vqe = -Sin_theta*Vds + Cos_theta*Vqs;

//  Vde = 0.5 * Cos_theta   * Vds_p + 0.5 * Sin_theta   * Vqs_p  + (-sin(Theta+PI_INV_2)*Vds_p + cos(Theta+PI_INV_2)*Vqs_p)*0.45;
//  Vde = 0.5 * Cos_theta   * Vds_p + 0.5 * Sin_theta   * Vqs_p  + (-sin(Theta+PI_INV_2)    * Vds_p + cos(Theta+PI_INV_2)   * Vqs_p)    * 0.49;
    Vde = 0.5 * Cos_theta   * Vds_p + 0.5 * Sin_theta   * Vqs_p  + (-Sin_theta_90           * Vds_p + Cos_theta_90          * Vqs_p)    * 0.49;

    Vqe = -0.5 * Sin_theta  * Vds_p + 0.5 * Cos_theta   * Vqs_p;

//  Vde_dc =  0.5 * cos(Theta+PI_INV_2) * Vds_p +  0.5 * sin(Theta+PI_INV_2)    * Vqs_p;
    Vde_dc =  0.5 * Cos_theta_90        * Vds_p +  0.5 * Sin_theta_90           * Vqs_p;

//  Vqe_dc = -0.5 * sin(Theta+PI_INV_2) * Vds_p +  0.5 * cos(Theta+PI_INV_2)    * Vqs_p;
    Vqe_dc = -0.5 * Sin_theta_90        * Vds_p +  0.5 * Cos_theta_90           * Vqs_p;

    Vde_dc_sum = Vde + Vqe_dc;

//  Vde_C = 0.5 * Cos_theta_C   * Vds_p + 0.5 * Sin_theta_C     * Vqs_p +(-sin(Theta_C+PI_INV_2)    * Vds_p + cos(Theta_C+PI_INV_2) * Vqs_p) * 0.45;//jyp
    Vde_C = 0.5 * Cos_theta_C   * Vds_p + 0.5 * Sin_theta_C     * Vqs_p +(-Sin_theta_C_90           * Vds_p + Cos_theta_C_90        * Vqs_p) * 0.49;//jyp


    Vde_flt = La_e_volt*Vde_flt + Lb_e_volt*(Vde + Vde_old);    Vde_old = Vde;  Vde_sum+=Vde_flt;//jyp
    Vqe_flt = La_e_volt*Vqe_flt + Lb_e_volt*(Vqe + Vqe_old);    Vqe_old = Vqe;  Vqe_sum+=Vqe_flt;//jyp

    Vde_flt_C = La_e_volt*Vde_flt_C + Lb_e_volt*(Vde_C + Vde_old_C);    Vde_old_C = Vde_C;

    Vde_p_flt     = La_e_volt * Vde_p_flt   + Lb_e_volt * (Vde_p   + Vde_p_old);        Vde_p_old     = Vde_p;
    Vqe_p_flt     = La_e_volt * Vqe_p_flt   + Lb_e_volt * (Vqe_p   + Vqe_p_old);        Vqe_p_old     = Vqe_p;

    Vde_n_flt     = La_e_volt * Vde_n_flt   + Lb_e_volt * (Vde_n   + Vde_n_old);        Vde_n_old     = Vde_n;
    Vqe_n_flt     = La_e_volt * Vqe_n_flt   + Lb_e_volt * (Vqe_n   + Vqe_n_old);        Vqe_n_old     = Vqe_n;

    /*--------------------------------------------------*/
    /*  phase angle detecting & sine/cosine calculate   */
    /*--------------------------------------------------*/
    // 20.12.14.lsc harmonic 수식 신규 추가
/*------------------------------------------------------------------------*/

// Theta_h = 76860576.0 수치값이 높게 측정되어 짐. 확인 필요
//  Em = sqrt(Vde_p*Vde_p + Vqe_p*Vqe_p);
//  Kp_PLL = 2.*zeta*Wn/(Em+1e-10);
//  Ki_PLL = (Wn*Wn)/(Kp_PLL*Em+1e-10);
//
//  Vde_err = Vde_p;
//  W_delta_intg += Ki_PLL * Vde_err * Tsamp;
//  W_delta = W_delta_intg + Kp_PLL * Vde_err;
//
//  Theta_h += (Wgrid + W_delta) * Tsamp;
//  Theta_h += Wgrid * Tsamp;
//  Theta_h=BOUND_PI(Theta_h);                  // theta bound ( -PI ~ PI)
//  Wgrid = (Wgrid + W_delta) * INV_2PI;

#if 1
/*------------------------------------------------------------------------*/
    Theta_old = Theta;
    Theta_comp3 = Theta_comp3 + Kp_ang*(-Vde_flt - Err_Vde) + Tsamp*Ki_ang*(-Vde_flt);
    Err_Vde = -Vde_flt;
//  Theta = Theta + We_rate*Tsamp + Theta_comp3;
    Theta = Theta + We_rate_init*Tsamp + Theta_comp3;

    Theta=BOUND_PI(Theta);                          // theta bound ( -PI ~ PI)
    a=Theta*Theta;
    Sin_theta=SIN(Theta,a);     Cos_theta=COS(a);
#endif

    a               = (Theta    + PI_INV_2) * (Theta    + PI_INV_2);
    Sin_theta_90    = SIN(Theta + PI_INV_2, a);
    Cos_theta_90    = COS(a);


    // 20.12.14.lsc harmonic 수식 신규 추가
/*------------------------------------------------------------------------*/
    Theta_n=-Theta;
    Theta_n=BOUND_PI(Theta_n);                  // theta bound ( -PI ~ PI)
    a_n=Theta_n*Theta_n;
    Sin_theta_n=SIN(Theta_n,a_n);       Cos_theta_n=COS(a_n);
/*------------------------------------------------------------------------*/

#if 1
    Theta_comp_out = Theta_comp_out + Kp_ang*(-Vde_flt_C - Err_Vde_C) + Tsamp*Ki_ang*(-Vde_flt_C);
    Err_Vde_C = -Vde_flt_C+Err_theta_comp;
    Theta_C = Theta_C + We_rate*Tsamp+ Theta_comp_out;

    Theta_C = BOUND_PI(Theta_C);                // theta bound ( -PI ~ PI)
    a_comp = Theta_C*Theta_C;
    Sin_theta_C = SIN(Theta_C,a_comp);
    Cos_theta_C = COS(a_comp);
#endif

    a               = (Theta_C      + PI_INV_2) * (Theta_C  + PI_INV_2);
    Sin_theta_C_90  = SIN(Theta_C   + PI_INV_2, a);
    Cos_theta_C_90  = COS(a);


    // 20.12.14.lsc harmonic 수식 신규 추가
/*------------------------------------------------------------------------*/
    Theta_C_n=-Theta_C;
    Theta_C_n = BOUND_PI(Theta_C_n);                // theta bound ( -PI ~ PI)
    a_comp_n = Theta_C_n*Theta_C_n;
    Sin_theta_C_n = SIN(Theta_C_n,a_comp_n);
    Cos_theta_C_n = COS(a_comp_n);
/*------------------------------------------------------------------------*/


    /*---- Frequence Low/High ----*/
    if(Theta*Theta_old < 0.) {  if(Theta < 0.)      Flag_FreqLowHigh^=1;    }

    if(Flag_FreqLowHigh==1) {
        if(Cnt_freq2_old >  100){

            Cnt_freq2_max = Cnt_freq2_old;
            Count_freq2=0;

            Count_freq1++;
            Cnt_freq1_old = Count_freq1;

        }
        else Cnt_freq2_max = 0;

    }
    else {
        if(Cnt_freq1_old >  100){

            Cnt_freq1_max = Cnt_freq1_old;
            Count_freq1=0;

            Count_freq2++;
            Cnt_freq2_old = Count_freq2;
        }
        else Cnt_freq1_max=0;

    }

    Theta_old = Theta;
    /*----------------------------*/

    /*--------------------------------------*/
    /*  detection of currents               */
    /*--------------------------------------*/

//  Ids= Ia;
//  Iqs= INV_SQRT3*(Ib-Ic);


    // 20.12.14.lsc harmonic 수식 변경 = Ids 연산 결과는 확인이 필요함.
#if 1
    Ids= (2 * Ia - Ib - Ic) * INV_3;
    Iqs= (Ib - Ic) * INV_SQRT3;
#endif

#if 0
    Ids= (2 * Ia_flt - Ib_flt - Ic_flt) * INV_3;
    Iqs= (Ib_flt - Ic_flt) * INV_SQRT3;
#endif

    // 20.12.14.lsc harmonic 수식 신규 추가
/*------------------------------------------------------------------------*/
    Ids_apf = Lb_APF_FRI * Ids_apf + Lb_APF_FRI * Ids  - Ids_old;
    Iqs_apf = Lb_APF_FRI * Iqs_apf + Lb_APF_FRI * Iqs  - Iqs_old;

    Ids_old = Ids;
    Iqs_old = Iqs;

    Ids_p = Ids + Iqs_apf;
    Iqs_p = Iqs - Ids_apf;
    Ids_n = Ids - Iqs_apf;
    Iqs_n = Iqs + Ids_apf;

    Ide_p = 0.5 * Cos_theta_C   * Ids_p + 0.5 * Sin_theta_C     * Iqs_p;
    Iqe_p = -0.5 * Sin_theta_C  * Ids_p + 0.5 * Cos_theta_C     * Iqs_p;
    Ide_n = 0.5 * Cos_theta_C_n * Ids_n + 0.5 * Sin_theta_C_n   * Iqs_n;
    Iqe_n = -0.5 * Sin_theta_C_n * Ids_n + 0.5 * Cos_theta_C_n  * Iqs_n;

/*------------------------------------------------------------------------*/


//  Ide=  Cos_theta*Ids + Sin_theta*Iqs;
//  Iqe= -Sin_theta*Ids + Cos_theta*Iqs;

    Ide=  Cos_theta_C*Ids + Sin_theta_C*Iqs;
    Iqe= -Sin_theta_C*Ids + Cos_theta_C*Iqs;


    Ide_p_flt     = La_e_volt * Ide_p_flt   + Lb_e_volt * (Ide_p   + Ide_p_old);        Ide_p_old     = Ide_p;
    Iqe_p_flt     = La_e_volt * Iqe_p_flt   + Lb_e_volt * (Iqe_p   + Iqe_p_old);        Iqe_p_old     = Iqe_p;

    Ide_n_flt     = La_e_volt * Ide_n_flt   + Lb_e_volt * (Ide_n   + Ide_n_old);        Ide_n_old     = Ide_n;
    Iqe_n_flt     = La_e_volt * Iqe_n_flt   + Lb_e_volt * (Iqe_n   + Iqe_n_old);        Iqe_n_old     = Iqe_n;


//  Ide_sum+=Ide;
//  Iqe_sum+=Iqe;

    if(Flag_Grid_err == 1)
    {
    //  a=Vsrc_dz*(Vs_rate_peak/100.);     // Vsrc_dz=1
        a=Vsrc_dz*(Vs_rate_peak*0.01);     // Vsrc_dz=1

        /* 1. polarity detector */

        /* 1-1. a is hysteresis threshold (negative th, positive th), i is rectangular pulse. */
        i=(Vds_flt >= a) ? 1 : (Vds_flt <= -a) ? -1 : i;

        /* 1-2. rising edge detector for i */
        if((i==1)&&(POL_Vds==-1) )
        {
            /* check level (negative / positive) */
            SEQ_Vsrc=(Vqs_flt >= 0.) ? -1 : 1;
        }
        /* 1-3. save previous level to detect the edge */
        POL_Vds=i;

        /* 2. monitor the sequence (Vds vs. Vqs) */

        /* 2-1. phase sequence => Va, Vb, Vc : +120, 0, -120 */
        if(SEQ_Vsrc!=1)
        {
            if(++Cnt_SEQ >= 2000)
            {
                System_fault_latch |= 0x2000;
                Fault_SW|=SFT_SEQ_Src;        // sequence error of source voltage
            }
        }
        else    Cnt_SEQ = 0;
    }
}



#if 1
void Ia_PLL3_harmonic()
{
    register float  a;
//    Idsp= in[0];
//    Iqsp= in[1];
//    Idsn= in[2];
//    Iqsn= in[3];
//    Angle_Grid_p = in[4];

    Idsp= Ids_p;
    Iqsp= Iqs_p;
    Idsn= Ids_n;
    Iqsn= Iqs_n;
    Angle_Grid_p = Theta_C;

    Angle_Grid_n = -Angle_Grid_p;

    a               = (Angle_Grid_p    + Ia_PLL3_harmonic_k1) * (Angle_Grid_p    + Ia_PLL3_harmonic_k1);
    Sin_theta_k1    = SIN(Angle_Grid_p + Ia_PLL3_harmonic_k1, a);
    Cos_theta_k1    = COS(a);

    a               = (Angle_Grid_n    + Ia_PLL3_harmonic_k1) * (Angle_Grid_n    + Ia_PLL3_harmonic_k1);
    Sin_theta_n_k1  = SIN(Angle_Grid_n + Ia_PLL3_harmonic_k1, a);
    Cos_theta_n_k1  = COS(a);

    a               = (Angle_Grid_p    + Ia_PLL3_harmonic_k2) * (Angle_Grid_p    + Ia_PLL3_harmonic_k2);
    Sin_theta_k2    = SIN(Angle_Grid_p + Ia_PLL3_harmonic_k2, a);
    Cos_theta_k2    = COS(a);

    a               = (Angle_Grid_n    + Ia_PLL3_harmonic_k2) * (Angle_Grid_n    + Ia_PLL3_harmonic_k2);
    Sin_theta_n_k2  = SIN(Angle_Grid_n + Ia_PLL3_harmonic_k2, a);
    Cos_theta_n_k2  = COS(a);

    //2 setting
//1
//  Ide_5th_p1 = cos(Angle_Grid_p * Ia_PLL3_harmonic_k1) * Idsp - sin(Angle_Grid_p *Ia_PLL3_harmonic_k1) * Iqsp; //Positive
    Ide_5th_p1 = Cos_theta_k1                            * Idsp - Sin_theta_k1                           * Iqsp; //Positive

//  Iqe_5th_p1 =  sin(Angle_Grid_p * Ia_PLL3_harmonic_k1)   * Idsp + cos(Angle_Grid_p * Ia_PLL3_harmonic_k1)    * Iqsp;
    Iqe_5th_p1 =  Sin_theta_k1                              * Idsp + Cos_theta_k1                               * Iqsp;

    Ide_5th_flt_p1 = La_I_5th * Ide_5th_flt_p1 + Lb_I_5th * (Ide_5th_p1 + Ide_5th_old_p1);
    Iqe_5th_flt_p1 = La_I_5th * Iqe_5th_flt_p1 + Lb_I_5th * (Iqe_5th_p1 + Iqe_5th_old_p1);
    Ide_5th_old_p1 = Ide_5th_p1;
    Iqe_5th_old_p1 = Iqe_5th_p1;

//  Ide_5th_n1 = cos(Angle_Grid_n *Ia_PLL3_harmonic_k1) * Idsn -  sin(Angle_Grid_n *Ia_PLL3_harmonic_k1) * Iqsn; //Negative
    Ide_5th_n1 = Cos_theta_n_k1                         * Idsn -  Sin_theta_n_k1                         * Iqsn; //Negative

//  Iqe_5th_n1 =  sin(Angle_Grid_n *Ia_PLL3_harmonic_k1) * Idsn + cos(Angle_Grid_n *Ia_PLL3_harmonic_k1)    * Iqsn;
    Iqe_5th_n1 =  Sin_theta_n_k1                         * Idsn + Cos_theta_n_k1                            * Iqsn;


    Ide_5th_flt_n1 = La_I_5th * Ide_5th_flt_n1 + Lb_I_5th * (Ide_5th_n1 + Ide_5th_old_n1);
    Iqe_5th_flt_n1 = La_I_5th * Iqe_5th_flt_n1 + Lb_I_5th * (Iqe_5th_n1 + Iqe_5th_old_n1);
    Ide_5th_old_n1 = Ide_5th_n1;
    Iqe_5th_old_n1 = Iqe_5th_n1;


//    Ide_5th_err_p1 = (0 - Ide_5th_flt_p1); //Positive
//    Iqe_5th_err_p1 = (0 - Iqe_5th_flt_p1);

    Ide_5th_err_p1 = (0 - Kp_5th_ref * Ide_5th_flt_p1); //Positive
    Iqe_5th_err_p1 = (0 - Kp_5th_ref * Iqe_5th_flt_p1);

    Vde_5th_integ_p1 += Ki_CC_Grid_comp_5th * Ide_5th_err_p1 * Tsamp;
    Vde_5th_ref_fb_p1 = Vde_5th_integ_p1 + Kp_CC_Grid_comp_5th * Ide_5th_err_p1;
    Vqe_5th_integ_p1 += Ki_CC_Grid_comp_5th * Iqe_5th_err_p1 * Tsamp;
    Vqe_5th_ref_fb_p1 = Vqe_5th_integ_p1 + Kp_CC_Grid_comp_5th * Iqe_5th_err_p1;
    Vde_5th_ref_p1 = Vde_5th_ref_fb_p1;
    Vqe_5th_ref_p1 = Vqe_5th_ref_fb_p1;

//  Vds_5th_ref_p1 = cos(Angle_Grid_p * Ia_PLL3_harmonic_k1) * Vde_5th_ref_p1 + sin(Angle_Grid_p * Ia_PLL3_harmonic_k1) * Vqe_5th_ref_p1;
    Vds_5th_ref_p1 = Cos_theta_k1                            * Vde_5th_ref_p1 + Sin_theta_k1                            * Vqe_5th_ref_p1;

//  Vqs_5th_ref_p1 = - sin(Angle_Grid_p * Ia_PLL3_harmonic_k1) * Vde_5th_ref_p1 + cos(Angle_Grid_p *Ia_PLL3_harmonic_k1) * Vqe_5th_ref_p1;
    Vqs_5th_ref_p1 = - Sin_theta_k1                            * Vde_5th_ref_p1 + Cos_theta_k1                           * Vqe_5th_ref_p1;

//    Ide_5th_err_n1 = (0 - Ide_5th_flt_n1); //Negative
//    Iqe_5th_err_n1 = (0 - Iqe_5th_flt_n1);

    Ide_5th_err_n1 = (0 - Kp_5th_ref * Ide_5th_flt_n1); //Negative
    Iqe_5th_err_n1 = (0 - Kp_5th_ref * Iqe_5th_flt_n1);

    Vde_5th_integ_n1 += Ki_CC_Grid_comp_5th * Ide_5th_err_n1*Tsamp;
    Vde_5th_ref_fb_n1 = Vde_5th_integ_n1 + Kp_CC_Grid_comp_5th * Ide_5th_err_n1;

    Vqe_5th_integ_n1 += Ki_CC_Grid_comp_5th * Iqe_5th_err_n1* Tsamp;
    Vqe_5th_ref_fb_n1 = Vqe_5th_integ_n1 + Kp_CC_Grid_comp_5th * Iqe_5th_err_n1;

    Vde_5th_ref_n1 = Vde_5th_ref_fb_n1;
    Vqe_5th_ref_n1 = Vqe_5th_ref_fb_n1;

//  Vds_5th_ref_n1 = cos(Angle_Grid_n * Ia_PLL3_harmonic_k1) * Vde_5th_ref_n1 + sin(Angle_Grid_n * Ia_PLL3_harmonic_k1) * Vqe_5th_ref_n1;
    Vds_5th_ref_n1 = Cos_theta_n_k1                          * Vde_5th_ref_n1 + Sin_theta_n_k1                          * Vqe_5th_ref_n1;

//  Vqs_5th_ref_n1 = - sin(Angle_Grid_n * Ia_PLL3_harmonic_k1) * Vde_5th_ref_n1 + cos(Angle_Grid_n *Ia_PLL3_harmonic_k1) * Vqe_5th_ref_n1; //5th
    Vqs_5th_ref_n1 = - Sin_theta_n_k1                          * Vde_5th_ref_n1 + Cos_theta_n_k1                         * Vqe_5th_ref_n1; //5th

//2
//  Ide_5th_p2 = cos(Angle_Grid_p * Ia_PLL3_harmonic_k2) * Idsp - sin(Angle_Grid_p *Ia_PLL3_harmonic_k2)    * Iqsp; //Positive
    Ide_5th_p2 = Cos_theta_k2                            * Idsp - Sin_theta_k2                              * Iqsp; //Positive

//  Iqe_5th_p2 =  sin(Angle_Grid_p * Ia_PLL3_harmonic_k2) * Idsp + cos(Angle_Grid_p * Ia_PLL3_harmonic_k2)  * Iqsp;
    Iqe_5th_p2 =  Sin_theta_k2                            * Idsp + Cos_theta_k2                             * Iqsp;

    Ide_5th_flt_p2 = La_I_5th * Ide_5th_flt_p2 + Lb_I_5th * (Ide_5th_p2 + Ide_5th_old_p2);
    Iqe_5th_flt_p2 = La_I_5th * Iqe_5th_flt_p2 + Lb_I_5th * (Iqe_5th_p2 + Iqe_5th_old_p2);
    Ide_5th_old_p2 = Ide_5th_p2;
    Iqe_5th_old_p2 = Iqe_5th_p2;

//  Ide_5th_n2 = cos(Angle_Grid_n *Ia_PLL3_harmonic_k2) * Idsn -  sin(Angle_Grid_n *Ia_PLL3_harmonic_k2) * Iqsn; //Negative
    Ide_5th_n2 = Cos_theta_n_k2                         * Idsn -  Sin_theta_n_k2                         * Iqsn; //Negative

//  Iqe_5th_n2 =  sin(Angle_Grid_n *Ia_PLL3_harmonic_k2) * Idsn + cos(Angle_Grid_n *Ia_PLL3_harmonic_k2)    * Iqsn;
    Iqe_5th_n2 =  Sin_theta_n_k2                         * Idsn + Cos_theta_n_k2                            * Iqsn;

    Ide_5th_flt_n2 = La_I_5th * Ide_5th_flt_n2 + Lb_I_5th * (Ide_5th_n2 + Ide_5th_old_n2);
    Iqe_5th_flt_n2 = La_I_5th * Iqe_5th_flt_n2 + Lb_I_5th * (Iqe_5th_n2 + Iqe_5th_old_n2);
    Ide_5th_old_n2 = Ide_5th_n2;
    Iqe_5th_old_n2 = Iqe_5th_n2;


//    Ide_5th_err_p2 = (0 - Ide_5th_flt_p2); //Positive
//    Iqe_5th_err_p2 = (0 - Iqe_5th_flt_p2);
    Ide_5th_err_p2 = (0 - Kp_5th_ref * Ide_5th_flt_p2); //Positive
    Iqe_5th_err_p2 = (0 - Kp_5th_ref * Iqe_5th_flt_p2);

    Vde_5th_integ_p2 += Ki_CC_Grid_comp_5th * Ide_5th_err_p2 * Tsamp;
    Vde_5th_ref_fb_p2 = Vde_5th_integ_p2 + Kp_CC_Grid_comp_5th * Ide_5th_err_p2;
    Vqe_5th_integ_p2 += Ki_CC_Grid_comp_5th * Iqe_5th_err_p2 * Tsamp;
    Vqe_5th_ref_fb_p2 = Vqe_5th_integ_p2 + Kp_CC_Grid_comp_5th * Iqe_5th_err_p2;
    Vde_5th_ref_p2 = Vde_5th_ref_fb_p2;
    Vqe_5th_ref_p2 = Vqe_5th_ref_fb_p2;

//  Vds_5th_ref_p2 = cos(Angle_Grid_p * Ia_PLL3_harmonic_k2) * Vde_5th_ref_p2 + sin(Angle_Grid_p * Ia_PLL3_harmonic_k2) * Vqe_5th_ref_p2;
    Vds_5th_ref_p2 = Cos_theta_k2                            * Vde_5th_ref_p2 + Sin_theta_k2                            * Vqe_5th_ref_p2;

//  Vqs_5th_ref_p2 = - sin(Angle_Grid_p * Ia_PLL3_harmonic_k2) * Vde_5th_ref_p2 + cos(Angle_Grid_p *Ia_PLL3_harmonic_k2) * Vqe_5th_ref_p2;
    Vqs_5th_ref_p2 = - Sin_theta_k2                            * Vde_5th_ref_p2 + Cos_theta_k2                           * Vqe_5th_ref_p2;


//    Ide_5th_err_n2 = (0 - Ide_5th_flt_n2); //Negative
//    Iqe_5th_err_n2  = (0 - Iqe_5th_flt_n2);
    Ide_5th_err_n2 = (0 - Kp_5th_ref * Ide_5th_flt_n2); //Negative
    Iqe_5th_err_n2  = (0 - Kp_5th_ref * Iqe_5th_flt_n2);


    Vde_5th_integ_n2 += Ki_CC_Grid_comp_5th * Ide_5th_err_n2*Tsamp;
    Vde_5th_ref_fb_n2 = Vde_5th_integ_n2 + Kp_CC_Grid_comp_5th * Ide_5th_err_n2;

    Vqe_5th_integ_n2 += Ki_CC_Grid_comp_5th * Iqe_5th_err_n2* Tsamp;
    Vqe_5th_ref_fb_n2 = Vqe_5th_integ_n2 + Kp_CC_Grid_comp_5th * Iqe_5th_err_n2;

    Vde_5th_ref_n2 = Vde_5th_ref_fb_n2;
    Vqe_5th_ref_n2 = Vqe_5th_ref_fb_n2;

//  Vds_5th_ref_n2 = cos(Angle_Grid_n * Ia_PLL3_harmonic_k2) * Vde_5th_ref_n2 + sin(Angle_Grid_n * Ia_PLL3_harmonic_k2) * Vqe_5th_ref_n2;
    Vds_5th_ref_n2 = Cos_theta_n_k2                          * Vde_5th_ref_n2 + Sin_theta_n_k2                          * Vqe_5th_ref_n2;

//  Vqs_5th_ref_n2 = - sin(Angle_Grid_n * Ia_PLL3_harmonic_k2) * Vde_5th_ref_n2 + cos(Angle_Grid_n *Ia_PLL3_harmonic_k2) * Vqe_5th_ref_n2; //5th
    Vqs_5th_ref_n2 = - Sin_theta_n_k2                          * Vde_5th_ref_n2 + Cos_theta_n_k2                         * Vqe_5th_ref_n2; //5th

    Vds_5th_ref_p = (Vds_5th_ref_p1 + Vds_5th_ref_p2);
    Vqs_5th_ref_p = (Vqs_5th_ref_p1 + Vqs_5th_ref_p2);
    Vds_5th_ref_n = (Vds_5th_ref_n1 + Vds_5th_ref_n2);
    Vqs_5th_ref_n = (Vqs_5th_ref_n1 + Vqs_5th_ref_n2);

//    Vds_5th_ref_p = Kp_5th_ref * (Vds_5th_ref_p1 + Vds_5th_ref_p2);
//    Vqs_5th_ref_p = Kp_5th_ref * (Vqs_5th_ref_p1 + Vqs_5th_ref_p2);
//    Vds_5th_ref_n = Kp_5th_ref * (Vds_5th_ref_n1 + Vds_5th_ref_n2);
//    Vqs_5th_ref_n = Kp_5th_ref * (Vqs_5th_ref_n1 + Vqs_5th_ref_n2);

//    out[0]=Vds_5th_ref_p   ;
//    out[1]=Vqs_5th_ref_p  ;
//    out[2]= a;
//
//    out[3]=a ;
//    out[4]= Vds_5th_ref_n   ;
//    out[5]= Vqs_5th_ref_n  ;
}

void Ia_PLL3_harmonic_init()
{

    //2
    Ide_5th_p1 = 0;
    Iqe_5th_p1 = 0;

    Ide_5th_flt_p1 = 0;
    Iqe_5th_flt_p1 = 0;
    Ide_5th_old_p1 = 0;
    Iqe_5th_old_p1 = 0;

    Ide_5th_n1 = 0;
    Iqe_5th_n1 = 0;

    Ide_5th_flt_n1 = 0;
    Iqe_5th_flt_n1 = 0;
    Ide_5th_old_n1 = 0;
    Iqe_5th_old_n1 = 0;


    Ide_5th_err_p1 = 0;
    Iqe_5th_err_p1 = 0;

    Vde_5th_integ_p1 = 0;
    Vde_5th_ref_fb_p1 = 0;
    Vqe_5th_integ_p1 = 0;
    Vqe_5th_ref_fb_p1 = 0;
    Vde_5th_ref_p1 = 0;
    Vqe_5th_ref_p1 = 0;
    Vds_5th_ref_p1 = 0;
    Vqs_5th_ref_p1 = 0;

    Ide_5th_err_n1 = 0;
    Iqe_5th_err_n1 = 0;
    Vde_5th_integ_n1 = 0;
    Vde_5th_ref_fb_n1 = 0;

    Vqe_5th_integ_n1 = 0;
    Vqe_5th_ref_fb_n1 = 0;

    Vde_5th_ref_n1 = 0;
    Vqe_5th_ref_n1 = 0;
    Vds_5th_ref_n1 = 0;
    Vqs_5th_ref_n1  = 0;


    Ide_5th_p2 = 0;
    Iqe_5th_p2 = 0;

    Ide_5th_flt_p2 = 0;
    Iqe_5th_flt_p2 = 0;
    Ide_5th_old_p2 = 0;
    Iqe_5th_old_p2 = 0;

    Ide_5th_n2 = 0;
    Iqe_5th_n2 = 0;

    Ide_5th_flt_n2 = 0;
    Iqe_5th_flt_n2 = 0;
    Ide_5th_old_n2 = 0;
    Iqe_5th_old_n2 = 0;


    Ide_5th_err_p2 = 0;
    Iqe_5th_err_p2 = 0;

    Vde_5th_integ_p2 = 0;
    Vde_5th_ref_fb_p2 = 0;
    Vqe_5th_integ_p2 = 0;
    Vqe_5th_ref_fb_p2 = 0;
    Vde_5th_ref_p2 = 0;
    Vqe_5th_ref_p2 = 0;
    Vds_5th_ref_p2 = 0;
    Vqs_5th_ref_p2 = 0;

    Ide_5th_err_n2 = 0;
    Iqe_5th_err_n2 = 0;
    Vde_5th_integ_n2 = 0;
    Vde_5th_ref_fb_n2 = 0;

    Vqe_5th_integ_n2 = 0;
    Vqe_5th_ref_fb_n2 = 0;

    Vde_5th_ref_n2 = 0;
    Vqe_5th_ref_n2 = 0;
    Vds_5th_ref_n2 = 0;
    Vqs_5th_ref_n2  = 0;
}

#endif


void Control_Run_Stop()
{
    if(Mode_system == TEST_MODE)
    {
        if((System_fault == NORMAL) && (DI_input == 1))
        {
            Flag_gating         = Flag_gating_test;
            Flag_gating_VF      = Flag_gating_VF_TEST;

            if(Flag_gating_test == 1)
            {
                Flag_pwm_con_test1  = Flag_gating_test;
            }
            else
            {
                Flag_pwm_con_test1 = 0;
            }

            if(Enable_EEPROM_write2 == 0)
            {
                Fault_save = 1; //18.10.10.lsc redefine 에러저장중이 아닐때만 에러저장기능 업데이트
            }
        }
        else
        {
            Flag_gating         = 0;
            Flag_gating_VF      = 0;
            Flag_pwm_con_test1  = 0;
            flag_voltage_control_inv3 = 0;
        }
    }
    else
    {
        if((System_fault == NORMAL) && (DI_Run_Stop == 1))
        {
            Flag_gating = 1;
            if(Enable_EEPROM_write2 == 0)
            {
                Fault_save = 1; //18.10.10.lsc redefine 에러저장중이 아닐때만 에러저장기능 업데이트
            }
        }

        else
        {
            Flag_gating         = 0;
            Flag_gating_VF      = 0;
            Flag_pwm_con_test1  = 0;
            flag_voltage_control_inv3 = 0;
    //      Flag_gating_inv_VF  = 0;
        }
        //66.6us x 0.38% = 0.25us
    }
    //    if(time_check_cnt == 2)   LED1_OFF;
}

void current_control_con()
{

//  Idc_ref_Cf = Kp_Idc_ref_Cf * Idc_ref * sin(3 * Theta);
//  Err_Idc     = Idc_ref   - Idc + Idc_ref_Cf;

    Err_Idc     = Idc_ref   - Idc;
    Idc_integ   += Ki_Idc   * (Err_Idc  - Ka_Idc    * (Idc_out - Idc_real));
    Idc_out     = Idc_integ + Kp_Idc    * Err_Idc;

//  Idc_real    = ((Idc_out > 50) ? 50 : (Idc_out < 0) ? 0 : Idc_out);
    Idc_real    = ((Idc_out > Vin_max_80) ? Vin_max_80 : (Idc_out < 0) ? 0 : Idc_out);

//  Tsamp_INV_Vin   = (INV_Vin * 5000);
    Tsamp_INV_Vin   = (INV_Vin * CNT_max_con_50);
    Ta_real_con     = (Idc_real * Tsamp_INV_Vin);

//  Ta_con          = Ta_real_con;
//  Ta_con = ((Ta_real_con > 2480)              ? 2480              : (Ta_real_con  < 100)                  ? 100                   : Ta_real_con);
//  Ta_con = ((Ta_real_con > CNT_max_con_49_5)  ? CNT_max_con_49_5  : (Ta_real_con  < CNT_max_con_dead_50)  ? CNT_max_con_dead_50   : Ta_real_con);
//  Ta_con = ((Ta_real_con > CNT_max_con_49_5)  ? CNT_max_con_49_5  : (Ta_real_con  < T_dead_con_CNT_50)    ? T_dead_con_CNT_50     : Ta_real_con);
    Ta_con = ((Ta_real_con > (CNT_max_con_50-50)) ? (CNT_max_con_50-50):(Ta_real_con<50) ? 50:Ta_real_con); //duty 1999 max
}

void VF_test3()
{
    register float  a;

    VF_vtg  += Tsamp    * VF_vtg_max    / VF_time;
    if(VF_vtg > VF_vtg_max)
    {
        VF_vtg = VF_vtg_max;
    }

    if(VF_vtg < VF_vtg_off)
    {
        a = VF_vtg_off;
    }
    else
    {
        a = VF_vtg;
    }

    VF_freq     = (a    / VF_vtg_max)   * VF_freq_max   + VF_freq_off;
    theta_VF    += 2    * PI    * VF_freq   * Tsamp;

    if(theta_VF > PI)
    {
        theta_VF    -= 2.   * PI;
    }
    else if(theta_VF < -PI)
    {
        theta_VF    += 2.   * PI;
    }

    a = theta_VF    * theta_VF;
    Sin_Theta_VF = SIN(theta_VF,a);
    Cos_Theta_VF = COS(a);

    DA_Test1 = sin(theta_VF) + sin(DA_Test_K1 * theta_VF);
    DA_Test2 = sin(theta_VF) + sin(DA_Test_K2 * theta_VF);

    Vds_ref = Cos_Theta_VF  * VF_vtg;
    Vqs_ref = Sin_Theta_VF  * VF_vtg;

    Va_ref  =      Vds_ref;
    Vb_ref  =    -(Vds_ref  - SQRT3  * Vqs_ref) * INV_2;
    Vc_ref  =    -(Va_ref   + Vb_ref);

#if 0
//  Ta_real_inv = (int)((0.5    * Va_ref    * INV_Vdc   + 0.5)  * 2500);
    Ta_real_inv = (int)((0.5    * Va_ref    * INV_Vdc   + 0.5)  * CNT_max);
    Tb_real_inv = (int)((0.5    * Vb_ref    * INV_Vdc   + 0.5)  * CNT_max);
    Tc_real_inv = (int)((0.5    * Vc_ref    * INV_Vdc   + 0.5)  * CNT_max);

//  Ta_inv = ((Ta_real_inv > 2440)          ? 2440          : (Ta_real_inv  < 70) ? 70  : Ta_real_inv);
    Ta_inv = ((Ta_real_inv > CNT_max_98)    ? CNT_max_98    : (Ta_real_inv  < 60) ? 60  : Ta_real_inv);
    Tb_inv = ((Tb_real_inv > CNT_max_98)    ? CNT_max_98    : (Tb_real_inv  < 60) ? 60  : Tb_real_inv);
    Tc_inv = ((Tc_real_inv > CNT_max_98)    ? CNT_max_98    : (Tc_real_inv  < 60) ? 60  : Tc_real_inv);
#endif

#if 0
    INV_Vdc_2 = INV_Vdc * 2;

    Ta_real_inv = (int)((0.5    * Va_ref    * INV_Vdc_2   + 0.5)  * CNT_max);
    Tb_real_inv = (int)((0.5    * Vb_ref    * INV_Vdc_2   + 0.5)  * CNT_max);
    Tc_real_inv = (int)((0.5    * Vc_ref    * INV_Vdc_2   + 0.5)  * CNT_max);

    Ta_inv = ((Ta_real_inv > CNT_max_98)    ? CNT_max_98    : (Ta_real_inv  < 60) ? 60  : Ta_real_inv);
    Tb_inv = ((Tb_real_inv > CNT_max_98)    ? CNT_max_98    : (Tb_real_inv  < 60) ? 60  : Tb_real_inv);
    Tc_inv = ((Tc_real_inv > CNT_max_98)    ? CNT_max_98    : (Tc_real_inv  < 60) ? 60  : Tc_real_inv);
#endif

#if 1
    INV_Vdc_2 = INV_Vdc * 2;

    //3.75kHz
    LIMIT_i((int)(( Va_ref*INV_Vdc_2*0.5+0.5 )* CNT_max), CNT_max_98, CNT_max_2, &Ta_inv);
    LIMIT_i((int)(( Vb_ref*INV_Vdc_2*0.5+0.5 )* CNT_max), CNT_max_98, CNT_max_2, &Tb_inv);
    LIMIT_i((int)(( Vc_ref*INV_Vdc_2*0.5+0.5 )* CNT_max), CNT_max_98, CNT_max_2, &Tc_inv);
#endif

}


void VF_test3_no_Vdc()
{
    register float  a;

    VF_vtg  += Tsamp    * VF_vtg_max_no_Vdc    / VF_time;
    if(VF_vtg > VF_vtg_max_no_Vdc)
    {
        VF_vtg = VF_vtg_max_no_Vdc;
    }

    if(VF_vtg < VF_vtg_off)
    {
        a = VF_vtg_off;
    }
    else
    {
        a = VF_vtg;
    }

    VF_freq     = (a    / VF_vtg_max)   * VF_freq_max   + VF_freq_off;
    theta_VF    += 2    * PI    * VF_freq   * Tsamp;

    if(theta_VF > PI)
    {
        theta_VF    -= 2.   * PI;
    }
    else if(theta_VF < -PI)
    {
        theta_VF    += 2.   * PI;
    }

    a = theta_VF    * theta_VF;
    Sin_Theta_VF = SIN(theta_VF,a);
    Cos_Theta_VF = COS(a);

    DA_Test1 = sin(theta_VF) + sin(DA_Test_K1 * theta_VF);
    DA_Test2 = sin(theta_VF) + sin(DA_Test_K2 * theta_VF);

    Vds_ref = Cos_Theta_VF  * VF_vtg;
    Vqs_ref = Sin_Theta_VF  * VF_vtg;

    Va_ref  =      Vds_ref;
    Vb_ref  =    -(Vds_ref  - SQRT3  * Vqs_ref) * INV_2;
    Vc_ref  =    -(Va_ref   + Vb_ref);

#if 0
//  Ta_real_inv = (int)((0.5    * Va_ref    * INV_Vdc   + 0.5)  * 2500);
    Ta_real_inv = (int)((0.5    * Va_ref    * INV_Vdc   + 0.5)  * CNT_max);
    Tb_real_inv = (int)((0.5    * Vb_ref    * INV_Vdc   + 0.5)  * CNT_max);
    Tc_real_inv = (int)((0.5    * Vc_ref    * INV_Vdc   + 0.5)  * CNT_max);

//  Ta_inv = ((Ta_real_inv > 2440)          ? 2440          : (Ta_real_inv  < 70) ? 70  : Ta_real_inv);
    Ta_inv = ((Ta_real_inv > CNT_max_98)    ? CNT_max_98    : (Ta_real_inv  < 60) ? 60  : Ta_real_inv);
    Tb_inv = ((Tb_real_inv > CNT_max_98)    ? CNT_max_98    : (Tb_real_inv  < 60) ? 60  : Tb_real_inv);
    Tc_inv = ((Tc_real_inv > CNT_max_98)    ? CNT_max_98    : (Tc_real_inv  < 60) ? 60  : Tc_real_inv);
#endif

#if 0
    INV_Vdc_2 = INV_Vdc * 2;

    Ta_real_inv = (int)((0.5    * Va_ref    * INV_Vdc_2   + 0.5)  * CNT_max);
    Tb_real_inv = (int)((0.5    * Vb_ref    * INV_Vdc_2   + 0.5)  * CNT_max);
    Tc_real_inv = (int)((0.5    * Vc_ref    * INV_Vdc_2   + 0.5)  * CNT_max);

    Ta_inv = ((Ta_real_inv > CNT_max_98)    ? CNT_max_98    : (Ta_real_inv  < 60) ? 60  : Ta_real_inv);
    Tb_inv = ((Tb_real_inv > CNT_max_98)    ? CNT_max_98    : (Tb_real_inv  < 60) ? 60  : Tb_real_inv);
    Tc_inv = ((Tc_real_inv > CNT_max_98)    ? CNT_max_98    : (Tc_real_inv  < 60) ? 60  : Tc_real_inv);
#endif

#if 0
    INV_Vdc_2 = INV_Vdc * 2;

    //3.75kHz
    LIMIT_i((int)(( Va_ref*INV_Vdc_2*0.5+0.5 )* CNT_max), CNT_max_98, CNT_max_2, &Ta_inv);
    LIMIT_i((int)(( Vb_ref*INV_Vdc_2*0.5+0.5 )* CNT_max), CNT_max_98, CNT_max_2, &Tb_inv);
    LIMIT_i((int)(( Vc_ref*INV_Vdc_2*0.5+0.5 )* CNT_max), CNT_max_98, CNT_max_2, &Tc_inv);
#endif

#if 1
    //3.75kHz
    LIMIT_i((int)(( Va_ref*0.5+0.5 )* CNT_max), CNT_max_98, CNT_max_2, &Ta_inv);
    LIMIT_i((int)(( Vb_ref*0.5+0.5 )* CNT_max), CNT_max_98, CNT_max_2, &Tb_inv);
    LIMIT_i((int)(( Vc_ref*0.5+0.5 )* CNT_max), CNT_max_98, CNT_max_2, &Tc_inv);
#endif
}



void VF_test3_SVPWM()
{
    register float  a;

    VF_vtg  += Tsamp    * VF_vtg_max    / VF_time;
    if(VF_vtg > VF_vtg_max)
    {
        VF_vtg = VF_vtg_max;
    }

    if(VF_vtg < VF_vtg_off)
    {
        a = VF_vtg_off;
    }
    else
    {
        a = VF_vtg;
    }

    VF_freq     = (a    / VF_vtg_max)   * VF_freq_max   + VF_freq_off;
    theta_VF    += 2    * PI    * VF_freq   * Tsamp;

    if(theta_VF > PI)
    {
        theta_VF    -= 2.   * PI;
    }
    else if(theta_VF < -PI)
    {
        theta_VF    += 2.   * PI;
    }

    a = theta_VF    * theta_VF;
    Sin_Theta_VF = SIN(theta_VF,a);
    Cos_Theta_VF = COS(a);

    DA_Test1 = sin(theta_VF) + sin(DA_Test_K1 * theta_VF);
    DA_Test2 = sin(theta_VF) + sin(DA_Test_K2 * theta_VF);

    Vds_ref = Cos_Theta_VF  * VF_vtg;
    Vqs_ref = Sin_Theta_VF  * VF_vtg;

    Va_ref  =      Vds_ref;
    Vb_ref  =    -(Vds_ref  - SQRT3  * Vqs_ref) * INV_2;
    Vc_ref  =    -(Va_ref   + Vb_ref);

#if 0
    INV_Vdc_2 = INV_Vdc * 2;

    //3.75kHz
    LIMIT_i((int)(( Va_ref*INV_Vdc_2*0.5+0.5 )* CNT_max), CNT_max_98, CNT_max_2, &Ta_inv);
    LIMIT_i((int)(( Vb_ref*INV_Vdc_2*0.5+0.5 )* CNT_max), CNT_max_98, CNT_max_2, &Tb_inv);
    LIMIT_i((int)(( Vc_ref*INV_Vdc_2*0.5+0.5 )* CNT_max), CNT_max_98, CNT_max_2, &Tc_inv);
#endif


#if 1
//    Vas_ref_SV=   Vds_ref;
//    Vbs_ref_SV= -(Vds_ref - SQRT3*Vqs_ref)/2.;
//    Vcs_ref_SV= -(Vas_ref_SV + Vbs_ref_SV);

    Vas_ref_SV= Va_ref;
    Vbs_ref_SV= Vb_ref;
    Vcs_ref_SV= Vc_ref;

    ///////////////////////////////////////////////////////////////////////////////////////////////
    //100kW T-npc DC Link balance controll code 추가 부분///
    Vmax_SV = (Vas_ref_SV>Vbs_ref_SV && Vas_ref_SV>Vcs_ref_SV)?Vas_ref_SV:((Vbs_ref_SV>Vas_ref_SV && Vbs_ref_SV>Vcs_ref_SV)?Vbs_ref_SV:Vcs_ref_SV);
    Vmin_SV = (Vas_ref_SV<Vbs_ref_SV && Vas_ref_SV<Vcs_ref_SV)?Vas_ref_SV:((Vbs_ref_SV<Vas_ref_SV && Vbs_ref_SV<Vcs_ref_SV)?Vbs_ref_SV:Vcs_ref_SV);

    // Vmax -> Vmax_SV
    // Vmin -> Vmin_SV
    // Vsn -> Vsn_SV
    Vsn_SV = -0.5*(Vmax_SV + Vmin_SV);

    Van_ref = Vas_ref_SV + Vsn_SV;
    Vbn_ref = Vbs_ref_SV + Vsn_SV;
    Vcn_ref = Vcs_ref_SV + Vsn_SV;

    INV_Vdc_2 = INV_Vdc * 2;

    //3.75kHz
    LIMIT_i((int)(( Van_ref*INV_Vdc_2*0.5+0.5 )* CNT_max), CNT_max_98, CNT_max_2, &Ta_inv);
    LIMIT_i((int)(( Vbn_ref*INV_Vdc_2*0.5+0.5 )* CNT_max), CNT_max_98, CNT_max_2, &Tb_inv);
    LIMIT_i((int)(( Vcn_ref*INV_Vdc_2*0.5+0.5 )* CNT_max), CNT_max_98, CNT_max_2, &Tc_inv);
#endif
}

void current_control_inv3()
{
#if 0
    register float  a;
    register int    i;
    float   T0, b, c;

    float   dead_time=0;

    float   vtemp=0.;
    float   xde=0., xqe=0., xds=0., xqs=0.;
#endif

#if 1
    float   T0;
    float   dead_time=0;
    float   xds=0., xqs=0.;
#endif

#if 0
    //10kW Basic setting
    pVfe1[DX][CFF]  = (1.   * We)   * Lc    * Iqe - Vde_flt;                   // F/F
    pVfe1[QX][CFF]  = -(1.  * We)   * Lc    * Ide - Vqe_flt;
//  pVfe1[QX][CFF]  = Vqe_flt;
#endif

#if 0
    pVfe1[DX][CFF]  = Vde_flt - (1.     * We)   * Lc    * Iqe;                   // F/F
    pVfe1[QX][CFF]  = Vqe_flt + (1.     * We)   * Lc    * Ide;
#endif

#if 0
    pVfe1[DX][CFF]  = Vde_flt + (1.     * We)   * Lc    * Iqe;                   // F/F
    pVfe1[QX][CFF]  = Vqe_flt - (1.     * We)   * Lc    * Ide;
#endif

#if 0
    pVfe1[DX][CFF]  =  Vde_flt - (1.     * We)   * Lc    * Iqe;                   // F/F
    pVfe1[QX][CFF]  = -Vqe_flt + (1.     * We)   * Lc    * Ide;
#endif

#if 1
    //6.5kW Basic setting
    pVfe1[DX][CFF]  =  Kp_Vde_ff * Vde + Kp_Iqe_ff * (1.     * We)   * Lc    * Iqe;                   // F/F
    pVfe1[QX][CFF]  =  Kp_Vqe_ff * Vqe + Kp_Ide_ff * (1.     * We)   * Lc    * Ide;

    Kp_Vde_ff_flt = Kp_Vde_ff * Vde_flt;
    Kp_Vqe_ff_flt = Kp_Vqe_ff * Vqe_flt;
    Kp_Iqe_ff_flt = Kp_Iqe_ff * (1.     * We)   * Lc    * Iqe;
    Kp_Ide_ff_flt = Kp_Ide_ff * (1.     * We)   * Lc    * Ide;
#endif


#if 0
    pVfe1[DX][CFF]  =  Kp_Vde_ff * Vde + Kp_Iqe_ff * (1.     * We)   * Lc    * Iqe;                   // F/F
    pVfe1[QX][CFF]  =  Kp_Vqe_ff * Vqe + Kp_Ide_ff * (1.     * We)   * Lc    * Ide;
#endif


#if 0
    //real mode
    Err_Ide = Ide - Ide_ref + Ide_ref_Cf;
    Err_Iqe = Iqe - Iqe_ref;
#endif


    //Iqe_ref, Iqe_ref_p 다름
    // 인버터 동작 + 입력 -> Test 2 고정
    // 컨버터 동작 - 입력 -> - 값을 입력하지 마세요. 주의~~~~
   // Iqe_ref = -1;
//    Iqe_ref = Iqe_ref_input_test;
#if 0
    //real mode
    Err_Ide = Ide - Ide_ref + Ide_ref_Cf;
    Err_Iqe = Iqe - Iqe_ref + Iqe_ref_Cf;
#endif

#if 1
    //real mode
    Err_Ide = Ide - Ide_ref + Ide_ref_Cf;
    if(flag_Iqe_ref_flt == 0)
    {
        Err_Iqe = Iqe - Iqe_ref + Iqe_ref_Cf;
    }
    else
    {
        Err_Iqe = Iqe - Iqe_ref_flt + Iqe_ref_Cf;
    }
#endif


#if 0
    //test mode
    Err_Ide = Ide - 0;
    Err_Iqe = Iqe - 2;      //test 2 A control define
#endif

#if 0
    //test mode
    Err_Ide = Ide - 0 + Ide_ref_Cf;
    Err_Iqe = Iqe - 2 + Iqe_ref_Cf;      //test 2 A control define

    Iqe_ref_Cf_add = -2 + Iqe_ref_Cf;
#endif


#if 0
    //real mode
    Err_Ide = Ide_ref - Ide + Ide_ref_Cf;
    Err_Iqe = Iqe_ref - Iqe + Iqe_ref_Cf;
#endif

#if 0
    //test mode
    Err_Ide = 0 - Ide;
    Err_Iqe = 2 - Iqe;      //test 2 A control define
#endif

#if 0
    //test mode
    Err_Ide = 0 - Ide + Ide_ref_Cf;
    Err_Iqe = 2 - Iqe + Iqe_ref_Cf;      //test 2 A control define

    Iqe_ref_Cf_add = 2 + Iqe_ref_Cf;
#endif


#if 0
    pVfe1[DX][CINT] += K_cc[CKIT]*( Err_Ide                     // D-Axis PI
                                - K_cc[CKA]*(pVfe1[DX][CACT] - pVfe1[DX][CREF]));

    pVfe1[DX][CFB]  = K_cc[CKP]*Err_Ide + pVfe1[DX][CINT];
    pVfe1[DX][CREF] = pVfe1[DX][CFB] + pVfe1[DX][CFF];

    pVfe1[QX][CINT] += K_cc[CKIT]*( Err_Iqe                     // Q-Axis PI
                                - K_cc[CKA]*(pVfe1[QX][CACT] - pVfe1[QX][CREF]));

    pVfe1[QX][CFB]  = K_cc[CKP] * Err_Iqe + pVfe1[QX][CINT];
    pVfe1[QX][CREF] = pVfe1[QX][CFB] + pVfe1[QX][CFF];
#endif

#if 0
    pVfe1[DX][CINT] += K_cc[CKIT]*( Err_Ide                     // D-Axis PI
                                - K_cc[CKA]*(pVfe1[DX][CREF] - pVfe1[DX][CACT]));


    K_cc_DX_CKIT_Err_Ide = K_cc[CKIT]*( Err_Ide );
    K_cc_DX_CKIT_K_cc_CKA = K_cc[CKIT]*(- K_cc[CKA]*(pVfe1[DX][CREF] - pVfe1[DX][CACT]));

    pVfe1[DX][CFB]  = K_cc[CKP]*Err_Ide + pVfe1[DX][CINT];
    pVfe1[DX][CREF] = pVfe1[DX][CFB] + pVfe1[DX][CFF];

    pVfe1[QX][CINT] += K_cc[CKIT]*( Err_Iqe                     // Q-Axis PI
                                - K_cc[CKA]*(pVfe1[QX][CREF] - pVfe1[QX][CACT]));

    pVfe1[QX][CFB]  = K_cc[CKP] * Err_Iqe + pVfe1[QX][CINT];
    pVfe1[QX][CREF] = pVfe1[QX][CFB] + pVfe1[QX][CFF];

    K_cc_QX_CKIT_Err_Iqe = K_cc[CKIT]*( Err_Iqe );
    K_cc_QX_CKIT_K_cc_CKA = K_cc[CKIT]*(- K_cc[CKA]*(pVfe1[QX][CREF] - pVfe1[QX][CACT]));
#endif


#if 1
    pVfe1[DX][CINT] += K_cc[CKITD]*( Err_Ide                     // D-Axis PI
                                - K_cc[CKAD]*(pVfe1[DX][CREF] - pVfe1[DX][CACT]));


    K_cc_DX_CKIT_Err_Ide = K_cc[CKITD]*( Err_Ide );
    K_cc_DX_CKIT_K_cc_CKA = K_cc[CKITD]*(- K_cc[CKAD]*(pVfe1[DX][CREF] - pVfe1[DX][CACT]));

    pVfe1[DX][CFB]  = K_cc[CKPD]*Err_Ide + pVfe1[DX][CINT];
    pVfe1[DX][CREF] = pVfe1[DX][CFB] + pVfe1[DX][CFF];

    pVfe1[QX][CINT] += K_cc[CKIT]*( Err_Iqe                     // Q-Axis PI
                                - K_cc[CKA]*(pVfe1[QX][CREF] - pVfe1[QX][CACT]));

    pVfe1[QX][CFB]  = K_cc[CKP] * Err_Iqe + pVfe1[QX][CINT];
    pVfe1[QX][CREF] = pVfe1[QX][CFB] + pVfe1[QX][CFF];

    K_cc_QX_CKIT_Err_Iqe = K_cc[CKIT]*( Err_Iqe );
    K_cc_QX_CKIT_K_cc_CKA = K_cc[CKIT]*(- K_cc[CKA]*(pVfe1[QX][CREF] - pVfe1[QX][CACT]));
#endif


#if 0
    pVfe1[DX][CINT] += K_cc[CKIT]*( Err_Ide                     // D-Axis PI
                                - K_cc[CKA]*(pVfe1[DX][CREF] - pVfe1[DX][CACT]));

    pVfe1[DX][CFB]  = K_cc[CKP]*Err_Ide + pVfe1[DX][CINT];
    pVfe1[DX][CREF] = pVfe1[DX][CFB] + pVfe1[DX][CFF];

    a=400;

    pVfe1[DX][CACT] = (( pVfe1[DX][CREF]  > a) ? a : ( pVfe1[DX][CREF]  < 0) ? 0 :  pVfe1[DX][CREF] );




    pVfe1[QX][CINT] += K_cc[CKIT]*( Err_Iqe                     // Q-Axis PI
                                - K_cc[CKA]*(pVfe1[QX][CREF] - pVfe1[QX][CACT]));

    pVfe1[QX][CFB]  = K_cc[CKP] * Err_Iqe + pVfe1[QX][CINT];
    pVfe1[QX][CREF] = pVfe1[QX][CFB] + pVfe1[QX][CFF];

    pVfe1[QX][CACT] = ((  pVfe1[QX][CREF] > a) ? a : (  pVfe1[QX][CREF] < 0) ? 0 :   pVfe1[QX][CREF]);


#endif

#if 0
    Vde_ref = pVfe1[DX][CREF];
    Vqe_ref = pVfe1[QX][CREF];
#endif

#if 1
    xds = Cos_theta_C   * pVfe1[DX][CREF] - Sin_theta_C * pVfe1[QX][CREF];    // e -> s
    xqs = Sin_theta_C   * pVfe1[DX][CREF] + Cos_theta_C * pVfe1[QX][CREF];

    Vds_ref = xds   * Cos_thetaT - xqs  * Sin_thetaT;                  // compensate delay
    Vqs_ref = xds   * Sin_thetaT + xqs  * Cos_thetaT;
#endif

#if 0
    Vde_ref = pVfe1[DX][CACT];
    Vqe_ref = pVfe1[QX][CACT];


    xds = Cos_theta_C   * pVfe1[DX][CACT] - Sin_theta_C * pVfe1[QX][CACT];    // e -> s
    xqs = Sin_theta_C   * pVfe1[DX][CACT] + Cos_theta_C * pVfe1[QX][CACT];

    Vds_ref = xds   * Cos_thetaT - xqs  * Sin_thetaT;                  // compensate delay
    Vqs_ref = xds   * Sin_thetaT + xqs  * Cos_thetaT;
#endif



#if 0
/*--------------------------------------*/
/*  limit voltage reference             */
/*--------------------------------------*/
    Vfds_ref    = Vds_ref;
    Vfqs_ref    = Vqs_ref;

//  if(Vdc_flt > Vdc_ref_set)
    if(Vdc_flt > Vdc_ref_set_inv)
    {
        Vmax    = (1-4. * T_dead    * INV_Tsamp)    * Vdc_ref_set_inv   * INV_SQRT3;
    }
    else
    {
        Vmax    = (1-4. * T_dead    * INV_Tsamp)    * Vdc_flt           * INV_SQRT3;
    }

    Vmax2   = Vmax  * Vmax;
    Vf_mag2 = Vfds_ref  * Vfds_ref  + Vfqs_ref  * Vfqs_ref;


    if(Vf_mag2 > Vmax2)
    {   // over-modulation region
        Flag_volt_limit = 1;

        Vf_mag  = sqrt(Vf_mag2);

        vtemp=(Vmax)/(Vf_mag+1.e-30);
        Vfds_ref    = vtemp * Vds_ref;
        Vfqs_ref    = vtemp * Vqs_ref;

        xde = Cos_theta * Vfds_ref + Sin_theta  * Vfqs_ref;
        xqe =-Sin_theta * Vfds_ref + Cos_theta  * Vfqs_ref;

        pVfe1[DX][CACT] = xde   * Cos_thetaT + xqe  * Sin_thetaT;
        pVfe1[QX][CACT] =-xde   * Sin_thetaT + xqe  * Cos_thetaT;
    }
    else
    {
        Flag_volt_limit = 0;
        pVfe1[DX][CACT] = pVfe1[DX][CREF];
        pVfe1[QX][CACT] = pVfe1[QX][CREF];
    }
#endif

    Va_ref  =      Vds_ref;
    Vb_ref  =    -(Vds_ref  - SQRT3 * Vqs_ref) * INV_2;
    Vc_ref  =    -(Va_ref   + Vb_ref);

#if 0
    Ta_real_inv = (int)((0.5    * Va_ref   * INV_Vdc   + 0.5)  * CNT_max);
    Tb_real_inv = (int)((0.5    * Vb_ref   * INV_Vdc   + 0.5)  * CNT_max);
    Tc_real_inv = (int)((0.5    * Vc_ref   * INV_Vdc   + 0.5)  * CNT_max);

    Ta_inv = ((Ta_real_inv > CNT_max_98)    ? CNT_max_98    : (Ta_real_inv  < 60) ? 60  : Ta_real_inv);
    Tb_inv = ((Tb_real_inv > CNT_max_98)    ? CNT_max_98    : (Tb_real_inv  < 60) ? 60  : Tb_real_inv);
    Tc_inv = ((Tc_real_inv > CNT_max_98)    ? CNT_max_98    : (Tc_real_inv  < 60) ? 60  : Tc_real_inv);
#endif


#if 0
    Tsamp_Inv_Vdc   = Tsamp * INV_Vdc;
#endif

#if 1
    Tsamp_Inv_Vdc   = Tsamp * INV_Vdc * Tsamp_Inv_Vdc_gain;
#endif


    Tsamp_Inv_Vdc = fabs(Tsamp_Inv_Vdc);   // 2005.03.23 //

    Ta  = Va_ref    * Tsamp_Inv_Vdc;                                    // imaginary switching time
    Tb  = Vb_ref    * Tsamp_Inv_Vdc;

//  Tc  = Vc_ref    * Tsamp_Inv_Vdc;
    Tc  = -(Ta  + Tb);

    if( Ta>Tb ) { Vmax=Ta;  Vmin=Tb; }                          // 3-elements sorting : a(Tmax),b(Tmin)
    else        { Vmax=Tb;  Vmin=Ta; }

    if( Tc>Vmax )   Vmax=Tc;
    if( Tc<Vmin )   Vmin=Tc;

    dead_time=(T_dead > T_dead_comp) ? T_dead : T_dead_comp;    // select dead-time
    T0=Tsamp-(Vmax-Vmin);

    T0_check = (Tsamp-(Vmax-Vmin) ) * Freq_ctrl * 1000;

    if(Flag_over_check==1)
    {
        Flag_over_modu=0;
        pVfe1[DX][CACT]=pVfe1[DX][CREF];
        pVfe1[QX][CACT]=pVfe1[QX][CREF];
    }
    else
    {
        if( T0 < 2.*dead_time )
        {                                    // over-modulation
            Flag_over_modu=1;
            Vmax=(Tsamp-2.*dead_time)/(Vmax-Vmin+1.e-30);
            Ta*=Vmax; Tb*=Vmax; Tc*=Vmax; Vmin*=Vmax;   T0=2.*dead_time;
            Vds_ref*=Vmax;  Vqs_ref*=Vmax;  Vde_ref*=Vmax;  Vqe_ref*=Vmax;
            pVfe1[DX][CACT]=Vde_ref;    pVfe1[QX][CACT]=Vqe_ref;

        }
        else
        {
            Flag_over_modu=0;
            pVfe1[DX][CACT]=pVfe1[DX][CREF];
            pVfe1[QX][CACT]=pVfe1[QX][CREF];
        }
    }






    Vmax=T0*0.5-Vmin;                                                   // effective time calculation
    Ta+=Vmax;   Tb+=Vmax;   Tc+=Vmax;

#if 1
    //3.75kHz
    LIMIT_i((int)( Ta*Scale_gating*0.5+0.5 ), CNT_max_98, CNT_max_2, &Ta_inv);
    LIMIT_i((int)( Tb*Scale_gating*0.5+0.5 ), CNT_max_98, CNT_max_2, &Tb_inv);
    LIMIT_i((int)( Tc*Scale_gating*0.5+0.5 ), CNT_max_98, CNT_max_2, &Tc_inv);
#endif

}


#if 0

// 20.12.14.lsc harmonic 함수 신규 추가
void current_control_inv3_harmonic()
{
#if 0
    float   vtemp=0.;
    float   xde=0., xqe=0., xds=0., xqs=0.;
#endif

//  pVfe1[DX][CFF]= (1.*We)*Lc*Iqe + Vde_flt;                   // F/F
//  Ide_cff_p = Iqe     * We * Lc + Vde_flt;
//  Ide_cff_p = Iqe_p   * We * Lc - Vde_p;
    Ide_cff_p = -Iqe_p  * We * Lc + Vde_p;

//  Vfe1[QX][CFF]= Vqe_flt - (1.*We)*Lc*Ide;
//  Iqe_cff_p = -Ide    * We * Lc + Vqe_flt;
    Iqe_cff_p = Ide_p   * We * Lc + Vqe_p;

//  Ide_cff_n = Iqe_n   * We * Lc - Vde_n;
    Ide_cff_n = -Iqe_n  * We * Lc + Vde_n;
    Iqe_cff_n = Ide_n   * We * Lc + Vqe_n;

    //Ide_ref, Ide_ref_p 다름
    Ide_err_p = Ide_p - Ide_ref + Ide_ref_Cf_p;
    Ide_ref_integ_p += Ki_ide*(Ide_err_p - Ka_ide*( Ide_ref_p - Ide_ref_out_p));
    Ide_out_p = Kp_ide*Ide_err_p + Ide_ref_integ_p;
    Ide_ref_p = Ide_out_p + Ide_cff_p ;
    Ide_ref_out_p = (Ide_ref_p <= -400.)?-400.:((Ide_ref_p >= 400.)?400.:Ide_ref_p);

    //Iqe_ref, Iqe_ref_p 다름
    Iqe_err_p = Iqe_p - Iqe_ref;
    Iqe_ref_integ_p += Ki_iqe*( Iqe_err_p - Ka_iqe*(Iqe_ref_p -Iqe_ref_out_p));
    Iqe_out_p = Kp_iqe*Iqe_err_p +Iqe_ref_integ_p;
    Iqe_ref_p = Iqe_out_p + Iqe_cff_p;
    Iqe_ref_out_p = (Iqe_ref_p <= -400.)?-400.:((Iqe_ref_p >= 400.)?400.:Iqe_ref_p);

    Ide_err_n = Ide_n - Ide_ref_n + Ide_ref_Cf_n;
    Ide_ref_integ_n += Ki_ide*(Ide_err_n - Ka_ide*( Ide_ref_p_n - Ide_ref_out_n));
    Ide_out_n = Kp_ide*Ide_err_n + Ide_ref_integ_n;
    Ide_ref_p_n = Ide_out_n + Ide_cff_n ;
    Ide_ref_out_n = (Ide_ref_p_n <= -400.)?-400.:((Ide_ref_p_n >= 400.)?400.:Ide_ref_p_n);

    Iqe_err_n = Iqe_n - Iqe_ref_n;
    Iqe_ref_integ_n += Ki_iqe*( Iqe_err_n - Ka_iqe*(Iqe_ref_p_n -Iqe_ref_out_n));
    Iqe_out_n = Kp_iqe*Iqe_err_n +Iqe_ref_integ_n;
    Iqe_ref_p_n = Iqe_out_n + Iqe_cff_n;
    Iqe_ref_out_n = (Iqe_ref_p_n <= -400.)?-400.:((Iqe_ref_p_n >= 400.)?400.:Iqe_ref_p_n);

//  Vde_ref = pVfe1[DX][CREF];
//  Vqe_ref = pVfe1[QX][CREF];

//  xds = Cos_theta*pVfe1[DX][CREF] - Sin_theta*pVfe1[QX][CREF];        // e -> s
//  xqs = Sin_theta*pVfe1[DX][CREF] + Cos_theta*pVfe1[QX][CREF];

//  xds = Cos_theta_C*pVfe1[DX][CREF] - Sin_theta_C*pVfe1[QX][CREF];    // e -> s
    Vcon_alpha_p =  Ide_ref_out_p*Cos_theta_C - Iqe_ref_out_p*Sin_theta_C;

//  xqs = Sin_theta_C*pVfe1[DX][CREF] + Cos_theta_C*pVfe1[QX][CREF];
    Vcon_beta_p =   Ide_ref_out_p*Sin_theta_C +  Iqe_ref_out_p*Cos_theta_C;

    Vcon_alpha_n =  Ide_ref_out_n*Cos_theta_C_n   -  Iqe_ref_out_n*Sin_theta_C_n;
    Vcon_beta_n =   Ide_ref_out_n*Sin_theta_C_n  + Iqe_ref_out_n*Cos_theta_C_n;

    Vas_ref_p = Vcon_alpha_p;
//  Vbs_ref_p = -0.5*Vcon_alpha_p + 0.5*SQRT3*Vcon_beta_p;
    Vbs_ref_p = -0.5*Vcon_alpha_p + SQRT3_INV_2*Vcon_beta_p;
    Vcs_ref_p = -(Vas_ref_p +Vbs_ref_p ) ;

    Vas_ref_n = Vcon_alpha_n;
//  Vbs_ref_n = -0.5*Vcon_alpha_n + 0.5*SQRT3*Vcon_beta_n;
    Vbs_ref_n = -0.5*Vcon_alpha_n + SQRT3_INV_2*Vcon_beta_n;
    Vcs_ref_n = -(Vas_ref_n +Vbs_ref_n ) ;

//  Vds_ref = xds*Cos_thetaT - xqs*Sin_thetaT;                  // compensate delay
//  Vqs_ref = xds*Sin_thetaT + xqs*Cos_thetaT;

#if 0
    /*--------------------------------------*/
    /*  limit voltage reference             */
    /*--------------------------------------*/
    Vfds_ref=Vds_ref;
    Vfqs_ref=Vqs_ref;

    if(Vdc_flt > Vdc_ref_set)   { Vmax=(1-4.*T_dead*INV_Tsamp)*Vdc_ref_set_inv*INV_SQRT3;   }
    else                        { Vmax=(1-4.*T_dead*INV_Tsamp)*Vdc_flt*INV_SQRT3;       }
    Vmax2=Vmax*Vmax;
    Vf_mag2=Vfds_ref*Vfds_ref+Vfqs_ref*Vfqs_ref;

    if(Vf_mag2 > Vmax2) {               // over-modulation region
        Flag_volt_limit=1;

        Vf_mag=sqrt(Vf_mag2);

        vtemp=(Vmax)/(Vf_mag+1.e-30);
        Vfds_ref=vtemp*Vds_ref;
        Vfqs_ref=vtemp*Vqs_ref;

        xde = Cos_theta*Vfds_ref + Sin_theta*Vfqs_ref;
        xqe =-Sin_theta*Vfds_ref + Cos_theta*Vfqs_ref;

        pVfe1[DX][CACT] = xde*Cos_thetaT + xqe*Sin_thetaT;
        pVfe1[QX][CACT] =-xde*Sin_thetaT + xqe*Cos_thetaT;
    }
    else {
        Flag_volt_limit=0;
        pVfe1[DX][CACT]=pVfe1[DX][CREF];    pVfe1[QX][CACT]=pVfe1[QX][CREF];
    }


    Va_ref  =      Vds_ref;
    Vb_ref  =    -(Vds_ref - SQRT3*Vqs_ref)/2.;
    Vc_ref  =    -(Va_ref + Vb_ref);

    Ta_real_inv = (int)((0.5*Va_ref*INV_Vdc+0.5)*2500);
    Tb_real_inv = (int)((0.5*Vb_ref*INV_Vdc+0.5)*2500);
    Tc_real_inv = (int)((0.5*Vc_ref*INV_Vdc+0.5)*2500);
#endif

#if 0
    Van_ref =  Vas_ref_p + Vas_ref_n ;
    Vbn_ref =  Vbs_ref_p + Vbs_ref_n ;
    Vcn_ref =  Vcs_ref_p + Vcs_ref_n ;

    Ta_real_inv = (int)((0.5    * Van_ref   * INV_Vdc   + 0.5)  * CNT_max);
    Tb_real_inv = (int)((0.5    * Vbn_ref   * INV_Vdc   + 0.5)  * CNT_max);
    Tc_real_inv = (int)((0.5    * Vcn_ref   * INV_Vdc   + 0.5)  * CNT_max);

    Ta_inv = ((Ta_real_inv > CNT_max_98)    ? CNT_max_98    : (Ta_real_inv  < 60) ? 60  : Ta_real_inv);
    Tb_inv = ((Tb_real_inv > CNT_max_98)    ? CNT_max_98    : (Tb_real_inv  < 60) ? 60  : Tb_real_inv);
    Tc_inv = ((Tc_real_inv > CNT_max_98)    ? CNT_max_98    : (Tc_real_inv  < 60) ? 60  : Tc_real_inv);
#endif

    Va_ref =  Vas_ref_p + Vas_ref_n ;
    Vb_ref =  Vbs_ref_p + Vbs_ref_n ;
    Vc_ref =  Vcs_ref_p + Vcs_ref_n ;
}
#endif


// 20.12.14.lsc harmonic 함수 신규 추가
void current_control_inv3_harmonic()
{
#if 0
    register float  a;
    register int    i;
    float   T0, b, c;
    float   dead_time=0;

    float   vtemp=0.;
    float   xde=0., xqe=0., xds=0., xqs=0.;
#endif

    // Esa = real 동상
    // Ia = real 역상
    // Va_ref = real 동상

#if 0
    Ide_cff_p = -Iqe_p * We * Lc + Vde_p;
    Iqe_cff_p = Ide_p * We * Lc + Vqe_p;
    Ide_cff_n = -Iqe_n * We * Lc + Vde_n;
    Iqe_cff_n = Ide_n * We * Lc + Vqe_n;
#endif

#if 0
    Ide_cff_p = -Iqe_p * We * Lc + Vde_p;
    Iqe_cff_p = Ide_p * We * Lc + 2* Vqe_p;
    Ide_cff_n = -Iqe_n * We * Lc + Vde_n;
    Iqe_cff_n = Ide_n * We * Lc + Vqe_n;
#endif

#if 0
    Ide_cff_p = 0;
    Iqe_cff_p = 0;

    Ide_cff_n = 0;
    Iqe_cff_n = 0;
#endif

#if 0
    Ide_cff_p = Kp_Iqe_ff * Iqe_p * We * Lc + Kp_Vde_ff * Vde_p;
    Iqe_cff_p = Kp_Ide_ff * Ide_p * We * Lc + Kp_Vqe_ff * Vqe_p;

    Ide_cff_n = -Iqe_n * We * Lc + Vde_n;
    Iqe_cff_n = Ide_n * We * Lc + Vqe_n;
#endif


#if 0
    Ide_cff_p = Kp_Iqe_ff * Iqe_p * We * Lc + Kp_Vde_ff * Vde_p_flt;
    Iqe_cff_p = Kp_Ide_ff * Ide_p * We * Lc + Kp_Vqe_ff * Vqe_p_flt;

    Ide_cff_n = -Iqe_n * We * Lc + Vde_n_flt;
    Iqe_cff_n = Ide_n * We * Lc + Vqe_n_flt;
#endif

#if 0
    Ide_cff_p = Kp_Iqe_ff * Iqe_p_flt * We * Lc + Kp_Vde_ff * Vde_p;
    Iqe_cff_p = Kp_Ide_ff * Ide_p_flt * We * Lc + Kp_Vqe_ff * Vqe_p;

    Ide_cff_n = -Iqe_n_flt * We * Lc + Vde_n;
    Iqe_cff_n = Ide_n_flt * We * Lc + Vqe_n;
#endif

#if 0
    Ide_cff_p = Kp_Iqe_ff * Iqe_p * We * Lc + Kp_Vde_ff * Vde_p;
    Iqe_cff_p = Kp_Ide_ff * Ide_p * We * Lc + Kp_Vqe_ff * Vqe_p;

    Ide_cff_n = -Iqe_n * We * Lc + Vde_n;
    Iqe_cff_n = Ide_n * We * Lc + Vqe_n;
#endif

#if 1
    Ide_cff_p = Kp_Iqe_ff * Iqe_p_flt * We * Lc + Kp_Vde_ff * Vde_p_flt;
    Iqe_cff_p = Kp_Ide_ff * Ide_p_flt * We * Lc + Kp_Vqe_ff * Vqe_p_flt;

    Ide_cff_n = -Iqe_n_flt * We * Lc + Vde_n_flt;
    Iqe_cff_n = Ide_n_flt * We * Lc + Vqe_n_flt;
#endif


#if 0
    pVfe1[DX][CFF]  =  Kp_Vde_ff * Vde_flt + Kp_Iqe_ff * (1.     * We)   * Lc    * Iqe;                   // F/F
    pVfe1[QX][CFF]  =  Kp_Vqe_ff * Vqe_flt + Kp_Ide_ff * (1.     * We)   * Lc    * Ide;
#endif


    //Ide_ref, Ide_ref_p 다름
    Ide_err_p = Ide_p - Ide_ref + Ide_ref_Cf_p;
    Ide_ref_integ_p += Ki_ide*(Ide_err_p - Ka_ide*( Ide_ref_p - Ide_ref_out_p));
    Ide_out_p = Kp_ide*Ide_err_p + Ide_ref_integ_p;
    Ide_ref_p = Ide_out_p + Ide_cff_p  ;


    Ka_ide_fb_p = Ka_ide*( Ide_ref_p - Ide_ref_out_p);


//    Ide_ref_out_p = (Ide_ref_p <= -850.)?-850.:((Ide_ref_p >= 850.)?850.:Ide_ref_p);
//    Ide_ref_out_p = (Ide_ref_p <= -800.)?-800.:((Ide_ref_p >= 800.)?800.:Ide_ref_p);
//    Ide_ref_out_p = (Ide_ref_p <= -700.)?-700.:((Ide_ref_p >= 700.)?700.:Ide_ref_p);
    Ide_ref_out_p = (Ide_ref_p <= -400.)?-400.:((Ide_ref_p >= 400.)?400.:Ide_ref_p);
//    Ide_ref_out_p = (Ide_ref_p <= -200.)?-200.:((Ide_ref_p >= 200.)?200.:Ide_ref_p);

    //Iqe_ref, Iqe_ref_p 다름
    // 인버터 동작 - 입력 -> Test -1 고정
    // 컨버터 동작 + 입력 ->
   // Iqe_ref = -1;
//    Iqe_ref = Iqe_ref_input_test;


    if(flag_Iqe_ref_flt == 0)
    {
        Iqe_err_p = Iqe_p - Iqe_ref  + Iqe_ref_Cf;
    }
    else
    {
        Iqe_err_p = Iqe_p - Iqe_ref_flt  + Iqe_ref_Cf;
    }

    Iqe_ref_integ_p += Ki_iqe*( Iqe_err_p - Ka_iqe*(Iqe_ref_p -Iqe_ref_out_p));
    Iqe_out_p = Kp_iqe*Iqe_err_p +Iqe_ref_integ_p;
    Iqe_ref_p = Iqe_out_p + Iqe_cff_p  ;


    Ka_iqe_fb_p = Ka_iqe*(Iqe_ref_p -Iqe_ref_out_p);

//    Iqe_ref_out_p = (Iqe_ref_p <= -850.)?-850.:((Iqe_ref_p >= 850.)?850.:Iqe_ref_p);
//    Iqe_ref_out_p = (Iqe_ref_p <= -800.)?-800.:((Iqe_ref_p >= 800.)?800.:Iqe_ref_p);
//    Iqe_ref_out_p = (Iqe_ref_p <= -700.)?-700.:((Iqe_ref_p >= 700.)?700.:Iqe_ref_p);
    Iqe_ref_out_p = (Iqe_ref_p <= -400.)?-400.:((Iqe_ref_p >= 400.)?400.:Iqe_ref_p);
//    Iqe_ref_out_p = (Iqe_ref_p <= -200.)?-200.:((Iqe_ref_p >= 200.)?200.:Iqe_ref_p);

    Ide_err_n = Ide_n - Ide_ref_n + Ide_ref_Cf_n;
    Ide_ref_integ_n += Ki_ide*(Ide_err_n - Ka_ide*( Ide_ref_p_n - Ide_ref_out_n));
    Ide_out_n = Kp_ide*Ide_err_n + Ide_ref_integ_n;
    Ide_ref_p_n = Ide_out_n + Ide_cff_n  ;

    Ka_ide_fb_n = Ka_ide*( Ide_ref_p_n - Ide_ref_out_n);


//    Ide_ref_out_n = (Ide_ref_p_n <= -850.)?-850.:((Ide_ref_p_n >= 850.)?850.:Ide_ref_p_n);
//    Ide_ref_out_n = (Ide_ref_p_n <= -800.)?-800.:((Ide_ref_p_n >= 800.)?800.:Ide_ref_p_n);
//    Ide_ref_out_n = (Ide_ref_p_n <= -700.)?-700:((Ide_ref_p_n >= 700.)?700.:Ide_ref_p_n);
    Ide_ref_out_n = (Ide_ref_p_n <= -400.)?-400.:((Ide_ref_p_n >= 400.)?400.:Ide_ref_p_n);
//    Ide_ref_out_n = (Ide_ref_p_n <= -200.)?-200.:((Ide_ref_p_n >= 200.)?200.:Ide_ref_p_n);

    Iqe_err_n = Iqe_n - Iqe_ref_n;
    Iqe_ref_integ_n += Ki_iqe*( Iqe_err_n - Ka_iqe*(Iqe_ref_p_n -Iqe_ref_out_n));
    Iqe_out_n = Kp_iqe*Iqe_err_n +Iqe_ref_integ_n;
    Iqe_ref_p_n = Iqe_out_n + Iqe_cff_n;

    Ka_iqe_fb_n = Ka_iqe*(Iqe_ref_p_n -Iqe_ref_out_n);


//    Iqe_ref_out_n = (Iqe_ref_p_n <= -850.)?-850.:((Iqe_ref_p_n >= 850.)?850.:Iqe_ref_p_n);
//    Iqe_ref_out_n = (Iqe_ref_p_n <= -800.)?-800.:((Iqe_ref_p_n >= 800.)?800.:Iqe_ref_p_n);
//    Iqe_ref_out_n = (Iqe_ref_p_n <= -700.)?-700.:((Iqe_ref_p_n >= 700.)?700.:Iqe_ref_p_n);
    Iqe_ref_out_n = (Iqe_ref_p_n <= -400.)?-400.:((Iqe_ref_p_n >= 400.)?400.:Iqe_ref_p_n);
//    Iqe_ref_out_n = (Iqe_ref_p_n <= -200.)?-200.:((Iqe_ref_p_n >= 200.)?200.:Iqe_ref_p_n);


//  Vde_ref = pVfe1[DX][CREF];
//  Vqe_ref = pVfe1[QX][CREF];

//  xds = Cos_theta*pVfe1[DX][CREF] - Sin_theta*pVfe1[QX][CREF];        // e -> s
//  xqs = Sin_theta*pVfe1[DX][CREF] + Cos_theta*pVfe1[QX][CREF];

//  xds = Cos_theta_C*pVfe1[DX][CREF] - Sin_theta_C*pVfe1[QX][CREF];    // e -> s
    Vcon_alpha_p =  Ide_ref_out_p*Cos_theta_C - Iqe_ref_out_p*Sin_theta_C ;//- Vds_5th_ref_p;

//  xqs = Sin_theta_C*pVfe1[DX][CREF] + Cos_theta_C*pVfe1[QX][CREF];
    Vcon_beta_p =   Ide_ref_out_p*Sin_theta_C +  Iqe_ref_out_p*Cos_theta_C ;//- Vqs_5th_ref_p;

    Vcon_alpha_n =  Ide_ref_out_n*Cos_theta_C_n   -  Iqe_ref_out_n*Sin_theta_C_n  ;//- Vds_5th_ref_n;
    Vcon_beta_n =   Ide_ref_out_n*Sin_theta_C_n  + Iqe_ref_out_n*Cos_theta_C_n;// - Vqs_5th_ref_n ;


    Vas_ref_p = Vcon_alpha_p;
//  Vbs_ref_p = -0.5*Vcon_alpha_p + 0.5*SQRT3*Vcon_beta_p;
    Vbs_ref_p = -0.5*Vcon_alpha_p + SQRT3_INV_2*Vcon_beta_p;
    Vcs_ref_p = -(Vas_ref_p +Vbs_ref_p ) ;

    Vas_ref_n = Vcon_alpha_n;
    Vbs_ref_n = -0.5*Vcon_alpha_n + SQRT3_INV_2*Vcon_beta_n;
    Vcs_ref_n = -(Vas_ref_n +Vbs_ref_n ) ;


//  Vds_ref = xds*Cos_thetaT - xqs*Sin_thetaT;                  // compensate delay
//  Vqs_ref = xds*Sin_thetaT + xqs*Cos_thetaT;


#if 0
    /*--------------------------------------*/
    /*  limit voltage reference             */
    /*--------------------------------------*/
    Vfds_ref=Vds_ref;
    Vfqs_ref=Vqs_ref;

    if(Vdc_flt > Vdc_ref_set)   { Vmax=(1-4.*T_dead*INV_Tsamp)*Vdc_ref_set_inv*INV_SQRT3;   }
    else                        { Vmax=(1-4.*T_dead*INV_Tsamp)*Vdc_flt*INV_SQRT3;       }
    Vmax2=Vmax*Vmax;
    Vf_mag2=Vfds_ref*Vfds_ref+Vfqs_ref*Vfqs_ref;

    if(Vf_mag2 > Vmax2) {               // over-modulation region
        Flag_volt_limit=1;

        Vf_mag=sqrt(Vf_mag2);

        vtemp=(Vmax)/(Vf_mag+1.e-30);
        Vfds_ref=vtemp*Vds_ref;
        Vfqs_ref=vtemp*Vqs_ref;

        xde = Cos_theta*Vfds_ref + Sin_theta*Vfqs_ref;
        xqe =-Sin_theta*Vfds_ref + Cos_theta*Vfqs_ref;

        pVfe1[DX][CACT] = xde*Cos_thetaT + xqe*Sin_thetaT;
        pVfe1[QX][CACT] =-xde*Sin_thetaT + xqe*Cos_thetaT;
    }
    else {
        Flag_volt_limit=0;
        pVfe1[DX][CACT]=pVfe1[DX][CREF];    pVfe1[QX][CACT]=pVfe1[QX][CREF];
    }


    Va_ref  =      Vds_ref;
    Vb_ref  =    -(Vds_ref - SQRT3*Vqs_ref)/2.;
    Vc_ref  =    -(Va_ref + Vb_ref);

    Ta_real_inv = (int)((0.5*Va_ref*INV_Vdc+0.5)*2500);
    Tb_real_inv = (int)((0.5*Vb_ref*INV_Vdc+0.5)*2500);
    Tc_real_inv = (int)((0.5*Vc_ref*INV_Vdc+0.5)*2500);
#endif

//    Va_ref =  -Vas_ref_p  - Vas_ref_n ;
//    Vb_ref =  -Vbs_ref_p  - Vbs_ref_n ;
//    Vc_ref =  -Vcs_ref_p  - Vcs_ref_n ;

    Va_ref =  Vas_ref_p  + Vas_ref_n ;
    Vb_ref =  Vbs_ref_p  + Vbs_ref_n ;
    Vc_ref =  Vcs_ref_p  + Vcs_ref_n ;

#if 0
    Ta_real_inv = (int)((0.5    * Va_ref   * INV_Vdc   + 0.5)  * CNT_max);
    Tb_real_inv = (int)((0.5    * Vb_ref   * INV_Vdc   + 0.5)  * CNT_max);
    Tc_real_inv = (int)((0.5    * Vc_ref   * INV_Vdc   + 0.5)  * CNT_max);

    Ta_inv = ((Ta_real_inv > CNT_max_98)    ? CNT_max_98    : (Ta_real_inv  < 60) ? 60  : Ta_real_inv);
    Tb_inv = ((Tb_real_inv > CNT_max_98)    ? CNT_max_98    : (Tb_real_inv  < 60) ? 60  : Tb_real_inv);
    Tc_inv = ((Tc_real_inv > CNT_max_98)    ? CNT_max_98    : (Tc_real_inv  < 60) ? 60  : Tc_real_inv);
#endif

#if 0

//    Vas_ref_SV=   Vds_ref;
//    Vbs_ref_SV= -(Vds_ref - SQRT3*Vqs_ref)/2.;
//    Vcs_ref_SV= -(Vas_ref_SV + Vbs_ref_SV);

    Vas_ref_SV= Va_ref;
    Vbs_ref_SV= Vb_ref;
    Vcs_ref_SV= Vc_ref;

    ///////////////////////////////////////////////////////////////////////////////////////////////
    //100kW T-npc DC Link balance controll code 추가 부분///
    Vmax_SV = (Vas_ref_SV>Vbs_ref_SV && Vas_ref_SV>Vcs_ref_SV)?Vas_ref_SV:((Vbs_ref_SV>Vas_ref_SV && Vbs_ref_SV>Vcs_ref_SV)?Vbs_ref_SV:Vcs_ref_SV);
    Vmin_SV = (Vas_ref_SV<Vbs_ref_SV && Vas_ref_SV<Vcs_ref_SV)?Vas_ref_SV:((Vbs_ref_SV<Vas_ref_SV && Vbs_ref_SV<Vcs_ref_SV)?Vbs_ref_SV:Vcs_ref_SV);

    // Vmax -> Vmax_SV
    // Vmin -> Vmin_SV
    // Vsn -> Vsn_SV
    Vsn_SV = -0.5*(Vmax_SV + Vmin_SV);

    Van_ref = Vas_ref_SV + Vsn_SV;
    Vbn_ref = Vbs_ref_SV + Vsn_SV;
    Vcn_ref = Vcs_ref_SV + Vsn_SV;

    Ta_real_inv = (int)((0.5    * Van_ref   * INV_Vdc   + 0.5)  * CNT_max);
    Tb_real_inv = (int)((0.5    * Vbn_ref   * INV_Vdc   + 0.5)  * CNT_max);
    Tc_real_inv = (int)((0.5    * Vcn_ref   * INV_Vdc   + 0.5)  * CNT_max);

    Ta_inv = ((Ta_real_inv > CNT_max_98)    ? CNT_max_98    : (Ta_real_inv  < 60) ? 60  : Ta_real_inv);
    Tb_inv = ((Tb_real_inv > CNT_max_98)    ? CNT_max_98    : (Tb_real_inv  < 60) ? 60  : Tb_real_inv);
    Tc_inv = ((Tc_real_inv > CNT_max_98)    ? CNT_max_98    : (Tc_real_inv  < 60) ? 60  : Tc_real_inv);
#endif


#if 1
//    Vas_ref_SV=   Vds_ref;
//    Vbs_ref_SV= -(Vds_ref - SQRT3*Vqs_ref)/2.;
//    Vcs_ref_SV= -(Vas_ref_SV + Vbs_ref_SV);

    Vas_ref_SV= Va_ref;
    Vbs_ref_SV= Vb_ref;
    Vcs_ref_SV= Vc_ref;

    ///////////////////////////////////////////////////////////////////////////////////////////////
    //100kW T-npc DC Link balance controll code 추가 부분///
    Vmax_SV = (Vas_ref_SV>Vbs_ref_SV && Vas_ref_SV>Vcs_ref_SV)?Vas_ref_SV:((Vbs_ref_SV>Vas_ref_SV && Vbs_ref_SV>Vcs_ref_SV)?Vbs_ref_SV:Vcs_ref_SV);
    Vmin_SV = (Vas_ref_SV<Vbs_ref_SV && Vas_ref_SV<Vcs_ref_SV)?Vas_ref_SV:((Vbs_ref_SV<Vas_ref_SV && Vbs_ref_SV<Vcs_ref_SV)?Vbs_ref_SV:Vcs_ref_SV);

    // Vmax -> Vmax_SV
    // Vmin -> Vmin_SV
    // Vsn -> Vsn_SV
    Vsn_SV = -0.5*(Vmax_SV + Vmin_SV);

    //svpwm
    Van_ref = Vas_ref_SV + Vsn_SV;
    Vbn_ref = Vbs_ref_SV + Vsn_SV;
    Vcn_ref = Vcs_ref_SV + Vsn_SV;

    //spwm
//    Van_ref = Vas_ref_SV;
//    Vbn_ref = Vbs_ref_SV;
//    Vcn_ref = Vcs_ref_SV;

    INV_Vdc_2 = INV_Vdc * 2;

    //3.75kHz
    LIMIT_i((int)(( Van_ref*INV_Vdc_2*0.5+0.5 )* CNT_max), CNT_max_98, CNT_max_2, &Ta_inv);
    LIMIT_i((int)(( Vbn_ref*INV_Vdc_2*0.5+0.5 )* CNT_max), CNT_max_98, CNT_max_2, &Tb_inv);
    LIMIT_i((int)(( Vcn_ref*INV_Vdc_2*0.5+0.5 )* CNT_max), CNT_max_98, CNT_max_2, &Tc_inv);
#endif

}

void spwm()
{
#if 1
    //3.75kHz
    LIMIT_i((int)(( Va_ref*INV_Vdc*0.5+0.5 )* CNT_max), CNT_max_98, CNT_max_2, &Ta_inv);
    LIMIT_i((int)(( Vb_ref*INV_Vdc*0.5+0.5 )* CNT_max), CNT_max_98, CNT_max_2, &Tb_inv);
    LIMIT_i((int)(( Vc_ref*INV_Vdc*0.5+0.5 )* CNT_max), CNT_max_98, CNT_max_2, &Tc_inv);
#endif

#if 0
    Ta_real_inv = (int)((0.5    * Va_ref   * INV_Vdc   + 0.5)  * CNT_max);
    Tb_real_inv = (int)((0.5    * Vb_ref   * INV_Vdc   + 0.5)  * CNT_max);
    Tc_real_inv = (int)((0.5    * Vc_ref   * INV_Vdc   + 0.5)  * CNT_max);

    Ta_inv = ((Ta_real_inv > CNT_max_98)    ? CNT_max_98    : (Ta_real_inv  < 60) ? 60  : Ta_real_inv);
    Tb_inv = ((Tb_real_inv > CNT_max_98)    ? CNT_max_98    : (Tb_real_inv  < 60) ? 60  : Tb_real_inv);
    Tc_inv = ((Tc_real_inv > CNT_max_98)    ? CNT_max_98    : (Tc_real_inv  < 60) ? 60  : Tc_real_inv);
#endif

#if 0
    float   vtemp=0.;
    float   xde=0., xqe=0., xds=0., xqs=0.;

    Vfds_ref=Vds_ref;
    Vfqs_ref=Vqs_ref;

//  if(Vdc_flt > Vdc_ref_set)   { Vmax=(1-2.*T_dead*INV_Tsamp)*Vdc_ref_inv_set*INV_SQRT3;   }
//  else                        { Vmax=(1-2.*T_dead*INV_Tsamp)*Vdc_flt*0.5;     }
//  if(Vdc_flt > Vdc_ref_set)   { Vmax=(1-4.*T_dead*INV_Tsamp)*Vdc_ref_inv_set*INV_SQRT3;   }
//  else                        { Vmax=(1-4.*T_dead*INV_Tsamp)*Vdc_flt*INV_SQRT3;       }

    if(Vdc_flt > Vdc_ref_inv)   { Vmax=(1-4.*T_dead*INV_Tsamp)*Vdc_ref_inv*INV_SQRT3;   }
    else                        { Vmax=(1-4.*T_dead*INV_Tsamp)*Vdc_flt*INV_SQRT3;       }

//  Vmax=(1-2.*T_dead*INV_Tsamp)*Vdc_flt*0.5;
    Vmax2=Vmax*Vmax;
    Vf_mag2=Vfds_ref*Vfds_ref+Vfqs_ref*Vfqs_ref;

    if(Vf_mag2 > Vmax2) {               // over-modulation region
        Flag_over_modu=1;
        Vf_mag=sqrt(Vf_mag2);
        vtemp=(Vmax)/(Vf_mag+1.e-30);

        Vds_ref=vtemp*Vfds_ref;
        Vqs_ref=vtemp*Vfqs_ref;
        xde = Cos_theta*Vds_ref + Sin_theta*Vqs_ref;
        xqe =-Sin_theta*Vds_ref + Cos_theta*Vqs_ref;

        Vde_ref=pVfe1[DX][CACT] = xde*Cos_thetaT + xqe*Sin_thetaT;
        Vqe_ref=pVfe1[QX][CACT] =-xde*Sin_thetaT + xqe*Cos_thetaT;
    }
    else {
        Flag_over_modu=0;
        pVfe1[DX][CACT]=pVfe1[DX][CREF];
        pVfe1[QX][CACT]=pVfe1[QX][CREF];
    }

    Va_ref  =      Vds_ref;
    Vb_ref  =    -(Vds_ref - SQRT3*Vqs_ref)/2.;
    Vc_ref  =    -(Va_ref + Vb_ref);

/* 7.5kHz at div2, div2*/
/*
    Ta_real_inv = (int)((Va_ref*INV_Vdc+0.5)*2500);
    Tb_real_inv = (int)((Vb_ref*INV_Vdc+0.5)*2500);
    Tc_real_inv = (int)((Vc_ref*INV_Vdc+0.5)*2500);

    Ta_inv = ((Ta_real_inv > 2400) ? 2400:(Ta_real_inv<100) ? 100:Ta_real_inv);
    Tb_inv = ((Tb_real_inv > 2400) ? 2400:(Tb_real_inv<100) ? 100:Tb_real_inv);
    Tc_inv = ((Tc_real_inv > 2400) ? 2400:(Tc_real_inv<100) ? 100:Tc_real_inv);
*/

/* 5kHz at div2, div2*/
    Ta_real_inv = (int)((Va_ref*INV_Vdc+0.5)*3750);
    Tb_real_inv = (int)((Vb_ref*INV_Vdc+0.5)*3750);
    Tc_real_inv = (int)((Vc_ref*INV_Vdc+0.5)*3750);

    Ta_inv = ((Ta_real_inv > 3600) ? 3600:(Ta_real_inv<150) ? 150:Ta_real_inv);
    Tb_inv = ((Tb_real_inv > 3600) ? 3600:(Tb_real_inv<150) ? 150:Tb_real_inv);
    Tc_inv = ((Tc_real_inv > 3600) ? 3600:(Tc_real_inv<150) ? 150:Tc_real_inv);
#endif
}

void svpwm()
{
#if 0
    register float  a;
    register int    i;
    float   T0, b, c;

    float   dead_time=0;
#endif

#if 1

    float   T0;

    float   dead_time=0;
#endif

//  Tsamp_Inv_Vdc   = Tsamp * INV_Vdc;
    Tsamp_Inv_Vdc   = Tsamp * INV_Vdc * Tsamp_Inv_Vdc_gain;

    Tsamp_Inv_Vdc = fabs(Tsamp_Inv_Vdc);   // 2005.03.23 //

    Ta  = Va_ref    * Tsamp_Inv_Vdc;                                    // imaginary switching time
    Tb  = Vb_ref    * Tsamp_Inv_Vdc;

//  Tc  = Vc_ref    * Tsamp_Inv_Vdc;
    Tc  = -(Ta  + Tb);

    if( Ta>Tb ) { Vmax=Ta;  Vmin=Tb; }                          // 3-elements sorting : a(Tmax),b(Tmin)
    else        { Vmax=Tb;  Vmin=Ta; }

    if( Tc>Vmax )   Vmax=Tc;
    if( Tc<Vmin )   Vmin=Tc;

    dead_time=(T_dead > T_dead_comp) ? T_dead : T_dead_comp;    // select dead-time
    T0=Tsamp-(Vmax-Vmin);

    if( T0 < 2.*dead_time ){                                    // over-modulation
        Flag_over_modu=1;
        Vmax=(Tsamp-2.*dead_time)/(Vmax-Vmin+1.e-30);
        Ta*=Vmax; Tb*=Vmax; Tc*=Vmax; Vmin*=Vmax;   T0=2.*dead_time;
        Vds_ref*=Vmax;  Vqs_ref*=Vmax;  Vde_ref*=Vmax;  Vqe_ref*=Vmax;
        pVfe1[DX][CACT]=Vde_ref;    pVfe1[QX][CACT]=Vqe_ref;

    }
    else    {
        Flag_over_modu=0;
        pVfe1[DX][CACT]=pVfe1[DX][CREF];
        pVfe1[QX][CACT]=pVfe1[QX][CREF];
    }

    Vmax=T0*0.5-Vmin;                                                   // effective time calculation
    Ta+=Vmax;   Tb+=Vmax;   Tc+=Vmax;

#if 1
    //3.75kHz
    LIMIT_i((int)( Ta*Scale_gating*0.5+0.5 ), CNT_max_98, CNT_max_2, &Ta_inv);
    LIMIT_i((int)( Tb*Scale_gating*0.5+0.5 ), CNT_max_98, CNT_max_2, &Tb_inv);
    LIMIT_i((int)( Tc*Scale_gating*0.5+0.5 ), CNT_max_98, CNT_max_2, &Tc_inv);
#endif
}
//======================================================================================


void LIMIT_i(int variable, int positive, int negative, int *limit)
{
    *limit = (variable > positive)? positive : (variable < negative)? negative : variable;
}
