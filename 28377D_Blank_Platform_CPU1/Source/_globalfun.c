//###############################################################################################################
// 파일명      : _globalfun.c
// 회사명      : G-Philos
// 작성날짜  : 2020.12.17
// 작성자      : KYJ-PC
// 수정날짜  : 2021.01.04
// 수정자      : Lee Sang Cheol
// 설명         : I2C(EEPROM), SPI(DAC) 통신용 메모리 공간 할당
//###############################################################################################################

#include "Define.h"


void serial_code_init()
{
    int i = 0;

    //3000EA data define
    for(i = 0; i < DATA_PTR_MAX; i++)        data_ptr[i] = &dummy;

    //1000EA data define
    //500EA data EEPROM write define : 401 ~ 500 data EEPROM setting
    init_code_rw1();                    /* Float-type   Read/Write  (1-500)     */

    //500EA data EEPROM write define : 501 ~ 700 data EEPROM setting
    init_code_rw2();                    /* Integer-type Read/Write  (501-1000)  */

    //2000EA data define : not used (DAC check = CPU2)
    init_code_r11();                    /* Float-type   only Read   (1001-1500) */
    init_code_r12();                    /* Float-type   only Read   (1501-2000) */
    init_code_r21();                    /* Integer-type only Read   (2001-2500) */
    init_code_r22();                    /* Integer-type only Read   (2501-3000) */
}


void Read_EEPROM_code()
{

    //  SIZE_EEPROM_CODE=300
    //  INIT_EEPROM_CODE=401
    // 401 ~ 700    Read_EEPROM

    float   *temp;

    for(Ptr_code_EEPROM = 0 ; Ptr_code_EEPROM < SIZE_EEPROM_CODE ; Ptr_code_EEPROM++)
    {   // from FRAM

        Read_EEPROM_Data((Ptr_code_EEPROM*4)+0, &eep_read_data);
        b2w.bycode.by0  = eep_read_data;
        Read_EEPROM_Data((Ptr_code_EEPROM*4)+1, &eep_read_data);
        b2w.bycode.by1  = eep_read_data;
        Read_EEPROM_Data((Ptr_code_EEPROM*4)+2, &eep_read_data);
        b2w.bycode.by2  = eep_read_data;
        Wait_cnt[0] = Wait_cnt[1]   = Wait_cnt[2]   = Wait_cnt[3]   = Wait_cnt[4]   = 0;
        Read_EEPROM_Data((Ptr_code_EEPROM*4)+3, &eep_read_data);
        b2w.bycode.by3  = eep_read_data;

        temp    = data_ptr[Ptr_code_EEPROM  + INIT_EEPROM_CODE];
        *temp=b2w.w;
    }

    Ptr_code_EEPROM = 0;

    if(Err_EEPROM   != 0)
    {
        Fault_SW    |= SFT_write_EEPROM;
        //Flag_Read_eeprom = 1;
    }
}


void Write_EEPROM_code()
{                          // 10m routine

    //  SIZE_EEPROM_CODE1=100
    //  INIT_EEPROM_CODE1=401
    // 401 ~ 500

    int     temp_addr=0;
//  float   *temp, aa;
    float   *temp;

    //  SIZE_EEPROM_CODE1=100
    //  INIT_EEPROM_CODE1=401
    // 401 ~ 500
    if(Enable_EEPROM_write  == 1)
    {
        if(Ptr_code_EEPROM < SIZE_EEPROM_CODE1)
        {   // now writing
            temp_addr   = Ptr_code_EEPROM   + INIT_EEPROM_CODE1;
            temp        = data_ptr[temp_addr];
//          w2b.w   = aa    = *temp;
            w2b.w   = *temp;

            switch(Ptr_byte)
            {
                case 0: b2w.bycode.by0  = eep_write_data    = w2b.bycode.by0;   break;
                case 1: b2w.bycode.by1  = eep_write_data    = w2b.bycode.by1;   break;
                case 2: b2w.bycode.by2  = eep_write_data    = w2b.bycode.by2;   break;
                case 3: b2w.bycode.by3  = eep_write_data    = w2b.bycode.by3;   break;
                default: break;
            }

            eep_addr    = (Ptr_code_EEPROM  * 4)    + Ptr_byte;
            Write_EEPROM_Data(eep_addr, (BYTE)(eep_write_data & 0xff));
            Ptr_byte++;

            if(Ptr_byte==4)
            {
//              aa  = b2w.w;
                Ptr_code_EEPROM++;
                Ptr_byte    = 0;
            }
            if(Err_EEPROM != 0)
            {
                Fault_SW    |= SFT_write_EEPROM;
                Enable_EEPROM_write = 0;
            }
        }
        else
        {
            Enable_EEPROM_write = 0;
            Ptr_code_EEPROM     = 0; //Edit KSC
        }
        Flag_EEPROM_init_cnt    = 0;
    }

    //  SIZE_EEPROM_CODE2=200
    //  INIT_EEPROM_CODE2=501
    // 501 ~ 700
    else if(Enable_EEPROM_write2==1)
    {
        if(Ptr_code_EEPROM2 < SIZE_EEPROM_CODE2)
        {   // now writing
            temp_addr   = Ptr_code_EEPROM2  + INIT_EEPROM_CODE2;
            temp        = data_ptr[temp_addr];
//          w2b.w   = aa    = *temp;
            w2b.w   = *temp;

            switch(Ptr_byte)
            {
                case 0: b2w.bycode.by0  = eep_write_data    = w2b.bycode.by0;   break;
                case 1: b2w.bycode.by1  = eep_write_data    = w2b.bycode.by1;   break;
                case 2: b2w.bycode.by2  = eep_write_data    = w2b.bycode.by2;   break;
                case 3: b2w.bycode.by3  = eep_write_data    = w2b.bycode.by3;   break;
                default: break;
            }

            eep_addr    = ((Ptr_code_EEPROM2    + SIZE_EEPROM_CODE1)    * 4)    + Ptr_byte;
            Write_EEPROM_Data(eep_addr, (BYTE)(eep_write_data & 0xff));
            Ptr_byte++;

            if(Ptr_byte == 4)
            {
//              aa  = b2w.w;
                Ptr_code_EEPROM2++;
                Ptr_byte    = 0;
            }
            if(Err_EEPROM != 0)
            {
                Fault_SW    |= SFT_write_EEPROM;
                Enable_EEPROM_write2    = 0;
            }
        }
        else
        {
            Enable_EEPROM_write2    = 0;
//          Ptr_code_EEPROM2        = 120;   //Edit KSC
            Ptr_code_EEPROM2        = 0; //Edit KSC
        }
        Flag_EEPROM_init_cnt    = 0;
    }
}

