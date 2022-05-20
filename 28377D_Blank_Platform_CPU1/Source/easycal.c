/*
 * easycal.c
 *
 *  Created on: 2021. 7. 8.asd
 *      Author: KYJ-PC
 */

#include "Define.h"
#include "easycal.h"



/*
 * ========================
 *      Sum_Arr_Float
 * ========================
 *
 * 1. parameter
 * par1 = array
 * par2 = F_SIZE(array)
 * par3 = number how many array you want to calculate. ( i.e, 0 ~ , ALL, HALF)
 *
 * 2. return value
 * Error : 1234.
 * Normal : Final Sum.
 *
 * 3. Guide
 * final_value = Sum_Arr_Float(array, F_SIZE(array), ALL);
 */
float Sum_Arr_Float(float * arr,  int arrsize,  int index)
{

    register int i, k;

    if(index == ALL)
        k = arrsize;

    else if(index == HALF)
        k = arrsize * 0.5;

    else if(index > arrsize)
        return 1234;
    else
        k = index;

    register float * rp_arr = &arr[0], sum;

    for(i = 0;i < k; i++)
    {
        sum += rp_arr[i];
    }

    return sum;
}

