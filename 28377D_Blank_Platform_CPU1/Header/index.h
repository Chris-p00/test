#ifndef HEADER_INDEX_H_
#define HEADER_INDEX_H_

#include "ipc.h"
#include "string.h"
#define CTRL_POS        0
#define MATCH(cnt, v, n)    list[cnt] = &v; index_bb[cnt + 1] = index_bb[cnt] + strnpack(name_bb, index_bb[cnt], n, strlen(n));
#define XMATCH(cnt, v, n)   list[cnt] = 0;  index_bb[cnt + 1] = index_bb[cnt] + strnpack(name_bb, index_bb[cnt], "dummy", strlen("dummy"));
#define DIS_INDEX       0x1f4

extern float32 *list[500];
extern int index_num[BUF_CTRL_MAX];

extern char  index_ctrl[BUF_CTRL_MAX][10];


extern float BB_Send_ctrl_data_cnt1;
extern float BB_Send_ctrl_data_cnt2;
extern float BB_Send_ctrl_data_cnt3;
extern float BB_Send_ctrl_data_cnt4;
extern float BB_Send_ctrl_data_cnt5;
extern float BB_Send_ctrl_data_cnt6;
extern float BB_Send_ctrl_data_cnt7;
extern float BB_Send_ctrl_data_cnt8;
extern float BB_Send_ctrl_data_cnt9;
extern float BB_Send_ctrl_data_cnt10;

extern float BB_Send_ctrl_data_cnt11;
extern float BB_Send_ctrl_data_cnt12;
extern float BB_Send_ctrl_data_cnt13;
extern float BB_Send_ctrl_data_cnt14;
extern float BB_Send_ctrl_data_cnt15;
extern float BB_Send_ctrl_data_cnt16;
extern float BB_Send_ctrl_data_cnt17;
extern float BB_Send_ctrl_data_cnt18;
extern float BB_Send_ctrl_data_cnt19;
extern float BB_Send_ctrl_data_cnt20;

extern float BB_Send_ctrl_data_cnt21;
extern float BB_Send_ctrl_data_cnt22;
extern float BB_Send_ctrl_data_cnt23;
extern float BB_Send_ctrl_data_cnt24;
extern float BB_Send_ctrl_data_cnt25;
extern float BB_Send_ctrl_data_cnt26;
extern float BB_Send_ctrl_data_cnt27;
extern float BB_Send_ctrl_data_cnt28;
extern float BB_Send_ctrl_data_cnt29;
extern float BB_Send_ctrl_data_cnt30;


void BB_Send_ctrl_data_check();

void BB_List_ctrl_select();
void BB_Send_ctrl_data();
void BB_Send_dac_data();
void BB_Send_500us_data();
void BB_Send_2ms_data();
void BB_Send_10ms_data();
void BB_Send_100ms_data();
void Set_List();
void Use_List();


#endif /* HEADER_INDEX_H_ */
