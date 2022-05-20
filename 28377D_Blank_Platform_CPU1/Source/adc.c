//###############################################################################################################
// 파일명      : adc.c
// 회사명      : G-Philos
// 작성날짜  : 2020.12.17
// 작성자      : KYJ-PC
// 수정날짜  : 2021.01.04
// 수정자      : Lee Sang Cheol
// 설명         : F28377D의 내부 ADC 주변장치 관련 구현 코드
//###############################################################################################################

#pragma CODE_SECTION(Get_Adc,               ".TI.ramfunc");
#pragma CODE_SECTION(Get_Adc_Sensor,        ".TI.ramfunc");
#pragma CODE_SECTION(Get_Adc_Filter,        ".TI.ramfunc");

#include "Define.h"


float adc_data[18] = {0,};

//Uint16  adc_data[18] = {0,};
//int32  adc_data[18] = {0,};

void Init_Adc(char module_a_status, char module_b_status, char module_c_status, char module_d_status)
{

    EALLOW;
    PieVectTable.ADCB1_INT = &adcb1_isr;
    EDIS;

    PieCtrlRegs.PIEIER1.bit.INTx2 = 1;
    IER |= M_INT1;
    EINT;
    ERTM;

    EALLOW;
    //
    //write configurations
    //
    /*
     * Input ADC CLK = 200MHz
     *
     * PRECALE
    0000 ADCCLK = Input ADC Clock / 1.0
    0001 Invalid
    0010 ADCCLK = Input ADC Clock / 2.0
    0011 ADCCLK = Input ADC Clock / 2.5
    0100 ADCCLK = Input ADC Clock / 3.0
    0101 ADCCLK = Input ADC Clock / 3.5
    0110 ADCCLK = Input ADC Clock / 4.0
    0111 ADCCLK = Input ADC Clock / 4.5
    1000 ADCCLK = Input ADC Clock / 5.0
    1001 ADCCLK = Input ADC Clock / 5.5
    1010 ADCCLK = Input ADC Clock / 6.0
    1011 ADCCLK = Input ADC Clock / 6.5
    1100 ADCCLK = Input ADC Clock / 7.0
    1101 ADCCLK = Input ADC Clock / 7.5
    1110 ADCCLK = Input ADC Clock / 8.0
    1111 ADCCLK = Input ADC Clock / 8.5
    */
    AdcaRegs.ADCCTL2.bit.PRESCALE = 6; //set ADCCLK 200MHz /4 = 50MHz
    AdcbRegs.ADCCTL2.bit.PRESCALE = 6; //set ADCCLK 200MHz /4 = 50MHz
    AdccRegs.ADCCTL2.bit.PRESCALE = 6; //set ADCCLK 200MHz /4 = 50MHz
    AdcdRegs.ADCCTL2.bit.PRESCALE = 6; //set ADCCLK 200MHz /4 = 50MHz

    switch (module_a_status)
    {
        case 0:
            AdcSetMode(ADC_ADCA, ADC_RESOLUTION_12BIT, ADC_SIGNALMODE_SINGLE);



            AdcaRegs.ADCSOC0CTL.bit.CHSEL = DRV2_ADC_ADCIN_2;      // SOC0: ADCINA2
            AdcaRegs.ADCSOC0CTL.bit.ACQPS = DRV2_ADC_ACQPS_12BIT;     // sample window is 14 SYSCLK cycles
            AdcaRegs.ADCSOC0CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA

            AdcaRegs.ADCSOC1CTL.bit.CHSEL = DRV2_ADC_ADCIN_3;      // SOC1: ADCINA3
            AdcaRegs.ADCSOC1CTL.bit.ACQPS = DRV2_ADC_ACQPS_12BIT;     // sample window is 14 SYSCLK cycles
            AdcaRegs.ADCSOC1CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA

            AdcaRegs.ADCSOC2CTL.bit.CHSEL = DRV2_ADC_ADCIN_4;      // SOC0: ADCINA4
            AdcaRegs.ADCSOC2CTL.bit.ACQPS = DRV2_ADC_ACQPS_12BIT;     // sample window is 14 SYSCLK cycles
            AdcaRegs.ADCSOC2CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA

            AdcaRegs.ADCSOC3CTL.bit.CHSEL = DRV2_ADC_ADCIN_5;      // SOC1: ADCINA5
            AdcaRegs.ADCSOC3CTL.bit.ACQPS = DRV2_ADC_ACQPS_12BIT;     // sample window is 14 SYSCLK cycles
            AdcaRegs.ADCSOC3CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA


            break;
        case 1:
            AdcSetMode(ADC_ADCA, ADC_RESOLUTION_16BIT, ADC_SIGNALMODE_DIFFERENTIAL);



            AdcaRegs.ADCSOC0CTL.bit.CHSEL = DRV2_ADC_ADCIN_2_3;      // SOC0: ADCINA2+ADCINA3
            AdcaRegs.ADCSOC0CTL.bit.ACQPS = DRV2_ADC_ACQPS_16BIT;     // sample window is 63 SYSCLK cycles
            AdcaRegs.ADCSOC0CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA

            AdcaRegs.ADCSOC1CTL.bit.CHSEL = DRV2_ADC_ADCIN_4_5;      // SOC1: ADCINA4+ADCINA5
            AdcaRegs.ADCSOC1CTL.bit.ACQPS = DRV2_ADC_ACQPS_16BIT;     // sample window is 63 SYSCLK cycles
            AdcaRegs.ADCSOC1CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA

            break;
        default :
            break;

    }

    switch (module_b_status)
    {
        case 0:
            AdcSetMode(ADC_ADCB, ADC_RESOLUTION_12BIT, ADC_SIGNALMODE_SINGLE);


            AdcbRegs.ADCSOC0CTL.bit.CHSEL = DRV2_ADC_ADCIN_2;           // SOC6: ADCINB2
            AdcbRegs.ADCSOC0CTL.bit.ACQPS = DRV2_ADC_ACQPS_12BIT;        // sample window is 14 SYSCLK cycles
            AdcbRegs.ADCSOC0CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA;    // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA
            AdcbRegs.ADCINTSEL1N2.bit.INT1SEL = DRV2_ADC_CALL_INT_EOC0;  // end of SOC4 will set INT1 flag
            AdcbRegs.ADCINTSEL1N2.bit.INT1E = DRV2_ADC_INTEN;            // enable INT1 flag
            AdcbRegs.ADCINTFLGCLR.bit.ADCINT1 = DRV2_ADC_CLEAR_INTFLG_Y; // make sure INT1 flag is cleared

            AdcbRegs.ADCSOC1CTL.bit.CHSEL = DRV2_ADC_ADCIN_3;        // SOC7: ADCINB3
            AdcbRegs.ADCSOC1CTL.bit.ACQPS = DRV2_ADC_ACQPS_12BIT;     // sample window is 14 SYSCLK cycles
            AdcbRegs.ADCSOC1CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA

            AdcbRegs.ADCSOC2CTL.bit.CHSEL = DRV2_ADC_ADCIN_4;        // SOC8: ADCINB4
            AdcbRegs.ADCSOC2CTL.bit.ACQPS = DRV2_ADC_ACQPS_12BIT;     // sample window is 14 SYSCLK cycles
            AdcbRegs.ADCSOC2CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA

            AdcbRegs.ADCSOC3CTL.bit.CHSEL = DRV2_ADC_ADCIN_5;        // SOC9: ADCINB5
            AdcbRegs.ADCSOC3CTL.bit.ACQPS = DRV2_ADC_ACQPS_12BIT;     // sample window is 14 SYSCLK cycles
            AdcbRegs.ADCSOC3CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA

            AdcbRegs.ADCSOC4CTL.bit.CHSEL = DRV2_ADC_ADCIN_14;       // SOC10: ADCINB_14(CAL)
            AdcbRegs.ADCSOC4CTL.bit.ACQPS = DRV2_ADC_ACQPS_12BIT;     // sample window is 14 SYSCLK cycles
            AdcbRegs.ADCSOC4CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA

            AdcbRegs.ADCSOC5CTL.bit.CHSEL = DRV2_ADC_ADCIN_15;       // SOC11: ADCINB_15(CAL)
            AdcbRegs.ADCSOC5CTL.bit.ACQPS = DRV2_ADC_ACQPS_12BIT;     // sample window is 14 SYSCLK cycles
            AdcbRegs.ADCSOC5CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA



            break;
        case 1:
            AdcSetMode(ADC_ADCB, ADC_RESOLUTION_16BIT, ADC_SIGNALMODE_DIFFERENTIAL);


            AdcbRegs.ADCSOC0CTL.bit.CHSEL = DRV2_ADC_ADCIN_2_3;           // SOC6: ADCINB2
            AdcbRegs.ADCSOC0CTL.bit.ACQPS = DRV2_ADC_ACQPS_16BIT;        // sample window is 14 SYSCLK cycles
            AdcbRegs.ADCSOC0CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA;    // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA
            AdcbRegs.ADCINTSEL1N2.bit.INT1SEL = DRV2_ADC_CALL_INT_EOC0;  // end of SOC4 will set INT1 flag
            AdcbRegs.ADCINTSEL1N2.bit.INT1E = DRV2_ADC_INTEN;            // enable INT1 flag
            AdcbRegs.ADCINTFLGCLR.bit.ADCINT1 = DRV2_ADC_CLEAR_INTFLG_Y; // make sure INT1 flag is cleared

            AdcbRegs.ADCSOC1CTL.bit.CHSEL = DRV2_ADC_ADCIN_4_5;        // SOC7: ADCINB3
            AdcbRegs.ADCSOC1CTL.bit.ACQPS = DRV2_ADC_ACQPS_16BIT;     // sample window is 14 SYSCLK cycles
            AdcbRegs.ADCSOC1CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA

            AdcbRegs.ADCSOC2CTL.bit.CHSEL = DRV2_ADC_ADCIN_14_15;        // SOC8: ADCINB4
            AdcbRegs.ADCSOC2CTL.bit.ACQPS = DRV2_ADC_ACQPS_16BIT;     // sample window is 14 SYSCLK cycles
            AdcbRegs.ADCSOC2CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA


            break;
        default :

            break;
    }

    switch (module_c_status)
    {
        case 0:
            AdcSetMode(ADC_ADCC, ADC_RESOLUTION_12BIT, ADC_SIGNALMODE_SINGLE);

            AdccRegs.ADCSOC0CTL.bit.CHSEL = DRV2_ADC_ADCIN_2;        // SOC2: ADCINC2
            AdccRegs.ADCSOC0CTL.bit.ACQPS = DRV2_ADC_ACQPS_12BIT;     // sample window is 63 SYSCLK cycles
            AdccRegs.ADCSOC0CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA

            AdccRegs.ADCSOC1CTL.bit.CHSEL = DRV2_ADC_ADCIN_3;        // SOC3: ADCINC3
            AdccRegs.ADCSOC1CTL.bit.ACQPS = DRV2_ADC_ACQPS_12BIT;     // sample window is 63 SYSCLK cycles
            AdccRegs.ADCSOC1CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA

            AdccRegs.ADCSOC2CTL.bit.CHSEL = DRV2_ADC_ADCIN_4;        // SOC4: ADCINC4
            AdccRegs.ADCSOC2CTL.bit.ACQPS = DRV2_ADC_ACQPS_12BIT;     // sample window is 63 SYSCLK cycles
            AdccRegs.ADCSOC2CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA

            AdccRegs.ADCSOC3CTL.bit.CHSEL = DRV2_ADC_ADCIN_5;        // SOC5: ADCINC5
            AdccRegs.ADCSOC3CTL.bit.ACQPS = DRV2_ADC_ACQPS_12BIT;     // sample window is 63 SYSCLK cycles
            AdccRegs.ADCSOC3CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA

            break;
        case 1:
            AdcSetMode(ADC_ADCC, ADC_RESOLUTION_16BIT, ADC_SIGNALMODE_DIFFERENTIAL);


            AdccRegs.ADCSOC0CTL.bit.CHSEL = DRV2_ADC_ADCIN_2_3;        // SOC2: ADCINC2
            AdccRegs.ADCSOC0CTL.bit.ACQPS = DRV2_ADC_ACQPS_16BIT;     // sample window is 63 SYSCLK cycles
            AdccRegs.ADCSOC0CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA

            AdccRegs.ADCSOC1CTL.bit.CHSEL = DRV2_ADC_ADCIN_4_5;        // SOC3: ADCINC3
            AdccRegs.ADCSOC1CTL.bit.ACQPS = DRV2_ADC_ACQPS_16BIT;     // sample window is 63 SYSCLK cycles
            AdccRegs.ADCSOC1CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA


            break;
        default :

            break;
    }

    switch (module_d_status)
    {
        case 0:
            AdcSetMode(ADC_ADCD, ADC_RESOLUTION_12BIT, ADC_SIGNALMODE_SINGLE);


            AdcdRegs.ADCSOC0CTL.bit.CHSEL = DRV2_ADC_ADCIN_0;        // SOC12: ADCIND0
            AdcdRegs.ADCSOC0CTL.bit.ACQPS = DRV2_ADC_ACQPS_12BIT;     // sample window is 14 SYSCLK cycles
            AdcdRegs.ADCSOC0CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA

            AdcdRegs.ADCSOC1CTL.bit.CHSEL = DRV2_ADC_ADCIN_1;        // SOC13: ADCIND1
            AdcdRegs.ADCSOC1CTL.bit.ACQPS = DRV2_ADC_ACQPS_12BIT;     // sample window is 14 SYSCLK cycles
            AdcdRegs.ADCSOC1CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA

            AdcdRegs.ADCSOC2CTL.bit.CHSEL = DRV2_ADC_ADCIN_2;        // SOC14: ADCIND2
            AdcdRegs.ADCSOC2CTL.bit.ACQPS = DRV2_ADC_ACQPS_12BIT;     // sample window is 14 SYSCLK cycles
            AdcdRegs.ADCSOC2CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA

            AdcdRegs.ADCSOC3CTL.bit.CHSEL = DRV2_ADC_ADCIN_3;        // SOC15: ADCIND3
            AdcdRegs.ADCSOC3CTL.bit.ACQPS = DRV2_ADC_ACQPS_12BIT;     // sample window is 14 SYSCLK cycles
            AdcdRegs.ADCSOC3CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA

            AdcdRegs.ADCSOC4CTL.bit.CHSEL = DRV2_ADC_ADCIN_4;        // SOC1: ADCIND4
            AdcdRegs.ADCSOC4CTL.bit.ACQPS = DRV2_ADC_ACQPS_12BIT;     // sample window is 14 SYSCLK cycles
            AdcdRegs.ADCSOC4CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA

            AdcdRegs.ADCSOC5CTL.bit.CHSEL = DRV2_ADC_ADCIN_5;        // SOC2: ADCIND5
            AdcdRegs.ADCSOC5CTL.bit.ACQPS = DRV2_ADC_ACQPS_12BIT;     // sample window is 14 SYSCLK cycles
            AdcdRegs.ADCSOC5CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA



            break;
        case 1:
            AdcSetMode(ADC_ADCD, ADC_RESOLUTION_16BIT, ADC_SIGNALMODE_DIFFERENTIAL);


            AdcdRegs.ADCSOC0CTL.bit.CHSEL = DRV2_ADC_ADCIN_0_1;        // SOC12: ADCIND0
            AdcdRegs.ADCSOC0CTL.bit.ACQPS = DRV2_ADC_ACQPS_16BIT;     // sample window is 14 SYSCLK cycles
            AdcdRegs.ADCSOC0CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA

            AdcdRegs.ADCSOC1CTL.bit.CHSEL = DRV2_ADC_ADCIN_2_3;        // SOC14: ADCIND2
            AdcdRegs.ADCSOC1CTL.bit.ACQPS = DRV2_ADC_ACQPS_16BIT;     // sample window is 14 SYSCLK cycles
            AdcdRegs.ADCSOC1CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA

            AdcdRegs.ADCSOC2CTL.bit.CHSEL = DRV2_ADC_ADCIN_4_5;        // SOC1: ADCIND4
            AdcdRegs.ADCSOC2CTL.bit.ACQPS = DRV2_ADC_ACQPS_16BIT;     // sample window is 14 SYSCLK cycles
            AdcdRegs.ADCSOC2CTL.bit.TRIGSEL = DRV2_ADC_EPWM_ADCSOCA; // trigger on 05h ADCTRIG5 - ePWM1, ADCSOCA


            break;
        default :

            break;
    }

    //
    //Set pulse positions to late
    //
    AdcbRegs.ADCCTL1.bit.INTPULSEPOS = 1;
    AdccRegs.ADCCTL1.bit.INTPULSEPOS = 1;
    AdcdRegs.ADCCTL1.bit.INTPULSEPOS = 1;

    //
    //power up the ADC
    //
    AdcaRegs.ADCCTL1.bit.ADCPWDNZ = 1;
    AdcbRegs.ADCCTL1.bit.ADCPWDNZ = 1;
    AdccRegs.ADCCTL1.bit.ADCPWDNZ = 1;
    AdcdRegs.ADCCTL1.bit.ADCPWDNZ = 1;

    //
    //delay for 1ms to allow ADC time to power up
    //
    DELAY_US(1000);

    EDIS;
}



int ft = 0;
//BB_Send_Flag(ft, !GpioDataRegs.GPADAT.bit.GPIO1);
// CPU1 : ft -> SDcard 확인용 변수 : 0 -> 1
// CPU2 : fresult -> check ? FR_OK

//ft = 0 (DA 동작 가능), ft = 1 (DA 동작 안됨)
float  _on_off = 0, _ofs1 = 0, _ofs2 = 0, _ofs3 = 0, _ofs4 = 0,
       _max1 = 10, _max2 = 10, _max3 = 10, _max4 = 10;
float *dac_data_addr1 = 0;
float *dac_data_addr2 = 0;
float *dac_data_addr3 = 0;
float *dac_data_addr4 = 0;

float f_gen = 60.0;
float i_gen = 0.2; /* 0.2A */
void Get_Adc_From_Generator()
{
    float f = 0.0;
    float dt = Tsamp;
    float Iac = 1.0;

    /* change frequency */
    if( f_gen < 40.0 )
    {
        f_gen = 40.0;
    }

    if( f_gen > 70.0 )
    {
        f_gen = 70.0;
    }

    if( f_gen < f_gen_target )
    {
        if( f_gen <= (f_gen_target - 0.0001) )
        {
            f_gen += 0.0001;
        }

        f = f_gen;
    }
    else if( f_gen > f_gen_target )
    {
        if( f_gen >= (f_gen_target + 0.0001) )
        {
            f_gen -= 0.0001;
        }

        f = f_gen;
    }
    else
    {
        f = f_gen;
    }

    /* change current (power operating) */
    if( i_gen_target < 0.2 )
    {
        i_gen_target = 0.2;
    }

    if( i_gen_target > Iac_max_gen )
    {
        i_gen_target = Iac_max_gen;
    }

    if( i_gen < i_gen_target )
    {
        if( i_gen <= (i_gen_target - 0.001) )
        {
            i_gen += 0.001;
        }
    }
    else if( i_gen > i_gen_target )
    {
        if( i_gen >= (i_gen_target - 0.001) )
        {
            i_gen -= 0.001;
        }
    }
    else
    {
        /* no work */
    }

    Vin      =  Vin_max_gen;
    Idc      =  i_gen;
    A_ref    =  A_ref_target;
    Vdc      =  Vdc_max_gen;

    /* power conversion (95%) */
    if(1)
    {
        float p = Vdc * Idc;
        Iac = Peff_gen * p * SQRT2 / Vac_max_gen;
    }

    /* generate the signals that are scaled with ADC values. */
    Esa_gen =  Vac_max_gen * sin(PI_MPY_2 * f * t_gen + 120.0 * PI_MPY_2 / 360.0);
    Esb_gen =  Vac_max_gen * sin(PI_MPY_2 * f * t_gen +   0.0 * PI_MPY_2 / 360.0);
    Esc_gen =  Vac_max_gen * sin(PI_MPY_2 * f * t_gen - 120.0 * PI_MPY_2 / 360.0);

    Ia_gen  =  Iac * sin(PI_MPY_2 * f * t_gen + (180.0 + 120.0) * PI_MPY_2 / 360.0);
    Ib_gen  =  Iac * sin(PI_MPY_2 * f * t_gen + (180.0 +   0.0) * PI_MPY_2 / 360.0);
    Ic_gen  =  Iac * sin(PI_MPY_2 * f * t_gen + (180.0 - 120.0) * PI_MPY_2 / 360.0);

    t_gen += dt;
    if( t_gen >= PI )
    {
        t_gen -= PI_MPY_2;
    }

    Esa = Esa_gen;
    Esb = Esb_gen;
    Esc = Esc_gen;

    Ia = Ia_gen;
    Ib = Ib_gen;
    Ic = Ic_gen;
}


interrupt void adcb1_isr(void)
{
    if(time_check_cnt == 0)   LED1_ON;

    if(Flag_offset == 3)
    {
        rout_cntl();
    }  // Tsamp - pwm_ctrl.c
    else
    {
        rout_offset();
    }  // Tsamp - offset.c

#ifdef _BLACKBOX

//    ft = System_fault;
    BB_Send_Flag(!GpioDataRegs.GPADAT.bit.GPIO1, 0);

    BB_Send_ctrl_data_check();

#if 1
    Send_Dac_Data(1, *dac_data_addr1, (char)_on_off, (int)_ofs1, (int)_max1);
    Send_Dac_Data(2, *dac_data_addr2, (char)_on_off, (int)_ofs2, (int)_max2);
    Send_Dac_Data(3, *dac_data_addr3, (char)_on_off, (int)_ofs3, (int)_max3);
    Send_Dac_Data(4, *dac_data_addr4, (char)_on_off, (int)_ofs4, (int)_max4);
#endif

    BB_Send_ctrl_data();
    BB_Send_dac_data();

    /*--------------------------------------*/
    /*  download check                      */
    /*--------------------------------------*/
    Bl_Shutdown();
#endif

    if(time_check_cnt == 0)   LED1_OFF;

    //time check = 26.1us = 66.6us x 39.2%
    AdcbRegs.ADCINTFLGCLR.bit.ADCINT1 = 1; //clear INT1 flag
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

void Get_Adc()
{
    // ADC1 ~ ADC6 <= ADC-B : 6EA(B: 4EA / CAL: 2EA)
    adc_data[0] =  AdcbResultRegs.ADCRESULT0;
    adc_data[1] =  AdcbResultRegs.ADCRESULT1;
    adc_data[2] =  AdcbResultRegs.ADCRESULT2;
    adc_data[3] =  AdcbResultRegs.ADCRESULT3;
    adc_data[4] =  AdcbResultRegs.ADCRESULT4;
    adc_data[5] =  AdcbResultRegs.ADCRESULT5;

    // ADC7 ~ ADC12 <= ADC-D : 6EA(D: 6EA)
    adc_data[6] =  AdcdResultRegs.ADCRESULT0;
    adc_data[7] =  AdcdResultRegs.ADCRESULT1;
    adc_data[8] =  AdcdResultRegs.ADCRESULT2;
    adc_data[9] =  AdcdResultRegs.ADCRESULT3;
    adc_data[10] = AdcdResultRegs.ADCRESULT4;
    adc_data[11] = AdcdResultRegs.ADCRESULT5;

    // ADC13 ~ ADC16 <= ADC-C : 4EA(C: 4EA)
    adc_data[12] = AdccResultRegs.ADCRESULT0;
    adc_data[13] = AdccResultRegs.ADCRESULT1;
    adc_data[14] = AdccResultRegs.ADCRESULT2;
    adc_data[15] = AdccResultRegs.ADCRESULT3;

    // ADC17 ~ ADC18 <= ADC-A(16bit) : 6EA(B: 4EA / CAL: 2EA)
    adc_data[16] = AdcaResultRegs.ADCRESULT0;
    adc_data[17] = AdcaResultRegs.ADCRESULT1;
}


void Get_Adc_Sensor_AC()
{
    Vin      =  (float)(adc_data[0]     - INV_12bit_AD1_OFFSET      - Vin_offset)   * Scale_Vin;
    Idc      =  (float)(adc_data[1]     - INV_12bit_AD2_OFFSET      - Idc_offset)   * Scale_Idc;
    A_ref    =  (float)(adc_data[2]     - INV_12bit_AD3_OFFSET      - A_ref_offset) * Scale_A_ref;
    Vdc      =  (float)(adc_data[3]     - INV_12bit_AD4_OFFSET      - Vdc_offset)   * Scale_Vdc;

    Esa      =  (float)(adc_data[4]     - INV_12bit_AD5_OFFSET)     * Scale_Esa;    //offset 계산
    Esb      =  (float)(adc_data[5]     - INV_12bit_AD6_OFFSET)     * Scale_Esb;    //offset 계산
    Esc      =  (float)(adc_data[6]     - INV_12bit_AD7_OFFSET)     * Scale_Esc;    //offset 계산
    Ia       =  (float)(adc_data[7]     - INV_12bit_AD8_OFFSET)     * Scale_Ia;     //offset 계산
    Ib       =  (float)(adc_data[8]     - INV_12bit_AD9_OFFSET)     * Scale_Ib;     //offset 계산
    Ic       =  (float)(adc_data[9]     - INV_12bit_AD10_OFFSET)    * Scale_Ic;     //offset 계산

    Get_Adc_From_Generator();
}


void Get_Adc_Sensor()
{
    Vin      =  (float)(adc_data[0]     - INV_12bit_AD1_OFFSET      - Vin_offset)   * Scale_Vin;
    Idc      =  (float)(adc_data[1]     - INV_12bit_AD2_OFFSET      - Idc_offset)   * Scale_Idc;
    A_ref    =  (float)(adc_data[2]     - INV_12bit_AD3_OFFSET      - A_ref_offset) * Scale_A_ref;
    Vdc      =  (float)(adc_data[3]     - INV_12bit_AD4_OFFSET      - Vdc_offset)   * Scale_Vdc;

    Esa      =  (float)(adc_data[4]     - INV_12bit_AD5_OFFSET)     * Scale_Esa   - Esa_offset;
    Esb      =  (float)(adc_data[5]     - INV_12bit_AD6_OFFSET)     * Scale_Esb   - Esb_offset;
    Esc      =  (float)(adc_data[6]     - INV_12bit_AD7_OFFSET)     * Scale_Esc   - Esc_offset;
    Ia       =  (float)(adc_data[7]     - INV_12bit_AD8_OFFSET)     * Scale_Ia    - Ia_offset   - Ia_offset_comp;
    Ib       =  (float)(adc_data[8]     - INV_12bit_AD9_OFFSET)     * Scale_Ib    - Ib_offset   - Ib_offset_comp;
    Ic       =  (float)(adc_data[9]     - INV_12bit_AD10_OFFSET)    * Scale_Ic    - Ic_offset   - Ic_offset_comp;

/************** To reduce control time ****************/
#if 0
    Eab     = Esa   - Esb;
    Ebc     = Esb   - Esc;
    Eca     = Esc   - Esa;
#endif
/************** To reduce control time ****************/

    Get_Adc_From_Generator();
}



void Get_Adc_Filter_AC()
{
    Esa_flt     = La_Va    * Esa_flt    + Lb_Va     * (Esa      + Esa_old);     Esa_old     = Esa;
    Esb_flt     = La_Va    * Esb_flt    + Lb_Va     * (Esb      + Esb_old);     Esb_old     = Esb;
    Esc_flt     = La_Va    * Esc_flt    + Lb_Va     * (Esc      + Esc_old);     Esc_old     = Esc;

#if 0
    Eab_flt     = La_Va    * Eab_flt    + Lb_Va     * (Eab      + Eab_old);     Eab_old     = Eab;
    Ebc_flt     = La_Va    * Ebc_flt    + Lb_Va     * (Ebc      + Ebc_old);     Ebc_old     = Ebc;
    Eca_flt     = La_Va    * Eca_flt    + Lb_Va     * (Eca      + Eca_old);     Eca_old     = Eca;
#endif

    Ia_flt      = La_Ia    * Ia_flt     + Lb_Ia     * (Ia       + Ia_old);      Ia_old      = Ia;
    Ib_flt      = La_Ia    * Ib_flt     + Lb_Ia     * (Ib       + Ib_old);      Ib_old      = Ib;
    Ic_flt      = La_Ia    * Ic_flt     + Lb_Ia     * (Ic       + Ic_old);      Ic_old      = Ic;
}


void Get_Adc_Filter()
{
    Vin_flt     = La_Vin   * Vin_flt    + Lb_Vin    * (Vin      + Vin_old);     Vin_old     = Vin;
    Idc_flt     = La_Idc   * Idc_flt    + Lb_Idc    * (Idc      + Idc_old);     Idc_old     = Idc;
    A_ref_flt   = La_A_ref * A_ref_flt  + Lb_A_ref  * (A_ref    + A_ref_old);   A_ref_old   = A_ref;
    Vdc_flt     = La_Vdc   * Vdc_flt    + Lb_Vdc    * (Vdc      + Vdc_old);     Vdc_old     = Vdc;


#if 1
    Esa_flt     = La_Va    * Esa_flt    + Lb_Va     * (Esa      + Esa_old);     Esa_old     = Esa;
    Esb_flt     = La_Va    * Esb_flt    + Lb_Va     * (Esb      + Esb_old);     Esb_old     = Esb;
    Esc_flt     = La_Va    * Esc_flt    + Lb_Va     * (Esc      + Esc_old);     Esc_old     = Esc;
#endif

/************** To reduce control time ****************/
#if 0
    Eab_flt     = La_Va    * Eab_flt    + Lb_Va     * (Eab      + Eab_old);     Eab_old     = Eab;
    Ebc_flt     = La_Va    * Ebc_flt    + Lb_Va     * (Ebc      + Ebc_old);     Ebc_old     = Ebc;
    Eca_flt     = La_Va    * Eca_flt    + Lb_Va     * (Eca      + Eca_old);     Eca_old     = Eca;
#endif
/************** To reduce control time ****************/

#if 1
    Ia_flt      = La_Ia    * Ia_flt     + Lb_Ia     * (Ia      + Ia_old);     Ia_old     = Ia;
    Ib_flt      = La_Ia    * Ib_flt     + Lb_Ia     * (Ib      + Ib_old);     Ib_old     = Ib;
    Ic_flt      = La_Ia    * Ic_flt     + Lb_Ia     * (Ic      + Ic_old);     Ic_old     = Ic;
#endif

    INV_Vin = 1. / (Vin_flt + 1.e-30);
    INV_Vdc = 1. / (Vdc_flt + 1.e-30);

    Ia_abs  = fabs(Ia);
    Ib_abs  = fabs(Ib);
    Ic_abs  = fabs(Ic);

    Vin_flt_sum         +=  Vin_flt;
    Idc_flt_sum         +=  Idc_flt;
    A_ref_flt_sum       +=  A_ref_flt;
    Vdc_flt_sum         +=  Vdc_flt;

    Esa_rms_sum         +=  Esa * Esa;
    Esb_rms_sum         +=  Esb * Esb;
    Esc_rms_sum         +=  Esc * Esc;

/************** To reduce control time ****************/
#if 0
    Eab_rms_sum         += Eab  * Eab;
    Ebc_rms_sum         += Ebc  * Ebc;
    Eca_rms_sum         += Eca  * Eca;
#endif
/************** To reduce control time ****************/

    Ia_rms_sum          +=  Ia  * Ia;
    Ib_rms_sum          +=  Ib  * Ib;
    Ic_rms_sum          +=  Ic  * Ic;

    Cnt_rms++;
}

void Power_cal()
{
    Pinv_DQ     = 0.0015 * (Vde_flt * Ide + Vqe_flt * Iqe );
    Pinv_DQ_sum += Pinv_DQ;
    Cnt_OL++;

/************** To reduce control time ****************/
#if 0
    PF_util = Iqe   / sqrt(Ide  * Ide + Iqe * Iqe);
#endif
/************** To reduce control time ****************/
}


void Init_scale_offset()
{

    if(Init_offset==1)
    {
        Kp_Vdc_con_ratio            = 100;      /* 421  */
        Ki_Vdc_con_ratio            = 100;      /* 422  */
        Kp_Idc_con_ratio            = 100;      /* 421  */
        Ki_Idc_con_ratio            = 100;      /* 422  */
        Kp_Vdc_ratio                = 100;      /* 423  */
        Ki_Vdc_inv_ratio            = 100;      /* 424  */
        Kp_Ia_ratio                 = 100;      /* 425  */
        Ki_Ia_ratio                 = 100;      /* 426  */

//      OP_MODE                     = 1;        /* 431  */
        OP_MODE                     = 3;        /* 431  */
        Flag_Act_islanding_input    = 77;       /* 441  */
        Flag_scia_cpu1_cpu2         = 1;        /* 451  */ //Baud rate

        Init_offset                 = 0;
    }

    if(Init_scale==1)
    {

        //401~500 할당
         Scale_Vin_ratio             = 100;       /* 401  */
         Scale_Idc_ratio             = 100;       /* 402  */
         Scale_A_ref_ratio           = 100;     /* 403  */
         Scale_Vdc_ratio             = 100;       /* 404  */
         Scale_Esa_ratio             = 100;       /* 405  */
         Scale_Esb_ratio             = 100;       /* 405  */
         Scale_Esc_ratio             = 100;       /* 406  */
         Scale_Ia_ratio              = 100;        /* 408  */
         Scale_Ib_ratio              = 100;        /* 409  */
         Scale_Ic_ratio              = 100;        /* 410  */

         Vin_offset_input            = 0;          /* 411  */
         Idc_offset_input            = 0;          /* 412  */
         A_ref_offset_input          = 0;        /* 413  */
         Vdc_offset_input            = 0;          /* 414  */
         Esa_offset_comp_input       = 0;     /* 415  */
         Esb_offset_comp_input       = 0;     /* 416  */
         Esc_offset_comp_input       = 0;     /* 417  */
         Ia_offset_comp_input        = 0;      /* 418  */
         Ib_offset_comp_input        = 0;      /* 419  */
         Ic_offset_comp_input        = 0;      /* 420  */

        Init_scale                   = 0;
    }


// lsc_step 1 EEPROM init
// 1. 빌드 및 예뮬레이터 연결 후 다운로딩
// 2. Init_offset = 1 후 0으로 변경되는 것을 확인.
// 3. 401 ~ 500 번지 EEPROM 데이터 값 확인
// 4. Enable_EEPROM_write = 1 후 0으로 변경되는 것을 확인.
#if 0
//Init_offset setting
//Init_offset -> Init_EEPROM
    if(Init_offset==1)
    {
        EEPROM_list_init();
        Init_offset=0;
    }
#endif
}


/*--------------------------------------*/
/*  call EEPROM_list_init()             */
/*--------------------------------------*/
void EEPROM_list_init()
{

/*--------------------------------------*/
/*  system EEPROM variables initialize  */
/*--------------------------------------*/
    //0~400 할당(float)
    // float 선언에 대한 EEPROM 저장 되는 것을 확인 하지 않았음.

    //401~500 할당(float)
    // float 선언에 대한 EEPROM 저장 되는 것을 일부분 확인 완료.

    //501~1000 할당(int)
    // int 선언에 대한 EEPROM 저장 되는 것을 확인 하지 않았음.
    // 단, 에러발생에 대한 저장은 확인함. 501~700 -> 10개목록 x 20개 데이터 저장 코드
    // 정확한 저장 방법에 대한 정의가 필요함.

    //401~500 할당
    Scale_Vin_ratio             = 100;      /* 401  */
    Scale_Idc_ratio             = 100;      /* 402  */
    Scale_A_ref_ratio           = 100;      /* 403  */
    Scale_Vdc_ratio             = 100;      /* 404  */
    Scale_Esa_ratio             = 100;      /* 405  */
    Scale_Esb_ratio             = 100;      /* 405  */
    Scale_Esc_ratio             = 100;      /* 406  */
    Scale_Ia_ratio              = 100;      /* 408  */
    Scale_Ib_ratio              = 100;      /* 409  */
    Scale_Ic_ratio              = 100;      /* 410  */

    Vin_offset_input            = 0;        /* 411  */
    Idc_offset_input            = 0;        /* 412  */
    A_ref_offset_input          = 0;        /* 413  */
    Vdc_offset_input            = 0;        /* 414  */
    Esa_offset_comp_input       = 0;        /* 415  */
    Esb_offset_comp_input       = 0;        /* 416  */
    Esc_offset_comp_input       = 0;        /* 417  */
    Ia_offset_comp_input        = 0;        /* 418  */
    Ib_offset_comp_input        = 0;        /* 419  */
    Ic_offset_comp_input        = 0;        /* 420  */

    Kp_Vdc_con_ratio            = 100;      /* 421  */
    Ki_Vdc_con_ratio            = 100;      /* 422  */
    Kp_Idc_con_ratio            = 100;      /* 421  */
    Ki_Idc_con_ratio            = 100;      /* 422  */
    Kp_Vdc_ratio                = 100;      /* 423  */
    Ki_Vdc_inv_ratio            = 100;      /* 424  */
    Kp_Ia_ratio                 = 100;      /* 425  */
    Ki_Ia_ratio                 = 100;      /* 426  */

    OP_MODE                     = 3;        /* 431  */
    Flag_Act_islanding_input    = 77;       /* 441  */

    Flag_scia_cpu1_cpu2         = 1;        /* 451  */ //CPU1 RS232 COM
}
