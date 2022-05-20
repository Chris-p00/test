#include "Define.h"

//MODBUS_receive_buffer
//MODBUS_transmitt_buffer
//function_WR_SanRex3


#define CPUCLK 200000000L        // CPU Main Clock
#define SCIA_LSPCLK (CPUCLK / 4) // Peripheral Low Speed Clock for SCI-A
#define SCIB_LSPCLK (CPUCLK / 4) // Peripheral Low Speed Clock for SCI-B
#define SCIC_LSPCLK (CPUCLK / 4) // Peripheral Low Speed Clock for SCI-C
#define SCID_LSPCLK (CPUCLK / 4) // Peripheral Low Speed Clock for SCI-D

#define SCIA_BAUDRATE_BB 115200L

#define SCIA_BAUDRATE 9600L
//#define   SCIA_BAUDRATE   19200L                              // SCI-A Baudrate
//#define   SCIA_BAUDRATE   115200L                             // SCI-A Baudrate
//#define   SCIA_BAUDRATE   38400L                              // SCI-A Baudrate

//#define SCIB_BAUDRATE 9600L
//#define   SCIB_BAUDRATE   19200L                              // SCI-B Baudrate
#define   SCIB_BAUDRATE   115200L                             // SCI-B Baudrate
//#define   SCIB_BAUDRATE   38400L                              // SCI-B Baudrate

#define SCIC_BAUDRATE 9600L
//#define   SCIC_BAUDRATE   19200L                              // SCI-C Baudrate
//#define   SCIC_BAUDRATE   115200L                             // SCI-C Baudrate
//#define   SCIC_BAUDRATE   38400L                              // SCI-C Baudrate

#define SCID_BAUDRATE 9600L
//#define   SCID_BAUDRATE   19200L                              // SCI-D Baudrate
//#define   SCID_BAUDRATE   115200L                             // SCI-D Baudrate
//#define   SCID_BAUDRATE   38400L                              // SCI-D Baudrate

#define SCIA_BRR_VAL_BB (SCIA_LSPCLK / (8 * SCIA_BAUDRATE_BB) - 1)
#define SCIA_BRR_VAL    (SCIA_LSPCLK / (8 * SCIA_BAUDRATE) - 1)
#define SCIB_BRR_VAL    (SCIB_LSPCLK / (8 * SCIB_BAUDRATE) - 1)
#define SCIC_BRR_VAL    (SCIC_LSPCLK / (8 * SCIC_BAUDRATE) - 1)
#define SCID_BRR_VAL    (SCID_LSPCLK / (8 * SCID_BAUDRATE) - 1)

#define ASC_HEX_ERROR       0xff

#define MODBUS_RX_RDY_a     0x01    // receiver ready
#define MODBUS_RX_RDY       0x01    // receiver ready

#define MODBUS_TX_RDY_a     0x01    // transmitter ready
#define MODBUS_TX_RDY       0x01    // transmitter ready

#define RECEIVE_MAX_BYTE_a  50
#define RECEIVE_MAX_BYTE    50

#define RECEIVE_MIN_BYTE_a  2
#define RECEIVE_MIN_BYTE    2

#define GPIOB_485EN_TX (GpioDataRegs.GPESET.bit.GPIO134     = 1)
#define GPIOB_485EN_RX (GpioDataRegs.GPECLEAR.bit.GPIO134   = 1)

int     receive_count_a         = 0;
int     receive_count           = 0;

int     transmitt_count_a       = 0;
int     transmitt_count         = 0;

int     receive_err_cnt_a       = 0;
int     receive_err_cnt         = 0;

int     char_time_a             = 0;
int     char_time               = 0;

int     Flag_modbus_response_a  = 0;
int     Flag_modbus_response    = 0;

int     MODBUS_count_a          = 0;
int     MODBUS_count            = 0;

int     transmitt_flag_a        = 0;
int     transmitt_flag          = 0;

int     transmitt_data_length_a = 0;
int     transmitt_data_length   = 0;

int     rxerror_a               = 0;
int     rxerror                 = 0;

int     hyun_flag_a             = 0;
int     hyun_flag               = 0;

int     SanRex_ptr_0_cnt        = 0;

int     function_SanRex_HT_cnt  = 0;
int     function_SanRex_HT_a_cnt  = 0;

int     Flag_modbus_response_count_a        = 0;
int     Flag_modbus_response_count_test_a   = 0;
int     scia_com_init_count                 = 0;

int     Flag_modbus_response_count          = 0;
int     Flag_modbus_response_count_test     = 0;
int     scib_com_init_count                 = 0;


Uint16 MODBUS_transmitt_buffer_a[200]   = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                           0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                           0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                           0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                           0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

Uint16 MODBUS_transmitt_buffer[200]     = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                           0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                           0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                           0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                           0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

Uint16 MODBUS_receive_buffer_a[50]  = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Uint16 MODBUS_receive_buffer[50]    = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int SanRex_ptr_a[30]    = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int SanRex_ptr[30]      = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

unsigned int high_CRC_Receive = 0;
unsigned int low_CRC_Receive = 0;
unsigned int high_CRC_Send = 0;
unsigned int low_CRC_Send = 0;

int receiveC = 0;

int Write_Buffer[10] = {0,0,0,0,0,0,0,0,0,0 };

int     SCI_Recv_Error          = 0;

unsigned int     add_data_lsc       = 0;
unsigned int     all_data_lsc       = 0;
float               float_data_lsc  = 0;

//int     add_data_lsc       = 0;
//int     int_data_lsc       = 0;
//float   float_data_lsc    = 0;

unsigned int high_CRC_Receive_a = 0;
unsigned int low_CRC_Receive_a = 0;
unsigned int high_CRC_Send_a = 0;
unsigned int low_CRC_Send_a = 0;

int receiveC_a = 0;

int Write_Buffer_a[10] = {0,0,0,0,0,0,0,0,0,0 };

int     SCI_Recv_Error_a          = 0;


unsigned int     add_data_lsc_a        = 0;
unsigned int     all_data_lsc_a        = 0;
float               float_data_lsc_a   = 0;


//int     int_data_lsc_a       = 0;
//float   float_data_lsc_a    = 0;

unsigned int     CRC16_check1_test        = 0;
unsigned int     CRC16_check1_test_a        = 0;

unsigned int     CRC16_check2_test        = 0;
unsigned int     CRC16_check2_test_a        = 0;

unsigned int     CRC16_check1_test_a_cnt        = 0;




int SCI_WR_Mode   = 0;
int SCI_WR_setting = 0;

void Init_Scia_BB(void)
{

    SciaRegs.SCICCR.bit.STOPBITS = 0;  //1 stop bit
    SciaRegs.SCICCR.bit.PARITY = 1;    //Even parity
    SciaRegs.SCICCR.bit.LOOPBKENA = 0; //No loopback
    SciaRegs.SCICCR.bit.SCICHAR = 7;   //8 char bits
    SciaRegs.SCICCR.bit.PARITYENA = 1; //parity enable

    SciaRegs.SCICTL1.bit.RXERRINTENA = 1;
    SciaRegs.SCICTL1.bit.RXENA = 1;
    SciaRegs.SCICTL1.bit.TXENA = 1;

    SciaRegs.SCICTL2.bit.TXINTENA = 0;
    SciaRegs.SCICTL2.bit.RXBKINTENA = 0;
    SciaRegs.SCIHBAUD.all = SCIA_BRR_VAL_BB >> 8;
    SciaRegs.SCILBAUD.all = SCIA_BRR_VAL_BB & 0xff;

    // SCI의 송신 FIFO 설정
    SciaRegs.SCIFFTX.bit.SCIFFENA = 1;    // SCI FIFO 사용 설정 Enable
    SciaRegs.SCIFFTX.bit.TXFFINTCLR = 1;  // SCI 송신 FIFO 인터럽트 플래그 클리어
    SciaRegs.SCIFFTX.bit.TXFIFORESET = 1; // SCI 송신 FIFO RE-enable
    SciaRegs.SCIFFTX.bit.TXFFIENA = 0;    // SCI 송신 FIFO 인터럽트 Enable
    SciaRegs.SCIFFTX.bit.TXFFIL = 0;      // SCI 수신 FIFO 인터럽트 레벨 설정

    // SCI의 수신 FIFO 설정
    SciaRegs.SCIFFRX.bit.RXFFINTCLR = 1;  // SCI 수신 FIFO 인터럽트 플래그 클리어
    SciaRegs.SCIFFRX.bit.RXFIFORESET = 1; // SCI 수신 FIFO RE-enable
    SciaRegs.SCIFFRX.bit.RXFFIENA = 1;    // SCI 수신 FIFO 인터럽트 Enable
    SciaRegs.SCIFFRX.bit.RXFFIL = 1;      // SCI 수신 FIFO 인터럽트 레벨 설정

    SciaRegs.SCICTL1.all = 0x0023; // Relinquish SCI from Reset


}

void Init_Scia(void)
{
    EALLOW;
    GPIO_SetupPinMux(136, GPIO_MUX_CPU1, 6);              //SCI_A_RX (MUX6)
    GPIO_SetupPinOptions(136, GPIO_INPUT, GPIO_PUSHPULL); //SCI_A_RX (MUX6)
    GPIO_SetupPinMux(135, GPIO_MUX_CPU1, 6);              //SCI_A_TX (MUX6)
    GPIO_SetupPinOptions(135, GPIO_OUTPUT, GPIO_ASYNC);   //SCI_A_TX (MUX6)
    EDIS;

    SciaRegs.SCIFFTX.all = 0x8000;          // FIFO reset
    SciaRegs.SCIFFCT.all = 0x4000;          // Clear ABD(Auto baud bit)

    SciaRegs.SCICCR.all = 0x0067;           // 1 stop bit,  No loopback
//  SciaRegs.SCICCR.all = 0x0047;           // 1 stop bit,  No loopback
                                            // No parity,8 char bits,
                                            // async mode, idle-line protocol
    SciaRegs.SCICTL1.all = 0x0003;          // enable TX, RX, internal SCICLK,
                                            // Disable RX ERR, SLEEP, TXWAKE

    SciaRegs.SCICTL2.bit.RXBKINTENA = 0;    // RX/BK INT ENA=1,
    SciaRegs.SCICTL2.bit.TXINTENA = 0;      // TX INT ENA=1,

    SciaRegs.SCIHBAUD.all = SCIA_BRR_VAL >> 8;
    SciaRegs.SCILBAUD.all = SCIA_BRR_VAL & 0xff;

    SciaRegs.SCICTL1.all = 0x0023;          // Relinquish SCI from Reset
}

void Init_Scib(void)
{
    EALLOW;
    GPIO_SetupPinMux(138, GPIO_MUX_CPU1, 6);              //SCI_B_RX (MUX6)
    GPIO_SetupPinOptions(138, GPIO_INPUT, GPIO_PULLUP);   //SCI_B_RX (MUX6)
    GPIO_SetupPinMux(137, GPIO_MUX_CPU1, 6);              //SCI_B_TX (MUX6)
    GPIO_SetupPinOptions(137, GPIO_OUTPUT, GPIO_ASYNC);   //SCI_B_TX (MUX6)

    GPIO_SetupPinMux(134, GPIO_MUX_CPU1, 0);
    GPIO_SetupPinOptions(134, GPIO_OUTPUT, GPIO_PUSHPULL);
    EDIS;

    ScibRegs.SCIFFTX.all = 0x8000;          // FIFO reset
    ScibRegs.SCIFFCT.all = 0x4000;          // Clear ABD(Auto baud bit)

    ScibRegs.SCICCR.all = 0x0067;           // 1 stop bit,  No loopback
//  ScibRegs.SCICCR.all = 0x0047;           // 1 stop bit,  No loopback
                                            // No parity,8 char bits,
                                            // async mode, idle-line protocol
    ScibRegs.SCICTL1.all = 0x0003;          // enable TX, RX, internal SCICLK,
                                            // Disable RX ERR, SLEEP, TXWAKE

    ScibRegs.SCICTL2.bit.RXBKINTENA = 0;    // RX/BK INT ENA=1,
    ScibRegs.SCICTL2.bit.TXINTENA = 0;      // TX INT ENA=1,

    ScibRegs.SCIHBAUD.all = SCIB_BRR_VAL >> 8;
    ScibRegs.SCILBAUD.all = SCIB_BRR_VAL & 0xff;

    ScibRegs.SCICTL1.all = 0x0023;          // Relinquish SCI from Reset

    /* Configure /RS485 Enable*/
    GpioCtrlRegs.GPEGMUX1.bit.GPIO134   = 0;
    GpioDataRegs.GPEDAT.bit.GPIO134     = 1;
    GpioDataRegs.GPECLEAR.bit.GPIO134   = 1;
}


void Init_Scic(void)
{
    GPIO_SetupPinMux(139, GPIO_MUX_CPU2, 6);              //SCI_C_RX (MUX6)
    GPIO_SetupPinOptions(139, GPIO_INPUT, GPIO_PUSHPULL); //SCI_C_RX (MUX6)
    GPIO_SetupPinMux(140, GPIO_MUX_CPU2, 6);              //SCI_C_TX (MUX6)
    GPIO_SetupPinOptions(140, GPIO_OUTPUT, GPIO_ASYNC);   //SCI_C_TX (MUX6)

    ScicRegs.SCIFFTX.all = 0x8000;          // FIFO reset
    ScicRegs.SCIFFCT.all = 0x4000;          // Clear ABD(Auto baud bit)

    ScicRegs.SCICCR.all = 0x0067;           // 1 stop bit,  No loopback
//  ScicRegs.SCICCR.all = 0x0047;           // 1 stop bit,  No loopback
                                            // No parity,8 char bits,
                                            // async mode, idle-line protocol
    ScicRegs.SCICTL1.all = 0x0003;          // enable TX, RX, internal SCICLK,
                                            // Disable RX ERR, SLEEP, TXWAKE

    ScicRegs.SCICTL2.bit.RXBKINTENA = 0;    // RX/BK INT ENA=1,
    ScicRegs.SCICTL2.bit.TXINTENA = 0;      // TX INT ENA=1,

    ScicRegs.SCIHBAUD.all = SCIC_BRR_VAL >> 8;
    ScicRegs.SCILBAUD.all = SCIC_BRR_VAL & 0xff;

    ScicRegs.SCICTL1.all = 0x0023;          // Relinquish SCI from Reset

}

void Init_Scid(void)
{

    EALLOW;
    GPIO_SetupPinMux(141, GPIO_MUX_CPU1, 6);              //SCI_D_RX (MUX6)
    GPIO_SetupPinOptions(141, GPIO_INPUT, GPIO_PUSHPULL); //SCI_D_RX (MUX6)
    GPIO_SetupPinMux(142, GPIO_MUX_CPU1, 6);              //SCI_D_TX (MUX6)
    GPIO_SetupPinOptions(142, GPIO_OUTPUT, GPIO_ASYNC);   //SCI_D_TX (MUX6)
    EDIS;

    ScidRegs.SCIFFTX.all = 0x8000;          // FIFO reset
    ScidRegs.SCIFFCT.all = 0x4000;          // Clear ABD(Auto baud bit)

    ScidRegs.SCICCR.all = 0x0067;           // 1 stop bit,  No loopback
//  ScidRegs.SCICCR.all = 0x0047;           // 1 stop bit,  No loopback
                                            // No parity,8 char bits,
                                            // async mode, idle-line protocol
    ScidRegs.SCICTL1.all = 0x0003;          // enable TX, RX, internal SCICLK,
                                            // Disable RX ERR, SLEEP, TXWAKE

    ScidRegs.SCICTL2.bit.RXBKINTENA = 0;    // RX/BK INT ENA=1,
    ScidRegs.SCICTL2.bit.TXINTENA = 0;      // TX INT ENA=1,

    ScidRegs.SCIHBAUD.all = SCIB_BRR_VAL >> 8;
    ScidRegs.SCILBAUD.all = SCIB_BRR_VAL & 0xff;

    ScidRegs.SCICTL1.all = 0x0023;          // Relinquish SCI from Reset
}
//------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------
void serial_modbus_500us()
{
    int ri0 = 0;
    int ri1 = 0;

    ri0 = (ScibRegs.SCIRXST.bit.RXRDY) & 0xff;

    if(ScibRegs.SCIRXST.all & 0x80)
    {
        ScibRegs.SCICTL1.all = 0x0003;          // Relinquish SCI from Reset
        ScibRegs.SCICTL1.all = 0x0023;          // Relinquish SCI from Reset
    }

    if(ri0 & MODBUS_RX_RDY)
    {
        if(receive_count < RECEIVE_MAX_BYTE)
        {   // RECEIVE_MAX_BYTE = 12
            MODBUS_receive_buffer[receive_count] = ScibRegs.SCIRXBUF.all;
            receive_count++;
            receive_err_cnt = 0;
        }
        else if( receive_err_cnt > 30)
        {
            receive_count   = 0;
        }
        char_time           = 0;
        receive_err_cnt++;
    }
    else if((Flag_modbus_response == 0) && (++char_time == 15 ))
    {   // <not receive> and <char_time(3.5)(38400:730us->250us :3times)>
        //char_time=0;
        MODBUS_count            = receive_count;
        receive_count           = 0;
        receive_err_cnt         = 0;
        Flag_modbus_response    = 1;
    }
    else if((Flag_modbus_response == 0) && (char_time > 15))
    {
        char_time   = 15;
    }

    ri1 = ScibRegs.SCICTL2.bit.TXRDY;

    if(transmitt_flag == 1)
    {
        if(ri1 & MODBUS_TX_RDY)
        {
            if(transmitt_count < transmitt_data_length)
            {
                asm(" EALLOW");
                GPIOB_485EN_TX;   //485 transmitt enable
                asm(" EDIS");

                ScibRegs.SCITXBUF.all = MODBUS_transmitt_buffer[transmitt_count];
                transmitt_count++;
            }
            else if(transmitt_count <= (transmitt_data_length + 4))
            {
                transmitt_count++;
            }
            else
            {
                asm(" EALLOW");
                GPIOB_485EN_RX;   //485 receive enable
                asm(" EDIS");

                transmitt_flag  = 0;
                transmitt_count = 0;
            }
        }
    }
}
//---------------------------------------------------------------------------------


//---------------------------------------------------------------------------------
void serial_modbus_10ms()
{
    if(Flag_modbus_response == 1)
    {
        Flag_modbus_response_count++;

        //if (CRC16(6,1) == 1){
        if (MODBUS_receive_buffer[0] == 'M' && MODBUS_receive_buffer[1] == 'N' && MODBUS_receive_buffer[2] == 0x20 &&
            MODBUS_receive_buffer[3] == 'H' && MODBUS_receive_buffer[4] == 0x0d)
        {
            hyun_flag   = 2;  // Monitor Read
            GPIOB_485EN_TX;   //485 transmitt enable
        }
        else if (MODBUS_receive_buffer[0] == 'M' && MODBUS_receive_buffer[1] == 'S' && MODBUS_receive_buffer[2] == 0x20 &&
            MODBUS_receive_buffer[3] == 'H' && MODBUS_receive_buffer[4] == 0x0d)
        {
            hyun_flag   = 4;  // Scale Read
            GPIOB_485EN_TX;   //485 transmitt enable
        }
        else if (MODBUS_receive_buffer[0] == 'M' && MODBUS_receive_buffer[1] == 'K' && MODBUS_receive_buffer[2] == 0x20 &&
            MODBUS_receive_buffer[3] == 'H' && MODBUS_receive_buffer[4] == 0x0d) {
            hyun_flag=5;  // Scale Read
            GPIOB_485EN_TX;   //485 transmitt enable

        }
        else if (MODBUS_receive_buffer[0] == 'M' && MODBUS_receive_buffer[1] == 'E' && MODBUS_receive_buffer[2] == 0x20 &&
            MODBUS_receive_buffer[3] == 'H' && MODBUS_receive_buffer[4] == 0x0d) {
            hyun_flag=9;        // inverter setting read
            GPIOB_485EN_TX;     //485 transmitt enable
        }

        else if (MODBUS_receive_buffer[0] == 'H' && MODBUS_receive_buffer[1] == 'T' &&
            MODBUS_receive_buffer[3] == 'H' && MODBUS_receive_buffer[4] == 0x0d)
        {
            if((MODBUS_receive_buffer[2] >= 0x20) && (MODBUS_receive_buffer[2] <= 0x29))
            {
                switch(MODBUS_receive_buffer[2])
                {
                    case 0x20: hyun_flag=0x20;  break;  // History Read
                    case 0x21: hyun_flag=0x21;  break;  // History Read
                    case 0x22: hyun_flag=0x22;  break;  // History Read
                    case 0x23: hyun_flag=0x23;  break;  // History Read
                    case 0x24: hyun_flag=0x24;  break;  // History Read
                    case 0x25: hyun_flag=0x25;  break;  // History Read
                    case 0x26: hyun_flag=0x26;  break;  // History Read
                    case 0x27: hyun_flag=0x27;  break;  // History Read
                    case 0x28: hyun_flag=0x28;  break;  // History Read
                    case 0x29: hyun_flag=0x29;  break;  // History Read
                    default: break;
                }
                GPIOB_485EN_TX;   //485 transmitt enable
            }
        }
        else if (MODBUS_receive_buffer[0] == 'W'  && MODBUS_receive_buffer[1] == 'C' && MODBUS_receive_buffer[2] == 0x20 &&
            MODBUS_receive_buffer[10] == 0x0d)
        {
            hyun_flag = 3;
            GPIOB_485EN_TX;   //485 transmitt enable
        }
        /* GS write protocol */
//        else if (MODBUS_receive_buffer[0] == 'M'  && MODBUS_receive_buffer[1] == 'N' && MODBUS_receive_buffer[2] == 0x20 &&
//            MODBUS_receive_buffer[3] == 'W' && MODBUS_receive_buffer[10] == 0x0d)   {
//            hyun_flag = 6;
//            GPIOB_485EN_TX;   //485 transmitt enable
//        }
        /* GS write protocol */

        else if (MODBUS_receive_buffer[0] == 'T' && MODBUS_receive_buffer[1] == 'A' && MODBUS_receive_buffer[2] == 0x20 &&
            MODBUS_receive_buffer[3] == 'H' && MODBUS_receive_buffer[4] == 0x0d)
        {
            hyun_flag   = 11;  // Scale Read
            GPIOB_485EN_TX;   //485 transmitt enable
        }

        else if (MODBUS_receive_buffer[0] == 'T' && MODBUS_receive_buffer[1] == 'B' && MODBUS_receive_buffer[2] == 0x20 &&
            MODBUS_receive_buffer[3] == 'H' && MODBUS_receive_buffer[4] == 0x0d)
        {
            hyun_flag   = 12;  // Scale Read
            GPIOB_485EN_TX;   //485 transmitt enable
        }

        else if (MODBUS_receive_buffer[0] == 'T' && MODBUS_receive_buffer[1] == 'C' && MODBUS_receive_buffer[2] == 0x20 &&
            MODBUS_receive_buffer[3] == 'H' && MODBUS_receive_buffer[4] == 0x0d)
        {
            hyun_flag   = 13;  // Scale Read
            GPIOB_485EN_TX;   //485 transmitt enable
        }

        else if (MODBUS_receive_buffer[0] == 'T' && MODBUS_receive_buffer[1] == 'D' && MODBUS_receive_buffer[2] == 0x20 &&
            MODBUS_receive_buffer[3] == 'H' && MODBUS_receive_buffer[4] == 0x0d)
        {
            hyun_flag   = 14;  // Scale Read
            GPIOB_485EN_TX;   //485 transmitt enable
        }

        else if (MODBUS_receive_buffer[0] == 'T' && MODBUS_receive_buffer[1] == 'E' && MODBUS_receive_buffer[2] == 0x20 &&
            MODBUS_receive_buffer[3] == 'H' && MODBUS_receive_buffer[4] == 0x0d)
        {
            hyun_flag   = 15;  // Scale Read
            GPIOB_485EN_TX;   //485 transmitt enable
        }

        else if (MODBUS_receive_buffer[0] == 'T' && MODBUS_receive_buffer[1] == 'F' && MODBUS_receive_buffer[2] == 0x20 &&
            MODBUS_receive_buffer[3] == 'H' && MODBUS_receive_buffer[4] == 0x0d)
        {
            hyun_flag   = 16;  // Scale Read
            GPIOB_485EN_TX;   //485 transmitt enable
        }

        else if (MODBUS_receive_buffer[0] == 'M'  && MODBUS_receive_buffer[1] == 'N' && MODBUS_receive_buffer[2] == 0x20 &&
                   MODBUS_receive_buffer[3] == 'W'  && MODBUS_receive_buffer[10] == 0x0d)//CRC (L) CRC (H)
          {


              if (CRC16(11,1) == 1){
                  hyun_flag = 30;
                  GPIOB_485EN_TX;   //485 transmitt enable
              }
              else {/*BAD_RESPONSE*/}

                CRC16_check1_test =  CRC16(11,1);



//              hyun_flag = 30;
//              GPIOB_485EN_TX;   //485 transmitt enable
          }
        else {SCI_Recv_Error++;}

        Flag_modbus_response    = 0;
    }


    if ((hyun_flag == 2)||(hyun_flag == 4)||(hyun_flag == 5)||(hyun_flag == 9))
    {
        function_SanRex();
        hyun_flag   = 0;
    }
    else if ((hyun_flag >= 0x20) && (hyun_flag <= 0x29))
    {
        function_SanRex_HT();
        hyun_flag   = 0;
    }
    else if (hyun_flag == 3)
    {
        function_WR_SanRex();
        hyun_flag   = 0;
    }
    else if(hyun_flag == 6)
    {
        function_WR_SanRex2();
        hyun_flag=0;
    }
    else if ((hyun_flag == 11)||(hyun_flag == 12)||(hyun_flag == 13)||(hyun_flag == 14)||(hyun_flag == 15)||(hyun_flag == 16))
    {
        function_SanRex2();
        hyun_flag   = 0;
    }

    else if (hyun_flag == 30)
    {
        function_WR_SanRex3();
        hyun_flag = 0;
    }

    rxerror = (ScibRegs.SCIRXST.bit.RXERROR) & 0x0ff;
    if(rxerror != 0)
    {
        ScibRegs.SCICTL2.bit.RXBKINTENA = 0;
        ScibRegs.SCICTL2.bit.TXINTENA   = 0;
        ScibRegs.SCICTL1.all            = 0x0023;   // Relinquish SCI from Reset Edit 0829 err
    }
}



//---------------------------------------------------------------------------------
void function_SanRex()
{

// SanRex Inverter Protocol
    unsigned char imsi_data_bytehigh=0, imsi_data_bytelow=0;
    unsigned char imsi_data_bytehigh_high=0, imsi_data_bytehigh_low=0,imsi_data_bytelow_high=0, imsi_data_bytelow_low=0 ;
    int i=0;

/************************************************ Edit 100517 *************************************************/

    if(hyun_flag == 2)
    {  // Edit 100517

#if 0
        SanRex_ptr_0_cnt++;
        if(SanRex_ptr_0_cnt >= 300) SanRex_ptr_0_cnt = 0;
        SanRex_ptr[0]  = (int)(SanRex_ptr_0_cnt   * 100.);
#endif

#if 0
        if(SCI_WR_Mode == 0)
        {
            SanRex_ptr[0]  = (int)(Vin_flt_avg_avg   * 100.);
            SanRex_ptr[1]  = (int)(Idc_flt_avg_avg   * 100.);
            SanRex_ptr[2]  = (int)(Pin               * 1000.);
            SanRex_ptr[3]  = (int)(Esa_rms_avg       * 10.);
            SanRex_ptr[4]  = (int)(Esb_rms_avg       * 10.);
            SanRex_ptr[5]  = (int)(Esc_rms_avg       * 10.);
            SanRex_ptr[6]  = (int)(Flag_Act_islanding);      //
            SanRex_ptr[7]  = (int)(Pinv_DQ_avg       * 1000.);      // Pout
            SanRex_ptr[8]  = (int)(Freq_out          * 100.);         // Frequency
            SanRex_ptr[9]  = (int)(Vdc_flt           * 10.);           // Vdc

            SanRex_ptr[10] = (int)(Ia_rms_avg       * 100.);      // Vdc
            SanRex_ptr[11] = (int)(Ib_rms_avg       * 100.);      // Pout
            SanRex_ptr[12] = (int)(Ic_rms_avg       * 100.);
            SanRex_ptr[13] = INV_status;                    // 0:offset, 1:ready, 2: buildup, 3: run, 4: fault
            SanRex_ptr[14] = (Fault_SW & 0xFFFF);           // fault
            SanRex_ptr[15] = ((Fault_SW>>16) & 0xFFFF);
            SanRex_ptr[16] = Fault_history[1];
            SanRex_ptr[17] = Fault_history[2];
            SanRex_ptr[18] = Fault_history[0];
            SanRex_ptr[19] = (int)(Vdc_con_real_max * 100.);    //Idc_ref

            SanRex_ptr[20] = INV_SW_VER; //Ver1.00
        }
        else
        {
            SanRex_ptr[0]  = (int)(Vdc_ref_inv      * 10.);
            SanRex_ptr[1]  = (int)(Vdc_flt          * 10.);
            SanRex_ptr[2]  = (int)(Err_Vdc_inv      * 10.);
            SanRex_ptr[3]  = (int)(Ip_ref_integ     * 10.);
            SanRex_ptr[4]  = (int)(Ip_ref_out       * 10.);
            SanRex_ptr[5]  = (int)(Ip_ref           * 10.);
            SanRex_ptr[6]  = (int)(Flag_Act_islanding);             //
            SanRex_ptr[7]  = (int)(Ip_ref_real_max   * 10.);        // Pout
            SanRex_ptr[8]  = (int)(Freq_out          * 100.);       // Frequency
            SanRex_ptr[9]  = (int)(Vdc_flt           * 10.);        // Vdc

            SanRex_ptr[10] = (int)(Ia_rms_avg       * 100.);        // Vdc
            SanRex_ptr[11] = (int)(Ib_rms_avg       * 100.);        // Pout
            SanRex_ptr[12] = (int)(Ic_rms_avg       * 100.);
            SanRex_ptr[13] = INV_status;                    // 0:offset, 1:ready, 2: buildup, 3: run, 4: fault
            SanRex_ptr[14] = (Fault_SW & 0xFFFF);           // fault
            SanRex_ptr[15] = ((Fault_SW>>16) & 0xFFFF);
            SanRex_ptr[16] = Fault_history[1];
            SanRex_ptr[17] = Fault_history[2];
            SanRex_ptr[18] = Fault_history[0];
            SanRex_ptr[19] = (int)(Vdc_con_real_max * 100.);    //Idc_ref

            SanRex_ptr[20] = INV_SW_VER; //Ver1.00
        }
#endif

#if 0
        SanRex_ptr[0]  = (int)(Vin_flt_avg_avg   * 100.);
        SanRex_ptr[1]  = (int)(Idc_flt_avg_avg   * 100.);
        SanRex_ptr[2]  = (int)(Pin               * 1000.);
        SanRex_ptr[3]  = (int)(Esa_rms_avg       * 10.);
        SanRex_ptr[4]  = (int)(Esb_rms_avg       * 10.);
        SanRex_ptr[5]  = (int)(Esc_rms_avg       * 10.);
        SanRex_ptr[6]  = (int)(Flag_Act_islanding);      //
        SanRex_ptr[7]  = (int)(Pinv_DQ_avg       * 1000.);      // Pout
        SanRex_ptr[8]  = (int)(Freq_out          * 100.);         // Frequency
        SanRex_ptr[9]  = (int)(Vdc_flt           * 10.);           // Vdc

        SanRex_ptr[10] = (int)(Ia_rms_avg       * 100.);      // Vdc
        SanRex_ptr[11] = (int)(Ib_rms_avg       * 100.);      // Pout
        SanRex_ptr[12] = (int)(Ic_rms_avg       * 100.);
        SanRex_ptr[13] = INV_status;                    // 0:offset, 1:ready, 2: buildup, 3: run, 4: fault
        SanRex_ptr[14] = (Fault_SW & 0xFFFF);           // fault
        SanRex_ptr[15] = ((Fault_SW>>16) & 0xFFFF);
        SanRex_ptr[16] = Fault_history[1];
        SanRex_ptr[17] = Fault_history[2];
        SanRex_ptr[18] = Fault_history[0];
        SanRex_ptr[19] = (int)(Vdc_con_real_max * 100.);    //Idc_ref

        SanRex_ptr[20] = INV_SW_VER; //Ver1.00
        MODBUS_transmitt_buffer[0]  = 'M';
        MODBUS_transmitt_buffer[1]  = 'N';
        MODBUS_transmitt_buffer[2]  = 0x20;
//      MODBUS_transmitt_buffer[3]  = '0';
//      MODBUS_transmitt_buffer[4]  = '0';
//      MODBUS_transmitt_buffer[5]  = 0x20;
#endif

#if 0
        SanRex_ptr[0] = (int)0;
        SanRex_ptr[1] = (int)1;
        SanRex_ptr[2] = (int)2;
        SanRex_ptr[3] = (int)3;
        SanRex_ptr[4] = (int)4;
        SanRex_ptr[5] = (int)5;
        SanRex_ptr[6] = (int)6;
        SanRex_ptr[7] = (int)7;
        SanRex_ptr[8] = (int)8;
        SanRex_ptr[9] = (int)9;
        SanRex_ptr[10] = (int)10;
        SanRex_ptr[11] = (int)11;
        SanRex_ptr[12] = (int)12;
        SanRex_ptr[13] = (int)13;
        SanRex_ptr[14] = (int)14;
        SanRex_ptr[15] = (int)15;
        SanRex_ptr[16] = (int)16;
        SanRex_ptr[17] = (int)17;
        SanRex_ptr[18] = (int)18;
        SanRex_ptr[19] = (int)19;
        SanRex_ptr[20] = (int)20;
        SanRex_ptr[21] = (int)21;
        SanRex_ptr[22] = (int)22;

        MODBUS_transmitt_buffer[0]  = 'M';
        MODBUS_transmitt_buffer[1]  = 'N';
        MODBUS_transmitt_buffer[2]  = 0x20;
#endif


#if 0
        SanRex_ptr[0]  = (int)(Fault_EPWM1_TZ1   * 1.);
        SanRex_ptr[1]  = (int)(Fault_EPWM2_TZ1   * 1.);
        SanRex_ptr[2]  = (int)(Fault_EPWM3_TZ1   * 1.);
        SanRex_ptr[3]  = (int)(Fault_EPWM4_TZ2   * 1.);
        SanRex_ptr[4]  = (int)(Fault_EPWM5_TZ2   * 1.);
        SanRex_ptr[5]  = (int)(Fault_EPWM6_TZ2   * 1.);
        SanRex_ptr[6]  = (int)(Fault_EPWM7_TZ3   * 1.);      //
        SanRex_ptr[7]  = (int)(Fault_EPWM8_TZ3   * 1.);      // Pout
        SanRex_ptr[8]  = (int)(Fault_EPWM9_TZ3   * 1.);         // Frequency
        SanRex_ptr[9]  = (int)(Fault_EPWM10_TZ4  * 1.);           // Vdc

        SanRex_ptr[10] = (int)(Fault_EPWM11_TZ4  * 1.);      // Vdc
        SanRex_ptr[11] = (int)(Fault_EPWM12_TZ4  * 1.);      // Pout
        SanRex_ptr[12] = (int)(Fault_TZ          * 1.);
        SanRex_ptr[13] = Fault_HW;                    // 0:offset, 1:ready, 2: buildup, 3: run, 4: fault
        SanRex_ptr[14] = (Fault_SW & 0xFFFF);           // fault
        SanRex_ptr[15] = ((Fault_SW>>16) & 0xFFFF);
        SanRex_ptr[16] = Fault_history[1];
        SanRex_ptr[17] = Fault_history[2];
        SanRex_ptr[18] = Fault_history[0];
        SanRex_ptr[19] = (int)(Vdc_con_real_max * 100.);    //Idc_ref

//        SanRex_ptr[20] = INV_SW_VER; //Ver1.00 -> ver1.01
//        SanRex_ptr[20] = Idc_ref_comp_input; //Ver1.00 -> ver1.01
        SanRex_ptr[20] = Idc_ref_comp; //Ver1.00 -> ver1.01
        SanRex_ptr[21] = (int)(OP_MODE          * 1.); //Ver1.00 -> ver1.01
        SanRex_ptr[22] = (int)(Run_Stop_com     * 1.); //Ver1.00 -> ver1.01
#endif


#if 0
        SanRex_ptr[0]  = (int)(EPwm1_TZ1_IntCount   * 1.);
        SanRex_ptr[1]  = (int)(EPwm2_TZ1_IntCount   * 1.);
        SanRex_ptr[2]  = (int)(EPwm3_TZ1_IntCount   * 1.);
        SanRex_ptr[3]  = (int)(EPwm4_TZ2_IntCount   * 1.);
        SanRex_ptr[4]  = (int)(EPwm5_TZ2_IntCount   * 1.);
        SanRex_ptr[5]  = (int)(EPwm6_TZ2_IntCount   * 1.);
        SanRex_ptr[6]  = (int)(EPwm7_TZ3_IntCount   * 1.);      //
        SanRex_ptr[7]  = (int)(EPwm8_TZ3_IntCount   * 1.);      // Pout
        SanRex_ptr[8]  = (int)(EPwm9_TZ3_IntCount   * 1.);         // Frequency
        SanRex_ptr[9]  = (int)(EPwm10_TZ4_IntCount  * 1.);           // Vdc

        SanRex_ptr[10] = (int)(EPwm11_TZ4_IntCount  * 1.);      // Vdc
        SanRex_ptr[11] = (int)(EPwm12_TZ4_IntCount  * 1.);      // Pout
        SanRex_ptr[12] = (int)(Fault_TZ          * 1.);
        SanRex_ptr[13] = Fault_HW;                    // 0:offset, 1:ready, 2: buildup, 3: run, 4: fault
        SanRex_ptr[14] = (Fault_SW & 0xFFFF);           // fault
        SanRex_ptr[15] = ((Fault_SW>>16) & 0xFFFF);
        SanRex_ptr[16] = Fault_history[1];
        SanRex_ptr[17] = Fault_history[2];
        SanRex_ptr[18] = Fault_history[0];
        SanRex_ptr[19] = (int)(Vdc_con_real_max * 100.);    //Idc_ref

//        SanRex_ptr[20] = INV_SW_VER; //Ver1.00 -> ver1.01
//        SanRex_ptr[20] = Idc_ref_comp_input; //Ver1.00 -> ver1.01
        SanRex_ptr[20] = Idc_ref_comp; //Ver1.00 -> ver1.01
        SanRex_ptr[21] = (int)(OP_MODE          * 1.); //Ver1.00 -> ver1.01
        SanRex_ptr[22] = (int)(Run_Stop_com     * 1.); //Ver1.00 -> ver1.01
#endif


#if 1
        SanRex_ptr[0]  = (int)(Vin_flt_avg_avg_abs   * 100.);
        SanRex_ptr[1]  = (int)(Idc_flt_avg_avg_abs   * 100.);
        SanRex_ptr[2]  = (int)(Pin_abs               * 1000.);
        SanRex_ptr[3]  = (int)(Esc_rms_avg       * 10.);
        SanRex_ptr[4]  = (int)(Esb_rms_avg       * 10.);
        SanRex_ptr[5]  = (int)(Esa_rms_avg       * 10.);
        SanRex_ptr[6]  = (int)(Ia_rms_avg        * 100.);      //
        SanRex_ptr[7]  = (int)(Pinv_DQ_avg_abs       * 1000.);      // Pout
        SanRex_ptr[8]  = (int)(Freq_out          * 100.);         // Frequency
        SanRex_ptr[9]  = (int)(Vdc_flt           * 10.);           // Vdc

        SanRex_ptr[10] = (int)(Ib_rms_avg       * 100.);      // Vdc
        SanRex_ptr[11] = (int)(Pinv_DQ_avg_abs      * 1000.);      // Pout
        SanRex_ptr[12] = (int)(Ic_rms_avg       * 100.);
        SanRex_ptr[13] = INV_status;                    // 0:offset, 1:ready, 2: buildup, 3: run, 4: fault
        SanRex_ptr[14] = (Fault_SW & 0xFFFF);           // fault
        SanRex_ptr[15] = ((Fault_SW>>16) & 0xFFFF);
        SanRex_ptr[16] = Fault_history[1];
        SanRex_ptr[17] = Fault_history[2];
        SanRex_ptr[18] = Fault_history[0];
        SanRex_ptr[19] = (int)(Vdc_con_real_max * 100.);    //Idc_ref

//        SanRex_ptr[20] = INV_SW_VER; //Ver1.00 -> ver1.01
//        SanRex_ptr[20] = Idc_ref_comp_input; //Ver1.00 -> ver1.01
        SanRex_ptr[20] = Idc_ref_comp; //Ver1.00 -> ver1.01
        SanRex_ptr[21] = (int)(OP_MODE          * 1.); //Ver1.00 -> ver1.01
        SanRex_ptr[22] = (int)(Run_Stop_com     * 1.); //Ver1.00 -> ver1.01
#endif

        MODBUS_transmitt_buffer[0]  = 'M';
        MODBUS_transmitt_buffer[1]  = 'N';
        MODBUS_transmitt_buffer[2]  = 0x20;
//      MODBUS_transmitt_buffer[3]  = '0';
//      MODBUS_transmitt_buffer[4]  = '0';
//      MODBUS_transmitt_buffer[5]  = 0x20;

    }
    else if(hyun_flag==4)
    {
#if 1
        if(SCI_WR_Mode == 0)
        {
            //Inverter Scale
            SanRex_ptr[0] = (int)(Scale_Vin_ratio   * 100);
            SanRex_ptr[1] = (int)(Scale_Idc_ratio   * 100);
            SanRex_ptr[2] = (int)(Scale_A_ref_ratio * 100);
            SanRex_ptr[3] = (int)(Scale_Vdc_ratio   * 100);
            SanRex_ptr[4] = (int)(Scale_Esa_ratio   * 100);
            SanRex_ptr[5] = (int)(Scale_Esb_ratio   * 100);
            SanRex_ptr[6] = (int)(Scale_Esc_ratio   * 100);
            SanRex_ptr[7] = (int)(Scale_Ia_ratio    * 100);
            SanRex_ptr[8] = (int)(Scale_Ib_ratio    * 100);
            SanRex_ptr[9] = (int)(Scale_Ic_ratio    * 100);

            SanRex_ptr[10] = (int)(Vin_offset     * 100);
            SanRex_ptr[11] = (int)(Idc_offset     * 100);
            SanRex_ptr[12] = (int)(A_ref_offset   * 100);
            SanRex_ptr[13] = (int)(Vdc_offset     * 100);
            SanRex_ptr[14] = (int)(Ia_offset_comp * 100);
            SanRex_ptr[15] = (int)(Ib_offset_comp * 100);
            SanRex_ptr[16] = (int)(Ic_offset_comp * 100);
            SanRex_ptr[17] = (int)(Idc_ref_comp   * 100);
            SanRex_ptr[18] = (int)(SCI_WR_setting    * 100);
            SanRex_ptr[19] = (int)(SCI_WR_Mode    * 100);

//          SanRex_ptr[20] = Enable_EEPROM_write;
            SanRex_ptr[20] = (int)(OP_MODE          * 1);
            SanRex_ptr[21] = (int)(Run_Stop_com     * 1);
            SanRex_ptr[22] = (int)(Fault_reset_com  * 1);
       }

        else if(SCI_WR_Mode == 1)
        {
            //Inverter /V/I/Power
            SanRex_ptr[0] = (int)(Vin_max           * 100);
            SanRex_ptr[1] = (int)(Vin_min           * 100);
            SanRex_ptr[2] = (int)(Idc_max           * 100);
            SanRex_ptr[3] = (int)(Vdc_max           * 10);
            SanRex_ptr[4] = (int)(Vl_rate           * 10);
            SanRex_ptr[5] = (int)(Ic_rate           * 100);
            SanRex_ptr[6] = (int)(Pout_rate         * 100);
            SanRex_ptr[7] = (int)(OV_Vin_level      * 100);
            SanRex_ptr[8] = (int)(UV_Vin_level      * 100);
            SanRex_ptr[9] = (int)(OC_Idc_ratio      * 100);

            SanRex_ptr[10] = (int)(OV_Vdc_level     * 100);
            SanRex_ptr[11] = (int)(OV_ratio_src     * 100);
            SanRex_ptr[12] = (int)(UV_ratio_src     * 100);
            SanRex_ptr[13] = (int)(INTER_ratio_src  * 100);
            SanRex_ptr[14] = (int)(OV_ratio_src_rms * 100);
            SanRex_ptr[15] = (int)(UV_ratio_src_rms * 100);
            SanRex_ptr[16] = (int)(OC_ratio         * 100);
            SanRex_ptr[17] = (int)(OL_ratio         * 100);
            SanRex_ptr[18] = (int)(Mode_system      * 100);
            SanRex_ptr[19] = (int)(SCI_WR_Mode      * 100);

//          SanRex_ptr[20] = Enable_EEPROM_write;
            SanRex_ptr[20] = (int)(OP_MODE          * 1);
            SanRex_ptr[21] = (int)(Run_Stop_com     * 1);
            SanRex_ptr[22] = (int)(Fault_reset_com  * 1);
        }

        else if(SCI_WR_Mode == 2)
        {
            //Inverter /V/I/Power
              SanRex_ptr[0] = (int)(Ref_con_inv_flag            * 100);
              SanRex_ptr[1] = (int)(Vdc_ref_inv                 * 10);
              SanRex_ptr[2] = (int)(Vl_rate                     * 10);
              SanRex_ptr[3] = (int)(Vdc_ref_inv_ratio           * 100);
              SanRex_ptr[4] = (int)(Ip_ref_real_max             * 100);
              SanRex_ptr[5] = (int)(Ic_rate                     * 100);
              SanRex_ptr[6] = (int)(Ip_ref_ratio                * 100);
              SanRex_ptr[7] = (int)(Vdc_ref_con_set             * 10);
              SanRex_ptr[8] = (int)(Vdc_ref_con_set_level       * 100);
              SanRex_ptr[9] = (int)(Idc_ref_comp                * 100);

              SanRex_ptr[10] = (int)(Kp_Vdc_con_ratio     * 100);
              SanRex_ptr[11] = (int)(Ki_Vdc_con_ratio     * 100);
              SanRex_ptr[12] = (int)(Kp_Idc_con_ratio     * 100);
              SanRex_ptr[13] = (int)(Ki_Idc_con_ratio     * 100);
              SanRex_ptr[14] = (int)(Kp_Vdc_ratio         * 100);
              SanRex_ptr[15] = (int)(Ki_Vdc_inv_ratio     * 100);
              SanRex_ptr[16] = (int)(Kp_Ia_ratio          * 100);
              SanRex_ptr[17] = (int)(Ki_Ia_ratio          * 100);
              SanRex_ptr[18] = (int)(Mode_system          * 100);
              SanRex_ptr[19] = (int)(SCI_WR_Mode          * 100);

//            SanRex_ptr[20] = Enable_EEPROM_write;
              SanRex_ptr[20] = (int)(OP_MODE          * 1);
              SanRex_ptr[21] = (int)(Run_Stop_com     * 1);
              SanRex_ptr[22] = (int)(Fault_reset_com  * 1);
       }

        else if(SCI_WR_Mode == 3)
        {
            //Inverter /V/I/Power
              SanRex_ptr[0] = (int)(Kp_Vdc_con                  * 100);
              SanRex_ptr[1] = (int)(Ki_Vdc_con                  * 100);
              SanRex_ptr[2] = (int)(Kp_Idc                      * 10000);
              SanRex_ptr[3] = (int)(Ki_Idc                      * 10000);
              SanRex_ptr[4] = (int)(Kp_Vdc_con_ratio            * 100);
              SanRex_ptr[5] = (int)(Ki_Vdc_con_ratio            * 100);
              SanRex_ptr[6] = (int)(Kp_Idc_con_ratio            * 100);
              SanRex_ptr[7] = (int)(Ki_Idc_con_ratio            * 100);
              SanRex_ptr[8] = (int)(Wn_VC                       * 10);
              SanRex_ptr[9] = (int)(Wc_CC                       * 10);

              SanRex_ptr[10] = (int)(Lc_input                   * 10);
              SanRex_ptr[11] = (int)(Cdc_input                  * 10);
              SanRex_ptr[12] = (int)(Vdc_ref_set_init           * 10);
              SanRex_ptr[13] = (int)(Kp_Vdc_ratio               * 100);
              SanRex_ptr[14] = (int)(Ki_Vdc_inv_ratio           * 100);
              SanRex_ptr[15] = (int)(K_cc_ratio[0]              * 10);
              SanRex_ptr[16] = (int)(K_cc_ratio[1]              * 10);
              SanRex_ptr[17] = (int)(K_cc_ratio[2]              * 10);
              SanRex_ptr[18] = (int)(Mode_system                * 100);
              SanRex_ptr[19] = (int)(SCI_WR_Mode                * 100);

  //          SanRex_ptr[20] = Enable_EEPROM_write;
              SanRex_ptr[20] = (int)(OP_MODE          * 1);
              SanRex_ptr[21] = (int)(Run_Stop_com     * 1);
              SanRex_ptr[22] = (int)(Fault_reset_com  * 1);
        }

        else if(SCI_WR_Mode == 4)
        {
            SanRex_ptr[0] = (int)(EPwm1_CMP_test              * 100);
            SanRex_ptr[1] = (int)(EPwm2_CMP_test              * 100);
            SanRex_ptr[2] = (int)(Ta_con_test1                * 10);
            SanRex_ptr[3] = (int)(Flag_gating_test            * 100);
            SanRex_ptr[4] = (int)(VF_vtg_max                  * 10);
//            SanRex_ptr[4] = (int)(VF_vtg_max_no_Vdc           * 100);


            SanRex_ptr[5] = (int)(Flag_gating_VF_TEST         * 100);
            SanRex_ptr[6] = (int)(OV_set_Vin_test             * 100);
            SanRex_ptr[7] = (int)(OC_Idc_set_test             * 100);
            SanRex_ptr[8] = (int)(OV_set_Vdc_test             * 10);
            SanRex_ptr[9] = (int)(OC_set_test                 * 100);

            SanRex_ptr[10] = (int)(DO7_output                 * 100);
            SanRex_ptr[11] = (int)(DO6_output                 * 100);
            SanRex_ptr[12] = (int)(DO5_output                 * 100);
            SanRex_ptr[13] = (int)(DO4_output                 * 100);
            SanRex_ptr[14] = (int)(DO3_output                 * 100);
            SanRex_ptr[15] = (int)(DO2_output                 * 100);
            SanRex_ptr[16] = (int)(DO1_output                 * 100);
            SanRex_ptr[17] = (int)(Mode_test                  * 100);
            SanRex_ptr[18] = (int)(Mode_system                * 100);
            SanRex_ptr[19] = (int)(SCI_WR_Mode                * 100);

//          SanRex_ptr[20] = Enable_EEPROM_write;
            SanRex_ptr[20] = (int)(OP_MODE          * 1);
            SanRex_ptr[21] = (int)(Run_Stop_com     * 1);
            SanRex_ptr[22] = (int)(Fault_reset_com  * 1);
        }

        else if(SCI_WR_Mode == 5)
        {
            SanRex_ptr[0] = (int)(Vin_max                  * 100);
            SanRex_ptr[1] = (int)(Vin_min                  * 100);
            SanRex_ptr[2] = (int)(Idc_max                  * 100);
            SanRex_ptr[3] = (int)(Vdc_max                  * 10);
            SanRex_ptr[4] = (int)(Vl_rate                  * 10);
            SanRex_ptr[5] = (int)(Ic_rate                  * 100);
            SanRex_ptr[6] = (int)(Pout_rate                * 100);
            SanRex_ptr[7] = (int)(Vdc_ref_inv              * 10);
            SanRex_ptr[8] = (int)(Ip_ref_real_max          * 100);
            SanRex_ptr[9] = (int)(Vdc_ref_con_set          * 10);

            SanRex_ptr[10] = (int)(OV_set_Vin                 * 100);
            SanRex_ptr[11] = (int)(UV_set_Vin                 * 100);
            SanRex_ptr[12] = (int)(OC_Idc_set                 * 100);
            SanRex_ptr[13] = (int)(OV_set_Vdc                 * 10);
            SanRex_ptr[14] = (int)(OV_set_src                 * 10);
            SanRex_ptr[15] = (int)(UV_set_src                 * 10);
            SanRex_ptr[16] = (int)(INTER_set_src              * 100);
            SanRex_ptr[17] = (int)(OC_set                     * 100);
            SanRex_ptr[18] = (int)(Overload_Pout              * 100);
            SanRex_ptr[19] = (int)(SCI_WR_Mode                * 100);

//          SanRex_ptr[20] = Enable_EEPROM_write;
            SanRex_ptr[20] = (int)(OP_MODE          * 1);
            SanRex_ptr[21] = (int)(Run_Stop_com     * 1);
            SanRex_ptr[22] = (int)(Fault_reset_com  * 1);
        }

        else if(SCI_WR_Mode == 6)
        {
            //Inverter /V/I/Power
              SanRex_ptr[0] = (int)(Kp_Vde_ff                   * 100);
              SanRex_ptr[1] = (int)(Kp_Vqe_ff                   * 100);
              SanRex_ptr[2] = (int)(Kp_Ide_ff                   * 100);
              SanRex_ptr[3] = (int)(Kp_Iqe_ff                   * 100);
              SanRex_ptr[4] = (int)(Ide_ref_Cf                  * 100);
              SanRex_ptr[5] = (int)(Iqe_ref_Cf                  * 100);
              SanRex_ptr[6] = (int)(Ide_ref_Cf                  * 100);
              SanRex_ptr[7] = (int)(Iqe_ref_Cf                  * 100);
              SanRex_ptr[8] = (int)(Wn_VC                       * 10);
              SanRex_ptr[9] = (int)(Wc_CC                       * 10);

              SanRex_ptr[10] = (int)(Lc_input                   * 10);
              SanRex_ptr[11] = (int)(Cdc_input                  * 10);
              SanRex_ptr[12] = (int)(Vdc_ref_set_init           * 10);
              SanRex_ptr[13] = (int)(Kp_Vdc_ratio               * 100);
              SanRex_ptr[14] = (int)(Ki_Vdc_inv_ratio           * 100);
              SanRex_ptr[15] = (int)(K_cc_ratio[0]              * 10);
              SanRex_ptr[16] = (int)(K_cc_ratio[1]              * 10);
              SanRex_ptr[17] = (int)(K_cc_ratio[2]              * 10);
              SanRex_ptr[18] = (int)(Mode_system                * 100);
              SanRex_ptr[19] = (int)(SCI_WR_Mode                * 100);

//          SanRex_ptr[20] = Enable_EEPROM_write;
              SanRex_ptr[20] = (int)(OP_MODE          * 1);
              SanRex_ptr[21] = (int)(Run_Stop_com     * 1);
              SanRex_ptr[22] = (int)(Fault_reset_com  * 1);
        }

        else if(SCI_WR_Mode == 7)
        {
            //Inverter /V/I/Power
              SanRex_ptr[0] = (int)(T_dead_input                * 100);
              SanRex_ptr[1] = (int)(T_dead_con_input            * 100);
              SanRex_ptr[2] = (int)(T_dead_comp_input           * 100);
              SanRex_ptr[3] = (int)(mode_Va_PLL3                * 100);
              SanRex_ptr[4] = (int)(time_check_cnt              * 100);
              SanRex_ptr[5] = (int)(Flag_Grid_err               * 100);
              SanRex_ptr[6] = (int)(EPwm1_CMP_test              * 100);
              SanRex_ptr[7] = (int)(EPwm2_CMP_test              * 100);
              SanRex_ptr[8] = (int)(flag_Iqe_ref_flt            * 100);
              SanRex_ptr[9] = (int)(Kp_Idc_ref_Cf               * 10000);

              SanRex_ptr[10] = (int)(FL_Vin                     * 1);
              SanRex_ptr[11] = (int)(FL_Idc                     * 1);
              SanRex_ptr[12] = (int)(FL_A_ref                   * 1);
              SanRex_ptr[13] = (int)(FL_Vdc                     * 1);
              SanRex_ptr[14] = (int)(FL_Va                      * 1);
              SanRex_ptr[15] = (int)(FL_Ia                      * 1);
              SanRex_ptr[16] = (int)(flag_control_parameter             * 100);
              SanRex_ptr[17] = (int)(Idc_ref_comp               * 100);
              SanRex_ptr[18] = (int)(SCI_WR_setting             * 100);
              SanRex_ptr[19] = (int)(SCI_WR_Mode                * 100);

  //          SanRex_ptr[20] = Enable_EEPROM_write;
              SanRex_ptr[20] = (int)(OP_MODE          * 1);
              SanRex_ptr[21] = (int)(Run_Stop_com     * 1);
              SanRex_ptr[22] = (int)(Fault_reset_com  * 1);
        }

        else if(SCI_WR_Mode == 8)
        {
              //Inverter /V/I/Power
              SanRex_ptr[0] = (int)(Wn_VC                   * 10);
              SanRex_ptr[1] = (int)(Kp_Vdc_ratio            * 10);
              SanRex_ptr[2] = (int)(Ki_Vdc_inv_ratio        * 10);
              SanRex_ptr[3] = (int)(Wc_CC                   * 10);
              SanRex_ptr[4] = (int)(K_cc_ratio[0]           * 10);
              SanRex_ptr[5] = (int)(K_cc_ratio[1]           * 10);
              SanRex_ptr[6] = (int)(K_cc_ratio[2]           * 10);
              SanRex_ptr[7] = (int)(K_cc_ratio[3]           * 10);
              SanRex_ptr[8] = (int)(K_cc_ratio[4]           * 10);
              SanRex_ptr[9] = (int)(K_cc_ratio[5]           * 10);

              SanRex_ptr[10] = (int)(Kp_Ia_ratio            * 10);
              SanRex_ptr[11] = (int)(Ki_Ia_ratio            * 10);
              SanRex_ptr[12] = (int)(Kp_Ia_ratio_D          * 10);
              SanRex_ptr[13] = (int)(Ki_Ia_ratio_D          * 10);
              SanRex_ptr[14] = (int)(voltage_control_inv3_cnt_max  * 100);
              SanRex_ptr[15] = (int)(Flag_over_check        * 100);
              SanRex_ptr[16] = (int)(flag_control_parameter * 100);
              SanRex_ptr[17] = (int)(Idc_ref_comp_input     * 100);
              SanRex_ptr[18] = (int)(SCI_WR_setting         * 100);
              SanRex_ptr[19] = (int)(SCI_WR_Mode            * 100);

  //          SanRex_ptr[20] = Enable_EEPROM_write;
              SanRex_ptr[20] = (int)(OP_MODE          * 1);
              SanRex_ptr[21] = (int)(Run_Stop_com     * 1);
              SanRex_ptr[22] = (int)(Fault_reset_com  * 1);
        }

        else if(SCI_WR_Mode == 9)
        {
              //Inverter /V/I/Power
              SanRex_ptr[0] = (int)(FL_Vin                  * 1);
              SanRex_ptr[1] = (int)(FL_Idc                  * 1);
              SanRex_ptr[2] = (int)(FL_A_ref                * 1);
              SanRex_ptr[3] = (int)(FL_Vdc                  * 1);
              SanRex_ptr[4] = (int)(FL_Va                   * 1);
              SanRex_ptr[5] = (int)(FL_Ia                   * 1);
              SanRex_ptr[6] = (int)(FL_s_volt               * 1);
              SanRex_ptr[7] = (int)(FL_e_volt               * 1);
              SanRex_ptr[8] = (int)(Fc_I_5th               * 1);
              SanRex_ptr[9] = (int)(Ia_PLL3_harmonic_k     * 100);

              SanRex_ptr[10] = (int)(mode_Va_PLL3            * 100);
              SanRex_ptr[11] = (int)(Flag_Ia_PLL3            * 100);
              SanRex_ptr[12] = (int)(Flag_current_control_inv3          * 100);
              SanRex_ptr[13] = (int)(Flag_Va_PLL3          * 100);
              SanRex_ptr[14] = (int)(voltage_control_inv3_cnt_max  * 100);
              SanRex_ptr[15] = (int)(Flag_over_check        * 100);
              SanRex_ptr[16] = (int)(flag_control_parameter * 100);
              SanRex_ptr[17] = (int)(Idc_ref_comp_input     * 100);
              SanRex_ptr[18] = (int)(SCI_WR_setting         * 100);
              SanRex_ptr[19] = (int)(SCI_WR_Mode            * 100);

  //          SanRex_ptr[20] = Enable_EEPROM_write;
              SanRex_ptr[20] = (int)(OP_MODE          * 1);
              SanRex_ptr[21] = (int)(Run_Stop_com     * 1);
              SanRex_ptr[22] = (int)(Fault_reset_com  * 1);
        }


        else if(SCI_WR_Mode == 10)
        {
              //Inverter /V/I/Power
              SanRex_ptr[0] = (int)(Flag_Ia_PLL3              * 100);
              SanRex_ptr[1] = (int)(Fc_I_5th                  * 1);
              SanRex_ptr[2] = (int)(Ia_PLL3_harmonic_k1       * 100);
              SanRex_ptr[3] = (int)(Ia_PLL3_harmonic_k2       * 100);
              SanRex_ptr[4] = (int)(Ia_PLL3_harmonic_k3       * 100);
              SanRex_ptr[5] = (int)(Kp_CC_Grid_comp_5th       * 10);
              SanRex_ptr[6] = (int)(Ki_CC_Grid_comp_5th       * 10);
              SanRex_ptr[7] = (int)(Kp_5th_ref                * 100);
              SanRex_ptr[8] = (int)(Flag_scia_cpu1_cpu2       * 100);
              SanRex_ptr[9] = (int)(OP_MODE                   * 100);

              SanRex_ptr[10] = (int)(mode_Va_PLL3            * 100);
              SanRex_ptr[11] = (int)(Flag_Ia_PLL3            * 100);
              SanRex_ptr[12] = (int)(Flag_current_control_inv3          * 100);
              SanRex_ptr[13] = (int)(Flag_Va_PLL3          * 100);
              SanRex_ptr[14] = (int)(voltage_control_inv3_cnt_max  * 100);
              SanRex_ptr[15] = (int)(Flag_over_check        * 100);
              SanRex_ptr[16] = (int)(flag_control_parameter * 100);
              SanRex_ptr[17] = (int)(Idc_ref_comp_input     * 100);
              SanRex_ptr[18] = (int)(SCI_WR_setting         * 100);
              SanRex_ptr[19] = (int)(SCI_WR_Mode            * 100);

  //          SanRex_ptr[20] = Enable_EEPROM_write;
              SanRex_ptr[20] = (int)(OP_MODE          * 1);
              SanRex_ptr[21] = (int)(Run_Stop_com     * 1);
              SanRex_ptr[22] = (int)(Fault_reset_com  * 1);
        }

        else if(SCI_WR_Mode == 11)
        {
              //Inverter /V/I/Power
              SanRex_ptr[0] = (int)(Flag_Act_islanding         * 100);
              SanRex_ptr[1] = (int)(Freq_high                  * 100);
              SanRex_ptr[2] = (int)(Freq_low                   * 100);
              SanRex_ptr[3] = (int)(Ia_PLL3_harmonic_k2       * 100);
              SanRex_ptr[4] = (int)(Ia_PLL3_harmonic_k3       * 100);
              SanRex_ptr[5] = (int)(Kp_CC_Grid_comp_5th       * 10);
              SanRex_ptr[6] = (int)(Ki_CC_Grid_comp_5th       * 10);
              SanRex_ptr[7] = (int)(Kp_5th_ref                * 100);
              SanRex_ptr[8] = (int)(Flag_scia_cpu1_cpu2       * 100);
              SanRex_ptr[9] = (int)(OP_MODE                   * 100);

              SanRex_ptr[10] = (int)(mode_Va_PLL3            * 100);
              SanRex_ptr[11] = (int)(Flag_Ia_PLL3            * 100);
              SanRex_ptr[12] = (int)(Flag_current_control_inv3          * 100);
              SanRex_ptr[13] = (int)(Flag_Va_PLL3          * 100);
              SanRex_ptr[14] = (int)(voltage_control_inv3_cnt_max  * 100);
              SanRex_ptr[15] = (int)(Flag_over_check        * 100);
              SanRex_ptr[16] = (int)(flag_control_parameter * 100);
              SanRex_ptr[17] = (int)(Idc_ref_comp_input     * 100);
              SanRex_ptr[18] = (int)(SCI_WR_setting         * 100);
              SanRex_ptr[19] = (int)(SCI_WR_Mode            * 100);

  //          SanRex_ptr[20] = Enable_EEPROM_write;
              SanRex_ptr[20] = (int)(OP_MODE          * 1);
              SanRex_ptr[21] = (int)(Run_Stop_com     * 1);
              SanRex_ptr[22] = (int)(Fault_reset_com  * 1);
        }
        else
        {
            //Inverter Scale
            SanRex_ptr[0] = (int)(Scale_Vin_ratio   * 100);
            SanRex_ptr[1] = (int)(Scale_Idc_ratio   * 100);
            SanRex_ptr[2] = (int)(Scale_A_ref_ratio * 100);
            SanRex_ptr[3] = (int)(Scale_Vdc_ratio   * 100);
            SanRex_ptr[4] = (int)(Scale_Esa_ratio   * 100);
            SanRex_ptr[5] = (int)(Scale_Esb_ratio   * 100);
            SanRex_ptr[6] = (int)(Scale_Esc_ratio   * 100);
            SanRex_ptr[7] = (int)(Scale_Ia_ratio    * 100);
            SanRex_ptr[8] = (int)(Scale_Ib_ratio    * 100);
            SanRex_ptr[9] = (int)(Scale_Ic_ratio    * 100);

            SanRex_ptr[10] = (int)(Vin_offset     * 100);
            SanRex_ptr[11] = (int)(Idc_offset     * 100);
            SanRex_ptr[12] = (int)(A_ref_offset   * 100);
            SanRex_ptr[13] = (int)(Vdc_offset     * 100);
            SanRex_ptr[14] = (int)(Ia_offset_comp * 100);
            SanRex_ptr[15] = (int)(Ib_offset_comp * 100);
            SanRex_ptr[16] = (int)(Ic_offset_comp * 100);
            SanRex_ptr[17] = (int)(Idc_ref_comp   * 100);
            SanRex_ptr[18] = (int)(Mode_system    * 100);
            SanRex_ptr[19] = (int)(SCI_WR_Mode    * 100);

//          SanRex_ptr[20] = Enable_EEPROM_write;
            SanRex_ptr[20] = (int)(OP_MODE          * 1);
            SanRex_ptr[21] = (int)(Run_Stop_com     * 1);
            SanRex_ptr[22] = (int)(Fault_reset_com  * 1);

        }

#endif

        // 2.   Mode_system_input       = 0         -> 1
        // 3.   Mode_test               = 0         -> no action
        // 4.   Flag_pwm_inv_test2      = 0         -> 1
        // 5.   Ta_inv_test2            = 0         -> 1
        // 6.   Tb_inv_test2            = 0         -> 1
        // 7.   Tc_inv_test2            = 0         -> 1
#if 0
        SanRex_ptr[0] = (int)(Scale_Vin_ratio*100);
        SanRex_ptr[1] = (int)(Scale_Idc_ratio*100);
        SanRex_ptr[2] = (int)(Scale_A_ref_ratio*100);
        SanRex_ptr[3] = (int)(Scale_Vdc_ratio*100);
        SanRex_ptr[4] = (int)(Scale_Esa_ratio*100);
        SanRex_ptr[5] = (int)(Scale_Ia_ratio*100);
        SanRex_ptr[6] = (int)(Kp_Vdc_con_ratio*100);
        SanRex_ptr[7] = (int)(Ki_Vdc_con_ratio*100);
        SanRex_ptr[8] = (int)(Kp_Idc_con_ratio*100);
        SanRex_ptr[9] = (int)(Ki_Idc_con_ratio*100);

        SanRex_ptr[10] = (int)(Vin_offset_input*100);
        SanRex_ptr[11] = (int)(Idc_offset_input*100);
        SanRex_ptr[12] = (int)(A_ref_offset_input*100);
        SanRex_ptr[13] = (int)(Vdc_offset_input*100);
        SanRex_ptr[14] = (int)(Scale_Esb_ratio*100);
        SanRex_ptr[15] = (int)(Scale_Ic_ratio*100);
        SanRex_ptr[16] = (int)(Kp_Vdc_ratio*100);
        SanRex_ptr[17] = (int)(Ki_Vdc_inv_ratio*100);
        SanRex_ptr[18] = (int)(Kp_Ia_ratio*100);
        SanRex_ptr[19] = (int)(Ki_Ia_ratio*100);

        SanRex_ptr[20] = Enable_EEPROM_write;
#endif

        // 2.   Mode_system_input       = 0         -> 1
        // 3.   Mode_test               = 0         -> no action
        // 4.   Flag_pwm_inv_test2      = 0         -> 1
        // 5.   Ta_inv_test2            = 0         -> 1
        // 6.   Tb_inv_test2            = 0         -> 1
        // 7.   Tc_inv_test2            = 0         -> 1
#if 0
        //phase shift test
        SanRex_ptr[0] = (int)(Mode_system_input * 100);
        SanRex_ptr[1] = (int)(Mode_test         * 100);
        SanRex_ptr[2] = (int)(DO1_output        * 100);
        SanRex_ptr[3] = (int)(Vdc_ref_con_set   * 10);
        SanRex_ptr[4] = (int)(Idc_ref_comp      * 100);
        SanRex_ptr[5] = (int)(Idc_limit_con     * 100);
        SanRex_ptr[6] = (int)(Flag_gating_test  * 100);
        SanRex_ptr[7] = (int)(OV_set_Vin_test   * 100);
        SanRex_ptr[8] = (int)(OC_Idc_set_test   * 100);
        SanRex_ptr[9] = (int)(OV_set_Vdc_test   * 10);

        SanRex_ptr[10] = (int)(Mode_system_input    * 100);
        SanRex_ptr[11] = (int)(Mode_test            * 100);
        SanRex_ptr[12] = (int)(DO2_output           * 100);
        SanRex_ptr[13] = (int)(VF_vtg_max           * 10);
        SanRex_ptr[14] = (int)(Flag_gating_VF_TEST  * 100);
        SanRex_ptr[15] = (int)(OC_set_test          * 100);
        SanRex_ptr[16] = (int)(DO3_output           * 100);

//        SanRex_ptr[17] = (int)(DO4_output           * 100);
//        SanRex_ptr[18] = (int)(DO5_output          * 100);
        SanRex_ptr[17] = (int)(EPwm1_CMP_test           * 100);
        SanRex_ptr[18] = (int)(EPwm2_CMP_test          * 100);
        SanRex_ptr[19] = (int)(Ta_con_test1        * 10);

        SanRex_ptr[20] = Enable_EEPROM_write;
#endif


#if 0
        //one pulse test
        SanRex_ptr[0] = (int)(Mode_system_input * 100);
        SanRex_ptr[1] = (int)(Mode_test         * 100);
        SanRex_ptr[2] = (int)(DO1_output        * 100);
        SanRex_ptr[3] = (int)(Flag_gating_test   * 100);
        SanRex_ptr[4] = (int)(Ta_con_test1      * 10);
        SanRex_ptr[5] = (int)(Ta_con_test1      * 10);
        SanRex_ptr[6] = (int)(Tb_con_test1      * 10);
        SanRex_ptr[7] = (int)(Tb_con_test1      * 10);
        SanRex_ptr[8] = (int)(Tc_con_test1      * 10);
        SanRex_ptr[9] = (int)(Tc_con_test1      * 10);

        SanRex_ptr[10] = (int)(Mode_system_input    * 100);
        SanRex_ptr[11] = (int)(Mode_test            * 100);
        SanRex_ptr[12] = (int)(DO2_output           * 100);
        SanRex_ptr[13] = (int)(Flag_gating_test_cnt_max           * 100);
        SanRex_ptr[14] = (int)(Flag_pwm_1P          * 100);
        SanRex_ptr[15] = (int)(Flag_pwm_1N          * 100);
        SanRex_ptr[16] = (int)(Flag_pwm_2P          * 100);
        SanRex_ptr[17] = (int)(Flag_pwm_2N          * 100);
        SanRex_ptr[18] = (int)(Flag_pwm_3P          * 100);
        SanRex_ptr[19] = (int)(Flag_pwm_3N          * 100);

        SanRex_ptr[20] = Enable_EEPROM_write;
#endif

        MODBUS_transmitt_buffer[0]='M';
        MODBUS_transmitt_buffer[1]='S';
        MODBUS_transmitt_buffer[2]=0x20;
    }

    else if(hyun_flag==5)
    {
        SanRex_ptr[0] = (int)(Scale_Vin_ratio*10);
        SanRex_ptr[1] = (int)(Scale_Idc_ratio*10);
        SanRex_ptr[2] = (int)(Scale_A_ref_ratio*10);
        SanRex_ptr[3] = (int)(Scale_Vdc_ratio*10);
        SanRex_ptr[4] = (int)(Scale_Esa_ratio*10);
        SanRex_ptr[5] = (int)(Scale_Ia_ratio*10);
        SanRex_ptr[6] = (int)(Kp_Vdc_con_ratio*10);
        SanRex_ptr[7] = (int)(Ki_Vdc_con_ratio*10);
        SanRex_ptr[8] = (int)(Kp_Idc_con_ratio*10);
        SanRex_ptr[9] = (int)(Ki_Idc_con_ratio*10);

        SanRex_ptr[10] = (int)(Vin_offset_input*10);
        SanRex_ptr[11] = (int)(Idc_offset_input*10);
        SanRex_ptr[12] = (int)(A_ref_offset_input*10);
        SanRex_ptr[13] = (int)(Vdc_offset_input*10);
        SanRex_ptr[14] = (int)(Esa_offset_comp_input*10);
        SanRex_ptr[15] = (int)(Ia_offset_comp_input*10);
        SanRex_ptr[16] = (int)(Kp_Vdc_ratio*10);
        SanRex_ptr[17] = (int)(Ki_Vdc_inv_ratio*10);
        SanRex_ptr[18] = (int)(Kp_Ia_ratio*10);
        SanRex_ptr[19] = (int)(Ki_Ia_ratio*10);

//          SanRex_ptr[20] = Enable_EEPROM_write;
        SanRex_ptr[20] = (int)(OP_MODE          * 1);
        SanRex_ptr[21] = (int)(Run_Stop_com     * 1);
        SanRex_ptr[22] = (int)(Fault_reset_com  * 1);

        MODBUS_transmitt_buffer[0]='M';
        MODBUS_transmitt_buffer[1]='K';
        MODBUS_transmitt_buffer[2]=0x20;
    }

    else if(hyun_flag==9)
    {
        SanRex_ptr[0] = (int)(Vin_max                  * 100);
        SanRex_ptr[1] = (int)(Vin_min                  * 100);
        SanRex_ptr[2] = (int)(Idc_max                  * 100);
        SanRex_ptr[3] = (int)(Vdc_max                  * 10);
        SanRex_ptr[4] = (int)(Vl_rate                  * 10);
        SanRex_ptr[5] = (int)(Ic_rate                  * 100);
        SanRex_ptr[6] = (int)(Pout_rate                * 100);
        SanRex_ptr[7] = (int)(Vdc_ref_inv              * 10);
        SanRex_ptr[8] = (int)(Ip_ref_real_max          * 100);
        SanRex_ptr[9] = (int)(Vdc_ref_con_set          * 10);

        SanRex_ptr[10] = (int)(OV_set_Vin                 * 100);
        SanRex_ptr[11] = (int)(UV_set_Vin                 * 100);
        SanRex_ptr[12] = (int)(OC_Idc_set                 * 100);
        SanRex_ptr[13] = (int)(OV_set_Vdc                 * 10);
        SanRex_ptr[14] = (int)(OV_set_src                 * 10);
        SanRex_ptr[15] = (int)(UV_set_src                 * 10);
        SanRex_ptr[16] = (int)(INTER_set_src              * 100);
        SanRex_ptr[17] = (int)(OC_set                     * 100);
        SanRex_ptr[18] = (int)(Overload_Pout              * 100);
        SanRex_ptr[19] = (int)(SCI_WR_Mode                * 100);

//          SanRex_ptr[20] = Enable_EEPROM_write;
        SanRex_ptr[20] = (int)(OP_MODE          * 1);
        SanRex_ptr[21] = (int)(Run_Stop_com     * 1);
        SanRex_ptr[22] = (int)(Fault_reset_com  * 1);

        MODBUS_transmitt_buffer[0]='M';
        MODBUS_transmitt_buffer[1]='E';
        MODBUS_transmitt_buffer[2]=0x20;
    }

#if 0
    else if(0x20 <= hyun_flag <= 0x29)
    {
        SanRex_ptr[0]  = History[hyun_flag-0x20][0];
        SanRex_ptr[1]  = History[hyun_flag-0x20][1];
        SanRex_ptr[2]  = History[hyun_flag-0x20][2];
        SanRex_ptr[3]  = History[hyun_flag-0x20][3];
        SanRex_ptr[4]  = History[hyun_flag-0x20][4];
        SanRex_ptr[5]  = History[hyun_flag-0x20][5];
        SanRex_ptr[6]  = History[hyun_flag-0x20][6];
        SanRex_ptr[7]  = History[hyun_flag-0x20][7];
        SanRex_ptr[8]  = History[hyun_flag-0x20][8];
        SanRex_ptr[9]  = History[hyun_flag-0x20][9];
        SanRex_ptr[10] = History[hyun_flag-0x20][10];
        SanRex_ptr[11] = History[hyun_flag-0x20][11];
        SanRex_ptr[12] = History[hyun_flag-0x20][12];
        SanRex_ptr[13] = History[hyun_flag-0x20][13];
        SanRex_ptr[14] = History[hyun_flag-0x20][14];
        SanRex_ptr[15] = History[hyun_flag-0x20][15];
        SanRex_ptr[16] = History[hyun_flag-0x20][16];
        SanRex_ptr[17] = History[hyun_flag-0x20][17];
        SanRex_ptr[18] = History[hyun_flag-0x20][18];
        SanRex_ptr[19] = History[hyun_flag-0x20][19];

        SanRex_ptr[20] = 0;
        SanRex_ptr[21] = 0;
        SanRex_ptr[22] = 0;
        SanRex_ptr[23] = 0;

        MODBUS_transmitt_buffer[0]  = 'H';
        MODBUS_transmitt_buffer[1]  = 'T';
        MODBUS_transmitt_buffer[2]  = hyun_flag;
    }
#endif
        MODBUS_transmitt_buffer[3]  = '0';
        MODBUS_transmitt_buffer[4]  = '0';
        MODBUS_transmitt_buffer[5]  = 0x20;

#if 0
    for(i=0; i< 21; i++) // Make TransmittBuffer
    {
        imsi_data_bytehigh = ((SanRex_ptr[i] & 0xff00)>>8) & 0x00ff;
        imsi_data_bytelow  = (SanRex_ptr[i] & 0x00ff);

        imsi_data_bytehigh_high = ((imsi_data_bytehigh & 0x00f0) >> 4) & 0x000f;
        imsi_data_bytehigh_low  = (imsi_data_bytehigh & 0x000f);

        imsi_data_bytelow_high = ((imsi_data_bytelow & 0x00f0) >> 4) & 0x000f;
        imsi_data_bytelow_low  = (imsi_data_bytelow & 0x000f);


        if (imsi_data_bytehigh_high > 0x09)
        {   // Convert ASCII CHAR
            MODBUS_transmitt_buffer[(i*5)+6] = imsi_data_bytehigh_high + 0x37;

        } else MODBUS_transmitt_buffer[(i*5)+6] = imsi_data_bytehigh_high + 0x30;

        if (imsi_data_bytehigh_low > 0x09)
        {   // Convert ASCII CHAR
            MODBUS_transmitt_buffer[(i*5)+7] = imsi_data_bytehigh_low + 0x37;

        } else MODBUS_transmitt_buffer[(i*5)+7] = imsi_data_bytehigh_low + 0x30;

        if (imsi_data_bytelow_high > 0x09)
        {   // Convert ASCII CHAR
            MODBUS_transmitt_buffer[(i*5)+8] = imsi_data_bytelow_high + 0x37;

        } else MODBUS_transmitt_buffer[(i*5)+8] = imsi_data_bytelow_high + 0x30;

        if (imsi_data_bytelow_low > 0x09)
        {    // Convert ASCII CHAR
            MODBUS_transmitt_buffer[(i*5)+9] = imsi_data_bytelow_low + 0x37;

        } else MODBUS_transmitt_buffer[(i*5)+9] = imsi_data_bytelow_low + 0x30;

        if (i < 20) MODBUS_transmitt_buffer[(i*5)+10] = 0x2c;
    }


    MODBUS_transmitt_buffer[110]    = 0x0d;
    MODBUS_transmitt_buffer[111]    = 'H';
    MODBUS_transmitt_buffer[112]    = ':';

    transmitt_flag  = 1;
    transmitt_data_length = 113;
#endif


    for(i=0; i< 23; i++) // Make TransmittBuffer
       {
           imsi_data_bytehigh = ((SanRex_ptr[i] & 0xff00)>>8) & 0x00ff;
           imsi_data_bytelow  = (SanRex_ptr[i] & 0x00ff);

           imsi_data_bytehigh_high = ((imsi_data_bytehigh & 0x00f0) >> 4) & 0x000f;
           imsi_data_bytehigh_low  = (imsi_data_bytehigh & 0x000f);

           imsi_data_bytelow_high = ((imsi_data_bytelow & 0x00f0) >> 4) & 0x000f;
           imsi_data_bytelow_low  = (imsi_data_bytelow & 0x000f);


           if (imsi_data_bytehigh_high > 0x09)
           {   // Convert ASCII CHAR
               MODBUS_transmitt_buffer[(i*5)+6] = imsi_data_bytehigh_high + 0x37;

           } else MODBUS_transmitt_buffer[(i*5)+6] = imsi_data_bytehigh_high + 0x30;

           if (imsi_data_bytehigh_low > 0x09)
           {   // Convert ASCII CHAR
               MODBUS_transmitt_buffer[(i*5)+7] = imsi_data_bytehigh_low + 0x37;

           } else MODBUS_transmitt_buffer[(i*5)+7] = imsi_data_bytehigh_low + 0x30;

           if (imsi_data_bytelow_high > 0x09)
           {   // Convert ASCII CHAR
               MODBUS_transmitt_buffer[(i*5)+8] = imsi_data_bytelow_high + 0x37;

           } else MODBUS_transmitt_buffer[(i*5)+8] = imsi_data_bytelow_high + 0x30;

           if (imsi_data_bytelow_low > 0x09)
           {    // Convert ASCII CHAR
               MODBUS_transmitt_buffer[(i*5)+9] = imsi_data_bytelow_low + 0x37;

           } else MODBUS_transmitt_buffer[(i*5)+9] = imsi_data_bytelow_low + 0x30;

           if (i < 22) MODBUS_transmitt_buffer[(i*5)+10] = 0x2c;
       }


       MODBUS_transmitt_buffer[120]    = 0x0d;
       MODBUS_transmitt_buffer[121]    = 'H';
       MODBUS_transmitt_buffer[122]    = ':';


       transmitt_data_length = 123;
      // (CRC16(transmitt_data_length-2,2));
       transmitt_flag  = 1;
}


//---------------------------------------------------------------------------------
void function_SanRex_HT()
{

// SanRex Inverter Protocol
    unsigned char imsi_data_bytehigh=0, imsi_data_bytelow=0;
    unsigned char imsi_data_bytehigh_high=0, imsi_data_bytehigh_low=0,imsi_data_bytelow_high=0, imsi_data_bytelow_low=0 ;
    int i=0;

    function_SanRex_HT_cnt++;

/************************************************ Edit 100517 *************************************************/
    if(0x20 <= hyun_flag <= 0x29)
    {
        SanRex_ptr[0]  = History[hyun_flag-0x20][0];
        SanRex_ptr[1]  = History[hyun_flag-0x20][1];
        SanRex_ptr[2]  = History[hyun_flag-0x20][2];
        SanRex_ptr[3]  = History[hyun_flag-0x20][3];
        SanRex_ptr[4]  = History[hyun_flag-0x20][4];
        SanRex_ptr[5]  = History[hyun_flag-0x20][5];
        SanRex_ptr[6]  = History[hyun_flag-0x20][6];
        SanRex_ptr[7]  = History[hyun_flag-0x20][7];
        SanRex_ptr[8]  = History[hyun_flag-0x20][8];
        SanRex_ptr[9]  = History[hyun_flag-0x20][9];
        SanRex_ptr[10] = History[hyun_flag-0x20][10];
        SanRex_ptr[11] = History[hyun_flag-0x20][11];
        SanRex_ptr[12] = History[hyun_flag-0x20][12];
        SanRex_ptr[13] = History[hyun_flag-0x20][13];
        SanRex_ptr[14] = History[hyun_flag-0x20][14];
        SanRex_ptr[15] = History[hyun_flag-0x20][15];
        SanRex_ptr[16] = History[hyun_flag-0x20][16];
        SanRex_ptr[17] = History[hyun_flag-0x20][17];
        SanRex_ptr[18] = History[hyun_flag-0x20][18];
        SanRex_ptr[19] = History[hyun_flag-0x20][19];

        SanRex_ptr[20] = 0;

        MODBUS_transmitt_buffer[0]  = 'H';
        MODBUS_transmitt_buffer[1]  = 'T';
        MODBUS_transmitt_buffer[2]  = hyun_flag;
    }

        MODBUS_transmitt_buffer[3]  = '0';
        MODBUS_transmitt_buffer[4]  = '0';
        MODBUS_transmitt_buffer[5]  = 0x20;

    for(i=0; i< 21; i++) // Make TransmittBuffer
    {
        imsi_data_bytehigh = ((SanRex_ptr[i] & 0xff00)>>8) & 0x00ff;
        imsi_data_bytelow  = (SanRex_ptr[i] & 0x00ff);

        imsi_data_bytehigh_high = ((imsi_data_bytehigh & 0x00f0) >> 4) & 0x000f;
        imsi_data_bytehigh_low  = (imsi_data_bytehigh & 0x000f);

        imsi_data_bytelow_high = ((imsi_data_bytelow & 0x00f0) >> 4) & 0x000f;
        imsi_data_bytelow_low  = (imsi_data_bytelow & 0x000f);


        if (imsi_data_bytehigh_high > 0x09)
        {   // Convert ASCII CHAR
            MODBUS_transmitt_buffer[(i*5)+6] = imsi_data_bytehigh_high + 0x37;

        } else MODBUS_transmitt_buffer[(i*5)+6] = imsi_data_bytehigh_high + 0x30;

        if (imsi_data_bytehigh_low > 0x09)
        {   // Convert ASCII CHAR
            MODBUS_transmitt_buffer[(i*5)+7] = imsi_data_bytehigh_low + 0x37;

        } else MODBUS_transmitt_buffer[(i*5)+7] = imsi_data_bytehigh_low + 0x30;

        if (imsi_data_bytelow_high > 0x09)
        {   // Convert ASCII CHAR
            MODBUS_transmitt_buffer[(i*5)+8] = imsi_data_bytelow_high + 0x37;

        } else MODBUS_transmitt_buffer[(i*5)+8] = imsi_data_bytelow_high + 0x30;

        if (imsi_data_bytelow_low > 0x09)
        {    // Convert ASCII CHAR
            MODBUS_transmitt_buffer[(i*5)+9] = imsi_data_bytelow_low + 0x37;

        } else MODBUS_transmitt_buffer[(i*5)+9] = imsi_data_bytelow_low + 0x30;

        if (i < 20) MODBUS_transmitt_buffer[(i*5)+10] = 0x2c;
    }


    MODBUS_transmitt_buffer[110]    = 0x0d;
    MODBUS_transmitt_buffer[111]    = 'H';
    MODBUS_transmitt_buffer[112]    = ':';

    transmitt_flag  = 1;
    transmitt_data_length = 113;
}



//---------------------------------------------------------------------------------
void function_SanRex2()
{

// SanRex Inverter Protocol
    unsigned char imsi_data_bytehigh=0, imsi_data_bytelow=0;
    unsigned char imsi_data_bytehigh_high=0, imsi_data_bytehigh_low=0,imsi_data_bytelow_high=0, imsi_data_bytelow_low=0 ;
    int i=0;

/************************************************ Edit 100517 *************************************************/

    if(hyun_flag == 11)
    {  // Edit 100517

        //Inverter Scale
        SanRex_ptr[0] = (int)(Scale_Vin_ratio   * 100);
        SanRex_ptr[1] = (int)(Scale_Idc_ratio   * 100);
        SanRex_ptr[2] = (int)(Scale_A_ref_ratio * 100);
        SanRex_ptr[3] = (int)(Scale_Vdc_ratio   * 100);
        SanRex_ptr[4] = (int)(Scale_Esa_ratio   * 100);
        SanRex_ptr[5] = (int)(Scale_Esb_ratio   * 100);
        SanRex_ptr[6] = (int)(Scale_Esc_ratio   * 100);
        SanRex_ptr[7] = (int)(Scale_Ia_ratio    * 100);
        SanRex_ptr[8] = (int)(Scale_Ib_ratio    * 100);
        SanRex_ptr[9] = (int)(Scale_Ic_ratio    * 100);

        SanRex_ptr[10] = (int)(Vin_offset     * 100);
        SanRex_ptr[11] = (int)(Idc_offset     * 100);
        SanRex_ptr[12] = (int)(A_ref_offset   * 100);
        SanRex_ptr[13] = (int)(Vdc_offset     * 100);
        SanRex_ptr[14] = (int)(Ia_offset_comp * 100);
        SanRex_ptr[15] = (int)(Ib_offset_comp * 100);
        SanRex_ptr[16] = (int)(Ic_offset_comp * 100);
        SanRex_ptr[17] = (int)(Idc_ref_comp   * 100);
        SanRex_ptr[18] = (int)(SCI_WR_setting    * 100);
        SanRex_ptr[19] = (int)(SCI_WR_Mode    * 100);

        SanRex_ptr[20] = Enable_EEPROM_write;
//        SanRex_ptr[20] = (int)(OP_MODE          * 1);
//        SanRex_ptr[21] = (int)(Run_Stop_com     * 1);
//        SanRex_ptr[22] = (int)(Fault_reset_com  * 1);


        MODBUS_transmitt_buffer[0]='T';
        MODBUS_transmitt_buffer[1]='A';
        MODBUS_transmitt_buffer[2]=0x20;
    }
    else if(hyun_flag == 12)
    {

        //Inverter /V/I/Power
        SanRex_ptr[0] = (int)(Vin_max           * 100);
        SanRex_ptr[1] = (int)(Vin_min           * 100);
        SanRex_ptr[2] = (int)(Idc_max           * 100);
        SanRex_ptr[3] = (int)(Vdc_max           * 10);
        SanRex_ptr[4] = (int)(Vl_rate           * 10);
        SanRex_ptr[5] = (int)(Ic_rate           * 100);
        SanRex_ptr[6] = (int)(Pout_rate         * 100);
        SanRex_ptr[7] = (int)(OV_Vin_level      * 100);
        SanRex_ptr[8] = (int)(UV_Vin_level      * 100);
        SanRex_ptr[9] = (int)(OC_Idc_ratio      * 100);

        SanRex_ptr[10] = (int)(OV_Vdc_level     * 100);
        SanRex_ptr[11] = (int)(OV_ratio_src     * 100);
        SanRex_ptr[12] = (int)(UV_ratio_src     * 100);
        SanRex_ptr[13] = (int)(INTER_ratio_src  * 100);
        SanRex_ptr[14] = (int)(OV_ratio_src_rms * 100);
        SanRex_ptr[15] = (int)(UV_ratio_src_rms * 100);
        SanRex_ptr[16] = (int)(OC_ratio         * 100);
        SanRex_ptr[17] = (int)(OL_ratio         * 100);
        SanRex_ptr[18] = (int)(Mode_system      * 100);
        SanRex_ptr[19] = (int)(SCI_WR_Mode      * 100);

        SanRex_ptr[20] = Enable_EEPROM_write;
//        SanRex_ptr[20] = (int)(OP_MODE          * 1);
//        SanRex_ptr[21] = (int)(Run_Stop_com     * 1);
//        SanRex_ptr[22] = (int)(Fault_reset_com  * 1);

        MODBUS_transmitt_buffer[0]='T';
        MODBUS_transmitt_buffer[1]='B';
        MODBUS_transmitt_buffer[2]=0x20;
    }
    else if(hyun_flag == 13)
    {
        //Inverter /V/I/Power
        SanRex_ptr[0] = (int)(Ref_con_inv_flag            * 100);
        SanRex_ptr[1] = (int)(Vdc_ref_inv                 * 10);
        SanRex_ptr[2] = (int)(Vl_rate                     * 10);
        SanRex_ptr[3] = (int)(Vdc_ref_inv_ratio           * 100);
        SanRex_ptr[4] = (int)(Ip_ref_real_max             * 100);
        SanRex_ptr[5] = (int)(Ic_rate                     * 100);
        SanRex_ptr[6] = (int)(Ip_ref_ratio                * 100);
        SanRex_ptr[7] = (int)(Vdc_ref_con_set             * 10);
        SanRex_ptr[8] = (int)(Vdc_ref_con_set_level       * 100);
        SanRex_ptr[9] = (int)(Idc_ref_comp                * 100);

        SanRex_ptr[10] = (int)(Kp_Vdc_con_ratio     * 100);
        SanRex_ptr[11] = (int)(Ki_Vdc_con_ratio     * 100);
        SanRex_ptr[12] = (int)(Kp_Idc_con_ratio     * 100);
        SanRex_ptr[13] = (int)(Ki_Idc_con_ratio     * 100);
        SanRex_ptr[14] = (int)(Kp_Vdc_ratio         * 100);
        SanRex_ptr[15] = (int)(Ki_Vdc_inv_ratio     * 100);
        SanRex_ptr[16] = (int)(Kp_Ia_ratio          * 100);
        SanRex_ptr[17] = (int)(Ki_Ia_ratio          * 100);
        SanRex_ptr[18] = (int)(Mode_system          * 100);
        SanRex_ptr[19] = (int)(SCI_WR_Mode          * 100);

        SanRex_ptr[20] = Enable_EEPROM_write;
//        SanRex_ptr[20] = (int)(OP_MODE          * 1);
//        SanRex_ptr[21] = (int)(Run_Stop_com     * 1);
//        SanRex_ptr[22] = (int)(Fault_reset_com  * 1);

        MODBUS_transmitt_buffer[0]='T';
        MODBUS_transmitt_buffer[1]='C';
        MODBUS_transmitt_buffer[2]=0x20;
    }
    else if(hyun_flag == 14)
    {
        //Inverter /V/I/Power
        SanRex_ptr[0] = (int)(Kp_Vdc_con                  * 100);
        SanRex_ptr[1] = (int)(Ki_Vdc_con                  * 100);
        SanRex_ptr[2] = (int)(Kp_Idc                      * 10000);
        SanRex_ptr[3] = (int)(Ki_Idc                      * 10000);
        SanRex_ptr[4] = (int)(Kp_Vdc_con_ratio            * 100);
        SanRex_ptr[5] = (int)(Ki_Vdc_con_ratio            * 100);
        SanRex_ptr[6] = (int)(Kp_Idc_con_ratio            * 100);
        SanRex_ptr[7] = (int)(Ki_Idc_con_ratio            * 100);
        SanRex_ptr[8] = (int)(Wn_VC                       * 10);
        SanRex_ptr[9] = (int)(Wc_CC                       * 10);

        SanRex_ptr[10] = (int)(Lc_input                   * 10);
        SanRex_ptr[11] = (int)(Cdc_input                  * 10);
        SanRex_ptr[12] = (int)(Vdc_ref_set_init           * 10);
        SanRex_ptr[13] = (int)(Kp_Vdc_ratio               * 100);
        SanRex_ptr[14] = (int)(Ki_Vdc_inv_ratio           * 100);
        SanRex_ptr[15] = (int)(K_cc_ratio[0]              * 10);
        SanRex_ptr[16] = (int)(K_cc_ratio[1]              * 10);
        SanRex_ptr[17] = (int)(K_cc_ratio[2]              * 10);
        SanRex_ptr[18] = (int)(Mode_system                * 100);
        SanRex_ptr[19] = (int)(SCI_WR_Mode                * 100);

        SanRex_ptr[20] = Enable_EEPROM_write;
//        SanRex_ptr[20] = (int)(OP_MODE          * 1);
//        SanRex_ptr[21] = (int)(Run_Stop_com     * 1);
//        SanRex_ptr[22] = (int)(Fault_reset_com  * 1);

        MODBUS_transmitt_buffer[0]='T';
        MODBUS_transmitt_buffer[1]='D';
        MODBUS_transmitt_buffer[2]=0x20;
    }

    else if(hyun_flag == 15)
    {
        SanRex_ptr[0] = (int)(EPwm1_CMP_test              * 100);
        SanRex_ptr[1] = (int)(EPwm2_CMP_test              * 100);
        SanRex_ptr[2] = (int)(Ta_con_test1                * 10);
        SanRex_ptr[3] = (int)(Flag_gating_test            * 100);
        SanRex_ptr[4] = (int)(VF_vtg_max                  * 10);
//            SanRex_ptr[4] = (int)(VF_vtg_max_no_Vdc           * 100);


        SanRex_ptr[5] = (int)(Flag_gating_VF_TEST         * 100);
        SanRex_ptr[6] = (int)(OV_set_Vin_test             * 100);
        SanRex_ptr[7] = (int)(OC_Idc_set_test             * 100);
        SanRex_ptr[8] = (int)(OV_set_Vdc_test             * 10);
        SanRex_ptr[9] = (int)(OC_set_test                 * 100);

        SanRex_ptr[10] = (int)(DO7_output                 * 100);
        SanRex_ptr[11] = (int)(DO6_output                 * 100);
        SanRex_ptr[12] = (int)(DO5_output                 * 100);
        SanRex_ptr[13] = (int)(DO4_output                 * 100);
        SanRex_ptr[14] = (int)(DO3_output                 * 100);
        SanRex_ptr[15] = (int)(DO2_output                 * 100);
        SanRex_ptr[16] = (int)(DO1_output                 * 100);
        SanRex_ptr[17] = (int)(Mode_test                  * 100);
        SanRex_ptr[18] = (int)(Mode_system                * 100);
        SanRex_ptr[19] = (int)(SCI_WR_Mode                * 100);

        SanRex_ptr[20] = Enable_EEPROM_write;
//        SanRex_ptr[20] = (int)(OP_MODE          * 1);
//        SanRex_ptr[21] = (int)(Run_Stop_com     * 1);
//        SanRex_ptr[22] = (int)(Fault_reset_com  * 1);

        MODBUS_transmitt_buffer[0]='T';
        MODBUS_transmitt_buffer[1]='E';
        MODBUS_transmitt_buffer[2]=0x20;
    }

    else if(hyun_flag == 16)
    {
        SanRex_ptr[0] = (int)(Vin_max                  * 100);
        SanRex_ptr[1] = (int)(Vin_min                  * 100);
        SanRex_ptr[2] = (int)(Idc_max                  * 100);
        SanRex_ptr[3] = (int)(Vdc_max                  * 10);
        SanRex_ptr[4] = (int)(Vl_rate                  * 10);
        SanRex_ptr[5] = (int)(Ic_rate                  * 100);
        SanRex_ptr[6] = (int)(Pout_rate                * 100);
        SanRex_ptr[7] = (int)(Vdc_ref_inv              * 10);
        SanRex_ptr[8] = (int)(Ip_ref_real_max          * 100);
        SanRex_ptr[9] = (int)(Vdc_ref_con_set          * 10);

        SanRex_ptr[10] = (int)(OV_set_Vin                 * 100);
        SanRex_ptr[11] = (int)(UV_set_Vin                 * 100);
        SanRex_ptr[12] = (int)(OC_Idc_set                 * 100);
        SanRex_ptr[13] = (int)(OV_set_Vdc                 * 10);
        SanRex_ptr[14] = (int)(OV_set_src                 * 10);
        SanRex_ptr[15] = (int)(UV_set_src                 * 10);
        SanRex_ptr[16] = (int)(INTER_set_src              * 100);
        SanRex_ptr[17] = (int)(OC_set                     * 100);
        SanRex_ptr[18] = (int)(Overload_Pout              * 100);
        SanRex_ptr[19] = (int)(SCI_WR_Mode                * 100);

        SanRex_ptr[20] = Enable_EEPROM_write;
//        SanRex_ptr[20] = (int)(OP_MODE          * 1);
//        SanRex_ptr[21] = (int)(Run_Stop_com     * 1);
//        SanRex_ptr[22] = (int)(Fault_reset_com  * 1);

        MODBUS_transmitt_buffer[0]='T';
        MODBUS_transmitt_buffer[1]='F';
        MODBUS_transmitt_buffer[2]=0x20;
    }

        MODBUS_transmitt_buffer[3]  = '0';
        MODBUS_transmitt_buffer[4]  = '0';
        MODBUS_transmitt_buffer[5]  = 0x20;

    for(i=0; i< 21; i++) // Make TransmittBuffer
    {
        imsi_data_bytehigh = ((SanRex_ptr[i] & 0xff00)>>8) & 0x00ff;
        imsi_data_bytelow  = (SanRex_ptr[i] & 0x00ff);

        imsi_data_bytehigh_high = ((imsi_data_bytehigh & 0x00f0) >> 4) & 0x000f;
        imsi_data_bytehigh_low  = (imsi_data_bytehigh & 0x000f);

        imsi_data_bytelow_high = ((imsi_data_bytelow & 0x00f0) >> 4) & 0x000f;
        imsi_data_bytelow_low  = (imsi_data_bytelow & 0x000f);


        if (imsi_data_bytehigh_high > 0x09)
        {   // Convert ASCII CHAR
            MODBUS_transmitt_buffer[(i*5)+6] = imsi_data_bytehigh_high + 0x37;

        } else MODBUS_transmitt_buffer[(i*5)+6] = imsi_data_bytehigh_high + 0x30;

        if (imsi_data_bytehigh_low > 0x09)
        {   // Convert ASCII CHAR
            MODBUS_transmitt_buffer[(i*5)+7] = imsi_data_bytehigh_low + 0x37;

        } else MODBUS_transmitt_buffer[(i*5)+7] = imsi_data_bytehigh_low + 0x30;

        if (imsi_data_bytelow_high > 0x09)
        {   // Convert ASCII CHAR
            MODBUS_transmitt_buffer[(i*5)+8] = imsi_data_bytelow_high + 0x37;

        } else MODBUS_transmitt_buffer[(i*5)+8] = imsi_data_bytelow_high + 0x30;

        if (imsi_data_bytelow_low > 0x09)
        {    // Convert ASCII CHAR
            MODBUS_transmitt_buffer[(i*5)+9] = imsi_data_bytelow_low + 0x37;

        } else MODBUS_transmitt_buffer[(i*5)+9] = imsi_data_bytelow_low + 0x30;

        if (i < 20) MODBUS_transmitt_buffer[(i*5)+10] = 0x2c;
    }


    MODBUS_transmitt_buffer[110]    = 0x0d;
    MODBUS_transmitt_buffer[111]    = 'H';
    MODBUS_transmitt_buffer[112]    = ':';

    transmitt_flag  = 1;
    transmitt_data_length = 113;
}

void function_WR_SanRex()
{
    char recv_buffer[6]={0x00,0x00,0x00,0x00,0x00,0x00};
    unsigned int add_data, all_data, low_data, high_data;
    int int_data;
    float float_data;
//    float   *temp;

    recv_buffer[0] = asc2hex(MODBUS_receive_buffer[3]);
    recv_buffer[1] = asc2hex(MODBUS_receive_buffer[4]);
    recv_buffer[2] = asc2hex(MODBUS_receive_buffer[6]);
    recv_buffer[3] = asc2hex(MODBUS_receive_buffer[7]);
    recv_buffer[4] = asc2hex(MODBUS_receive_buffer[8]);
    recv_buffer[5] = asc2hex(MODBUS_receive_buffer[9]);

    add_data = (((recv_buffer[0]&0xff) << 4) | recv_buffer[1]&0xff);
    high_data = (((recv_buffer[2]&0xff) << 4) | recv_buffer[3]&0xff);
    low_data = (((recv_buffer[4]&0xff) << 4) | recv_buffer[5]&0xff);
    all_data = ((high_data << 8) | low_data);

    int_data = (int)all_data;
    float_data = (float)int_data;

    add_data_lsc    = add_data;
    all_data_lsc    = all_data;
    float_data_lsc  = (float)int_data;

    if(add_data==0xff)      {   Enable_EEPROM_write=all_data;   }
    else if(add_data==0xfe) {   Init_offset=all_data;   }
    else if(add_data==0xfd) {   Init_scale=all_data;    }
    else if(add_data==0xf1) {   wr_time_Sel_Wr=all_data; }  //RTC initial
    else if(add_data==0xf3) {   wr_time_Set_year=all_data;      }  //RTC year
    else if(add_data==0xf4) {   wr_time_Set_mon_day=all_data;   }  //RTC mon_day
    else if(add_data==0xf5) {   wr_time_Set_hour_min=all_data;  }  //RTC hour_min

    else if(add_data==41) {   Flag_Act_islanding_input=all_data;  }  //RTC hour_min
    else if(add_data==42) {   Freq_shift_ratio_input=all_data;  }  //RTC hour_min

#if 1
    if(SCI_WR_Mode == 0)
    {
        //Inverter Scale
        if(add_data==0)         {   Scale_Vin_ratio      = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==1)    {   Scale_Idc_ratio      = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==2)    {   Scale_A_ref_ratio    = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==3)    {   Scale_Vdc_ratio      = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==4)    {   Scale_Esa_ratio      = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==5)    {   Scale_Esb_ratio      = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==6)    {   Scale_Esc_ratio      = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==7)    {   Scale_Ia_ratio       = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==8)    {   Scale_Ib_ratio       = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==9)    {   Scale_Ic_ratio       = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의

        else if(add_data==10)   {   Vin_offset_input     = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==11)   {   Idc_offset_input     = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==12)   {   A_ref_offset_input   = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==13)   {   Vdc_offset_input     = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==14)   {   Ia_offset_comp_input = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==15)   {   Ib_offset_comp_input = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==16)   {   Ic_offset_comp_input = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==17)   {   Idc_ref_comp_input   = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==18)   {   SCI_WR_setting       = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==19)   {   SCI_WR_Mode          = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의

        else if(add_data==20)   {  if(Flag_gating == 0)  {   OP_MODE=float_data;    }    }
        else if(add_data==21)   {   Run_Stop_com=float_data; }
        else if(add_data==22)   {   Fault_reset_com=float_data; }
    }

    else if(SCI_WR_Mode == 1)
    {
        //Inverter setting
        if(add_data==0)         {   Vin_max              = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==1)    {   Vin_min              = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==2)    {   Idc_max              = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==3)    {   Vdc_max              = (float_data   * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==4)    {   Vl_rate              = (float_data   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==5)    {   Ic_rate              = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==6)    {   Pout_rate            = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==7)    {   OV_Vin_level         = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==8)    {   UV_Vin_level         = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==9)    {   OC_Idc_ratio         = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의

        else if(add_data==10)   {   OV_Vdc_level         = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==11)   {   OV_ratio_src         = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==12)   {   UV_ratio_src         = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==13)   {   INTER_ratio_src      = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==14)   {   OV_ratio_src_rms     = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==15)   {   UV_ratio_src_rms     = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==16)   {   OC_ratio             = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==17)   {   OL_ratio             = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==18)   {   Mode_system_input    = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==19)   {   SCI_WR_Mode          = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의

        else if(add_data==20)   {  if(Flag_gating == 0)  {   OP_MODE=float_data;    }    }
        else if(add_data==21)   {   Run_Stop_com=float_data; }
        else if(add_data==22)   {   Fault_reset_com=float_data; }
    }

    else if(SCI_WR_Mode == 2)
    {
        //Inverter setting
        if(add_data==0)         {   Ref_con_inv_flag        = (int)(float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==1)    {   Vdc_ref_inv_input       = (float_data   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==2)    {   Vl_rate                 = (float_data   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==3)    {   Vdc_ref_inv_ratio       = (float_data   * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==4)    {   Ip_ref_real_max_input   = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==5)    {   Ic_rate                 = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==6)    {   Ip_ref_ratio            = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==7)    {   Vdc_ref_con_set_input   = (float_data   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==8)    {   Vdc_ref_con_set_level   = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==9)    {   Idc_ref_comp_input      = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의

        else if(add_data==10)   {   Kp_Vdc_con_ratio        = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==11)   {   Ki_Vdc_con_ratio        = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==12)   {   Kp_Idc_con_ratio        = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==13)   {   Ki_Idc_con_ratio        = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==14)   {   Kp_Vdc_ratio            = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==15)   {   Ki_Vdc_inv_ratio        = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==16)   {   Kp_Ia_ratio             = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==17)   {   Ki_Ia_ratio             = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==18)   {   Mode_system_input       = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==19)   {   SCI_WR_Mode             = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의

        else if(add_data==20)   {  if(Flag_gating == 0)  {   OP_MODE=float_data;    }    }
        else if(add_data==21)   {   Run_Stop_com=float_data; }
        else if(add_data==22)   {   Fault_reset_com=float_data; }
    }

    else if(SCI_WR_Mode == 3)
    {
        //Inverter setting
        if(add_data==0)         {   Kp_Vdc_con_input        = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==1)    {   Ki_Vdc_con_input        = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==2)    {   Kp_Idc_con_input        = (float_data   * 0.0001); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==3)    {   Ki_Idc_con_input        = (float_data   * 0.0001); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==4)    {   Kp_Vdc_con_ratio        = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==5)    {   Ki_Vdc_con_ratio        = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==6)    {   Kp_Idc_con_ratio        = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==7)    {   Ki_Idc_con_ratio        = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==8)    {   Wn_VC                   = (float_data   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==9)    {   Wc_CC                   = (float_data   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의

        else if(add_data==10)   {   Lc_input                = (float_data  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==11)   {   Cdc_input               = (float_data  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==12)   {   Vdc_ref_set_init        = (float_data  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==13)   {   Kp_Vdc_ratio            = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==14)   {   Ki_Vdc_inv_ratio        = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==15)   {   K_cc_ratio[0]           = (float_data  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==16)   {   K_cc_ratio[1]           = (float_data  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==17)   {   K_cc_ratio[2]           = (float_data  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==18)   {   Mode_system_input       = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==19)   {   SCI_WR_Mode             = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의

        else if(add_data==20)   {  if(Flag_gating == 0)  {   OP_MODE=float_data;    }    }
        else if(add_data==21)   {   Run_Stop_com=float_data; }
        else if(add_data==22)   {   Fault_reset_com=float_data; }
    }

    else if(SCI_WR_Mode == 4)
    {
        //Inverter setting
        if(add_data==0)         {   EPwm1_CMP_test          = (int)(float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==1)    {   EPwm2_CMP_test          = (int)(float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==2)    {   Ta_con_test1            = (int)(float_data   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==3)    {   Flag_gating_test        = (int)(float_data   * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==4)    {   VF_vtg_max              = (float_data   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
//        else if(add_data==4)    {   VF_vtg_max_no_Vdc       = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의

        else if(add_data==5)    {   Flag_gating_VF_TEST     = (int)(float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==6)    {   OV_set_Vin_test         = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==7)    {   OC_Idc_set_test         = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==8)    {   OV_set_Vdc_test         = (float_data   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==9)    {   OC_set_test             = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의

        else if(add_data==10)   {   DO7_output              = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==11)   {   DO6_output              = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==12)   {   DO5_output              = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==13)   {   DO4_output              = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==14)   {   DO3_output              = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==15)   {   DO2_output              = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==16)   {   DO1_output              = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==17)   {   Mode_test               = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==18)   {   Mode_system_input       = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==19)   {   SCI_WR_Mode             = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의

        else if(add_data==20)   {  if(Flag_gating == 0)  {   OP_MODE=float_data;    }    }
        else if(add_data==21)   {   Run_Stop_com=float_data; }
        else if(add_data==22)   {   Fault_reset_com=float_data; }
    }

    else if(SCI_WR_Mode == 6)
    {
        //Inverter setting
        if(add_data==0)         {   Kp_Vde_ff               = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==1)    {   Kp_Vqe_ff               = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==2)    {   Kp_Ide_ff               = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==3)    {   Kp_Iqe_ff               = (float_data   * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==4)    {   Ide_ref_Cf              = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==5)    {   Iqe_ref_Cf              = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==6)    {   Ide_ref_Cf              = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==7)    {   Iqe_ref_Cf              = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==8)    {   Wn_VC                   = (float_data   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==9)    {   Wc_CC                   = (float_data   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의

        else if(add_data==10)   {   Lc_input                = (float_data  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==11)   {   Cdc_input               = (float_data  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==12)   {   Vdc_ref_set_init        = (float_data  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==13)   {   Kp_Vdc_ratio            = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==14)   {   Ki_Vdc_inv_ratio        = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==15)   {   K_cc_ratio[0]           = (float_data  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==16)   {   K_cc_ratio[1]           = (float_data  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==17)   {   K_cc_ratio[2]           = (float_data  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==18)   {   Mode_system_input       = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==19)   {   SCI_WR_Mode             = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의

        else if(add_data==20)   {  if(Flag_gating == 0)  {   OP_MODE=float_data;    }    }
        else if(add_data==21)   {   Run_Stop_com=float_data; }
        else if(add_data==22)   {   Fault_reset_com=float_data; }
    }

    else if(SCI_WR_Mode == 7)
    {
        //Inverter setting
        if(add_data==0)         {   T_dead_input            = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==1)    {   T_dead_con_input        = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==2)    {   T_dead_comp_input       = (float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==3)    {   mode_Va_PLL3            = (int)(float_data   * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==4)    {   time_check_cnt          = (int)(float_data   * 0.01); }  //CNT_max   eeprom setting    사용자 테스트 주소 정의
        else if(add_data==5)    {   Flag_Grid_err           = (int)(float_data   * 0.01); }  //CNT_max_con   eeprom setting    사용자 테스트 주소 정의
        else if(add_data==6)    {   EPwm1_CMP_test          = (int)(float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==7)    {   EPwm2_CMP_test          = (int)(float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==8)    {   flag_Iqe_ref_flt        = (int)(float_data   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==9)    {   Kp_Idc_ref_Cf           = (float_data   * 0.0001); }  //eeprom setting    사용자 테스트 주소 정의

        else if(add_data==10)   {   FL_Vin               = (float_data  * 1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==11)   {   FL_Idc               = (float_data  * 1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==12)   {   FL_A_ref             = (float_data  * 1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==13)   {   FL_Vdc               = (float_data  * 1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==14)   {   FL_Va                = (float_data  * 1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==15)   {   FL_Ia                = (float_data  * 1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==16)   {   flag_control_parameter       = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==17)   {   Idc_ref_comp_input   = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==18)   {   SCI_WR_setting       = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data==19)   {   SCI_WR_Mode          = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의

        else if(add_data==20)   {  if(Flag_gating == 0)  {   OP_MODE=float_data;    }    }
        else if(add_data==21)   {   Run_Stop_com=float_data; }
        else if(add_data==22)   {   Fault_reset_com=float_data; }
    }

    else if(SCI_WR_Mode == 8)
     {
         //Inverter setting
         if(add_data==0)         {   Wn_VC               = (float_data   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==1)    {   Kp_Vdc_ratio        = (float_data   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==2)    {   Ki_Vdc_inv_ratio    = (float_data   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==3)    {   Wc_CC               = (float_data   * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==4)    {   K_cc_ratio[0]       = (float_data   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==5)    {   K_cc_ratio[1]       = (float_data   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==6)    {   K_cc_ratio[2]       = (float_data   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==7)    {   K_cc_ratio[3]       = (float_data   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==8)    {   K_cc_ratio[4]       = (float_data   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==9)    {   K_cc_ratio[5]       = (float_data   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의

         else if(add_data==10)   {   Kp_Ia_ratio          = (float_data  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==11)   {   Ki_Ia_ratio          = (float_data  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==12)   {   Kp_Ia_ratio_D        = (float_data  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==13)   {   Ki_Ia_ratio_D        = (float_data  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==14)   {   voltage_control_inv3_cnt_max     = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==15)   {   Flag_over_check        = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==16)   {   flag_control_parameter = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==17)   {   Idc_ref_comp_input     = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==18)   {   SCI_WR_setting         = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==19)   {   SCI_WR_Mode            = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의

         else if(add_data==20)   {  if(Flag_gating == 0)  {   OP_MODE=float_data;    }    }
         else if(add_data==21)   {   Run_Stop_com=float_data; }
         else if(add_data==22)   {   Fault_reset_com=float_data; }
     }


    else if(SCI_WR_Mode == 9)
     {
         //Inverter setting
         if(add_data==0)         {   FL_Vin                 = (float_data  * 1);}  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==1)    {   FL_Idc                 = (float_data  * 1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==2)    {   FL_A_ref               = (float_data  * 1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==3)    {   FL_Vdc                 = (float_data  * 1); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==4)    {   FL_Va                  = (float_data  * 1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==5)    {   FL_Ia                  = (float_data  * 1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==6)    {   FL_s_volt              = (float_data  * 1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==7)    {   FL_e_volt              = (float_data  * 1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==8)    {   Fc_I_5th              = (float_data  * 1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==9)    {   Ia_PLL3_harmonic_k     = (float_data  * 0.01); }  //eeprom setting    사용자 테스트 주소 정의

         else if(add_data==10)   {   mode_Va_PLL3           = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==11)   {   Flag_Ia_PLL3           = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==12)   {   Flag_current_control_inv3           = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==13)   {   Flag_Va_PLL3           = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==14)   {   voltage_control_inv3_cnt_max     = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==15)   {   Flag_over_check        = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==16)   {   flag_control_parameter = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==17)   {   Idc_ref_comp_input     = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==18)   {   SCI_WR_setting         = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==19)   {   SCI_WR_Mode            = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의

         else if(add_data==20)   {  if(Flag_gating == 0)  {   OP_MODE=float_data;    }    }
         else if(add_data==21)   {   Run_Stop_com=float_data; }
         else if(add_data==22)   {   Fault_reset_com=float_data; }
     }


    else if(SCI_WR_Mode == 10)
     {
         //Inverter setting
         if(add_data==0)         {   Flag_Ia_PLL3           = (int)(float_data  * 0.01);}  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==1)    {   Fc_I_5th               = (float_data  * 1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==2)    {   Ia_PLL3_harmonic_k1    = (float_data  * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==3)    {   Ia_PLL3_harmonic_k2    = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==4)    {   Ia_PLL3_harmonic_k3    = (float_data  * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==5)    {   Kp_CC_Grid_comp_5th    = (float_data  * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==6)    {   Ki_CC_Grid_comp_5th    = (float_data  * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==7)    {   Kp_5th_ref             = (float_data  * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==8)    {   Flag_scia_cpu1_cpu2    = (float_data  * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==9)    {   OP_MODE                = (int)(float_data  * 0.01); }  //eeprom setting    사용자 테스트 주소 정의

         else if(add_data==10)   {   mode_Va_PLL3           = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==11)   {   Flag_Ia_PLL3           = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==12)   {   Flag_current_control_inv3           = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==13)   {   Flag_Va_PLL3           = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==14)   {   voltage_control_inv3_cnt_max     = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==15)   {   Flag_over_check        = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==16)   {   flag_control_parameter = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==17)   {   Idc_ref_comp_input     = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==18)   {   SCI_WR_setting         = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==19)   {   SCI_WR_Mode            = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의

         else if(add_data==20)   {  if(Flag_gating == 0)  {   OP_MODE=float_data;    }    }
         else if(add_data==21)   {   Run_Stop_com=float_data; }
         else if(add_data==22)   {   Fault_reset_com=float_data; }
     }


    else if(SCI_WR_Mode == 11)
     {
         //Inverter setting
         if(add_data==0)         {   Flag_Act_islanding_input           = (int)(float_data  * 0.01);}  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==1)    {   Freq_high                  = (float_data  * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==2)    {   Freq_low                   = (float_data  * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==3)    {   Ia_PLL3_harmonic_k2    = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==4)    {   Ia_PLL3_harmonic_k3    = (float_data  * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==5)    {   Kp_CC_Grid_comp_5th    = (float_data  * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==6)    {   Ki_CC_Grid_comp_5th    = (float_data  * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==7)    {   Kp_5th_ref             = (float_data  * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==8)    {   Flag_scia_cpu1_cpu2    = (float_data  * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==9)    {   OP_MODE                = (int)(float_data  * 0.01); }  //eeprom setting    사용자 테스트 주소 정의

         else if(add_data==10)   {   mode_Va_PLL3           = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==11)   {   Flag_Ia_PLL3           = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==12)   {   Flag_current_control_inv3           = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==13)   {   Flag_Va_PLL3           = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==14)   {   voltage_control_inv3_cnt_max     = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==15)   {   Flag_over_check        = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==16)   {   flag_control_parameter = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==17)   {   Idc_ref_comp_input     = (float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==18)   {   SCI_WR_setting         = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data==19)   {   SCI_WR_Mode            = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의

         else if(add_data==20)   {  if(Flag_gating == 0)  {   OP_MODE=float_data;    }    }
         else if(add_data==21)   {   Run_Stop_com=float_data; }
         else if(add_data==22)   {   Fault_reset_com=float_data; }
     }

    else
    {
        if(add_data==19)   {   SCI_WR_Mode             = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
    }
#endif


#if 0
    if(add_data==0xff)      {   Enable_EEPROM_write=all_data;   }
    else if(add_data==0xfe) {   Init_offset=all_data;   }
    else if(add_data==0xfd) {   Init_scale=all_data;    }
//  else if(add_data==0xf1) {   Flag_RTC_init=all_data; }  //RTC initial
//  else if(add_data==0xf3) {   Set_year=all_data;      }  //RTC year
//  else if(add_data==0xf4) {   Set_mon_day=all_data;   }  //RTC mon_day
//  else if(add_data==0xf5) {   Set_hour_min=all_data;  }  //RTC hour_min
#endif

#if 0
    if(add_data==0xff)      {   Enable_EEPROM_write=all_data;   }
    else if(add_data==0xfe) {   Init_offset=all_data;   }
    else if(add_data==0xfd) {   Init_scale=all_data;    }

    else if(add_data==0)    {   Scale_Vin_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==1)    {   Scale_Idc_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==2)    {   Scale_A_ref_ratio = float_data* 0.01; } //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==3)    {   Scale_Vdc_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==4)    {   Scale_Esa_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==5)    {   Scale_Ia_ratio = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==6)    {   Kp_Vdc_con_ratio = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==7)    {   Ki_Vdc_con_ratio = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==8)    {   Kp_Idc_con_ratio = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==9)    {   Ki_Idc_con_ratio = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의

    else if(add_data==10)   {   Vin_offset_input = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==11)   {   Idc_offset_input = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==12)   {   A_ref_offset_input = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==13)   {   Vdc_offset_input = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==14)   {   Scale_Esb_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==15)   {   Scale_Ic_ratio = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==16)   {   Kp_Vdc_ratio = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==17)   {   Ki_Vdc_inv_ratio = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==18)   {   Kp_Ia_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==19)   {   Ki_Ia_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의

    else if(add_data==20)   {   Ia_offset_comp = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==21)   {   Ic_offset_comp = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
#endif

#if 0
    else if(add_data==0)    {   Scale_Vin_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==1)    {   Scale_Idc_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==2)    {   Scale_A_ref_ratio = float_data* 0.01; } //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==3)    {   Scale_Vdc_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==4)    {   Scale_Esa_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==5)    {   Scale_Ia_ratio = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==6)    {   Kp_Vdc_con_ratio = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==7)    {   Ki_Vdc_con_ratio = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==8)    {   Kp_Idc_con_ratio = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==9)    {   Ki_Idc_con_ratio = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의

    else if(add_data==10)   {   Vin_offset_input = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==11)   {   Idc_offset_input = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
//  else if(add_data==12)   {   A_ref_offset_input = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
//  else if(add_data==12)   {   Ide_ref_Cf = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
//    else if(add_data==12)   {   time_check_cnt = (int)(float_data* 0.01); } //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==13)   {   Vdc_offset_input = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==14)   {   Scale_Esb_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==15)   {   Scale_Ic_ratio = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==16)   {   Wn_VC = float_data* 0.1; }  //eeprom setting    사용자 테스트 주소 정의

//  else if(add_data==16)   {   Kp_Vdc_ratio = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
//  else if(add_data==16)   {   Wn_VC = float_data* 0.01; } //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==17)   {   Wc_CC = float_data* 0.1; }  //eeprom setting    사용자 테스트 주소 정의
//  else if(add_data==17)   {   Wc_CC = float_data* 0.01; } //eeprom setting    사용자 테스트 주소 정의
//  else if(add_data==17)   {   Ki_Vdc_inv_ratio = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==18)   {   Kp_Ia_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==19)   {   Ki_Ia_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의

    else if(add_data==20)   {   Ia_offset_comp = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==21)   {   Ic_offset_comp = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
#endif

    // 2.   Mode_system_input       = 0         -> 1
    // 3.   Mode_test               = 0         -> no action
    // 4.   Flag_pwm_inv_test2      = 0         -> 1
    // 5.   Ta_inv_test2            = 0         -> 1
    // 6.   Tb_inv_test2            = 0         -> 1
    // 7.   Tc_inv_test2            = 0         -> 1

#if 0
    //phase shift test
    else if(add_data==0)    {   Mode_system_input   = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==1)    {   Mode_test           = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==2)    {   DO1_output          = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==3)    {   Vdc_ref_con_set     = float_data* 0.1; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==4)    {   Idc_ref_comp        = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==5)    {   Idc_limit_con       = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==6)    {   Flag_gating_test    = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==7)    {   OV_set_Vin_test     = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==8)    {   OC_Idc_set_test     = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==9)    {   OV_set_Vdc_test     = float_data* 0.1; }  //eeprom setting    사용자 테스트 주소 정의

    else if(add_data==10)   {   Mode_system_input   = (int)(float_data * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==11)   {   Mode_test           = (int)(float_data * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==12)   {   DO2_output          = (int)(float_data * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==13)   {   VF_vtg_max          = float_data* 0.1; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==14)   {   Flag_gating_VF_TEST = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==15)   {   OC_set_test         = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==16)   {   DO3_output          = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
//    else if(add_data==17)   {   DO4_output          = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
//    else if(add_data==18)   {   DO5_output          = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의

    else if(add_data==17)   {   EPwm1_CMP_test          = (int)(float_data* 0.01); }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==18)   {   EPwm2_CMP_test          = (int)(float_data* 0.01); }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==19)   {   Ta_con_test1        = float_data* 0.1; }   //eeprom setting    사용자 테스트 주소 정의

    else if(add_data==20)   {   Ia_offset_comp      = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==21)   {   Ic_offset_comp      = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
#endif


#if 0
    //one pwm pulse test
    else if(add_data==0)    {   Mode_system_input   = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==1)    {   Mode_test           = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==2)    {   DO1_output          = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==3)    {   Flag_gating_test    = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==4)    {   Ta_con_test1        = (int)(float_data  * 0.1);}   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==5)    {   Ta_con_test1        = (int)(float_data  * 0.1);}    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==6)    {   Tb_con_test1        = (int)(float_data  * 0.1);}  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==7)    {   Tb_con_test1        = (int)(float_data  * 0.1);}  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==8)    {   Tc_con_test1        = (int)(float_data  * 0.1);}  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==9)    {   Tc_con_test1        = (int)(float_data  * 0.1);}  //eeprom setting    사용자 테스트 주소 정의

    else if(add_data==10)   {   Mode_system_input   = (int)(float_data * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==11)   {   Mode_test           = (int)(float_data * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==12)   {   DO2_output          = (int)(float_data * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==13)   {   Flag_gating_test_cnt_max          = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==14)   {   Flag_pwm_1P         = (int)(float_data  * 0.01);}   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==15)   {   Flag_pwm_1N         = (int)(float_data  * 0.01);}    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==16)   {   Flag_pwm_2P         = (int)(float_data  * 0.01);}  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==17)   {   Flag_pwm_2N         = (int)(float_data  * 0.01);}  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==18)   {   Flag_pwm_3P         = (int)(float_data  * 0.01);}   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==19)   {   Flag_pwm_3N         = (int)(float_data  * 0.01);}   //eeprom setting    사용자 테스트 주소 정의

    else if(add_data==20)   {   Ia_offset_comp      = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==21)   {   Ic_offset_comp      = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
#endif


#if 0
    else
    {   // 0x00~0xFC(0~252)
        temp    = data_ptr[INIT_EEPROM_CODE + add_data];
        *temp   = float_data * 0.01;
    }
#endif

    MODBUS_transmitt_buffer[0]  = 'W';   // 'W'
    MODBUS_transmitt_buffer[1]  = 'R';   // 'R'
    MODBUS_transmitt_buffer[2]  = 0x20;  // Space
    MODBUS_transmitt_buffer[3]  = MODBUS_receive_buffer[3];  // '3'
    MODBUS_transmitt_buffer[4]  = MODBUS_receive_buffer[4];  // '0'
    MODBUS_transmitt_buffer[5]  = 0x20;  // Space
    MODBUS_transmitt_buffer[6]  = MODBUS_receive_buffer[6];  // data4
    MODBUS_transmitt_buffer[7]  = MODBUS_receive_buffer[7];  // data3
    MODBUS_transmitt_buffer[8]  = MODBUS_receive_buffer[8];  // data2
    MODBUS_transmitt_buffer[9]  = MODBUS_receive_buffer[9];  // data1
    MODBUS_transmitt_buffer[10] = 0x0d;  // CR
    MODBUS_transmitt_buffer[11] = 'H';   // 'H'
    MODBUS_transmitt_buffer[12] = ':';   // ':'

    transmitt_flag  = 1;
    transmitt_data_length = 13;
}


void function_WR_SanRex2()
{
    char recv_buffer[6]={0x00,0x00,0x00,0x00,0x00,0x00};
    unsigned int add_data, all_data, low_data, high_data;
    int int_data;
    float float_data;
#if 0
    long temp_data;
    float   *temp;
    unsigned int    chk_sum, chk_sum_send_buffer, chk_sum_high, chk_sum_low;
#endif
    unsigned int    chk_sum, chk_sum_send_buffer;

    recv_buffer[0] = asc2hex(MODBUS_receive_buffer[4]);
    recv_buffer[1] = asc2hex(MODBUS_receive_buffer[5]);
    recv_buffer[2] = asc2hex(MODBUS_receive_buffer[6]);
    recv_buffer[3] = asc2hex(MODBUS_receive_buffer[7]);
    recv_buffer[4] = asc2hex(MODBUS_receive_buffer[8]);
    recv_buffer[5] = asc2hex(MODBUS_receive_buffer[9]);

    chk_sum =   MODBUS_receive_buffer[0]+MODBUS_receive_buffer[1]+MODBUS_receive_buffer[2]+
                MODBUS_receive_buffer[3]+MODBUS_receive_buffer[4]+MODBUS_receive_buffer[5]+
                MODBUS_receive_buffer[6]+MODBUS_receive_buffer[7]+MODBUS_receive_buffer[8]+
                MODBUS_receive_buffer[9]+MODBUS_receive_buffer[10];

    if(((MODBUS_receive_buffer[12]==((chk_sum>>8)&0xff)))&&(MODBUS_receive_buffer[11]==(chk_sum&0xff)))
    {

        add_data = (((recv_buffer[0]&0xff) << 4) | recv_buffer[1]&0xff);
        high_data = (((recv_buffer[2]&0xff) << 4) | recv_buffer[3]&0xff);
        low_data = (((recv_buffer[4]&0xff) << 4) | recv_buffer[5]&0xff);
        all_data = ((high_data << 8) | low_data);

        int_data = (int)all_data;
        float_data = (float)int_data;

        add_data_lsc    = add_data;
        all_data_lsc    = all_data;
        float_data_lsc  = (float)int_data;

        if(add_data==0x19)          {   Fault_reset_com=float_data;   }
        else if(add_data==0x20)     {   Idc_ref_comp_input           = (float_data  * 0.01);        }
        else if(add_data==0x22)     {   if(Flag_gating == 0) {OP_MODE=float_data;           }       }
        else if(add_data==0x23)     {   Run_Stop_com=float_data; }  //RTC initial
    }

    MODBUS_transmitt_buffer[0] = 'M';   // 'M'
    MODBUS_transmitt_buffer[1] = 'N';   // 'N'
    MODBUS_transmitt_buffer[2] = 0x20;  // Space
    MODBUS_transmitt_buffer[3] = 'W';   // '3'
    MODBUS_transmitt_buffer[4] = MODBUS_receive_buffer[4];  // '0'
    MODBUS_transmitt_buffer[5] = MODBUS_receive_buffer[5];  // Space
    MODBUS_transmitt_buffer[6] = 0x0d;;                     // CR
    MODBUS_transmitt_buffer[7] = 'H';                       // 'H'
    MODBUS_transmitt_buffer[8] = ':';                       // ':'
    chk_sum_send_buffer = MODBUS_transmitt_buffer[0]+MODBUS_transmitt_buffer[1]+MODBUS_transmitt_buffer[2]+
                          MODBUS_transmitt_buffer[3]+MODBUS_transmitt_buffer[4]+MODBUS_transmitt_buffer[5]+
                          MODBUS_transmitt_buffer[6]+MODBUS_transmitt_buffer[7]+MODBUS_transmitt_buffer[8];

    MODBUS_transmitt_buffer[9] = (chk_sum_send_buffer&0xff);                // check sum low
    MODBUS_transmitt_buffer[10] = (chk_sum_send_buffer>>8&0xff);            // check sum high

    transmitt_flag=1;
    transmitt_data_length = 11;

}

void function_WR_SanRex3()
{
///NEW

    char recv_buffer[6]={0x00,0x00,0x00,0x00,0x00,0x00};
    unsigned int add_data, all_data, low_data, high_data;
    int int_data;
    float float_data;
//    float   *temp;
    receiveC++;
    recv_buffer[0] = asc2hex(MODBUS_receive_buffer[4]); //ADDR LOW
    recv_buffer[1] = asc2hex(MODBUS_receive_buffer[5]); //ADDR HIGH

    recv_buffer[2] = asc2hex(MODBUS_receive_buffer[6]); //ADDR 1
    recv_buffer[3] = asc2hex(MODBUS_receive_buffer[7]); //ADDR 2
    recv_buffer[4] = asc2hex(MODBUS_receive_buffer[8]); //ADDR 3
    recv_buffer[5] = asc2hex(MODBUS_receive_buffer[9]); //ADDR 4

    add_data = (((recv_buffer[0]&0xff) << 4) | recv_buffer[1]&0xff);

    high_data = (((recv_buffer[2]&0xff) << 4) | recv_buffer[3]&0xff);
    low_data = (((recv_buffer[4]&0xff) << 4) | recv_buffer[5]&0xff);

    all_data = ((high_data << 8) | low_data);

    int_data = (int)all_data;
    float_data = (float)int_data;


    add_data_lsc    = add_data;
    all_data_lsc    = all_data;
    float_data_lsc  = (float)int_data;

//    if(add_data==0x19)      {   Write_Buffer[0]=all_data;   } //Fault Reset
//    else if(add_data==0x20) {   Write_Buffer[1]=all_data;   } //Ref
//    else if(add_data==0x21) {   Write_Buffer[2]=all_data;   } // Reserved
//    else if(add_data==0x22) {   Write_Buffer[3]=all_data;   } //Operation Mode
//    else if(add_data==0x23) {   Write_Buffer[4]=all_data;   } //RUN/STOP

//    if(add_data==0x19)      {   Fault_reset_com     = all_data;         }
//    else if(add_data==0x20) {   Idc_ref_comp        = all_data * 0.01;  }
//    else if(add_data==0x22) {   OP_MODE             = all_data;         }
//    else if(add_data==0x23) {   Comm_Run_Stop       = all_data;         }  //RTC initial
    if(add_data==0x19)          {   Fault_reset_com=float_data;   }
    else if(add_data==0x20)     {   Idc_ref_comp_input           = (float_data  * 0.01);        }
    else if(add_data==0x22)     {   if(Flag_gating == 0) {OP_MODE=float_data;           }       }
    else if(add_data==0x23)     {   Run_Stop_com=float_data; }  //RTC initial


    MODBUS_transmitt_buffer[0]  = 'M';   // 'W'
    MODBUS_transmitt_buffer[1]  = 'N';   // 'R'
    MODBUS_transmitt_buffer[2]  = 0x20;  // Space
    MODBUS_transmitt_buffer[3]  = 'W';
    MODBUS_transmitt_buffer[4]  = MODBUS_receive_buffer[4];  // '3'
    MODBUS_transmitt_buffer[5]  = MODBUS_receive_buffer[5];  // '0'
    MODBUS_transmitt_buffer[6] = 0x0d;  // CR
    MODBUS_transmitt_buffer[7] = 'H';   // 'H'
    MODBUS_transmitt_buffer[8] = ':';   // ':'


    transmitt_data_length = 11;
    (CRC16(transmitt_data_length-2,2));

    CRC16_check2_test =  CRC16(transmitt_data_length-2,2);


    transmitt_flag  = 1;
}

/*--------------------------------------*/
/*  call scib_com_init()                */
/*--------------------------------------*/
void scib_com_init()
{
    // SCI-B 초기화 함수
    scib_com_init_count++;
//  if(scib_com_init_count >=10){       //10s
    if(scib_com_init_count >=30){       //30s
        scib_com_init_count=0;
        if(Flag_modbus_response_count >= 1){
            Flag_modbus_response_count = 0;
        }
        else{            // KSC
            Flag_modbus_response_count = 0;
            Flag_modbus_response_count_test++;
//            Init_Scib();         // RS485 MMI Communication Init Func.
            //Fault_SW|=SFT_SCI_Comm;
        }
    }
    else{}
}



//---------------------------------------------------------------------------------
void serial_modbus_500us_a()
{
    int ri0_a = 0;
    int ri1_a = 0;

    ri0_a = (SciaRegs.SCIRXST.bit.RXRDY) & 0xff;

    if(SciaRegs.SCIRXST.all & 0x80)
    {
        SciaRegs.SCICTL1.all = 0x0003;          // Relinquish SCI from Reset
        SciaRegs.SCICTL1.all = 0x0023;          // Relinquish SCI from Reset
    }

    if(ri0_a & MODBUS_RX_RDY_a)
    {
        if(receive_count_a < RECEIVE_MAX_BYTE_a)
        {   // RECEIVE_MAX_BYTE = 12
            MODBUS_receive_buffer_a[receive_count_a] = SciaRegs.SCIRXBUF.all;
            receive_count_a++;
            receive_err_cnt_a = 0;
        }
        else if(receive_err_cnt_a > 30)
        {
            receive_count_a = 0;
        }
        char_time_a         = 0;
        receive_err_cnt_a++;
    }
    else if((Flag_modbus_response_a == 0) && (++char_time_a == 15 ))
    {   // <not receive> and <char_time(3.5)(38400:730us->250us :3times)>
        //char_time=0;
        MODBUS_count_a            = receive_count_a;
        receive_count_a           = 0;
        receive_err_cnt_a         = 0;
        Flag_modbus_response_a    = 1;
    }
    else if((Flag_modbus_response_a == 0) && (char_time_a > 15))
    {
        char_time_a   = 15;
    }

    ri1_a = SciaRegs.SCICTL2.bit.TXRDY;

    if(transmitt_flag_a == 1)
    {
        if(ri1_a & MODBUS_TX_RDY_a)
        {
            if(transmitt_count_a < transmitt_data_length_a)
            {
                SciaRegs.SCITXBUF.all = MODBUS_transmitt_buffer_a[transmitt_count_a];
                transmitt_count_a++;
            }
            else if(transmitt_count_a <= (transmitt_data_length_a + 4))
            {
                transmitt_count_a++;
            }
            else
            {
                transmitt_flag_a  = 0;
                transmitt_count_a = 0;
            }
        }
    }
}
//---------------------------------------------------------------------------------


//---------------------------------------------------------------------------------
void serial_modbus_10ms_a()
{
    if(Flag_modbus_response_a == 1)
    {
        Flag_modbus_response_count_a++;

        if (MODBUS_receive_buffer_a[0] == 'M' && MODBUS_receive_buffer_a[1] == 'N' && MODBUS_receive_buffer_a[2] == 0x20 &&
            MODBUS_receive_buffer_a[3] == 'H' && MODBUS_receive_buffer_a[4] == 0x0d)
        {
            hyun_flag_a   = 2;  // Monitor Read
//            GPIOB_485EN_TX;   //485 transmitt enable
        }
        else if (MODBUS_receive_buffer_a[0] == 'M' && MODBUS_receive_buffer_a[1] == 'S' && MODBUS_receive_buffer_a[2] == 0x20 &&
            MODBUS_receive_buffer_a[3] == 'H' && MODBUS_receive_buffer_a[4] == 0x0d)
        {
            hyun_flag_a   = 4;  // Scale Read
//            GPIOB_485EN_TX;   //485 transmitt enable
        }
        else if (MODBUS_receive_buffer_a[0] == 'M' && MODBUS_receive_buffer_a[1] == 'K' && MODBUS_receive_buffer_a[2] == 0x20 &&
            MODBUS_receive_buffer_a[3] == 'H' && MODBUS_receive_buffer_a[4] == 0x0d) {
            hyun_flag_a=5;  // Scale Read
//            GPIOB_485EN_TX;   //485 transmitt enable

        }

        /* GS write protocol */
//        else if (MODBUS_receive_buffer_a[0] == 'M'  && MODBUS_receive_buffer_a[1] == 'N' && MODBUS_receive_buffer_a[2] == 0x20 &&
//            MODBUS_receive_buffer_a[3] == 'W' && MODBUS_receive_buffer_a[10] == 0x0d)   {
//            hyun_flag_a = 6;
//////            GPIOB_485EN_TX;   //485 transmitt enable
//        }
        /* GS write protocol */

        else if (MODBUS_receive_buffer_a[0] == 'M' && MODBUS_receive_buffer_a[1] == 'E' && MODBUS_receive_buffer_a[2] == 0x20 &&
            MODBUS_receive_buffer_a[3] == 'H' && MODBUS_receive_buffer_a[4] == 0x0d) {
            hyun_flag_a=9;        // inverter setting read
//            GPIOB_485EN_TX;     //485 transmitt enable
        }

        else if (MODBUS_receive_buffer_a[0] == 'H' && MODBUS_receive_buffer_a[1] == 'T' &&
            MODBUS_receive_buffer_a[3] == 'H' && MODBUS_receive_buffer_a[4] == 0x0d)
        {
            if((MODBUS_receive_buffer_a[2] >= 0x20) && (MODBUS_receive_buffer_a[2] <= 0x29))
            {
                switch(MODBUS_receive_buffer_a[2])
                {
                    case 0x20: hyun_flag_a=0x20;  break;  // History Read
                    case 0x21: hyun_flag_a=0x21;  break;  // History Read
                    case 0x22: hyun_flag_a=0x22;  break;  // History Read
                    case 0x23: hyun_flag_a=0x23;  break;  // History Read
                    case 0x24: hyun_flag_a=0x24;  break;  // History Read
                    case 0x25: hyun_flag_a=0x25;  break;  // History Read
                    case 0x26: hyun_flag_a=0x26;  break;  // History Read
                    case 0x27: hyun_flag_a=0x27;  break;  // History Read
                    case 0x28: hyun_flag_a=0x28;  break;  // History Read
                    case 0x29: hyun_flag_a=0x29;  break;  // History Read
                    default: break;
                }
//                GPIOB_485EN_TX;   //485 transmitt enable
            }
        }
        else if (MODBUS_receive_buffer_a[0] == 'W'  && MODBUS_receive_buffer_a[1] == 'C' && MODBUS_receive_buffer_a[2] == 0x20 &&
            MODBUS_receive_buffer_a[10] == 0x0d)
        {
            hyun_flag_a = 3;
//            GPIOB_485EN_TX;   //485 transmitt enable
        }

        else if (MODBUS_receive_buffer_a[0] == 'T' && MODBUS_receive_buffer_a[1] == 'A' && MODBUS_receive_buffer_a[2] == 0x20 &&
            MODBUS_receive_buffer_a[3] == 'H' && MODBUS_receive_buffer_a[4] == 0x0d)
        {
            hyun_flag_a   = 11;  // Scale Read
//            GPIOB_485EN_TX;   //485 transmitt enable
        }

        else if (MODBUS_receive_buffer_a[0] == 'T' && MODBUS_receive_buffer_a[1] == 'B' && MODBUS_receive_buffer_a[2] == 0x20 &&
            MODBUS_receive_buffer_a[3] == 'H' && MODBUS_receive_buffer_a[4] == 0x0d)
        {
            hyun_flag_a   = 12;  // Scale Read
//            GPIOB_485EN_TX;   //485 transmitt enable
        }

        else if (MODBUS_receive_buffer_a[0] == 'T' && MODBUS_receive_buffer_a[1] == 'C' && MODBUS_receive_buffer_a[2] == 0x20 &&
            MODBUS_receive_buffer_a[3] == 'H' && MODBUS_receive_buffer_a[4] == 0x0d)
        {
            hyun_flag_a   = 13;  // Scale Read
//            GPIOB_485EN_TX;   //485 transmitt enable
        }

        else if (MODBUS_receive_buffer_a[0] == 'T' && MODBUS_receive_buffer_a[1] == 'D' && MODBUS_receive_buffer_a[2] == 0x20 &&
            MODBUS_receive_buffer_a[3] == 'H' && MODBUS_receive_buffer_a[4] == 0x0d)
        {
            hyun_flag_a   = 14;  // Scale Read
//            GPIOB_485EN_TX;   //485 transmitt enable
        }

        else if (MODBUS_receive_buffer_a[0] == 'T' && MODBUS_receive_buffer_a[1] == 'E' && MODBUS_receive_buffer_a[2] == 0x20 &&
            MODBUS_receive_buffer_a[3] == 'H' && MODBUS_receive_buffer_a[4] == 0x0d)
        {
            hyun_flag_a   = 15;  // Scale Read
//            GPIOB_485EN_TX;   //485 transmitt enable
        }

        else if (MODBUS_receive_buffer_a[0] == 'T' && MODBUS_receive_buffer_a[1] == 'F' && MODBUS_receive_buffer_a[2] == 0x20 &&
            MODBUS_receive_buffer_a[3] == 'H' && MODBUS_receive_buffer_a[4] == 0x0d)
        {
            hyun_flag_a   = 16;  // Scale Read
//            GPIOB_485EN_TX;   //485 transmitt enable
        }

        else if (MODBUS_receive_buffer_a[0] == 'M'  && MODBUS_receive_buffer_a[1] == 'N' && MODBUS_receive_buffer_a[2] == 0x20 &&
                   MODBUS_receive_buffer_a[3] == 'W'  && MODBUS_receive_buffer_a[10] == 0x0d)//CRC (L) CRC (H)
          {


              if (CRC16_a(11,1) == 1){
                  CRC16_check1_test_a_cnt++;
                hyun_flag_a = 30;
//                GPIOB_485EN_TX;   //485 transmitt enable
              }
              else {/*BAD_RESPONSE*/}


                CRC16_check1_test_a        = CRC16_a(11,1);
//
//                  hyun_flag_a = 30;
//                  GPIOB_485EN_TX;   //485 transmitt enable


          }
        else {SCI_Recv_Error_a++;}


        Flag_modbus_response_a    = 0;
    }


    if ((hyun_flag_a == 2)||(hyun_flag_a == 4)||(hyun_flag_a == 5)||(hyun_flag_a == 9))
    {
        function_SanRex_a();
        hyun_flag_a   = 0;
    }

    else if ((hyun_flag_a >= 0x20) && (hyun_flag_a <= 0x29))
    {
        function_SanRex_HT_a();
        hyun_flag_a   = 0;
    }

    else if (hyun_flag_a == 3)
    {
        function_WR_SanRex_a();
        hyun_flag_a   = 0;
    }

    else if(hyun_flag_a == 6)
    {
        function_WR_SanRex2_a();
        hyun_flag_a=0;
    }

    else if ((hyun_flag_a == 11)||(hyun_flag_a == 12)||(hyun_flag_a == 13)||(hyun_flag_a == 14)||(hyun_flag_a == 15)||(hyun_flag_a == 16))
    {
        function_SanRex2_a();
        hyun_flag_a   = 0;
    }

    else if (hyun_flag_a == 30)
    {
        function_WR_SanRex3_a();
        hyun_flag_a = 0;
    }

    rxerror = (SciaRegs.SCIRXST.bit.RXERROR) & 0x0ff;
    if(rxerror != 0)
    {
        SciaRegs.SCICTL2.bit.RXBKINTENA = 0;
        SciaRegs.SCICTL2.bit.TXINTENA   = 0;
        SciaRegs.SCICTL1.all            = 0x0023;   // Relinquish SCI from Reset Edit 0829 err
    }
}



//---------------------------------------------------------------------------------
void function_SanRex_a()
{

// SanRex Inverter Protocol
    unsigned char imsi_data_bytehigh_a=0, imsi_data_bytelow_a=0;
    unsigned char imsi_data_bytehigh_high_a=0, imsi_data_bytehigh_low_a=0,imsi_data_bytelow_high_a=0, imsi_data_bytelow_low_a=0 ;
    int i=0;

/************************************************ Edit 100517 *************************************************/

    if(hyun_flag_a == 2)
    {  // Edit 100517

#if 0
        SanRex_ptr_0_cnt++;
        if(SanRex_ptr_0_cnt >= 300) SanRex_ptr_0_cnt = 0;
        SanRex_ptr_a[0]  = (int)(SanRex_ptr_0_cnt   * 100.);
#endif

#if 0
        if(SCI_WR_Mode == 0)
        {
            SanRex_ptr_a[0]  = (int)(Vin_flt_avg_avg   * 100.);
            SanRex_ptr_a[1]  = (int)(Idc_flt_avg_avg   * 100.);
            SanRex_ptr_a[2]  = (int)(Pin               * 1000.);
            SanRex_ptr_a[3]  = (int)(Esa_rms_avg       * 10.);
            SanRex_ptr_a[4]  = (int)(Esb_rms_avg       * 10.);
            SanRex_ptr_a[5]  = (int)(Esc_rms_avg       * 10.);
            SanRex_ptr_a[6]  = (int)(Flag_Act_islanding);      //
            SanRex_ptr_a[7]  = (int)(Pinv_DQ_avg       * 1000.);      // Pout
            SanRex_ptr_a[8]  = (int)(Freq_out          * 100.);         // Frequency
            SanRex_ptr_a[9]  = (int)(Vdc_flt           * 10.);           // Vdc

            SanRex_ptr_a[10] = (int)(Ia_rms_avg       * 100.);      // Vdc
            SanRex_ptr_a[11] = (int)(Ib_rms_avg       * 100.);      // Pout
            SanRex_ptr_a[12] = (int)(Ic_rms_avg       * 100.);
            SanRex_ptr_a[13] = INV_status;                    // 0:offset, 1:ready, 2: buildup, 3: run, 4: fault
            SanRex_ptr_a[14] = (Fault_SW & 0xFFFF);           // fault
            SanRex_ptr_a[15] = ((Fault_SW>>16) & 0xFFFF);
            SanRex_ptr_a[16] = Fault_history[1];
            SanRex_ptr_a[17] = Fault_history[2];
            SanRex_ptr_a[18] = Fault_history[0];
            SanRex_ptr_a[19] = (int)(Vdc_con_real_max * 100.);    //Idc_ref

            SanRex_ptr_a[20] = INV_SW_VER; //Ver1.00
        }
        else
        {
            SanRex_ptr_a[0]  = (int)(Vdc_ref_inv      * 10.);
            SanRex_ptr_a[1]  = (int)(Vdc_flt          * 10.);
            SanRex_ptr_a[2]  = (int)(Err_Vdc_inv      * 10.);
            SanRex_ptr_a[3]  = (int)(Ip_ref_integ     * 10.);
            SanRex_ptr_a[4]  = (int)(Ip_ref_out       * 10.);
            SanRex_ptr_a[5]  = (int)(Ip_ref           * 10.);
            SanRex_ptr_a[6]  = (int)(Flag_Act_islanding);             //
            SanRex_ptr_a[7]  = (int)(Ip_ref_real_max   * 10.);        // Pout
            SanRex_ptr_a[8]  = (int)(Freq_out          * 100.);       // Frequency
            SanRex_ptr_a[9]  = (int)(Vdc_flt           * 10.);        // Vdc

            SanRex_ptr_a[10] = (int)(Ia_rms_avg       * 100.);        // Vdc
            SanRex_ptr_a[11] = (int)(Ib_rms_avg       * 100.);        // Pout
            SanRex_ptr_a[12] = (int)(Ic_rms_avg       * 100.);
            SanRex_ptr_a[13] = INV_status;                    // 0:offset, 1:ready, 2: buildup, 3: run, 4: fault
            SanRex_ptr_a[14] = (Fault_SW & 0xFFFF);           // fault
            SanRex_ptr_a[15] = ((Fault_SW>>16) & 0xFFFF);
            SanRex_ptr_a[16] = Fault_history[1];
            SanRex_ptr_a[17] = Fault_history[2];
            SanRex_ptr_a[18] = Fault_history[0];
            SanRex_ptr_a[19] = (int)(Vdc_con_real_max * 100.);    //Idc_ref

            SanRex_ptr_a[20] = INV_SW_VER; //Ver1.00
        }
#endif

#if 0
        SanRex_ptr_a[0]  = (int)(Vin_flt_avg_avg   * 100.);
        SanRex_ptr_a[1]  = (int)(Idc_flt_avg_avg   * 100.);
        SanRex_ptr_a[2]  = (int)(Pin               * 1000.);
        SanRex_ptr_a[3]  = (int)(Esa_rms_avg       * 10.);
        SanRex_ptr_a[4]  = (int)(Esb_rms_avg       * 10.);
        SanRex_ptr_a[5]  = (int)(Esc_rms_avg       * 10.);
        SanRex_ptr_a[6]  = (int)(Flag_Act_islanding);      //
        SanRex_ptr_a[7]  = (int)(Pinv_DQ_avg       * 1000.);      // Pout
        SanRex_ptr_a[8]  = (int)(Freq_out          * 100.);         // Frequency
        SanRex_ptr_a[9]  = (int)(Vdc_flt           * 10.);           // Vdc

        SanRex_ptr_a[10] = (int)(Ia_rms_avg       * 100.);      // Vdc
        SanRex_ptr_a[11] = (int)(Ib_rms_avg       * 100.);      // Pout
        SanRex_ptr_a[12] = (int)(Ic_rms_avg       * 100.);
        SanRex_ptr_a[13] = INV_status;                    // 0:offset, 1:ready, 2: buildup, 3: run, 4: fault
        SanRex_ptr_a[14] = (Fault_SW & 0xFFFF);           // fault
        SanRex_ptr_a[15] = ((Fault_SW>>16) & 0xFFFF);
        SanRex_ptr_a[16] = Fault_history[1];
        SanRex_ptr_a[17] = Fault_history[2];
        SanRex_ptr_a[18] = Fault_history[0];
        SanRex_ptr_a[19] = (int)(Vdc_con_real_max * 100.);    //Idc_ref

        SanRex_ptr_a[20] = INV_SW_VER; //Ver1.00
        MODBUS_transmitt_buffer_a[0]  = 'M';
        MODBUS_transmitt_buffer_a[1]  = 'N';
        MODBUS_transmitt_buffer_a[2]  = 0x20;
//      MODBUS_transmitt_buffer_a[3]  = '0';
//      MODBUS_transmitt_buffer_a[4]  = '0';
//      MODBUS_transmitt_buffer_a[5]  = 0x20;
#endif

#if 0
        SanRex_ptr_a[0] = (int)0;
        SanRex_ptr_a[1] = (int)1;
        SanRex_ptr_a[2] = (int)2;
        SanRex_ptr_a[3] = (int)3;
        SanRex_ptr_a[4] = (int)4;
        SanRex_ptr_a[5] = (int)5;
        SanRex_ptr_a[6] = (int)6;
        SanRex_ptr_a[7] = (int)7;
        SanRex_ptr_a[8] = (int)8;
        SanRex_ptr_a[9] = (int)9;
        SanRex_ptr_a[10] = (int)10;
        SanRex_ptr_a[11] = (int)11;
        SanRex_ptr_a[12] = (int)12;
        SanRex_ptr_a[13] = (int)13;
        SanRex_ptr_a[14] = (int)14;
        SanRex_ptr_a[15] = (int)15;
        SanRex_ptr_a[16] = (int)16;
        SanRex_ptr_a[17] = (int)17;
        SanRex_ptr_a[18] = (int)18;
        SanRex_ptr_a[19] = (int)19;
        SanRex_ptr_a[20] = (int)20;
        SanRex_ptr_a[21] = (int)21;
        SanRex_ptr_a[22] = (int)22;

        MODBUS_transmitt_buffer_a[0]  = 'M';
        MODBUS_transmitt_buffer_a[1]  = 'N';
        MODBUS_transmitt_buffer_a[2]  = 0x20;
#endif

        SanRex_ptr_a[0]  = (int)(Vin_flt_avg_avg_abs   * 100.);
        SanRex_ptr_a[1]  = (int)(Idc_flt_avg_avg_abs   * 100.);
        SanRex_ptr_a[2]  = (int)(Pin_abs               * 1000.);
        SanRex_ptr_a[3]  = (int)(Esc_rms_avg       * 10.);
        SanRex_ptr_a[4]  = (int)(Esb_rms_avg       * 10.);
        SanRex_ptr_a[5]  = (int)(Esa_rms_avg       * 10.);
        SanRex_ptr_a[6]  = (int)(Ia_rms_avg        * 100.);      //
        SanRex_ptr_a[7]  = (int)(Pinv_DQ_avg_abs       * 1000.);      // Pout
        SanRex_ptr_a[8]  = (int)(Freq_out          * 100.);         // Frequency
        SanRex_ptr_a[9]  = (int)(Vdc_flt           * 10.);           // Vdc

        SanRex_ptr_a[10] = (int)(Ib_rms_avg       * 100.);      // Vdc
        SanRex_ptr_a[11] = (int)(Pinv_DQ_avg_abs      * 1000.);      // Pout
        SanRex_ptr_a[12] = (int)(Ic_rms_avg       * 100.);
        SanRex_ptr_a[13] = INV_status;                    // 0:offset, 1:ready, 2: buildup, 3: run, 4: fault
        SanRex_ptr_a[14] = (Fault_SW & 0xFFFF);           // fault
        SanRex_ptr_a[15] = ((Fault_SW>>16) & 0xFFFF);
        SanRex_ptr_a[16] = Fault_history[1];
        SanRex_ptr_a[17] = Fault_history[2];
        SanRex_ptr_a[18] = Fault_history[0];
        SanRex_ptr_a[19] = (int)(Vdc_con_real_max * 100.);    //Idc_ref

//        SanRex_ptr_a[20] = INV_SW_VER; //Ver1.00 -> ver1.01
//        SanRex_ptr_a[20] = Idc_ref_comp_input; //Ver1.00 -> ver1.01
        SanRex_ptr_a[20] = Idc_ref_comp; //Ver1.00 -> ver1.01
        SanRex_ptr_a[21] = (int)(OP_MODE          * 1.); //Ver1.00 -> ver1.01
        SanRex_ptr_a[22] = (int)(Run_Stop_com     * 1.); //Ver1.00 -> ver1.01

        MODBUS_transmitt_buffer_a[0]  = 'M';
        MODBUS_transmitt_buffer_a[1]  = 'N';
        MODBUS_transmitt_buffer_a[2]  = 0x20;
//      MODBUS_transmitt_buffer_a[3]  = '0';
//      MODBUS_transmitt_buffer_a[4]  = '0';
//      MODBUS_transmitt_buffer_a[5]  = 0x20;
    }
    else if(hyun_flag_a==4)
    {
#if 1
        if(SCI_WR_Mode == 0)
        {
            //Inverter Scale
            SanRex_ptr_a[0] = (int)(Scale_Vin_ratio   * 100);
            SanRex_ptr_a[1] = (int)(Scale_Idc_ratio   * 100);
            SanRex_ptr_a[2] = (int)(Scale_A_ref_ratio * 100);
            SanRex_ptr_a[3] = (int)(Scale_Vdc_ratio   * 100);
            SanRex_ptr_a[4] = (int)(Scale_Esa_ratio   * 100);
            SanRex_ptr_a[5] = (int)(Scale_Esb_ratio   * 100);
            SanRex_ptr_a[6] = (int)(Scale_Esc_ratio   * 100);
            SanRex_ptr_a[7] = (int)(Scale_Ia_ratio    * 100);
            SanRex_ptr_a[8] = (int)(Scale_Ib_ratio    * 100);
            SanRex_ptr_a[9] = (int)(Scale_Ic_ratio    * 100);

            SanRex_ptr_a[10] = (int)(Vin_offset     * 100);
            SanRex_ptr_a[11] = (int)(Idc_offset     * 100);
            SanRex_ptr_a[12] = (int)(A_ref_offset   * 100);
            SanRex_ptr_a[13] = (int)(Vdc_offset     * 100);
            SanRex_ptr_a[14] = (int)(Ia_offset_comp * 100);
            SanRex_ptr_a[15] = (int)(Ib_offset_comp * 100);
            SanRex_ptr_a[16] = (int)(Ic_offset_comp * 100);
            SanRex_ptr_a[17] = (int)(Idc_ref_comp   * 100);
            SanRex_ptr_a[18] = (int)(SCI_WR_setting    * 100);
            SanRex_ptr_a[19] = (int)(SCI_WR_Mode    * 100);

//          SanRex_ptr_a[20] = Enable_EEPROM_write;
            SanRex_ptr_a[20] = (int)(OP_MODE          * 1);
            SanRex_ptr_a[21] = (int)(Run_Stop_com     * 1);
            SanRex_ptr_a[22] = (int)(Fault_reset_com  * 1);
        }

        else if(SCI_WR_Mode == 1)
        {
            //Inverter /V/I/Power
            SanRex_ptr_a[0] = (int)(Vin_max           * 100);
            SanRex_ptr_a[1] = (int)(Vin_min           * 100);
            SanRex_ptr_a[2] = (int)(Idc_max           * 100);
            SanRex_ptr_a[3] = (int)(Vdc_max           * 10);
            SanRex_ptr_a[4] = (int)(Vl_rate           * 10);
            SanRex_ptr_a[5] = (int)(Ic_rate           * 100);
            SanRex_ptr_a[6] = (int)(Pout_rate         * 100);
            SanRex_ptr_a[7] = (int)(OV_Vin_level      * 100);
            SanRex_ptr_a[8] = (int)(UV_Vin_level      * 100);
            SanRex_ptr_a[9] = (int)(OC_Idc_ratio      * 100);

            SanRex_ptr_a[10] = (int)(OV_Vdc_level     * 100);
            SanRex_ptr_a[11] = (int)(OV_ratio_src     * 100);
            SanRex_ptr_a[12] = (int)(UV_ratio_src     * 100);
            SanRex_ptr_a[13] = (int)(INTER_ratio_src  * 100);
            SanRex_ptr_a[14] = (int)(OV_ratio_src_rms * 100);
            SanRex_ptr_a[15] = (int)(UV_ratio_src_rms * 100);
            SanRex_ptr_a[16] = (int)(OC_ratio         * 100);
            SanRex_ptr_a[17] = (int)(OL_ratio         * 100);
            SanRex_ptr_a[18] = (int)(Mode_system      * 100);
            SanRex_ptr_a[19] = (int)(SCI_WR_Mode      * 100);

//          SanRex_ptr_a[20] = Enable_EEPROM_write;
            SanRex_ptr_a[20] = (int)(OP_MODE          * 1);
            SanRex_ptr_a[21] = (int)(Run_Stop_com     * 1);
            SanRex_ptr_a[22] = (int)(Fault_reset_com  * 1);
        }

        else if(SCI_WR_Mode == 2)
        {

            //Inverter /V/I/Power
              SanRex_ptr_a[0] = (int)(Ref_con_inv_flag            * 100);
              SanRex_ptr_a[1] = (int)(Vdc_ref_inv                 * 10);
              SanRex_ptr_a[2] = (int)(Vl_rate                     * 10);
              SanRex_ptr_a[3] = (int)(Vdc_ref_inv_ratio           * 100);
              SanRex_ptr_a[4] = (int)(Ip_ref_real_max             * 100);
              SanRex_ptr_a[5] = (int)(Ic_rate                     * 100);
              SanRex_ptr_a[6] = (int)(Ip_ref_ratio                * 100);
              SanRex_ptr_a[7] = (int)(Vdc_ref_con_set             * 10);
              SanRex_ptr_a[8] = (int)(Vdc_ref_con_set_level       * 100);
              SanRex_ptr_a[9] = (int)(Idc_ref_comp                * 100);

              SanRex_ptr_a[10] = (int)(Kp_Vdc_con_ratio     * 100);
              SanRex_ptr_a[11] = (int)(Ki_Vdc_con_ratio     * 100);
              SanRex_ptr_a[12] = (int)(Kp_Idc_con_ratio     * 100);
              SanRex_ptr_a[13] = (int)(Ki_Idc_con_ratio     * 100);
              SanRex_ptr_a[14] = (int)(Kp_Vdc_ratio         * 100);
              SanRex_ptr_a[15] = (int)(Ki_Vdc_inv_ratio     * 100);
              SanRex_ptr_a[16] = (int)(Kp_Ia_ratio          * 100);
              SanRex_ptr_a[17] = (int)(Ki_Ia_ratio          * 100);
              SanRex_ptr_a[18] = (int)(Mode_system          * 100);
              SanRex_ptr_a[19] = (int)(SCI_WR_Mode          * 100);


  //          SanRex_ptr_a[20] = Enable_EEPROM_write;
              SanRex_ptr_a[20] = (int)(OP_MODE          * 1);
              SanRex_ptr_a[21] = (int)(Run_Stop_com     * 1);
              SanRex_ptr_a[22] = (int)(Fault_reset_com  * 1);
       }

        else if(SCI_WR_Mode == 3)
        {
            //Inverter /V/I/Power
              SanRex_ptr_a[0] = (int)(Kp_Vdc_con                  * 100);
              SanRex_ptr_a[1] = (int)(Ki_Vdc_con                  * 100);
              SanRex_ptr_a[2] = (int)(Kp_Idc                      * 10000);
              SanRex_ptr_a[3] = (int)(Ki_Idc                      * 10000);
              SanRex_ptr_a[4] = (int)(Kp_Vdc_con_ratio            * 100);
              SanRex_ptr_a[5] = (int)(Ki_Vdc_con_ratio            * 100);
              SanRex_ptr_a[6] = (int)(Kp_Idc_con_ratio            * 100);
              SanRex_ptr_a[7] = (int)(Ki_Idc_con_ratio            * 100);
              SanRex_ptr_a[8] = (int)(Wn_VC                       * 10);
              SanRex_ptr_a[9] = (int)(Wc_CC                       * 10);

              SanRex_ptr_a[10] = (int)(Lc_input                   * 10);
              SanRex_ptr_a[11] = (int)(Cdc_input                  * 10);
              SanRex_ptr_a[12] = (int)(Vdc_ref_set_init           * 10);
              SanRex_ptr_a[13] = (int)(Kp_Vdc_ratio               * 100);
              SanRex_ptr_a[14] = (int)(Ki_Vdc_inv_ratio           * 100);
              SanRex_ptr_a[15] = (int)(K_cc_ratio[0]              * 10);
              SanRex_ptr_a[16] = (int)(K_cc_ratio[1]              * 10);
              SanRex_ptr_a[17] = (int)(K_cc_ratio[2]              * 10);
              SanRex_ptr_a[18] = (int)(Mode_system                * 100);
              SanRex_ptr_a[19] = (int)(SCI_WR_Mode                * 100);


  //          SanRex_ptr_a[20] = Enable_EEPROM_write;
              SanRex_ptr_a[20] = (int)(OP_MODE          * 1);
              SanRex_ptr_a[21] = (int)(Run_Stop_com     * 1);
              SanRex_ptr_a[22] = (int)(Fault_reset_com  * 1);
        }

        else if(SCI_WR_Mode == 4)
        {
            SanRex_ptr_a[0] = (int)(EPwm1_CMP_test              * 100);
            SanRex_ptr_a[1] = (int)(EPwm2_CMP_test              * 100);
            SanRex_ptr_a[2] = (int)(Ta_con_test1                * 10);
            SanRex_ptr_a[3] = (int)(Flag_gating_test            * 100);
            SanRex_ptr_a[4] = (int)(VF_vtg_max                  * 10);
//            SanRex_ptr_a[4] = (int)(VF_vtg_max_no_Vdc           * 100);


            SanRex_ptr_a[5] = (int)(Flag_gating_VF_TEST         * 100);
            SanRex_ptr_a[6] = (int)(OV_set_Vin_test             * 100);
            SanRex_ptr_a[7] = (int)(OC_Idc_set_test             * 100);
            SanRex_ptr_a[8] = (int)(OV_set_Vdc_test             * 10);
            SanRex_ptr_a[9] = (int)(OC_set_test                 * 100);

            SanRex_ptr_a[10] = (int)(DO7_output                 * 100);
            SanRex_ptr_a[11] = (int)(DO6_output                 * 100);
            SanRex_ptr_a[12] = (int)(DO5_output                 * 100);
            SanRex_ptr_a[13] = (int)(DO4_output                 * 100);
            SanRex_ptr_a[14] = (int)(DO3_output                 * 100);
            SanRex_ptr_a[15] = (int)(DO2_output                 * 100);
            SanRex_ptr_a[16] = (int)(DO1_output                 * 100);
            SanRex_ptr_a[17] = (int)(Mode_test                  * 100);
            SanRex_ptr_a[18] = (int)(Mode_system                * 100);
            SanRex_ptr_a[19] = (int)(SCI_WR_Mode                * 100);

//          SanRex_ptr_a[20] = Enable_EEPROM_write;
            SanRex_ptr_a[20] = (int)(OP_MODE          * 1);
            SanRex_ptr_a[21] = (int)(Run_Stop_com     * 1);
            SanRex_ptr_a[22] = (int)(Fault_reset_com  * 1);
        }

        else if(SCI_WR_Mode == 5)
        {
            SanRex_ptr_a[0] = (int)(Vin_max                  * 100);
            SanRex_ptr_a[1] = (int)(Vin_min                  * 100);
            SanRex_ptr_a[2] = (int)(Idc_max                  * 100);
            SanRex_ptr_a[3] = (int)(Vdc_max                  * 10);
            SanRex_ptr_a[4] = (int)(Vl_rate                  * 10);
            SanRex_ptr_a[5] = (int)(Ic_rate                  * 100);
            SanRex_ptr_a[6] = (int)(Pout_rate                * 100);
            SanRex_ptr_a[7] = (int)(Vdc_ref_inv              * 10);
            SanRex_ptr_a[8] = (int)(Ip_ref_real_max          * 100);
            SanRex_ptr_a[9] = (int)(Vdc_ref_con_set          * 10);

            SanRex_ptr_a[10] = (int)(OV_set_Vin                 * 100);
            SanRex_ptr_a[11] = (int)(UV_set_Vin                 * 100);
            SanRex_ptr_a[12] = (int)(OC_Idc_set                 * 100);
            SanRex_ptr_a[13] = (int)(OV_set_Vdc                 * 10);
            SanRex_ptr_a[14] = (int)(OV_set_src                 * 10);
            SanRex_ptr_a[15] = (int)(UV_set_src                 * 10);
            SanRex_ptr_a[16] = (int)(INTER_set_src              * 100);
            SanRex_ptr_a[17] = (int)(OC_set                     * 100);
            SanRex_ptr_a[18] = (int)(Overload_Pout              * 100);
            SanRex_ptr_a[19] = (int)(SCI_WR_Mode                * 100);

//          SanRex_ptr_a[20] = Enable_EEPROM_write;
            SanRex_ptr_a[20] = (int)(OP_MODE          * 1);
            SanRex_ptr_a[21] = (int)(Run_Stop_com     * 1);
            SanRex_ptr_a[22] = (int)(Fault_reset_com  * 1);
        }

        else if(SCI_WR_Mode == 6)
        {
            //Inverter /V/I/Power
              SanRex_ptr_a[0] = (int)(Kp_Vde_ff                   * 100);
              SanRex_ptr_a[1] = (int)(Kp_Vqe_ff                   * 100);
              SanRex_ptr_a[2] = (int)(Kp_Ide_ff                   * 100);
              SanRex_ptr_a[3] = (int)(Kp_Iqe_ff                   * 100);
              SanRex_ptr_a[4] = (int)(Ide_ref_Cf                  * 100);
              SanRex_ptr_a[5] = (int)(Iqe_ref_Cf                  * 100);
              SanRex_ptr_a[6] = (int)(Ide_ref_Cf                  * 100);
              SanRex_ptr_a[7] = (int)(Iqe_ref_Cf                  * 100);
              SanRex_ptr_a[8] = (int)(Wn_VC                       * 10);
              SanRex_ptr_a[9] = (int)(Wc_CC                       * 10);

              SanRex_ptr_a[10] = (int)(Lc_input                   * 10);
              SanRex_ptr_a[11] = (int)(Cdc_input                  * 10);
              SanRex_ptr_a[12] = (int)(Vdc_ref_set_init           * 10);
              SanRex_ptr_a[13] = (int)(Kp_Vdc_ratio               * 100);
              SanRex_ptr_a[14] = (int)(Ki_Vdc_inv_ratio           * 100);
              SanRex_ptr_a[15] = (int)(K_cc_ratio[0]              * 10);
              SanRex_ptr_a[16] = (int)(K_cc_ratio[1]              * 10);
              SanRex_ptr_a[17] = (int)(K_cc_ratio[2]              * 10);
              SanRex_ptr_a[18] = (int)(Mode_system                * 100);
              SanRex_ptr_a[19] = (int)(SCI_WR_Mode                * 100);

  //          SanRex_ptr_a[20] = Enable_EEPROM_write;
              SanRex_ptr_a[20] = (int)(OP_MODE          * 1);
              SanRex_ptr_a[21] = (int)(Run_Stop_com     * 1);
              SanRex_ptr_a[22] = (int)(Fault_reset_com  * 1);
        }

        else if(SCI_WR_Mode == 7)
        {
            //Inverter /V/I/Power
              SanRex_ptr_a[0] = (int)(T_dead_input                * 100);
              SanRex_ptr_a[1] = (int)(T_dead_con_input            * 100);
              SanRex_ptr_a[2] = (int)(T_dead_comp_input           * 100);
              SanRex_ptr_a[3] = (int)(mode_Va_PLL3                * 100);
              SanRex_ptr_a[4] = (int)(time_check_cnt              * 100);
              SanRex_ptr_a[5] = (int)(Flag_Grid_err               * 100);
              SanRex_ptr_a[6] = (int)(EPwm1_CMP_test              * 100);
              SanRex_ptr_a[7] = (int)(EPwm2_CMP_test              * 100);
              SanRex_ptr_a[8] = (int)(flag_Iqe_ref_flt            * 100);
              SanRex_ptr_a[9] = (int)(Kp_Idc_ref_Cf               * 10000);

              SanRex_ptr_a[10] = (int)(FL_Vin                     * 1);
              SanRex_ptr_a[11] = (int)(FL_Idc                     * 1);
              SanRex_ptr_a[12] = (int)(FL_A_ref                   * 1);
              SanRex_ptr_a[13] = (int)(FL_Vdc                     * 1);
              SanRex_ptr_a[14] = (int)(FL_Va                      * 1);
              SanRex_ptr_a[15] = (int)(FL_Ia                      * 1);
              SanRex_ptr_a[16] = (int)(flag_control_parameter             * 100);
              SanRex_ptr_a[17] = (int)(Idc_ref_comp_input         * 100);
              SanRex_ptr_a[18] = (int)(SCI_WR_setting             * 100);
              SanRex_ptr_a[19] = (int)(SCI_WR_Mode                * 100);


  //          SanRex_ptr_a[20] = Enable_EEPROM_write;
              SanRex_ptr_a[20] = (int)(OP_MODE          * 1);
              SanRex_ptr_a[21] = (int)(Run_Stop_com     * 1);
              SanRex_ptr_a[22] = (int)(Fault_reset_com  * 1);
        }

        else if(SCI_WR_Mode == 8)
        {
              //Inverter /V/I/Power
              SanRex_ptr_a[0] = (int)(Wn_VC                   * 10);
              SanRex_ptr_a[1] = (int)(Kp_Vdc_ratio            * 10);
              SanRex_ptr_a[2] = (int)(Ki_Vdc_inv_ratio        * 10);
              SanRex_ptr_a[3] = (int)(Wc_CC                   * 10);
              SanRex_ptr_a[4] = (int)(K_cc_ratio[0]           * 10);
              SanRex_ptr_a[5] = (int)(K_cc_ratio[1]           * 10);
              SanRex_ptr_a[6] = (int)(K_cc_ratio[2]           * 10);
              SanRex_ptr_a[7] = (int)(K_cc_ratio[3]           * 10);
              SanRex_ptr_a[8] = (int)(K_cc_ratio[4]           * 10);
              SanRex_ptr_a[9] = (int)(K_cc_ratio[5]           * 10);

              SanRex_ptr_a[10] = (int)(Kp_Ia_ratio            * 10);
              SanRex_ptr_a[11] = (int)(Ki_Ia_ratio            * 10);
              SanRex_ptr_a[12] = (int)(Kp_Ia_ratio_D          * 10);
              SanRex_ptr_a[13] = (int)(Ki_Ia_ratio_D          * 10);
              SanRex_ptr_a[14] = (int)(voltage_control_inv3_cnt_max  * 100);
              SanRex_ptr_a[15] = (int)(Flag_over_check        * 100);
              SanRex_ptr_a[16] = (int)(flag_control_parameter * 100);
              SanRex_ptr_a[17] = (int)(Idc_ref_comp_input     * 100);
              SanRex_ptr_a[18] = (int)(SCI_WR_setting         * 100);
              SanRex_ptr_a[19] = (int)(SCI_WR_Mode            * 100);

  //          SanRex_ptr_a[20] = Enable_EEPROM_write;
              SanRex_ptr_a[20] = (int)(OP_MODE          * 1);
              SanRex_ptr_a[21] = (int)(Run_Stop_com     * 1);
              SanRex_ptr_a[22] = (int)(Fault_reset_com  * 1);
        }

        else if(SCI_WR_Mode == 9)
        {
              //Inverter /V/I/Power
              SanRex_ptr_a[0] = (int)(FL_Vin                  * 1);
              SanRex_ptr_a[1] = (int)(FL_Idc                  * 1);
              SanRex_ptr_a[2] = (int)(FL_A_ref                * 1);
              SanRex_ptr_a[3] = (int)(FL_Vdc                  * 1);
              SanRex_ptr_a[4] = (int)(FL_Va                   * 1);
              SanRex_ptr_a[5] = (int)(FL_Ia                   * 1);
              SanRex_ptr_a[6] = (int)(FL_s_volt               * 1);
              SanRex_ptr_a[7] = (int)(FL_e_volt               * 1);
              SanRex_ptr_a[8] = (int)(Fc_I_5th               * 1);
              SanRex_ptr_a[9] = (int)(Ia_PLL3_harmonic_k     * 100);

              SanRex_ptr_a[10] = (int)(mode_Va_PLL3            * 100);
              SanRex_ptr_a[11] = (int)(Flag_Ia_PLL3            * 100);
              SanRex_ptr_a[12] = (int)(Flag_current_control_inv3          * 100);
              SanRex_ptr_a[13] = (int)(Flag_Va_PLL3          * 100);
              SanRex_ptr_a[14] = (int)(voltage_control_inv3_cnt_max  * 100);
              SanRex_ptr_a[15] = (int)(Flag_over_check        * 100);
              SanRex_ptr_a[16] = (int)(flag_control_parameter * 100);
              SanRex_ptr_a[17] = (int)(Idc_ref_comp_input     * 100);
              SanRex_ptr_a[18] = (int)(SCI_WR_setting         * 100);
              SanRex_ptr_a[19] = (int)(SCI_WR_Mode            * 100);

  //          SanRex_ptr_a[20] = Enable_EEPROM_write;
              SanRex_ptr_a[20] = (int)(OP_MODE          * 1);
              SanRex_ptr_a[21] = (int)(Run_Stop_com     * 1);
              SanRex_ptr_a[22] = (int)(Fault_reset_com  * 1);
        }


        else if(SCI_WR_Mode == 10)
        {
              //Inverter /V/I/Power
              SanRex_ptr_a[0] = (int)(Flag_Ia_PLL3              * 100);
              SanRex_ptr_a[1] = (int)(Fc_I_5th                  * 1);
              SanRex_ptr_a[2] = (int)(Ia_PLL3_harmonic_k1       * 100);
              SanRex_ptr_a[3] = (int)(Ia_PLL3_harmonic_k2       * 100);
              SanRex_ptr_a[4] = (int)(Ia_PLL3_harmonic_k3       * 100);
              SanRex_ptr_a[5] = (int)(Kp_CC_Grid_comp_5th       * 10);
              SanRex_ptr_a[6] = (int)(Ki_CC_Grid_comp_5th       * 10);
              SanRex_ptr_a[7] = (int)(Kp_5th_ref                * 100);
              SanRex_ptr_a[8] = (int)(Flag_scia_cpu1_cpu2       * 100);
              SanRex_ptr_a[9] = (int)(OP_MODE                   * 100);

              SanRex_ptr_a[10] = (int)(mode_Va_PLL3            * 100);
              SanRex_ptr_a[11] = (int)(Flag_Ia_PLL3            * 100);
              SanRex_ptr_a[12] = (int)(Flag_current_control_inv3          * 100);
              SanRex_ptr_a[13] = (int)(Flag_Va_PLL3          * 100);
              SanRex_ptr_a[14] = (int)(voltage_control_inv3_cnt_max  * 100);
              SanRex_ptr_a[15] = (int)(Flag_over_check        * 100);
              SanRex_ptr_a[16] = (int)(flag_control_parameter * 100);
              SanRex_ptr_a[17] = (int)(Idc_ref_comp_input     * 100);
              SanRex_ptr_a[18] = (int)(SCI_WR_setting         * 100);
              SanRex_ptr_a[19] = (int)(SCI_WR_Mode            * 100);

  //          SanRex_ptr_a[20] = Enable_EEPROM_write;
              SanRex_ptr_a[20] = Idc_ref_comp; //Ver1.00 -> ver1.01
              SanRex_ptr_a[21] = (int)(OP_MODE          * 1.); //Ver1.00 -> ver1.01
              SanRex_ptr_a[22] = (int)(Run_Stop_com     * 1.); //Ver1.00 -> ver1.01
        }

        else if(SCI_WR_Mode == 11)
        {
              //Inverter /V/I/Power
              SanRex_ptr_a[0] = (int)(Flag_Act_islanding         * 100);
              SanRex_ptr_a[1] = (int)(Freq_high                  * 100);
              SanRex_ptr_a[2] = (int)(Freq_low                   * 100);
              SanRex_ptr_a[3] = (int)(Ia_PLL3_harmonic_k2       * 100);
              SanRex_ptr_a[4] = (int)(Ia_PLL3_harmonic_k3       * 100);
              SanRex_ptr_a[5] = (int)(Kp_CC_Grid_comp_5th       * 10);
              SanRex_ptr_a[6] = (int)(Ki_CC_Grid_comp_5th       * 10);
              SanRex_ptr_a[7] = (int)(Kp_5th_ref                * 100);
              SanRex_ptr_a[8] = (int)(Flag_scia_cpu1_cpu2       * 100);
              SanRex_ptr_a[9] = (int)(OP_MODE                   * 100);

              SanRex_ptr_a[10] = (int)(mode_Va_PLL3            * 100);
              SanRex_ptr_a[11] = (int)(Flag_Ia_PLL3            * 100);
              SanRex_ptr_a[12] = (int)(Flag_current_control_inv3          * 100);
              SanRex_ptr_a[13] = (int)(Flag_Va_PLL3          * 100);
              SanRex_ptr_a[14] = (int)(voltage_control_inv3_cnt_max  * 100);
              SanRex_ptr_a[15] = (int)(Flag_over_check        * 100);
              SanRex_ptr_a[16] = (int)(flag_control_parameter * 100);
              SanRex_ptr_a[17] = (int)(Idc_ref_comp_input     * 100);
              SanRex_ptr_a[18] = (int)(SCI_WR_setting         * 100);
              SanRex_ptr_a[19] = (int)(SCI_WR_Mode            * 100);

  //          SanRex_ptr[20] = Enable_EEPROM_write;
              SanRex_ptr[20] = (int)(OP_MODE          * 1);
              SanRex_ptr[21] = (int)(Run_Stop_com     * 1);
              SanRex_ptr[22] = (int)(Fault_reset_com  * 1);
        }
        else
        {
            //Inverter Scale
            SanRex_ptr_a[0] = (int)(Scale_Vin_ratio   * 100);
            SanRex_ptr_a[1] = (int)(Scale_Idc_ratio   * 100);
            SanRex_ptr_a[2] = (int)(Scale_A_ref_ratio * 100);
            SanRex_ptr_a[3] = (int)(Scale_Vdc_ratio   * 100);
            SanRex_ptr_a[4] = (int)(Scale_Esa_ratio   * 100);
            SanRex_ptr_a[5] = (int)(Scale_Esb_ratio   * 100);
            SanRex_ptr_a[6] = (int)(Scale_Esc_ratio   * 100);
            SanRex_ptr_a[7] = (int)(Scale_Ia_ratio    * 100);
            SanRex_ptr_a[8] = (int)(Scale_Ib_ratio    * 100);
            SanRex_ptr_a[9] = (int)(Scale_Ic_ratio    * 100);

            SanRex_ptr_a[10] = (int)(Vin_offset     * 100);
            SanRex_ptr_a[11] = (int)(Idc_offset     * 100);
            SanRex_ptr_a[12] = (int)(A_ref_offset   * 100);
            SanRex_ptr_a[13] = (int)(Vdc_offset     * 100);
            SanRex_ptr_a[14] = (int)(Ia_offset_comp * 100);
            SanRex_ptr_a[15] = (int)(Ib_offset_comp * 100);
            SanRex_ptr_a[16] = (int)(Ic_offset_comp * 100);
            SanRex_ptr_a[17] = (int)(Idc_ref_comp   * 100);
            SanRex_ptr_a[18] = (int)(Mode_system    * 100);
            SanRex_ptr_a[19] = (int)(SCI_WR_Mode    * 100);


//          SanRex_ptr_a[20] = Enable_EEPROM_write;
            SanRex_ptr_a[20] = (int)(OP_MODE          * 1);
            SanRex_ptr_a[21] = (int)(Run_Stop_com     * 1);
            SanRex_ptr_a[22] = (int)(Fault_reset_com  * 1);
        }

#endif

        // 2.   Mode_system_input       = 0         -> 1
        // 3.   Mode_test               = 0         -> no action
        // 4.   Flag_pwm_inv_test2      = 0         -> 1
        // 5.   Ta_inv_test2            = 0         -> 1
        // 6.   Tb_inv_test2            = 0         -> 1
        // 7.   Tc_inv_test2            = 0         -> 1
#if 0
        SanRex_ptr_a[0] = (int)(Scale_Vin_ratio*100);
        SanRex_ptr_a[1] = (int)(Scale_Idc_ratio*100);
        SanRex_ptr_a[2] = (int)(Scale_A_ref_ratio*100);
        SanRex_ptr_a[3] = (int)(Scale_Vdc_ratio*100);
        SanRex_ptr_a[4] = (int)(Scale_Esa_ratio*100);
        SanRex_ptr_a[5] = (int)(Scale_Ia_ratio*100);
        SanRex_ptr_a[6] = (int)(Kp_Vdc_con_ratio*100);
        SanRex_ptr_a[7] = (int)(Ki_Vdc_con_ratio*100);
        SanRex_ptr_a[8] = (int)(Kp_Idc_con_ratio*100);
        SanRex_ptr_a[9] = (int)(Ki_Idc_con_ratio*100);

        SanRex_ptr_a[10] = (int)(Vin_offset_input*100);
        SanRex_ptr_a[11] = (int)(Idc_offset_input*100);
        SanRex_ptr_a[12] = (int)(A_ref_offset_input*100);
        SanRex_ptr_a[13] = (int)(Vdc_offset_input*100);
        SanRex_ptr_a[14] = (int)(Scale_Esb_ratio*100);
        SanRex_ptr_a[15] = (int)(Scale_Ic_ratio*100);
        SanRex_ptr_a[16] = (int)(Kp_Vdc_ratio*100);
        SanRex_ptr_a[17] = (int)(Ki_Vdc_inv_ratio*100);
        SanRex_ptr_a[18] = (int)(Kp_Ia_ratio*100);
        SanRex_ptr_a[19] = (int)(Ki_Ia_ratio*100);

        SanRex_ptr_a[20] = Enable_EEPROM_write;
#endif

        // 2.   Mode_system_input       = 0         -> 1
        // 3.   Mode_test               = 0         -> no action
        // 4.   Flag_pwm_inv_test2      = 0         -> 1
        // 5.   Ta_inv_test2            = 0         -> 1
        // 6.   Tb_inv_test2            = 0         -> 1
        // 7.   Tc_inv_test2            = 0         -> 1
#if 0
        //phase shift test
        SanRex_ptr_a[0] = (int)(Mode_system_input * 100);
        SanRex_ptr_a[1] = (int)(Mode_test         * 100);
        SanRex_ptr_a[2] = (int)(DO1_output        * 100);
        SanRex_ptr_a[3] = (int)(Vdc_ref_con_set   * 10);
        SanRex_ptr_a[4] = (int)(Idc_ref_comp      * 100);
        SanRex_ptr_a[5] = (int)(Idc_limit_con     * 100);
        SanRex_ptr_a[6] = (int)(Flag_gating_test  * 100);
        SanRex_ptr_a[7] = (int)(OV_set_Vin_test   * 100);
        SanRex_ptr_a[8] = (int)(OC_Idc_set_test   * 100);
        SanRex_ptr_a[9] = (int)(OV_set_Vdc_test   * 10);

        SanRex_ptr_a[10] = (int)(Mode_system_input    * 100);
        SanRex_ptr_a[11] = (int)(Mode_test            * 100);
        SanRex_ptr_a[12] = (int)(DO2_output           * 100);
        SanRex_ptr_a[13] = (int)(VF_vtg_max           * 10);
        SanRex_ptr_a[14] = (int)(Flag_gating_VF_TEST  * 100);
        SanRex_ptr_a[15] = (int)(OC_set_test          * 100);
        SanRex_ptr_a[16] = (int)(DO3_output           * 100);

//        SanRex_ptr_a[17] = (int)(DO4_output           * 100);
//        SanRex_ptr_a[18] = (int)(DO5_output          * 100);
        SanRex_ptr_a[17] = (int)(EPwm1_CMP_test           * 100);
        SanRex_ptr_a[18] = (int)(EPwm2_CMP_test          * 100);
        SanRex_ptr_a[19] = (int)(Ta_con_test1        * 10);

        SanRex_ptr_a[20] = Enable_EEPROM_write;
#endif


#if 0
        //one pulse test
        SanRex_ptr_a[0] = (int)(Mode_system_input * 100);
        SanRex_ptr_a[1] = (int)(Mode_test         * 100);
        SanRex_ptr_a[2] = (int)(DO1_output        * 100);
        SanRex_ptr_a[3] = (int)(Flag_gating_test   * 100);
        SanRex_ptr_a[4] = (int)(Ta_con_test1      * 10);
        SanRex_ptr_a[5] = (int)(Ta_con_test1      * 10);
        SanRex_ptr_a[6] = (int)(Tb_con_test1      * 10);
        SanRex_ptr_a[7] = (int)(Tb_con_test1      * 10);
        SanRex_ptr_a[8] = (int)(Tc_con_test1      * 10);
        SanRex_ptr_a[9] = (int)(Tc_con_test1      * 10);

        SanRex_ptr_a[10] = (int)(Mode_system_input    * 100);
        SanRex_ptr_a[11] = (int)(Mode_test            * 100);
        SanRex_ptr_a[12] = (int)(DO2_output           * 100);
        SanRex_ptr_a[13] = (int)(Flag_gating_test_cnt_max           * 100);
        SanRex_ptr_a[14] = (int)(Flag_pwm_1P          * 100);
        SanRex_ptr_a[15] = (int)(Flag_pwm_1N          * 100);
        SanRex_ptr_a[16] = (int)(Flag_pwm_2P          * 100);
        SanRex_ptr_a[17] = (int)(Flag_pwm_2N          * 100);
        SanRex_ptr_a[18] = (int)(Flag_pwm_3P          * 100);
        SanRex_ptr_a[19] = (int)(Flag_pwm_3N          * 100);

        SanRex_ptr_a[20] = Enable_EEPROM_write;
#endif

        MODBUS_transmitt_buffer_a[0]='M';
        MODBUS_transmitt_buffer_a[1]='S';
        MODBUS_transmitt_buffer_a[2]=0x20;

    }

    else if(hyun_flag_a==5)
    {
        SanRex_ptr_a[0] = (int)(Scale_Vin_ratio*10);
        SanRex_ptr_a[1] = (int)(Scale_Idc_ratio*10);
        SanRex_ptr_a[2] = (int)(Scale_A_ref_ratio*10);
        SanRex_ptr_a[3] = (int)(Scale_Vdc_ratio*10);
        SanRex_ptr_a[4] = (int)(Scale_Esa_ratio*10);
        SanRex_ptr_a[5] = (int)(Scale_Ia_ratio*10);
        SanRex_ptr_a[6] = (int)(Kp_Vdc_con_ratio*10);
        SanRex_ptr_a[7] = (int)(Ki_Vdc_con_ratio*10);
        SanRex_ptr_a[8] = (int)(Kp_Idc_con_ratio*10);
        SanRex_ptr_a[9] = (int)(Ki_Idc_con_ratio*10);

        SanRex_ptr_a[10] = (int)(Vin_offset_input*10);
        SanRex_ptr_a[11] = (int)(Idc_offset_input*10);
        SanRex_ptr_a[12] = (int)(A_ref_offset_input*10);
        SanRex_ptr_a[13] = (int)(Vdc_offset_input*10);
        SanRex_ptr_a[14] = (int)(Esa_offset_comp_input*10);
        SanRex_ptr_a[15] = (int)(Ia_offset_comp_input*10);
        SanRex_ptr_a[16] = (int)(Kp_Vdc_ratio*10);
        SanRex_ptr_a[17] = (int)(Ki_Vdc_inv_ratio*10);
        SanRex_ptr_a[18] = (int)(Kp_Ia_ratio*10);
        SanRex_ptr_a[19] = (int)(Ki_Ia_ratio*10);

//          SanRex_ptr_a[20] = Enable_EEPROM_write;
        SanRex_ptr_a[20] = (int)(OP_MODE          * 1);
        SanRex_ptr_a[21] = (int)(Run_Stop_com     * 1);
        SanRex_ptr_a[22] = (int)(Fault_reset_com  * 1);

        MODBUS_transmitt_buffer_a[0]='M';
        MODBUS_transmitt_buffer_a[1]='K';
        MODBUS_transmitt_buffer_a[2]=0x20;
    }

    else if(hyun_flag_a==9)
    {
        SanRex_ptr_a[0] = (int)(Vin_max                  * 100);
        SanRex_ptr_a[1] = (int)(Vin_min                  * 100);
        SanRex_ptr_a[2] = (int)(Idc_max                  * 100);
        SanRex_ptr_a[3] = (int)(Vdc_max                  * 10);
        SanRex_ptr_a[4] = (int)(Vl_rate                  * 10);
        SanRex_ptr_a[5] = (int)(Ic_rate                  * 100);
        SanRex_ptr_a[6] = (int)(Pout_rate                * 100);
        SanRex_ptr_a[7] = (int)(Vdc_ref_inv              * 10);
        SanRex_ptr_a[8] = (int)(Ip_ref_real_max          * 100);
        SanRex_ptr_a[9] = (int)(Vdc_ref_con_set          * 10);

        SanRex_ptr_a[10] = (int)(OV_set_Vin                 * 100);
        SanRex_ptr_a[11] = (int)(UV_set_Vin                 * 100);
        SanRex_ptr_a[12] = (int)(OC_Idc_set                 * 100);
        SanRex_ptr_a[13] = (int)(OV_set_Vdc                 * 10);
        SanRex_ptr_a[14] = (int)(OV_set_src                 * 10);
        SanRex_ptr_a[15] = (int)(UV_set_src                 * 10);
        SanRex_ptr_a[16] = (int)(INTER_set_src              * 100);
        SanRex_ptr_a[17] = (int)(OC_set                     * 100);
        SanRex_ptr_a[18] = (int)(Overload_Pout              * 100);
        SanRex_ptr_a[19] = (int)(SCI_WR_Mode                * 100);


//          SanRex_ptr_a[20] = Enable_EEPROM_write;
        SanRex_ptr_a[20] = (int)(OP_MODE          * 1);
        SanRex_ptr_a[21] = (int)(Run_Stop_com     * 1);
        SanRex_ptr_a[22] = (int)(Fault_reset_com  * 1);

        MODBUS_transmitt_buffer_a[0]='M';
        MODBUS_transmitt_buffer_a[1]='E';
        MODBUS_transmitt_buffer_a[2]=0x20;
    }

#if 0
    else if(0x20 <= hyun_flag_a <= 0x29)
    {
        SanRex_ptr_a[0]  = History[hyun_flag_a-0x20][0];
        SanRex_ptr_a[1]  = History[hyun_flag_a-0x20][1];
        SanRex_ptr_a[2]  = History[hyun_flag_a-0x20][2];
        SanRex_ptr_a[3]  = History[hyun_flag_a-0x20][3];
        SanRex_ptr_a[4]  = History[hyun_flag_a-0x20][4];
        SanRex_ptr_a[5]  = History[hyun_flag_a-0x20][5];
        SanRex_ptr_a[6]  = History[hyun_flag_a-0x20][6];
        SanRex_ptr_a[7]  = History[hyun_flag_a-0x20][7];
        SanRex_ptr_a[8]  = History[hyun_flag_a-0x20][8];
        SanRex_ptr_a[9]  = History[hyun_flag_a-0x20][9];
        SanRex_ptr_a[10] = History[hyun_flag_a-0x20][10];
        SanRex_ptr_a[11] = History[hyun_flag_a-0x20][11];
        SanRex_ptr_a[12] = History[hyun_flag_a-0x20][12];
        SanRex_ptr_a[13] = History[hyun_flag_a-0x20][13];
        SanRex_ptr_a[14] = History[hyun_flag_a-0x20][14];
        SanRex_ptr_a[15] = History[hyun_flag_a-0x20][15];
        SanRex_ptr_a[16] = History[hyun_flag_a-0x20][16];
        SanRex_ptr_a[17] = History[hyun_flag_a-0x20][17];
        SanRex_ptr_a[18] = History[hyun_flag_a-0x20][18];
        SanRex_ptr_a[19] = History[hyun_flag_a-0x20][19];

        SanRex_ptr_a[20] = 0;

        MODBUS_transmitt_buffer_a[0]  = 'H';
        MODBUS_transmitt_buffer_a[1]  = 'T';
        MODBUS_transmitt_buffer_a[2]  = hyun_flag;
    }
#endif

        MODBUS_transmitt_buffer_a[3]  = '0';
        MODBUS_transmitt_buffer_a[4]  = '0';
        MODBUS_transmitt_buffer_a[5]  = 0x20;

#if 0
    for(i=0; i< 21; i++) // Make TransmittBuffer
    {
        imsi_data_bytehigh_a = ((SanRex_ptr_a[i] & 0xff00)>>8) & 0x00ff;
        imsi_data_bytelow_a  = (SanRex_ptr_a[i] & 0x00ff);

        imsi_data_bytehigh_high_a = ((imsi_data_bytehigh_a & 0x00f0) >> 4) & 0x000f;
        imsi_data_bytehigh_low_a  = (imsi_data_bytehigh_a & 0x000f);

        imsi_data_bytelow_high_a = ((imsi_data_bytelow_a & 0x00f0) >> 4) & 0x000f;
        imsi_data_bytelow_low_a  = (imsi_data_bytelow_a & 0x000f);


        if (imsi_data_bytehigh_high_a > 0x09)
        {   // Convert ASCII CHAR
            MODBUS_transmitt_buffer_a[(i*5)+6] = imsi_data_bytehigh_high_a + 0x37;

        } else MODBUS_transmitt_buffer_a[(i*5)+6] = imsi_data_bytehigh_high_a + 0x30;

        if (imsi_data_bytehigh_low_a > 0x09)
        {   // Convert ASCII CHAR
            MODBUS_transmitt_buffer_a[(i*5)+7] = imsi_data_bytehigh_low_a + 0x37;

        } else MODBUS_transmitt_buffer_a[(i*5)+7] = imsi_data_bytehigh_low_a + 0x30;

        if (imsi_data_bytelow_high_a > 0x09)
        {   // Convert ASCII CHAR
            MODBUS_transmitt_buffer_a[(i*5)+8] = imsi_data_bytelow_high_a + 0x37;

        } else MODBUS_transmitt_buffer_a[(i*5)+8] = imsi_data_bytelow_high_a + 0x30;

        if (imsi_data_bytelow_low_a > 0x09)
        {    // Convert ASCII CHAR
            MODBUS_transmitt_buffer_a[(i*5)+9] = imsi_data_bytelow_low_a + 0x37;

        } else MODBUS_transmitt_buffer_a[(i*5)+9] = imsi_data_bytelow_low_a + 0x30;

        if (i < 20) MODBUS_transmitt_buffer_a[(i*5)+10] = 0x2c;
    }


    MODBUS_transmitt_buffer_a[110]    = 0x0d;
    MODBUS_transmitt_buffer_a[111]    = 'H';
    MODBUS_transmitt_buffer_a[112]    = ':';

    transmitt_flag_a  = 1;
    transmitt_data_length_a = 113;
#endif


    for(i=0; i< 23; i++) // Make TransmittBuffer
       {
           imsi_data_bytehigh_a = ((SanRex_ptr_a[i] & 0xff00)>>8) & 0x00ff;
           imsi_data_bytelow_a  = (SanRex_ptr_a[i] & 0x00ff);

           imsi_data_bytehigh_high_a = ((imsi_data_bytehigh_a & 0x00f0) >> 4) & 0x000f;
           imsi_data_bytehigh_low_a  = (imsi_data_bytehigh_a & 0x000f);

           imsi_data_bytelow_high_a = ((imsi_data_bytelow_a & 0x00f0) >> 4) & 0x000f;
           imsi_data_bytelow_low_a  = (imsi_data_bytelow_a & 0x000f);


           if (imsi_data_bytehigh_high_a > 0x09)
           {   // Convert ASCII CHAR
               MODBUS_transmitt_buffer_a[(i*5)+6] = imsi_data_bytehigh_high_a + 0x37;

           } else MODBUS_transmitt_buffer_a[(i*5)+6] = imsi_data_bytehigh_high_a + 0x30;

           if (imsi_data_bytehigh_low_a > 0x09)
           {   // Convert ASCII CHAR
               MODBUS_transmitt_buffer_a[(i*5)+7] = imsi_data_bytehigh_low_a + 0x37;

           } else MODBUS_transmitt_buffer_a[(i*5)+7] = imsi_data_bytehigh_low_a + 0x30;

           if (imsi_data_bytelow_high_a > 0x09)
           {   // Convert ASCII CHAR
               MODBUS_transmitt_buffer_a[(i*5)+8] = imsi_data_bytelow_high_a + 0x37;

           } else MODBUS_transmitt_buffer_a[(i*5)+8] = imsi_data_bytelow_high_a + 0x30;

           if (imsi_data_bytelow_low_a > 0x09)
           {    // Convert ASCII CHAR
               MODBUS_transmitt_buffer_a[(i*5)+9] = imsi_data_bytelow_low_a + 0x37;

           } else MODBUS_transmitt_buffer_a[(i*5)+9] = imsi_data_bytelow_low_a + 0x30;

           if (i < 22) MODBUS_transmitt_buffer_a[(i*5)+10] = 0x2c;
       }


       MODBUS_transmitt_buffer_a[120]    = 0x0d;
       MODBUS_transmitt_buffer_a[121]    = 'H';
       MODBUS_transmitt_buffer_a[122]    = ':';


       transmitt_data_length_a = 123;
      // (CRC16_a(transmitt_data_length_a-2,2));
       transmitt_flag_a  = 1;
}


//---------------------------------------------------------------------------------
void function_SanRex_HT_a()
{

// SanRex Inverter Protocol
    unsigned char imsi_data_bytehigh_a=0, imsi_data_bytelow_a=0;
    unsigned char imsi_data_bytehigh_high_a=0, imsi_data_bytehigh_low_a=0,imsi_data_bytelow_high_a=0, imsi_data_bytelow_low_a=0 ;
    int i=0;

    function_SanRex_HT_a_cnt++;


    if(0x20 <= hyun_flag_a <= 0x29)
    {
        SanRex_ptr_a[0]  = History[hyun_flag_a-0x20][0];
        SanRex_ptr_a[1]  = History[hyun_flag_a-0x20][1];
        SanRex_ptr_a[2]  = History[hyun_flag_a-0x20][2];
        SanRex_ptr_a[3]  = History[hyun_flag_a-0x20][3];
        SanRex_ptr_a[4]  = History[hyun_flag_a-0x20][4];
        SanRex_ptr_a[5]  = History[hyun_flag_a-0x20][5];
        SanRex_ptr_a[6]  = History[hyun_flag_a-0x20][6];
        SanRex_ptr_a[7]  = History[hyun_flag_a-0x20][7];
        SanRex_ptr_a[8]  = History[hyun_flag_a-0x20][8];
        SanRex_ptr_a[9]  = History[hyun_flag_a-0x20][9];
        SanRex_ptr_a[10] = History[hyun_flag_a-0x20][10];
        SanRex_ptr_a[11] = History[hyun_flag_a-0x20][11];
        SanRex_ptr_a[12] = History[hyun_flag_a-0x20][12];
        SanRex_ptr_a[13] = History[hyun_flag_a-0x20][13];
        SanRex_ptr_a[14] = History[hyun_flag_a-0x20][14];
        SanRex_ptr_a[15] = History[hyun_flag_a-0x20][15];
        SanRex_ptr_a[16] = History[hyun_flag_a-0x20][16];
        SanRex_ptr_a[17] = History[hyun_flag_a-0x20][17];
        SanRex_ptr_a[18] = History[hyun_flag_a-0x20][18];
        SanRex_ptr_a[19] = History[hyun_flag_a-0x20][19];

        SanRex_ptr_a[20] = 0;

        MODBUS_transmitt_buffer_a[0]  = 'H';
        MODBUS_transmitt_buffer_a[1]  = 'T';
        MODBUS_transmitt_buffer_a[2]  = hyun_flag_a;
    }

        MODBUS_transmitt_buffer_a[3]  = '0';
        MODBUS_transmitt_buffer_a[4]  = '0';
        MODBUS_transmitt_buffer_a[5]  = 0x20;

    for(i=0; i< 21; i++) // Make TransmittBuffer
    {
        imsi_data_bytehigh_a = ((SanRex_ptr_a[i] & 0xff00)>>8) & 0x00ff;
        imsi_data_bytelow_a  = (SanRex_ptr_a[i] & 0x00ff);

        imsi_data_bytehigh_high_a = ((imsi_data_bytehigh_a & 0x00f0) >> 4) & 0x000f;
        imsi_data_bytehigh_low_a  = (imsi_data_bytehigh_a & 0x000f);

        imsi_data_bytelow_high_a = ((imsi_data_bytelow_a & 0x00f0) >> 4) & 0x000f;
        imsi_data_bytelow_low_a  = (imsi_data_bytelow_a & 0x000f);


        if (imsi_data_bytehigh_high_a > 0x09)
        {   // Convert ASCII CHAR
            MODBUS_transmitt_buffer_a[(i*5)+6] = imsi_data_bytehigh_high_a + 0x37;

        } else MODBUS_transmitt_buffer_a[(i*5)+6] = imsi_data_bytehigh_high_a + 0x30;

        if (imsi_data_bytehigh_low_a > 0x09)
        {   // Convert ASCII CHAR
            MODBUS_transmitt_buffer_a[(i*5)+7] = imsi_data_bytehigh_low_a + 0x37;

        } else MODBUS_transmitt_buffer_a[(i*5)+7] = imsi_data_bytehigh_low_a + 0x30;

        if (imsi_data_bytelow_high_a > 0x09)
        {   // Convert ASCII CHAR
            MODBUS_transmitt_buffer_a[(i*5)+8] = imsi_data_bytelow_high_a + 0x37;

        } else MODBUS_transmitt_buffer_a[(i*5)+8] = imsi_data_bytelow_high_a + 0x30;

        if (imsi_data_bytelow_low_a > 0x09)
        {    // Convert ASCII CHAR
            MODBUS_transmitt_buffer_a[(i*5)+9] = imsi_data_bytelow_low_a + 0x37;

        } else MODBUS_transmitt_buffer_a[(i*5)+9] = imsi_data_bytelow_low_a + 0x30;

        if (i < 20) MODBUS_transmitt_buffer_a[(i*5)+10] = 0x2c;
    }


    MODBUS_transmitt_buffer_a[110]    = 0x0d;
    MODBUS_transmitt_buffer_a[111]    = 'H';
    MODBUS_transmitt_buffer_a[112]    = ':';

    transmitt_flag_a  = 1;
    transmitt_data_length_a = 113;
}


//---------------------------------------------------------------------------------
void function_SanRex2_a()
{

// SanRex Inverter Protocol
    unsigned char imsi_data_bytehigh_a=0, imsi_data_bytelow_a=0;
    unsigned char imsi_data_bytehigh_high_a=0, imsi_data_bytehigh_low_a=0,imsi_data_bytelow_high_a=0, imsi_data_bytelow_low_a=0 ;
    int i=0;

/************************************************ Edit 100517 *************************************************/

    if(hyun_flag == 11)
    {  // Edit 100517

        //Inverter Scale
        SanRex_ptr_a[0] = (int)(Scale_Vin_ratio   * 100);
        SanRex_ptr_a[1] = (int)(Scale_Idc_ratio   * 100);
        SanRex_ptr_a[2] = (int)(Scale_A_ref_ratio * 100);
        SanRex_ptr_a[3] = (int)(Scale_Vdc_ratio   * 100);
        SanRex_ptr_a[4] = (int)(Scale_Esa_ratio   * 100);
        SanRex_ptr_a[5] = (int)(Scale_Esb_ratio   * 100);
        SanRex_ptr_a[6] = (int)(Scale_Esc_ratio   * 100);
        SanRex_ptr_a[7] = (int)(Scale_Ia_ratio    * 100);
        SanRex_ptr_a[8] = (int)(Scale_Ib_ratio    * 100);
        SanRex_ptr_a[9] = (int)(Scale_Ic_ratio    * 100);

        SanRex_ptr_a[10] = (int)(Vin_offset     * 100);
        SanRex_ptr_a[11] = (int)(Idc_offset     * 100);
        SanRex_ptr_a[12] = (int)(A_ref_offset   * 100);
        SanRex_ptr_a[13] = (int)(Vdc_offset     * 100);
        SanRex_ptr_a[14] = (int)(Ia_offset_comp * 100);
        SanRex_ptr_a[15] = (int)(Ib_offset_comp * 100);
        SanRex_ptr_a[16] = (int)(Ic_offset_comp * 100);
        SanRex_ptr_a[17] = (int)(Idc_ref_comp   * 100);
        SanRex_ptr_a[18] = (int)(SCI_WR_setting    * 100);
        SanRex_ptr_a[19] = (int)(SCI_WR_Mode    * 100);

        SanRex_ptr_a[20] = Enable_EEPROM_write;


        MODBUS_transmitt_buffer_a[0]='T';
        MODBUS_transmitt_buffer_a[1]='A';
        MODBUS_transmitt_buffer_a[2]=0x20;
    }
    else if(hyun_flag_a == 12)
    {

        //Inverter /V/I/Power
        SanRex_ptr_a[0] = (int)(Vin_max           * 100);
        SanRex_ptr_a[1] = (int)(Vin_min           * 100);
        SanRex_ptr_a[2] = (int)(Idc_max           * 100);
        SanRex_ptr_a[3] = (int)(Vdc_max           * 10);
        SanRex_ptr_a[4] = (int)(Vl_rate           * 10);
        SanRex_ptr_a[5] = (int)(Ic_rate           * 100);
        SanRex_ptr_a[6] = (int)(Pout_rate         * 100);
        SanRex_ptr_a[7] = (int)(OV_Vin_level      * 100);
        SanRex_ptr_a[8] = (int)(UV_Vin_level      * 100);
        SanRex_ptr_a[9] = (int)(OC_Idc_ratio      * 100);

        SanRex_ptr_a[10] = (int)(OV_Vdc_level     * 100);
        SanRex_ptr_a[11] = (int)(OV_ratio_src     * 100);
        SanRex_ptr_a[12] = (int)(UV_ratio_src     * 100);
        SanRex_ptr_a[13] = (int)(INTER_ratio_src  * 100);
        SanRex_ptr_a[14] = (int)(OV_ratio_src_rms * 100);
        SanRex_ptr_a[15] = (int)(UV_ratio_src_rms * 100);
        SanRex_ptr_a[16] = (int)(OC_ratio         * 100);
        SanRex_ptr_a[17] = (int)(OL_ratio         * 100);
        SanRex_ptr_a[18] = (int)(Mode_system      * 100);
        SanRex_ptr_a[19] = (int)(SCI_WR_Mode      * 100);

        SanRex_ptr_a[20] = Enable_EEPROM_write;

        MODBUS_transmitt_buffer_a[0]='T';
        MODBUS_transmitt_buffer_a[1]='B';
        MODBUS_transmitt_buffer_a[2]=0x20;
    }
    else if(hyun_flag_a == 13)
    {
        //Inverter /V/I/Power
        SanRex_ptr_a[0] = (int)(Ref_con_inv_flag            * 100);
        SanRex_ptr_a[1] = (int)(Vdc_ref_inv                 * 10);
        SanRex_ptr_a[2] = (int)(Vl_rate                     * 10);
        SanRex_ptr_a[3] = (int)(Vdc_ref_inv_ratio           * 100);
        SanRex_ptr_a[4] = (int)(Ip_ref_real_max             * 100);
        SanRex_ptr_a[5] = (int)(Ic_rate                     * 100);
        SanRex_ptr_a[6] = (int)(Ip_ref_ratio                * 100);
        SanRex_ptr_a[7] = (int)(Vdc_ref_con_set             * 10);
        SanRex_ptr_a[8] = (int)(Vdc_ref_con_set_level       * 100);
        SanRex_ptr_a[9] = (int)(Idc_ref_comp                * 100);

        SanRex_ptr_a[10] = (int)(Kp_Vdc_con_ratio     * 100);
        SanRex_ptr_a[11] = (int)(Ki_Vdc_con_ratio     * 100);
        SanRex_ptr_a[12] = (int)(Kp_Idc_con_ratio     * 100);
        SanRex_ptr_a[13] = (int)(Ki_Idc_con_ratio     * 100);
        SanRex_ptr_a[14] = (int)(Kp_Vdc_ratio         * 100);
        SanRex_ptr_a[15] = (int)(Ki_Vdc_inv_ratio     * 100);
        SanRex_ptr_a[16] = (int)(Kp_Ia_ratio          * 100);
        SanRex_ptr_a[17] = (int)(Ki_Ia_ratio          * 100);
        SanRex_ptr_a[18] = (int)(Mode_system          * 100);
        SanRex_ptr_a[19] = (int)(SCI_WR_Mode          * 100);

        SanRex_ptr_a[20] = Enable_EEPROM_write;

        MODBUS_transmitt_buffer_a[0]='T';
        MODBUS_transmitt_buffer_a[1]='C';
        MODBUS_transmitt_buffer_a[2]=0x20;
    }
    else if(hyun_flag == 14)
    {
        //Inverter /V/I/Power
        SanRex_ptr_a[0] = (int)(Kp_Vdc_con                  * 100);
        SanRex_ptr_a[1] = (int)(Ki_Vdc_con                  * 100);
        SanRex_ptr_a[2] = (int)(Kp_Idc                      * 10000);
        SanRex_ptr_a[3] = (int)(Ki_Idc                      * 10000);
        SanRex_ptr_a[4] = (int)(Kp_Vdc_con_ratio            * 100);
        SanRex_ptr_a[5] = (int)(Ki_Vdc_con_ratio            * 100);
        SanRex_ptr_a[6] = (int)(Kp_Idc_con_ratio            * 100);
        SanRex_ptr_a[7] = (int)(Ki_Idc_con_ratio            * 100);
        SanRex_ptr_a[8] = (int)(Wn_VC                       * 10);
        SanRex_ptr_a[9] = (int)(Wc_CC                       * 10);

        SanRex_ptr_a[10] = (int)(Lc_input                   * 10);
        SanRex_ptr_a[11] = (int)(Cdc_input                  * 10);
        SanRex_ptr_a[12] = (int)(Vdc_ref_set_init           * 10);
        SanRex_ptr_a[13] = (int)(Kp_Vdc_ratio               * 100);
        SanRex_ptr_a[14] = (int)(Ki_Vdc_inv_ratio           * 100);
        SanRex_ptr_a[15] = (int)(K_cc_ratio[0]              * 10);
        SanRex_ptr_a[16] = (int)(K_cc_ratio[1]              * 10);
        SanRex_ptr_a[17] = (int)(K_cc_ratio[2]              * 10);
        SanRex_ptr_a[18] = (int)(Mode_system                * 100);
        SanRex_ptr_a[19] = (int)(SCI_WR_Mode                * 100);

        SanRex_ptr_a[20] = Enable_EEPROM_write;

        MODBUS_transmitt_buffer_a[0]='T';
        MODBUS_transmitt_buffer_a[1]='D';
        MODBUS_transmitt_buffer_a[2]=0x20;
    }

    else if(hyun_flag_a == 15)
    {
        SanRex_ptr_a[0] = (int)(EPwm1_CMP_test              * 100);
        SanRex_ptr_a[1] = (int)(EPwm2_CMP_test              * 100);
        SanRex_ptr_a[2] = (int)(Ta_con_test1                * 10);
        SanRex_ptr_a[3] = (int)(Flag_gating_test            * 100);
        SanRex_ptr_a[4] = (int)(VF_vtg_max                  * 10);
//            SanRex_ptr_a[4] = (int)(VF_vtg_max_no_Vdc           * 100);


        SanRex_ptr_a[5] = (int)(Flag_gating_VF_TEST         * 100);
        SanRex_ptr_a[6] = (int)(OV_set_Vin_test             * 100);
        SanRex_ptr_a[7] = (int)(OC_Idc_set_test             * 100);
        SanRex_ptr_a[8] = (int)(OV_set_Vdc_test             * 10);
        SanRex_ptr_a[9] = (int)(OC_set_test                 * 100);

        SanRex_ptr_a[10] = (int)(DO7_output                 * 100);
        SanRex_ptr_a[11] = (int)(DO6_output                 * 100);
        SanRex_ptr_a[12] = (int)(DO5_output                 * 100);
        SanRex_ptr_a[13] = (int)(DO4_output                 * 100);
        SanRex_ptr_a[14] = (int)(DO3_output                 * 100);
        SanRex_ptr_a[15] = (int)(DO2_output                 * 100);
        SanRex_ptr_a[16] = (int)(DO1_output                 * 100);
        SanRex_ptr_a[17] = (int)(Mode_test                  * 100);
        SanRex_ptr_a[18] = (int)(Mode_system                * 100);
        SanRex_ptr_a[19] = (int)(SCI_WR_Mode                * 100);

        SanRex_ptr_a[20] = Enable_EEPROM_write;

        MODBUS_transmitt_buffer_a[0]='T';
        MODBUS_transmitt_buffer_a[1]='E';
        MODBUS_transmitt_buffer_a[2]=0x20;
    }

    else if(hyun_flag_a == 16)
    {
        SanRex_ptr_a[0] = (int)(Vin_max                  * 100);
        SanRex_ptr_a[1] = (int)(Vin_min                  * 100);
        SanRex_ptr_a[2] = (int)(Idc_max                  * 100);
        SanRex_ptr_a[3] = (int)(Vdc_max                  * 10);
        SanRex_ptr_a[4] = (int)(Vl_rate                  * 10);
        SanRex_ptr_a[5] = (int)(Ic_rate                  * 100);
        SanRex_ptr_a[6] = (int)(Pout_rate                * 100);
        SanRex_ptr_a[7] = (int)(Vdc_ref_inv              * 10);
        SanRex_ptr_a[8] = (int)(Ip_ref_real_max          * 100);
        SanRex_ptr_a[9] = (int)(Vdc_ref_con_set          * 10);

        SanRex_ptr_a[10] = (int)(OV_set_Vin                 * 100);
        SanRex_ptr_a[11] = (int)(UV_set_Vin                 * 100);
        SanRex_ptr_a[12] = (int)(OC_Idc_set                 * 100);
        SanRex_ptr_a[13] = (int)(OV_set_Vdc                 * 10);
        SanRex_ptr_a[14] = (int)(OV_set_src                 * 10);
        SanRex_ptr_a[15] = (int)(UV_set_src                 * 10);
        SanRex_ptr_a[16] = (int)(INTER_set_src              * 100);
        SanRex_ptr_a[17] = (int)(OC_set                     * 100);
        SanRex_ptr_a[18] = (int)(Overload_Pout              * 100);
        SanRex_ptr_a[19] = (int)(SCI_WR_Mode                * 100);

        SanRex_ptr_a[20] = Enable_EEPROM_write;

        MODBUS_transmitt_buffer_a[0]='T';
        MODBUS_transmitt_buffer_a[1]='F';
        MODBUS_transmitt_buffer_a[2]=0x20;
    }

        MODBUS_transmitt_buffer_a[3]  = '0';
        MODBUS_transmitt_buffer_a[4]  = '0';
        MODBUS_transmitt_buffer_a[5]  = 0x20;


    for(i=0; i< 21; i++) // Make TransmittBuffer
    {
        imsi_data_bytehigh_a = ((SanRex_ptr_a[i] & 0xff00)>>8) & 0x00ff;
        imsi_data_bytelow_a  = (SanRex_ptr_a[i] & 0x00ff);

        imsi_data_bytehigh_high_a = ((imsi_data_bytehigh_a & 0x00f0) >> 4) & 0x000f;
        imsi_data_bytehigh_low_a  = (imsi_data_bytehigh_a & 0x000f);

        imsi_data_bytelow_high_a = ((imsi_data_bytelow_a & 0x00f0) >> 4) & 0x000f;
        imsi_data_bytelow_low_a  = (imsi_data_bytelow_a & 0x000f);


        if (imsi_data_bytehigh_high_a > 0x09)
        {   // Convert ASCII CHAR
            MODBUS_transmitt_buffer_a[(i*5)+6] = imsi_data_bytehigh_high_a + 0x37;

        } else MODBUS_transmitt_buffer_a[(i*5)+6] = imsi_data_bytehigh_high_a + 0x30;

        if (imsi_data_bytehigh_low_a > 0x09)
        {   // Convert ASCII CHAR
            MODBUS_transmitt_buffer_a[(i*5)+7] = imsi_data_bytehigh_low_a + 0x37;

        } else MODBUS_transmitt_buffer_a[(i*5)+7] = imsi_data_bytehigh_low_a + 0x30;

        if (imsi_data_bytelow_high_a > 0x09)
        {   // Convert ASCII CHAR
            MODBUS_transmitt_buffer_a[(i*5)+8] = imsi_data_bytelow_high_a + 0x37;

        } else MODBUS_transmitt_buffer_a[(i*5)+8] = imsi_data_bytelow_high_a + 0x30;

        if (imsi_data_bytelow_low_a > 0x09)
        {    // Convert ASCII CHAR
            MODBUS_transmitt_buffer_a[(i*5)+9] = imsi_data_bytelow_low_a + 0x37;

        } else MODBUS_transmitt_buffer_a[(i*5)+9] = imsi_data_bytelow_low_a + 0x30;

        if (i < 20) MODBUS_transmitt_buffer_a[(i*5)+10] = 0x2c;
    }


    MODBUS_transmitt_buffer_a[110]    = 0x0d;
    MODBUS_transmitt_buffer_a[111]    = 'H';
    MODBUS_transmitt_buffer_a[112]    = ':';

    transmitt_flag_a  = 1;
    transmitt_data_length_a = 113;
}

void function_WR_SanRex_a()
{
    char recv_buffer_a[6]={0x00,0x00,0x00,0x00,0x00,0x00};
    unsigned int add_data_a, all_data_a, low_data_a, high_data_a;
    int int_data_a;
    float float_data_a;
//    float   *temp;

    recv_buffer_a[0] = asc2hex(MODBUS_receive_buffer_a[3]);
    recv_buffer_a[1] = asc2hex(MODBUS_receive_buffer_a[4]);
    recv_buffer_a[2] = asc2hex(MODBUS_receive_buffer_a[6]);
    recv_buffer_a[3] = asc2hex(MODBUS_receive_buffer_a[7]);
    recv_buffer_a[4] = asc2hex(MODBUS_receive_buffer_a[8]);
    recv_buffer_a[5] = asc2hex(MODBUS_receive_buffer_a[9]);

    add_data_a = (((recv_buffer_a[0]&0xff) << 4) | recv_buffer_a[1]&0xff);
    high_data_a = (((recv_buffer_a[2]&0xff) << 4) | recv_buffer_a[3]&0xff);
    low_data_a = (((recv_buffer_a[4]&0xff) << 4) | recv_buffer_a[5]&0xff);
    all_data_a = ((high_data_a << 8) | low_data_a);

    int_data_a = (int)all_data_a;
    float_data_a = (float)int_data_a;

    add_data_lsc_a    = add_data_a;
    all_data_lsc_a    = all_data_a;
    float_data_lsc_a  = (float)int_data_a;

    if(add_data_a==0xff)      {   Enable_EEPROM_write=all_data_a;   }
    else if(add_data_a==0xfe) {   Init_offset=all_data_a;   }
    else if(add_data_a==0xfd) {   Init_scale=all_data_a;    }

    else if(add_data_a==0xf1) {   wr_time_Sel_Wr=all_data_a;}  //RTC initial
    else if(add_data_a==0xf3) {   wr_time_Set_year=all_data_a;      }  //RTC year
    else if(add_data_a==0xf4) {   wr_time_Set_mon_day=all_data_a;   }  //RTC mon_day
    else if(add_data_a==0xf5) {   wr_time_Set_hour_min=all_data_a;  }  //RTC hour_min

    else if(add_data_a==41) {   Flag_Act_islanding_input=all_data_a;  }  //RTC hour_min
    else if(add_data_a==42) {   Freq_shift_ratio_input=all_data_a;  }  //RTC hour_min

#if 1
    if(SCI_WR_Mode == 0)
    {
        //Inverter Scale
        if(add_data_a==0)         {   Scale_Vin_ratio      = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==1)    {   Scale_Idc_ratio      = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==2)    {   Scale_A_ref_ratio    = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==3)    {   Scale_Vdc_ratio      = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==4)    {   Scale_Esa_ratio      = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==5)    {   Scale_Esb_ratio      = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==6)    {   Scale_Esc_ratio      = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==7)    {   Scale_Ia_ratio       = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==8)    {   Scale_Ib_ratio       = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==9)    {   Scale_Ic_ratio       = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의

        else if(add_data_a==10)   {   Vin_offset_input     = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==11)   {   Idc_offset_input     = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==12)   {   A_ref_offset_input   = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==13)   {   Vdc_offset_input     = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==14)   {   Ia_offset_comp_input = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==15)   {   Ib_offset_comp_input = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==16)   {   Ic_offset_comp_input = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==17)   {   Idc_ref_comp_input   = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==18)   {   SCI_WR_setting       = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==19)   {   SCI_WR_Mode          = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의

        else if(add_data_a==20)   {  if(Flag_gating == 0)  {   OP_MODE=float_data_a;    }    }
        else if(add_data_a==21)   {   Run_Stop_com=float_data_a; }
        else if(add_data_a==22)   {   Fault_reset_com=float_data_a; }
    }

    else if(SCI_WR_Mode == 1)
    {
        //Inverter setting
        if(add_data_a==0)         {   Vin_max              = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==1)    {   Vin_min              = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==2)    {   Idc_max              = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==3)    {   Vdc_max              = (float_data_a   * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==4)    {   Vl_rate              = (float_data_a   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==5)    {   Ic_rate              = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==6)    {   Pout_rate            = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==7)    {   OV_Vin_level         = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==8)    {   UV_Vin_level         = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==9)    {   OC_Idc_ratio         = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의

        else if(add_data_a==10)   {   OV_Vdc_level         = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==11)   {   OV_ratio_src         = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==12)   {   UV_ratio_src         = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==13)   {   INTER_ratio_src      = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==14)   {   OV_ratio_src_rms     = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==15)   {   UV_ratio_src_rms     = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==16)   {   OC_ratio             = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==17)   {   OL_ratio             = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==18)   {   Mode_system_input    = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==19)   {   SCI_WR_Mode          = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의

        else if(add_data_a==20)   {  if(Flag_gating == 0)  {   OP_MODE=float_data_a;    }    }
        else if(add_data_a==21)   {   Run_Stop_com=float_data_a; }
        else if(add_data_a==22)   {   Fault_reset_com=float_data_a; }
    }

    else if(SCI_WR_Mode == 2)
    {
        //Inverter setting
        if(add_data_a==0)         {   Ref_con_inv_flag        = (int)(float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==1)    {   Vdc_ref_inv_input       = (float_data_a   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==2)    {   Vl_rate                 = (float_data_a   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==3)    {   Vdc_ref_inv_ratio       = (float_data_a   * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==4)    {   Ip_ref_real_max_input   = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==5)    {   Ic_rate                 = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==6)    {   Ip_ref_ratio            = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==7)    {   Vdc_ref_con_set_input   = (float_data_a   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==8)    {   Vdc_ref_con_set_level   = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==9)    {   Idc_ref_comp_input      = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의

        else if(add_data_a==10)   {   Kp_Vdc_con_ratio        = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==11)   {   Ki_Vdc_con_ratio        = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==12)   {   Kp_Idc_con_ratio        = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==13)   {   Ki_Idc_con_ratio        = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==14)   {   Kp_Vdc_ratio            = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==15)   {   Ki_Vdc_inv_ratio        = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==16)   {   Kp_Ia_ratio             = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==17)   {   Ki_Ia_ratio             = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==18)   {   Mode_system_input       = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==19)   {   SCI_WR_Mode             = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의

        else if(add_data_a==20)   {  if(Flag_gating == 0)  {   OP_MODE=float_data_a;    }    }
        else if(add_data_a==21)   {   Run_Stop_com=float_data_a; }
        else if(add_data_a==22)   {   Fault_reset_com=float_data_a; }
    }

    else if(SCI_WR_Mode == 3)
    {
        //Inverter setting
        if(add_data_a==0)         {   Kp_Vdc_con_input        = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==1)    {   Ki_Vdc_con_input        = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==2)    {   Kp_Idc_con_input        = (float_data_a   * 0.0001); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==3)    {   Ki_Idc_con_input        = (float_data_a   * 0.0001); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==4)    {   Kp_Vdc_con_ratio        = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==5)    {   Ki_Vdc_con_ratio        = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==6)    {   Kp_Idc_con_ratio        = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==7)    {   Ki_Idc_con_ratio        = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==8)    {   Wn_VC                   = (float_data_a   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==9)    {   Wc_CC                   = (float_data_a   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의

        else if(add_data_a==10)   {   Lc_input                = (float_data_a  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==11)   {   Cdc_input               = (float_data_a  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==12)   {   Vdc_ref_set_init        = (float_data_a  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==13)   {   Kp_Vdc_ratio            = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==14)   {   Ki_Vdc_inv_ratio        = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==15)   {   K_cc_ratio[0]           = (float_data_a  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==16)   {   K_cc_ratio[1]           = (float_data_a  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==17)   {   K_cc_ratio[2]           = (float_data_a  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==18)   {   Mode_system_input       = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==19)   {   SCI_WR_Mode             = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의

        else if(add_data_a==20)   {  if(Flag_gating == 0)  {   OP_MODE=float_data_a;    }    }
        else if(add_data_a==21)   {   Run_Stop_com=float_data_a; }
        else if(add_data_a==22)   {   Fault_reset_com=float_data_a; }
    }

    else if(SCI_WR_Mode == 4)
    {
        //Inverter setting
        if(add_data_a==0)         {   EPwm1_CMP_test          = (int)(float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==1)    {   EPwm2_CMP_test          = (int)(float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==2)    {   Ta_con_test1            = (int)(float_data_a   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==3)    {   Flag_gating_test        = (int)(float_data_a   * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==4)    {   VF_vtg_max              = (float_data_a   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
//        else if(add_data_a==4)    {   VF_vtg_max_no_Vdc       = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==5)    {   Flag_gating_VF_TEST     = (int)(float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==6)    {   OV_set_Vin_test         = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==7)    {   OC_Idc_set_test         = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==8)    {   OV_set_Vdc_test         = (float_data_a   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==9)    {   OC_set_test             = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의

        else if(add_data_a==10)   {   DO7_output              = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==11)   {   DO6_output              = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==12)   {   DO5_output              = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==13)   {   DO4_output              = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==14)   {   DO3_output              = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==15)   {   DO2_output              = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==16)   {   DO1_output              = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==17)   {   Mode_test               = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==18)   {   Mode_system_input       = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==19)   {   SCI_WR_Mode             = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의

        else if(add_data_a==20)   {  if(Flag_gating == 0)  {   OP_MODE=float_data_a;    }    }
        else if(add_data_a==21)   {   Run_Stop_com=float_data_a; }
        else if(add_data_a==22)   {   Fault_reset_com=float_data_a; }
    }

    else if(SCI_WR_Mode == 6)
    {
        //Inverter setting
        if(add_data_a==0)         {   Kp_Vde_ff               = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==1)    {   Kp_Vqe_ff               = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==2)    {   Kp_Ide_ff               = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==3)    {   Kp_Iqe_ff               = (float_data_a   * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==4)    {   Ide_ref_Cf              = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==5)    {   Iqe_ref_Cf              = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==6)    {   Ide_ref_Cf              = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==7)    {   Iqe_ref_Cf              = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==8)    {   Wn_VC                   = (float_data_a   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==9)    {   Wc_CC                   = (float_data_a   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의

        else if(add_data_a==10)   {   Lc_input                = (float_data_a  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==11)   {   Cdc_input               = (float_data_a  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==12)   {   Vdc_ref_set_init        = (float_data_a  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==13)   {   Kp_Vdc_ratio            = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==14)   {   Ki_Vdc_inv_ratio        = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==15)   {   K_cc_ratio[0]           = (float_data_a  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==16)   {   K_cc_ratio[1]           = (float_data_a  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==17)   {   K_cc_ratio[2]           = (float_data_a  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==18)   {   Mode_system_input       = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==19)   {   SCI_WR_Mode             = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의

        else if(add_data_a==20)   {  if(Flag_gating == 0)  {   OP_MODE=float_data_a;    }    }
        else if(add_data_a==21)   {   Run_Stop_com=float_data_a; }
        else if(add_data_a==22)   {   Fault_reset_com=float_data_a; }
    }

    else if(SCI_WR_Mode == 7)
    {
        //Inverter setting
        if(add_data_a==0)         {   T_dead_input            = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==1)    {   T_dead_con_input        = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==2)    {   T_dead_comp_input       = (float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==3)    {   mode_Va_PLL3            = (int)(float_data_a   * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==4)    {   time_check_cnt          = (int)(float_data_a   * 0.01); }  //CNT_max   eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==5)    {   Flag_Grid_err           = (int)(float_data_a   * 0.01); }  //CNT_max_con   eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==6)    {   EPwm1_CMP_test          = (int)(float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==7)    {   EPwm2_CMP_test          = (int)(float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==8)    {   flag_Iqe_ref_flt        = (int)(float_data_a   * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==9)    {   Kp_Idc_ref_Cf           = (float_data_a   * 0.0001); }  //eeprom setting    사용자 테스트 주소 정의

        else if(add_data_a==10)   {   FL_Vin               = (float_data_a  * 1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==11)   {   FL_Idc               = (float_data_a  * 1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==12)   {   FL_A_ref             = (float_data_a  * 1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==13)   {   FL_Vdc               = (float_data_a  * 1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==14)   {   FL_Va                = (float_data_a  * 1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==15)   {   FL_Ia                = (float_data_a  * 1); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==16)   {   flag_control_parameter       = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==17)   {   Idc_ref_comp_input   = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==18)   {   SCI_WR_setting       = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
        else if(add_data_a==19)   {   SCI_WR_Mode          = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의

        else if(add_data_a==20)   {  if(Flag_gating == 0)  {   OP_MODE=float_data_a;    }    }
        else if(add_data_a==21)   {   Run_Stop_com=float_data_a; }
        else if(add_data_a==22)   {   Fault_reset_com=float_data_a; }
    }

    else if(SCI_WR_Mode == 8)
     {
         //Inverter setting
         if(add_data_a==0)         {   Wn_VC               = (float_data_a   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==1)    {   Kp_Vdc_ratio        = (float_data_a   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==2)    {   Ki_Vdc_inv_ratio    = (float_data_a   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==3)    {   Wc_CC               = (float_data_a   * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==4)    {   K_cc_ratio[0]       = (float_data_a   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==5)    {   K_cc_ratio[1]       = (float_data_a   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==6)    {   K_cc_ratio[2]       = (float_data_a   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==7)    {   K_cc_ratio[3]       = (float_data_a   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==8)    {   K_cc_ratio[4]       = (float_data_a   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==9)    {   K_cc_ratio[5]       = (float_data_a   * 0.1); }  //eeprom setting    사용자 테스트 주소 정의

         else if(add_data_a==10)   {   Kp_Ia_ratio          = (float_data_a  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==11)   {   Ki_Ia_ratio          = (float_data_a  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==12)   {   Kp_Ia_ratio_D        = (float_data_a  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==13)   {   Ki_Ia_ratio_D        = (float_data_a  * 0.1); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==14)   {   voltage_control_inv3_cnt_max     = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==15)   {   Flag_over_check        = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==16)   {   flag_control_parameter = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==17)   {   Idc_ref_comp_input     = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==18)   {   SCI_WR_setting         = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==19)   {   SCI_WR_Mode            = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의

         else if(add_data_a==20)   {  if(Flag_gating == 0)  {   OP_MODE=float_data_a;    }    }
         else if(add_data_a==21)   {   Run_Stop_com=float_data_a; }
         else if(add_data_a==22)   {   Fault_reset_com=float_data_a; }
     }


    else if(SCI_WR_Mode == 9)
     {
         //Inverter setting
         if(add_data_a==0)         {   FL_Vin                 = (float_data_a  * 1);}  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==1)    {   FL_Idc                 = (float_data_a  * 1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==2)    {   FL_A_ref               = (float_data_a  * 1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==3)    {   FL_Vdc                 = (float_data_a  * 1); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==4)    {   FL_Va                  = (float_data_a  * 1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==5)    {   FL_Ia                  = (float_data_a  * 1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==6)    {   FL_s_volt              = (float_data_a  * 1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==7)    {   FL_e_volt              = (float_data_a  * 1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==8)    {   Fc_I_5th               = (float_data_a  * 1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==9)    {   Ia_PLL3_harmonic_k     = (float_data_a  * 0.01); }  //eeprom setting    사용자 테스트 주소 정의

         else if(add_data_a==10)   {   mode_Va_PLL3           = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==11)   {   Flag_Ia_PLL3           = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==12)   {   Flag_current_control_inv3           = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==13)   {   Flag_Va_PLL3           = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==14)   {   voltage_control_inv3_cnt_max     = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==15)   {   Flag_over_check        = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==16)   {   flag_control_parameter = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==17)   {   Idc_ref_comp_input     = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==18)   {   SCI_WR_setting         = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==19)   {   SCI_WR_Mode            = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의

         else if(add_data_a==20)   {  if(Flag_gating == 0)  {   OP_MODE=float_data_a;    }    }
         else if(add_data_a==21)   {   Run_Stop_com=float_data_a; }
         else if(add_data_a==22)   {   Fault_reset_com=float_data_a; }
     }

    else if(SCI_WR_Mode == 10)
     {
         //Inverter setting
         if(add_data_a==0)         {   Flag_Ia_PLL3           = (int)(float_data_a  * 0.01);}  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==1)    {   Fc_I_5th               = (float_data_a  * 1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==2)    {   Ia_PLL3_harmonic_k1    = (float_data_a  * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==3)    {   Ia_PLL3_harmonic_k2    = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==4)    {   Ia_PLL3_harmonic_k3    = (float_data_a  * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==5)    {   Kp_CC_Grid_comp_5th    = (float_data_a  * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==6)    {   Ki_CC_Grid_comp_5th    = (float_data_a  * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==7)    {   Kp_5th_ref             = (float_data_a  * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==8)    {   Flag_scia_cpu1_cpu2    = (float_data_a  * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==9)    {   OP_MODE                = (int)(float_data_a  * 0.01); }  //eeprom setting    사용자 테스트 주소 정의

         else if(add_data_a==10)   {   mode_Va_PLL3           = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==11)   {   Flag_Ia_PLL3           = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==12)   {   Flag_current_control_inv3           = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==13)   {   Flag_Va_PLL3           = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==14)   {   voltage_control_inv3_cnt_max     = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==15)   {   Flag_over_check        = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==16)   {   flag_control_parameter = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==17)   {   Idc_ref_comp_input     = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==18)   {   SCI_WR_setting         = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==19)   {   SCI_WR_Mode            = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의

         else if(add_data_a==20)   {  if(Flag_gating == 0)  {   OP_MODE=float_data_a;    }    }
         else if(add_data_a==21)   {   Run_Stop_com=float_data_a; }
         else if(add_data_a==22)   {   Fault_reset_com=float_data_a; }
     }

    else if(SCI_WR_Mode == 11)
     {
         //Inverter setting
         if(add_data_a==0)         {   Flag_Act_islanding_input           = (int)(float_data_a  * 0.01);}  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==1)    {   Freq_high                  = (float_data_a  * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==2)    {   Freq_low                   = (float_data_a  * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==3)    {   Ia_PLL3_harmonic_k2    = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==4)    {   Ia_PLL3_harmonic_k3    = (float_data_a  * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==5)    {   Kp_CC_Grid_comp_5th    = (float_data_a  * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==6)    {   Ki_CC_Grid_comp_5th    = (float_data_a  * 0.1); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==7)    {   Kp_5th_ref             = (float_data_a  * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==8)    {   Flag_scia_cpu1_cpu2    = (float_data_a  * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==9)    {   OP_MODE                = (int)(float_data_a  * 0.01); }  //eeprom setting    사용자 테스트 주소 정의

         else if(add_data_a==10)   {   mode_Va_PLL3           = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==11)   {   Flag_Ia_PLL3           = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==12)   {   Flag_current_control_inv3           = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==13)   {   Flag_Va_PLL3           = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==14)   {   voltage_control_inv3_cnt_max     = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==15)   {   Flag_over_check        = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==16)   {   flag_control_parameter = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==17)   {   Idc_ref_comp_input     = (float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==18)   {   SCI_WR_setting         = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
         else if(add_data_a==19)   {   SCI_WR_Mode            = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의

         else if(add_data_a==20)   {  if(Flag_gating == 0)  {   OP_MODE=float_data_a;    }    }
         else if(add_data_a==21)   {   Run_Stop_com=float_data_a; }
         else if(add_data_a==22)   {   Fault_reset_com=float_data_a; }
     }

    else
    {
        if(add_data_a==19)   {   SCI_WR_Mode             = (int)(float_data_a  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
    }
#endif


#if 0
    if(add_data==0xff)      {   Enable_EEPROM_write=all_data;   }
    else if(add_data==0xfe) {   Init_offset=all_data;   }
    else if(add_data==0xfd) {   Init_scale=all_data;    }
//  else if(add_data==0xf1) {   Flag_RTC_init=all_data; }  //RTC initial
//  else if(add_data==0xf3) {   Set_year=all_data;      }  //RTC year
//  else if(add_data==0xf4) {   Set_mon_day=all_data;   }  //RTC mon_day
//  else if(add_data==0xf5) {   Set_hour_min=all_data;  }  //RTC hour_min
#endif

#if 0
    if(add_data==0xff)      {   Enable_EEPROM_write=all_data;   }
    else if(add_data==0xfe) {   Init_offset=all_data;   }
    else if(add_data==0xfd) {   Init_scale=all_data;    }

    else if(add_data==0)    {   Scale_Vin_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==1)    {   Scale_Idc_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==2)    {   Scale_A_ref_ratio = float_data* 0.01; } //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==3)    {   Scale_Vdc_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==4)    {   Scale_Esa_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==5)    {   Scale_Ia_ratio = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==6)    {   Kp_Vdc_con_ratio = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==7)    {   Ki_Vdc_con_ratio = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==8)    {   Kp_Idc_con_ratio = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==9)    {   Ki_Idc_con_ratio = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의

    else if(add_data==10)   {   Vin_offset_input = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==11)   {   Idc_offset_input = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==12)   {   A_ref_offset_input = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==13)   {   Vdc_offset_input = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==14)   {   Scale_Esb_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==15)   {   Scale_Ic_ratio = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==16)   {   Kp_Vdc_ratio = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==17)   {   Ki_Vdc_inv_ratio = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==18)   {   Kp_Ia_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==19)   {   Ki_Ia_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의

    else if(add_data==20)   {   Ia_offset_comp = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==21)   {   Ic_offset_comp = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
#endif

#if 0
    else if(add_data==0)    {   Scale_Vin_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==1)    {   Scale_Idc_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==2)    {   Scale_A_ref_ratio = float_data* 0.01; } //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==3)    {   Scale_Vdc_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==4)    {   Scale_Esa_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==5)    {   Scale_Ia_ratio = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==6)    {   Kp_Vdc_con_ratio = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==7)    {   Ki_Vdc_con_ratio = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==8)    {   Kp_Idc_con_ratio = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==9)    {   Ki_Idc_con_ratio = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의

    else if(add_data==10)   {   Vin_offset_input = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==11)   {   Idc_offset_input = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
//  else if(add_data==12)   {   A_ref_offset_input = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
//  else if(add_data==12)   {   Ide_ref_Cf = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
//    else if(add_data==12)   {   time_check_cnt = (int)(float_data* 0.01); } //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==13)   {   Vdc_offset_input = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==14)   {   Scale_Esb_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==15)   {   Scale_Ic_ratio = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==16)   {   Wn_VC = float_data* 0.1; }  //eeprom setting    사용자 테스트 주소 정의

//  else if(add_data==16)   {   Kp_Vdc_ratio = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
//  else if(add_data==16)   {   Wn_VC = float_data* 0.01; } //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==17)   {   Wc_CC = float_data* 0.1; }  //eeprom setting    사용자 테스트 주소 정의
//  else if(add_data==17)   {   Wc_CC = float_data* 0.01; } //eeprom setting    사용자 테스트 주소 정의
//  else if(add_data==17)   {   Ki_Vdc_inv_ratio = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==18)   {   Kp_Ia_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==19)   {   Ki_Ia_ratio = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의

    else if(add_data==20)   {   Ia_offset_comp = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==21)   {   Ic_offset_comp = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
#endif

    // 2.   Mode_system_input       = 0         -> 1
    // 3.   Mode_test               = 0         -> no action
    // 4.   Flag_pwm_inv_test2      = 0         -> 1
    // 5.   Ta_inv_test2            = 0         -> 1
    // 6.   Tb_inv_test2            = 0         -> 1
    // 7.   Tc_inv_test2            = 0         -> 1

#if 0
    //phase shift test
    else if(add_data==0)    {   Mode_system_input   = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==1)    {   Mode_test           = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==2)    {   DO1_output          = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==3)    {   Vdc_ref_con_set     = float_data* 0.1; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==4)    {   Idc_ref_comp        = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==5)    {   Idc_limit_con       = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==6)    {   Flag_gating_test    = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==7)    {   OV_set_Vin_test     = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==8)    {   OC_Idc_set_test     = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==9)    {   OV_set_Vdc_test     = float_data* 0.1; }  //eeprom setting    사용자 테스트 주소 정의

    else if(add_data==10)   {   Mode_system_input   = (int)(float_data * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==11)   {   Mode_test           = (int)(float_data * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==12)   {   DO2_output          = (int)(float_data * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==13)   {   VF_vtg_max          = float_data* 0.1; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==14)   {   Flag_gating_VF_TEST = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==15)   {   OC_set_test         = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==16)   {   DO3_output          = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
//    else if(add_data==17)   {   DO4_output          = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
//    else if(add_data==18)   {   DO5_output          = float_data* 0.01; }   //eeprom setting    사용자 테스트 주소 정의

    else if(add_data==17)   {   EPwm1_CMP_test          = (int)(float_data* 0.01); }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==18)   {   EPwm2_CMP_test          = (int)(float_data* 0.01); }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==19)   {   Ta_con_test1        = float_data* 0.1; }   //eeprom setting    사용자 테스트 주소 정의

    else if(add_data==20)   {   Ia_offset_comp      = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==21)   {   Ic_offset_comp      = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
#endif


#if 0
    //one pwm pulse test
    else if(add_data==0)    {   Mode_system_input   = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==1)    {   Mode_test           = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==2)    {   DO1_output          = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==3)    {   Flag_gating_test    = (int)(float_data  * 0.01); }   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==4)    {   Ta_con_test1        = (int)(float_data  * 0.1);}   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==5)    {   Ta_con_test1        = (int)(float_data  * 0.1);}    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==6)    {   Tb_con_test1        = (int)(float_data  * 0.1);}  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==7)    {   Tb_con_test1        = (int)(float_data  * 0.1);}  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==8)    {   Tc_con_test1        = (int)(float_data  * 0.1);}  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==9)    {   Tc_con_test1        = (int)(float_data  * 0.1);}  //eeprom setting    사용자 테스트 주소 정의

    else if(add_data==10)   {   Mode_system_input   = (int)(float_data * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==11)   {   Mode_test           = (int)(float_data * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==12)   {   DO2_output          = (int)(float_data * 0.01); }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==13)   {   Flag_gating_test_cnt_max          = float_data* 0.01; }  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==14)   {   Flag_pwm_1P         = (int)(float_data  * 0.01);}   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==15)   {   Flag_pwm_1N         = (int)(float_data  * 0.01);}    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==16)   {   Flag_pwm_2P         = (int)(float_data  * 0.01);}  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==17)   {   Flag_pwm_2N         = (int)(float_data  * 0.01);}  //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==18)   {   Flag_pwm_3P         = (int)(float_data  * 0.01);}   //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==19)   {   Flag_pwm_3N         = (int)(float_data  * 0.01);}   //eeprom setting    사용자 테스트 주소 정의

    else if(add_data==20)   {   Ia_offset_comp      = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
    else if(add_data==21)   {   Ic_offset_comp      = float_data* 0.01; }    //eeprom setting    사용자 테스트 주소 정의
#endif


#if 0
    else
    {   // 0x00~0xFC(0~252)
        temp    = data_ptr[INIT_EEPROM_CODE + add_data];
        *temp   = float_data * 0.01;
    }
#endif

    MODBUS_transmitt_buffer_a[0]  = 'W';   // 'W'
    MODBUS_transmitt_buffer_a[1]  = 'R';   // 'R'
    MODBUS_transmitt_buffer_a[2]  = 0x20;  // Space
    MODBUS_transmitt_buffer_a[3]  = MODBUS_receive_buffer_a[3];  // '3'
    MODBUS_transmitt_buffer_a[4]  = MODBUS_receive_buffer_a[4];  // '0'
    MODBUS_transmitt_buffer_a[5]  = 0x20;  // Space
    MODBUS_transmitt_buffer_a[6]  = MODBUS_receive_buffer_a[6];  // data4
    MODBUS_transmitt_buffer_a[7]  = MODBUS_receive_buffer_a[7];  // data3
    MODBUS_transmitt_buffer_a[8]  = MODBUS_receive_buffer_a[8];  // data2
    MODBUS_transmitt_buffer_a[9]  = MODBUS_receive_buffer_a[9];  // data1
    MODBUS_transmitt_buffer_a[10] = 0x0d;  // CR
    MODBUS_transmitt_buffer_a[11] = 'H';   // 'H'
    MODBUS_transmitt_buffer_a[12] = ':';   // ':'

    transmitt_flag_a  = 1;
    transmitt_data_length_a = 13;
}


void function_WR_SanRex2_a()
{
    char recv_buffer_a[6]={0x00,0x00,0x00,0x00,0x00,0x00};
    unsigned int add_data_a, all_data_a, low_data_a, high_data_a;
    int int_data_a;
    float float_data_a;
#if 0
    long temp_data_a;
    float   *temp_a;
    unsigned int    chk_sum_a, chk_sum_send_buffer_a, chk_sum_high_a, chk_sum_low_a;
#endif

    unsigned int    chk_sum_a, chk_sum_send_buffer_a;

    recv_buffer_a[0] = asc2hex(MODBUS_receive_buffer_a[4]);
    recv_buffer_a[1] = asc2hex(MODBUS_receive_buffer_a[5]);
    recv_buffer_a[2] = asc2hex(MODBUS_receive_buffer_a[6]);
    recv_buffer_a[3] = asc2hex(MODBUS_receive_buffer_a[7]);
    recv_buffer_a[4] = asc2hex(MODBUS_receive_buffer_a[8]);
    recv_buffer_a[5] = asc2hex(MODBUS_receive_buffer_a[9]);

    chk_sum_a =   MODBUS_receive_buffer_a[0]+MODBUS_receive_buffer_a[1]+MODBUS_receive_buffer_a[2]+
                MODBUS_receive_buffer_a[3]+MODBUS_receive_buffer_a[4]+MODBUS_receive_buffer_a[5]+
                MODBUS_receive_buffer_a[6]+MODBUS_receive_buffer_a[7]+MODBUS_receive_buffer_a[8]+
                MODBUS_receive_buffer_a[9]+MODBUS_receive_buffer_a[10];

    if(((MODBUS_receive_buffer_a[12]==((chk_sum_a>>8)&0xff)))&&(MODBUS_receive_buffer_a[11]==(chk_sum_a&0xff)))
    {
        add_data_a = (((recv_buffer_a[0]&0xff) << 4) | recv_buffer_a[1]&0xff);
        high_data_a = (((recv_buffer_a[2]&0xff) << 4) | recv_buffer_a[3]&0xff);
        low_data_a = (((recv_buffer_a[4]&0xff) << 4) | recv_buffer_a[5]&0xff);
        all_data_a = ((high_data_a << 8) | low_data_a);

        int_data_a = (int)all_data_a;
        float_data_a = (float)int_data_a;

        add_data_lsc_a    = add_data_a;
        all_data_lsc_a    = all_data_a;
        float_data_lsc_a  = (float)int_data_a;

        if(add_data_a==0x19)          {   Fault_reset_com=float_data_a;   }
        else if(add_data_a==0x20)     {   Idc_ref_comp_input           = (float_data_a  * 0.01);        }
        else if(add_data_a==0x22)     {   if(Flag_gating == 0) {OP_MODE=float_data_a;           }       }
        else if(add_data_a==0x23)     {   Run_Stop_com=float_data_a; }  //RTC initial
    }

    MODBUS_transmitt_buffer_a[0] = 'M';   // 'M'
    MODBUS_transmitt_buffer_a[1] = 'N';   // 'N'
    MODBUS_transmitt_buffer_a[2] = 0x20;  // Space
    MODBUS_transmitt_buffer_a[3] = 'W';   // '3'
    MODBUS_transmitt_buffer_a[4] = MODBUS_receive_buffer_a[4];  // '0'
    MODBUS_transmitt_buffer_a[5] = MODBUS_receive_buffer_a[5];  // Space
    MODBUS_transmitt_buffer_a[6] = 0x0d;;                     // CR
    MODBUS_transmitt_buffer_a[7] = 'H';                       // 'H'
    MODBUS_transmitt_buffer_a[8] = ':';                       // ':'
    chk_sum_send_buffer_a = MODBUS_transmitt_buffer_a[0]+MODBUS_transmitt_buffer_a[1]+MODBUS_transmitt_buffer_a[2]+
                          MODBUS_transmitt_buffer_a[3]+MODBUS_transmitt_buffer_a[4]+MODBUS_transmitt_buffer_a[5]+
                          MODBUS_transmitt_buffer_a[6]+MODBUS_transmitt_buffer_a[7]+MODBUS_transmitt_buffer_a[8];

    MODBUS_transmitt_buffer_a[9] = (chk_sum_send_buffer_a&0xff);                // check sum low
    MODBUS_transmitt_buffer_a[10] = (chk_sum_send_buffer_a>>8&0xff);            // check sum high

    transmitt_flag_a=1;
    transmitt_data_length_a = 11;
}


void function_WR_SanRex3_a()
{
///NEW

    char recv_buffer_a[6]={0x00,0x00,0x00,0x00,0x00,0x00};
    unsigned int add_data_a, all_data_a, low_data_a, high_data_a;
    int int_data_a;
    float float_data_a;
//    float   *temp;
    receiveC_a++;
    recv_buffer_a[0] = asc2hex(MODBUS_receive_buffer_a[4]); //ADDR LOW
    recv_buffer_a[1] = asc2hex(MODBUS_receive_buffer_a[5]); //ADDR HIGH

    recv_buffer_a[2] = asc2hex(MODBUS_receive_buffer_a[6]); //ADDR 1
    recv_buffer_a[3] = asc2hex(MODBUS_receive_buffer_a[7]); //ADDR 2
    recv_buffer_a[4] = asc2hex(MODBUS_receive_buffer_a[8]); //ADDR 3
    recv_buffer_a[5] = asc2hex(MODBUS_receive_buffer_a[9]); //ADDR 4

    add_data_a = (((recv_buffer_a[0]&0xff) << 4) | recv_buffer_a[1]&0xff);

    high_data_a = (((recv_buffer_a[2]&0xff) << 4) | recv_buffer_a[3]&0xff);
    low_data_a = (((recv_buffer_a[4]&0xff) << 4) | recv_buffer_a[5]&0xff);

    all_data_a = ((high_data_a << 8) | low_data_a);

    int_data_a = (int)all_data_a;
    float_data_a = (float)int_data_a;

    add_data_lsc_a    = add_data_a;
    all_data_lsc_a    = all_data_a;
    float_data_lsc_a  = (float)int_data_a;

//    if(add_data_a==0x19)      {   Write_Buffer_a[0]=all_data_a;   } //Fault Reset
//    else if(add_data_a==0x20) {   Write_Buffer_a[1]=all_data_a;   } //Ref
//    else if(add_data_a==0x21) {   Write_Buffer_a[2]=all_data_a;   } // Reserved
//    else if(add_data_a==0x22) {   Write_Buffer_a[3]=all_data_a;   } //Operation Mode
//    else if(add_data_a==0x23) {   Write_Buffer_a[4]=all_data_a;   } //RUN/STOP


//    if(add_data_a==0x19)      {   Fault_reset_com     = all_data_a;         }
//    else if(add_data_a==0x20) {   Idc_ref_comp        = all_data_a * 0.01;  }
//    else if(add_data_a==0x22) {   OP_MODE             = all_data_a;         }
//    else if(add_data_a==0x23) {   Comm_Run_Stop       = all_data_a;         }  //RTC initial

    if(add_data_a==0x19)          {   Fault_reset_com=float_data_a;   }
    else if(add_data_a==0x20)     {   Idc_ref_comp_input           = (float_data_a  * 0.01);        }
    else if(add_data_a==0x22)     {   if(Flag_gating == 0) {OP_MODE=float_data_a;           }       }
    else if(add_data_a==0x23)     {   Run_Stop_com=float_data_a; }  //RTC initial

    MODBUS_transmitt_buffer_a[0]  = 'M';   // 'W'
    MODBUS_transmitt_buffer_a[1]  = 'N';   // 'R'
    MODBUS_transmitt_buffer_a[2]  = 0x20;  // Space
    MODBUS_transmitt_buffer_a[3]  = 'W';
    MODBUS_transmitt_buffer_a[4]  = MODBUS_receive_buffer_a[4];  // '3'
    MODBUS_transmitt_buffer_a[5]  = MODBUS_receive_buffer_a[5];  // '0'
    MODBUS_transmitt_buffer_a[6] = 0x0d;  // CR
    MODBUS_transmitt_buffer_a[7] = 'H';   // 'H'
    MODBUS_transmitt_buffer_a[8] = ':';   // ':'


    transmitt_data_length_a = 11;
    (CRC16_a(transmitt_data_length_a-2,2));

    CRC16_check1_test_a        = CRC16_a(transmitt_data_length_a-2,2);

    transmitt_flag_a  = 1;
}

/*--------------------------------------*/
/*  call scia_com_init()                */
/*--------------------------------------*/
void scia_com_init()
{
    // SCI-A 초기화 함수
    scia_com_init_count++;
//  if(scia_com_init_count >=10){       //10s
    if(scia_com_init_count >=30){       //30s
        scia_com_init_count=0;
        if(Flag_modbus_response_count_a >= 1){
            Flag_modbus_response_count_a = 0;
        }
        else{            // KSC
            Flag_modbus_response_count_a = 0;
            Flag_modbus_response_count_test_a++;
            Init_Scia();         // RS485 MMI Communication Init Func.
            //Fault_SW|=SFT_SCI_Comm;
        }
    }
    else{}
}

/*--------------------------------------*/
/*  call scia_com_setting()                */
/*--------------------------------------*/
void scia_com_setting()
{
    EALLOW;
    if(Flag_scia_cpu1_cpu2 == CPU1_MODE)
    {
        DevCfgRegs.CPUSEL5.bit.SCI_A = 0;
        if(Flag_scia == 1)
        {
          Init_Scia();      //black box define -> add check need
          Flag_scia = 2;

        }
        scia_com_init();

    }
    else if(Flag_scia_cpu1_cpu2 == CPU2_MODE)
    {
        if(Flag_scia == 2)
        {
          Init_Scia_BB();      //black box define -> add check need
          Flag_scia = 1;
          DevCfgRegs.CPUSEL5.bit.SCI_A = 1;
        }
    }
    else
    {
      Flag_scia = 1;
      Flag_scia_cpu1_cpu2 = CPU1_MODE;
    }
    EDIS;
}

//---------------------------------------------------------------------------
char asc2hex(char asc)
{

    if((asc >= '0') && (asc <= '9'))    return (asc - '0');
    else if((asc >= 'A') && (asc <= 'F'))   return (asc - 'A' + 0x0a);
    else if((asc >= 'a') && (asc <= 'f'))    return (asc - 'a' + 0x0a);
    else return ASC_HEX_ERROR;
}
//---------------------------------------------------------------------------
char hex2asc(char hex)
{
    char da;
    da = hex & 0x0f;
    if((da >= 0) && (da <= 9))    return  ('0' + da);
    else    return  ('A' + da - 0x0a);
}


interrupt void scib_rx_isr(void)
{
    ScibRegs.SCIFFRX.bit.RXFFOVRCLR = 1; // Clear Overflow flag
    ScibRegs.SCIFFRX.bit.RXFFINTCLR = 1; // Clear Interrupt flag
    PieCtrlRegs.PIEACK.all |= 0x100; // Issue PIE ack
}


void function_3rd_response() //response for modbus 03 function (read registers)
{
}

void function_6th_response() //response for modbus 03 function (read registers)
{
}

void Bad_response() //response for modbus 03 function (read registers)
{
}

//////  CRC16 21.03.01 HSJ/////

int CRC16(int dataLength, int check)   //CRC 16 for modbus checksum
{

    unsigned int CheckSum;
    int i, j;
    int lowCRC, highCRC;
//      dataLength = transmitt_data_length;
        CheckSum = 0x0ffff;
//if (hyun_flag == 2){

//for (j=0; j<dataLength; j++)
        for (j=0; j < dataLength; j++)

    {
        if(check==1)        {   CheckSum = (CheckSum^(MODBUS_receive_buffer[j] & 0x0ff)) & 0x0000FFFF;}  //수신 Data CRC
        else if (check ==2){            CheckSum = (CheckSum^(MODBUS_transmitt_buffer[j] & 0x0ff)) & 0x0000FFFF;} //송신 DATA CRC

        for(i=8; i>0; i--)//CRC Caculation
        {
            if(CheckSum & 0x00000001)   CheckSum=(((CheckSum>>1) & 0x0ffff)^0x0000a001) & 0x0000FFFF;
            //if(CheckSum & 0x00000001)     CheckSum=(((CheckSum>>1) & 0x0ffff)^0x00008005) & 0x0000FFFF;
            else        CheckSum = (CheckSum>>1) & 0x0000FFFF;
        }
    }

//  hyun_data6 = CheckSum & 0xffff;
    highCRC = ((CheckSum>>8) & 0x000000FF); // High Data 결정
    CheckSum<<=8;   lowCRC = ((CheckSum>>8) & 0x000000FF);   //LOW Data 결정

    if (check==1)
    {
        low_CRC_Receive = lowCRC;
        high_CRC_Receive= highCRC;

        if ((MODBUS_receive_buffer[dataLength+1] == highCRC) & (MODBUS_receive_buffer[dataLength] == lowCRC ))      return 1;//  수신 DATA의 HIGH/LOW CRC

        else return 0;
    }
    else if (check ==2)
        {

    //  high_CRC_Send = lowCRC;
    //  low_CRC_Send= highCRC;

        low_CRC_Send = lowCRC;
        high_CRC_Send = highCRC;

              MODBUS_transmitt_buffer[dataLength] = lowCRC;                                                                 //송신 DATA의 HIGH/LOW
              MODBUS_transmitt_buffer[dataLength+1] = highCRC;         //-> transmitt_data_length -2의 는 CRC Data 자리 이다.
//      MODBUS_transmitt_buffer[5] = lowCRC;
//      MODBUS_transmitt_buffer[5+1] = highCRC;
        return 1;

        }
}


int CRC16_a(int dataLength_a, int check_a)   //CRC 16 for modbus checksum
{

    unsigned int CheckSum_a;
    int i_a, j_a;
    int lowCRC_a, highCRC_a;
//      dataLength = transmitt_data_length;
        CheckSum_a = 0x0ffff;
//if (hyun_flag == 2){

//for (j=0; j<dataLength; j++)
        for (j_a=0; j_a < dataLength_a; j_a++)

    {
        if(check_a==1)        {   CheckSum_a = (CheckSum_a^(MODBUS_receive_buffer_a[j_a] & 0x0ff)) & 0x0000FFFF;}  //수신 Data CRC
        else if (check_a ==2){            CheckSum_a = (CheckSum_a^(MODBUS_transmitt_buffer_a[j_a] & 0x0ff)) & 0x0000FFFF;} //송신 DATA CRC

        for(i_a=8; i_a>0; i_a--)//CRC Caculation
        {
            if(CheckSum_a & 0x00000001)   CheckSum_a=(((CheckSum_a>>1) & 0x0ffff)^0x0000a001) & 0x0000FFFF;
            //if(CheckSum_a & 0x00000001)     CheckSum_a=(((CheckSum_a>>1) & 0x0ffff)^0x00008005) & 0x0000FFFF;
            else        CheckSum_a = (CheckSum_a>>1) & 0x0000FFFF;
        }
    }

//  hyun_data6 = CheckSum & 0xffff;
    highCRC_a = ((CheckSum_a>>8) & 0x000000FF); // High Data 결정
    CheckSum_a<<=8;   lowCRC_a = ((CheckSum_a>>8) & 0x000000FF);   //LOW Data 결정

    if (check_a==1)
    {
        low_CRC_Receive_a = lowCRC_a;
        high_CRC_Receive_a= highCRC_a;

        if ((MODBUS_receive_buffer_a[dataLength_a+1] == highCRC_a) & (MODBUS_receive_buffer_a[dataLength_a] == lowCRC_a ))      return 1;//  수신 DATA의 HIGH/LOW CRC

        else return 0;
    }
    else if (check_a ==2)
        {

    //  high_CRC_Send_a = lowCRC_a;
    //  low_CRC_Send_a= highCRC_a;

        low_CRC_Send_a = lowCRC_a;
        high_CRC_Send_a = highCRC_a;

              MODBUS_transmitt_buffer_a[dataLength_a] = lowCRC_a;                                                                 //송신 DATA의 HIGH/LOW
              MODBUS_transmitt_buffer_a[dataLength_a+1] = highCRC_a;         //-> transmitt_data_length -2의 는 CRC Data 자리 이다.



//      MODBUS_transmitt_buffer_a[5] = lowCRC_a;
//      MODBUS_transmitt_buffer_a[5+1] = highCRC_a;
        return 1;

        }
}
