//###############################################################################################################
// 파일명      : main_cpu1.c
// 회사명      : G-Philos
// 작성날짜  : 2020.12.17
// 작성자      : KYJ-PC
// 수정날짜  : 2021.01.04
// 수정자      : Lee Sang Cheol
// 설명         : GPIO Input/Output Define
//###############################################################################################################

#include "Define.h"
float Sum_Arr_Float(float * arr,  int arrsize,  int index);
float test_f[10] = {0,0,0,0,0,0,0,0,}, testfresult;

int main(void)
{
    DINT;
    IER = 0x0000;
    IFR = 0x0000;

    testfresult = Sum_Arr_Float(test_f,F_SIZE(test_f), ALL);
    // Step 1. Initialize EEPROM, DAC Variables:
    // 아래 serial_code_init()는 아래 Flash 를 통하여 초기 때 data_ptr[]에 초기값을 write하므로
    // 항상 Flash Write하는 코드보다 위에 존재해야 한다. 그렇지 않으면 data_ptr[]의 포인터를
    // 제대로 참조할 수 없기 때문에 Flash ROM에 쓰레기 값이 Write된다.
    // define review need, 디버깅이 안됨.
/*****************************************************************************************************/
// check #1 : redefine need
    serial_code_init();  // 28335 function #4 // initialize serial-comm. code
/*****************************************************************************************************/

    // Step 2. Initialize Variables:
//  variables_init();     // 28335 function #5
    Init_Variables();

    // Step 3. Initialize System Control:
    // WatchDog(DisableDog), Initialize External Interface, serial_code_init
    // memcpy, InitFlash, PLL, enable Peripheral Clocks
    // FLASH Code Copy and Initialize setting
    // Copy time critical code and Flash setup code to RAM
    // The  RamfuncsLoadStart, RamfuncsLoadEnd, and RamfuncsRunStart
    // symbols are created by the linker. Refer to the FLASH.cmd file.
//  InitSysCtrl();        // 28335 function #1
//  Init_Ext_Bus();       // 28335 function #3
//  MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);   // 28335 function #8
//  InitFlash();    // 28335 function #9
    InitSysCtrl();  //no check -> 28377D define add check need

    // Step 4. Clear all interrupts and initialize PIE vector table:
    // Disable CPU interrupts
    // Initialize the PIE control registers to their default state.
    // The default state is all PIE interrupts disabled and flags
    // are cleared.
//  InitPieCtrl();        // 28335 function #6
    InitPieCtrl();  //no check -> 28377D define add check need

    // Step 5. Initialize PieVectTable:
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    // This will populate the entire table, even if the interrupt
    // is not used in this example.  This is useful for debug purposes.
//  InitPieVectTable();     // 28335 function #7
    InitPieVectTable();

    // Step 6. Initialize GPIO:
//  Init_system_Gpio(); // 28335 function #2
    InitGpio();       //no check -> 28377D define add check need

    // Step 7. Enable Interrupts:
    // Enables the PIE module and CPU interrupts and global Interrupt INTM
//    EnableInterrupts(); // 28335 function #17
    EnableInterrupts();

    // Step 8. Initalize Function:
    // Step 8. 1a SCI Initalize Function:
//    scia_init();        // 28335 function #14
    Init_Scia();      //black box define -> add check need

    // Step 8. 1b SCI Initalize Function:
//    scib_init();         // 28335 function #15  // RS485 MMI Communication Init Func.
    Init_Scib();
#if (0)
    EALLOW;
    DevCfgRegs.CPUSEL5.bit.SCI_B = 1;
    GPIO_SetupPinMux(138, GPIO_MUX_CPU2, 6);              //SCI_B_RX (MUX6)
    GPIO_SetupPinOptions(138, GPIO_INPUT, GPIO_PULLUP);   //SCI_B_RX (MUX6)
    GPIO_SetupPinMux(137, GPIO_MUX_CPU2, 6);              //SCI_B_TX (MUX6)
    GPIO_SetupPinOptions(137, GPIO_OUTPUT, GPIO_ASYNC);   //SCI_B_TX (MUX6)
    GPIO_SetupPinMux(134, GPIO_MUX_CPU2, 0);
    GPIO_SetupPinOptions(134, GPIO_OUTPUT, GPIO_PUSHPULL);
    EDIS;
#endif
    // Step 8. 1c SCI Initalize Function:
    Init_Scic();

    // Step 8. 1d SCI Initalize Function:
    Init_Scid();

    // Step 8. 2 PWM Initalize Function:
//    Init_ePwm();      // 28335 function #16
    Init_Epwm();

    // Step 8. 3 ADC Initalize Function:
//    Init_Adc_Mode();     // 28335 function #10  // AD 16 Channel Init Func.
    Init_Adc(SET_16BIT, SET_12BIT, SET_12BIT, SET_12BIT);

    // Step 8. 4 SDRAM Initalize Function:
    Init_Sdram();

    // Step 8. 5 DIDO Initalize Function:
    Init_Dido();

    // Step 8. 6 I2C RTC Initalize Function:
    Init_Rtc();

    // Step 8. 7 I2C EEPROM Initalize Function:
//    Init_I2C_eeprom();   // 28335 function #11  // I2C Bus Init Func.
    Init_I2c_Eeprom();

    // Step 9. Bloack Box Initalize Function:
#ifdef _BLACKBOX
//    Init_Spi_Dac();      // 28335 function #12  // DA 4 Channel Init Func.- A/D 5327BRUZ
//    init_can();          // 28335 function #13  // eCAN A,B Init Func.
    Flag_scia_cpu1_cpu2 = 2.0;
    init_blackbox.after_period = 1 * S;
    init_blackbox.total_period = 2 * S;
//  init_blackbox.ctrl_period = 50 * US;
    init_blackbox.ctrl_period = Tsamp;

    Permit_Blackbox();
    Set_List();
    Use_List();
    BB_List_ctrl_select();

    EALLOW;
    DevCfgRegs.CPUSEL5.bit.SCI_B = 1;
    //DevCfgRegs.CPUSEL5.bit.SCI_D = 1;
    GpioCtrlRegs.GPECSEL1.bit.GPIO134 = 2;
    GPIO_SetupPinMux(101, GPIO_MUX_CPU1, 0);
    GPIO_SetupPinOptions(101, GPIO_OUTPUT, GPIO_PUSHPULL);
    GPIO_SetupPinMux(102, GPIO_MUX_CPU1, 0);
    GPIO_SetupPinOptions(102, GPIO_OUTPUT, GPIO_PUSHPULL);
    GPIO_SetupPinMux(103, GPIO_MUX_CPU1, 0);
    GPIO_SetupPinOptions(103, GPIO_OUTPUT, GPIO_PUSHPULL);

    GpioCtrlRegs.GPDCSEL1.bit.GPIO101 = 2;
    GpioCtrlRegs.GPDCSEL1.bit.GPIO102 = 2;
    GpioCtrlRegs.GPDCSEL1.bit.GPIO103 = 2;
    EDIS;

    //IPC
    if( CpuSysRegs.RESC.bit.TRSTn_pin_status == 1 )
    {
        IpcRegs.IPCACK.all = 0xFFFFFFFF;
        IpcRegs.IPCCLR.all = 0xFFFFFFFF;
    }
    else
    {
        GpioDataRegs.GPADAT.bit.GPIO24 = 0;
        IPCBootCPU2(C1C2_BROM_BOOTMODE_BOOT_FROM_FLASH);
    }

    //Waiting CPU2 boot.
    Check_Start_Flag();

    unique_id = *(unsigned long *)0x703CC;
    Read_EEPROM_Data(0x654, &device_id);
#endif

/*****************************************************************************************************/
// check #1 : redefine need
// lsc_step 1 EEPROM init
// 1. 주석처리: Read_EEPROM_code();
// 2. 빌드 및 예뮬레이터 연결 후 다운로딩 (Eum_enable = 1)
// 3. Enable_EEPROM_write = 1 후 0으로 변경되는 것을 확인.
// 4. 예뮬레이터 연결 제거.
// 5. 주석해제: Read_EEPROM_code();
// 6. 빌드 및 예뮬레이터 연결 후 다운로딩 (Eum_enable = 0)
// 7. code_rw1.c -> 401~500 번지 변수 명, 초기값, 설정값, 최대값, 최소값 정의 확인
    Read_EEPROM_code(); // 28335 function #18
/*****************************************************************************************************/

    scia_com_setting();

    Flag_scia_cpu1_cpu2 = 2.0;
    //--------------------------------------------------------------------------------------------
    // time loop
    while (TRUE)
    {
        m_cnt++;

        if ( (Flag_offset == 2) && (Cnt_offset_wait <= 0) )
        {
            Cnt_offset_wait = Set_offset_wait;
            Flag_offset     = 3;
        }

        if (Flag_T_250us == TRUE)
        { // 250us routine
            rout_250us();   Flag_T_250us = 0;

            if (Flag_T_500us == TRUE)
            { // 500us routine
                rout_500us();   Flag_T_500us = 0;

                if (Flag_T_1ms == TRUE)
                { // 1ms routine
                    rout_1ms();     Flag_T_1ms = 0;

                    if (Flag_T_2ms == TRUE)
                    { // 2ms routine
                        rout_2ms();     Flag_T_2ms = 0;

                        if (Flag_T_10ms == TRUE)
                        { // 10ms routine
                            rout_10ms();    Flag_T_10ms = 0;

                            if (Flag_T_100ms == TRUE)
                            { // 100ms routine
                                rout_100ms();   Flag_T_100ms = 0;

                                if (Flag_T_500ms == TRUE)
                                { // 500ms routine
                                    rout_500ms();   Flag_T_500ms = 0;

                                    if (Flag_T_1000ms == TRUE)
                                    { // 1000ms routine
                                        rout_1000ms();  Flag_T_1000ms = 0;

                                        //operation check
                                        if(time_check_cnt == 100) LED_1_TOGGLE;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    //--------------------------------------------------------------------------------------------
}
