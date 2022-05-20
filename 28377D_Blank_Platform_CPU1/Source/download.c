//###############################################################################################################
// ���ϸ�      : download.c
// ȸ���      : G-Philos
// �ۼ���¥  : 2021.05.24
// �ۼ���      : LSC-PC
// ������¥  : 2021.05.24
// ������      : Lee Sang Cheol
// ����         : Program download seq Define
//###############################################################################################################

#include "Define.h"

void Bl_Shutdown()
{
// ���� ���� & �������� ���� �ڵ�
    // 0 : init, 0x77 : download run, 0x88 : download run check
    if(download_check == 0x77)
    {
        //dwonload run program cpu2 run start time : 1s �̳�
        control_power_check_flag    = 1;
        download_check = 0x88;
        System_fault = 1;
//        Fault_HW    |= 0x0800;  // download run, check event error define
//    System_fault = 0 (NORMAL = download run : no), 1 (FAULT = download run : ok)
    }
}
