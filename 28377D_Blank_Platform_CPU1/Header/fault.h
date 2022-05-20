/*
 * fault.h
 *
 *  Created on: 2021. 1. 4.
 *      Author: USER
 */

#ifndef HEADER_FAULT_H_
#define HEADER_FAULT_H_

//#pragma CODE_SECTION(fault_check_test,      ".TI.ramfunc");
//#pragma CODE_SECTION(fault_check,           ".TI.ramfunc");
//#pragma CODE_SECTION(inv_fault,             ".TI.ramfunc");
//#pragma CODE_SECTION(system_restart,        ".TI.ramfunc");

void fault_HW_check();
void fault_check_test();
void fault_check();
void Fault_check_100ms();
void check_overload();
void inv_fault();
void Fault_reset_100ms();
void system_restart();

#endif /* HEADER_FAULT_H_ */
