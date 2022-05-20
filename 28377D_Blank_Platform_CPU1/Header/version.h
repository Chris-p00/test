/*
 * version.h
 *
 *  Created on: 2021. 4. 7.
 *      Author: j.g.choe
 *
 *  Software Version Manager 2021. 4. 7, (c) G-Philos
 *
 */
#ifndef __VERSION_H
#define __VERSION_H

#define VERSION_MAJOR       "1"
#define VERSION_MINOR       "1"

#define _CPU1 "C1"
#define _CPU2 "C2"

#define CORE_ID _CPU1

/*
 * Model ID
 *
 * 1KW   (1570)     28335
 * 1KW   (2545)     28335
 * 2.5KW (6741)     28335
 * 5KW   (42130)    28335
 * 6.5KW (11063)    28377D
 * 10KW  (67165)    28335
 */

#define __MODEL_ID_1570       "1570"
#define __MODEL_ID_2545       "2545"
#define __MODEL_ID_6741       "6741"
#define __MODEL_ID_42130      "42130"
#define __MODEL_ID_11063      "11063"
#define __MODEL_ID_67165      "67165"

#define MODEL_ID    __MODEL_ID_11063

/*
 * Customer ID
 * Reference: "4. ���ڵ� ver.2.0 20201019.xlsx"
 *
 * Abbreviation     English Name            Korean Name
 * DF               DooSan Fuel Cell        (��)�λ� ǻ��
 * AL               Acro LABS               ��ũ�η��� �ֽ�ȸ��
 * BH               BumHan                  ���ѻ����
 * HP               H&Power                 H&Power
 * HS               Hyundai Steel           ������ö
 * KD               Kyung Dong Navien       �߰浿����
 * LC               LG Chem                 LGȭ��
 * MC               MICO                    (��)����
 * PP               P&P ENG                 P&P ENG
 * PR               Pureun                  Ǫ�����������
 * SF               S-Fuel Cell             ����ǻ��(��)
 * ST               STX Heavy Industries    STX�߰���
 * KE               Korea Institute         �ѱ����������������
 *                  of energy Research
 * KC               K Ceracell              ���̼���
 * US               UPSTART                 UPSTART
 * HG               Hydro Genics            ���̵�� ���н�
 * DA               Dong-A Fuel cell        ����ǻ��
 * EA               Energy                  �������� ����
 *                  Air Conditioning
 * CE               Cotek Energy            ���ؿ�����
 *
 */

#define CUSTOMER_ID     "BH"

/*
 * Firmware ID
 *
 * CONTROLLER
 * BOOTLOADER
 * BLACKBOX
 */

#define FIRMWARE_ID_CONTROLLER      "CONTROLLER"
#define FIRMWARE_ID_BOOTLOADER      "BOOTLOADER"
#define FIRMWARE_ID_BLACKBOX        "BLACKBOX"

#define FIRMWARE_ID        FIRMWARE_ID_CONTROLLER

/*
 * CPU ID
 *
 * TMS320F28335
 * TMS320F28377D
 */

#define CPU_ID_28335                "TMS320F28335"
#define CPU_ID_28377D               "TMS320F28377D"

#define CPU_ID                      CPU_ID_28377D

/*
 * BOARD ID
 *
 * CURRENT_CONTROL
 * VOLTAGE_CONTROL
 */

#define BOARD_ID_0                  "DSP377D-SP-VER3.3(20.12.07)"

#define BOARD_ID                    BOARD_ID_0



float get_version(void);

#endif // __VERSION_H
