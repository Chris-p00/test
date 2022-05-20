//###############################################################################################################
// 파일명      : download.c
// 회사명      : G-Philos
// 작성날짜  : 2021.05.24
// 작성자      : LSC-PC
// 수정날짜  : 2021.05.24
// 수정자      : Lee Sang Cheol
// 설명         : Program download seq Define
//###############################################################################################################

#include "Define.h"

void Bl_Shutdown()
{
// 운전 정지 & 안전상태 동작 코드
    // 0 : init, 0x77 : download run, 0x88 : download run check
    if(download_check == 0x77)
    {
        //dwonload run program cpu2 run start time : 1s 이내
        control_power_check_flag    = 1;
        download_check = 0x88;
        System_fault = 1;
//        Fault_HW    |= 0x0800;  // download run, check event error define
//    System_fault = 0 (NORMAL = download run : no), 1 (FAULT = download run : ok)
    }
}
