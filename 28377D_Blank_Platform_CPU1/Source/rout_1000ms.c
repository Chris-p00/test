//###############################################################################################################
// ���ϸ�      : rout_1000ms.c
// ȸ���      : G-Philos
// �ۼ���¥  : 2020.12.17
// �ۼ���      : KYJ-PC
// ������¥  : 2021.01.04
// ������      : Lee Sang Cheol
// ����         : 1000ms routine
//###############################################################################################################

#include "Define.h"
BYTE r_datasuc = 0;
void rout_1000ms()
{
    if(time_check_cnt == 10)   LED1_ON;

	rout_1000ms_count++;

	if(rout_1000ms_count > 1000)
	{
		rout_1000ms_count = 0;
	}

    if(Flag_charge == 1)
    {
//      Run_TOGGLE;
//        DO_7_TOGGLE;        //Flag_Ready = FC Power on
   }
    else
    {
        DO_7_OFF;           //Flag_Ready = FC Power off
    }

/*------------------------------------------*/
/*  scia_com_init                           */
/*------------------------------------------*/
    scia_com_setting();


/*------------------------------------------*/
/*  scib_com_init                           */
/*------------------------------------------*/
    scib_com_init();

/* R/W RTC
 * Read : Update struct 'time' from rtc.lib
 * Write: Reflect struct 'wr_time' from rtc.lib
 */
    // lsc_step 2 RTC Test
    // * RTC setting
    // 1. ���� �� ���ķ����� ���� �� �ٿ�ε�
    // 2. wr_time.Wr_flag = 1 ("1" ���� Ȯ�θ� �ϸ� �˴ϴ�.)
    // 3. wr_time.Set_year =2010 -> �����⵵�� �Է��Ͻÿ�.
    // 4. wr_time.Set_mon_day = 1231 -> �����޿��� �Է��Ͻÿ�.
    // 5. wr_time.Set_hour_min = 2359 -> �����ð����� �Է��Ͻÿ�.
    // 6. wr_time.Set_sec = 55 -> �������� �Է��Ͻÿ�.
    // 7. wr_time.Sel_Wr = 0 -> 1 (�����ϸ� RTC �ð����� ������Ʈ ��.)
    // 8. time.Read_year = "���� �⵵�� �������� Ȯ�θ� �ϸ� ��."
    // 9. time.Read_mon_day = "���� ������ �������� Ȯ�θ� �ϸ� ��."
    // 10. time.Read_hour_min = "���� �ð����� �������� Ȯ�θ� �ϸ� ��."
    // 11. time.Read_sec = "���� �ʰ� �������� Ȯ�θ� �ϸ� ��."

    //I2C����� RTC or EEPROM �� �� �ϳ��� �����ؾ� ��.
    if((Enable_EEPROM_write==0)||(Enable_EEPROM_write2==0))
    {
//        wr_time.Sel_Wr      = (int)(wr_time_Sel_Wr);
//        wr_time.Set_year    = (int)(wr_time_Set_year);
//        wr_time.Set_mon_day = (int)(wr_time_Set_mon_day);
//        wr_time.Set_hour_min= (int)(wr_time_Set_hour_min);
//        wr_time.Set_sec     = (int)(wr_time_Set_sec);

        if(wr_time_Sel_Wr==1)
        {
            I2C_RTC_init2();
            wr_time_Sel_Wr=0;
        }
        else
        {
            Rw_Rtc();
//            time_Read_year      = (int)(time.Read_year);
//            time_Read_mon_day   = (int)(time.Read_mon_day);
//            time_Read_hour_min  = (int)(time.Read_hour_min);
//            time_Read_sec       = (int)(time.Read_sec);
        }
    }

    if(time_check_cnt == 10)   LED1_OFF;

}
