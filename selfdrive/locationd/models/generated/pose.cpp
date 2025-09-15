#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_7569354656790451798) {
   out_7569354656790451798[0] = delta_x[0] + nom_x[0];
   out_7569354656790451798[1] = delta_x[1] + nom_x[1];
   out_7569354656790451798[2] = delta_x[2] + nom_x[2];
   out_7569354656790451798[3] = delta_x[3] + nom_x[3];
   out_7569354656790451798[4] = delta_x[4] + nom_x[4];
   out_7569354656790451798[5] = delta_x[5] + nom_x[5];
   out_7569354656790451798[6] = delta_x[6] + nom_x[6];
   out_7569354656790451798[7] = delta_x[7] + nom_x[7];
   out_7569354656790451798[8] = delta_x[8] + nom_x[8];
   out_7569354656790451798[9] = delta_x[9] + nom_x[9];
   out_7569354656790451798[10] = delta_x[10] + nom_x[10];
   out_7569354656790451798[11] = delta_x[11] + nom_x[11];
   out_7569354656790451798[12] = delta_x[12] + nom_x[12];
   out_7569354656790451798[13] = delta_x[13] + nom_x[13];
   out_7569354656790451798[14] = delta_x[14] + nom_x[14];
   out_7569354656790451798[15] = delta_x[15] + nom_x[15];
   out_7569354656790451798[16] = delta_x[16] + nom_x[16];
   out_7569354656790451798[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4882156975285941590) {
   out_4882156975285941590[0] = -nom_x[0] + true_x[0];
   out_4882156975285941590[1] = -nom_x[1] + true_x[1];
   out_4882156975285941590[2] = -nom_x[2] + true_x[2];
   out_4882156975285941590[3] = -nom_x[3] + true_x[3];
   out_4882156975285941590[4] = -nom_x[4] + true_x[4];
   out_4882156975285941590[5] = -nom_x[5] + true_x[5];
   out_4882156975285941590[6] = -nom_x[6] + true_x[6];
   out_4882156975285941590[7] = -nom_x[7] + true_x[7];
   out_4882156975285941590[8] = -nom_x[8] + true_x[8];
   out_4882156975285941590[9] = -nom_x[9] + true_x[9];
   out_4882156975285941590[10] = -nom_x[10] + true_x[10];
   out_4882156975285941590[11] = -nom_x[11] + true_x[11];
   out_4882156975285941590[12] = -nom_x[12] + true_x[12];
   out_4882156975285941590[13] = -nom_x[13] + true_x[13];
   out_4882156975285941590[14] = -nom_x[14] + true_x[14];
   out_4882156975285941590[15] = -nom_x[15] + true_x[15];
   out_4882156975285941590[16] = -nom_x[16] + true_x[16];
   out_4882156975285941590[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_5814428664983507972) {
   out_5814428664983507972[0] = 1.0;
   out_5814428664983507972[1] = 0.0;
   out_5814428664983507972[2] = 0.0;
   out_5814428664983507972[3] = 0.0;
   out_5814428664983507972[4] = 0.0;
   out_5814428664983507972[5] = 0.0;
   out_5814428664983507972[6] = 0.0;
   out_5814428664983507972[7] = 0.0;
   out_5814428664983507972[8] = 0.0;
   out_5814428664983507972[9] = 0.0;
   out_5814428664983507972[10] = 0.0;
   out_5814428664983507972[11] = 0.0;
   out_5814428664983507972[12] = 0.0;
   out_5814428664983507972[13] = 0.0;
   out_5814428664983507972[14] = 0.0;
   out_5814428664983507972[15] = 0.0;
   out_5814428664983507972[16] = 0.0;
   out_5814428664983507972[17] = 0.0;
   out_5814428664983507972[18] = 0.0;
   out_5814428664983507972[19] = 1.0;
   out_5814428664983507972[20] = 0.0;
   out_5814428664983507972[21] = 0.0;
   out_5814428664983507972[22] = 0.0;
   out_5814428664983507972[23] = 0.0;
   out_5814428664983507972[24] = 0.0;
   out_5814428664983507972[25] = 0.0;
   out_5814428664983507972[26] = 0.0;
   out_5814428664983507972[27] = 0.0;
   out_5814428664983507972[28] = 0.0;
   out_5814428664983507972[29] = 0.0;
   out_5814428664983507972[30] = 0.0;
   out_5814428664983507972[31] = 0.0;
   out_5814428664983507972[32] = 0.0;
   out_5814428664983507972[33] = 0.0;
   out_5814428664983507972[34] = 0.0;
   out_5814428664983507972[35] = 0.0;
   out_5814428664983507972[36] = 0.0;
   out_5814428664983507972[37] = 0.0;
   out_5814428664983507972[38] = 1.0;
   out_5814428664983507972[39] = 0.0;
   out_5814428664983507972[40] = 0.0;
   out_5814428664983507972[41] = 0.0;
   out_5814428664983507972[42] = 0.0;
   out_5814428664983507972[43] = 0.0;
   out_5814428664983507972[44] = 0.0;
   out_5814428664983507972[45] = 0.0;
   out_5814428664983507972[46] = 0.0;
   out_5814428664983507972[47] = 0.0;
   out_5814428664983507972[48] = 0.0;
   out_5814428664983507972[49] = 0.0;
   out_5814428664983507972[50] = 0.0;
   out_5814428664983507972[51] = 0.0;
   out_5814428664983507972[52] = 0.0;
   out_5814428664983507972[53] = 0.0;
   out_5814428664983507972[54] = 0.0;
   out_5814428664983507972[55] = 0.0;
   out_5814428664983507972[56] = 0.0;
   out_5814428664983507972[57] = 1.0;
   out_5814428664983507972[58] = 0.0;
   out_5814428664983507972[59] = 0.0;
   out_5814428664983507972[60] = 0.0;
   out_5814428664983507972[61] = 0.0;
   out_5814428664983507972[62] = 0.0;
   out_5814428664983507972[63] = 0.0;
   out_5814428664983507972[64] = 0.0;
   out_5814428664983507972[65] = 0.0;
   out_5814428664983507972[66] = 0.0;
   out_5814428664983507972[67] = 0.0;
   out_5814428664983507972[68] = 0.0;
   out_5814428664983507972[69] = 0.0;
   out_5814428664983507972[70] = 0.0;
   out_5814428664983507972[71] = 0.0;
   out_5814428664983507972[72] = 0.0;
   out_5814428664983507972[73] = 0.0;
   out_5814428664983507972[74] = 0.0;
   out_5814428664983507972[75] = 0.0;
   out_5814428664983507972[76] = 1.0;
   out_5814428664983507972[77] = 0.0;
   out_5814428664983507972[78] = 0.0;
   out_5814428664983507972[79] = 0.0;
   out_5814428664983507972[80] = 0.0;
   out_5814428664983507972[81] = 0.0;
   out_5814428664983507972[82] = 0.0;
   out_5814428664983507972[83] = 0.0;
   out_5814428664983507972[84] = 0.0;
   out_5814428664983507972[85] = 0.0;
   out_5814428664983507972[86] = 0.0;
   out_5814428664983507972[87] = 0.0;
   out_5814428664983507972[88] = 0.0;
   out_5814428664983507972[89] = 0.0;
   out_5814428664983507972[90] = 0.0;
   out_5814428664983507972[91] = 0.0;
   out_5814428664983507972[92] = 0.0;
   out_5814428664983507972[93] = 0.0;
   out_5814428664983507972[94] = 0.0;
   out_5814428664983507972[95] = 1.0;
   out_5814428664983507972[96] = 0.0;
   out_5814428664983507972[97] = 0.0;
   out_5814428664983507972[98] = 0.0;
   out_5814428664983507972[99] = 0.0;
   out_5814428664983507972[100] = 0.0;
   out_5814428664983507972[101] = 0.0;
   out_5814428664983507972[102] = 0.0;
   out_5814428664983507972[103] = 0.0;
   out_5814428664983507972[104] = 0.0;
   out_5814428664983507972[105] = 0.0;
   out_5814428664983507972[106] = 0.0;
   out_5814428664983507972[107] = 0.0;
   out_5814428664983507972[108] = 0.0;
   out_5814428664983507972[109] = 0.0;
   out_5814428664983507972[110] = 0.0;
   out_5814428664983507972[111] = 0.0;
   out_5814428664983507972[112] = 0.0;
   out_5814428664983507972[113] = 0.0;
   out_5814428664983507972[114] = 1.0;
   out_5814428664983507972[115] = 0.0;
   out_5814428664983507972[116] = 0.0;
   out_5814428664983507972[117] = 0.0;
   out_5814428664983507972[118] = 0.0;
   out_5814428664983507972[119] = 0.0;
   out_5814428664983507972[120] = 0.0;
   out_5814428664983507972[121] = 0.0;
   out_5814428664983507972[122] = 0.0;
   out_5814428664983507972[123] = 0.0;
   out_5814428664983507972[124] = 0.0;
   out_5814428664983507972[125] = 0.0;
   out_5814428664983507972[126] = 0.0;
   out_5814428664983507972[127] = 0.0;
   out_5814428664983507972[128] = 0.0;
   out_5814428664983507972[129] = 0.0;
   out_5814428664983507972[130] = 0.0;
   out_5814428664983507972[131] = 0.0;
   out_5814428664983507972[132] = 0.0;
   out_5814428664983507972[133] = 1.0;
   out_5814428664983507972[134] = 0.0;
   out_5814428664983507972[135] = 0.0;
   out_5814428664983507972[136] = 0.0;
   out_5814428664983507972[137] = 0.0;
   out_5814428664983507972[138] = 0.0;
   out_5814428664983507972[139] = 0.0;
   out_5814428664983507972[140] = 0.0;
   out_5814428664983507972[141] = 0.0;
   out_5814428664983507972[142] = 0.0;
   out_5814428664983507972[143] = 0.0;
   out_5814428664983507972[144] = 0.0;
   out_5814428664983507972[145] = 0.0;
   out_5814428664983507972[146] = 0.0;
   out_5814428664983507972[147] = 0.0;
   out_5814428664983507972[148] = 0.0;
   out_5814428664983507972[149] = 0.0;
   out_5814428664983507972[150] = 0.0;
   out_5814428664983507972[151] = 0.0;
   out_5814428664983507972[152] = 1.0;
   out_5814428664983507972[153] = 0.0;
   out_5814428664983507972[154] = 0.0;
   out_5814428664983507972[155] = 0.0;
   out_5814428664983507972[156] = 0.0;
   out_5814428664983507972[157] = 0.0;
   out_5814428664983507972[158] = 0.0;
   out_5814428664983507972[159] = 0.0;
   out_5814428664983507972[160] = 0.0;
   out_5814428664983507972[161] = 0.0;
   out_5814428664983507972[162] = 0.0;
   out_5814428664983507972[163] = 0.0;
   out_5814428664983507972[164] = 0.0;
   out_5814428664983507972[165] = 0.0;
   out_5814428664983507972[166] = 0.0;
   out_5814428664983507972[167] = 0.0;
   out_5814428664983507972[168] = 0.0;
   out_5814428664983507972[169] = 0.0;
   out_5814428664983507972[170] = 0.0;
   out_5814428664983507972[171] = 1.0;
   out_5814428664983507972[172] = 0.0;
   out_5814428664983507972[173] = 0.0;
   out_5814428664983507972[174] = 0.0;
   out_5814428664983507972[175] = 0.0;
   out_5814428664983507972[176] = 0.0;
   out_5814428664983507972[177] = 0.0;
   out_5814428664983507972[178] = 0.0;
   out_5814428664983507972[179] = 0.0;
   out_5814428664983507972[180] = 0.0;
   out_5814428664983507972[181] = 0.0;
   out_5814428664983507972[182] = 0.0;
   out_5814428664983507972[183] = 0.0;
   out_5814428664983507972[184] = 0.0;
   out_5814428664983507972[185] = 0.0;
   out_5814428664983507972[186] = 0.0;
   out_5814428664983507972[187] = 0.0;
   out_5814428664983507972[188] = 0.0;
   out_5814428664983507972[189] = 0.0;
   out_5814428664983507972[190] = 1.0;
   out_5814428664983507972[191] = 0.0;
   out_5814428664983507972[192] = 0.0;
   out_5814428664983507972[193] = 0.0;
   out_5814428664983507972[194] = 0.0;
   out_5814428664983507972[195] = 0.0;
   out_5814428664983507972[196] = 0.0;
   out_5814428664983507972[197] = 0.0;
   out_5814428664983507972[198] = 0.0;
   out_5814428664983507972[199] = 0.0;
   out_5814428664983507972[200] = 0.0;
   out_5814428664983507972[201] = 0.0;
   out_5814428664983507972[202] = 0.0;
   out_5814428664983507972[203] = 0.0;
   out_5814428664983507972[204] = 0.0;
   out_5814428664983507972[205] = 0.0;
   out_5814428664983507972[206] = 0.0;
   out_5814428664983507972[207] = 0.0;
   out_5814428664983507972[208] = 0.0;
   out_5814428664983507972[209] = 1.0;
   out_5814428664983507972[210] = 0.0;
   out_5814428664983507972[211] = 0.0;
   out_5814428664983507972[212] = 0.0;
   out_5814428664983507972[213] = 0.0;
   out_5814428664983507972[214] = 0.0;
   out_5814428664983507972[215] = 0.0;
   out_5814428664983507972[216] = 0.0;
   out_5814428664983507972[217] = 0.0;
   out_5814428664983507972[218] = 0.0;
   out_5814428664983507972[219] = 0.0;
   out_5814428664983507972[220] = 0.0;
   out_5814428664983507972[221] = 0.0;
   out_5814428664983507972[222] = 0.0;
   out_5814428664983507972[223] = 0.0;
   out_5814428664983507972[224] = 0.0;
   out_5814428664983507972[225] = 0.0;
   out_5814428664983507972[226] = 0.0;
   out_5814428664983507972[227] = 0.0;
   out_5814428664983507972[228] = 1.0;
   out_5814428664983507972[229] = 0.0;
   out_5814428664983507972[230] = 0.0;
   out_5814428664983507972[231] = 0.0;
   out_5814428664983507972[232] = 0.0;
   out_5814428664983507972[233] = 0.0;
   out_5814428664983507972[234] = 0.0;
   out_5814428664983507972[235] = 0.0;
   out_5814428664983507972[236] = 0.0;
   out_5814428664983507972[237] = 0.0;
   out_5814428664983507972[238] = 0.0;
   out_5814428664983507972[239] = 0.0;
   out_5814428664983507972[240] = 0.0;
   out_5814428664983507972[241] = 0.0;
   out_5814428664983507972[242] = 0.0;
   out_5814428664983507972[243] = 0.0;
   out_5814428664983507972[244] = 0.0;
   out_5814428664983507972[245] = 0.0;
   out_5814428664983507972[246] = 0.0;
   out_5814428664983507972[247] = 1.0;
   out_5814428664983507972[248] = 0.0;
   out_5814428664983507972[249] = 0.0;
   out_5814428664983507972[250] = 0.0;
   out_5814428664983507972[251] = 0.0;
   out_5814428664983507972[252] = 0.0;
   out_5814428664983507972[253] = 0.0;
   out_5814428664983507972[254] = 0.0;
   out_5814428664983507972[255] = 0.0;
   out_5814428664983507972[256] = 0.0;
   out_5814428664983507972[257] = 0.0;
   out_5814428664983507972[258] = 0.0;
   out_5814428664983507972[259] = 0.0;
   out_5814428664983507972[260] = 0.0;
   out_5814428664983507972[261] = 0.0;
   out_5814428664983507972[262] = 0.0;
   out_5814428664983507972[263] = 0.0;
   out_5814428664983507972[264] = 0.0;
   out_5814428664983507972[265] = 0.0;
   out_5814428664983507972[266] = 1.0;
   out_5814428664983507972[267] = 0.0;
   out_5814428664983507972[268] = 0.0;
   out_5814428664983507972[269] = 0.0;
   out_5814428664983507972[270] = 0.0;
   out_5814428664983507972[271] = 0.0;
   out_5814428664983507972[272] = 0.0;
   out_5814428664983507972[273] = 0.0;
   out_5814428664983507972[274] = 0.0;
   out_5814428664983507972[275] = 0.0;
   out_5814428664983507972[276] = 0.0;
   out_5814428664983507972[277] = 0.0;
   out_5814428664983507972[278] = 0.0;
   out_5814428664983507972[279] = 0.0;
   out_5814428664983507972[280] = 0.0;
   out_5814428664983507972[281] = 0.0;
   out_5814428664983507972[282] = 0.0;
   out_5814428664983507972[283] = 0.0;
   out_5814428664983507972[284] = 0.0;
   out_5814428664983507972[285] = 1.0;
   out_5814428664983507972[286] = 0.0;
   out_5814428664983507972[287] = 0.0;
   out_5814428664983507972[288] = 0.0;
   out_5814428664983507972[289] = 0.0;
   out_5814428664983507972[290] = 0.0;
   out_5814428664983507972[291] = 0.0;
   out_5814428664983507972[292] = 0.0;
   out_5814428664983507972[293] = 0.0;
   out_5814428664983507972[294] = 0.0;
   out_5814428664983507972[295] = 0.0;
   out_5814428664983507972[296] = 0.0;
   out_5814428664983507972[297] = 0.0;
   out_5814428664983507972[298] = 0.0;
   out_5814428664983507972[299] = 0.0;
   out_5814428664983507972[300] = 0.0;
   out_5814428664983507972[301] = 0.0;
   out_5814428664983507972[302] = 0.0;
   out_5814428664983507972[303] = 0.0;
   out_5814428664983507972[304] = 1.0;
   out_5814428664983507972[305] = 0.0;
   out_5814428664983507972[306] = 0.0;
   out_5814428664983507972[307] = 0.0;
   out_5814428664983507972[308] = 0.0;
   out_5814428664983507972[309] = 0.0;
   out_5814428664983507972[310] = 0.0;
   out_5814428664983507972[311] = 0.0;
   out_5814428664983507972[312] = 0.0;
   out_5814428664983507972[313] = 0.0;
   out_5814428664983507972[314] = 0.0;
   out_5814428664983507972[315] = 0.0;
   out_5814428664983507972[316] = 0.0;
   out_5814428664983507972[317] = 0.0;
   out_5814428664983507972[318] = 0.0;
   out_5814428664983507972[319] = 0.0;
   out_5814428664983507972[320] = 0.0;
   out_5814428664983507972[321] = 0.0;
   out_5814428664983507972[322] = 0.0;
   out_5814428664983507972[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_5774518282165166048) {
   out_5774518282165166048[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_5774518282165166048[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_5774518282165166048[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_5774518282165166048[3] = dt*state[12] + state[3];
   out_5774518282165166048[4] = dt*state[13] + state[4];
   out_5774518282165166048[5] = dt*state[14] + state[5];
   out_5774518282165166048[6] = state[6];
   out_5774518282165166048[7] = state[7];
   out_5774518282165166048[8] = state[8];
   out_5774518282165166048[9] = state[9];
   out_5774518282165166048[10] = state[10];
   out_5774518282165166048[11] = state[11];
   out_5774518282165166048[12] = state[12];
   out_5774518282165166048[13] = state[13];
   out_5774518282165166048[14] = state[14];
   out_5774518282165166048[15] = state[15];
   out_5774518282165166048[16] = state[16];
   out_5774518282165166048[17] = state[17];
}
void F_fun(double *state, double dt, double *out_8025296144773174735) {
   out_8025296144773174735[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8025296144773174735[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8025296144773174735[2] = 0;
   out_8025296144773174735[3] = 0;
   out_8025296144773174735[4] = 0;
   out_8025296144773174735[5] = 0;
   out_8025296144773174735[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8025296144773174735[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8025296144773174735[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8025296144773174735[9] = 0;
   out_8025296144773174735[10] = 0;
   out_8025296144773174735[11] = 0;
   out_8025296144773174735[12] = 0;
   out_8025296144773174735[13] = 0;
   out_8025296144773174735[14] = 0;
   out_8025296144773174735[15] = 0;
   out_8025296144773174735[16] = 0;
   out_8025296144773174735[17] = 0;
   out_8025296144773174735[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8025296144773174735[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8025296144773174735[20] = 0;
   out_8025296144773174735[21] = 0;
   out_8025296144773174735[22] = 0;
   out_8025296144773174735[23] = 0;
   out_8025296144773174735[24] = 0;
   out_8025296144773174735[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8025296144773174735[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8025296144773174735[27] = 0;
   out_8025296144773174735[28] = 0;
   out_8025296144773174735[29] = 0;
   out_8025296144773174735[30] = 0;
   out_8025296144773174735[31] = 0;
   out_8025296144773174735[32] = 0;
   out_8025296144773174735[33] = 0;
   out_8025296144773174735[34] = 0;
   out_8025296144773174735[35] = 0;
   out_8025296144773174735[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8025296144773174735[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8025296144773174735[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8025296144773174735[39] = 0;
   out_8025296144773174735[40] = 0;
   out_8025296144773174735[41] = 0;
   out_8025296144773174735[42] = 0;
   out_8025296144773174735[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8025296144773174735[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8025296144773174735[45] = 0;
   out_8025296144773174735[46] = 0;
   out_8025296144773174735[47] = 0;
   out_8025296144773174735[48] = 0;
   out_8025296144773174735[49] = 0;
   out_8025296144773174735[50] = 0;
   out_8025296144773174735[51] = 0;
   out_8025296144773174735[52] = 0;
   out_8025296144773174735[53] = 0;
   out_8025296144773174735[54] = 0;
   out_8025296144773174735[55] = 0;
   out_8025296144773174735[56] = 0;
   out_8025296144773174735[57] = 1;
   out_8025296144773174735[58] = 0;
   out_8025296144773174735[59] = 0;
   out_8025296144773174735[60] = 0;
   out_8025296144773174735[61] = 0;
   out_8025296144773174735[62] = 0;
   out_8025296144773174735[63] = 0;
   out_8025296144773174735[64] = 0;
   out_8025296144773174735[65] = 0;
   out_8025296144773174735[66] = dt;
   out_8025296144773174735[67] = 0;
   out_8025296144773174735[68] = 0;
   out_8025296144773174735[69] = 0;
   out_8025296144773174735[70] = 0;
   out_8025296144773174735[71] = 0;
   out_8025296144773174735[72] = 0;
   out_8025296144773174735[73] = 0;
   out_8025296144773174735[74] = 0;
   out_8025296144773174735[75] = 0;
   out_8025296144773174735[76] = 1;
   out_8025296144773174735[77] = 0;
   out_8025296144773174735[78] = 0;
   out_8025296144773174735[79] = 0;
   out_8025296144773174735[80] = 0;
   out_8025296144773174735[81] = 0;
   out_8025296144773174735[82] = 0;
   out_8025296144773174735[83] = 0;
   out_8025296144773174735[84] = 0;
   out_8025296144773174735[85] = dt;
   out_8025296144773174735[86] = 0;
   out_8025296144773174735[87] = 0;
   out_8025296144773174735[88] = 0;
   out_8025296144773174735[89] = 0;
   out_8025296144773174735[90] = 0;
   out_8025296144773174735[91] = 0;
   out_8025296144773174735[92] = 0;
   out_8025296144773174735[93] = 0;
   out_8025296144773174735[94] = 0;
   out_8025296144773174735[95] = 1;
   out_8025296144773174735[96] = 0;
   out_8025296144773174735[97] = 0;
   out_8025296144773174735[98] = 0;
   out_8025296144773174735[99] = 0;
   out_8025296144773174735[100] = 0;
   out_8025296144773174735[101] = 0;
   out_8025296144773174735[102] = 0;
   out_8025296144773174735[103] = 0;
   out_8025296144773174735[104] = dt;
   out_8025296144773174735[105] = 0;
   out_8025296144773174735[106] = 0;
   out_8025296144773174735[107] = 0;
   out_8025296144773174735[108] = 0;
   out_8025296144773174735[109] = 0;
   out_8025296144773174735[110] = 0;
   out_8025296144773174735[111] = 0;
   out_8025296144773174735[112] = 0;
   out_8025296144773174735[113] = 0;
   out_8025296144773174735[114] = 1;
   out_8025296144773174735[115] = 0;
   out_8025296144773174735[116] = 0;
   out_8025296144773174735[117] = 0;
   out_8025296144773174735[118] = 0;
   out_8025296144773174735[119] = 0;
   out_8025296144773174735[120] = 0;
   out_8025296144773174735[121] = 0;
   out_8025296144773174735[122] = 0;
   out_8025296144773174735[123] = 0;
   out_8025296144773174735[124] = 0;
   out_8025296144773174735[125] = 0;
   out_8025296144773174735[126] = 0;
   out_8025296144773174735[127] = 0;
   out_8025296144773174735[128] = 0;
   out_8025296144773174735[129] = 0;
   out_8025296144773174735[130] = 0;
   out_8025296144773174735[131] = 0;
   out_8025296144773174735[132] = 0;
   out_8025296144773174735[133] = 1;
   out_8025296144773174735[134] = 0;
   out_8025296144773174735[135] = 0;
   out_8025296144773174735[136] = 0;
   out_8025296144773174735[137] = 0;
   out_8025296144773174735[138] = 0;
   out_8025296144773174735[139] = 0;
   out_8025296144773174735[140] = 0;
   out_8025296144773174735[141] = 0;
   out_8025296144773174735[142] = 0;
   out_8025296144773174735[143] = 0;
   out_8025296144773174735[144] = 0;
   out_8025296144773174735[145] = 0;
   out_8025296144773174735[146] = 0;
   out_8025296144773174735[147] = 0;
   out_8025296144773174735[148] = 0;
   out_8025296144773174735[149] = 0;
   out_8025296144773174735[150] = 0;
   out_8025296144773174735[151] = 0;
   out_8025296144773174735[152] = 1;
   out_8025296144773174735[153] = 0;
   out_8025296144773174735[154] = 0;
   out_8025296144773174735[155] = 0;
   out_8025296144773174735[156] = 0;
   out_8025296144773174735[157] = 0;
   out_8025296144773174735[158] = 0;
   out_8025296144773174735[159] = 0;
   out_8025296144773174735[160] = 0;
   out_8025296144773174735[161] = 0;
   out_8025296144773174735[162] = 0;
   out_8025296144773174735[163] = 0;
   out_8025296144773174735[164] = 0;
   out_8025296144773174735[165] = 0;
   out_8025296144773174735[166] = 0;
   out_8025296144773174735[167] = 0;
   out_8025296144773174735[168] = 0;
   out_8025296144773174735[169] = 0;
   out_8025296144773174735[170] = 0;
   out_8025296144773174735[171] = 1;
   out_8025296144773174735[172] = 0;
   out_8025296144773174735[173] = 0;
   out_8025296144773174735[174] = 0;
   out_8025296144773174735[175] = 0;
   out_8025296144773174735[176] = 0;
   out_8025296144773174735[177] = 0;
   out_8025296144773174735[178] = 0;
   out_8025296144773174735[179] = 0;
   out_8025296144773174735[180] = 0;
   out_8025296144773174735[181] = 0;
   out_8025296144773174735[182] = 0;
   out_8025296144773174735[183] = 0;
   out_8025296144773174735[184] = 0;
   out_8025296144773174735[185] = 0;
   out_8025296144773174735[186] = 0;
   out_8025296144773174735[187] = 0;
   out_8025296144773174735[188] = 0;
   out_8025296144773174735[189] = 0;
   out_8025296144773174735[190] = 1;
   out_8025296144773174735[191] = 0;
   out_8025296144773174735[192] = 0;
   out_8025296144773174735[193] = 0;
   out_8025296144773174735[194] = 0;
   out_8025296144773174735[195] = 0;
   out_8025296144773174735[196] = 0;
   out_8025296144773174735[197] = 0;
   out_8025296144773174735[198] = 0;
   out_8025296144773174735[199] = 0;
   out_8025296144773174735[200] = 0;
   out_8025296144773174735[201] = 0;
   out_8025296144773174735[202] = 0;
   out_8025296144773174735[203] = 0;
   out_8025296144773174735[204] = 0;
   out_8025296144773174735[205] = 0;
   out_8025296144773174735[206] = 0;
   out_8025296144773174735[207] = 0;
   out_8025296144773174735[208] = 0;
   out_8025296144773174735[209] = 1;
   out_8025296144773174735[210] = 0;
   out_8025296144773174735[211] = 0;
   out_8025296144773174735[212] = 0;
   out_8025296144773174735[213] = 0;
   out_8025296144773174735[214] = 0;
   out_8025296144773174735[215] = 0;
   out_8025296144773174735[216] = 0;
   out_8025296144773174735[217] = 0;
   out_8025296144773174735[218] = 0;
   out_8025296144773174735[219] = 0;
   out_8025296144773174735[220] = 0;
   out_8025296144773174735[221] = 0;
   out_8025296144773174735[222] = 0;
   out_8025296144773174735[223] = 0;
   out_8025296144773174735[224] = 0;
   out_8025296144773174735[225] = 0;
   out_8025296144773174735[226] = 0;
   out_8025296144773174735[227] = 0;
   out_8025296144773174735[228] = 1;
   out_8025296144773174735[229] = 0;
   out_8025296144773174735[230] = 0;
   out_8025296144773174735[231] = 0;
   out_8025296144773174735[232] = 0;
   out_8025296144773174735[233] = 0;
   out_8025296144773174735[234] = 0;
   out_8025296144773174735[235] = 0;
   out_8025296144773174735[236] = 0;
   out_8025296144773174735[237] = 0;
   out_8025296144773174735[238] = 0;
   out_8025296144773174735[239] = 0;
   out_8025296144773174735[240] = 0;
   out_8025296144773174735[241] = 0;
   out_8025296144773174735[242] = 0;
   out_8025296144773174735[243] = 0;
   out_8025296144773174735[244] = 0;
   out_8025296144773174735[245] = 0;
   out_8025296144773174735[246] = 0;
   out_8025296144773174735[247] = 1;
   out_8025296144773174735[248] = 0;
   out_8025296144773174735[249] = 0;
   out_8025296144773174735[250] = 0;
   out_8025296144773174735[251] = 0;
   out_8025296144773174735[252] = 0;
   out_8025296144773174735[253] = 0;
   out_8025296144773174735[254] = 0;
   out_8025296144773174735[255] = 0;
   out_8025296144773174735[256] = 0;
   out_8025296144773174735[257] = 0;
   out_8025296144773174735[258] = 0;
   out_8025296144773174735[259] = 0;
   out_8025296144773174735[260] = 0;
   out_8025296144773174735[261] = 0;
   out_8025296144773174735[262] = 0;
   out_8025296144773174735[263] = 0;
   out_8025296144773174735[264] = 0;
   out_8025296144773174735[265] = 0;
   out_8025296144773174735[266] = 1;
   out_8025296144773174735[267] = 0;
   out_8025296144773174735[268] = 0;
   out_8025296144773174735[269] = 0;
   out_8025296144773174735[270] = 0;
   out_8025296144773174735[271] = 0;
   out_8025296144773174735[272] = 0;
   out_8025296144773174735[273] = 0;
   out_8025296144773174735[274] = 0;
   out_8025296144773174735[275] = 0;
   out_8025296144773174735[276] = 0;
   out_8025296144773174735[277] = 0;
   out_8025296144773174735[278] = 0;
   out_8025296144773174735[279] = 0;
   out_8025296144773174735[280] = 0;
   out_8025296144773174735[281] = 0;
   out_8025296144773174735[282] = 0;
   out_8025296144773174735[283] = 0;
   out_8025296144773174735[284] = 0;
   out_8025296144773174735[285] = 1;
   out_8025296144773174735[286] = 0;
   out_8025296144773174735[287] = 0;
   out_8025296144773174735[288] = 0;
   out_8025296144773174735[289] = 0;
   out_8025296144773174735[290] = 0;
   out_8025296144773174735[291] = 0;
   out_8025296144773174735[292] = 0;
   out_8025296144773174735[293] = 0;
   out_8025296144773174735[294] = 0;
   out_8025296144773174735[295] = 0;
   out_8025296144773174735[296] = 0;
   out_8025296144773174735[297] = 0;
   out_8025296144773174735[298] = 0;
   out_8025296144773174735[299] = 0;
   out_8025296144773174735[300] = 0;
   out_8025296144773174735[301] = 0;
   out_8025296144773174735[302] = 0;
   out_8025296144773174735[303] = 0;
   out_8025296144773174735[304] = 1;
   out_8025296144773174735[305] = 0;
   out_8025296144773174735[306] = 0;
   out_8025296144773174735[307] = 0;
   out_8025296144773174735[308] = 0;
   out_8025296144773174735[309] = 0;
   out_8025296144773174735[310] = 0;
   out_8025296144773174735[311] = 0;
   out_8025296144773174735[312] = 0;
   out_8025296144773174735[313] = 0;
   out_8025296144773174735[314] = 0;
   out_8025296144773174735[315] = 0;
   out_8025296144773174735[316] = 0;
   out_8025296144773174735[317] = 0;
   out_8025296144773174735[318] = 0;
   out_8025296144773174735[319] = 0;
   out_8025296144773174735[320] = 0;
   out_8025296144773174735[321] = 0;
   out_8025296144773174735[322] = 0;
   out_8025296144773174735[323] = 1;
}
void h_4(double *state, double *unused, double *out_8507801575896652222) {
   out_8507801575896652222[0] = state[6] + state[9];
   out_8507801575896652222[1] = state[7] + state[10];
   out_8507801575896652222[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_4616481183100609868) {
   out_4616481183100609868[0] = 0;
   out_4616481183100609868[1] = 0;
   out_4616481183100609868[2] = 0;
   out_4616481183100609868[3] = 0;
   out_4616481183100609868[4] = 0;
   out_4616481183100609868[5] = 0;
   out_4616481183100609868[6] = 1;
   out_4616481183100609868[7] = 0;
   out_4616481183100609868[8] = 0;
   out_4616481183100609868[9] = 1;
   out_4616481183100609868[10] = 0;
   out_4616481183100609868[11] = 0;
   out_4616481183100609868[12] = 0;
   out_4616481183100609868[13] = 0;
   out_4616481183100609868[14] = 0;
   out_4616481183100609868[15] = 0;
   out_4616481183100609868[16] = 0;
   out_4616481183100609868[17] = 0;
   out_4616481183100609868[18] = 0;
   out_4616481183100609868[19] = 0;
   out_4616481183100609868[20] = 0;
   out_4616481183100609868[21] = 0;
   out_4616481183100609868[22] = 0;
   out_4616481183100609868[23] = 0;
   out_4616481183100609868[24] = 0;
   out_4616481183100609868[25] = 1;
   out_4616481183100609868[26] = 0;
   out_4616481183100609868[27] = 0;
   out_4616481183100609868[28] = 1;
   out_4616481183100609868[29] = 0;
   out_4616481183100609868[30] = 0;
   out_4616481183100609868[31] = 0;
   out_4616481183100609868[32] = 0;
   out_4616481183100609868[33] = 0;
   out_4616481183100609868[34] = 0;
   out_4616481183100609868[35] = 0;
   out_4616481183100609868[36] = 0;
   out_4616481183100609868[37] = 0;
   out_4616481183100609868[38] = 0;
   out_4616481183100609868[39] = 0;
   out_4616481183100609868[40] = 0;
   out_4616481183100609868[41] = 0;
   out_4616481183100609868[42] = 0;
   out_4616481183100609868[43] = 0;
   out_4616481183100609868[44] = 1;
   out_4616481183100609868[45] = 0;
   out_4616481183100609868[46] = 0;
   out_4616481183100609868[47] = 1;
   out_4616481183100609868[48] = 0;
   out_4616481183100609868[49] = 0;
   out_4616481183100609868[50] = 0;
   out_4616481183100609868[51] = 0;
   out_4616481183100609868[52] = 0;
   out_4616481183100609868[53] = 0;
}
void h_10(double *state, double *unused, double *out_4484960606295619259) {
   out_4484960606295619259[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_4484960606295619259[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_4484960606295619259[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_3400459211528847226) {
   out_3400459211528847226[0] = 0;
   out_3400459211528847226[1] = 9.8100000000000005*cos(state[1]);
   out_3400459211528847226[2] = 0;
   out_3400459211528847226[3] = 0;
   out_3400459211528847226[4] = -state[8];
   out_3400459211528847226[5] = state[7];
   out_3400459211528847226[6] = 0;
   out_3400459211528847226[7] = state[5];
   out_3400459211528847226[8] = -state[4];
   out_3400459211528847226[9] = 0;
   out_3400459211528847226[10] = 0;
   out_3400459211528847226[11] = 0;
   out_3400459211528847226[12] = 1;
   out_3400459211528847226[13] = 0;
   out_3400459211528847226[14] = 0;
   out_3400459211528847226[15] = 1;
   out_3400459211528847226[16] = 0;
   out_3400459211528847226[17] = 0;
   out_3400459211528847226[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_3400459211528847226[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_3400459211528847226[20] = 0;
   out_3400459211528847226[21] = state[8];
   out_3400459211528847226[22] = 0;
   out_3400459211528847226[23] = -state[6];
   out_3400459211528847226[24] = -state[5];
   out_3400459211528847226[25] = 0;
   out_3400459211528847226[26] = state[3];
   out_3400459211528847226[27] = 0;
   out_3400459211528847226[28] = 0;
   out_3400459211528847226[29] = 0;
   out_3400459211528847226[30] = 0;
   out_3400459211528847226[31] = 1;
   out_3400459211528847226[32] = 0;
   out_3400459211528847226[33] = 0;
   out_3400459211528847226[34] = 1;
   out_3400459211528847226[35] = 0;
   out_3400459211528847226[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_3400459211528847226[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_3400459211528847226[38] = 0;
   out_3400459211528847226[39] = -state[7];
   out_3400459211528847226[40] = state[6];
   out_3400459211528847226[41] = 0;
   out_3400459211528847226[42] = state[4];
   out_3400459211528847226[43] = -state[3];
   out_3400459211528847226[44] = 0;
   out_3400459211528847226[45] = 0;
   out_3400459211528847226[46] = 0;
   out_3400459211528847226[47] = 0;
   out_3400459211528847226[48] = 0;
   out_3400459211528847226[49] = 0;
   out_3400459211528847226[50] = 1;
   out_3400459211528847226[51] = 0;
   out_3400459211528847226[52] = 0;
   out_3400459211528847226[53] = 1;
}
void h_13(double *state, double *unused, double *out_3480051689038598104) {
   out_3480051689038598104[0] = state[3];
   out_3480051689038598104[1] = state[4];
   out_3480051689038598104[2] = state[5];
}
void H_13(double *state, double *unused, double *out_1404207357768277067) {
   out_1404207357768277067[0] = 0;
   out_1404207357768277067[1] = 0;
   out_1404207357768277067[2] = 0;
   out_1404207357768277067[3] = 1;
   out_1404207357768277067[4] = 0;
   out_1404207357768277067[5] = 0;
   out_1404207357768277067[6] = 0;
   out_1404207357768277067[7] = 0;
   out_1404207357768277067[8] = 0;
   out_1404207357768277067[9] = 0;
   out_1404207357768277067[10] = 0;
   out_1404207357768277067[11] = 0;
   out_1404207357768277067[12] = 0;
   out_1404207357768277067[13] = 0;
   out_1404207357768277067[14] = 0;
   out_1404207357768277067[15] = 0;
   out_1404207357768277067[16] = 0;
   out_1404207357768277067[17] = 0;
   out_1404207357768277067[18] = 0;
   out_1404207357768277067[19] = 0;
   out_1404207357768277067[20] = 0;
   out_1404207357768277067[21] = 0;
   out_1404207357768277067[22] = 1;
   out_1404207357768277067[23] = 0;
   out_1404207357768277067[24] = 0;
   out_1404207357768277067[25] = 0;
   out_1404207357768277067[26] = 0;
   out_1404207357768277067[27] = 0;
   out_1404207357768277067[28] = 0;
   out_1404207357768277067[29] = 0;
   out_1404207357768277067[30] = 0;
   out_1404207357768277067[31] = 0;
   out_1404207357768277067[32] = 0;
   out_1404207357768277067[33] = 0;
   out_1404207357768277067[34] = 0;
   out_1404207357768277067[35] = 0;
   out_1404207357768277067[36] = 0;
   out_1404207357768277067[37] = 0;
   out_1404207357768277067[38] = 0;
   out_1404207357768277067[39] = 0;
   out_1404207357768277067[40] = 0;
   out_1404207357768277067[41] = 1;
   out_1404207357768277067[42] = 0;
   out_1404207357768277067[43] = 0;
   out_1404207357768277067[44] = 0;
   out_1404207357768277067[45] = 0;
   out_1404207357768277067[46] = 0;
   out_1404207357768277067[47] = 0;
   out_1404207357768277067[48] = 0;
   out_1404207357768277067[49] = 0;
   out_1404207357768277067[50] = 0;
   out_1404207357768277067[51] = 0;
   out_1404207357768277067[52] = 0;
   out_1404207357768277067[53] = 0;
}
void h_14(double *state, double *unused, double *out_8093714864730119229) {
   out_8093714864730119229[0] = state[6];
   out_8093714864730119229[1] = state[7];
   out_8093714864730119229[2] = state[8];
}
void H_14(double *state, double *unused, double *out_7699269615395982164) {
   out_7699269615395982164[0] = 0;
   out_7699269615395982164[1] = 0;
   out_7699269615395982164[2] = 0;
   out_7699269615395982164[3] = 0;
   out_7699269615395982164[4] = 0;
   out_7699269615395982164[5] = 0;
   out_7699269615395982164[6] = 1;
   out_7699269615395982164[7] = 0;
   out_7699269615395982164[8] = 0;
   out_7699269615395982164[9] = 0;
   out_7699269615395982164[10] = 0;
   out_7699269615395982164[11] = 0;
   out_7699269615395982164[12] = 0;
   out_7699269615395982164[13] = 0;
   out_7699269615395982164[14] = 0;
   out_7699269615395982164[15] = 0;
   out_7699269615395982164[16] = 0;
   out_7699269615395982164[17] = 0;
   out_7699269615395982164[18] = 0;
   out_7699269615395982164[19] = 0;
   out_7699269615395982164[20] = 0;
   out_7699269615395982164[21] = 0;
   out_7699269615395982164[22] = 0;
   out_7699269615395982164[23] = 0;
   out_7699269615395982164[24] = 0;
   out_7699269615395982164[25] = 1;
   out_7699269615395982164[26] = 0;
   out_7699269615395982164[27] = 0;
   out_7699269615395982164[28] = 0;
   out_7699269615395982164[29] = 0;
   out_7699269615395982164[30] = 0;
   out_7699269615395982164[31] = 0;
   out_7699269615395982164[32] = 0;
   out_7699269615395982164[33] = 0;
   out_7699269615395982164[34] = 0;
   out_7699269615395982164[35] = 0;
   out_7699269615395982164[36] = 0;
   out_7699269615395982164[37] = 0;
   out_7699269615395982164[38] = 0;
   out_7699269615395982164[39] = 0;
   out_7699269615395982164[40] = 0;
   out_7699269615395982164[41] = 0;
   out_7699269615395982164[42] = 0;
   out_7699269615395982164[43] = 0;
   out_7699269615395982164[44] = 1;
   out_7699269615395982164[45] = 0;
   out_7699269615395982164[46] = 0;
   out_7699269615395982164[47] = 0;
   out_7699269615395982164[48] = 0;
   out_7699269615395982164[49] = 0;
   out_7699269615395982164[50] = 0;
   out_7699269615395982164[51] = 0;
   out_7699269615395982164[52] = 0;
   out_7699269615395982164[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_7569354656790451798) {
  err_fun(nom_x, delta_x, out_7569354656790451798);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4882156975285941590) {
  inv_err_fun(nom_x, true_x, out_4882156975285941590);
}
void pose_H_mod_fun(double *state, double *out_5814428664983507972) {
  H_mod_fun(state, out_5814428664983507972);
}
void pose_f_fun(double *state, double dt, double *out_5774518282165166048) {
  f_fun(state,  dt, out_5774518282165166048);
}
void pose_F_fun(double *state, double dt, double *out_8025296144773174735) {
  F_fun(state,  dt, out_8025296144773174735);
}
void pose_h_4(double *state, double *unused, double *out_8507801575896652222) {
  h_4(state, unused, out_8507801575896652222);
}
void pose_H_4(double *state, double *unused, double *out_4616481183100609868) {
  H_4(state, unused, out_4616481183100609868);
}
void pose_h_10(double *state, double *unused, double *out_4484960606295619259) {
  h_10(state, unused, out_4484960606295619259);
}
void pose_H_10(double *state, double *unused, double *out_3400459211528847226) {
  H_10(state, unused, out_3400459211528847226);
}
void pose_h_13(double *state, double *unused, double *out_3480051689038598104) {
  h_13(state, unused, out_3480051689038598104);
}
void pose_H_13(double *state, double *unused, double *out_1404207357768277067) {
  H_13(state, unused, out_1404207357768277067);
}
void pose_h_14(double *state, double *unused, double *out_8093714864730119229) {
  h_14(state, unused, out_8093714864730119229);
}
void pose_H_14(double *state, double *unused, double *out_7699269615395982164) {
  H_14(state, unused, out_7699269615395982164);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
