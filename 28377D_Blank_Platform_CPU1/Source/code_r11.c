//###############################################################################################################
// 파일명      : code_r11.c
// 회사명      : G-Philos
// 작성날짜  : 2009.12.02
// 작성자      : S.H.Moon
// 수정날짜  : 2021.01.04
// 수정자      : Lee Sang Cheol
// 설명         : communication pointer define(float read code(1/2))
//###############################################################################################################

#include "Define.h"

void init_code_r11()
{

#if 1
//  int tmp=1001;
/*--------------------------------------*/
/*  read(float-type)                    */
/*--------------------------------------*/
//  tmp = RF_CURRENT_POS;

        data_ptr[1001] = &Ia;                   // 1001     // for control
        data_ptr[1002] = &Ib;                   // 1002
        data_ptr[1003] = &Ic;                   // 1003
        data_ptr[1004] = &Ia_flt;               // 1004
        data_ptr[1005] = &Ids;                  // 1005
        data_ptr[1006] = &Iqs;                  // 1006
        data_ptr[1007] = &Ide;                  // 1007
        data_ptr[1008] = &Iqe;                  // 1008
//      data_ptr[1009] = &Ide_avg;              // 1009
//      data_ptr[1010] = &Iqe_avg;              // 1010     // for monitoring
                 
        data_ptr[1011] = &Ia_rms;               // 1011
        data_ptr[1012] = &Ib_rms;               // 1012
        data_ptr[1013] = &Ic_rms;               // 1013
        data_ptr[1014] = &dummy;                // 1014
        data_ptr[1015] = &dummy;                // 1015
        data_ptr[1016] = &dummy;                // 1016
        data_ptr[1017] = &dummy;                // 1017
        data_ptr[1018] = &Ia_abs;               // 1018
        data_ptr[1019] = &Ib_abs;               // 1019
        data_ptr[1020] = &Ic_abs;               // 1020
                 
        data_ptr[1021] = &Ia_offset;            // 1021
        data_ptr[1022] = &Ib_offset;            // 1022
        data_ptr[1023] = &dummy;                // 1023
        data_ptr[1024] = &dummy;                // 1024
        data_ptr[1025] = &dummy;                // 1025
        data_ptr[1026] = &dummy;                // 1026
        data_ptr[1027] = &dummy;                // 1027
        data_ptr[1028] = &dummy;                // 1028
        data_ptr[1029] = &dummy;                // 1029
        data_ptr[1030] = &dummy;                // 1030
                 
        data_ptr[1031] = &Vin_flt_avg;          // 1031
        data_ptr[1032] = &Idc_flt_avg;          // 1032
        data_ptr[1033] = &Pin;                  // 1033
        data_ptr[1034] = &dummy;                // 1034
        data_ptr[1035] = &dummy;                // 1035
        data_ptr[1036] = &dummy;                // 1036
        data_ptr[1037] = &Idc_ref;              // 1037
        data_ptr[1038] = &dummy;                // 1038
        data_ptr[1039] = &dummy;                // 1039
        data_ptr[1040] = &dummy;                // 1040
                 
        data_ptr[1041] = &Pout;                 // 1041
        data_ptr[1042] = &dummy;                // 1042
        data_ptr[1043] = &dummy;                // 1043
        data_ptr[1044] = &dummy;                // 1044
        data_ptr[1045] = &dummy;                // 1045
        data_ptr[1046] = &dummy;                // 1046
        data_ptr[1047] = &dummy;                // 1047
        data_ptr[1048] = &dummy;                // 1048
        data_ptr[1049] = &dummy;                // 1049
        data_ptr[1050] = &dummy;                // 1050
                 
        data_ptr[1051] = &dummy;                // 1051
        data_ptr[1052] = &dummy;                // 1052
        data_ptr[1053] = &dummy;                // 1053
        data_ptr[1054] = &dummy;                // 1054
        data_ptr[1055] = &dummy;                // 1055
        data_ptr[1056] = &dummy;                // 1056
        data_ptr[1057] = &dummy;                // 1057
        data_ptr[1058] = &dummy;                // 1058
        data_ptr[1059] = &dummy;                // 1059
        data_ptr[1060] = &dummy;                // 1060
                 
        data_ptr[1061] = &dummy;                // 1061
        data_ptr[1062] = &dummy;                // 1062
        data_ptr[1063] = &dummy;                // 1063
        data_ptr[1064] = &dummy;                // 1064
        data_ptr[1065] = &dummy;                // 1065
        data_ptr[1066] = &dummy;                // 1066
        data_ptr[1067] = &dummy;                // 1067
        data_ptr[1068] = &dummy;                // 1068
        data_ptr[1069] = &dummy;                // 1069
        data_ptr[1070] = &dummy;                // 1070
                 
        data_ptr[1071] = &dummy;                // 1071
        data_ptr[1072] = &dummy;                // 1072
        data_ptr[1073] = &dummy;                // 1073
        data_ptr[1074] = &dummy;                // 1074
        data_ptr[1075] = &dummy;                // 1075
        data_ptr[1076] = &dummy;                // 1076
        data_ptr[1077] = &dummy;                // 1077
        data_ptr[1078] = &dummy;                // 1078
        data_ptr[1079] = &dummy;                // 1079
        data_ptr[1080] = &dummy;                // 1080
                 
        data_ptr[1081] = &dummy;                // 1081
        data_ptr[1082] = &dummy;                // 1082
        data_ptr[1083] = &dummy;                // 1083
        data_ptr[1084] = &dummy;                // 1084
        data_ptr[1085] = &dummy;                // 1085
        data_ptr[1086] = &dummy;                // 1086
        data_ptr[1087] = &dummy;                // 1087
        data_ptr[1088] = &dummy;                // 1088
        data_ptr[1089] = &dummy;                // 1089
        data_ptr[1090] = &dummy;                // 1090
                 
        data_ptr[1091] = &dummy;                // 1091
        data_ptr[1092] = &dummy;                // 1092
        data_ptr[1093] = &dummy;                // 1093
        data_ptr[1094] = &dummy;                // 1094
        data_ptr[1095] = &dummy;                // 1095
        data_ptr[1096] = &dummy;                // 1096
        data_ptr[1097] = &dummy;                // 1097
        data_ptr[1098] = &dummy;                // 1098
        data_ptr[1099] = &dummy;                // 1099
        data_ptr[1100] = &dummy;                // 1100
                 
        data_ptr[1101] = &dummy;                // 1101
        data_ptr[1102] = &dummy;                // 1102
        data_ptr[1103] = &dummy;                // 1103
        data_ptr[1104] = &dummy;                // 1104
        data_ptr[1105] = &dummy;                // 1105
        data_ptr[1106] = &dummy;                // 1106
        data_ptr[1107] = &dummy;                // 1107
        data_ptr[1108] = &dummy;                // 1108
        data_ptr[1109] = &dummy;                // 1109
        data_ptr[1110] = &dummy;                // 1110
                 
        data_ptr[1111] = &dummy;                // 1111
        data_ptr[1112] = &dummy;                // 1112
        data_ptr[1113] = &dummy;                // 1113
        data_ptr[1114] = &dummy;                // 1114
        data_ptr[1115] = &dummy;                // 1115
        data_ptr[1116] = &dummy;                // 1116
        data_ptr[1117] = &dummy;                // 1117
        data_ptr[1118] = &dummy;                // 1118
        data_ptr[1119] = &dummy;                // 1119
        data_ptr[1120] = &dummy;                // 1120

        data_ptr[1121] = &Ide_ref;              // 1121
        data_ptr[1122] = &Iqe_ref;              // 1122
//      data_ptr[1123] = &Ids_ref;              // 1123
//      data_ptr[1124] = &Iqs_ref;              // 1124
//      data_ptr[1125] = &Ia_ref;               // 1125
        data_ptr[1126] = &dummy;                // 1126
        data_ptr[1127] = &dummy;                // 1127
        data_ptr[1128] = &dummy;                // 1128
        data_ptr[1129] = &dummy;                // 1129
        data_ptr[1130] = &dummy;                // 1130
                 
        data_ptr[1131] = &Err_Ide;              // 1131
        data_ptr[1132] = &Err_Iqe;              // 1132
//      data_ptr[1133] = &Err_Ia;               // 1133
//      data_ptr[1134] = &Ia_integ;             // 1134
//      data_ptr[1135] = &Ia_out;               /* 1135 */
        data_ptr[1136] = &dummy;                /* 1136 */
        data_ptr[1137] = &dummy;                /* 1137 */
        data_ptr[1138] = &dummy;                /* 1138 */
        data_ptr[1139] = &dummy;                /* 1139 */
        data_ptr[1140] = &dummy;                /* 1140 */
                 
//      data_ptr[1141] = &Err_Vas;              /* 1141 */
//      data_ptr[1142] = &X1;                   /* 1142 */
//      data_ptr[1143] = &X2;                   /* 1143 */
//      data_ptr[1144] = &Y1;                   /* 1144 */
//      data_ptr[1145] = &Y2;                   /* 1145 */
//      data_ptr[1146] = &Y3;                   /* 1146 */
//      data_ptr[1147] = &Ias_real;             /* 1147 */
//      data_ptr[1148] = &Vas_flt;              /* 1148 */
        data_ptr[1149] = &dummy;                /* 1149 */
        data_ptr[1150] = &dummy;                /* 1150 */
                 
        data_ptr[1151] = &dummy;                // 1151
        data_ptr[1152] = &dummy;                // 1152
        data_ptr[1153] = &dummy;                // 1153
        data_ptr[1154] = &dummy;                // 1154
        data_ptr[1155] = &dummy;                // 1155
        data_ptr[1156] = &dummy;                // 1156
        data_ptr[1157] = &dummy;                // 1157
        data_ptr[1158] = &dummy;                // 1158
        data_ptr[1159] = &dummy;                /* 1159 */
        data_ptr[1160] = &dummy;                // 1160
                 
        data_ptr[1161] = &dummy;                // 1161
        data_ptr[1162] = &dummy;                // 1162
        data_ptr[1163] = &dummy;                // 1163
        data_ptr[1164] = &dummy;                // 1164
        data_ptr[1165] = &dummy;                // 1165
        data_ptr[1166] = &dummy;                // 1166
        data_ptr[1167] = &dummy;                // 1167
        data_ptr[1168] = &dummy;                // 1168
        data_ptr[1169] = &dummy;                // 1169
        data_ptr[1170] = &dummy;                // 1170
                 
        data_ptr[1171] = &dummy;                // 1171
        data_ptr[1172] = &dummy;                // 1172
        data_ptr[1173] = &dummy;                // 1173
        data_ptr[1174] = &dummy;                // 1174
        data_ptr[1175] = &dummy;                // 1175
        data_ptr[1176] = &dummy;                // 1176
        data_ptr[1177] = &dummy;                // 1177
        data_ptr[1178] = &dummy;                // 1178
        data_ptr[1179] = &dummy;                // 1179
        data_ptr[1180] = &dummy;                // 1180
                 
        data_ptr[1181] = &dummy;                /* 1181 */
        data_ptr[1182] = &dummy;                /* 1182 */
        data_ptr[1183] = &dummy;                /* 1183 */
        data_ptr[1184] = &dummy;                /* 1184 */
        data_ptr[1185] = &dummy;                /* 1185 */
        data_ptr[1186] = &dummy;                /* 1186 */
        data_ptr[1187] = &dummy;                /* 1187 */
        data_ptr[1188] = &dummy;                /* 1188 */
        data_ptr[1189] = &dummy;                /* 1189 */
        data_ptr[1190] = &dummy;                /* 1190 */
                 
        data_ptr[1191] = &dummy;                /* 1191 */
        data_ptr[1192] = &dummy;                /* 1192 */
        data_ptr[1193] = &dummy;                /* 1193 */
        data_ptr[1194] = &dummy;                /* 1194 */
        data_ptr[1195] = &dummy;                /* 1195 */
        data_ptr[1196] = &dummy;                /* 1196 */
        data_ptr[1197] = &dummy;                /* 1197 */
        data_ptr[1198] = &dummy;                /* 1198 */
        data_ptr[1199] = &dummy;                /* 1199 */
        data_ptr[1200] = &dummy;                /* 1200 */
                 
//      data_ptr[1201] = &AD_ext1;              // 1201
//      data_ptr[1202] = &Thermal_avg;  // 1202
        data_ptr[1203] = &dummy;                // 1203
        data_ptr[1204] = &dummy;                // 1204
        data_ptr[1205] = &dummy;                // 1205
        data_ptr[1206] = &dummy;                // 1206
        data_ptr[1207] = &dummy;                // 1207
        data_ptr[1208] = &dummy;                // 1208
        data_ptr[1209] = &dummy;                // 1209
        data_ptr[1210] = &dummy;                // 1210
                 
        data_ptr[1211] = &dummy;                // 1211
        data_ptr[1212] = &dummy;                // 1212
        data_ptr[1213] = &dummy;                // 1213
        data_ptr[1214] = &dummy;                // 1214
        data_ptr[1215] = &dummy;                // 1215
        data_ptr[1216] = &dummy;                // 1216
        data_ptr[1217] = &dummy;                // 1217
        data_ptr[1218] = &dummy;                // 1218
        data_ptr[1219] = &dummy;                // 1219
        data_ptr[1220] = &dummy;                // 1220
                 
        data_ptr[1221] = &dummy;                /* 1221 */
        data_ptr[1222] = &dummy;                /* 1222 */
        data_ptr[1223] = &dummy;                /* 1223 */
        data_ptr[1224] = &dummy;                /* 1224 */
        data_ptr[1225] = &dummy;                /* 1225 */
        data_ptr[1226] = &dummy;                /* 1226 */
        data_ptr[1227] = &dummy;                /* 1227 */
        data_ptr[1228] = &dummy;                /* 1228 */
        data_ptr[1229] = &dummy;                /* 1229 */
        data_ptr[1230] = &dummy;                /* 1230 */
                 
        data_ptr[1231] = &dummy;                // 1231
        data_ptr[1232] = &dummy;                // 1232
        data_ptr[1233] = &dummy;                // 1233
        data_ptr[1234] = &dummy;                // 1234
        data_ptr[1235] = &dummy;                // 1235
        data_ptr[1236] = &dummy;                // 1236
        data_ptr[1237] = &dummy;                // 1237
        data_ptr[1238] = &dummy;                /* 1238 */
        data_ptr[1239] = &dummy;                /* 1239 */
        data_ptr[1240] = &dummy;                /* 1240 */
                 
        data_ptr[1241] = &dummy;                /* 1241 */
        data_ptr[1242] = &dummy;                /* 1242 */
        data_ptr[1243] = &dummy;                /* 1243 */
        data_ptr[1244] = &dummy;                /* 1244 */
        data_ptr[1245] = &dummy;                /* 1245 */
        data_ptr[1246] = &dummy;                /* 1246 */
        data_ptr[1247] = &dummy;                /* 1247 */
        data_ptr[1248] = &dummy;                /* 1248 */
        data_ptr[1249] = &dummy;                // 1249
        data_ptr[1250] = &dummy;                // 1250
                 
        data_ptr[1251] = &dummy;                // 1251     // for MMI
        data_ptr[1252] = &dummy;                // 1252
        data_ptr[1253] = &dummy;                // 1253
        data_ptr[1254] = &dummy;                // 1254
        data_ptr[1255] = &dummy;                // 1255
        data_ptr[1256] = &dummy;                // 1256
        data_ptr[1257] = &dummy;                // 1257
        data_ptr[1258] = &dummy;                // 1258
        data_ptr[1259] = &dummy;                // 1259
        data_ptr[1260] = &dummy;                // 1260
                 
        data_ptr[1261] = &dummy;                // 1261
        data_ptr[1262] = &dummy;                // 1262
        data_ptr[1263] = &dummy;                // 1263
        data_ptr[1264] = &dummy;                // 1264
        data_ptr[1265] = &dummy;                // 1265
        data_ptr[1266] = &dummy;                // 1266
        data_ptr[1267] = &dummy;                // 1267
        data_ptr[1268] = &dummy;                // 1268
        data_ptr[1269] = &dummy;                // 1269
        data_ptr[1270] = &dummy;                // 1270
                 
        data_ptr[1271] = &dummy;                // 1271
        data_ptr[1272] = &dummy;                // 1272
        data_ptr[1273] = &dummy;                // 1273
        data_ptr[1274] = &dummy;                // 1274
        data_ptr[1275] = &dummy;                // 1275
        data_ptr[1276] = &dummy;                // 1276
        data_ptr[1277] = &dummy;                // 1277
        data_ptr[1278] = &dummy;                // 1278
        data_ptr[1279] = &dummy;                // 1279
        data_ptr[1280] = &dummy;                // 1280
                 
        data_ptr[1281] = &dummy;                /* 1281 */
        data_ptr[1282] = &dummy;                /* 1282 */
        data_ptr[1283] = &dummy;                /* 1283 */
        data_ptr[1284] = &dummy;                /* 1284 */
        data_ptr[1285] = &dummy;                /* 1285 */
        data_ptr[1286] = &dummy;                /* 1286 */
        data_ptr[1287] = &dummy;                /* 1287 */
        data_ptr[1288] = &dummy;                /* 1288 */
        data_ptr[1289] = &dummy;                /* 1289 */
        data_ptr[1290] = &dummy;                /* 1290 */
                 
        data_ptr[1291] = &dummy;                /* 1291 */
        data_ptr[1292] = &dummy;                /* 1292 */
        data_ptr[1293] = &dummy;                /* 1293 */
        data_ptr[1294] = &dummy;                /* 1294 */
        data_ptr[1295] = &dummy;                /* 1295 */
        data_ptr[1296] = &dummy;                /* 1296 */
        data_ptr[1297] = &dummy;                /* 1297 */
        data_ptr[1298] = &dummy;                /* 1298 */
        data_ptr[1299] = &dummy;                /* 1299 */
        data_ptr[1300] = &dummy;                /* 1300 */
                 
        data_ptr[1301] = &dummy;                // 1301
        data_ptr[1302] = &dummy;                // 1302
        data_ptr[1303] = &dummy;                // 1303
        data_ptr[1304] = &dummy;                /* 1304 */
        data_ptr[1305] = &dummy;                /* 1305 */
        data_ptr[1306] = &dummy;                /* 1306 */
        data_ptr[1307] = &dummy;                /* 1307 */
        data_ptr[1308] = &dummy;                /* 1308 */
        data_ptr[1309] = &dummy;                /* 1309 */
        data_ptr[1310] = &dummy;                // 1310
                 
        data_ptr[1311] = &dummy;                /* 1311 */
        data_ptr[1312] = &dummy;                /* 1312 */
        data_ptr[1313] = &dummy;                /* 1313 */
        data_ptr[1314] = &dummy;                /* 1314 */
        data_ptr[1315] = &dummy;                /* 1315 */
        data_ptr[1316] = &dummy;                /* 1316 */
        data_ptr[1317] = &dummy;                /* 1317 */
        data_ptr[1318] = &dummy;                /* 1318 */
        data_ptr[1319] = &dummy;                /* 1319 */
        data_ptr[1320] = &dummy;                /* 1320 */
                 
        data_ptr[1321] = &dummy;                // 1321
        data_ptr[1322] = &dummy;                // 1322
        data_ptr[1323] = &dummy;                // 1323
        data_ptr[1324] = &dummy;                // 1324
        data_ptr[1325] = &dummy;                // 1325
        data_ptr[1326] = &dummy;                // 1326
        data_ptr[1327] = &dummy;                // 1327
        data_ptr[1328] = &dummy;                /* 1328 */
        data_ptr[1329] = &dummy;                /* 1329 */
        data_ptr[1330] = &dummy;                /* 1330 */
                 
        data_ptr[1331] = &dummy;                /* 1331 */
        data_ptr[1332] = &dummy;                /* 1332 */
        data_ptr[1333] = &dummy;                /* 1333 */
        data_ptr[1334] = &dummy;                /* 1334 */
        data_ptr[1335] = &dummy;                /* 1335 */
        data_ptr[1336] = &dummy;                /* 1336 */
        data_ptr[1337] = &dummy;                /* 1337 */
        data_ptr[1338] = &dummy;                /* 1338 */
        data_ptr[1339] = &dummy;                // 1339
        data_ptr[1340] = &dummy;                // 1340
                 
        data_ptr[1341] = &dummy;                /* 1341 */
        data_ptr[1342] = &dummy;                /* 1342 */
        data_ptr[1343] = &dummy;                /* 1343 */
        data_ptr[1344] = &dummy;                /* 1344 */
        data_ptr[1345] = &dummy;                /* 1345 */
        data_ptr[1346] = &dummy;                /* 1346 */
        data_ptr[1347] = &dummy;                /* 1347 */
        data_ptr[1348] = &dummy;                /* 1348 */
        data_ptr[1349] = &dummy;                /* 1349 */
        data_ptr[1350] = &dummy;                /* 1350 */
                 
        data_ptr[1351] = &Ip_ref;               // 1351         // voltage control
        data_ptr[1352] = &Ip_ref_real;          // 1352
        data_ptr[1353] = &Ip_ref_out;           // 1353
        data_ptr[1354] = &Ip_ref_integ;         // 1354
        data_ptr[1355] = &Ip_ref_ff;            // 1355
        data_ptr[1356] = &Vdc_inv_real;         // 1356
        data_ptr[1357] = &Vdc_inv_out;          // 1357
        data_ptr[1358] = &Vdc_inv_integ;        // 1358
        data_ptr[1359] = &Vdc_inv_ff;           // 1359
        data_ptr[1360] = &Ip_ref_real_max;      // 1360
                 
        data_ptr[1361] = &dummy;                /* 1361 */
        data_ptr[1362] = &dummy;                /* 1362 */
        data_ptr[1363] = &dummy;                /* 1363 */
        data_ptr[1364] = &dummy;                /* 1364 */
        data_ptr[1365] = &dummy;                /* 1365 */
        data_ptr[1366] = &dummy;                /* 1366 */
        data_ptr[1367] = &dummy;                /* 1367 */
        data_ptr[1368] = &dummy;                /* 1368 */
        data_ptr[1369] = &dummy;                /* 1369 */
        data_ptr[1370] = &dummy;                /* 1370 */
                 
        data_ptr[1371] = &dummy;                // 1371
        data_ptr[1372] = &dummy;                // 1372
        data_ptr[1373] = &dummy;                // 1373
        data_ptr[1374] = &dummy;                // 1374
        data_ptr[1375] = &dummy;                // 1375
        data_ptr[1376] = &dummy;                // 1376
        data_ptr[1377] = &dummy;                // 1377
        data_ptr[1378] = &dummy;                // 1378
        data_ptr[1379] = &dummy;                // 1379
        data_ptr[1380] = &dummy;                // 1380
                 
        data_ptr[1381] = &dummy;                // 1381
        data_ptr[1382] = &dummy;                // 1382
        data_ptr[1383] = &dummy;                // 1383
        data_ptr[1384] = &dummy;                // 1384
        data_ptr[1385] = &dummy;                // 1385
        data_ptr[1386] = &dummy;                // 1386
        data_ptr[1387] = &dummy;                // 1387
        data_ptr[1388] = &dummy;                // 1388
        data_ptr[1389] = &dummy;                // 1389
        data_ptr[1390] = &dummy;                // 1390
                 
        data_ptr[1391] = &dummy;                // 1391
        data_ptr[1392] = &dummy;                // 1392
        data_ptr[1393] = &dummy;                // 1393
        data_ptr[1394] = &dummy;                // 1394
        data_ptr[1395] = &dummy;                // 1395
        data_ptr[1396] = &dummy;                // 1396
        data_ptr[1397] = &dummy;                // 1397
        data_ptr[1398] = &dummy;                // 1398
        data_ptr[1399] = &dummy;                // 1399
        data_ptr[1400] = &dummy;                // 1400

//  tmp = RF_THETA_POS;

        data_ptr[1401] = &Theta;                // 1401
//      data_ptr[1402] = &Theta_comp;           // 1402
        data_ptr[1403] = &Sin_theta;            // 1403
        data_ptr[1404] = &Cos_theta;            // 1404
//      data_ptr[1405] = &comp_theta;           // 1405
        data_ptr[1406] = &Sin_thetaT;           // 1406
        data_ptr[1407] = &Cos_theta_C;          // 1407
        data_ptr[1408] = &Sin_Theta_VF;         // 1408
        data_ptr[1409] = &Cos_Theta_VF;         // 1409
        data_ptr[1410] = &theta_VF;             // 1410
                 
        data_ptr[1411] = &Freq_out;             /* 1411 */
        data_ptr[1412] = &dummy;                /* 1412 */
        data_ptr[1413] = &dummy;                /* 1413 */
        data_ptr[1414] = &dummy;                /* 1414 */
        data_ptr[1415] = &dummy;                /* 1415 */
        data_ptr[1416] = &dummy;                /* 1416 */
        data_ptr[1417] = &dummy;                /* 1417 */
        data_ptr[1418] = &dummy;                /* 1418 */
        data_ptr[1419] = &dummy;                /* 1419 */
        data_ptr[1420] = &dummy;                /* 1420 */
                 
//  tmp = RF_CONTROL_POS;
                 
        data_ptr[1421] = &K_cc[CKP];            // 1421
        data_ptr[1422] = &K_cc[CKIT];           // 1422
        data_ptr[1423] = &K_cc[CKA];            // 1423
        data_ptr[1424] = &dummy;                // 1424
        data_ptr[1425] = &dummy;                // 1425
        data_ptr[1426] = &dummy;                // 1426
        data_ptr[1427] = &dummy;                // 1427
        data_ptr[1428] = &Kp_VC;                // 1428
        data_ptr[1429] = &Ki_VC;                // 1429
        data_ptr[1430] = &Ka_VC;                // 1430
                 
        data_ptr[1431] = &dummy;                /* 1431 */
        data_ptr[1432] = &dummy;                /* 1432 */
        data_ptr[1433] = &dummy;                /* 1433 */
        data_ptr[1434] = &dummy;                /* 1434 */
        data_ptr[1435] = &dummy;                /* 1435 */
        data_ptr[1436] = &dummy;                /* 1436 */
        data_ptr[1437] = &dummy;                /* 1437 */
        data_ptr[1438] = &dummy;                /* 1438 */
        data_ptr[1439] = &dummy;                /* 1439 */
        data_ptr[1440] = &dummy;                /* 1440 */

        data_ptr[1441] = &OV_set_Vdc;           // 1441
        data_ptr[1442] = &UV_set_Vdc;           // 1442
//      data_ptr[1443] = &MC_set;               // 1443
        data_ptr[1444] = &OV_set_src;           // 1444
        data_ptr[1445] = &UV_set_src;           // 1445
        data_ptr[1446] = &INTER_set_src;        // 1446
        data_ptr[1447] = &dummy;                // 1447
        data_ptr[1448] = &dummy;                // 1448
        data_ptr[1449] = &OC_set;               // 1449
//      data_ptr[1450] = &OH_set;               // 1450

//      data_ptr[1451] = &T_CC_max;             /* 1451 */
        data_ptr[1452] = &dummy;                /* 1452 */
        data_ptr[1453] = &dummy;                /* 1453 */
        data_ptr[1454] = &dummy;                /* 1454 */
        data_ptr[1455] = &dummy;                /* 1455 */
        data_ptr[1456] = &dummy;                /* 1456 */
        data_ptr[1457] = &dummy;                /* 1457 */
        data_ptr[1458] = &dummy;                /* 1458 */
        data_ptr[1459] = &dummy;                /* 1459 */
        data_ptr[1460] = &dummy;                /* 1460 */
                 
        data_ptr[1461] = &dummy;                // 1461
        data_ptr[1462] = &dummy;                // 1462
        data_ptr[1463] = &dummy;                // 1463
        data_ptr[1464] = &dummy;                // 1464
//      data_ptr[1465] = &Ic_limit;             // 1465
        data_ptr[1466] = &dummy;                // 1466
        data_ptr[1467] = &dummy;                // 1467
        data_ptr[1468] = &dummy;                // 1468
        data_ptr[1469] = &dummy;                // 1469
        data_ptr[1470] = &dummy;                // 1470
                 
        data_ptr[1471] = &dummy;                // 1471
        data_ptr[1472] = &dummy;                // 1472
        data_ptr[1473] = &dummy;                // 1473
        data_ptr[1474] = &dummy;                // 1474
        data_ptr[1475] = &dummy;                // 1475
        data_ptr[1476] = &dummy;                // 1476
        data_ptr[1477] = &dummy;                // 1477
        data_ptr[1478] = &dummy;                // 1478
        data_ptr[1479] = &dummy;                // 1479
        data_ptr[1480] = &dummy;                // 1480
                 
        data_ptr[1481] = &dummy;                /* 1481 */
        data_ptr[1482] = &dummy;                /* 1482 */
        data_ptr[1483] = &dummy;                /* 1483 */
        data_ptr[1484] = &dummy;                /* 1484 */
        data_ptr[1485] = &dummy;                /* 1485 */
        data_ptr[1486] = &dummy;                /* 1486 */
        data_ptr[1487] = &dummy;                /* 1487 */
        data_ptr[1488] = &dummy;                /* 1488 */
        data_ptr[1489] = &dummy;                /* 1489 */
        data_ptr[1490] = &dummy;                /* 1490 */
                 
        data_ptr[1491] = &dummy;                /* 1491 */
        data_ptr[1492] = &dummy;                /* 1492 */
        data_ptr[1493] = &dummy;                /* 1493 */
        data_ptr[1494] = &dummy;                /* 1494 */
        data_ptr[1495] = &dummy;                /* 1495 */
        data_ptr[1496] = &dummy;                /* 1496 */
        data_ptr[1497] = &dummy;                /* 1497 */
        data_ptr[1498] = &dummy;                /* 1498 */
        data_ptr[1499] = &dummy;                /* 1499 */
        data_ptr[1500] = &dummy;                /* 1500 */
#endif
}
