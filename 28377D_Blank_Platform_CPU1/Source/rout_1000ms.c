//###############################################################################################################
// 파일명      : rout_1000ms.c
// 회사명      : G-Philos
// 작성날짜  : 2020.12.17
// 작성자      : KYJ-PC
// 수정날짜  : 2021.01.04
// 수정자      : Lee Sang Cheol
// 설명         : 1000ms routine
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
    // 1. 빌드 및 예뮬레이터 연결 후 다운로딩
    // 2. wr_time.Wr_flag = 1 ("1" 값을 확인만 하면 됩니다.)
    // 3. wr_time.Set_year =2010 -> 실제년도를 입력하시오.
    // 4. wr_time.Set_mon_day = 1231 -> 실제달월을 입력하시오.
    // 5. wr_time.Set_hour_min = 2359 -> 실제시간분을 입력하시오.
    // 6. wr_time.Set_sec = 55 -> 실제초을 입력하시오.
    // 7. wr_time.Sel_Wr = 0 -> 1 (변경하면 RTC 시간값이 업데이트 됨.)
    // 8. time.Read_year = "실제 년도와 동일한지 확인만 하면 됨."
    // 9. time.Read_mon_day = "실제 달일이 동일한지 확인만 하면 됨."
    // 10. time.Read_hour_min = "실제 시간분이 동일한지 확인만 하면 됨."
    // 11. time.Read_sec = "실제 초가 동일한지 확인만 하면 됨."

    //I2C통신은 RTC or EEPROM 둘 중 하나만 진행해야 함.
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
