//###############################################################################################################
// 파일명      : eeprom.c
// 회사명      : G-Philos
// 작성날짜  : 2020.12.17
// 작성자      : KYJ-PC
// 수정날짜  : 2021.01.04
// 수정자      : Lee Sang Cheol
// 설명         : Serial EEPROM(AT24C16) 구동에 필요한 I2C 관련 함수 구현
//###############################################################################################################

#include "Define.h"


void Init_Epwm(void)
{

    // Stop all the TB clocks
    EALLOW;
    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 0;
    EDIS;

    // ePwm function init setting
    Init_ePwm1(); //PWM1초기화
    Init_ePwm2(); //PWM2초기화
    Init_ePwm3(); //PWM3초기화
    Init_ePwm4(); //PWM4초기화
    Init_ePwm5(); //PWM5초기화
    Init_ePwm6(); //PWM6초기화

    Init_ePwm7();  //PWM7초기화
    Init_ePwm8();  //PWM8초기화
    Init_ePwm9();  //PWM9초기화
    Init_ePwm10(); //PWM10초기화
    Init_ePwm11(); //PWM11초기화
    Init_ePwm12(); //PWM12초기화

    // Start all the timers synced
    EALLOW;
    //PWM
    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1;
    EPwm2Regs.TBCTL.bit.SWFSYNC      = 1;
    EPwm3Regs.TBCTL.bit.SWFSYNC      = 1;
    EPwm4Regs.TBCTL.bit.SWFSYNC      = 1;
    EPwm5Regs.TBCTL.bit.SWFSYNC      = 1;
    EPwm6Regs.TBCTL.bit.SWFSYNC      = 1;

    EPwm7Regs.TBCTL.bit.SWFSYNC      = 1;
    EPwm8Regs.TBCTL.bit.SWFSYNC      = 1;
    EPwm9Regs.TBCTL.bit.SWFSYNC      = 1;
    EPwm10Regs.TBCTL.bit.SWFSYNC     = 1;
    EPwm11Regs.TBCTL.bit.SWFSYNC     = 1;
    EPwm12Regs.TBCTL.bit.SWFSYNC     = 1;
    EDIS;

    EALLOW;
    //PWM
    GpioCtrlRegs.GPEMUX2.bit.GPIO145 = 1; //  1 for ePWM1A
    GpioCtrlRegs.GPEMUX2.bit.GPIO146 = 1; //  1 for ePWM1B
    GpioCtrlRegs.GPEMUX2.bit.GPIO147 = 1; //  1 for ePWM2A
    GpioCtrlRegs.GPEMUX2.bit.GPIO148 = 1; //  1 for ePWM2B
    GpioCtrlRegs.GPEMUX2.bit.GPIO149 = 1; //  1 for ePWM3A
    GpioCtrlRegs.GPEMUX2.bit.GPIO150 = 1; //  1 for ePWM3B
    GpioCtrlRegs.GPEMUX2.bit.GPIO151 = 1; //  1 for ePWM4A
    GpioCtrlRegs.GPEMUX2.bit.GPIO152 = 1; //  1 for ePWM4B
    GpioCtrlRegs.GPEMUX2.bit.GPIO153 = 1; //  1 for ePWM5A
    GpioCtrlRegs.GPEMUX2.bit.GPIO154 = 1; //  1 for ePWM5B
    GpioCtrlRegs.GPEMUX2.bit.GPIO155 = 1; //  1 for ePWM6A
    GpioCtrlRegs.GPEMUX2.bit.GPIO156 = 1; //  1 for ePWM6B

    GpioCtrlRegs.GPEMUX2.bit.GPIO157 = 1; //  1 for ePWM7A
    GpioCtrlRegs.GPEMUX2.bit.GPIO158 = 1; //  1 for ePWM7B
    GpioCtrlRegs.GPEMUX2.bit.GPIO159 = 1; //  1 for ePWM8A
    GpioCtrlRegs.GPFMUX1.bit.GPIO160 = 1; //  1 for ePWM8B
    GpioCtrlRegs.GPFMUX1.bit.GPIO161 = 1; //  1 for ePWM9A
    GpioCtrlRegs.GPFMUX1.bit.GPIO162 = 1; //  1 for ePWM9B
    GpioCtrlRegs.GPFMUX1.bit.GPIO163 = 1; //  1 for ePWM10A
    GpioCtrlRegs.GPFMUX1.bit.GPIO164 = 1; //  1 for ePWM10B
    GpioCtrlRegs.GPFMUX1.bit.GPIO165 = 1; //  1 for ePWM11A
    GpioCtrlRegs.GPFMUX1.bit.GPIO166 = 1; //  1 for ePWM11B
    GpioCtrlRegs.GPFMUX1.bit.GPIO167 = 1; //  1 for ePWM12A
    GpioCtrlRegs.GPFMUX1.bit.GPIO168 = 1; //  1 for ePWM12B
    EDIS;

    EALLOW;
    //ERR
    GpioCtrlRegs.GPCPUD.bit.GPIO94   = 0;   // Enable pullup on ERR1
    GpioCtrlRegs.GPCPUD.bit.GPIO95   = 0;   // Enable pullup on ERR2
    GpioCtrlRegs.GPDPUD.bit.GPIO96   = 0;   // Enable pullup on ERR3
    GpioCtrlRegs.GPDPUD.bit.GPIO97   = 0;   // Enable pullup on ERR4
    GpioCtrlRegs.GPDPUD.bit.GPIO98   = 0;   // Enable pullup on ERR5
    GpioCtrlRegs.GPDPUD.bit.GPIO99   = 0;   // Enable pullup on ERR6

    GpioCtrlRegs.GPDPUD.bit.GPIO112  = 0;   // Enable pullup on ERR7
    GpioCtrlRegs.GPDPUD.bit.GPIO113  = 0;   // Enable pullup on ERR8
    GpioCtrlRegs.GPDPUD.bit.GPIO114  = 0;   // Enable pullup on ERR9
    GpioCtrlRegs.GPDPUD.bit.GPIO115  = 0;   // Enable pullup on ERR10
    GpioCtrlRegs.GPDPUD.bit.GPIO116  = 0;   // Enable pullup on ERR11
    GpioCtrlRegs.GPDPUD.bit.GPIO117  = 0;   // Enable pullup on ERR12

    //TZ
    GpioCtrlRegs.GPAPUD.bit.GPIO20   = 0;   // Enable pullup on Final ERR1  ~ ERR3
    GpioCtrlRegs.GPAPUD.bit.GPIO21   = 0;   // Enable pullup on Final ERR4  ~ ERR6
    GpioCtrlRegs.GPAPUD.bit.GPIO22   = 0;   // Enable pullup on Final ERR7  ~ ERR9
    GpioCtrlRegs.GPAPUD.bit.GPIO23   = 0;   // Enable pullup on Final ERR10 ~ ERR12

    //ERR
    GpioCtrlRegs.GPCQSEL2.bit.GPIO94  = 3; // asynch input
    GpioCtrlRegs.GPCQSEL2.bit.GPIO95  = 3; // asynch input
    GpioCtrlRegs.GPDQSEL1.bit.GPIO96  = 3; // asynch input
    GpioCtrlRegs.GPDQSEL1.bit.GPIO97  = 3; // asynch input
    GpioCtrlRegs.GPDQSEL1.bit.GPIO98  = 3; // asynch input
    GpioCtrlRegs.GPDQSEL1.bit.GPIO99  = 3; // asynch input

    GpioCtrlRegs.GPDQSEL2.bit.GPIO112 = 3; // asynch input
    GpioCtrlRegs.GPDQSEL2.bit.GPIO113 = 3; // asynch input
    GpioCtrlRegs.GPDQSEL2.bit.GPIO114 = 3; // asynch input
    GpioCtrlRegs.GPDQSEL2.bit.GPIO115 = 3; // asynch input
    GpioCtrlRegs.GPDQSEL2.bit.GPIO116 = 3; // asynch input
    GpioCtrlRegs.GPDQSEL2.bit.GPIO117 = 3; // asynch input

    //TZ
    GpioCtrlRegs.GPAQSEL2.bit.GPIO20  = 3; // asynch input
    GpioCtrlRegs.GPAQSEL2.bit.GPIO21  = 3; // asynch input
    GpioCtrlRegs.GPAQSEL2.bit.GPIO22  = 3; // asynch input
    GpioCtrlRegs.GPAQSEL2.bit.GPIO23  = 3; // asynch input


    InputXbarRegs.INPUT1SELECT  = 20;      // GPIO20 = TZ1 ERR1  ~ ERR3
    InputXbarRegs.INPUT2SELECT  = 21;      // GPIO21 = TZ2 ERR4  ~ ERR6
    InputXbarRegs.INPUT3SELECT  = 22;      // GPIO22 = TZ3 ERR7  ~ ERR9
    InputXbarRegs.INPUT4SELECT  = 23;      // GPIO23 = TZ4 ERR10 ~ ERR12

    //ERR
    GpioCtrlRegs.GPCDIR.bit.GPIO94  = 0;  GPIO_SetupPinOptions( 94,  GPIO_INPUT, GPIO_PULLUP);   GPIO_SetupPinMux( 94, GPIO_MUX_CPU1, 0);
    GpioCtrlRegs.GPCDIR.bit.GPIO95  = 0;  GPIO_SetupPinOptions( 95,  GPIO_INPUT, GPIO_PULLUP);   GPIO_SetupPinMux( 95, GPIO_MUX_CPU1, 0);
    GpioCtrlRegs.GPDDIR.bit.GPIO96  = 0;  GPIO_SetupPinOptions( 96,  GPIO_INPUT, GPIO_PULLUP);   GPIO_SetupPinMux( 96, GPIO_MUX_CPU1, 0);
    GpioCtrlRegs.GPDDIR.bit.GPIO97  = 0;  GPIO_SetupPinOptions( 97,  GPIO_INPUT, GPIO_PULLUP);   GPIO_SetupPinMux( 97, GPIO_MUX_CPU1, 0);
    GpioCtrlRegs.GPDDIR.bit.GPIO98  = 0;  GPIO_SetupPinOptions( 98,  GPIO_INPUT, GPIO_PULLUP);   GPIO_SetupPinMux( 98, GPIO_MUX_CPU1, 0);
    GpioCtrlRegs.GPDDIR.bit.GPIO99  = 0;  GPIO_SetupPinOptions( 99,  GPIO_INPUT, GPIO_PULLUP);   GPIO_SetupPinMux( 99, GPIO_MUX_CPU1, 0);

    GpioCtrlRegs.GPDDIR.bit.GPIO112 = 0;  GPIO_SetupPinOptions( 112, GPIO_INPUT, GPIO_PULLUP);  GPIO_SetupPinMux( 112, GPIO_MUX_CPU1, 0);
    GpioCtrlRegs.GPDDIR.bit.GPIO113 = 0;  GPIO_SetupPinOptions( 113, GPIO_INPUT, GPIO_PULLUP);  GPIO_SetupPinMux( 113, GPIO_MUX_CPU1, 0);
    GpioCtrlRegs.GPDDIR.bit.GPIO114 = 0;  GPIO_SetupPinOptions( 114, GPIO_INPUT, GPIO_PULLUP);  GPIO_SetupPinMux( 114, GPIO_MUX_CPU1, 0);
    GpioCtrlRegs.GPDDIR.bit.GPIO115 = 0;  GPIO_SetupPinOptions( 115, GPIO_INPUT, GPIO_PULLUP);  GPIO_SetupPinMux( 115, GPIO_MUX_CPU1, 0);
    GpioCtrlRegs.GPDDIR.bit.GPIO116 = 0;  GPIO_SetupPinOptions( 116, GPIO_INPUT, GPIO_PULLUP);  GPIO_SetupPinMux( 116, GPIO_MUX_CPU1, 0);
    GpioCtrlRegs.GPDDIR.bit.GPIO117 = 0;  GPIO_SetupPinOptions( 117, GPIO_INPUT, GPIO_PULLUP);  GPIO_SetupPinMux( 117, GPIO_MUX_CPU1, 0);

    //TZ
    GpioCtrlRegs.GPADIR.bit.GPIO20  = 0;  GPIO_SetupPinOptions( 20,  GPIO_INPUT, GPIO_PULLUP);   GPIO_SetupPinMux( 20, GPIO_MUX_CPU1, 0);
    GpioCtrlRegs.GPADIR.bit.GPIO21  = 0;  GPIO_SetupPinOptions( 21,  GPIO_INPUT, GPIO_PULLUP);   GPIO_SetupPinMux( 21, GPIO_MUX_CPU1, 0);
    GpioCtrlRegs.GPADIR.bit.GPIO22  = 0;  GPIO_SetupPinOptions( 22,  GPIO_INPUT, GPIO_PULLUP);   GPIO_SetupPinMux( 22, GPIO_MUX_CPU1, 0);
    GpioCtrlRegs.GPADIR.bit.GPIO23  = 0;  GPIO_SetupPinOptions( 23,  GPIO_INPUT, GPIO_PULLUP);   GPIO_SetupPinMux( 23, GPIO_MUX_CPU1, 0);
    EDIS;

    EALLOW;
    EPwmXbarRegs.TRIP4MUX0TO15CFG.all       = 0x0000;   // TRIP4 입력에 대한 EPWM X-BAR Mux 0 ~ 31 설정을 모두 초기화 ( 0 ~ 15 )
    EPwmXbarRegs.TRIP4MUX16TO31CFG.all      = 0x0000;   // ( 16 ~ 31 )
    EPwmXbarRegs.TRIP4MUX0TO15CFG.bit.MUX7  = 1;        // TRIPIN4와 INPUTBAR4 연결 ( Mux7.2 = INPUTBAR4 )
    EPwmXbarRegs.TRIP4MUXENABLE.all         = 0x0000;   // TRIP4용 Mux 전체 비-활성화
    EPwmXbarRegs.TRIP4MUXENABLE.bit.MUX7    = 1;        // Mux7번만 활성화
    EDIS;

    // Interrupts that are used in this example are re-mapped to
    // ISR functions found within this file.
    EALLOW;
    PieVectTable.EPWM1_INT      = &epwm1_timer_isr;     //PIE Vector epwm1_timer_isr  interrupt 함수 define
    PieVectTable.EPWM2_INT      = &epwm2_timer_isr;     //PIE Vector epwm2_timer_isr  interrupt 함수 define
    PieVectTable.EPWM3_INT      = &epwm3_timer_isr;     //PIE Vector epwm3_timer_isr  interrupt 함수 define
    PieVectTable.EPWM4_INT      = &epwm4_timer_isr;     //PIE Vector epwm4_timer_isr  interrupt 함수 define
    PieVectTable.EPWM5_INT      = &epwm5_timer_isr;     //PIE Vector epwm5_timer_isr  interrupt 함수 define
    PieVectTable.EPWM6_INT      = &epwm6_timer_isr;     //PIE Vector epwm6_timer_isr  interrupt 함수 define
    PieVectTable.EPWM7_INT      = &epwm7_timer_isr;     //PIE Vector epwm7_timer_isr  interrupt 함수 define
    PieVectTable.EPWM8_INT      = &epwm8_timer_isr;     //PIE Vector epwm8_timer_isr  interrupt 함수 define
    PieVectTable.EPWM9_INT      = &epwm9_timer_isr;     //PIE Vector epwm9_timer_isr  interrupt 함수 define
    PieVectTable.EPWM10_INT     = &epwm10_timer_isr;    //PIE Vector epwm10_timer_isr interrupt 함수 define
    PieVectTable.EPWM11_INT     = &epwm11_timer_isr;    //PIE Vector epwm11_timer_isr interrupt 함수 define
    PieVectTable.EPWM12_INT     = &epwm12_timer_isr;    //PIE Vector epwm12_timer_isr interrupt 함수 define


    PieVectTable.EPWM1_TZ_INT   = &epwm1_tz1_isr;        //PIE Vector epwm1_tz1_isr  interrupt 함수 define
    PieVectTable.EPWM2_TZ_INT   = &epwm2_tz1_isr;        //PIE Vector epwm2_tz1_isr  interrupt 함수 define
    PieVectTable.EPWM3_TZ_INT   = &epwm3_tz1_isr;        //PIE Vector epwm3_tz1_isr  interrupt 함수 define
    PieVectTable.EPWM4_TZ_INT   = &epwm4_tz2_isr;        //PIE Vector epwm4_tz2_isr  interrupt 함수 define
    PieVectTable.EPWM5_TZ_INT   = &epwm5_tz2_isr;        //PIE Vector epwm5_tz2_isr  interrupt 함수 define
    PieVectTable.EPWM6_TZ_INT   = &epwm6_tz2_isr;        //PIE Vector epwm6_tz2_isr  interrupt 함수 define
    PieVectTable.EPWM7_TZ_INT   = &epwm7_tz3_isr;        //PIE Vector epwm7_tz3_isr  interrupt 함수 define
    PieVectTable.EPWM8_TZ_INT   = &epwm8_tz3_isr;        //PIE Vector epwm8_tz3_isr  interrupt 함수 define
    PieVectTable.EPWM9_TZ_INT   = &epwm9_tz3_isr;        //PIE Vector epwm9_tz3_isr  interrupt 함수 define
    PieVectTable.EPWM10_TZ_INT  = &epwm10_tz4_isr;       //PIE Vector epwm10_tz4_isr interrupt 함수 define
    PieVectTable.EPWM11_TZ_INT  = &epwm11_tz4_isr;       //PIE Vector epwm11_tz4_isr interrupt 함수 define
    PieVectTable.EPWM12_TZ_INT  = &epwm12_tz4_isr;       //PIE Vector epwm12_tz4_isr interrupt 함수 define
    EDIS;

    //Enable CPU INT2 which is connected to EPWM1/2 INT
    IER |= M_INT2;      //TZ
    IER |= M_INT3;      //EPWM

    //Enable CPU INT2 which is connected to EPWM1/2 INT
    //CPU Interrupt Enable
    PieCtrlRegs.PIEIER3.bit.INTx1 = 1; //PIE Group interrupt Enable
    PieCtrlRegs.PIEIER3.bit.INTx2 = 1; //PIE Group interrupt Enable
    PieCtrlRegs.PIEIER3.bit.INTx3 = 1; //PIE Group interrupt Enable
    PieCtrlRegs.PIEIER3.bit.INTx4 = 1; //PIE Group interrupt Enable
    PieCtrlRegs.PIEIER3.bit.INTx5 = 1; //PIE Group interrupt Enable
    PieCtrlRegs.PIEIER3.bit.INTx6 = 1; //PIE Group interrupt Enable
    PieCtrlRegs.PIEIER3.bit.INTx7 = 1; //PIE Group interrupt Enable
    PieCtrlRegs.PIEIER3.bit.INTx8 = 1; //PIE Group interrupt Enable
    PieCtrlRegs.PIEIER3.bit.INTx9 = 1; //PIE Group interrupt Enable
    PieCtrlRegs.PIEIER3.bit.INTx10 = 1; //PIE Group interrupt Enable
    PieCtrlRegs.PIEIER3.bit.INTx11 = 1; //PIE Group interrupt Enable
    PieCtrlRegs.PIEIER3.bit.INTx12 = 1; //PIE Group interrupt Enable

//    PieCtrlRegs.PIEIER2.bit.INTx1 = 1; //PIE Group interrupt Enable
//    PieCtrlRegs.PIEIER2.bit.INTx2 = 1; //PIE Group interrupt Enable
//    PieCtrlRegs.PIEIER2.bit.INTx3 = 1; //PIE Group interrupt Enable
//    PieCtrlRegs.PIEIER2.bit.INTx4 = 1; //PIE Group interrupt Enable
//    PieCtrlRegs.PIEIER2.bit.INTx5 = 1; //PIE Group interrupt Enable
//    PieCtrlRegs.PIEIER2.bit.INTx6 = 1; //PIE Group interrupt Enable
//    PieCtrlRegs.PIEIER2.bit.INTx7 = 1; //PIE Group interrupt Enable
//    PieCtrlRegs.PIEIER2.bit.INTx8 = 1; //PIE Group interrupt Enable
//    PieCtrlRegs.PIEIER2.bit.INTx9 = 1; //PIE Group interrupt Enable
//    PieCtrlRegs.PIEIER2.bit.INTx10 = 1; //PIE Group interrupt Enable
//    PieCtrlRegs.PIEIER2.bit.INTx11 = 1; //PIE Group interrupt Enable
//    PieCtrlRegs.PIEIER2.bit.INTx12 = 1; //PIE Group interrupt Enable
    EDIS;

    //EnableEPWM INTn int the PIE : Group 3 interrupt1/2
    //EnableEPWM INTn int the PIE : Group 2 interrupt1/2/3
}

//===========================================================================================================
void Init_ePwm1(void)
{
    EALLOW;
    // Initialize GPIO for ePWM output pin
    /* Enable internal pull-up for the selected pins */
    GpioCtrlRegs.GPEPUD.bit.GPIO145 = 0;    // Enable pull-up on GPIO145 (EPWM1A)
    GpioCtrlRegs.GPEPUD.bit.GPIO146 = 0;    // Enable pull-up on GPIO146 (EPWM1B)
    EDIS;

    // Setup TBCLK
    EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
    EPwm1Regs.TBPRD = (CNT_max_con -1);           // freq setting
    EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;    // Disable phase loading
    EPwm1Regs.TBPHS.bit.TBPHS = 0;         // Phase is 0
    EPwm1Regs.TBCTL.bit.PRDLD = TB_SHADOW;
    EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO;
    EPwm1Regs.TBCTL.bit.PHSDIR = 0;
    EPwm1Regs.TBCTR = 0x0000;
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV2;
    EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV1;

    // Setup shadow register load on ZERO
    EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm1Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
    EPwm1Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    // PWM setting
    // 효율 개선을 위한 수치 변경 적용 (EPwm1_CMP_test) 추가
    EPwm1Regs.CMPA.bit.CMPA = (CNT_max_con_50 - EPwm1_CMP_test);     // Set compare A value
    EPwm1Regs.CMPB.bit.CMPB = (CNT_max_con_50 - EPwm1_CMP_test);     // Set Compare B value

    // Set actions
    EPwm1Regs.AQCTLA.bit.PRD = AQ_SET;      // Set PWM1A on Zero
    EPwm1Regs.AQCTLA.bit.CAU = AQ_CLEAR;    // Clear PWM1A on event A, up count
    EPwm1Regs.AQCTLB.bit.PRD = AQ_SET;      // Set PWM1B on Zero
    EPwm1Regs.AQCTLB.bit.CAU = AQ_CLEAR;    // Clear PWM1B on event A, up count

    EPwm1Regs.AQCSFRC.bit.CSFA = 0x01;      // Low output. Continuous Software Force on output A
    EPwm1Regs.AQCSFRC.bit.CSFB = 0x02;      // High output. Continuous Software Force on output A
    EPwm1Regs.AQSFRC.bit.RLDCSF = 0x01;     // Load on event counter equals period

    // Set Dead-time
    EPwm1Regs.DBCTL.bit.IN_MODE = DBA_RED_DBB_FED;  // by moon
    EPwm1Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm1Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;

    //----------------------------------------------------------------------//
    EPwm1Regs.DBRED.bit.DBRED = T_dead_con_CNT;
    EPwm1Regs.DBFED.bit.DBFED = T_dead_con_CNT;


    // Disable PWM-chopping function
    EPwm1Regs.PCCTL.bit.CHPEN = 0;

#if 0
    EPwm1Regs.ETSEL.bit.SOCAEN = 0x1;    //Enable EPWMxSOCB pulse
    EPwm1Regs.ETSEL.bit.SOCASEL = 0x001; //Enable evemt to,e=base pimter equal to zero(TBCTR = 0x0000)
    EPwm1Regs.ETPS.bit.SOCACNT = 0x01;   // 1 event has occured
    EPwm1Regs.ETPS.bit.SOCAPRD = 0x01;   //Genetate the EPWMSOCB pulse on the first event

    DRV2_ADC_EPWM_ADCSOCA = DRV2_ADC_EPWM1_ADCSOCA;
#endif

    // Interrupt where we will change the Compare Values
    EPwm1Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO; // Select INT on Zero event
    EPwm1Regs.ETSEL.bit.INTEN = 1;            // Enable INT
    EPwm1Regs.ETPS.bit.INTPRD = ET_1ST;       // Generate INT on 1st event

#if 1
    EALLOW;
//  EPwm1Regs.DCTRIPSEL.bit.DCAHCOMPSEL    = 3;    // Digital Compare Trip 입력으로 TRIPIN4를 선택
//  EPwm1Regs.TZDCSEL.bit.DCAEVT1          = 2;    // Digital Compare Output A Event 1 생성 조건 설정
                                                    // DCAH = high, DCAL = don't care
    EPwm1Regs.TZEINT.bit.OST               = 1;    // TZ1, TZ2, TZ3  신호를  EPWM 모듈에 대한 One-Short Trip 입력으로 설정
//  EPwm1Regs.TZSEL.bit.DCAEVT1            = 1;    // TZ4( DCAEVT1 ) 신호를  EPWM 모듈에 대한 One-Short Trip 입력으로 설정

//  EPwm1Regs.TZCTL.bit.TZA                = 2;    // Trip 조건 발생 시 EPWM1A 핀 상태 규정 : Forced low
//  EPwm1Regs.TZCTL.bit.TZB                = 2;    // Trip 조건 발생 시 EPWM1B 핀 상태 규정 : Forced low

    EPwm1Regs.TZSEL.bit.OSHT1 = TZ_ENABLE;
//  EPwm1Regs.TZSEL.bit.OSHT2 = TZ_ENABLE;
//  EPwm1Regs.TZSEL.bit.OSHT3 = TZ_ENABLE;
//  EPwm1Regs.TZSEL.bit.OSHT4 = TZ_ENABLE;
    EDIS;
#endif
}
//===========================================================================================================

//===========================================================================================================
void Init_ePwm2(void)
{
    EALLOW;
    // Initialize GPIO for ePWM output pin
    /* Enable internal pull-up for the selected pins */
    GpioCtrlRegs.GPEPUD.bit.GPIO147 = 0;    // Enable pull-up on GPIO147 (EPWM2A)
    GpioCtrlRegs.GPEPUD.bit.GPIO148 = 0;    // Enable pull-up on GPIO148 (EPWM2B)
    EDIS;

    // Setup TBCLK
    EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
    EPwm2Regs.TBPRD = (CNT_max_con -1);         // freq setting
    EPwm2Regs.TBCTL.bit.PHSEN = TB_ENABLE;    // Enable phase loading
    EPwm2Regs.TBPHS.bit.TBPHS = 0;         // Phase is 0
    EPwm2Regs.TBCTL.bit.PRDLD = TB_SHADOW;
    EPwm2Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
    EPwm2Regs.TBCTL.bit.PHSDIR = 0;
    EPwm2Regs.TBCTR = 0x0000;                // Clear counter
    EPwm2Regs.TBCTL.bit.HSPCLKDIV = TB_DIV2; // Clock ratio to SYSCLKOUT/2
    EPwm2Regs.TBCTL.bit.CLKDIV = TB_DIV1; // 20kHz at 3750, 30kHz at 2500

    // Setup shadow register load on ZERO
    EPwm2Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm2Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm2Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
    EPwm2Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    // PWM setting
    // 효율 개선을 위한 수치 변경 적용 (EPwm2_CMP_test) 추가
    EPwm2Regs.CMPA.bit.CMPA = (CNT_max_con_50 - EPwm2_CMP_test);     // Set compare A value
    EPwm2Regs.CMPB.bit.CMPB = (CNT_max_con_50 - EPwm2_CMP_test);     // Set Compare B value

    //----------------------------------------------------------------------//
    // Set actions
    EPwm2Regs.AQCTLA.bit.ZRO = AQ_SET;      // Set PWM1A on Zero
    EPwm2Regs.AQCTLA.bit.CAU = AQ_CLEAR;    // Clear PWM1A on event A, up count
    EPwm2Regs.AQCTLB.bit.ZRO = AQ_SET;      // Set PWM1B on Zero
    EPwm2Regs.AQCTLB.bit.CAU = AQ_CLEAR;    // Clear PWM1B on event A, up count

    EPwm2Regs.AQCSFRC.bit.CSFA = 0x01;      // Low output. Continuous Software Force on output A
    EPwm2Regs.AQCSFRC.bit.CSFB = 0x02;      // High output. Continuous Software Force on output A
    EPwm2Regs.AQSFRC.bit.RLDCSF = 0x01;     // Load on event counter equals period

    // Set Dead-time
    EPwm2Regs.DBCTL.bit.IN_MODE = DBA_RED_DBB_FED;  // by moon
    EPwm2Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm2Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;

    //----------------------------------------------------------------------//
    EPwm2Regs.DBRED.bit.DBRED = T_dead_con_CNT;
    EPwm2Regs.DBFED.bit.DBFED = T_dead_con_CNT;

    // Disable PWM-chopping function
    EPwm2Regs.PCCTL.bit.CHPEN = 0;

#if 0
    EPwm2Regs.ETSEL.bit.SOCAEN = 0x1;    //Enable EPWMxSOCB pulse
    EPwm2Regs.ETSEL.bit.SOCASEL = 0x001; //Enable evemt to,e=base pimter equal to zero(TBCTR = 0x0000)
    EPwm2Regs.ETPS.bit.SOCACNT = 0x01;   // 1 event has occured
    EPwm2Regs.ETPS.bit.SOCAPRD = 0x01;   //Genetate the EPWMSOCB pulse on the first event

    DRV2_ADC_EPWM_ADCSOCA = DRV2_ADC_EPWM2_ADCSOCA;
#endif

    // Interrupt where we will change the Compare Values
    EPwm2Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO; // Select INT on Zero event
    EPwm2Regs.ETSEL.bit.INTEN = 1;            // Enable INT
    EPwm2Regs.ETPS.bit.INTPRD = ET_1ST;       // Generate INT on 1st event

#if 1
    EALLOW;
//  EPwm2Regs.DCTRIPSEL.bit.DCAHCOMPSEL    = 3;    // Digital Compare Trip 입력으로 TRIPIN4를 선택
//  EPwm2Regs.TZDCSEL.bit.DCAEVT1          = 2;    // Digital Compare Output A Event 1 생성 조건 설정
                                                    // DCAH = high, DCAL = don't care
    EPwm2Regs.TZEINT.bit.OST               = 1;    // TZ1, TZ2, TZ3  신호를  EPWM 모듈에 대한 One-Short Trip 입력으로 설정
//  EPwm2Regs.TZSEL.bit.DCAEVT1            = 1;    // TZ4( DCAEVT1 ) 신호를  EPWM 모듈에 대한 One-Short Trip 입력으로 설정

//  EPwm2Regs.TZCTL.bit.TZA                = 2;    // Trip 조건 발생 시 EPWM2A 핀 상태 규정 : Forced low
//  EPwm2Regs.TZCTL.bit.TZB                = 2;    // Trip 조건 발생 시 EPWM2B 핀 상태 규정 : Forced low

    EPwm2Regs.TZSEL.bit.OSHT1 = TZ_ENABLE;
//  EPwm2Regs.TZSEL.bit.OSHT2 = TZ_ENABLE;
//  EPwm2Regs.TZSEL.bit.OSHT3 = TZ_ENABLE;
//  EPwm2Regs.TZSEL.bit.OSHT4 = TZ_ENABLE;
    EDIS;
#endif
}
//===========================================================================================================


//===========================================================================================================
void Init_ePwm3(void)
{
    EALLOW;
    // Initialize GPIO for ePWM output pin
    /* Enable internal pull-up for the selected pins */
    GpioCtrlRegs.GPEPUD.bit.GPIO149 = 0;    // Enable pull-up on GPIO149 (EPWM3A)
    GpioCtrlRegs.GPEPUD.bit.GPIO150 = 0;    // Enable pull-up on GPIO150 (EPWM3B)
    EDIS;

    // Setup TBCLK
    EPwm3Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
    EPwm3Regs.TBPRD = (CNT_max_con -1);           // freq setting
    EPwm3Regs.TBCTL.bit.PHSEN = TB_ENABLE;    // Enable phase loading
    EPwm3Regs.TBPHS.bit.TBPHS = 0;         // Phase is 0
    EPwm3Regs.TBCTL.bit.PRDLD = TB_SHADOW;
    EPwm3Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
    EPwm3Regs.TBCTL.bit.PHSDIR = 0;
    EPwm3Regs.TBCTR = 0x0000;                // Clear counter
    EPwm3Regs.TBCTL.bit.HSPCLKDIV = TB_DIV2; // Clock ratio to SYSCLKOUT/2
    EPwm3Regs.TBCTL.bit.CLKDIV = TB_DIV1; // 20kHz at 3750, 30kHz at 2500

    // Setup shadow register load on ZERO
    EPwm3Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm3Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm3Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
    EPwm3Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    // PWM setting
    // 효율 개선을 위한 수치 변경 적용 (EPwm3_CMP_test) 추가
    EPwm3Regs.CMPA.bit.CMPA = (CNT_max_con_50 - EPwm3_CMP_test);     // Set compare A value
    EPwm3Regs.CMPB.bit.CMPB = (CNT_max_con_50 - EPwm3_CMP_test);     // Set Compare B value

    // Set actions
    EPwm3Regs.AQCTLA.bit.ZRO = AQ_SET;      // Set PWM1A on Zero
    EPwm3Regs.AQCTLA.bit.CAU = AQ_CLEAR;    // Clear PWM1A on event A, up count
    EPwm3Regs.AQCTLB.bit.ZRO = AQ_SET;      // Set PWM1B on Zero
    EPwm3Regs.AQCTLB.bit.CAU = AQ_CLEAR;    // Clear PWM1B on event A, up count

    EPwm3Regs.AQCSFRC.bit.CSFA = 0x01;      // Low output. Continuous Software Force on output A
    EPwm3Regs.AQCSFRC.bit.CSFB = 0x02;      // High output. Continuous Software Force on output A
    EPwm3Regs.AQSFRC.bit.RLDCSF = 0x01;     // Load on event counter equals period

    // Set Dead-time
    EPwm3Regs.DBCTL.bit.IN_MODE = DBA_RED_DBB_FED;  // by moon
    EPwm3Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm3Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;

    //----------------------------------------------------------------------//
    EPwm3Regs.DBRED.bit.DBRED = T_dead_con_CNT;
    EPwm3Regs.DBFED.bit.DBFED = T_dead_con_CNT;

    // Disable PWM-chopping function
    EPwm3Regs.PCCTL.bit.CHPEN = 0;

#if 0
    EPwm3Regs.ETSEL.bit.SOCAEN = 0x1;    //Enable EPWMxSOCB pulse
    EPwm3Regs.ETSEL.bit.SOCASEL = 0x001; //Enable evemt to,e=base pimter equal to zero(TBCTR = 0x0000)
    EPwm3Regs.ETPS.bit.SOCACNT = 0x01;   // 1 event has occured
    EPwm3Regs.ETPS.bit.SOCAPRD = 0x01;   //Genetate the EPWMSOCB pulse on the first event

    DRV2_ADC_EPWM_ADCSOCA = DRV2_ADC_EPWM3_ADCSOCA;
#endif

    // Interrupt where we will change the Compare Values
    EPwm3Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO; // Select INT on Zero event
    EPwm3Regs.ETSEL.bit.INTEN = 1;            // Enable INT
    EPwm3Regs.ETPS.bit.INTPRD = ET_1ST;       // Generate INT on 1st event

#if 1
    EALLOW;
//  EPwm3Regs.DCTRIPSEL.bit.DCAHCOMPSEL    = 3;    // Digital Compare Trip 입력으로 TRIPIN4를 선택
//  EPwm3Regs.TZDCSEL.bit.DCAEVT1          = 2;    // Digital Compare Output A Event 1 생성 조건 설정
                                                    // DCAH = high, DCAL = don't care
    EPwm3Regs.TZEINT.bit.OST               = 1;    // TZ1, TZ2, TZ3  신호를  EPWM 모듈에 대한 One-Short Trip 입력으로 설정
//  EPwm3Regs.TZSEL.bit.DCAEVT1            = 1;    // TZ4( DCAEVT1 ) 신호를  EPWM 모듈에 대한 One-Short Trip 입력으로 설정

//  EPwm3Regs.TZCTL.bit.TZA                = 2;    // Trip 조건 발생 시 EPWM3A 핀 상태 규정 : Forced low
//  EPwm3Regs.TZCTL.bit.TZB                = 2;    // Trip 조건 발생 시 EPWM3B 핀 상태 규정 : Forced low

    EPwm3Regs.TZSEL.bit.OSHT1 = TZ_ENABLE;
//  EPwm3Regs.TZSEL.bit.OSHT2 = TZ_ENABLE;
//  EPwm3Regs.TZSEL.bit.OSHT3 = TZ_ENABLE;
//  EPwm3Regs.TZSEL.bit.OSHT4 = TZ_ENABLE;
    EDIS;
#endif
}

//===========================================================================================================
void Init_ePwm4(void)
{
    EALLOW;
    // Initialize GPIO for ePWM output pin
    /* Enable internal pull-up for the selected pins */
    GpioCtrlRegs.GPEPUD.bit.GPIO151 = 0;    // Enable pull-up on GPIO151 (EPWM4A)
    GpioCtrlRegs.GPEPUD.bit.GPIO152 = 0;    // Enable pull-up on GPIO152 (EPWM4B)
    EDIS;

    // Setup TBCLK
    if(Mode_gating == 1)
    {
        EPwm4Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up
    }
    else
    {
        EPwm4Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
    }

    EPwm4Regs.TBPRD = (CNT_max);   // freq setting

    EPwm4Regs.TBCTL.bit.PHSEN = TB_DISABLE;    // Disable phase loading
    EPwm4Regs.TBPHS.bit.TBPHS = 0;         // Phase is 0
    EPwm4Regs.TBCTL.bit.PRDLD = TB_SHADOW;
    EPwm4Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO;
    EPwm4Regs.TBCTL.bit.PHSDIR = 0;
    EPwm4Regs.TBCTR = 0x0000;                // Clear counter
    EPwm4Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1; // Clock ratio to SYSCLKOUT
    EPwm4Regs.TBCTL.bit.CLKDIV = TB_DIV1; // 20kHz at 3750, 30kHz at 2500

    // Setup shadow register load on ZERO
    EPwm4Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm4Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm4Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
    EPwm4Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    // PWM setting
    EPwm4Regs.CMPA.bit.CMPA = 0;
    EPwm4Regs.CMPB.bit.CMPB = 0; // Set Compare B value

    if(Mode_gating == 1)
    {
        EPwm4Regs.AQCTLA.bit.CAD = AQ_SET;      // Set PWM4A on Zero
        EPwm4Regs.AQCTLA.bit.CAU = AQ_CLEAR;    // Clear PWM4A on event A, up count
        EPwm4Regs.AQCTLB.bit.CAD = AQ_SET;      // Set PWM4B on Zero
        EPwm4Regs.AQCTLB.bit.CAU = AQ_CLEAR;    // Clear PWM4B on event A, up count
    }
    else
    {
        // Set actions
        EPwm4Regs.AQCTLA.bit.ZRO = AQ_SET;      // Set PWM4A on Zero
        EPwm4Regs.AQCTLA.bit.CAU = AQ_CLEAR;    // Clear PWM4A on event A, up count
        EPwm4Regs.AQCTLB.bit.ZRO = AQ_SET;      // Set PWM4B on Zero
        EPwm4Regs.AQCTLB.bit.CAU = AQ_CLEAR;    // Clear PWM4B on event A, up count
    }

    EPwm4Regs.AQCSFRC.bit.CSFA = 0x01;      // Low output. Continuous Software Force on output A
    EPwm4Regs.AQCSFRC.bit.CSFB = 0x02;      // High output. Continuous Software Force on output A
    EPwm4Regs.AQSFRC.bit.RLDCSF = 0x01;     // Load on event counter equals period


    // Set Dead-time
    EPwm4Regs.DBCTL.bit.IN_MODE = DBA_RED_DBB_FED;  // by moon
    EPwm4Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm4Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;

    //----------------------------------------------------------------------//
    EPwm4Regs.DBRED.bit.DBRED = T_dead_CNT;
    EPwm4Regs.DBFED.bit.DBFED = T_dead_CNT;

    // Disable PWM-chopping function
    EPwm4Regs.PCCTL.bit.CHPEN = 0;

#if 1
    EPwm4Regs.ETSEL.bit.SOCAEN = 0x1;    //Enable EPWMxSOCB pulse

    if(Mode_gating == 1)
    {
        EPwm4Regs.ETSEL.bit.SOCASEL = 0x002;    //Enable evemt to,e=base pimter equal to zero(TBCTR = ---) - 1 check
    }
    else
    {
        EPwm4Regs.ETSEL.bit.SOCASEL = 0x001;  //Enable evemt to,e=base pimter equal to zero(TBCTR = 0x0000) - 1 check
    }

//    EPwm4Regs.ETSEL.bit.SOCASEL = 0x003;    //Enable evemt to,e=base pimter equal to zero(TBCTR = 0x0000 | ---) - 2 check

    EPwm4Regs.ETPS.bit.SOCACNT = 0x01;   // 1 event has occured

    if(Mode_SOCAPRD == 1)
    {
        EPwm4Regs.ETPS.bit.SOCAPRD = 0x01;   //Genetate the EPWMSOCB pulse on the first event
    }
    else if(Mode_SOCAPRD == 2)
    {
        EPwm4Regs.ETPS.bit.SOCAPRD = 0x02;   //Genetate the EPWMSOCB pulse on the 2번 1회 event
    }
    DRV2_ADC_EPWM_ADCSOCA = DRV2_ADC_EPWM4_ADCSOCA;
#endif

    // Interrupt where we will change the Compare Values
    EPwm4Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO; // Select INT on Zero event
    EPwm4Regs.ETSEL.bit.INTEN = 1;            // Enable INT
    EPwm4Regs.ETPS.bit.INTPRD = ET_1ST;       // Generate INT on 1st event

#if 1
    EALLOW;
//  EPwm4Regs.DCTRIPSEL.bit.DCAHCOMPSEL    = 3;    // Digital Compare Trip 입력으로 TRIPIN4를 선택
//  EPwm4Regs.TZDCSEL.bit.DCAEVT1          = 2;    // Digital Compare Output A Event 1 생성 조건 설정
                                                    // DCAH = high, DCAL = don't care
    EPwm4Regs.TZEINT.bit.OST               = 1;    // TZ1, TZ2, TZ3  신호를  EPWM 모듈에 대한 One-Short Trip 입력으로 설정
//  EPwm4Regs.TZSEL.bit.DCAEVT1            = 1;    // TZ4( DCAEVT1 ) 신호를  EPWM 모듈에 대한 One-Short Trip 입력으로 설정

//  EPwm4Regs.TZCTL.bit.TZA                = 2;    // Trip 조건 발생 시 EPWM4A 핀 상태 규정 : Forced low
//  EPwm4Regs.TZCTL.bit.TZB                = 2;    // Trip 조건 발생 시 EPWM4B 핀 상태 규정 : Forced low

//  EPwm4Regs.TZSEL.bit.OSHT1 = TZ_ENABLE;
    EPwm4Regs.TZSEL.bit.OSHT2 = TZ_ENABLE;
//  EPwm4Regs.TZSEL.bit.OSHT3 = TZ_ENABLE;
//  EPwm4Regs.TZSEL.bit.OSHT4 = TZ_ENABLE;
    EDIS;
#endif
}

//===========================================================================================================
void Init_ePwm5(void)
{
    EALLOW;
    // Initialize GPIO for ePWM output pin
    /* Enable internal pull-up for the selected pins */
    GpioCtrlRegs.GPEPUD.bit.GPIO153 = 0;    // Enable pull-up on GPIO153 (EPWM5A)
    GpioCtrlRegs.GPEPUD.bit.GPIO154 = 0;    // Enable pull-up on GPIO154 (EPWM5B)
    EDIS;

    // Setup TBCLK
    if(Mode_gating == 1)
    {
        EPwm5Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up
    }

    else
    {
        EPwm5Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
    }

    EPwm5Regs.TBPRD = (CNT_max);   // freq setting
    EPwm5Regs.TBCTL.bit.PHSEN = TB_ENABLE;      // Enable phase loading
    EPwm5Regs.TBPHS.bit.TBPHS = 0;         // Phase is 0
    EPwm5Regs.TBCTL.bit.PRDLD = TB_SHADOW;
    EPwm5Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
    EPwm5Regs.TBCTL.bit.PHSDIR = 0;
    EPwm5Regs.TBCTR = 0x0000;                // Clear counter
    EPwm5Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1; // Clock ratio to SYSCLKOUT
    EPwm5Regs.TBCTL.bit.CLKDIV = TB_DIV1; // 20kHz at 3750, 30kHz at 2500

    // Setup shadow register load on ZERO
    EPwm5Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm5Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm5Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
    EPwm5Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    // PWM setting
    EPwm5Regs.CMPA.bit.CMPA = 0;
    EPwm5Regs.CMPB.bit.CMPB = 0; // Set Compare B value

    if(Mode_gating == 1)
    {
        EPwm5Regs.AQCTLA.bit.CAD = AQ_SET;      // Set PWM5A on Zero
        EPwm5Regs.AQCTLA.bit.CAU = AQ_CLEAR;    // Clear PWM5A on event A, up count
        EPwm5Regs.AQCTLB.bit.CAD = AQ_SET;      // Set PWM5B on Zero
        EPwm5Regs.AQCTLB.bit.CAU = AQ_CLEAR;    // Clear PWM5B on event A, up count
    }
    else
    {
    // Set actions
        EPwm5Regs.AQCTLA.bit.ZRO = AQ_SET;      // Set PWM5A on Zero
        EPwm5Regs.AQCTLA.bit.CAU = AQ_CLEAR;    // Clear PWM5A on event A, up count
        EPwm5Regs.AQCTLB.bit.ZRO = AQ_SET;      // Set PWM5B on Zero
        EPwm5Regs.AQCTLB.bit.CAU = AQ_CLEAR;    // Clear PWM5B on event A, up count
    }

    EPwm5Regs.AQCSFRC.bit.CSFA = 0x01;      // Low output. Continuous Software Force on output A
    EPwm5Regs.AQCSFRC.bit.CSFB = 0x02;      // High output. Continuous Software Force on output A
    EPwm5Regs.AQSFRC.bit.RLDCSF = 0x01;     // Load on event cunter equals period

    // Set Dead-time
    EPwm5Regs.DBCTL.bit.IN_MODE = DBA_RED_DBB_FED;  // by moon
    EPwm5Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm5Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;

    EPwm5Regs.DBRED.bit.DBRED = T_dead_CNT;
    EPwm5Regs.DBFED.bit.DBFED = T_dead_CNT;

    // Disable PWM-chopping function
    EPwm5Regs.PCCTL.bit.CHPEN = 0;


#if 0
    EPwm5Regs.ETSEL.bit.SOCAEN = 0x1;    //Enable EPWMxSOCB pulse
    EPwm5Regs.ETSEL.bit.SOCASEL = 0x001; //Enable evemt to,e=base pimter equal to zero(TBCTR = 0x0000)
    EPwm5Regs.ETPS.bit.SOCACNT = 0x01;   // 1 event has occured
    EPwm5Regs.ETPS.bit.SOCAPRD = 0x01;   //Genetate the EPWMSOCB pulse on the first event

    DRV2_ADC_EPWM_ADCSOCA = DRV2_ADC_EPWM5_ADCSOCA;
#endif

    // Interrupt where we will change the Compare Values
    EPwm5Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO; // Select INT on Zero event
    EPwm5Regs.ETSEL.bit.INTEN = 1;            // Enable INT
    EPwm5Regs.ETPS.bit.INTPRD = ET_1ST;       // Generate INT on 1st event

#if 1
    EALLOW;
//  EPwm5Regs.DCTRIPSEL.bit.DCAHCOMPSEL    = 3;    // Digital Compare Trip 입력으로 TRIPIN4를 선택
//  EPwm5Regs.TZDCSEL.bit.DCAEVT1          = 2;    // Digital Compare Output A Event 1 생성 조건 설정
                                                    // DCAH = high, DCAL = don't care
    EPwm5Regs.TZEINT.bit.OST               = 1;    // TZ1, TZ2, TZ3  신호를  EPWM 모듈에 대한 One-Short Trip 입력으로 설정
//  EPwm5Regs.TZSEL.bit.DCAEVT1            = 1;    // TZ4( DCAEVT1 ) 신호를  EPWM 모듈에 대한 One-Short Trip 입력으로 설정

//  EPwm5Regs.TZCTL.bit.TZA                = 2;    // Trip 조건 발생 시 EPWM5A 핀 상태 규정 : Forced low
//  EPwm5Regs.TZCTL.bit.TZB                = 2;    // Trip 조건 발생 시 EPWM5B 핀 상태 규정 : Forced low

//  EPwm5Regs.TZSEL.bit.OSHT1 = TZ_ENABLE;
    EPwm5Regs.TZSEL.bit.OSHT2 = TZ_ENABLE;
//  EPwm5Regs.TZSEL.bit.OSHT3 = TZ_ENABLE;
//  EPwm5Regs.TZSEL.bit.OSHT4 = TZ_ENABLE;
    EDIS;
#endif
}

//===========================================================================================================
void Init_ePwm6(void)
{
    EALLOW;
    // Initialize GPIO for ePWM output pin
    /* Enable internal pull-up for the selected pins */
    GpioCtrlRegs.GPEPUD.bit.GPIO155 = 0;    // Enable pull-up on GPIO155 (EPWM6A)
    GpioCtrlRegs.GPEPUD.bit.GPIO156 = 0;    // Enable pull-up on GPIO156 (EPWM6B)
    EDIS;

    if(Mode_gating == 1)
    {
        EPwm6Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up
    }
    else
    {
        EPwm6Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
    }

    EPwm6Regs.TBPRD = (CNT_max);   // freq setting
    EPwm6Regs.TBCTL.bit.PHSEN = TB_ENABLE;    // Disable phase loading
    EPwm6Regs.TBPHS.bit.TBPHS = 0;         // Phase is 0
    EPwm6Regs.TBCTL.bit.PRDLD = TB_SHADOW;
    EPwm6Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
    EPwm6Regs.TBCTL.bit.PHSDIR = 0;
    EPwm6Regs.TBCTR = 0x0000;                // Clear counter
    EPwm6Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1; // Clock ratio to SYSCLKOUT
    EPwm6Regs.TBCTL.bit.CLKDIV = TB_DIV1; // 20kHz at 3750, 30kHz at 2500

    // Setup shadow register load on ZERO
    EPwm6Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm6Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm6Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
    EPwm6Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    // PWM setting
    EPwm6Regs.CMPA.bit.CMPA = 0;
    EPwm6Regs.CMPB.bit.CMPB = 0; // Set Compare B value


    EPwm6Regs.AQCSFRC.bit.CSFA = 0x01;      // Low output. Continuous Software Force on output A
    EPwm6Regs.AQCSFRC.bit.CSFB = 0x02;      // High output. Continuous Software Force on output A
    EPwm6Regs.AQSFRC.bit.RLDCSF = 0x01;     // Load on event counter equals period

    if(Mode_gating == 1)
    {
        EPwm6Regs.AQCTLA.bit.CAD = AQ_SET;      // Set PWM1A on Zero
        EPwm6Regs.AQCTLA.bit.CAU = AQ_CLEAR;    // Clear PWM1A on event A, up count
        EPwm6Regs.AQCTLB.bit.CAD = AQ_SET;      // Set PWM1B on Zero
        EPwm6Regs.AQCTLB.bit.CAU = AQ_CLEAR;    // Clear PWM1B on event A, up count
    }
    else
    {
        // Set actions
        EPwm6Regs.AQCTLA.bit.ZRO = AQ_SET;      // Set PWM6A on Zero
        EPwm6Regs.AQCTLA.bit.CAU = AQ_CLEAR;    // Clear PWM6A on event A, up count
        EPwm6Regs.AQCTLB.bit.ZRO = AQ_SET;      // Set PWM6B on Zero
        EPwm6Regs.AQCTLB.bit.CAU = AQ_CLEAR;    // Clear PWM6B on event A, up count
    }

    // Set Dead-time
    EPwm6Regs.DBCTL.bit.IN_MODE = DBA_RED_DBB_FED;  // by moon
    EPwm6Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm6Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;

    EPwm6Regs.DBRED.bit.DBRED = T_dead_CNT;
    EPwm6Regs.DBFED.bit.DBFED = T_dead_CNT;

    // Disable PWM-chopping function
    EPwm6Regs.PCCTL.bit.CHPEN = 0;


#if 0
    EPwm6Regs.ETSEL.bit.SOCAEN = 0x1;    //Enable EPWMxSOCB pulse
    EPwm6Regs.ETSEL.bit.SOCASEL = 0x001; //Enable evemt to,e=base pimter equal to zero(TBCTR = 0x0000)
    EPwm6Regs.ETPS.bit.SOCACNT = 0x01;   // 1 event has occured
    EPwm6Regs.ETPS.bit.SOCAPRD = 0x01;   //Genetate the EPWMSOCB pulse on the first event

    DRV2_ADC_EPWM_ADCSOCA = DRV2_ADC_EPWM6_ADCSOCA;
#endif

    // Interrupt where we will change the Compare Values
    EPwm6Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO; // Select INT on Zero event
    EPwm6Regs.ETSEL.bit.INTEN = 1;            // Enable INT
    EPwm6Regs.ETPS.bit.INTPRD = ET_1ST;       // Generate INT on 1st event

#if 1
    EALLOW;
//  EPwm6Regs.DCTRIPSEL.bit.DCAHCOMPSEL    = 3;    // Digital Compare Trip 입력으로 TRIPIN4를 선택
//  EPwm6Regs.TZDCSEL.bit.DCAEVT1          = 2;    // Digital Compare Output A Event 1 생성 조건 설정
                                                    // DCAH = high, DCAL = don't care
    EPwm6Regs.TZEINT.bit.OST               = 1;    // TZ1, TZ2, TZ3  신호를  EPWM 모듈에 대한 One-Short Trip 입력으로 설정
//  EPwm6Regs.TZSEL.bit.DCAEVT1            = 1;    // TZ4( DCAEVT1 ) 신호를  EPWM 모듈에 대한 One-Short Trip 입력으로 설정

//  EPwm6Regs.TZCTL.bit.TZA                = 2;    // Trip 조건 발생 시 EPWM6A 핀 상태 규정 : Forced low
//  EPwm6Regs.TZCTL.bit.TZB                = 2;    // Trip 조건 발생 시 EPWM6B 핀 상태 규정 : Forced low

//  EPwm6Regs.TZSEL.bit.OSHT1 = TZ_ENABLE;
    EPwm6Regs.TZSEL.bit.OSHT2 = TZ_ENABLE;
//  EPwm6Regs.TZSEL.bit.OSHT3 = TZ_ENABLE;
//  EPwm6Regs.TZSEL.bit.OSHT4 = TZ_ENABLE;
    EDIS;
#endif
}

void Init_ePwm7(void)
{
    EALLOW;
    // Initialize GPIO for ePWM output pin
    /* Enable internal pull-up for the selected pins */
    GpioCtrlRegs.GPEPUD.bit.GPIO157 = 0;    // Enable pull-up on GPIO157 (EPWM7A)
    GpioCtrlRegs.GPEPUD.bit.GPIO158 = 0;    // Enable pull-up on GPIO158 (EPWM7B)
    EDIS;

    EPwm7Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up
    EPwm7Regs.TBPRD = (CNT_max);   // freq setting
    EPwm7Regs.TBCTL.bit.PHSEN = TB_ENABLE;    // Disable phase loading
    EPwm7Regs.TBPHS.bit.TBPHS = 0;         // Phase is 0
    EPwm7Regs.TBCTL.bit.PRDLD = TB_SHADOW;
    EPwm7Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
    EPwm7Regs.TBCTL.bit.PHSDIR = 0;
    EPwm7Regs.TBCTR = 0x0000;                // Clear counter
    EPwm7Regs.TBCTL.bit.HSPCLKDIV = TB_DIV2; // Clock ratio to SYSCLKOUT/2
    EPwm7Regs.TBCTL.bit.CLKDIV = TB_DIV1; // 20kHz at 3750, 30kHz at 2500

    // Setup shadow register load on ZERO
    EPwm7Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm7Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm7Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
    EPwm7Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    // PWM setting
    EPwm7Regs.CMPA.bit.CMPA = 0;
    EPwm7Regs.CMPB.bit.CMPB = 0; // Set Compare B value

    EPwm7Regs.AQCSFRC.bit.CSFA = 0x01;      // Low output. Continuous Software Force on output A
    EPwm7Regs.AQCSFRC.bit.CSFB = 0x02;      // High output. Continuous Software Force on output A
    EPwm7Regs.AQSFRC.bit.RLDCSF = 0x01;     // Load on event counter equals period

    EPwm7Regs.AQCTLA.bit.CAD = AQ_SET;      // Set PWM1A on Zero
    EPwm7Regs.AQCTLA.bit.CAU = AQ_CLEAR;    // Clear PWM1A on event A, up count
    EPwm7Regs.AQCTLB.bit.CAD = AQ_SET;      // Set PWM1B on Zero
    EPwm7Regs.AQCTLB.bit.CAU = AQ_CLEAR;    // Clear PWM1B on event A, up count


    // Set Dead-time
    EPwm7Regs.DBCTL.bit.IN_MODE = DBA_RED_DBB_FED;  // by moon
    EPwm7Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm7Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;

    EPwm7Regs.DBRED.bit.DBRED = DEADTIME_GAP_inv;
    EPwm7Regs.DBFED.bit.DBFED = DEADTIME_GAP_inv;

    // Disable PWM-chopping function
    EPwm7Regs.PCCTL.bit.CHPEN = 0;


#if 0
    EPwm7Regs.ETSEL.bit.SOCAEN = 0x1;    //Enable EPWMxSOCB pulse
    EPwm7Regs.ETSEL.bit.SOCASEL = 0x001; //Enable evemt to,e=base pimter equal to zero(TBCTR = 0x0000)
    EPwm7Regs.ETPS.bit.SOCACNT = 0x01;   // 1 event has occured
    EPwm7Regs.ETPS.bit.SOCAPRD = 0x01;   //Genetate the EPWMSOCB pulse on the first event

    DRV2_ADC_EPWM_ADCSOCA = DRV2_ADC_EPWM7_ADCSOCA;
#endif


    // Interrupt where we will change the Compare Values
    EPwm7Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO; // Select INT on Zero event
    EPwm7Regs.ETSEL.bit.INTEN = 1;            // Enable INT
    EPwm7Regs.ETPS.bit.INTPRD = ET_1ST;       // Generate INT on 1st event

#if 1
    EALLOW;
//  EPwm7Regs.DCTRIPSEL.bit.DCAHCOMPSEL    = 3;    // Digital Compare Trip 입력으로 TRIPIN4를 선택
//  EPwm7Regs.TZDCSEL.bit.DCAEVT1          = 2;    // Digital Compare Output A Event 1 생성 조건 설정
                                                    // DCAH = high, DCAL = don't care
    EPwm7Regs.TZEINT.bit.OST               = 1;    // TZ1, TZ2, TZ3  신호를  EPWM 모듈에 대한 One-Short Trip 입력으로 설정
//  EPwm7Regs.TZSEL.bit.DCAEVT1            = 1;    // TZ4( DCAEVT1 ) 신호를  EPWM 모듈에 대한 One-Short Trip 입력으로 설정

//  EPwm7Regs.TZCTL.bit.TZA                = 2;    // Trip 조건 발생 시 EPWM7A 핀 상태 규정 : Forced low
//  EPwm7Regs.TZCTL.bit.TZB                = 2;    // Trip 조건 발생 시 EPWM7B 핀 상태 규정 : Forced low

//  EPwm7Regs.TZSEL.bit.OSHT1 = TZ_ENABLE;
//  EPwm7Regs.TZSEL.bit.OSHT2 = TZ_ENABLE;
    EPwm7Regs.TZSEL.bit.OSHT3 = TZ_ENABLE;
//  EPwm7Regs.TZSEL.bit.OSHT4 = TZ_ENABLE;
    EDIS;
#endif
}

void Init_ePwm8(void)
{

    EALLOW;
    // Initialize GPIO for ePWM output pin
    /* Enable internal pull-up for the selected pins */
    GpioCtrlRegs.GPEPUD.bit.GPIO159 = 0;    // Enable pull-up on GPIO159 (EPWM8A)
    GpioCtrlRegs.GPFPUD.bit.GPIO160 = 0;    // Enable pull-up on GPIO160 (EPWM8B)
    EDIS;

    EPwm8Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up
    EPwm8Regs.TBPRD = (CNT_max);   // freq setting

    EPwm8Regs.TBCTL.bit.PHSEN = TB_ENABLE;    // Disable phase loading
    EPwm8Regs.TBPHS.bit.TBPHS = 0;         // Phase is 0
    EPwm8Regs.TBCTL.bit.PRDLD = TB_SHADOW;
    EPwm8Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
    EPwm8Regs.TBCTL.bit.PHSDIR = 0;
    EPwm8Regs.TBCTR = 0x0000;                // Clear counter
    EPwm8Regs.TBCTL.bit.HSPCLKDIV = TB_DIV2; // Clock ratio to SYSCLKOUT/2
    EPwm8Regs.TBCTL.bit.CLKDIV = TB_DIV1; // 20kHz at 3750, 30kHz at 2500

    // Setup shadow register load on ZERO
    EPwm8Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm8Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm8Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
    EPwm8Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    // PWM setting
    EPwm8Regs.CMPA.bit.CMPA = 0;
    EPwm8Regs.CMPB.bit.CMPB = 0; // Set Compare B value

    EPwm8Regs.AQCSFRC.bit.CSFA = 0x01;      // Low output. Continuous Software Force on output A
    EPwm8Regs.AQCSFRC.bit.CSFB = 0x02;      // High output. Continuous Software Force on output A
    EPwm8Regs.AQSFRC.bit.RLDCSF = 0x01;     // Load on event counter equals period

    EPwm8Regs.AQCTLA.bit.CAD = AQ_SET;      // Set PWM1A on Zero
    EPwm8Regs.AQCTLA.bit.CAU = AQ_CLEAR;    // Clear PWM1A on event A, up count
    EPwm8Regs.AQCTLB.bit.CAD = AQ_SET;      // Set PWM1B on Zero
    EPwm8Regs.AQCTLB.bit.CAU = AQ_CLEAR;    // Clear PWM1B on event A, up count

    // Set Dead-time
    EPwm8Regs.DBCTL.bit.IN_MODE = DBA_RED_DBB_FED;  // by moon
    EPwm8Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm8Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;

    EPwm8Regs.DBRED.bit.DBRED = DEADTIME_GAP_inv;
    EPwm8Regs.DBFED.bit.DBFED = DEADTIME_GAP_inv;

    // Disable PWM-chopping function
    EPwm8Regs.PCCTL.bit.CHPEN = 0;


#if 0
    EPwm8Regs.ETSEL.bit.SOCAEN = 0x1;    //Enable EPWMxSOCB pulse
    EPwm8Regs.ETSEL.bit.SOCASEL = 0x001; //Enable evemt to,e=base pimter equal to zero(TBCTR = 0x0000)
    EPwm8Regs.ETPS.bit.SOCACNT = 0x01;   // 1 event has occured
    EPwm8Regs.ETPS.bit.SOCAPRD = 0x01;   //Genetate the EPWMSOCB pulse on the first event

    DRV2_ADC_EPWM_ADCSOCA = DRV2_ADC_EPWM8_ADCSOCA;
#endif


    // Interrupt where we will change the Compare Values
    EPwm8Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO; // Select INT on Zero event
    EPwm8Regs.ETSEL.bit.INTEN = 1;            // Enable INT
    EPwm8Regs.ETPS.bit.INTPRD = ET_1ST;       // Generate INT on 1st event

#if 1
    EALLOW;
//  EPwm8Regs.DCTRIPSEL.bit.DCAHCOMPSEL    = 3;    // Digital Compare Trip 입력으로 TRIPIN4를 선택
//  EPwm8Regs.TZDCSEL.bit.DCAEVT1          = 2;    // Digital Compare Output A Event 1 생성 조건 설정
                                                    // DCAH = high, DCAL = don't care
    EPwm8Regs.TZEINT.bit.OST               = 1;    // TZ1, TZ2, TZ3  신호를  EPWM 모듈에 대한 One-Short Trip 입력으로 설정
//  EPwm8Regs.TZSEL.bit.DCAEVT1            = 1;    // TZ4( DCAEVT1 ) 신호를  EPWM 모듈에 대한 One-Short Trip 입력으로 설정

//  EPwm8Regs.TZCTL.bit.TZA                = 2;    // Trip 조건 발생 시 EPWM9A 핀 상태 규정 : Forced low
//  EPwm8Regs.TZCTL.bit.TZB                = 2;    // Trip 조건 발생 시 EPWM9B 핀 상태 규정 : Forced low

//  EPwm8Regs.TZSEL.bit.OSHT1 = TZ_ENABLE;
//  EPwm8Regs.TZSEL.bit.OSHT2 = TZ_ENABLE;
    EPwm8Regs.TZSEL.bit.OSHT3 = TZ_ENABLE;
//  EPwm8Regs.TZSEL.bit.OSHT4 = TZ_ENABLE;
    EDIS;
#endif
}

void Init_ePwm9(void)
{
    EALLOW;
    // Initialize GPIO for ePWM output pin
    /* Enable internal pull-up for the selected pins */
    GpioCtrlRegs.GPFPUD.bit.GPIO161 = 0;    // Enable pull-up on GPIO161 (EPWM9A)
    GpioCtrlRegs.GPFPUD.bit.GPIO162 = 0;    // Enable pull-up on GPIO162 (EPWM9B)
    EDIS;

    // Setup TBCLK
    EPwm9Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up
    EPwm9Regs.TBPRD = (CNT_max);   // freq setting
    EPwm9Regs.TBCTL.bit.PHSEN = TB_ENABLE;    // Disable phase loading
    EPwm9Regs.TBPHS.bit.TBPHS = 0;         // Phase is 0
    EPwm9Regs.TBCTL.bit.PRDLD = TB_SHADOW;
    EPwm9Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
    EPwm9Regs.TBCTL.bit.PHSDIR = 0;
    EPwm9Regs.TBCTR = 0x0000;                // Clear counter
    EPwm9Regs.TBCTL.bit.HSPCLKDIV = TB_DIV2; // Clock ratio to SYSCLKOUT/2
    EPwm9Regs.TBCTL.bit.CLKDIV = TB_DIV1; // 20kHz at 3750, 30kHz at 2500

    // Setup shadow register load on ZERO
    EPwm9Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm9Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm9Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
    EPwm9Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    // PWM setting
    EPwm9Regs.CMPA.bit.CMPA = 0;
    EPwm9Regs.CMPB.bit.CMPB = 0; // Set Compare B value

    EPwm9Regs.AQCSFRC.bit.CSFA = 0x01;      // Low output. Continuous Software Force on output A
    EPwm9Regs.AQCSFRC.bit.CSFB = 0x02;      // High output. Continuous Software Force on output A
    EPwm9Regs.AQSFRC.bit.RLDCSF = 0x01;     // Load on event counter equals period

    EPwm9Regs.AQCTLA.bit.CAD = AQ_SET;      // Set PWM1A on Zero
    EPwm9Regs.AQCTLA.bit.CAU = AQ_CLEAR;    // Clear PWM1A on event A, up count
    EPwm9Regs.AQCTLB.bit.CAD = AQ_SET;      // Set PWM1B on Zero
    EPwm9Regs.AQCTLB.bit.CAU = AQ_CLEAR;    // Clear PWM1B on event A, up count

    // Set Dead-time
    EPwm9Regs.DBCTL.bit.IN_MODE = DBA_RED_DBB_FED;  // by moon
    EPwm9Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm9Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;

    EPwm9Regs.DBRED.bit.DBRED = DEADTIME_GAP_inv;
    EPwm9Regs.DBFED.bit.DBFED = DEADTIME_GAP_inv;

    // Disable PWM-chopping function
    EPwm9Regs.PCCTL.bit.CHPEN = 0;

#if 0
    EPwm9Regs.ETSEL.bit.SOCAEN = 0x1;    //Enable EPWMxSOCB pulse
    EPwm9Regs.ETSEL.bit.SOCASEL = 0x001; //Enable evemt to,e=base pimter equal to zero(TBCTR = 0x0000)
    EPwm9Regs.ETPS.bit.SOCACNT = 0x01;   // 1 event has occured
    EPwm9Regs.ETPS.bit.SOCAPRD = 0x01;   //Genetate the EPWMSOCB pulse on the first event

    DRV2_ADC_EPWM_ADCSOCA = DRV2_ADC_EPWM9_ADCSOCA;
#endif


    // Interrupt where we will change the Compare Values
    EPwm9Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO; // Select INT on Zero event
    EPwm9Regs.ETSEL.bit.INTEN = 1;            // Enable INT
    EPwm9Regs.ETPS.bit.INTPRD = ET_1ST;       // Generate INT on 1st event

#if 1
    EALLOW;
//  EPwm9Regs.DCTRIPSEL.bit.DCAHCOMPSEL    = 3;    // Digital Compare Trip 입력으로 TRIPIN4를 선택
//  EPwm9Regs.TZDCSEL.bit.DCAEVT1          = 2;    // Digital Compare Output A Event 1 생성 조건 설정
                                                    // DCAH = high, DCAL = don't care
    EPwm9Regs.TZEINT.bit.OST               = 1;    // TZ1, TZ2, TZ3  신호를  EPWM 모듈에 대한 One-Short Trip 입력으로 설정
//  EPwm9Regs.TZSEL.bit.DCAEVT1            = 1;    // TZ4( DCAEVT1 ) 신호를  EPWM 모듈에 대한 One-Short Trip 입력으로 설정

//  EPwm9Regs.TZCTL.bit.TZA                = 2;    // Trip 조건 발생 시 EPWM9A 핀 상태 규정 : Forced low
//  EPwm9Regs.TZCTL.bit.TZB                = 2;    // Trip 조건 발생 시 EPWM9B 핀 상태 규정 : Forced low

//  EPwm9Regs.TZSEL.bit.OSHT1 = TZ_ENABLE;
//  EPwm9Regs.TZSEL.bit.OSHT2 = TZ_ENABLE;
    EPwm9Regs.TZSEL.bit.OSHT3 = TZ_ENABLE;
//  EPwm9Regs.TZSEL.bit.OSHT4 = TZ_ENABLE;
    EDIS;
#endif
}


void Init_ePwm10(void)
{
    EALLOW;
    // Initialize GPIO for ePWM output pin
    /* Enable internal pull-up for the selected pins */
    GpioCtrlRegs.GPFPUD.bit.GPIO163 = 0;    // Enable pull-up on GPIO163 (EPWM10A)
    GpioCtrlRegs.GPFPUD.bit.GPIO164 = 0;    // Enable pull-up on GPIO164 (EPWM10B)
    EDIS;

    EPwm10Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up
    EPwm10Regs.TBPRD = (CNT_max);   // freq setting
    EPwm10Regs.TBCTL.bit.PHSEN = TB_ENABLE;    // Disable phase loading
    EPwm10Regs.TBPHS.bit.TBPHS = 0;         // Phase is 0
    EPwm10Regs.TBCTL.bit.PRDLD = TB_SHADOW;
    EPwm10Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
    EPwm10Regs.TBCTL.bit.PHSDIR = 0;
    EPwm10Regs.TBCTR = 0x0000;                // Clear counter
    EPwm10Regs.TBCTL.bit.HSPCLKDIV = TB_DIV2; // Clock ratio to SYSCLKOUT/2
    EPwm10Regs.TBCTL.bit.CLKDIV = TB_DIV1; // 20kHz at 3750, 30kHz at 2500

    // Setup shadow register load on ZERO
    EPwm10Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm10Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm10Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
    EPwm10Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    // PWM setting
    EPwm10Regs.CMPA.bit.CMPA = 0;
    EPwm10Regs.CMPB.bit.CMPB = 0; // Set Compare B value

    EPwm10Regs.AQCSFRC.bit.CSFA = 0x01;      // Low output. Continuous Software Force on output A
    EPwm10Regs.AQCSFRC.bit.CSFB = 0x02;      // High output. Continuous Software Force on output A
    EPwm10Regs.AQSFRC.bit.RLDCSF = 0x01;     // Load on event counter equals period

    EPwm10Regs.AQCTLA.bit.CAD = AQ_SET;      // Set PWM1A on Zero
    EPwm10Regs.AQCTLA.bit.CAU = AQ_CLEAR;    // Clear PWM1A on event A, up count
    EPwm10Regs.AQCTLB.bit.CAD = AQ_SET;      // Set PWM1B on Zero
    EPwm10Regs.AQCTLB.bit.CAU = AQ_CLEAR;    // Clear PWM1B on event A, up count


    // Set Dead-time
    EPwm10Regs.DBCTL.bit.IN_MODE = DBA_RED_DBB_FED;  // by moon
    EPwm10Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm10Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;

    EPwm10Regs.DBRED.bit.DBRED = DEADTIME_GAP_inv;
    EPwm10Regs.DBFED.bit.DBFED = DEADTIME_GAP_inv;

    // Disable PWM-chopping function
    EPwm10Regs.PCCTL.bit.CHPEN = 0;


#if 0
    EPwm10Regs.ETSEL.bit.SOCAEN = 0x1;    //Enable EPWMxSOCB pulse
    EPwm10Regs.ETSEL.bit.SOCASEL = 0x001; //Enable evemt to,e=base pimter equal to zero(TBCTR = 0x0000)
    EPwm10Regs.ETPS.bit.SOCACNT = 0x01;   // 1 event has occured
    EPwm10Regs.ETPS.bit.SOCAPRD = 0x01;   //Genetate the EPWMSOCB pulse on the first event

    DRV2_ADC_EPWM_ADCSOCA = DRV2_ADC_EPWM10_ADCSOCA;
#endif

    // Interrupt where we will change the Compare Values
    EPwm10Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO; // Select INT on Zero event
    EPwm10Regs.ETSEL.bit.INTEN = 1;            // Enable INT
    EPwm10Regs.ETPS.bit.INTPRD = ET_1ST;       // Generate INT on 1st event

#if 1
    EALLOW;
    EPwm10Regs.DCTRIPSEL.bit.DCAHCOMPSEL    = 3;    // Digital Compare Trip 입력으로 TRIPIN4를 선택
    EPwm10Regs.TZDCSEL.bit.DCAEVT1          = 1;    // Digital Compare Output A Event 1 생성 조건 설정
                                                    // DCAH = high, DCAL = don't care
//  EPwm10Regs.TZEINT.bit.OST               = 1;    // TZ1, TZ2, TZ3  신호를  EPWM 모듈에 대한 One-Short Trip 입력으로 설정
    EPwm10Regs.TZSEL.bit.DCAEVT1            = 1;    // TZ4( DCAEVT1 ) 신호를  EPWM 모듈에 대한 One-Short Trip 입력으로 설정

//  EPwm10Regs.TZCTL.bit.TZA                = 2;    // Trip 조건 발생 시 EPWM10A 핀 상태 규정 : Forced low
//  EPwm10Regs.TZCTL.bit.TZB                = 2;    // Trip 조건 발생 시 EPWM10B 핀 상태 규정 : Forced low

    EPwm10Regs.TZEINT.bit.DCAEVT1 = 1;  // Enable TZ interrupt
    EPwm10Regs.TZCLR.bit.DCAEVT1 = 1; // Clear Flag for Digital Compare Output A Event 2

//  EPwm10Regs.TZSEL.bit.OSHT1 = TZ_ENABLE;
//  EPwm10Regs.TZSEL.bit.OSHT2 = TZ_ENABLE;
//  EPwm10Regs.TZSEL.bit.OSHT3 = TZ_ENABLE;
    EPwm10Regs.TZSEL.bit.OSHT4 = TZ_ENABLE;
    EDIS;
#endif

}

void Init_ePwm11(void)
{
    EALLOW;
    // Initialize GPIO for ePWM output pin
    /* Enable internal pull-up for the selected pins */
    GpioCtrlRegs.GPFPUD.bit.GPIO165 = 0;    // Enable pull-up on GPIO165 (EPWM11A)
    GpioCtrlRegs.GPFPUD.bit.GPIO166 = 0;    // Enable pull-up on GPIO166 (EPWM11B)
    EDIS;


    EPwm11Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up
    EPwm11Regs.TBPRD = (CNT_max);   // freq setting
    EPwm11Regs.TBCTL.bit.PHSEN = TB_ENABLE;    // Disable phase loading
    EPwm11Regs.TBPHS.bit.TBPHS = 0;         // Phase is 0
    EPwm11Regs.TBCTL.bit.PRDLD = TB_SHADOW;
    EPwm11Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
    EPwm11Regs.TBCTL.bit.PHSDIR = 0;
    EPwm11Regs.TBCTR = 0x0000;                // Clear counter
    EPwm11Regs.TBCTL.bit.HSPCLKDIV = TB_DIV2; // Clock ratio to SYSCLKOUT/2
    EPwm11Regs.TBCTL.bit.CLKDIV = TB_DIV1; // 20kHz at 3750, 30kHz at 2500

    // Setup shadow register load on ZERO
    EPwm11Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm11Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm11Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
    EPwm11Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    // PWM setting
    EPwm11Regs.CMPA.bit.CMPA = 0;
    EPwm11Regs.CMPB.bit.CMPB = 0; // Set Compare B value

    EPwm11Regs.AQCSFRC.bit.CSFA = 0x01;      // Low output. Continuous Software Force on output A
    EPwm11Regs.AQCSFRC.bit.CSFB = 0x02;      // High output. Continuous Software Force on output A
    EPwm11Regs.AQSFRC.bit.RLDCSF = 0x01;     // Load on event counter equals period

    EPwm11Regs.AQCTLA.bit.CAD = AQ_SET;      // Set PWM1A on Zero
    EPwm11Regs.AQCTLA.bit.CAU = AQ_CLEAR;    // Clear PWM1A on event A, up count
    EPwm11Regs.AQCTLB.bit.CAD = AQ_SET;      // Set PWM1B on Zero
    EPwm11Regs.AQCTLB.bit.CAU = AQ_CLEAR;    // Clear PWM1B on event A, up count

    // Set Dead-time
    EPwm11Regs.DBCTL.bit.IN_MODE = DBA_RED_DBB_FED;  // by moon
    EPwm11Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm11Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;

    EPwm11Regs.DBRED.bit.DBRED = DEADTIME_GAP_inv;
    EPwm11Regs.DBFED.bit.DBFED = DEADTIME_GAP_inv;

    // Disable PWM-chopping function
    EPwm11Regs.PCCTL.bit.CHPEN = 0;

#if 0
    EPwm11Regs.ETSEL.bit.SOCAEN = 0x1;    //Enable EPWMxSOCB pulse
    EPwm11Regs.ETSEL.bit.SOCASEL = 0x001; //Enable evemt to,e=base pimter equal to zero(TBCTR = 0x0000)
    EPwm11Regs.ETPS.bit.SOCACNT = 0x01;   // 1 event has occured
    EPwm11Regs.ETPS.bit.SOCAPRD = 0x01;   //Genetate the EPWMSOCB pulse on the first event

    DRV2_ADC_EPWM_ADCSOCA = DRV2_ADC_EPWM11_ADCSOCA;
#endif

    // Interrupt where we will change the Compare Values
    EPwm11Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO; // Select INT on Zero event
    EPwm11Regs.ETSEL.bit.INTEN = 1;            // Enable INT
    EPwm11Regs.ETPS.bit.INTPRD = ET_1ST;       // Generate INT on 1st event

#if 1
    EALLOW;
    EPwm11Regs.DCTRIPSEL.bit.DCAHCOMPSEL    = 3;    // Digital Compare Trip 입력으로 TRIPIN4를 선택
    EPwm11Regs.TZDCSEL.bit.DCAEVT1          = 1;    // Digital Compare Output A Event 1 생성 조건 설정
                                                    // DCAH = high, DCAL = don't care
//  EPwm11Regs.TZEINT.bit.OST               = 1;    // TZ1, TZ2, TZ3  신호를  EPWM 모듈에 대한 One-Short Trip 입력으로 설정
    EPwm11Regs.TZSEL.bit.DCAEVT1            = 1;    // TZ4( DCAEVT1 ) 신호를  EPWM 모듈에 대한 One-Short Trip 입력으로 설정

//  EPwm11Regs.TZCTL.bit.TZA                = 2;    // Trip 조건 발생 시 EPWM11A 핀 상태 규정 : Forced low
//  EPwm11Regs.TZCTL.bit.TZB                = 2;    // Trip 조건 발생 시 EPWM11B 핀 상태 규정 : Forced low

    EPwm11Regs.TZEINT.bit.DCAEVT1 = 1;  // Enable TZ interrupt
    EPwm11Regs.TZCLR.bit.DCAEVT1 = 1; // Clear Flag for Digital Compare Output A Event 2

//  EPwm11Regs.TZSEL.bit.OSHT1 = TZ_ENABLE;
//  EPwm11Regs.TZSEL.bit.OSHT2 = TZ_ENABLE;
//  EPwm11Regs.TZSEL.bit.OSHT3 = TZ_ENABLE;
    EPwm11Regs.TZSEL.bit.OSHT4 = TZ_ENABLE;
    EDIS;
#endif

}

void Init_ePwm12(void)
{

    EALLOW;
    // Initialize GPIO for ePWM output pin
    /* Enable internal pull-up for the selected pins */
    GpioCtrlRegs.GPFPUD.bit.GPIO167 = 0;    // Enable pull-up on GPIO167 (EPWM12A)
    GpioCtrlRegs.GPFPUD.bit.GPIO168 = 0;    // Enable pull-up on GPIO168 (EPWM12B)
    EDIS;

    EPwm12Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up
    EPwm12Regs.TBPRD = (CNT_max);   // freq setting
    EPwm12Regs.TBCTL.bit.PHSEN = TB_ENABLE;    // Disable phase loading
    EPwm12Regs.TBPHS.bit.TBPHS = 0;         // Phase is 0
    EPwm12Regs.TBCTL.bit.PRDLD = TB_SHADOW;
    EPwm12Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
    EPwm12Regs.TBCTL.bit.PHSDIR = 0;
    EPwm12Regs.TBCTR = 0x0000;                // Clear counter
    EPwm12Regs.TBCTL.bit.HSPCLKDIV = TB_DIV2; // Clock ratio to SYSCLKOUT/2
    EPwm12Regs.TBCTL.bit.CLKDIV = TB_DIV1; // 20kHz at 3750, 30kHz at 2500

    // Setup shadow register load on ZERO
    EPwm12Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm12Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm12Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
    EPwm12Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    // PWM setting
    EPwm12Regs.CMPA.bit.CMPA = 0;
    EPwm12Regs.CMPB.bit.CMPB = 0; // Set Compare B value

    EPwm12Regs.AQCSFRC.bit.CSFA = 0x01;      // Low output. Continuous Software Force on output A
    EPwm12Regs.AQCSFRC.bit.CSFB = 0x02;      // High output. Continuous Software Force on output A
    EPwm12Regs.AQSFRC.bit.RLDCSF = 0x01;     // Load on event counter equals period

    EPwm12Regs.AQCTLA.bit.CAD = AQ_SET;      // Set PWM1A on Zero
    EPwm12Regs.AQCTLA.bit.CAU = AQ_CLEAR;    // Clear PWM1A on event A, up count
    EPwm12Regs.AQCTLB.bit.CAD = AQ_SET;      // Set PWM1B on Zero
    EPwm12Regs.AQCTLB.bit.CAU = AQ_CLEAR;    // Clear PWM1B on event A, up count

    // Set Dead-time
    EPwm12Regs.DBCTL.bit.IN_MODE = DBA_RED_DBB_FED;  // by moon
    EPwm12Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm12Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;

    EPwm12Regs.DBRED.bit.DBRED = DEADTIME_GAP_inv;
    EPwm12Regs.DBFED.bit.DBFED = DEADTIME_GAP_inv;

    // Disable PWM-chopping function
    EPwm12Regs.PCCTL.bit.CHPEN = 0;


#if 0
    EPwm12Regs.ETSEL.bit.SOCAEN = 0x1;    //Enable EPWMxSOCB pulse
    EPwm12Regs.ETSEL.bit.SOCASEL = 0x001; //Enable evemt to,e=base pimter equal to zero(TBCTR = 0x0000)
    EPwm12Regs.ETPS.bit.SOCACNT = 0x01;   // 1 event has occured
    EPwm12Regs.ETPS.bit.SOCAPRD = 0x01;   //Genetate the EPWMSOCB pulse on the first event

    DRV2_ADC_EPWM_ADCSOCA = DRV2_ADC_EPWM12_ADCSOCA;
#endif


    // Interrupt where we will change the Compare Values
    EPwm12Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO; // Select INT on Zero event
    EPwm12Regs.ETSEL.bit.INTEN = 1;            // Enable INT
    EPwm12Regs.ETPS.bit.INTPRD = ET_1ST;       // Generate INT on 1st event

#if 1

    EALLOW;
    EPwm12Regs.DCTRIPSEL.bit.DCAHCOMPSEL    = 3;    // Digital Compare Trip 입력으로 TRIPIN4를 선택
    EPwm12Regs.TZDCSEL.bit.DCAEVT1          = 1;    // Digital Compare Output A Event 1 생성 조건 설정
                                                    // DCAH = high, DCAL = don't care
//  EPwm12Regs.TZEINT.bit.OST               = 1;    // TZ1, TZ2, TZ3  신호를  EPWM 모듈에 대한 One-Short Trip 입력으로 설정
    EPwm12Regs.TZSEL.bit.DCAEVT1            = 1;    // TZ4( DCAEVT1 ) 신호를  EPWM 모듈에 대한 One-Short Trip 입력으로 설정

//  EPwm12Regs.TZCTL.bit.TZA                = 2;    // Trip 조건 발생 시 EPWM12A 핀 상태 규정 : Forced low
//  EPwm12Regs.TZCTL.bit.TZB                = 2;    // Trip 조건 발생 시 EPWM12B 핀 상태 규정 : Forced low

    EPwm12Regs.TZEINT.bit.DCAEVT1 = 1;  // Enable TZ interrupt
    EPwm12Regs.TZCLR.bit.DCAEVT1 = 1; // Clear Flag for Digital Compare Output A Event 2

//  EPwm12Regs.TZSEL.bit.OSHT1 = TZ_ENABLE;
//  EPwm12Regs.TZSEL.bit.OSHT2 = TZ_ENABLE;
//  EPwm12Regs.TZSEL.bit.OSHT3 = TZ_ENABLE;
    EPwm12Regs.TZSEL.bit.OSHT4 = TZ_ENABLE;

    EDIS;
#endif
}


//===========================================================================================================
interrupt void epwm1_timer_isr(void)
{

    // Clear INT flag for this timer
    EPwm1Regs.ETCLR.bit.INT = 1;
    // Acknowledge this interrupt to receive more interrupts from group 2
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}
//===========================================================================================================
interrupt void epwm2_timer_isr(void)
{
    // Clear INT flag for this timer
    EPwm2Regs.ETCLR.bit.INT = 1;
    // Acknowledge this interrupt to receive more interrupts from group 2
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}
//===========================================================================================================
interrupt void epwm3_timer_isr(void)
{
    // Clear INT flag for this timer
    EPwm3Regs.ETCLR.bit.INT = 1;
    // Acknowledge this interrupt to receive more interrupts from group 2
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}
//===========================================================================================================
interrupt void epwm4_timer_isr(void)
{

    // Clear INT flag for this timer
    EPwm4Regs.ETCLR.bit.INT = 1;
    // Acknowledge this interrupt to receive more interrupts from group 2
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}
//===========================================================================================================
interrupt void epwm5_timer_isr(void)
{
    // Clear INT flag for this timer
    EPwm5Regs.ETCLR.bit.INT = 1;
    // Acknowledge this interrupt to receive more interrupts from group 2
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}
//===========================================================================================================
interrupt void epwm6_timer_isr(void)
{
    // Clear INT flag for this timer
    EPwm6Regs.ETCLR.bit.INT = 1;
    // Acknowledge this interrupt to receive more interrupts from group 2
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

interrupt void epwm7_timer_isr(void)
{
    // Clear INT flag for this timer
    EPwm7Regs.ETCLR.bit.INT = 1;
    // Acknowledge this interrupt to receive more interrupts from group 2
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

interrupt void epwm8_timer_isr(void)
{
    // Clear INT flag for this timer
    EPwm8Regs.ETCLR.bit.INT = 1;
    // Acknowledge this interrupt to receive more interrupts from group 2
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

interrupt void epwm9_timer_isr(void)
{
    // Clear INT flag for this timer
    EPwm9Regs.ETCLR.bit.INT = 1;
    // Acknowledge this interrupt to receive more interrupts from group 2
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

interrupt void epwm10_timer_isr(void)
{
    // Clear INT flag for this timer
    EPwm10Regs.ETCLR.bit.INT = 1;
    // Acknowledge this interrupt to receive more interrupts from group 2
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

interrupt void epwm11_timer_isr(void)
{
    // Clear INT flag for this timer
    EPwm11Regs.ETCLR.bit.INT = 1;
    // Acknowledge this interrupt to receive more interrupts from group 2
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

interrupt void epwm12_timer_isr(void)
{
    // Clear INT flag for this timer
    EPwm12Regs.ETCLR.bit.INT = 1;
    // Acknowledge this interrupt to receive more interrupts from group 2
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}


interrupt void epwm1_tz1_isr(void)
{
    EPwm1_TZ1_IntCount++;

    Fault_EPWM1_TZ1 |=  EPwm1Regs.TZOSTFLG.all;
    Fault_TZ        |= Fault_EPWM1_TZ1;

    Fault_HW    |= 0x1000;

    fault_HW_check();

    inv_fault();    // Fault.c

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
}


interrupt void epwm2_tz1_isr(void)
{
    EPwm2_TZ1_IntCount++;

    Fault_EPWM2_TZ1 |=  EPwm2Regs.TZOSTFLG.all;
    Fault_TZ        |= Fault_EPWM2_TZ1;

    Fault_HW    |= 0x1000;

    fault_HW_check();

    inv_fault();    // Fault.c

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
}


interrupt void epwm3_tz1_isr(void)
{
    EPwm3_TZ1_IntCount++;

    Fault_EPWM3_TZ1 |=  EPwm3Regs.TZOSTFLG.all;
    Fault_TZ        |= Fault_EPWM3_TZ1;

    Fault_HW    |= 0x1000;

    fault_HW_check();

    inv_fault();    // Fault.c

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
}


interrupt void epwm4_tz2_isr(void)
{
    EPwm4_TZ2_IntCount++;

    Fault_EPWM4_TZ2 |=  EPwm4Regs.TZOSTFLG.all;
    Fault_TZ        |= Fault_EPWM4_TZ2;

    Fault_HW    |= 0x2000;

    fault_HW_check();

    inv_fault();    // Fault.c

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
}


interrupt void epwm5_tz2_isr(void)
{
    EPwm5_TZ2_IntCount++;

    Fault_EPWM5_TZ2 |=  EPwm5Regs.TZOSTFLG.all;
    Fault_TZ        |= Fault_EPWM5_TZ2;

    Fault_HW    |= 0x2000;

    fault_HW_check();

    inv_fault();    // Fault.c

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
}


interrupt void epwm6_tz2_isr(void)
{
    EPwm6_TZ2_IntCount++;

    Fault_EPWM6_TZ2 |=  EPwm6Regs.TZOSTFLG.all;
    Fault_TZ        |= Fault_EPWM6_TZ2;

    Fault_HW    |= 0x2000;

    fault_HW_check();

    inv_fault();    // Fault.c

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
}


interrupt void epwm7_tz3_isr(void)
{
    EPwm7_TZ3_IntCount++;

    Fault_EPWM7_TZ3 |=  EPwm7Regs.TZOSTFLG.all;
    Fault_TZ        |= Fault_EPWM7_TZ3;

    Fault_HW    |= 0x4000;

    fault_HW_check();

    inv_fault();    // Fault.c

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
}


interrupt void epwm8_tz3_isr(void)
{
    EPwm8_TZ3_IntCount++;

    Fault_EPWM8_TZ3 |=  EPwm8Regs.TZOSTFLG.all;
    Fault_TZ        |= Fault_EPWM8_TZ3;

    Fault_HW    |= 0x4000;

    fault_HW_check();

    inv_fault();    // Fault.c

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
}


interrupt void epwm9_tz3_isr(void)
{
    EPwm9_TZ3_IntCount++;

    Fault_EPWM9_TZ3 |=  EPwm9Regs.TZOSTFLG.all;
    Fault_TZ        |= Fault_EPWM9_TZ3;

    Fault_HW    |= 0x4000;

    fault_HW_check();

    inv_fault();    // Fault.c

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
}


interrupt void epwm10_tz4_isr(void)
{
    EPwm10_TZ4_IntCount++;

    Fault_EPWM10_TZ4 |=  EPwm10Regs.TZOSTFLG.all;
    Fault_TZ         |= Fault_EPWM10_TZ4;

    Fault_HW    |= 0x8000;

    fault_HW_check();

    inv_fault();    // Fault.c

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
}


interrupt void epwm11_tz4_isr(void)
{
    EPwm11_TZ4_IntCount++;

    Fault_EPWM11_TZ4 |=  EPwm11Regs.TZOSTFLG.all;
    Fault_TZ         |= Fault_EPWM11_TZ4;

    Fault_HW    |= 0x8000;

    fault_HW_check();

    inv_fault();    // Fault.c

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
}


interrupt void epwm12_tz4_isr(void)
{
    EPwm12_TZ4_IntCount++;

    Fault_EPWM11_TZ4 |=  EPwm11Regs.TZOSTFLG.all;
    Fault_TZ         |= Fault_EPWM11_TZ4;

    Fault_HW    |= 0x8000;

    fault_HW_check();

    inv_fault();    // Fault.c

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
}
