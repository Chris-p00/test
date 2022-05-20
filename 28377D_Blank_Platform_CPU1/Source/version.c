/*
 * version.c
 *
 *  Created on: 2021. 4. 7.
 *      Author: j.g.choe
 *
 *  Software Version Manager 2021. 4. 7, (c) G-Philos
 *
 */
#include <stdlib.h>
#include "version.h"

#define INDEX_SIGNITURE     (0)
#define INDEX_FIRMWARE_ID   (1)
#define INDEX_VERSION       (2)
#define INDEX_MODEL_ID      (3)
#define INDEX_CUSTOMER_ID   (4)
#define INDEX_CPU_ID        (5)
#define INDEX_BOARD_ID      (6)
#define INDEX_DATE_TIME_ID  (7)

const __attribute__((section(".version"))) char g_version[9][32] =
{
     "G-PHILOS",
     CORE_ID,
     FIRMWARE_ID,
     VERSION_MAJOR "." VERSION_MINOR,
     MODEL_ID,
     CUSTOMER_ID,
     CPU_ID,
     BOARD_ID,
     __DATE__ " " __TIME__,
};
