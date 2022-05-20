#ifndef HEADER_TIME_H_
#define HEADER_TIME_H_

#include "F28x_Project.h"
#include "ipc.h"
#include "rtc.h"


/*--------------------------------------*/
/*  control B/D setting & period        */
/*--------------------------------------*/
extern float   System_clock;
extern float   Scale_gating;
extern float   Scale_gating_con;
extern float   Freq_ctrl;
extern float   Freq_ctrl_con;
extern float   Tsamp;
extern float   Tsamp_con;

extern int     rout_cntl_count;
extern int     rout_1000ms_count;
extern int     rout_100ms_count;
extern int     rout_10ms_count;
extern int     rout_1ms_count;
extern int     rout_250us_count;
extern int     rout_2ms_count;
extern int     rout_500ms_count;
extern int     rout_500us_count;

extern float   rout_10ms_count_float;

extern float   Timer_clock;
extern int     Timer_Tsamp;
extern int     Timer_Tsamp2;

extern float   T_250us;
extern float   T_500us;
extern float   T_1ms;
extern float   T_2ms;
extern float   T_10ms;
extern float   T_100ms;
extern float   T_500ms;
extern float   T_1000ms;

extern float   INV_Tsamp;
extern float   INV_T_250us;
extern float   INV_T_500us;
extern float   INV_T_1ms;
extern float   INV_T_2ms;
extern float   INV_T_10ms;
extern float   INV_T_100ms;
extern float   INV_T_500ms;
extern float   INV_T_1000ms;

extern float   Tsamp_INV_T_2ms;
extern float   T_2ms_INV_T_100ms;
extern float   Tsamp_INV_T_100ms;


extern int     Set_T_250us;
extern int     Cnt_T_250us;
extern int     Flag_T_250us;

extern int     Set_T_500us;
extern int     Cnt_T_500us;
extern int     Flag_T_500us;

extern int     Set_T_1ms;
extern int     Cnt_T_1ms;
extern int     Flag_T_1ms;

extern int     Set_T_2ms;
extern int     Cnt_T_2ms;
extern int     Flag_T_2ms;

extern int     Set_T_10ms;
extern int     Cnt_T_10ms;
extern int     Flag_T_10ms;

extern int     Set_T_100ms;
extern int     Cnt_T_100ms;
extern int     Flag_T_100ms;

extern int     Set_T_500ms;
extern int     Cnt_T_500ms;
extern int     Flag_T_500ms;

extern int     Set_T_1000ms;
extern int     Cnt_T_1000ms;
extern int     Flag_T_1000ms;

/*--------------------------------------*/
/*  sequence(time, counter,...)         */
/*--------------------------------------*/
extern int     Flag_offset;
extern int     Offset_cnt;

extern float   TOL_offset;


extern float   Time_offset_wait;
extern int     Cnt_offset_wait;
extern int     Set_offset_wait;


void Init_Variables();

void rout_250us();
void rout_500us();
void rout_1ms();
void rout_2ms();
void rout_10ms();
void rout_100ms();
void rout_500ms();
void rout_1000ms();

#endif /* HEADER_TIME_H_ */
