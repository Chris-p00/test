#ifndef SCI_H_
#define SCI_H_

#pragma CODE_SECTION(serial_modbus_500us_a, ".TI.ramfunc");
#pragma CODE_SECTION(serial_modbus_500us, ".TI.ramfunc");

#pragma CODE_SECTION(serial_modbus_10ms_a, ".TI.ramfunc");
#pragma CODE_SECTION(serial_modbus_10ms, ".TI.ramfunc");


void Init_Scia_BB(void);
void Init_Scia(void);
void Init_Scib(void);
void Init_Scic(void);
void Init_Scid(void);

void serial_modbus_500us();
void serial_modbus_10ms();
void function_SanRex();
void function_SanRex_HT();
void function_SanRex2();
void function_WR_SanRex();
void function_WR_SanRex2();
void function_WR_SanRex3();
void scib_com_init();

void serial_modbus_500us_a();
void serial_modbus_10ms_a();
void function_SanRex_a();
void function_SanRex_HT_a();
void function_SanRex2_a();
void function_WR_SanRex_a();
void function_WR_SanRex2_a();
void function_WR_SanRex3_a();
void scia_com_init();
void scia_com_setting();

char asc2hex(char asc);
char hex2asc(char hex);

interrupt void scib_rx_isr(void);

void function_3rd_response();
void function_6th_response();
void Bad_response();
int  CRC16(int dataLength, int check);
int  CRC16_a(int dataLength_a, int check_a);

extern int SCI_WR_setting;



#endif
