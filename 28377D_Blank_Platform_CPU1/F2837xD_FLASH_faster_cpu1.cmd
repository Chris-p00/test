MEMORY
{
PAGE 0:    /* Program Memory */
          /* Memory (RAM/FLASH) blocks can be moved to PAGE1 for data allocation */
          /* BEGIN is used for the "boot to Flash" bootloader mode   */

//   BEGIN           	: origin = 0x088000, length = 0x000002   // shin //원격 부트로드 모드를 진행하기 위한 설정
   BEGIN           	: origin = 0x088000, length = 0x000002   // 다운로드 설정을 위한 진행
   RAMM0           	: origin = 0x000122, length = 0x0006DE
// RAMM1           : origin = 0x000400,  length = 0x000400     /* on-chip RAM block M1 */
   RAMD0           	: origin = 0x00B000, length = 0x000800

   RESET           	: origin = 0x3FFFC0, length = 0x000002

   RAMGS0      		: origin = 0x00D000, length = 0x003000


	/* Flash sectors */
//   FLASHA           : origin = 0x080002, length = 0x001FFE	/* on-chip Flash */
//   FLASHB           : origin = 0x082000, length = 0x002000	/* on-chip Flash */
//   FLASHC           : origin = 0x084000, length = 0x002000	/* on-chip Flash */
//   FLASHD           : origin = 0x086000, length = 0x002000	/* on-chip Flash */
   FLASHE           : origin = 0x088008, length = 0x007FF8	/* on-chip Flash */
   FLASHF           : origin = 0x090000, length = 0x008000	/* on-chip Flash */
   FLASHG           : origin = 0x098000, length = 0x008000	/* on-chip Flash */
   FLASHH           : origin = 0x0A0000, length = 0x008000	/* on-chip Flash */
   FLASHI           : origin = 0x0A8000, length = 0x008000	/* on-chip Flash */
   FLASHJ           : origin = 0x0B0000, length = 0x008000	/* on-chip Flash */
   FLASHK           : origin = 0x0B8000, length = 0x002000	/* on-chip Flash */
   FLASHL           : origin = 0x0BA000, length = 0x002000	/* on-chip Flash */
   FLASHM           : origin = 0x0BC000, length = 0x002000	/* on-chip Flash */
   FLASHN           : origin = 0x0BE000, length = 0x002000	/* on-chip Flash */

PAGE 1 :   /* Data Memory */
           /* Memory (RAM/FLASH) blocks can be moved to PAGE0 for program allocation */

    BOOT_RSVD       : origin = 0x000002, length = 0x000120     /* Part of M0, BOOT rom will use this for stack */

    RAMD1           : origin = 0x00B800, length = 0x000800

    RAMLS0_5 	    : origin = 0x008000, length = 0x003000
//  RAMLS1          : origin = 0x008800, length = 0x000800
//  RAMLS2          : origin = 0x009000, length = 0x000800
//  RAMLS3          : origin = 0x009800, length = 0x000800
//	RAMLS4          : origin = 0x00A000, length = 0x000800
//  RAMLS5      	: origin = 0x00A800, length = 0x000800




//------- CPU2 => CPU1 : GS4------------------------------------------------------

	RAMGS4_INITBB  		: origin = 0x010000, length = 0x000100
	RAMGS4_INDEXNUM     : origin = 0x010100, length = 0x000100
	RAMGS4_WTIME     	: origin = 0x010200, length = 0x000100
	RAMGS4_DAC2			: origin = 0x010300, length = 0x000100
	RAMGS4_RMOT			: origin = 0x010400, length = 0x000100
	RAMGS4_EDIT_AD		: origin = 0x010500, length = 0x000100
   	RAMGS4_STRTFLG2		: origin = 0x010600, length = 0x000100
   	RAMGS4_LOG			: origin = 0x010700, length = 0x000100
//--------------------------------------------------------------------------------

//------- CPU2 <= CPU1 : GS5 ~ ---------------------------------------------------
    RAMGS6_7_INDEX    	: origin = 0x012000, length = 0x001500
    RAMGS7_DATABB       : origin = 0x013500, length = 0x000200
	RAMGS7_RTIME		: origin = 0x013700, length = 0x000100
	RAMGS7_DAC			: origin = 0x013800, length = 0x000100
	RAMGS7_DAC2			: origin = 0x013900, length = 0x000100
	RAMGS7_INDEXSIZE	: origin = 0x013A00, length = 0x000200
	RAMGS7_EDIT_AD		: origin = 0x013C00, length = 0x000100
	RAMGS7_VERSION		: origin = 0x013D00, length = 0x000200
	RAMGS7_STRTFLG1		: origin = 0x013F00, length = 0x000100
	RAMGS8_UID			: origin = 0x014000, length = 0x0000F0
	RAMGS8_DEVID		: origin = 0x0140F0, length = 0x0000F0
//--------------------------------------------------------------------------------


   RAMGS0_ebss      : origin = 0x00C000, length = 0x001000
//   RAMGS1      : origin = 0x00D000, length = 0x001000
//   RAMGS2      : origin = 0x00E000, length = 0x001000
//   RAMGS3      : origin = 0x00F000, length = 0x001000

   RAMGS9      : origin = 0x015000, length = 0x001000
   RAMGS10     : origin = 0x016000, length = 0x001000
   RAMGS11     : origin = 0x017000, length = 0x001000
   RAMGS12     : origin = 0x018000, length = 0x001000     /* Only Available on F28379D, F28377D, F28375D devices. Remove line on other devices. */
// RAMGS13     : origin = 0x019000, length = 0x001000     /* Only Available on F28379D, F28377D, F28375D devices. Remove line on other devices. */


    EMIF1_CS0n      : origin = 0x80000000, length = 0x10000000
    EMIF1_CS2n      : origin = 0x00100000, length = 0x00200000
    EMIF1_CS3n      : origin = 0x00300000, length = 0x00080000
    EMIF1_CS4n      : origin = 0x00380000, length = 0x00060000
    EMIF2_CS0n      : origin = 0x90000000, length = 0x10000000
    EMIF2_CS2n      : origin = 0x00002000, length = 0x00001000



    CPU2TOCPU1RAM   : origin = 0x03F800, length = 0x000400
    CPU1TOCPU2RAM   : origin = 0x03FC00, length = 0x000400
}

SECTIONS
{
   /* Allocate program areas: */
   .cinit          : > FLASHE,      				PAGE = 0,   ALIGN(8)
   .text           : >> FLASHF | FLASHG | FLASHH    PAGE = 0,   ALIGN(8)
   .econst         : > FLASHI       				PAGE = 0,   ALIGN(8)
   codestart       : > BEGIN	    				PAGE = 0,   ALIGN(8)

   /* Allocate uninitalized data sections: */
   .stack          : > RAMD1     					PAGE = 1
   .ebss           : >> RAMLS0_5 | RAMGS0_ebss 		PAGE = 1
   .esysmem        : > RAMD1       					PAGE = 1


   /* Initalized sections go in Flash */
   .pinit          : > FLASHN,      		  		PAGE = 0,   ALIGN(8)
   .switch         : > FLASHN                 		PAGE = 0,   ALIGN(8)

   .reset          : > RESET,        	  			PAGE = 0, TYPE = DSECT /* not used, */

   .farbss         : > EMIF1_CS0n,     	  			PAGE = 1
   .farconst       : > EMIF1_CS0n,      	  		PAGE = 1

   .version        : > FLASHI,      	      		PAGE = 0,   ALIGN(8)

//------- CPU2 => CPU1 : GS4------------------------------------------------------
   RAMGS4_INDEXNUM  : > RAMGS4_INDEXNUM,        PAGE = 1
   RAMGS4_INITBB    : > RAMGS4_INITBB,          PAGE = 1
   RAMGS4_WTIME     : > RAMGS4_WTIME,           PAGE = 1
   RAMGS4_WTIME     : > RAMGS4_WTIME,           PAGE = 1
   RAMGS4_DAC2      : > RAMGS4_DAC2,            PAGE = 1
   RAMGS4_RMOT      : > RAMGS4_RMOT,            PAGE = 1
   RAMGS4_EDIT_AD	: > RAMGS4_EDIT_AD,       	PAGE = 1
   RAMGS4_STRTFLG2	: > RAMGS4_STRTFLG2,       	PAGE = 1
   RAMGS4_LOG       : > RAMGS4_LOG				PAGE = 1
//--------------------------------------------------------------------------------

//------- CPU2 <= CPU1 : GS5 ~ ---------------------------------------------------
   RAMGS6_7_INDEX  	: > RAMGS6_7_INDEX,			PAGE = 1
   RAMGS7_DATABB    : > RAMGS7_DATABB,      	PAGE = 1
   RAMGS7_RTIME     : > RAMGS7_RTIME, 			PAGE = 1
   RAMGS7_DAC       : > RAMGS7_DAC,				PAGE = 1
   RAMGS7_DAC2      : > RAMGS7_DAC2,			PAGE = 1
   RAMGS7_INDEXSIZE : > RAMGS7_INDEXSIZE,		PAGE = 1
   RAMGS7_EDIT_AD	: > RAMGS7_EDIT_AD,			PAGE = 1
   RAMGS7_VERSION   : > RAMGS7_VERSION, 		PAGE = 1
   RAMGS7_STRTFLG1	: > RAMGS7_STRTFLG1,       	PAGE = 1
   RAMGS8_UID		: > RAMGS8_UID,       		PAGE = 1
   RAMGS8_DEVID		: > RAMGS8_DEVID,       	PAGE = 1
//--------------------------------------------------------------------------------


#ifdef __TI_COMPILER_VERSION__
    #if __TI_COMPILER_VERSION__ >= 15009000
        GROUP
        {
            .TI.ramfunc
            {}

        }LOAD = FLASHN,
         RUN  = RAMGS0,
          LOAD_START(_RamfuncsLoadStart),
          LOAD_SIZE(_RamfuncsLoadSize),
          LOAD_END(_RamfuncsLoadEnd),
          RUN_START(_RamfuncsRunStart),
          RUN_SIZE(_RamfuncsRunSize),
          RUN_END(_RamfuncsRunEnd),
          PAGE = 0
    #else
        GROUP
        {
            ramfuncs {}

        } LOAD = FLASHN,
          RUN  = RAMD0,
          LOAD_START(_RamfuncsLoadStart),
          LOAD_SIZE(_RamfuncsLoadSize),
          LOAD_END(_RamfuncsLoadEnd),
          RUN_START(_RamfuncsRunStart),
          RUN_SIZE(_RamfuncsRunSize),
          RUN_END(_RamfuncsRunEnd),
          PAGE = 0
    #endif
#endif

   /* The following section definitions are required when using the IPC API Drivers */
    GROUP : > CPU1TOCPU2RAM, PAGE = 1
    {
        PUTBUFFER
        PUTWRITEIDX
        GETREADIDX
    }

    GROUP : > CPU2TOCPU1RAM, PAGE = 1
    {
        GETBUFFER :    TYPE = DSECT
        GETWRITEIDX :  TYPE = DSECT
        PUTREADIDX :   TYPE = DSECT
    }



}

/*
//===========================================================================
// End of file.
//===========================================================================
*/
