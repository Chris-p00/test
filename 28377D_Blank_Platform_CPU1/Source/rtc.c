//###############################################################################################################
// 파일명      : RTC.c
// 회사명      : G-Philos
// 작성날짜  : 2020.12.17
// 작성자      : LSC
// 수정날짜  : 2021.02.03
// 수정자      : Lee Sang Cheol
// 설명         : RTC 구동에 필요한 I2C 관련 함수 구현
//###############################################################################################################


#include "Define.h"


/*--------------------------------------*/
/*  call I2C_RTC_init2()                 */
/*--------------------------------------*/
void I2C_RTC_init2(void) {
    //초기화 Write_RX8025_Data(0x0E, 0x20);   ===>24시모드 0x20   12시모드 =>0x00  참고하세윰~~!
//
    int int_a,int_b,int_c,int_d;
//    int int_a,int_b,int_c;
    int hex_a,hex_b,hex_c,hex_d;
    int temp;

    rtc_write_data2[0]=(((int)((float)wr_time_Set_sec*0.1)&0x0f)<<4)|(wr_time_Set_sec&0x0f);


    temp=wr_time_Set_hour_min;
    int_a=(int)((float)temp*0.001)*1000;
    hex_a=((    ((int)((float)temp*0.001))  &0x0f)<<4);

    temp=temp-int_a;
    int_b=(int)((float)temp*0.01)*100;
    hex_b=( ((int)((float)temp*0.01))   &0x0f);

    temp=temp-int_b;
    int_c=(int)((float)temp*0.1)*10;
    hex_c=((    ((int)((float)temp*0.1))    &0x0f)<<4);

    temp=temp-int_c;
    int_d=(int)temp;
    hex_d=(int)temp &0x0f;

    rtc_write_data2[1]=(hex_c+hex_d);
    rtc_write_data2[2]=(hex_a+hex_b);

    temp=wr_time_Set_mon_day;
    int_a=(int)((float)temp*0.001)*1000;
    hex_a=((    ((int)((float)temp*0.001))  &0x0f)<<4);

    temp=temp-int_a;
    int_b=(int)((float)temp*0.01)*100;
    hex_b=( ((int)((float)temp*0.01))   &0x0f);

    temp=temp-int_b;
    int_c=(int)((float)temp*0.1)*10;
    hex_c=((    ((int)((float)temp*0.1))    &0x0f)<<4);

    temp=temp-int_c;
    int_d=(int)temp;
    hex_d=(int)temp &0x0f;

    rtc_write_data2[3]=(hex_c+hex_d);
    rtc_write_data2[4]=(hex_a+hex_b);


    temp=wr_time_Set_year;
    int_a=(int)((float)temp*0.001)*1000;
    hex_a=((    ((int)((float)temp*0.001))  &0x0f)<<4);

    temp=temp-int_a;
    int_b=(int)((float)temp*0.01)*100;
    hex_b=( ((int)((float)temp*0.01))   &0x0f);

    temp=temp-int_b;
    int_c=(int)((float)temp*0.1)*10;
    hex_c=((    ((int)((float)temp*0.1))    &0x0f)<<4);

    temp=temp-int_c;
    int_d=(int)temp;
    hex_d=(int)temp &0x0f;

    rtc_write_data2[5]=(hex_c+hex_d);
    //rtc_write_data[6]=(hex_a+hex_b);

    Write_RX8025_Data2(0x0e, 0x20);  //  24 hour_mode

    eep_write_data=(BYTE)(rtc_write_data2[0] & 0xff);    Write_RX8025_Data2(0x00, eep_write_data);
    eep_write_data=(BYTE)(rtc_write_data2[1] & 0xff);    Write_RX8025_Data2(0x01, eep_write_data);
    eep_write_data=(BYTE)(rtc_write_data2[2] & 0xff);    Write_RX8025_Data2(0x02, eep_write_data);
    eep_write_data=(BYTE)(rtc_write_data2[3] & 0xff);    Write_RX8025_Data2(0x04, eep_write_data);
    eep_write_data=(BYTE)(rtc_write_data2[4] & 0xff);    Write_RX8025_Data2(0x05, eep_write_data);
    eep_write_data=(BYTE)(rtc_write_data2[5] & 0xff);    Write_RX8025_Data2(0x06, eep_write_data);
}

void Write_RX8025_Data2(BYTE addr, BYTE data)
{
    WORD slave_addr, data_addr;
    int temp=0;

    slave_addr = 0x32;
    data_addr = ((addr << 4) & 0xf0);

    // Wait until the STP bit is cleared from any previous master communication.
    for(temp=0;temp<100;temp++) {       //  3/6=0.5
        if(I2cbRegs.I2CMDR.bit.STP == 0)    break;

    }

    // Wait until bus-free status
    for(temp=0;temp<10;temp++)  {
        if(I2cbRegs.I2CSTR.bit.BB == 0) break;

    }

    // Set Device(Slave) Address
    I2cbRegs.I2CSAR.all = slave_addr;

    // Setup number of bytes to send
    I2cbRegs.I2CCNT = 2;

    // Setup data to send
    I2cbRegs.I2CDXR.all = data_addr; // Data Address
    I2cbRegs.I2CDXR.all = data;      // Write Data

    // Send start as master transmitter with STT(=1), STP(=1), XA(=0), RM(=0)
    I2cbRegs.I2CMDR.all = 0x6E20;

    // Wait until STOP condition is detected and clear STOP condition bit
    for(temp=0;temp<300;temp++) {       //  328/6=55
        if(I2cbRegs.I2CSTR.bit.SCD == 1)    break;

    }
    I2cbRegs.I2CSTR.bit.SCD = 1;

    // Wait the Write-Cycle Time for RX8025SA
}

