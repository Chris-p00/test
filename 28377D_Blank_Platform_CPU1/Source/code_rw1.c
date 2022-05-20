//###############################################################################################################
// 파일명      : code_rw1.c
// 회사명      : G-Philos
// 작성날짜  : 2009.12.02
// 작성자      : S.H.Moon
// 수정날짜  : 2021.01.04
// 수정자      : Lee Sang Cheol
// 설명         : communication pointer define(float read/write code)
//###############################################################################################################


#include "Define.h"


void init_code_rw1()
{

#if 0
//  int tmp=0;
/*--------------------------------------*/
/*  flash ram read/write(float-type)    */
/*--------------------------------------*/
//  tmp = 0;

        data_ptr[0] = &dummy;                   // 0

//  tmp = WF_CONTROL_POS;

        data_ptr[1] = &Wc_CC;                   // 1
        data_ptr[2] = &dummy;                   // 2
        data_ptr[3] = &Alpha_CC;                // 3
        data_ptr[4] = &dummy;                   // 4
        data_ptr[5] = &dummy;                   // 5
        data_ptr[6] = &Wn_VC;                   // 6
        data_ptr[7] = &Zeta_VC;                 // 7
        data_ptr[8] = &dummy;                   // 8
        data_ptr[9] = &dummy;                   // 9
        data_ptr[10] = &dummy;                  // 10

        data_ptr[11] = &Kp_ang;                 // 11
        data_ptr[12] = &Ki_ang;                 // 12
        data_ptr[13] = &dummy;                  // 13
        data_ptr[14] = &dummy;                  // 14
        data_ptr[15] = &dummy;                  // 15
        data_ptr[16] = &dummy;                  // 16
        data_ptr[17] = &dummy;                  // 17
        data_ptr[18] = &dummy;                  // 18
//      data_ptr[19] = &Vdc_ref_set;            // 19
        data_ptr[20] = &dummy;                  // 20

        data_ptr[21] = &K_cc_ratio[CKP];        // 21
        data_ptr[22] = &K_cc_ratio[CKIT];       // 22
        data_ptr[23] = &K_cc_ratio[CKA];        // 23
        data_ptr[24] = &dummy;                  // 24
        data_ptr[25] = &dummy;                  // 25
        data_ptr[26] = &dummy;                  // 26
        data_ptr[27] = &dummy;                  // 27
        data_ptr[28] = &dummy;                  // 28
        data_ptr[29] = &dummy;                  // 29
        data_ptr[30] = &dummy;                  // 30

        data_ptr[31] = &dummy;                  // 31
        data_ptr[32] = &dummy;                  // 32
        data_ptr[33] = &dummy;                  // 33
        data_ptr[34] = &dummy;                  // 34
        data_ptr[35] = &dummy;                  // 35
        data_ptr[36] = &dummy;                  // 36
        data_ptr[37] = &dummy;                  // 37
        data_ptr[38] = &dummy;                  // 38
        data_ptr[39] = &dummy;                  // 39
        data_ptr[40] = &dummy;                  // 40

        data_ptr[41] = &dummy;                  // 41
        data_ptr[42] = &dummy;                  // 42
        data_ptr[43] = &dummy;                  // 43
        data_ptr[44] = &dummy;                  // 44
        data_ptr[45] = &dummy;                  // 45
        data_ptr[46] = &dummy;                  // 46
        data_ptr[47] = &dummy;                  // 47
        data_ptr[48] = &dummy;                  // 48
        data_ptr[49] = &dummy;                  // 49
        data_ptr[50] = &dummy;                  // 50

        data_ptr[51] = &Vdc_ref_con_set;        // 51   Vdc_ref_con
        data_ptr[52] = &Vdc_con_real_max;       // 52   Idc_ref = Vdc_con_real_max
        data_ptr[53] = &dummy;                  // 53
        data_ptr[54] = &dummy;                  // 54
        data_ptr[55] = &dummy;                  // 55
        data_ptr[56] = &dummy;                  // 56
        data_ptr[57] = &dummy;                  // 57
        data_ptr[58] = &dummy;                  // 58
        data_ptr[59] = &dummy;                  // 59
        data_ptr[60] = &dummy;                  // 60

//      data_ptr[61] = &Vdc_ref_inv;            // 61   Vdc_ref_inv
        data_ptr[62] = &dummy;                  // 62
        data_ptr[63] = &dummy;                  // 63
        data_ptr[64] = &dummy;                  // 64
        data_ptr[65] = &dummy;                  // 65
        data_ptr[66] = &dummy;                  // 66
        data_ptr[67] = &dummy;                  // 67
        data_ptr[68] = &dummy;                  // 68
        data_ptr[69] = &dummy;                  // 69
//      data_ptr[70] = &se_temp;                // 70

        data_ptr[71] = &dummy;                  // 71
        data_ptr[72] = &dummy;                  // 72
        data_ptr[73] = &dummy;                  // 73
        data_ptr[74] = &dummy;                  // 74
        data_ptr[75] = &dummy;                  // 75
        data_ptr[76] = &dummy;                  // 76
        data_ptr[77] = &dummy;                  // 77
        data_ptr[78] = &dummy;                  // 78
        data_ptr[79] = &dummy;                  // 79
        data_ptr[80] = &dummy;                  // 80

        data_ptr[81] = &dummy;                  // 81   restart enable
//      data_ptr[82] = &Vin_MC_ON_level;        // 82   Vin_MC_ON_level
        data_ptr[83] = &dummy;                  // 83
        data_ptr[84] = &dummy;                  // 84
        data_ptr[85] = &Idc_soft_ratio;         // 85   Acc. Time 0.03
        data_ptr[86] = &Vdc_soft_ratio;         // 86   Dec. Time 0.003
        data_ptr[87] = &dummy;                  // 87
        data_ptr[88] = &dummy;                  // 88
        data_ptr[89] = &dummy;                  // 89
        data_ptr[90] = &dummy;                  // 90

        data_ptr[91] = &Scale_Vin_input;        // 91
        data_ptr[92] = &Scale_Idc_input;        // 92
        data_ptr[93] = &Scale_A_ref_input;      // 93
        data_ptr[94] = &Scale_Vdc_input;        // 94
        data_ptr[95] = &Vin_offset;             // 95
        data_ptr[96] = &Idc_offset;             // 96
        data_ptr[97] = &A_ref_offset;           // 97
        data_ptr[98] = &Vdc_offset;             // 98
        data_ptr[99] = &dummy;                  // 99
        data_ptr[100] = &dummy;                 // 100

//  tmp = WF_ADC_POS;

        data_ptr[101] = &Scale_Ia_input;        // 101
        data_ptr[102] = &Scale_Ib_input;        // 102
        data_ptr[103] = &Scale_Ic_input;        // 103
        data_ptr[104] = &dummy;                 // 104
        data_ptr[105] = &Scale_Vdc_input;       // 105
        data_ptr[106] = &Scale_Eab_input;       // 106
        data_ptr[107] = &Scale_Ebc_input;       // 107
        data_ptr[108] = &Scale_Eca_input;       // 108
//      data_ptr[109] = &Scale_Heatsink_thermal_input;   // 109
        data_ptr[110] = &TOL_offset;            // 110

        data_ptr[111] = &dummy;                 // 111
        data_ptr[112] = &dummy;                 // 112
        data_ptr[113] = &dummy;                 // 113
        data_ptr[114] = &dummy;                 // 114
        data_ptr[115] = &dummy;                 // 115
        data_ptr[116] = &dummy;                 // 116
        data_ptr[117] = &dummy;                 // 117
        data_ptr[118] = &dummy;                 // 118
        data_ptr[119] = &dummy;                 // 119
        data_ptr[120] = &dummy;                 // 120

        data_ptr[121] = &dummy;                 // 121
        data_ptr[122] = &dummy;                 // 122
        data_ptr[123] = &dummy;                 // 123
        data_ptr[124] = &dummy;                 // 124
        data_ptr[125] = &dummy;                 // 125
        data_ptr[126] = &dummy;                 // 126
        data_ptr[127] = &dummy;                 // 127
        data_ptr[128] = &dummy;                 // 128
        data_ptr[129] = &dummy;                 // 129
        data_ptr[130] = &dummy;                 // 130

//  tmp = WF_DAC_POS;

//      data_ptr[131] = &DA_scale_input[0];     // 131
//      data_ptr[132] = &DA_scale_input[1];     // 132
//      data_ptr[133] = &DA_scale_input[2];     // 133
//      data_ptr[134] = &DA_scale_input[3];     // 134
//      data_ptr[135] = &DA_mid[0];             // 135
//      data_ptr[136] = &DA_mid[1];             // 136
//      data_ptr[137] = &DA_mid[2];             // 137
//      data_ptr[138] = &DA_mid[3];             // 138
        data_ptr[139] = &dummy;                 // 139
        data_ptr[140] = &dummy;                 // 140

//  tmp = WF_SYSTEM_POS;

        data_ptr[141] = &Pout_rate;             // 141
//      data_ptr[142] = &Va_rate;               // 142
        data_ptr[143] = &Ic_rate;               // 143
        data_ptr[144] = &Freq_rate;             // 144
        data_ptr[145] = &Lc_input;              // 145
        data_ptr[146] = &Cdc_input;             // 146
//      data_ptr[147] = &I_disp_rate;           // 147
        data_ptr[148] = &dummy;                 // 148
        data_ptr[149] = &dummy;                 // 149
        data_ptr[150] = &Freq_ctrl;             // 150

        data_ptr[151] = &T_dead_input;          // 151
        data_ptr[152] = &T_dead_comp_input;     // 152
        data_ptr[153] = &T_dead_onoff_input;    // 153
//      data_ptr[154] = &Icomp;                 // 154
        data_ptr[155] = &dummy;                 // 155
        data_ptr[156] = &dummy;                 // 156
        data_ptr[157] = &dummy;                 // 157
        data_ptr[158] = &dummy;                 // 158
        data_ptr[159] = &dummy;                 // 159
        data_ptr[160] = &dummy;                 // 160

//      data_ptr[161] = &OV_ratio_Vdc;          // 161
//      data_ptr[162] = &UV_ratio_Vdc;          // 162
//      data_ptr[163] = &MC_ratio;              // 163
        data_ptr[164] = &dummy;                 // 164
//      data_ptr[165] = &Ic_limit_ratio;        // 165
        data_ptr[166] = &dummy;                 // 166
        data_ptr[167] = &dummy;                 // 167
        data_ptr[168] = &dummy;                 // 168
        data_ptr[169] = &dummy;                 // 169
        data_ptr[170] = &dummy;                 // 170

//      data_ptr[171] = &Ip_ref_max;            // 171
        data_ptr[172] = &dummy;                 // 172 Over Frequency
        data_ptr[173] = &dummy;                 // 173
        data_ptr[174] = &dummy;                 // 174
        data_ptr[175] = &dummy;                 // 175
        data_ptr[176] = &dummy;                 // 176
        data_ptr[177] = &dummy;                 // 177
        data_ptr[178] = &dummy;                 // 178
        data_ptr[179] = &dummy;                 // 179
        data_ptr[180] = &dummy;                 // 180 A/D offset level

        data_ptr[181] = &Pin_rate;              // 181  Rated Power input
        data_ptr[182] = &Vin_rate;              // 182  Rated Volt input
        data_ptr[183] = &Idc_rate;              // 183  Rated Current input
        data_ptr[184] = &dummy;                 // 184
        data_ptr[185] = &dummy;                 // 185
        data_ptr[186] = &dummy;                 // 186
        data_ptr[187] = &dummy;                 // 187
        data_ptr[188] = &dummy;                 // 188
        data_ptr[189] = &dummy;                 // 189
        data_ptr[190] = &dummy;                 // 190

        data_ptr[191] = &dummy;                 // 191
        data_ptr[192] = &dummy;                 // 192
        data_ptr[193] = &dummy;                 // 193
        data_ptr[194] = &dummy;                 // 194
        data_ptr[195] = &dummy;                 // 195
        data_ptr[196] = &dummy;                 // 196
        data_ptr[197] = &dummy;                 // 197
        data_ptr[198] = &dummy;                 // 198
        data_ptr[199] = &dummy;                 // 199
        data_ptr[200] = &dummy;                 // 200

//  tmp = WF_TEST_POS;

//      data_ptr[201] = &Freq_sine_test;        // 201
//      data_ptr[202] = &Mag_sine_test;         // 202
//      data_ptr[203] = &T_sine_test;           // 203
//      data_ptr[204] = &Ta_test_set;           // 204
//      data_ptr[205] = &Tb_test_set;           // 205
//      data_ptr[206] = &Tc_test_set;           // 206
        data_ptr[207] = &dummy;                 // 207
        data_ptr[208] = &dummy;                 // 208
        data_ptr[209] = &dummy;                 // 209
        data_ptr[210] = &dummy;                 // 210

        data_ptr[211] = &dummy;                 // 211
        data_ptr[212] = &dummy;                 // 212
        data_ptr[213] = &dummy;                 // 213
        data_ptr[214] = &dummy;                 // 214
        data_ptr[215] = &dummy;                 // 215
        data_ptr[216] = &dummy;                 // 216
        data_ptr[217] = &dummy;                 // 217
        data_ptr[218] = &dummy;                 // 218
        data_ptr[219] = &dummy;                 // 219
        data_ptr[220] = &dummy;                 // 220

//  tmp = WF_SEQ_POS;

//      data_ptr[221] = &Time_Vdc_ramp;         // 221
        data_ptr[222] = &dummy;                 // 222
        data_ptr[223] = &Time_offset_wait;      // 223
        data_ptr[224] = &dummy;                 // 224
        data_ptr[225] = &dummy;                 // 225
        data_ptr[226] = &dummy;                 // 226
        data_ptr[227] = &dummy;                 // 227
        data_ptr[228] = &dummy;                 // 228
        data_ptr[229] = &dummy;                 // 229
        data_ptr[230] = &dummy;                 // 230

        data_ptr[231] = &dummy;                 // 231
        data_ptr[232] = &dummy;                 // 232
        data_ptr[233] = &dummy;                 // 233
        data_ptr[234] = &dummy;                 // 234
        data_ptr[235] = &dummy;                 // 235
        data_ptr[236] = &dummy;                 // 236
        data_ptr[237] = &dummy;                 // 237
        data_ptr[238] = &dummy;                 // 238
        data_ptr[239] = &dummy;                 // 239
        data_ptr[240] = &dummy;                 // 240

        data_ptr[241] = &dummy;                 // 241
        data_ptr[242] = &dummy;                 // 242
        data_ptr[243] = &dummy;                 // 243
        data_ptr[244] = &dummy;                 // 244
        data_ptr[245] = &dummy;                 // 245
        data_ptr[246] = &dummy;                 // 246
        data_ptr[247] = &dummy;                 // 247
        data_ptr[248] = &dummy;                 // 248
        data_ptr[249] = &dummy;                 // 249
        data_ptr[250] = &dummy;                 // 250

        data_ptr[251] = &dummy;                 // 251
        data_ptr[252] = &dummy;                 // 252
        data_ptr[253] = &dummy;                 // 253
        data_ptr[254] = &dummy;                 // 254
        data_ptr[255] = &dummy;                 // 255
        data_ptr[256] = &dummy;                 // 256
        data_ptr[257] = &dummy;                 // 257
        data_ptr[258] = &dummy;                 // 258
        data_ptr[259] = &dummy;                 // 259
        data_ptr[260] = &dummy;                 // 260

//  tmp = WF_FILTER_POS;

        data_ptr[261] = &FL_Vdc;                // 261
        data_ptr[262] = &FL_s_volt;             // 262
        data_ptr[263] = &FL_e_volt;             // 263
//      data_ptr[264] = &FL_voltage;            // 264
        data_ptr[265] = &dummy;                 // 265
        data_ptr[266] = &dummy;                 // 266
        data_ptr[267] = &dummy;                 // 267
        data_ptr[268] = &dummy;                 // 268
        data_ptr[269] = &dummy;                 // 269
        data_ptr[270] = &dummy;                 // 270

        data_ptr[271] = &FL_Vin;                    // 271
        data_ptr[272] = &FL_Idc;                    // 272
        data_ptr[273] = &FL_A_ref;                  // 273
        data_ptr[274] = &dummy;                 // 274
        data_ptr[275] = &dummy;                 // 275
        data_ptr[276] = &dummy;                 // 276
        data_ptr[277] = &dummy;                 // 277
        data_ptr[278] = &dummy;                 // 278
        data_ptr[279] = &dummy;                 // 279
        data_ptr[280] = &dummy;                 // 280

        data_ptr[281] = &dummy;                 // 281
        data_ptr[282] = &dummy;                 // 282
        data_ptr[283] = &dummy;                 // 283
        data_ptr[284] = &dummy;                 // 284
        data_ptr[285] = &dummy;                 // 285
        data_ptr[286] = &dummy;                 // 286
        data_ptr[287] = &dummy;                 // 287
        data_ptr[288] = &dummy;                 // 288
        data_ptr[289] = &dummy;                 // 289
        data_ptr[290] = &dummy;                 // 290

        data_ptr[291] = &dummy;                 // 291
        data_ptr[292] = &dummy;                 // 292
        data_ptr[293] = &dummy;                 // 293
        data_ptr[294] = &dummy;                 // 294
        data_ptr[295] = &dummy;                 // 295
        data_ptr[296] = &dummy;                 // 296
        data_ptr[297] = &dummy;                 // 297
        data_ptr[298] = &dummy;                 // 298
        data_ptr[299] = &dummy;                 // 299
        data_ptr[300] = &dummy;                 // 300

//  tmp = WF_REFERENCE_POS;

        data_ptr[301] = &dummy;                 // 301
        data_ptr[302] = &dummy;                 // 302
        data_ptr[303] = &dummy;                 // 303
        data_ptr[304] = &dummy;                 // 304
        data_ptr[305] = &dummy;                 // 305
        data_ptr[306] = &dummy;                 // 306
        data_ptr[307] = &dummy;                 // 307
        data_ptr[308] = &dummy;                 // 308
        data_ptr[309] = &dummy;                 // 309
        data_ptr[310] = &dummy;                 // 310

        data_ptr[311] = &dummy;                 // 311
        data_ptr[312] = &dummy;                 // 312
        data_ptr[313] = &dummy;                 // 313
        data_ptr[314] = &dummy;                 // 314
        data_ptr[315] = &dummy;                 // 315
        data_ptr[316] = &dummy;                 // 316
        data_ptr[317] = &dummy;                 // 317
        data_ptr[318] = &dummy;                 // 318
        data_ptr[319] = &dummy;                 // 319
        data_ptr[320] = &dummy;                 // 320

        data_ptr[321] = &dummy;                 /* 321  */
        data_ptr[322] = &dummy;                 /* 322  */
        data_ptr[323] = &dummy;                 /* 323  */
        data_ptr[324] = &dummy;                 /* 324  */
        data_ptr[325] = &dummy;                 /* 325  */
        data_ptr[326] = &dummy;                 /* 326  */
        data_ptr[327] = &dummy;                 /* 327  */
        data_ptr[328] = &dummy;                 /* 328  */
        data_ptr[329] = &dummy;                 /* 329  */
        data_ptr[330] = &dummy;                 /* 330  */

        data_ptr[331] = &dummy;                 /* 331  */
        data_ptr[332] = &dummy;                 /* 332  */
        data_ptr[333] = &dummy;                 /* 333  */
        data_ptr[334] = &dummy;                 /* 334  */
        data_ptr[335] = &dummy;                 /* 335  */
        data_ptr[336] = &dummy;                 /* 336  */
        data_ptr[337] = &dummy;                 /* 337  */
        data_ptr[338] = &dummy;                 /* 338  */
        data_ptr[339] = &dummy;                 /* 339  */
        data_ptr[340] = &dummy;                 /* 340  */

        data_ptr[341] = &dummy;                 /* 341  */
        data_ptr[342] = &dummy;                 /* 342  */
        data_ptr[343] = &dummy;                 /* 343  */
        data_ptr[344] = &dummy;                 /* 344  */
        data_ptr[345] = &dummy;                 /* 345  */
        data_ptr[346] = &dummy;                 /* 346  */
        data_ptr[347] = &dummy;                 /* 347  */
        data_ptr[348] = &dummy;                 /* 348  */
        data_ptr[349] = &dummy;                 /* 349  */
        data_ptr[350] = &dummy;                 /* 350  */

//  tmp = WF_MULTIPLE_POS;

        data_ptr[351] = &dummy;                 // 351
        data_ptr[352] = &dummy;                 /* 352  */
        data_ptr[353] = &dummy;                 /* 353  */
        data_ptr[354] = &dummy;                 /* 354  */
        data_ptr[355] = &dummy;                 /* 355  */
        data_ptr[356] = &dummy;                 /* 356  */
        data_ptr[357] = &dummy;                 /* 357  */
        data_ptr[358] = &dummy;                 /* 358  */
        data_ptr[359] = &dummy;                 /* 359  */
        data_ptr[360] = &dummy;                 /* 360  */

        data_ptr[361] = &dummy;                 /* 361  */
        data_ptr[362] = &dummy;                 /* 362  */
        data_ptr[363] = &dummy;                 /* 363  */
        data_ptr[364] = &dummy;                 /* 364  */
        data_ptr[365] = &dummy;                 /* 365  */
        data_ptr[366] = &dummy;                 /* 366  */
        data_ptr[367] = &dummy;                 /* 367  */
        data_ptr[368] = &dummy;                 /* 368  */
        data_ptr[369] = &dummy;                 /* 369  */
        data_ptr[370] = &dummy;                 /* 370  */

        data_ptr[371] = &dummy;                 /* 371  */
        data_ptr[372] = &dummy;                 /* 372  */
        data_ptr[373] = &dummy;                 /* 373  */
        data_ptr[374] = &dummy;                 /* 374  */
        data_ptr[375] = &dummy;                 /* 375  */
        data_ptr[376] = &dummy;                 /* 376  */
        data_ptr[377] = &dummy;                 /* 377  */
        data_ptr[378] = &dummy;                 /* 378  */
        data_ptr[379] = &dummy;                 /* 379  */
        data_ptr[380] = &dummy;                 /* 380  */

        data_ptr[381] = &dummy;                 /* 381  */
        data_ptr[382] = &dummy;                 /* 382  */
        data_ptr[383] = &dummy;                 /* 383  */
        data_ptr[384] = &dummy;                 /* 384  */
        data_ptr[385] = &dummy;                 /* 385  */
        data_ptr[386] = &dummy;                 /* 386  */
        data_ptr[387] = &dummy;                 /* 387  */
        data_ptr[388] = &dummy;                 /* 388  */
        data_ptr[389] = &dummy;                 /* 389  */
        data_ptr[390] = &dummy;                 /* 390  */

        data_ptr[391] = &dummy;                 /* 391  */
        data_ptr[392] = &dummy;                 /* 392  */
        data_ptr[393] = &dummy;                 /* 393  */
        data_ptr[394] = &dummy;                 /* 394  */
        data_ptr[395] = &dummy;                 /* 395  */
        data_ptr[396] = &dummy;                 /* 396  */
        data_ptr[397] = &dummy;                 /* 397  */
        data_ptr[398] = &dummy;                 /* 398  */
        data_ptr[399] = &dummy;                 /* 399  */
        data_ptr[400] = &dummy;                 /* 400  */
#endif

#if 1
        data_ptr[401] = &Scale_Vin_ratio;       /* 401  */
        data_ptr[402] = &Scale_Idc_ratio;       /* 402  */
        data_ptr[403] = &Scale_A_ref_ratio;     /* 403  */
        data_ptr[404] = &Scale_Vdc_ratio;       /* 404  */
        data_ptr[405] = &Scale_Esa_ratio;       /* 405  */
        data_ptr[406] = &Scale_Esb_ratio;       /* 405  */
        data_ptr[407] = &Scale_Esc_ratio;       /* 406  */
        data_ptr[408] = &Scale_Ia_ratio;        /* 408  */
        data_ptr[409] = &Scale_Ib_ratio;        /* 409  */
        data_ptr[410] = &Scale_Ic_ratio;        /* 410  */

        data_ptr[411] = &Vin_offset_input;          /* 411  */
        data_ptr[412] = &Idc_offset_input;          /* 412  */
        data_ptr[413] = &A_ref_offset_input;        /* 413  */
        data_ptr[414] = &Vdc_offset_input;          /* 414  */
        data_ptr[415] = &Esa_offset_comp_input;     /* 415  */
        data_ptr[416] = &Esb_offset_comp_input;     /* 416  */
        data_ptr[417] = &Esc_offset_comp_input;     /* 417  */
        data_ptr[418] = &Ia_offset_comp_input;      /* 418  */
        data_ptr[419] = &Ib_offset_comp_input;      /* 419  */
        data_ptr[420] = &Ic_offset_comp_input;      /* 420  */

        data_ptr[421] = &Kp_Vdc_con_ratio;      /* 421  */
        data_ptr[422] = &Ki_Vdc_con_ratio;      /* 422  */
        data_ptr[421] = &Kp_Idc_con_ratio;      /* 421  */
        data_ptr[422] = &Ki_Idc_con_ratio;      /* 422  */
        data_ptr[423] = &Kp_Vdc_ratio;          /* 423  */
        data_ptr[424] = &Ki_Vdc_inv_ratio;      /* 424  */
        data_ptr[425] = &Kp_Ia_ratio;           /* 425  */
        data_ptr[426] = &Ki_Ia_ratio;           /* 426  */
        data_ptr[427] = &dummy;                 /* 427  */
        data_ptr[428] = &dummy;                 /* 428  */
        data_ptr[429] = &dummy;                 /* 429  */
        data_ptr[430] = &dummy;                 /* 430  */

        data_ptr[431] = &OP_MODE;               /* 431  */
        data_ptr[432] = &dummy;                 /* 432  */
        data_ptr[433] = &dummy;                 /* 433  */
        data_ptr[434] = &dummy;                 /* 434  */
        data_ptr[435] = &dummy;                 /* 435  */
        data_ptr[436] = &dummy;                 /* 436  */
        data_ptr[437] = &dummy;                 /* 437  */
        data_ptr[438] = &dummy;                 /* 438  */
        data_ptr[439] = &dummy;                 /* 439  */
        data_ptr[440] = &dummy;                 /* 440  */

        data_ptr[441] = &Flag_Act_islanding_input;  /* 441  */
        data_ptr[442] = &dummy;                     /* 442  */
        data_ptr[443] = &dummy;                     /* 443  */
        data_ptr[444] = &dummy;                     /* 444  */
        data_ptr[445] = &dummy;                     /* 445  */
        data_ptr[446] = &dummy;                     /* 446  */
        data_ptr[447] = &dummy;                     /* 447  */
        data_ptr[448] = &dummy;                     /* 448  */
        data_ptr[449] = &dummy;                     /* 449  */
        data_ptr[450] = &dummy;                     /* 450  */

        data_ptr[451] = &Flag_scia_cpu1_cpu2;       /* 451  */ //Baud rate
        data_ptr[452] = &dummy;                     /* 452  */ //Station No.
        data_ptr[453] = &dummy;                     /* 453  */ //MODE Select
        data_ptr[454] = &dummy;                     /* 454  */
        data_ptr[455] = &dummy;                     /* 455  */
        data_ptr[456] = &dummy;                     /* 456  */
        data_ptr[457] = &dummy;                     /* 457  */
        data_ptr[458] = &dummy;                     /* 458  */
        data_ptr[459] = &dummy;                     /* 459  */
        data_ptr[460] = &dummy;                     /* 460  */

        data_ptr[461] = &dummy;                     /* 461  */
        data_ptr[462] = &dummy;                     /* 462  */
        data_ptr[463] = &dummy;                     /* 463  */
        data_ptr[464] = &dummy;                     /* 464  */
        data_ptr[465] = &dummy;                     /* 465  */
        data_ptr[466] = &dummy;                     /* 466  */
        data_ptr[467] = &dummy;                     /* 467  */
        data_ptr[468] = &dummy;                     /* 468  */
        data_ptr[469] = &dummy;                     /* 469  */
        data_ptr[470] = &dummy;                     /* 470  */

        data_ptr[471] = &dummy;                     /* 471  */ // Trace Enable
        data_ptr[472] = &dummy;                     /* 472  */ // Trace Code Enable
        data_ptr[473] = &dummy;                     /* 473  */ // Trace Data Read
        data_ptr[474] = &dummy;                     /* 474  */ // Trace Restart
        data_ptr[475] = &dummy;                     /* 475  */ // Download Trace-Data
        data_ptr[476] = &dummy;                     /* 476  */ // Remain Ratio
        data_ptr[477] = &dummy;                     /* 477  */ // #0 Trace Cycle
        data_ptr[478] = &dummy;                     /* 478  */ // #1 Trace Cycle
        data_ptr[479] = &dummy;                     /* 479  */ // #2 Trace Cycle
        data_ptr[480] = &dummy;                     /* 480  */

        data_ptr[481] = &dummy;                     /* 481  */
        data_ptr[482] = &dummy;                     /* 482  */
        data_ptr[483] = &dummy;                     /* 483  */
        data_ptr[484] = &dummy;                     /* 484  */
        data_ptr[485] = &dummy;                     /* 485  */
        data_ptr[486] = &dummy;                     /* 486  */
        data_ptr[487] = &dummy;                     /* 487  */
        data_ptr[488] = &dummy;                     /* 488  */
        data_ptr[489] = &dummy;                     /* 489  */
        data_ptr[490] = &dummy;                     /* 490  */

        data_ptr[491] = &dummy;                     /* 491  */
        data_ptr[492] = &dummy;                     /* 492  */
        data_ptr[493] = &dummy;                     /* 493  */
        data_ptr[494] = &dummy;                     /* 494  */
        data_ptr[495] = &dummy;                     /* 495  */
        data_ptr[494] = &dummy;                     /* 494  */
        data_ptr[495] = &dummy;                     /* 495  */
        data_ptr[496] = &dummy;                     /* 496  */
        data_ptr[497] = &dummy;                     /* 497  */
        data_ptr[498] = &dummy;                     /* 498  */
        data_ptr[499] = &dummy;                     /* 499  */
        data_ptr[500] = &dummy;                     /* 500  */
#endif
}




