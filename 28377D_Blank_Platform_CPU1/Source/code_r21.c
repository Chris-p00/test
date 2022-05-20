//###############################################################################################################
// 파일명      : code_r21.c
// 회사명      : G-Philos
// 작성날짜  : 2009.12.02
// 작성자      : S.H.Moon
// 수정날짜  : 2021.01.04
// 수정자      : Lee Sang Cheol
// 설명         : communication pointer define(integer read code(1/2))
//###############################################################################################################

#include "Define.h"


void init_code_r21()
{

#if 1
//  int tmp=2001;
/*--------------------------------------*/
/*  read(integer-type)                  */
/*--------------------------------------*/
//  tmp = RI_STATE_POS;

        data_ptr[2001] = &System_fault;         /* 2001 */
        data_ptr[2002] = &Mode_system;          /* 2002 */
        data_ptr[2003] = &idummy;               // 2003
        data_ptr[2004] = &idummy;               // 2004
        data_ptr[2005] = &Mode_test;            /* 2005 */
        data_ptr[2006] = &idummy;               /* 2006 */
        data_ptr[2007] = &idummy;               /* 2007 */
        data_ptr[2008] = &idummy;               /* 2008 */
        data_ptr[2009] = &idummy;               /* 2009 */
        data_ptr[2010] = &idummy;               /* 2010 */

        data_ptr[2011] = &idummy;               // 2011
        data_ptr[2012] = &idummy;               // 2012
        data_ptr[2013] = &idummy;               /* 2013 */
        data_ptr[2014] = &idummy;               /* 2014 */
        data_ptr[2015] = &idummy;               /* 2015 */
        data_ptr[2016] = &idummy;               /* 2016 */
        data_ptr[2017] = &idummy;               /* 2017 */
        data_ptr[2018] = &idummy;               /* 2018 */
        data_ptr[2019] = &idummy;               /* 2019 */
        data_ptr[2020] = &idummy;               /* 2020 */

//      data_ptr[2021] = &Main_control_MCCB;    /* 2021 */
//      data_ptr[2022] = &State_charge_MC;      /* 2022 */
//      data_ptr[2023] = &State_main_MCCB;      /* 2023 */
        data_ptr[2024] = &idummy;               /* 2024 */
        data_ptr[2025] = &idummy;               /* 2025 */
        data_ptr[2026] = &idummy;               /* 2026 */
//      data_ptr[2027] = &State_iheat;          /* 2027 */
        data_ptr[2028] = &idummy;               /* 2028 */
        data_ptr[2029] = &idummy;               /* 2029 */
        data_ptr[2030] = &idummy;               /* 2030 */

        data_ptr[2031] = &idummy;               /* 2031 */
        data_ptr[2032] = &idummy;               /* 2032 */
        data_ptr[2033] = &idummy;               /* 2033 */
        data_ptr[2034] = &idummy;               /* 2034 */
        data_ptr[2035] = &idummy;               /* 2035 */
        data_ptr[2036] = &idummy;               /* 2036 */
        data_ptr[2037] = &idummy;               /* 2037 */
        data_ptr[2038] = &idummy;               /* 2038 */
//      data_ptr[2039] = &State_32bit;          /* 2039 */
//      data_ptr[2040] = &DT_load;              /* 2040 */

        data_ptr[2041] = &Fault_history[0];     /* 2041 */
        data_ptr[2042] = &Fault_history[1];     /* 2042 */
        data_ptr[2043] = &Fault_history[2];     /* 2043 */
        data_ptr[2044] = &Fault_HW;             /* 2044 */
        data_ptr[2045] = &idummy;               /* 2045 */
        data_ptr[2046] = &idummy;               /* 2046 */
        data_ptr[2047] = &idummy;               /* 2047 */
        data_ptr[2048] = &idummy;               /* 2048 */
        data_ptr[2049] = &Fault_SW;             /* 2049 */
//      data_ptr[2050] = &Fault_interlock;      /* 2050 */

//  tmp = RI_FLAG_POS;

        data_ptr[2051] = &Flag_gating;          /* 2051 */
        data_ptr[2052] = &Flag_offset;          /* 2052 */
//      data_ptr[2053] = &Flag_on_off;          /* 2053 */
//      data_ptr[2054] = &Flag_OM;              /* 2054 */
//      data_ptr[2055] = &Flag_charge_MC;       /* 2055 */
        data_ptr[2056] = &dummy;                /* 2056 */
//      data_ptr[2057] = &Flag_run;             /* 2057 */
//      data_ptr[2058] = &Flag_ready;           /* 2058 */
        data_ptr[2059] = &Flag_buildup;         /* 2059 */
//      data_ptr[2060] = &State_ES;             /* 2060 */

//      data_ptr[2061] = &Flag_first_FRAM;      /* 2061 */
//      data_ptr[2062] = &Enable_FRAM_access;   /* 2062 */
//      data_ptr[2063] = &Flag_toggle_FRAM;     /* 2063 */
//      data_ptr[2064] = &Flag_code_all_erase;  /* 2064 */
//      data_ptr[2065] = &Flag_code_all_write;  /* 2065 */
//      data_ptr[2066] = &Flag_interlock;       /* 2066 */
//      data_ptr[2067] = &Set_trace_period;     /* 2067 */
        data_ptr[2068] = &idummy;               /* 2068 */
        data_ptr[2069] = &idummy;               /* 2069 */
        data_ptr[2070] = &idummy;               /* 2070 */

        data_ptr[2071] = &idummy;               // 2071
        data_ptr[2072] = &idummy;               // 2072
//      data_ptr[2073] = &Flag_waves;           /* 2073 */
        data_ptr[2074] = &idummy;               /* 2074 */
        data_ptr[2075] = &idummy;               /* 2075 */
        data_ptr[2076] = &idummy;               /* 2076 */
        data_ptr[2077] = &Flag_volt_limit;      // 2077
        data_ptr[2078] = &idummy;               // 2078
        data_ptr[2079] = &idummy;               // 2079
        data_ptr[2080] = &idummy;               // 2080

        data_ptr[2081] = &idummy;               /* 2081 */
        data_ptr[2082] = &idummy;               /* 2082 */
        data_ptr[2083] = &idummy;               /* 2083 */
        data_ptr[2084] = &idummy;               /* 2084 */
        data_ptr[2085] = &idummy;               /* 2085 */
        data_ptr[2086] = &idummy;               /* 2086 */
        data_ptr[2087] = &idummy;               /* 2087 */
        data_ptr[2088] = &idummy;               /* 2088 */
        data_ptr[2089] = &idummy;               /* 2089 */
        data_ptr[2090] = &idummy;               /* 2090 */

        data_ptr[2091] = &idummy;               /* 2091 */
        data_ptr[2092] = &idummy;               /* 2092 */
        data_ptr[2093] = &idummy;               /* 2093 */
        data_ptr[2094] = &idummy;               /* 2094 */
        data_ptr[2095] = &idummy;               /* 2095 */
        data_ptr[2096] = &idummy;               /* 2096 */
        data_ptr[2097] = &idummy;               /* 2097 */
        data_ptr[2098] = &idummy;               /* 2098 */
        data_ptr[2099] = &idummy;               /* 2099 */
        data_ptr[2100] = &idummy;               /* 2100 */

        data_ptr[2101] = &idummy;               /* 2101 */
        data_ptr[2102] = &idummy;               /* 2102 */
//      data_ptr[2103] = &Fault_Keypad_Moni;                /* 2103 */
        data_ptr[2104] = &idummy;               /* 2104 */
        data_ptr[2105] = &idummy;               /* 2105 */
        data_ptr[2106] = &idummy;               /* 2106 */
        data_ptr[2107] = &idummy;               /* 2107 */
        data_ptr[2108] = &idummy;               /* 2108 */
        data_ptr[2109] = &idummy;               /* 2109 */
        data_ptr[2110] = &idummy;               /* 2110 */

//      data_ptr[2111] = &Fault_keypad[0];      // 2111 //
//      data_ptr[2112] = &Fault_keypad[1];      // 2112 //
//      data_ptr[2113] = &Fault_keypad[2];      // 2113 //
//      data_ptr[2114] = &Fault_keypad[3];      // 2114 //
//      data_ptr[2115] = &Fault_keypad[4];      // 2115 //
//      data_ptr[2116] = &Fault_keypad[5];      // 2116 //
        data_ptr[2117] = &idummy;               // 2117 //
        data_ptr[2118] = &idummy;               // 2118 //
        data_ptr[2119] = &idummy;               // 2119 //
        data_ptr[2120] = &idummy;               // 2120 //

//      data_ptr[2121] = &Enb_RTC_init;         // 2121 //
//      data_ptr[2122] = &Flag_RTC_init;        // 2122 //
//      data_ptr[2123] = &Set_hour_min;         // 2123 //
//      data_ptr[2124] = &Set_mon_day;          // 2124 //
//      data_ptr[2125] = &Set_year;             // 2125 //
//      data_ptr[2126] = &Read_sec;             // 2126 //
//      data_ptr[2127] = &Read_hour_min;        // 2127 //
//      data_ptr[2128] = &Read_mon_day;         // 2128 //
//      data_ptr[2129] = &Read_year;            // 2129 //
//      data_ptr[2130] = &Enb_RTC_mode;         // 2130 //

        data_ptr[2131] = &idummy;               /* 2131 */
        data_ptr[2132] = &idummy;               /* 2132 */
        data_ptr[2133] = &idummy;               /* 2133 */
        data_ptr[2134] = &idummy;               /* 2134 */
        data_ptr[2135] = &idummy;               /* 2135 */
        data_ptr[2136] = &idummy;               /* 2136 */
        data_ptr[2137] = &idummy;               /* 2137 */
        data_ptr[2138] = &idummy;               /* 2138 */
        data_ptr[2139] = &idummy;               /* 2139 */
        data_ptr[2140] = &idummy;               /* 2140 */

        data_ptr[2141] = &idummy;               /* 2141 */
        data_ptr[2142] = &idummy;               /* 2142 */
        data_ptr[2143] = &idummy;               /* 2143 */
        data_ptr[2144] = &idummy;               /* 2144 */
        data_ptr[2145] = &idummy;               /* 2145 */
        data_ptr[2146] = &idummy;               /* 2146 */
        data_ptr[2147] = &idummy;               /* 2147 */
        data_ptr[2148] = &idummy;               /* 2148 */
        data_ptr[2149] = &idummy;               /* 2149 */
        data_ptr[2150] = &idummy;               /* 2150 */

        data_ptr[2151] = &idummy;               /* 2151 */
        data_ptr[2152] = &idummy;               /* 2152 */
        data_ptr[2153] = &idummy;               /* 2153 */
        data_ptr[2154] = &idummy;               /* 2154 */
        data_ptr[2155] = &idummy;               /* 2155 */
        data_ptr[2156] = &idummy;               /* 2156 */
        data_ptr[2157] = &idummy;               /* 2157 */
        data_ptr[2158] = &idummy;               /* 2158 */
        data_ptr[2159] = &idummy;               /* 2159 */
        data_ptr[2160] = &idummy;               /* 2160 */

        data_ptr[2161] = &idummy;               /* 2161 */
        data_ptr[2162] = &idummy;               /* 2162 */
        data_ptr[2163] = &idummy;               /* 2163 */
        data_ptr[2164] = &idummy;               /* 2164 */
        data_ptr[2165] = &idummy;               /* 2165 */
        data_ptr[2166] = &idummy;               /* 2166 */
        data_ptr[2167] = &idummy;               /* 2167 */
        data_ptr[2168] = &idummy;               /* 2168 */
        data_ptr[2169] = &idummy;               /* 2169 */
        data_ptr[2170] = &idummy;               /* 2170 */

        data_ptr[2171] = &idummy;               /* 2171 */
        data_ptr[2172] = &idummy;               /* 2172 */
        data_ptr[2173] = &idummy;               /* 2173 */
        data_ptr[2174] = &idummy;               /* 2174 */
        data_ptr[2175] = &idummy;               /* 2175 */
        data_ptr[2176] = &idummy;               /* 2176 */
        data_ptr[2177] = &idummy;               /* 2177 */
        data_ptr[2178] = &idummy;               /* 2178 */
        data_ptr[2179] = &idummy;               /* 2179 */
        data_ptr[2180] = &idummy;               /* 2180 */

        data_ptr[2181] = &idummy;               /* 2181 */
        data_ptr[2182] = &idummy;               /* 2182 */
        data_ptr[2183] = &idummy;               /* 2183 */
        data_ptr[2184] = &idummy;               /* 2184 */
        data_ptr[2185] = &idummy;               /* 2185 */
        data_ptr[2186] = &idummy;               /* 2186 */
        data_ptr[2187] = &idummy;               /* 2187 */
        data_ptr[2188] = &idummy;               /* 2188 */
        data_ptr[2189] = &idummy;               /* 2189 */
        data_ptr[2190] = &idummy;               /* 2190 */

        data_ptr[2191] = &idummy;               /* 2191 */
        data_ptr[2192] = &idummy;               /* 2192 */
        data_ptr[2193] = &idummy;               /* 2193 */
        data_ptr[2194] = &idummy;               /* 2194 */
        data_ptr[2195] = &idummy;               /* 2195 */
        data_ptr[2196] = &idummy;               /* 2196 */
        data_ptr[2197] = &idummy;               /* 2197 */
        data_ptr[2198] = &idummy;               /* 2198 */
        data_ptr[2199] = &idummy;               /* 2199 */
        data_ptr[2200] = &idummy;               /* 2200 */

//  tmp = RI_COMMAND_INPUT_POS;

//      data_ptr[2201] = &Cmd_code_save;        /* 2201 */
//      data_ptr[2202] = &Cmd_run_inv;          /* 2202 */
        data_ptr[2203] = &idummy;               /* 2203 */
        data_ptr[2204] = &idummy;               // 2204
        data_ptr[2205] = &idummy;               /* 2205 */
//      data_ptr[2206] = &Cmd_ES;               /* 2206 */
//      data_ptr[2207] = &Err_level5;           /* 2207 */
        data_ptr[2208] = &idummy;               /* 2208 */
        data_ptr[2209] = &idummy;               /* 2209 */
        data_ptr[2210] = &idummy;               /* 2210 */

        data_ptr[2211] = &idummy;               // 2211
        data_ptr[2212] = &idummy;               // 2212
        data_ptr[2213] = &idummy;               /* 2213 */
        data_ptr[2214] = &idummy;               /* 2214 */
        data_ptr[2215] = &idummy;               /* 2215 */
        data_ptr[2216] = &idummy;               /* 2216 */
        data_ptr[2217] = &idummy;               /* 2217 */
        data_ptr[2218] = &idummy;               /* 2218 */
        data_ptr[2219] = &idummy;               /* 2219 */
        data_ptr[2220] = &idummy;               /* 2220 */

//      data_ptr[2221] = &Cmd_gating;           /* 2221 */
        data_ptr[2222] = &idummy;               /* 2222 */
        data_ptr[2223] = &Fault_reset;          /* 2223 */
        data_ptr[2224] = &idummy;               /* 2224 */
        data_ptr[2225] = &idummy;               /* 2225 */
        data_ptr[2226] = &idummy;               /* 2226 */
        data_ptr[2227] = &idummy;               /* 2227 */
        data_ptr[2228] = &idummy;               /* 2228 */
        data_ptr[2229] = &idummy;               /* 2229 */
        data_ptr[2230] = &idummy;               /* 2230 */

        data_ptr[2231] = &idummy;               /* 2231 */
        data_ptr[2232] = &idummy;               /* 2232 */
        data_ptr[2233] = &idummy;               /* 2233 */
        data_ptr[2234] = &idummy;               /* 2234 */
        data_ptr[2235] = &idummy;               /* 2235 */
        data_ptr[2236] = &idummy;               /* 2236 */
        data_ptr[2237] = &idummy;               /* 2237 */
        data_ptr[2238] = &idummy;               /* 2238 */
        data_ptr[2239] = &idummy;               /* 2239 */
        data_ptr[2240] = &idummy;               /* 2240 */

        data_ptr[2241] = &idummy;               /* 2241 */
        data_ptr[2242] = &idummy;               /* 2242 */
        data_ptr[2243] = &idummy;               /* 2243 */
        data_ptr[2244] = &idummy;               /* 2244 */
        data_ptr[2245] = &idummy;               /* 2245 */
        data_ptr[2246] = &idummy;               /* 2246 */
        data_ptr[2247] = &idummy;               /* 2247 */
        data_ptr[2248] = &idummy;               /* 2248 */
        data_ptr[2249] = &idummy;               /* 2249 */
        data_ptr[2250] = &idummy;               /* 2250 */

        data_ptr[2251] = &idummy;               /* 2251 */
        data_ptr[2252] = &idummy;               /* 2252 */
        data_ptr[2253] = &idummy;               /* 2253 */
        data_ptr[2254] = &idummy;               /* 2254 */
        data_ptr[2255] = &idummy;               /* 2255 */
        data_ptr[2256] = &idummy;               /* 2256 */
        data_ptr[2257] = &idummy;               /* 2257 */
        data_ptr[2258] = &idummy;               /* 2258 */
        data_ptr[2259] = &idummy;               /* 2259 */
        data_ptr[2260] = &idummy;               /* 2260 */

        data_ptr[2261] = &idummy;               /* 2261 */
        data_ptr[2262] = &idummy;               /* 2262 */
        data_ptr[2263] = &idummy;               /* 2263 */
        data_ptr[2264] = &idummy;               /* 2264 */
        data_ptr[2265] = &idummy;               /* 2265 */
        data_ptr[2266] = &idummy;               /* 2266 */
        data_ptr[2267] = &idummy;               /* 2267 */
        data_ptr[2268] = &idummy;               /* 2268 */
        data_ptr[2269] = &idummy;               /* 2269 */
        data_ptr[2270] = &idummy;               /* 2270 */

        data_ptr[2271] = &idummy;               /* 2271 */
        data_ptr[2272] = &idummy;               /* 2272 */
        data_ptr[2273] = &idummy;               /* 2273 */
        data_ptr[2274] = &idummy;               /* 2274 */
        data_ptr[2275] = &idummy;               /* 2275 */
        data_ptr[2276] = &idummy;               /* 2276 */
        data_ptr[2277] = &idummy;               /* 2277 */
        data_ptr[2278] = &idummy;               /* 2278 */
        data_ptr[2279] = &idummy;               /* 2279 */
        data_ptr[2280] = &idummy;               /* 2280 */

        data_ptr[2281] = &idummy;               /* 2281 */
        data_ptr[2282] = &idummy;               /* 2282 */
        data_ptr[2283] = &idummy;               /* 2283 */
        data_ptr[2284] = &idummy;               /* 2284 */
        data_ptr[2285] = &idummy;               /* 2285 */
        data_ptr[2286] = &idummy;               /* 2286 */
        data_ptr[2287] = &idummy;               /* 2287 */
        data_ptr[2288] = &idummy;               /* 2288 */
        data_ptr[2289] = &idummy;               /* 2289 */
        data_ptr[2290] = &idummy;               /* 2290 */

        data_ptr[2291] = &idummy;               /* 2291 */
        data_ptr[2292] = &idummy;               /* 2292 */
        data_ptr[2293] = &idummy;               /* 2293 */
        data_ptr[2294] = &idummy;               /* 2294 */
        data_ptr[2295] = &idummy;               /* 2295 */
        data_ptr[2296] = &idummy;               /* 2296 */
        data_ptr[2297] = &idummy;               /* 2297 */
        data_ptr[2298] = &idummy;               /* 2298 */
        data_ptr[2299] = &idummy;               /* 2299 */
        data_ptr[2300] = &idummy;               /* 2300 */

//  tmp = RI_DIG_INOUT_POS;

//      data_ptr[2301] = &Din_data;             /* 2301 */
//      data_ptr[2302] = &Din_data_raw;         /* 2302 */
        data_ptr[2303] = &idummy;               /* 2303 */
        data_ptr[2304] = &idummy;               /* 2304 */
        data_ptr[2305] = &idummy;               /* 2305 */
//      data_ptr[2306] = &Dout_data;            /* 2306 */
        data_ptr[2307] = &idummy;               /* 2307 */
        data_ptr[2308] = &idummy;               /* 2308 */
        data_ptr[2309] = &idummy;               /* 2309 */
        data_ptr[2310] = &idummy;               /* 2310 */

        data_ptr[2311] = &idummy;               /* 2311 */
        data_ptr[2312] = &idummy;               /* 2312 */
        data_ptr[2313] = &idummy;               /* 2313 */
        data_ptr[2314] = &idummy;               /* 2314 */
        data_ptr[2315] = &idummy;               /* 2315 */
        data_ptr[2316] = &idummy;               /* 2316 */
        data_ptr[2317] = &idummy;               /* 2317 */
        data_ptr[2318] = &idummy;               /* 2318 */
        data_ptr[2319] = &idummy;               /* 2319 */
        data_ptr[2320] = &idummy;               /* 2320 */

        data_ptr[2321] = &idummy;               /* 2321 */
        data_ptr[2322] = &idummy;               /* 2322 */
        data_ptr[2323] = &idummy;               /* 2323 */
        data_ptr[2324] = &idummy;               /* 2324 */
        data_ptr[2325] = &idummy;               /* 2325 */
        data_ptr[2326] = &idummy;               /* 2326 */
        data_ptr[2327] = &idummy;               /* 2327 */
        data_ptr[2328] = &idummy;               /* 2328 */
        data_ptr[2329] = &idummy;               /* 2329 */
        data_ptr[2330] = &idummy;               /* 2330 */

        data_ptr[2331] = &idummy;               /* 2331 */
        data_ptr[2332] = &idummy;               /* 2332 */
        data_ptr[2333] = &idummy;               /* 2333 */
        data_ptr[2334] = &idummy;               /* 2334 */
        data_ptr[2335] = &idummy;               /* 2335 */
        data_ptr[2336] = &idummy;               /* 2336 */
        data_ptr[2337] = &idummy;               /* 2337 */
        data_ptr[2338] = &idummy;               /* 2338 */
        data_ptr[2339] = &idummy;               /* 2339 */
        data_ptr[2340] = &idummy;               /* 2340 */

        data_ptr[2341] = &idummy;               /* 2341 */
        data_ptr[2342] = &idummy;               /* 2342 */
        data_ptr[2343] = &idummy;               /* 2343 */
        data_ptr[2344] = &idummy;               /* 2344 */
        data_ptr[2345] = &idummy;               /* 2345 */
        data_ptr[2346] = &idummy;               /* 2346 */
        data_ptr[2347] = &idummy;               /* 2347 */
        data_ptr[2348] = &idummy;               /* 2348 */
        data_ptr[2349] = &idummy;               /* 2349 */
        data_ptr[2350] = &idummy;               /* 2350 */

        data_ptr[2351] = &idummy;               /* 2351 */
        data_ptr[2352] = &idummy;               /* 2352 */
        data_ptr[2353] = &idummy;               /* 2353 */
        data_ptr[2354] = &idummy;               /* 2354 */
        data_ptr[2355] = &idummy;               /* 2355 */
        data_ptr[2356] = &idummy;               /* 2356 */
        data_ptr[2357] = &idummy;               /* 2357 */
        data_ptr[2358] = &idummy;               /* 2358 */
        data_ptr[2359] = &idummy;               /* 2359 */
        data_ptr[2360] = &idummy;               /* 2360 */

        data_ptr[2361] = &idummy;               /* 2361 */
        data_ptr[2362] = &idummy;               /* 2362 */
        data_ptr[2363] = &idummy;               /* 2363 */
        data_ptr[2364] = &idummy;               /* 2364 */
        data_ptr[2365] = &idummy;               /* 2365 */
        data_ptr[2366] = &idummy;               /* 2366 */
        data_ptr[2367] = &idummy;               /* 2367 */
        data_ptr[2368] = &idummy;               /* 2368 */
        data_ptr[2369] = &idummy;               /* 2369 */
        data_ptr[2370] = &idummy;               /* 2370 */

        data_ptr[2371] = &idummy;               /* 2371 */
        data_ptr[2372] = &idummy;               /* 2372 */
        data_ptr[2373] = &idummy;               /* 2373 */
        data_ptr[2374] = &idummy;               /* 2374 */
        data_ptr[2375] = &idummy;               /* 2375 */
        data_ptr[2376] = &idummy;               /* 2376 */
        data_ptr[2377] = &idummy;               /* 2377 */
        data_ptr[2378] = &idummy;               /* 2378 */
        data_ptr[2379] = &idummy;               /* 2379 */
        data_ptr[2380] = &idummy;               /* 2380 */

        data_ptr[2381] = &idummy;               /* 2381 */
        data_ptr[2382] = &idummy;               /* 2382 */
        data_ptr[2383] = &idummy;               /* 2383 */
        data_ptr[2384] = &idummy;               /* 2384 */
        data_ptr[2385] = &idummy;               /* 2385 */
        data_ptr[2386] = &idummy;               /* 2386 */
        data_ptr[2387] = &idummy;               /* 2387 */
        data_ptr[2388] = &idummy;               /* 2388 */
        data_ptr[2389] = &idummy;               /* 2389 */
        data_ptr[2390] = &idummy;               /* 2390 */

        data_ptr[2391] = &idummy;               /* 2391 */
        data_ptr[2392] = &idummy;               /* 2392 */
        data_ptr[2393] = &idummy;               /* 2393 */
        data_ptr[2394] = &idummy;               /* 2394 */
        data_ptr[2395] = &idummy;               /* 2395 */
        data_ptr[2396] = &idummy;               /* 2396 */
        data_ptr[2397] = &idummy;               /* 2397 */
        data_ptr[2398] = &idummy;               /* 2398 */
        data_ptr[2399] = &idummy;               /* 2399 */
        data_ptr[2400] = &idummy;               /* 2400 */

//      data_ptr[2401] = &Cmd_waves_read;       /* 2401 */
        data_ptr[2402] = &idummy;               /* 2402 */
        data_ptr[2403] = &idummy;               /* 2403 */
        data_ptr[2404] = &idummy;               /* 2404 */
        data_ptr[2405] = &idummy;               /* 2405 */
        data_ptr[2406] = &idummy;               /* 2406 */
        data_ptr[2407] = &idummy;               /* 2407 */
        data_ptr[2408] = &idummy;               /* 2408 */
        data_ptr[2409] = &idummy;               /* 2409 */
        data_ptr[2410] = &idummy;               /* 2410 */

//      data_ptr[2411] = &Fast_trace_point;     /* 2411 */
//      data_ptr[2412] = &Slow_trace_point;     /* 2412 */
//      data_ptr[2413] = &First_trace;          /* 2413 */
//      data_ptr[2414] = &Fast_trace_stop_cnt;  /* 2414 */
//      data_ptr[2415] = &Fast_trace_index;     /* 2415 */
//      data_ptr[2416] = &Slow_trace_stop_cnt;  /* 2416 */
//      data_ptr[2417] = &Slow_trace_index;     /* 2417 */
        data_ptr[2418] = &idummy;               /* 2418 */
        data_ptr[2419] = &idummy;               /* 2419 */
        data_ptr[2420] = &idummy;               /* 2420 */

        data_ptr[2421] = &idummy;               /* 2421 */
        data_ptr[2422] = &idummy;               /* 2422 */
        data_ptr[2423] = &idummy;               /* 2423 */
        data_ptr[2424] = &idummy;               /* 2424 */
        data_ptr[2425] = &idummy;               /* 2425 */
        data_ptr[2426] = &idummy;               /* 2426 */
        data_ptr[2427] = &idummy;               /* 2427 */
        data_ptr[2428] = &idummy;               /* 2428 */
        data_ptr[2429] = &idummy;               /* 2429 */
        data_ptr[2430] = &idummy;               /* 2430 */

        data_ptr[2431] = &idummy;               /* 2431 */
        data_ptr[2432] = &idummy;               /* 2432 */
        data_ptr[2433] = &idummy;               /* 2433 */
        data_ptr[2434] = &idummy;               /* 2434 */
        data_ptr[2435] = &idummy;               /* 2435 */
        data_ptr[2436] = &idummy;               /* 2436 */
        data_ptr[2437] = &idummy;               /* 2437 */
        data_ptr[2438] = &idummy;               /* 2438 */
        data_ptr[2439] = &idummy;               /* 2439 */
        data_ptr[2440] = &idummy;               /* 2440 */

        data_ptr[2441] = &idummy;               /* 2441 */
        data_ptr[2442] = &idummy;               /* 2442 */
        data_ptr[2443] = &idummy;               /* 2443 */
        data_ptr[2444] = &idummy;               /* 2444 */
        data_ptr[2445] = &idummy;               /* 2445 */
        data_ptr[2446] = &idummy;               /* 2446 */
        data_ptr[2447] = &idummy;               /* 2447 */
        data_ptr[2448] = &idummy;               /* 2448 */
        data_ptr[2449] = &idummy;               /* 2449 */
        data_ptr[2450] = &idummy;               /* 2450 */

        data_ptr[2451] = &idummy;               /* 2451 */
        data_ptr[2452] = &idummy;               /* 2452 */
        data_ptr[2453] = &idummy;               /* 2453 */
        data_ptr[2454] = &idummy;               /* 2454 */
        data_ptr[2455] = &idummy;               /* 2455 */
        data_ptr[2456] = &idummy;               /* 2456 */
        data_ptr[2457] = &idummy;               /* 2457 */
        data_ptr[2458] = &idummy;               /* 2458 */
        data_ptr[2459] = &idummy;               /* 2459 */
        data_ptr[2460] = &idummy;               /* 2460 */

        data_ptr[2461] = &idummy;               /* 2461 */
        data_ptr[2462] = &idummy;               /* 2462 */
        data_ptr[2463] = &idummy;               /* 2463 */
        data_ptr[2464] = &idummy;               /* 2464 */
        data_ptr[2465] = &idummy;               /* 2465 */
        data_ptr[2466] = &idummy;               /* 2466 */
        data_ptr[2467] = &idummy;               /* 2467 */
        data_ptr[2468] = &idummy;               /* 2468 */
        data_ptr[2469] = &idummy;               /* 2469 */
        data_ptr[2470] = &idummy;               /* 2470 */

        data_ptr[2471] = &idummy;               /* 2471 */
        data_ptr[2473] = &idummy;               /* 2473 */
        data_ptr[2472] = &idummy;               /* 2472 */
        data_ptr[2474] = &idummy;               /* 2474 */
        data_ptr[2475] = &idummy;               /* 2475 */
        data_ptr[2476] = &idummy;               /* 2476 */
        data_ptr[2477] = &idummy;               /* 2477 */
        data_ptr[2478] = &idummy;               /* 2478 */
        data_ptr[2479] = &idummy;               /* 2479 */
        data_ptr[2480] = &idummy;               /* 2480 */

        data_ptr[2481] = &idummy;               /* 2481 */
        data_ptr[2482] = &idummy;               /* 2482 */
        data_ptr[2483] = &idummy;               /* 2483 */
        data_ptr[2484] = &idummy;               /* 2484 */
        data_ptr[2485] = &idummy;               /* 2485 */
        data_ptr[2486] = &idummy;               /* 2486 */
        data_ptr[2487] = &idummy;               /* 2487 */
        data_ptr[2488] = &idummy;               /* 2488 */
        data_ptr[2489] = &idummy;               /* 2489 */
        data_ptr[2490] = &idummy;               /* 2490 */

        data_ptr[2491] = &idummy;               /* 2491 */
        data_ptr[2492] = &idummy;               /* 2492 */
        data_ptr[2493] = &idummy;               /* 2493 */
        data_ptr[2494] = &idummy;               /* 2494 */
        data_ptr[2495] = &idummy;               /* 2495 */
        data_ptr[2496] = &idummy;               /* 2496 */
        data_ptr[2497] = &idummy;               /* 2497 */
        data_ptr[2498] = &idummy;               /* 2498 */
        data_ptr[2499] = &idummy;               /* 2499 */
        data_ptr[2500] = &idummy;               /* 2500 */
#endif
}

