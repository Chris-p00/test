//###############################################################################################################
// 파일명      : index.c
// 회사명      : G-Philos
// 작성날짜  : 2020.12.17
// 작성자      : KYJ-PC
// 수정날짜  : -
// 수정자      : -
// 설명         : Black Box 및 DAC 관련 함수 및 변수 구현
//###############################################################################################################


#include "Define.h"

#pragma DATA_SECTION(index_num,"RAMGS4_INDEXNUM");
#pragma DATA_SECTION(name_bb,"RAMGS6_7_INDEX")
#pragma DATA_SECTION(index_bb,"RAMGS7_INDEXSIZE")

#pragma DATA_SECTION(dac_index_num,"RAMGS4_DAC2");
#pragma DATA_SECTION(dac_data,"RAMGS7_DAC2");
char name_bb[5 * 1024];
int index_bb[501] = {0, };
int index_num[BUF_CTRL_MAX];
float32 *select_list[BUF_CTRL_MAX];
float32 *list[500];

float dac_data[4];



int dac_index_num[4];
float test0 = 45371;
extern float test_cnt;
extern float test_cnt2;
extern float sin_data;

//float BB_Send_ctrl_data_cnt1  = 0;
float BB_Send_ctrl_data_cnt1  = 5;
float BB_Send_ctrl_data_cnt2  = 0;
float BB_Send_ctrl_data_cnt3  = 0;
float BB_Send_ctrl_data_cnt4  = 0;
float BB_Send_ctrl_data_cnt5  = 0;
float BB_Send_ctrl_data_cnt6  = 0;
float BB_Send_ctrl_data_cnt7  = 0;
float BB_Send_ctrl_data_cnt8  = 0;
float BB_Send_ctrl_data_cnt9  = 0;
float BB_Send_ctrl_data_cnt10 = 0;

float BB_Send_ctrl_data_cnt11  = 0;
float BB_Send_ctrl_data_cnt12  = 0;
float BB_Send_ctrl_data_cnt13  = 0;
float BB_Send_ctrl_data_cnt14  = 0;
float BB_Send_ctrl_data_cnt15  = 0;
float BB_Send_ctrl_data_cnt16  = 0;
float BB_Send_ctrl_data_cnt17  = 0;
float BB_Send_ctrl_data_cnt18  = 0;
float BB_Send_ctrl_data_cnt19  = 0;
float BB_Send_ctrl_data_cnt20  = 0;

float BB_Send_ctrl_data_cnt21  = 0;
float BB_Send_ctrl_data_cnt22  = 0;
float BB_Send_ctrl_data_cnt23  = 0;
float BB_Send_ctrl_data_cnt24  = 0;
float BB_Send_ctrl_data_cnt25  = 0;
float BB_Send_ctrl_data_cnt26  = 0;
float BB_Send_ctrl_data_cnt27  = 0;
float BB_Send_ctrl_data_cnt28  = 0;
float BB_Send_ctrl_data_cnt29  = 0;
float BB_Send_ctrl_data_cnt30  = 0;





extern float adc_data[16];

//extern Uint16  adc_data[18];
//extern int32  adc_data[18];

extern float test;


int strnpack(char *dest, int index, char *source, int n)
{
    register int i = 0;
    register int r_index = index;
    register short unsigned int *pr_d = (short unsigned int *) &dest[r_index >> 1];
    register unsigned char *pr_s = (unsigned char *) source;

    for( i = 0; i < n; i++ )
    {
        if( (r_index & 0x01) == 0 )
        {
            *pr_d = (*pr_d & 0xff00) | ((short unsigned int)*pr_s << 0);
        }
        else
        {
            *pr_d = (*pr_d & 0x00ff) | ((short unsigned int)*pr_s << 8);
            pr_d++;
        }

        if( *pr_s == 0 )
        {
            break;
        }

        pr_s++;
        r_index++;
    }

    return (i);
}

int Idc_ripple = 0;
float Idc_ramp = 0.0;
unsigned int test_reg[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
void user_reg_service(Edit_Addr *pInfo)
{
    if( pInfo->dir == 0 )
    {
        /* write : CPU2 -> CPU1 */
        switch( pInfo->addr )
        {
            case 0: /* I */
                //reg[0] = 0; /* read only */
                test_reg[0] = pInfo->data; /* test */
                break;

            case 1: /* V */
                //reg[1] = 0; /* read only */
                test_reg[1] = pInfo->data; /* test */
                break;

            case 2: /* P */
                //reg[2] = 0; /* read only */
                test_reg[2] = pInfo->data; /* test */
                break;

            case 3: /* Imax => reg[3] : Imax_norm_float */
                Imax_norm_float = pInfo->data / 10.0; /* fixed point : 1/10 */
                test_reg[3] = pInfo->data; /* test */
                break;

            case 4: /* Vmax => reg[4] : Vmax_norm_float */
                Vmax_norm_float = pInfo->data / 10.0; /* fixed point : 1/10 */
                test_reg[4] = pInfo->data; /* test */
                break;

            case 5: /* Pmax => reg[5] : Pmax_norm_float */
                Pmax_norm_float = pInfo->data / 10.0; /* fixed point : 1/10 */
                test_reg[5] = pInfo->data; /* test */
                break;

            case 6: /* V target => reg[6] : Vref_target_float */
                if(pInfo->data == 0)
                {
                    Vref_target_float = 0;
                }
                else
                {
                    Vref_target_float = Vmax_norm_float * pInfo->data / 65535.0;
                }
                test_reg[6] = pInfo->data; /* test */
                break;

            case 7: /* I_in */
                //reg[7] = 0; /* read only */
                test_reg[7] = pInfo->data; /* test */
                break;

            case 8: /* V_in */
                //reg[8] = 0; /* read only */
                test_reg[8] = pInfo->data; /* test */
                break;

            case 9: /* P_in */
                //reg[9] = 0; /* read only */
                test_reg[9] = pInfo->data; /* test */
                break;

            case 10: /* Start/Stop */
                RunStopReset = pInfo->data; /* save previous command */
                if( pInfo->data == 77 )
                {
                    /* power on */
                    Run_Stop_com = 1.0;
                }
                else if( pInfo->data == 99 )
                {
                    /* power off */
                    Run_Stop_com = 0.0;
                }
                else if( pInfo->data == 33 )
                {
                    /* fault reset */
                    Fault_reset_com = 1.0;
                }
                else
                {
                    /* ignored */
                    pInfo->data = 0; /* return value */
                }
                test_reg[10] = pInfo->data; /* test */
                break;

            case 11: /* Status */
                //reg[11] = 0; /* don't care */
                test_reg[11] = pInfo->data; /* test */
                break;

            case 12:
                break;

            case 13: /* target current for test */
                i_gen_target = pInfo->data / 10.0; /* fixed point : 1/10 */
                test_reg[3] = pInfo->data; /* test */
                break;
        };
    }
    else
    {
        /* read : CPU2 <- CPU1 */
        switch( pInfo->addr )
        {
            case 0: /* I => reg[0] : Idc_flt_avg */
#if (0)
                if( Idc_flt_avg <= 0.0 )
                {
                    pInfo->data = 0;
                }
                else if( Idc_flt_avg > Imax_norm_float )
                {
                    pInfo->data = 65535;
                }
                else
                {
                    //pInfo->data = (unsigned int) (65535.0 * Ia_rms_avg / Imax_norm_float);
                    pInfo->data = (unsigned int) (65535.0 * Idc_flt_avg / Imax_norm_float);
                }
#else
    #if (1)
                if( Idc_ripple == 0 )
                {
                    Idc_ripple = 1;
                    Idc_ramp = 0.162; /* 86.0A / 529.9283A max */
                }
                else
                {
                    Idc_ripple = 0;
                    Idc_ramp = 0.165; /* ??A / 529.9283A max */
                }
                pInfo->data = (unsigned int) (65535.0 * Idc_ramp);
    #else
                pInfo->data = (unsigned int) (65535.0 * Idc_ramp);
                Idc_ramp += 0.0001;
                if( Idc_ramp >= 1.0 )
                {
                    Idc_ramp = 0.0;
                }
    #endif
#endif
                break;

            case 1: /* V => reg[1] : Esa_rms_avg */
                if( Vdc_flt_avg <= 0.0 )
                {
                    pInfo->data = 0;
                }
                else if( Vdc_flt_avg > Vmax_norm_float )
                {
                    pInfo->data = 65535;
                }
                else
                {
                    //pInfo->data = (unsigned int) (65535.0 * Esa_rms_avg / Vmax_norm_float);
                    pInfo->data = (unsigned int) (65535.0 * Vdc_flt_avg / Vmax_norm_float);
                }
                break;

            case 2: /* P => reg[2] : Pinv_DQ_avg */
                if( Pinv_DQ_avg <= 0.0 )
                {
                    pInfo->data = 0;
                }
                else if( Pinv_DQ_avg > Pmax_norm_float )
                {
                    pInfo->data = 65535;
                }
                else
                {
                    pInfo->data = (unsigned int) (65535.0 * Pinv_DQ_avg / Pmax_norm_float);
                }
                break;

            case 3: /* Imax => reg[3] : Imax_norm_float */
                pInfo->data = (unsigned int) (Imax_norm_float * 10.0); /* fixed point : x10 */
                break;

            case 4: /* Vmax => reg[4] : Vmax_norm_float */
                pInfo->data = (unsigned int) (Vmax_norm_float * 10.0); /* fixed point : x10 */
                break;

            case 5: /* Pmax => reg[5] : Pmax_norm_float */
                pInfo->data = (unsigned int) (Pmax_norm_float * 10.0); /* fixed point : x10 */
                break;

            case 6: /* Vref target */
                if( Vref_target_float <= 0.0 )
                {
                    pInfo->data = 0;
                }
                else if( Vref_target_float > Vmax_norm_float )
                {
                    pInfo->data = 65535;
                }
                else
                {
                    pInfo->data = (unsigned int) (65535.0 * Vref_target_float / Vmax_norm_float);
                }
                break;

            case 7: /* I_in */
                //pInfo->data = Vref_target_float;
                break;

            case 8: /* V_in */
                //pInfo->data = Vref_target_float;
                break;

            case 9: /* P_in */
                //pInfo->data = Vref_target_float;
                break;

            case 10: /* Start/Stop */
                pInfo->data = RunStopReset; /* return previous control command */
                break;

            case 11: /* Status */
                pInfo->data = INV_status; // 0:offset, 1:ready, 2: buildup, 3: run, 4: fault
                break;

            case 12: /* FaultSW */
                pInfo->data = Fault_SW;
                break;

            case 13: /* target current for test */
                pInfo->data = (unsigned int) (i_gen_target * 10.0); /* fixed point : x10 */
                break;
        };
    }
}

void BB_Send_dac_data()
{
    dac_data[0] = *list[dac_index_num[0]];
    dac_data[1] = *list[dac_index_num[1]];
    dac_data[2] = *list[dac_index_num[2]];
    dac_data[3] = *list[dac_index_num[3]];
}

float fault_test0 = 0;
float fault_test1 = 0;
float fault_test2 = 0;

void Set_List()
{
    unsigned int str_len = 0;
    // Max = 500 -> define = 150
    /* CTRL */ //50EA
#if(0)
    MATCH(0, Vin_flt, "Vin_flt")

    MATCH(1, Idc, "Idc")

    MATCH(2, Vdc_flt, "Vdc_flt")

    MATCH(3, Esa, "Esa")

    MATCH(4, Esb, "Esb")

    MATCH(5, Esc, "Esc")

    MATCH(6, Ia, "Ia")

    MATCH(7, Ib, "Ib")

    MATCH(8, Ic, "Ic")

    MATCH(9, Fault_SW_float, "Fault_SW_float")
#else


    //MATCH(0, test_cnt2, "test_cnt2")
    //MATCH(1, test_cnt, "test_cnt")
    //MATCH(2, test0, "test0")

    fault_test0 = System_fault_latch;
    fault_test1 = Fault_SW_latch;
    fault_test2 = Fault_HW_latch;
    //MATCH(0, fault_test0, "fault_test0")
    //MATCH(1, fault_test1, "fault_test1")
    //MATCH(2, fault_test2, "fault_test2")
    //MATCH(3, Vqs_flt, "Vqs_flt")

    MATCH(0, sig_test0, "sig_test0")
    MATCH(1, sig_test1, "sig_test1")
    MATCH(2, sig_test2, "sig_test2")
    MATCH(3, sig_test3, "sig_test3")
    MATCH(4, sig_test4, "sig_test4")
    MATCH(5, sig_test5, "sig_test5")

    //MATCH(3, adc_data[12], "adc_data[12]")
    //MATCH(3, Esa, "Esa")
    //MATCH(4, Esb, "Esb")
    //MATCH(5, Esc, "Esc")

    MATCH(6, Ia, "Ia")

    MATCH(7, Ib, "Ib")

    MATCH(8, Ic, "Ic")

    MATCH(9, Fault_SW_float, "Fault_SW_float")
#endif

#if 1
    //21.09.02
    MATCH(10, Esa_gen, "Esa_gen")

    MATCH(11, Esb_gen, "Esb_gen")

    MATCH(12, Esc_gen, "Esc_gen")

    MATCH(13, Ia_gen, "Ia_gen")

    MATCH(14, Ib_gen, "Ib_gen")

    MATCH(15, Ic_gen, "Ic_gen")

    MATCH(16, f_gen_target, "f_gen_target")

    MATCH(17, i_gen_target, "i_gen_target")

    MATCH(18, Vin_max_gen, "Vin_max_gen")

    MATCH(19, Vdc_max_gen, "Vdc_max_gen")

    MATCH(20, Vac_max_gen, "Vac_max_gen")

    MATCH(21, Peff_gen, "Peff_gen")

    MATCH(22, t_gen, "t_gen")

    {
        extern float f_gen;
    MATCH(23, f_gen, "f_gen")
    }
#endif
#if 0

    MATCH(10, Idc_ref, "Idc_ref")

    MATCH(11, Err_Idc, "Err_Idc")

    MATCH(12, Idc_integ, "Idc_integ")

    MATCH(13, Idc_out, "Idc_out")

    MATCH(14, Idc_real, "Idc_real")

    MATCH(15, Tsamp_INV_Vin, "Tsamp_INV_Vin")

    MATCH(16, Ta_real_con_float, "Ta_real_con_float")

    MATCH(17, Ta_con_float, "Ta_con_float")

    MATCH(18, Vin_flt, "Vin_flt")

    MATCH(19, Vdc_flt, "Vdc_flt")



    MATCH(20, VF_vtg_max, "VF_vtg_max")

    MATCH(21, VF_vtg, "VF_vtg")

    MATCH(22, VF_freq, "VF_freq")
#endif

//    MATCH(23, theta_VF, "theta_VF")

    MATCH(24, Va_ref, "Va_ref")

    MATCH(25, Vb_ref, "Vb_ref")

    MATCH(26, Vc_ref, "Vc_ref")

    MATCH(27, Ta_real_inv_float, "Ta_real_inv_float")

    MATCH(28, Tb_real_inv_float, "Tb_real_inv_float")

    MATCH(29, Tc_real_inv_float, "Tc_real_inv_float")


    MATCH(30, Vdc_ref_con_set, "Vdc_ref_con_set")

    MATCH(31, Vdc_ref_con, "Vdc_ref_con")

    MATCH(32, Idc_ref_comp, "Idc_ref_comp")

    MATCH(33, Idc_flt_avg, "Idc_flt_avg")

    MATCH(34, Vdc_con_real_max, "Vdc_con_real_max")

    MATCH(35, Err_Vdc_con, "Err_Vdc_con")

    MATCH(36, Vdc_con_integ, "Vdc_con_integ")

    MATCH(37, Vdc_con_out, "Vdc_con_out")

    MATCH(38, Vdc_con_real, "Vdc_con_real")

    MATCH(39, Vdc_flt, "Vdc_flt")


    MATCH(40, Vdc_ref_con_set, "Vdc_ref_con_set")

    MATCH(41, Vdc_ref_con, "Vdc_ref_con")

    MATCH(42, Idc_ref_comp, "Idc_ref_comp")

    MATCH(43, Idc_flt_avg, "Idc_flt_avg")

    MATCH(44, Vdc_con_real_max, "Vdc_con_real_max")

    MATCH(45, Err_Vdc_con, "Err_Vdc_con")

    MATCH(46, Vdc_con_integ, "Vdc_con_integ")

    MATCH(47, Vdc_con_out, "Vdc_con_out")

    MATCH(48, Vdc_con_real, "Vdc_con_real")

    MATCH(49, Vdc_flt, "Vdc_flt")


    MATCH(50, Vdc_ref_inv, "Vdc_ref_inv")

    MATCH(51, Err_Vdc_inv, "Err_Vdc_inv")

    MATCH(52, Ip_ref_integ, "Ip_ref_integ")

    MATCH(53, Ip_ref_out, "Ip_ref_out")

    MATCH(54, Ip_ref_real_max, "Ip_ref_real_max")

    MATCH(55, Ip_ref_real, "Ip_ref_real")

    MATCH(56, Ip_ref, "Ip_ref")

    MATCH(57, Iqe_ref, "Iqe_ref")

    MATCH(58, Ide_ref, "Ide_ref")

    MATCH(59, Vdc_flt, "Vdc_flt")


    MATCH(60, Vdc_ref_inv, "Vdc_ref_inv")

    MATCH(61, Err_Vdc_inv, "Err_Vdc_inv")

    MATCH(62, Ip_ref_integ, "Ip_ref_integ")

    MATCH(63, Ip_ref_out, "Ip_ref_out")

    MATCH(64, Ip_ref_real_max, "Ip_ref_real_max")

    MATCH(65, Ip_ref_real, "Ip_ref_real")

    MATCH(66, Ip_ref, "Ip_ref")

    MATCH(67, Iqe_ref, "Iqe_ref")

    MATCH(68, Ide_ref, "Ide_ref")

    MATCH(69, Vdc_flt, "Vdc_flt")

#if 1

    MATCH(70, Err_Vdc_inv, "Err_Vdc_inv")

    MATCH(71, Vdc_ref_inv, "Vdc_ref_inv")

    MATCH(72, Vdc_flt, "Vdc_flt")

    MATCH(73, Ip_ref_integ, "Ip_ref_integ")

    MATCH(74, Ip_ref_out, "Ip_ref_out")

    MATCH(75, Ip_ref_real_max, "Ip_ref_real_max")

    MATCH(76, Ip_ref_real, "Ip_ref_real")

    MATCH(77, Ip_ref, "Ip_ref")

    MATCH(78, Iqe_ref, "Iqe_ref")

    MATCH(79, Ide_ref, "Ide_ref")

    MATCH(80, Err_Ide, "Err_Ide")

    MATCH(81, Err_Iqe, "Err_Iqe")

    MATCH(82, Ide_ref, "Ide_ref")

    MATCH(83, Iqe_ref, "Iqe_ref")

    MATCH(84, Ide, "Ide")

    MATCH(85, Iqe, "Iqe")

    MATCH(86, Vde_ref, "Vde_ref")

    MATCH(87, Vqe_ref, "Vqe_ref")

    MATCH(88, Vds_ref, "Vds_ref")

    MATCH(89, Vqs_ref, "Vqs_ref")

    MATCH(90, Ide_n, "Ide_n")

    MATCH(91, Iqe_n, "Iqe_n")

    MATCH(92, pVfe1[DX][CREF], "pVfe1[DX][CREF]")

    MATCH(93, pVfe1[QX][CREF], "pVfe1[QX][CREF]")

    MATCH(94, pVfe1[DX][CFB], "pVfe1[DX][CFB]")

    MATCH(95, pVfe1[QX][CFB], "pVfe1[QX][CFB]")

    MATCH(96, pVfe1[DX][CFF], "pVfe1[DX][CFF]")

    MATCH(97, pVfe1[QX][CFF], "pVfe1[QX][CFF]")

    MATCH(98, pVfe1[DX][CINT], "pVfe1[DX][CINT]")

    MATCH(99, pVfe1[QX][CINT], "pVfe1[QX][CINT]")

    MATCH(100, pVfe1[DX][CACT], "pVfe1[DX][CACT]")

    MATCH(101, pVfe1[QX][CACT], "pVfe1[QX][CACT]")

    MATCH(102, Flag_Act_islanding, "Flag_Act_islanding")

    MATCH(103, Freq_source_period, "Freq_source_period")

    MATCH(104, Freq_out, "Freq_out")

    MATCH(105, Freq_rate_init, "Freq_rate_init")

    MATCH(106, Freq_rate, "Freq_rate")

    MATCH(107, Freq_shift_init, "Freq_shift_init")

    MATCH(108, Freq_shift_ratio, "Freq_shift_ratio")

    MATCH(109, Freq_jump, "Freq_jump")

    MATCH(110, Vin_flt_avg, "Vin_flt_avg")

    MATCH(111, A_ref_flt_avg, "A_ref_flt_avg")

    MATCH(112, Vdc_flt_avg, "Vdc_flt_avg")

    MATCH(113, Idc_flt_avg, "Idc_flt_avg")

    MATCH(114, Theta, "Theta")

    MATCH(115, Sin_theta, "Sin_theta")

    MATCH(116, Cos_theta, "Cos_theta")

    MATCH(117, Theta_C, "Theta_C")

    MATCH(118, Sin_theta_C, "Sin_theta_C")

    MATCH(119, Cos_theta_C, "Cos_theta_C")

    MATCH(120, Pin, "Pin")

    MATCH(121, Pinv_DQ_avg, "Pinv_DQ_avg")

    XMATCH(122, Mode_system_float, "Mode_system_float")

    MATCH(123, Vl_rate, "Vl_rate")

    MATCH(124, Vs_rate, "Vs_rate")

    MATCH(125, Vs_rate_peak, "Vs_rate_peak")

    MATCH(126, Ic_rate, "Ic_rate")

    MATCH(127, Ic_rate_peak, "Ic_rate_peak")

    MATCH(128, Vin_max, "Vin_max")

    MATCH(129, Vin_min, "Vin_min")

    MATCH(130, OV_set_Vin, "OV_set_Vin")

    MATCH(131, UV_set_Vin, "UV_set_Vin")

    MATCH(132, Idc_max, "Idc_max")

    MATCH(133, OC_Idc_set, "OC_Idc_set")

    MATCH(134, OV_set_src, "OV_set_src")

    MATCH(135, UV_set_src, "UV_set_src")

    MATCH(136, INTER_set_src, "INTER_set_src")

    MATCH(137, OV_set_src_rms, "OV_set_src_rms")

    MATCH(138, UV_set_src_rms, "UV_set_src_rms")

    MATCH(139, OC_set, "OC_set")

    MATCH(140, Overload_Pout, "Overload_Pout")

    MATCH(141, Vin_MC_ON_level, "Vin_MC_ON_level")

    MATCH(142, Vin_MC_OFF_level, "Vin_MC_OFF_level")

    MATCH(143, Vin_max_80, "Vin_max_80")

    MATCH(144, Vin_min_2, "Vin_min_2")

    MATCH(145, AC_MC_ON_level, "AC_MC_ON_level")

    MATCH(146, AC_MC_OFF_level, "AC_MC_OFF_level")

    MATCH(147, Vin_min_2, "Vin_min_2")

    MATCH(148, AC_MC_ON_level, "AC_MC_ON_level")

    MATCH(149, AC_MC_OFF_level, "AC_MC_OFF_level")
#endif

    MATCH(150, Ia, "Ia")

    MATCH(151, Ib, "Ib")

    MATCH(152, Ic, "Ic")

    MATCH(153, Ia_flt, "Ia_flt")

    MATCH(154, Ib_flt, "Ib_flt")

    MATCH(155, Ic_flt, "Ic_flt")

    MATCH(156, Ids, "Ids")

    MATCH(157, Iqs, "Iqs")

    MATCH(158, Ide, "Ide")

    MATCH(159, Iqe, "Iqe")

    MATCH(160, Ia_rms, "Ia_rms")

    MATCH(161, Ib_rms, "Ib_rms")

    MATCH(162, Ic_rms, "Ic_rms")

    MATCH(163, Ia_offset, "Ia_offset")

    MATCH(164, Ib_offset, "Ib_offset")

    MATCH(165, Ic_offset, "Ic_offset")

    MATCH(166, Vin_flt_avg, "Vin_flt_avg")

    MATCH(167, Idc_flt_avg, "Idc_flt_avg")

    MATCH(168, Pin, "Pin")

    MATCH(169, Idc_ref, "Idc_ref")

    MATCH(170, Ide_ref, "Ide_ref")

    MATCH(171, Iqe_ref, "Iqe_ref")

    MATCH(172, Err_Ide, "Err_Ide")

    MATCH(173, Err_Iqe, "Err_Iqe")

    MATCH(174, Ip_ref, "Ip_ref")

    MATCH(175, Ip_ref_real, "Ip_ref_real")

    MATCH(176, Ip_ref_out, "Ip_ref_out")

    MATCH(177, Ip_ref_integ, "Ip_ref_integ")

    MATCH(178, Ip_ref_ff, "Ip_ref_ff")

    MATCH(179, Vdc_inv_real, "Vdc_inv_real")

    MATCH(180, Vdc_inv_out, "Vdc_inv_out")

    MATCH(181, Vdc_inv_integ, "Vdc_inv_integ")

    MATCH(182, Vdc_inv_ff, "Vdc_inv_ff")

    MATCH(183, Ip_ref_real_max, "Ip_ref_real_max")

    MATCH(184, Theta, "Theta")

    MATCH(185, Sin_theta, "Sin_theta")

    MATCH(186, Cos_theta, "Cos_theta")

    MATCH(187, Sin_thetaT, "Sin_thetaT")

    MATCH(188, Sin_theta_C, "Sin_theta_C")

    MATCH(189, Cos_theta_C, "Cos_theta_C")

    MATCH(190, Freq_out, "Freq_out")

    MATCH(191, K_cc[CKP], "K_cc[CKP]")

    MATCH(192, K_cc[CKIT], "K_cc[CKIT]")

    MATCH(193, K_cc[CKA], "K_cc[CKA]")

    MATCH(194, Kp_VC, "Kp_VC")

    MATCH(195, Ki_VC, "Ki_VC")

    MATCH(196, Ka_VC, "Ka_VC")

    MATCH(197, OV_set_Vdc, "OV_set_Vdc")

    MATCH(198, UV_set_Vdc, "UV_set_Vdc")

    MATCH(199, OV_set_src, "OV_set_src")

    MATCH(200, UV_set_src, "UV_set_src")

    MATCH(201, INTER_set_src, "INTER_set_src")

    MATCH(202, OC_set, "OC_set")

    MATCH(203, Eab, "Eab")

    MATCH(204, Ebc, "Ebc")

    MATCH(205, Eca, "Eca")

    MATCH(206, Scale_A_ref, "Scale_A_ref")

    MATCH(207, A_ref_offset, "A_ref_offset")

    MATCH(208, Esc, "Esc")

    MATCH(209, Eab_flt, "Eab_flt")

    MATCH(210, Ebc_flt, "Ebc_flt")

    MATCH(211, Eca_flt, "Eca_flt")

    MATCH(212, Vds, "Vds")

    MATCH(213, Vqs, "Vqs")

    MATCH(214, Vde, "Vde")

    MATCH(215, Vqe, "Vqe")

    MATCH(216, Vds_flt, "Vds_flt")

    MATCH(217, Vqs_flt, "Vqs_flt")

    MATCH(218, Vde_flt, "Vde_flt")

    MATCH(219, Vqe_flt, "Vqe_flt")

    MATCH(220, Eab_rms, "Eab_rms")

    MATCH(221, Ebc_rms, "Ebc_rms")

    MATCH(222, Eca_rms, "Eca_rms")

    MATCH(223, Err_Vde, "Err_Vde")

    MATCH(224, Vde_ref, "Vde_ref")

    MATCH(225, Vqe_ref, "Vqe_ref")

    MATCH(226, Vds_ref, "Vds_ref")

    MATCH(227, Vqs_ref, "Vqs_ref")

    MATCH(228, Va_ref, "Va_ref")

    MATCH(229, Vb_ref, "Vb_ref")

    MATCH(230, Vc_ref, "Vc_ref")

    MATCH(231, Vfds_ref, "Vfds_ref")

    MATCH(232, Vfqs_ref, "Vfqs_ref")

    MATCH(233, Esa_rms, "Esa_rms")

    MATCH(234, Esb_rms, "Esb_rms")

    MATCH(235, Esc_rms, "Esc_rms")

    MATCH(236, PF_util, "PF_util")

    MATCH(237, PF_util_avg, "PF_util_avg")

    MATCH(238, Pinv_DQ_avg, "Pinv_DQ_avg")

    MATCH(239, Pout, "Pout")

    MATCH(240, Pinv_DQ, "Pinv_DQ")

    MATCH(241, Vde_flt_C, "Vde_flt_C")

    MATCH(242, Theta_C, "Theta_C")

    MATCH(243, Sin_theta_C, "Sin_theta_C")

    MATCH(244, Cos_theta_C, "Cos_theta_C")

    MATCH(245, Vds_apf, "Vds_apf")

    MATCH(246, Vqs_apf, "Vqs_apf")

    MATCH(247, Vds_p, "Vds_p")

    MATCH(248, Vqs_p, "Vqs_p")

    MATCH(249, Vds_n, "Vds_n")

    MATCH(250, Vqs_n, "Vqs_n")

    MATCH(251, Vde_p, "Vde_p")

    MATCH(252, Vqe_p, "Vqe_p")

    MATCH(253, Vde_n, "Vde_n")

    MATCH(254, Vqe_n, "Vqe_n")

    MATCH(255, Theta_h, "Theta_h")

    MATCH(256, Theta_n, "Theta_n")

    MATCH(257, Sin_theta_n, "Sin_theta_n")

    MATCH(258, Cos_theta_n, "Cos_theta_n")

    MATCH(259, Theta_C_n, "Theta_C_n")

    MATCH(260, Sin_theta_C_n, "Sin_theta_C_n")

    MATCH(261, Cos_theta_C_n, "Cos_theta_C_n")

    MATCH(262, Ids_apf, "Ids_apf")

    MATCH(263, Iqs_apf, "Iqs_apf")

    MATCH(264, Ids_p, "Ids_p")

    MATCH(265, Iqs_p, "Iqs_p")

    MATCH(266, Ids_n, "Ids_n")

    MATCH(267, Iqs_n, "Iqs_n")

    MATCH(268, Ide_p, "Ide_p")

    MATCH(269, Iqe_p, "Iqe_p")

    MATCH(270, Ide_n, "Ide_n")

    MATCH(271, Iqe_n, "Iqe_n")

    MATCH(272, pVfe1[DX][CREF], "pVfe1[DX][CREF]")

    MATCH(273, pVfe1[QX][CREF], "pVfe1[QX][CREF]")

    MATCH(274, pVfe1[DX][CFB], "pVfe1[DX][CFB]")

    MATCH(275, pVfe1[QX][CFB], "pVfe1[QX][CFB]")

    MATCH(276, pVfe1[DX][CFF], "pVfe1[DX][CFF]")

    MATCH(277, pVfe1[QX][CFF], "pVfe1[QX][CFF]")

    MATCH(278, pVfe1[DX][CINT], "pVfe1[DX][CINT]")

    MATCH(279, pVfe1[QX][CINT], "pVfe1[QX][CINT]")

    MATCH(280, pVfe1[DX][CACT], "pVfe1[DX][CACT]")

    MATCH(281, pVfe1[QX][CACT], "pVfe1[QX][CACT]")

    MATCH(282, Vdc, "Vdc")

    MATCH(283, Vdc_flt, "Vdc_flt")

    MATCH(284, Err_Vdc_con, "Err_Vdc_con")

    MATCH(285, Err_Vdc_inv, "Err_Vdc_inv")

    MATCH(286, Vdc_ref_con, "Vdc_ref_con")

    MATCH(287, A_ref_flt_avg, "A_ref_flt_avg")

    MATCH(288, Vdc_ref_inv, "Vdc_ref_inv")

    MATCH(289, Vdc_flt_avg, "Vdc_flt_avg")

    MATCH(290, Err_Vdc_inv, "Err_Vdc_inv")

    MATCH(291, Vdc_ref_inv, "Vdc_ref_inv")

    MATCH(292, Vdc_flt, "Vdc_flt")

    MATCH(293, Ip_ref_integ, "Ip_ref_integ")

    MATCH(294, Ip_ref_out, "Ip_ref_out")

    MATCH(295, Ip_ref_real_max, "Ip_ref_real_max")

    MATCH(296, Ip_ref_real, "Ip_ref_real")

    MATCH(297, Ip_ref, "Ip_ref")

    MATCH(298, Iqe_ref, "Iqe_ref")

    MATCH(299, Ide_ref, "Ide_ref")

    MATCH(300, Err_Ide, "Err_Ide")

    MATCH(301, Err_Iqe, "Err_Iqe")

    MATCH(302, Ide_ref, "Ide_ref")

    MATCH(303, Iqe_ref, "Iqe_ref")

    MATCH(304, Ide, "Ide")

    MATCH(305, Iqe, "Iqe")

    MATCH(306, Vde_ref, "Vde_ref")

    MATCH(307, Vqe_ref, "Vqe_ref")

    MATCH(308, Vds_ref, "Vds_ref")

    MATCH(309, Vqs_ref, "Vqs_ref")

    MATCH(310, Vfds_ref, "Vfds_ref")

    MATCH(311, Vfqs_ref, "Vfqs_ref")

    MATCH(312, Va_ref, "Va_ref")

    MATCH(313, Vb_ref, "Vb_ref")

    MATCH(314, Vc_ref, "Vc_ref")

    MATCH(315, Ta_real_inv_float, "Ta_real_inv_float")

    MATCH(316, Tb_real_inv_float, "Tb_real_inv_float")

    MATCH(317, Tc_real_inv_float, "Tc_real_inv_float")

    MATCH(318, Vin_flt, "Vin_flt")

    MATCH(319, Vdc_flt, "Vdc_flt")

    MATCH(320, Ide_cff_p, "Ide_cff_p")

    MATCH(321, Iqe_cff_p, "Iqe_cff_p")

    MATCH(322, Ide_cff_n, "Ide_cff_n")

    MATCH(323, Ide_cff_n, "Ide_cff_n")

    MATCH(324, Ide_err_p, "Ide_err_p")

    MATCH(325, Ide_ref_integ_p, "Ide_ref_integ_p")

    MATCH(326, Ide_ref_out_p, "Ide_ref_out_p")

    MATCH(327, Ide_ref_p, "Ide_ref_p")

    MATCH(328, Ide_ref_out_p, "Ide_ref_out_p")

    MATCH(329, Iqe_err_p, "Iqe_err_p")

    MATCH(330, Vfds_ref, "Iqe_ref_integ_p")

    MATCH(331, Iqe_out_p, "Iqe_out_p")

    MATCH(332, Iqe_ref_p, "Iqe_ref_p")

    MATCH(333, Iqe_ref_out_p, "Iqe_ref_out_p")

    MATCH(334, Ide_err_n, "Ide_err_n")

    MATCH(335, Ide_ref_integ_n, "Ide_ref_integ_n")

    MATCH(336, Ide_out_n, "Ide_out_n")

    MATCH(337, Ide_ref_p_n, "Ide_ref_p_n")

    MATCH(338, Ide_ref_out_n, "Ide_ref_out_n")

    MATCH(339, Iqe_err_n, "Iqe_err_n")

    MATCH(340, Iqe_ref_integ_n, "Iqe_ref_integ_n")

    MATCH(341, Iqe_ref_integ_n, "Iqe_ref_integ_n")

    MATCH(342, Iqe_ref_p_n, "Iqe_ref_p_n")

    MATCH(343, Iqe_ref_out_n, "Iqe_ref_out_n")

    MATCH(344, Vcon_beta_p, "Vcon_beta_p")

    MATCH(345, Vcon_alpha_n, "Vcon_alpha_n")

    MATCH(346, Vcon_beta_n, "Vcon_beta_n")

    MATCH(347, Vas_ref_p, "Vas_ref_p")

    MATCH(348, Vbs_ref_p, "Vbs_ref_p")

    MATCH(349, Vcs_ref_p, "Vcs_ref_p")

    MATCH(350, Vas_ref_n, "Vas_ref_n")

    MATCH(351, Vbs_ref_n, "Vbs_ref_n")

    MATCH(352, Vb_ref, "Vb_ref")

    MATCH(353, Va_ref, "Va_ref")

    MATCH(354, Vc_ref, "Vc_ref")

    MATCH(355, Vb_ref, "Vb_ref")

    MATCH(356, Ta_real_inv_float, "Ta_real_inv_float")

    MATCH(357, Tb_real_inv_float, "Tb_real_inv_float")

    MATCH(358, Tc_real_inv_float, "Tc_real_inv_float")

    MATCH(359, Vdc_flt, "Vdc_flt")

    MATCH(360, Ka_ide_fb_p, "Ka_ide_fb_p")

    MATCH(361, Ka_iqe_fb_p, "Ka_iqe_fb_p")

    MATCH(362, Ka_ide_fb_n, "Ka_ide_fb_n")

    MATCH(363, Ka_iqe_fb_n, "Ka_iqe_fb_n")

    MATCH(364, Vas_ref_SV, "Vas_ref_SV")

    MATCH(365, Vbs_ref_SV, "Vbs_ref_SV")

    MATCH(366, Vcs_ref_SV, "Vcs_ref_SV")

    MATCH(367, Vmax_SV, "Vmax_SV")

    MATCH(368, Vmin_SV, "Vmin_SV")

    MATCH(369, Vsn_SV, "Vsn_SV")

    MATCH(370, Err_Idc, "Err_Idc")

    MATCH(371, Idc_ref, "Idc_ref")

    MATCH(372, Idc, "Idc")

    MATCH(373, Idc_integ, "Idc_integ")

    MATCH(374, Idc_out, "Idc_out")

    MATCH(375, Idc_real, "Idc_real")

    MATCH(376, Tsamp_INV_Vin, "Tsamp_INV_Vin")

    MATCH(377, Ta_real_con_float, "Ta_real_con_float")

    MATCH(378, Vmin_SV, "Ta_real_con_float")

    MATCH(379, Idc_flt, "Idc_flt")

    MATCH(380, Kp_Idc_ref_Cf, "Kp_Idc_ref_Cf")

    MATCH(381, Idc_ref_Cf, "Idc_ref_Cf")

    MATCH(382, Iqe_ref_flt, "Iqe_ref_flt")

    MATCH(383, Vde_p_flt, "Vde_p_flt")

    MATCH(384, Vqe_p_flt, "Vqe_p_flt")

    MATCH(385, Vde_n_flt, "Vde_n_flt")

    MATCH(386, Vqe_n_flt, "Vqe_n_flt")

    MATCH(387, Kp_Vde_ff_flt, "Kp_Vde_ff_flt")

    MATCH(388, Kp_Vqe_ff_flt, "Kp_Vqe_ff_flt")

    MATCH(389, Kp_Iqe_ff_flt, "Kp_Iqe_ff_flt")

    MATCH(390, Kp_Ide_ff_flt, "Kp_Ide_ff_flt")

    MATCH(391, Err_Ide, "Err_Ide")

    MATCH(392, Ide, "Ide")

    MATCH(393, Ide_ref, "Ide_ref")

    MATCH(394, Ide_ref_Cf, "Ide_ref_Cf")

    MATCH(395, Err_Iqe, "Err_Iqe")

    MATCH(396, Iqe, "Iqe")

    MATCH(397, Iqe_ref, "Iqe_ref")

    MATCH(398, Iqe_ref_Cf, "Iqe_ref_Cf")

    MATCH(399, pVfe1[DX][CINT], "pVfe1[DX][CINT]")

    MATCH(400, pVfe1[DX][CFB], "pVfe1[DX][CFB]")

    MATCH(401, pVfe1[DX][CREF], "pVfe1[DX][CREF]")

    MATCH(402, pVfe1[DX][CACT], "pVfe1[DX][CACT]")

    MATCH(403, pVfe1[DX][CFF], "pVfe1[DX][CFF]")

    MATCH(404, pVfe1[QX][CINT], "pVfe1[QX][CINT]")

    MATCH(405, pVfe1[QX][CFB], "pVfe1[QX][CFB]")

    MATCH(406, pVfe1[QX][CREF], "pVfe1[QX][CREF]")

    MATCH(407, pVfe1[QX][CACT], "pVfe1[QX][CACT]")

    MATCH(408, pVfe1[QX][CFF], "pVfe1[QX][CFF]")

    MATCH(409, K_cc_DX_CKIT_Err_Ide, "K_cc_DX_CKIT_Err_Ide")

    MATCH(410, K_cc_DX_CKIT_K_cc_CKA, "K_cc_DX_CKIT_K_cc_CKA")

    MATCH(411, K_cc_QX_CKIT_Err_Iqe, "K_cc_QX_CKIT_Err_Iqe")

    MATCH(412, K_cc_QX_CKIT_K_cc_CKA, "K_cc_QX_CKIT_K_cc_CKA")

    MATCH(413, T0_check, "T0_check")

    MATCH(414, Flag_over_modu, "Flag_over_modu")

    MATCH(415, Vde_dc, "Vde_dc")

    MATCH(416, Vqe_dc, "Vqe_dc")

    MATCH(417, Iqe_p_flt, "Iqe_p_flt")

    MATCH(418, Ide_p_flt, "Ide_p_flt")

    MATCH(419, Iqe_n_flt, "Iqe_n_flt")

    MATCH(420, Ide_n_flt, "Ide_n_flt")

    MATCH(421, Vds_5th_ref_p, "Vds_5th_ref_p")

    MATCH(422, Vqs_5th_ref_p, "Vqs_5th_ref_p")

    MATCH(423, Vds_5th_ref_n, "Vds_5th_ref_n")

    MATCH(424, Vqs_5th_ref_n, "Vqs_5th_ref_n")

    MATCH(425, rout_10ms_count_float, "rout_10ms_count_float")

    MATCH(426, Flag_charge_float, "Flag_charge_float")

    MATCH(427, MC_on_cnt_float, "MC_on_cnt_float")

    MATCH(428, Tb_real_inv_float, "Tb_real_inv_float")

    MATCH(429, Tc_real_inv_float, "Tc_real_inv_float")

    MATCH(430, Vdc_ref_con_set, "Vdc_ref_con_set")

    MATCH(431, Vdc_ref_con, "Vdc_ref_con")

    MATCH(432, Idc_ref_comp, "Idc_ref_comp")

    MATCH(433, Idc_flt_avg, "Idc_flt_avg")

    MATCH(434, Vdc_con_real_max, "Vdc_con_real_max")

    MATCH(435, Err_Vdc_con, "Err_Vdc_con")

    MATCH(436, Vdc_con_integ, "Vdc_con_integ")

    MATCH(437, Vdc_con_out, "Vdc_con_out")

    MATCH(438, Vdc_con_real, "Vdc_con_real")

    MATCH(439, Vdc_flt, "Vdc_flt")

    MATCH(440, Vdc_ref_con_set, "Vdc_ref_con_set")

    MATCH(441, Vdc_ref_con, "Vdc_ref_con")

    MATCH(442, Idc_ref_comp, "Idc_ref_comp")

    MATCH(443, Idc_flt_avg, "Idc_flt_avg")

    MATCH(444, Vdc_con_real_max, "Vdc_con_real_max")

    MATCH(445, Err_Vdc_con, "Err_Vdc_con")

    MATCH(446, Vdc_con_integ, "Vdc_con_integ")

    MATCH(447, Vdc_con_out, "Vdc_con_out")

    MATCH(448, Vdc_con_real, "Vdc_con_real")

    MATCH(449, Vdc_flt, "Vdc_flt")

    MATCH(450, Vdc_ref_inv, "Vdc_ref_inv")

    MATCH(451, Err_Vdc_inv, "Err_Vdc_inv")

    MATCH(452, Ip_ref_integ, "Ip_ref_integ")

    MATCH(453, Ip_ref_out, "Ip_ref_out")

    MATCH(454, Ip_ref_real_max, "Ip_ref_real_max")

    MATCH(455, Ip_ref_real, "Ip_ref_real")

    MATCH(456, Ip_ref, "Ip_ref")

    MATCH(457, Iqe_ref, "Iqe_ref")

    MATCH(458, Ide_ref, "Ide_ref")

    MATCH(459, Vdc_flt, "Vdc_flt")


    MATCH(460, Vdc_ref_inv, "Vdc_ref_inv")

    MATCH(461, Err_Vdc_inv, "Err_Vdc_inv")

    MATCH(462, Ip_ref_integ, "Ip_ref_integ")

    MATCH(463, Ip_ref_out, "Ip_ref_out")

    MATCH(464, Ip_ref_real_max, "Ip_ref_real_max")

    MATCH(465, Ip_ref_real, "Ip_ref_real")

    MATCH(466, Ip_ref, "Ip_ref")

    MATCH(467, Iqe_ref, "Iqe_ref")

    MATCH(468, Ide_ref, "Ide_ref")

    MATCH(469, Vdc_flt, "Vdc_flt")

    MATCH(470, Esa, "Esa")

    MATCH(471, Esb, "Esb")

    MATCH(472, Esc, "Esc")

    MATCH(473, Theta, "Theta")

    MATCH(474, Sin_theta, "Sin_theta")

    MATCH(475, Cos_theta, "Cos_theta")

    MATCH(476, Theta_C, "Theta_C")

    MATCH(477, Sin_theta_C, "Sin_theta_C")

    MATCH(478, Sin_theta_C, "Sin_theta_C")

    MATCH(479, Fault_SW_float, "Fault_SW_float")


    XMATCH(480, DI11_input_float, "DI11_input_float")

    XMATCH(481, DI12_input_float, "DI12_input_float")

    XMATCH(482, DO1_output_float, "DO1_output_float")

    XMATCH(483, DO2_output_float, "DO2_output_float")

    XMATCH(484, DO3_output_float, "DO3_output_float")

    XMATCH(485, DO4_output_float, "DO4_output_float")

    XMATCH(486, DO5_output_float, "DO5_output_float")

    XMATCH(487, DO6_output_float, "DO6_output_float")

    XMATCH(488, DO7_output_float, "DO7_output_float")

    XMATCH(489, DO8_output_float, "DO8_output_float")


    XMATCH(490, DO9_output_float, "DO9_output_float")

    XMATCH(491, DO10_output_float, "DO10_output_float")

    XMATCH(492, DO11_output_float, "DO11_output_float")

    XMATCH(493, DO12_output_float, "DO12_output_float")

    XMATCH(494, DO13_output_float, "DO13_output_float")

    XMATCH(495, DO14_output_float, "DO14_output_float")

    XMATCH(496, DO15_output_float, "DO15_output_float")

    XMATCH(497, DO16_output_float, "DO16_output_float")

    XMATCH(498, Flag_gating_float, "Flag_gating_float")

    XMATCH(499, Flag_gating_inv_float, "Flag_gating_inv_float")
    {volatile long k = str_len;}
}

void BB_List_ctrl_select(void)
{
    int i = 0;

    EALLOW;
    MemCfgRegs.GSxMSEL.bit.MSEL_GS4 = 0;
    MemCfgRegs.GSxMSEL.bit.MSEL_GS5 = 0;
    EDIS;



    for( i = 0; i < BUF_CTRL_MAX; i++ )
    {
        select_list[i] = list[index_num[i]];
    }

    EALLOW;
    MemCfgRegs.GSxMSEL.bit.MSEL_GS4 = 1;
    MemCfgRegs.GSxMSEL.bit.MSEL_GS5 = 1;
    EDIS;
}
void Use_List()
{
    unsigned char _cnt = 0;
#if(0)
    _cnt = CTRL_POS;                  /*  CTRL  */
    index_num[_cnt++] = 0;            /*   1    */
    index_num[_cnt++] = 1;            /*   2    */
    index_num[_cnt++] = 2;            /*   3    */
    index_num[_cnt++] = 3;            /*   4    */
    index_num[_cnt++] = 4;            /*   5    */
    index_num[_cnt++] = 5;            /*   6    */
    index_num[_cnt++] = 6;            /*   7    */
    index_num[_cnt++] = 7;            /*   8    */
    index_num[_cnt++] = 8;            /*   9    */
    index_num[_cnt++] = 9;            /*   10   */
    index_num[_cnt++] = 10;           /*   11   */
    index_num[_cnt++] = 11;           /*   12   */
    index_num[_cnt++] = 12;           /*   13   */
    index_num[_cnt++] = 13;           /*   14   */
    index_num[_cnt++] = 14;           /*   15   */
    index_num[_cnt++] = 15;           /*   16   */
    index_num[_cnt++] = 16;           /*   17   */
    index_num[_cnt++] = 17;           /*   18   */
    index_num[_cnt++] = 18;           /*   19   */
    index_num[_cnt++] = 19;           /*   20   */
    index_num[_cnt++] = 20;           /*   21   */
    index_num[_cnt++] = 21;           /*   22   */
    index_num[_cnt++] = 22;           /*   23   */
    index_num[_cnt++] = 23;           /*   24   */
    index_num[_cnt++] = 24;           /*   25   */
    index_num[_cnt++] = 25;           /*   26   */
    index_num[_cnt++] = 26;           /*   27   */
    index_num[_cnt++] = 27;           /*   28   */
    index_num[_cnt++] = 28;           /*   29   */
    index_num[_cnt++] = 29;           /*   30   */
    index_num[_cnt++] = 427;          /*   31   */
    index_num[_cnt++] = 430;          /*   32   */
    index_num[_cnt++] = 430;          /*   33   */
    index_num[_cnt++] = 430;          /*   34   */
    index_num[_cnt++] = 430;          /*   35   */
    index_num[_cnt++] = 430;          /*   36   */
    index_num[_cnt++] = 430;          /*   37   */
    index_num[_cnt++] = 430;          /*   38   */
    index_num[_cnt++] = 430;          /*   39   */
    index_num[_cnt++] = 430;          /*   40   */
    index_num[_cnt++] = 427;          /*   41   */
    index_num[_cnt++] = 427;          /*   42   */
    index_num[_cnt++] = 427;          /*   43   */
    index_num[_cnt++] = 427;          /*   44   */
    index_num[_cnt++] = 430;          /*   45   */
    index_num[_cnt++] = 430;          /*   46   */
    index_num[_cnt++] = 430;          /*   47   */
    index_num[_cnt++] = 430;          /*   48   */
    index_num[_cnt++] = 430;          /*   49   */
    index_num[_cnt++] = 430;          /*   50   */
#else
    _cnt = CTRL_POS;                  /*  CTRL  */
    index_num[_cnt++] = 0;//318;          /*   1    */
    index_num[_cnt++] = 1;          /*   2    */
    index_num[_cnt++] = 2;          /*   3    */
    index_num[_cnt++] = 3;           /*   4    */
    index_num[_cnt++] = 4;          /*   5    */
//    index_num[_cnt++] = 240;//318;          /*   1    */
//    index_num[_cnt++] = 372;          /*   2    */
//    index_num[_cnt++] = 111;          /*   3    */
//    index_num[_cnt++] = 39;           /*   4    */
//    index_num[_cnt++] = 470;          /*   5    */
    index_num[_cnt++] = 471;          /*   6    */
    index_num[_cnt++] = 472;          /*   7    */
    index_num[_cnt++] = 6;            /*   8    */
    index_num[_cnt++] = 7;            /*   9    */
    index_num[_cnt++] = 8;            /*   10   */
    index_num[_cnt++] = 9;            /*   11   */
    index_num[_cnt++] = 212;          /*   12   */
    index_num[_cnt++] = 213;          /*   13   */
    index_num[_cnt++] = 214;          /*   14   */
    index_num[_cnt++] = 215;          /*   15   */
    index_num[_cnt++] = 15;           /*   16   */
    index_num[_cnt++] = 473;          /*   17   */
    index_num[_cnt++] = 115;          /*   18   */
    index_num[_cnt++] = 116;          /*   19   */
    index_num[_cnt++] = 117;          /*   20   */
    index_num[_cnt++] = 118;          /*   21   */
    index_num[_cnt++] = 119;          /*   22   */
    index_num[_cnt++] = 259;          /*   23   */
    index_num[_cnt++] = 260;          /*   24   */
    index_num[_cnt++] = 261;          /*   25   */
    index_num[_cnt++] = 156;          /*   26   */
    index_num[_cnt++] = 157;          /*   27   */
    index_num[_cnt++] = 158;          /*   28   */
    index_num[_cnt++] = 159;          /*   29   */
    index_num[_cnt++] = 240;          /*   30   */
    index_num[_cnt++] = 371;          /*   31   */
    index_num[_cnt++] = 370;          /*   32   */
    index_num[_cnt++] = 373;          /*   33   */
    index_num[_cnt++] = 375;          /*   34   */
    index_num[_cnt++] = 377;          /*   35   */
    index_num[_cnt++] = 432;          /*   36   */
    index_num[_cnt++] = 251;          /*   37   */
    index_num[_cnt++] = 252;          /*   38   */
    index_num[_cnt++] = 253;          /*   39   */
    index_num[_cnt++] = 254;          /*   40   */
    index_num[_cnt++] = 269;          /*   41   */
    index_num[_cnt++] = 268;          /*   42   */
    index_num[_cnt++] = 271;          /*   43   */
    index_num[_cnt++] = 270;          /*   44   */
    index_num[_cnt++] = 24;           /*   45   */
    index_num[_cnt++] = 25;           /*   46   */
    index_num[_cnt++] = 26;           /*   47   */
    index_num[_cnt++] = 27;           /*   48   */
    index_num[_cnt++] = 28;           /*   49   */
    index_num[_cnt++] = 29;           /*   50   */
#endif

    EALLOW;
    MemCfgRegs.GSxMSEL.bit.MSEL_GS4 = 1;
    MemCfgRegs.GSxMSEL.bit.MSEL_GS5 = 1;
    EDIS;
}


void BB_Send_ctrl_data_check()
{
#if 1
    Ta_real_con_float   = (float)Ta_real_con;
    Ta_con_float        = (float)Ta_con;

    Ta_real_inv_float   = (float)Ta_real_inv;
    Tb_real_inv_float   = (float)Tb_real_inv;
    Tc_real_inv_float   = (float)Tc_real_inv;


    Ta_inv_float        = (float)Ta_inv;
    Tb_inv_float        = (float)Tb_inv;
    Tc_inv_float        = (float)Tc_inv;

    Fault_SW_float      = (float)Fault_SW;

    rout_10ms_count_float     = (float)rout_10ms_count;
    Flag_charge_float         = (float)Flag_charge;
    MC_on_cnt_float           = (float)MC_on_cnt;

#endif
}

void BB_Send_ctrl_data()
{
    register float32 *rp_ctrl = &data.t_ctrl[0];
    register float32 **rp_list = &select_list[CTRL_POS];

    // Update ctrl Data List
    *rp_ctrl++ = **rp_list++; /* 0 */
    *rp_ctrl++ = **rp_list++; /* 1 */
    *rp_ctrl++ = **rp_list++; /* 2 */
    *rp_ctrl++ = **rp_list++; /* 3 */
    *rp_ctrl++ = **rp_list++; /* 4 */
    *rp_ctrl++ = **rp_list++; /* 5 */
    *rp_ctrl++ = **rp_list++; /* 6 */
    *rp_ctrl++ = **rp_list++; /* 7 */
    *rp_ctrl++ = **rp_list++; /* 8 */
    *rp_ctrl++ = **rp_list++; /* 9 */
    *rp_ctrl++ = **rp_list++; /* 10 */
    *rp_ctrl++ = **rp_list++; /* 11 */
    *rp_ctrl++ = **rp_list++; /* 12 */
    *rp_ctrl++ = **rp_list++; /* 13 */
    *rp_ctrl++ = **rp_list++; /* 14 */
    *rp_ctrl++ = **rp_list++; /* 15 */
    *rp_ctrl++ = **rp_list++; /* 16 */
    *rp_ctrl++ = **rp_list++; /* 17 */
    *rp_ctrl++ = **rp_list++; /* 18 */
    *rp_ctrl++ = **rp_list++; /* 19 */
    *rp_ctrl++ = **rp_list++; /* 20 */
    *rp_ctrl++ = **rp_list++; /* 21 */
    *rp_ctrl++ = **rp_list++; /* 22 */
    *rp_ctrl++ = **rp_list++; /* 23 */
    *rp_ctrl++ = **rp_list++; /* 24 */
    *rp_ctrl++ = **rp_list++; /* 25 */
    *rp_ctrl++ = **rp_list++; /* 26 */
    *rp_ctrl++ = **rp_list++; /* 27 */
    *rp_ctrl++ = **rp_list++; /* 28 */
    *rp_ctrl++ = **rp_list++; /* 29 */
    *rp_ctrl++ = **rp_list++; /* 30 */
    *rp_ctrl++ = **rp_list++; /* 31 */
    *rp_ctrl++ = **rp_list++; /* 32 */
    *rp_ctrl++ = **rp_list++; /* 33 */
    *rp_ctrl++ = **rp_list++; /* 34 */
    *rp_ctrl++ = **rp_list++; /* 35 */
    *rp_ctrl++ = **rp_list++; /* 36 */
    *rp_ctrl++ = **rp_list++; /* 37 */
    *rp_ctrl++ = **rp_list++; /* 38 */
    *rp_ctrl++ = **rp_list++; /* 39 */
    *rp_ctrl++ = **rp_list++; /* 40 */
    *rp_ctrl++ = **rp_list++; /* 41 */
    *rp_ctrl++ = **rp_list++; /* 42 */
    *rp_ctrl++ = **rp_list++; /* 43 */
    *rp_ctrl++ = **rp_list++; /* 44 */
    *rp_ctrl++ = **rp_list++; /* 45 */
    *rp_ctrl++ = **rp_list++; /* 46 */
    *rp_ctrl++ = **rp_list++; /* 47 */
    *rp_ctrl++ = **rp_list++; /* 48 */
    *rp_ctrl++ = **rp_list++; /* 49 */



    // Send updated data.
    Send_Ipc_Ctrl_Period(data.t_ctrl);
}
