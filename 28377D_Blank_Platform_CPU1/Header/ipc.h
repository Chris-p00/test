#ifndef HEADER_IPC_H_
#define HEADER_IPC_H_


#include "F28x_Project.h"
#include "F2837xD_Ipc_drivers.h"
#include "fatfs/src/integer.h"


#define LED1_ON                  GpioDataRegs.GPEDAT.bit.GPIO143 = 0;
#define LED1_OFF                 GpioDataRegs.GPEDAT.bit.GPIO143 = 1;

#define TG_ENB 0
#define TG_DIS 1

//EDIT CMD//
//***CAUTION*****
//it's also used to sci.c(28377D_Blackbox_CPU2).Therefore if it has been changed
//please reflect there too.

//Read & Write mode
#define EDIT_RMODE           1
#define EDIT_WMODE           0

//Whether the cmd was successful or not.
#define EDIT_DONE            1
#define EDIT_NDONE           0

//Edit for what.
#define EDIT_CPU1M           0
#define EDIT_CPU2M           1
#define EDIT_SCIA            2
#define EDIT_SCIB            3
#define EDIT_SCIC            4
#define EDIT_SCID            5
#define EDIT_I2CA            6

#define BUF_CTRL_MAX        (50)


typedef struct
{
    float32 total_period;
    float32 after_period;
    float32 ctrl_period;
}
Init_Blackbox;

typedef struct
{
    float32 data_ctrl[BUF_CTRL_MAX];
    Uint16 fault_bb;
    Uint16 fault_dac;
}
Send_Blackbox_Data;

typedef struct
{
    float32 t_ctrl[BUF_CTRL_MAX];
}
Time_Data;


typedef struct
{
    unsigned int  ch;
    unsigned long addr;
    unsigned int  data;
    unsigned int  dir;
    unsigned int result;

}
Edit_Addr;


extern Init_Blackbox init_blackbox;
extern Send_Blackbox_Data ipc_data;
extern Time_Data data;
extern Edit_Addr edit_addr_1;
extern Edit_Addr edit_addr_2;
extern unsigned char device_id;
extern unsigned long all_log_status, unique_id;
extern unsigned int start_flag_c1, start_flag_c2;
extern BYTE a,b,c,d;
void Get_Scipermisson_fromcpu2();
void Send_Ipc_Ctrl_Period(float *data_ctrl);
void Send_Initial_Clock_Train_Cpu2 (void);
void power_on_cpu2 (void);
void Permit_Blackbox();
void BB_Send_Flag(char trg1, char trg2);
void Check_bootloader_wake();
void Send_Complete_Cpu2(Edit_Addr* edit_info);
void Send_Task_Cpu2(Edit_Addr* edit_info);
void Check_Start_Flag();
void Check_Log_Eeprom();
void Get_Edit_Addr_Info();

extern void user_reg_service(Edit_Addr *);

#endif
