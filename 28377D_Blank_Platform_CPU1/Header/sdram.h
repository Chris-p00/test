/*
 * sdram.h
 *
 *  Created on: 2020. 8. 26.
 *      Author: KYJ-PC
 */

#ifndef SOURCE_SDRAM_H_
#define SOURCE_SDRAM_H_


extern void setup_emif1_pinmux_sdram_32bit(Uint16 cpu_sel);

//
// init_sdram
//
void Init_Sdram(void);

#endif /* SOURCE_SDRAM_H_ */
