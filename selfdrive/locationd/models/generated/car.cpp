#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_977553736874856114) {
   out_977553736874856114[0] = delta_x[0] + nom_x[0];
   out_977553736874856114[1] = delta_x[1] + nom_x[1];
   out_977553736874856114[2] = delta_x[2] + nom_x[2];
   out_977553736874856114[3] = delta_x[3] + nom_x[3];
   out_977553736874856114[4] = delta_x[4] + nom_x[4];
   out_977553736874856114[5] = delta_x[5] + nom_x[5];
   out_977553736874856114[6] = delta_x[6] + nom_x[6];
   out_977553736874856114[7] = delta_x[7] + nom_x[7];
   out_977553736874856114[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_778623081939477042) {
   out_778623081939477042[0] = -nom_x[0] + true_x[0];
   out_778623081939477042[1] = -nom_x[1] + true_x[1];
   out_778623081939477042[2] = -nom_x[2] + true_x[2];
   out_778623081939477042[3] = -nom_x[3] + true_x[3];
   out_778623081939477042[4] = -nom_x[4] + true_x[4];
   out_778623081939477042[5] = -nom_x[5] + true_x[5];
   out_778623081939477042[6] = -nom_x[6] + true_x[6];
   out_778623081939477042[7] = -nom_x[7] + true_x[7];
   out_778623081939477042[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_2435242585289315952) {
   out_2435242585289315952[0] = 1.0;
   out_2435242585289315952[1] = 0.0;
   out_2435242585289315952[2] = 0.0;
   out_2435242585289315952[3] = 0.0;
   out_2435242585289315952[4] = 0.0;
   out_2435242585289315952[5] = 0.0;
   out_2435242585289315952[6] = 0.0;
   out_2435242585289315952[7] = 0.0;
   out_2435242585289315952[8] = 0.0;
   out_2435242585289315952[9] = 0.0;
   out_2435242585289315952[10] = 1.0;
   out_2435242585289315952[11] = 0.0;
   out_2435242585289315952[12] = 0.0;
   out_2435242585289315952[13] = 0.0;
   out_2435242585289315952[14] = 0.0;
   out_2435242585289315952[15] = 0.0;
   out_2435242585289315952[16] = 0.0;
   out_2435242585289315952[17] = 0.0;
   out_2435242585289315952[18] = 0.0;
   out_2435242585289315952[19] = 0.0;
   out_2435242585289315952[20] = 1.0;
   out_2435242585289315952[21] = 0.0;
   out_2435242585289315952[22] = 0.0;
   out_2435242585289315952[23] = 0.0;
   out_2435242585289315952[24] = 0.0;
   out_2435242585289315952[25] = 0.0;
   out_2435242585289315952[26] = 0.0;
   out_2435242585289315952[27] = 0.0;
   out_2435242585289315952[28] = 0.0;
   out_2435242585289315952[29] = 0.0;
   out_2435242585289315952[30] = 1.0;
   out_2435242585289315952[31] = 0.0;
   out_2435242585289315952[32] = 0.0;
   out_2435242585289315952[33] = 0.0;
   out_2435242585289315952[34] = 0.0;
   out_2435242585289315952[35] = 0.0;
   out_2435242585289315952[36] = 0.0;
   out_2435242585289315952[37] = 0.0;
   out_2435242585289315952[38] = 0.0;
   out_2435242585289315952[39] = 0.0;
   out_2435242585289315952[40] = 1.0;
   out_2435242585289315952[41] = 0.0;
   out_2435242585289315952[42] = 0.0;
   out_2435242585289315952[43] = 0.0;
   out_2435242585289315952[44] = 0.0;
   out_2435242585289315952[45] = 0.0;
   out_2435242585289315952[46] = 0.0;
   out_2435242585289315952[47] = 0.0;
   out_2435242585289315952[48] = 0.0;
   out_2435242585289315952[49] = 0.0;
   out_2435242585289315952[50] = 1.0;
   out_2435242585289315952[51] = 0.0;
   out_2435242585289315952[52] = 0.0;
   out_2435242585289315952[53] = 0.0;
   out_2435242585289315952[54] = 0.0;
   out_2435242585289315952[55] = 0.0;
   out_2435242585289315952[56] = 0.0;
   out_2435242585289315952[57] = 0.0;
   out_2435242585289315952[58] = 0.0;
   out_2435242585289315952[59] = 0.0;
   out_2435242585289315952[60] = 1.0;
   out_2435242585289315952[61] = 0.0;
   out_2435242585289315952[62] = 0.0;
   out_2435242585289315952[63] = 0.0;
   out_2435242585289315952[64] = 0.0;
   out_2435242585289315952[65] = 0.0;
   out_2435242585289315952[66] = 0.0;
   out_2435242585289315952[67] = 0.0;
   out_2435242585289315952[68] = 0.0;
   out_2435242585289315952[69] = 0.0;
   out_2435242585289315952[70] = 1.0;
   out_2435242585289315952[71] = 0.0;
   out_2435242585289315952[72] = 0.0;
   out_2435242585289315952[73] = 0.0;
   out_2435242585289315952[74] = 0.0;
   out_2435242585289315952[75] = 0.0;
   out_2435242585289315952[76] = 0.0;
   out_2435242585289315952[77] = 0.0;
   out_2435242585289315952[78] = 0.0;
   out_2435242585289315952[79] = 0.0;
   out_2435242585289315952[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_7003703653612928503) {
   out_7003703653612928503[0] = state[0];
   out_7003703653612928503[1] = state[1];
   out_7003703653612928503[2] = state[2];
   out_7003703653612928503[3] = state[3];
   out_7003703653612928503[4] = state[4];
   out_7003703653612928503[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_7003703653612928503[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_7003703653612928503[7] = state[7];
   out_7003703653612928503[8] = state[8];
}
void F_fun(double *state, double dt, double *out_8514390697440110489) {
   out_8514390697440110489[0] = 1;
   out_8514390697440110489[1] = 0;
   out_8514390697440110489[2] = 0;
   out_8514390697440110489[3] = 0;
   out_8514390697440110489[4] = 0;
   out_8514390697440110489[5] = 0;
   out_8514390697440110489[6] = 0;
   out_8514390697440110489[7] = 0;
   out_8514390697440110489[8] = 0;
   out_8514390697440110489[9] = 0;
   out_8514390697440110489[10] = 1;
   out_8514390697440110489[11] = 0;
   out_8514390697440110489[12] = 0;
   out_8514390697440110489[13] = 0;
   out_8514390697440110489[14] = 0;
   out_8514390697440110489[15] = 0;
   out_8514390697440110489[16] = 0;
   out_8514390697440110489[17] = 0;
   out_8514390697440110489[18] = 0;
   out_8514390697440110489[19] = 0;
   out_8514390697440110489[20] = 1;
   out_8514390697440110489[21] = 0;
   out_8514390697440110489[22] = 0;
   out_8514390697440110489[23] = 0;
   out_8514390697440110489[24] = 0;
   out_8514390697440110489[25] = 0;
   out_8514390697440110489[26] = 0;
   out_8514390697440110489[27] = 0;
   out_8514390697440110489[28] = 0;
   out_8514390697440110489[29] = 0;
   out_8514390697440110489[30] = 1;
   out_8514390697440110489[31] = 0;
   out_8514390697440110489[32] = 0;
   out_8514390697440110489[33] = 0;
   out_8514390697440110489[34] = 0;
   out_8514390697440110489[35] = 0;
   out_8514390697440110489[36] = 0;
   out_8514390697440110489[37] = 0;
   out_8514390697440110489[38] = 0;
   out_8514390697440110489[39] = 0;
   out_8514390697440110489[40] = 1;
   out_8514390697440110489[41] = 0;
   out_8514390697440110489[42] = 0;
   out_8514390697440110489[43] = 0;
   out_8514390697440110489[44] = 0;
   out_8514390697440110489[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_8514390697440110489[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_8514390697440110489[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8514390697440110489[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8514390697440110489[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_8514390697440110489[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_8514390697440110489[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_8514390697440110489[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_8514390697440110489[53] = -9.8100000000000005*dt;
   out_8514390697440110489[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_8514390697440110489[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_8514390697440110489[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8514390697440110489[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8514390697440110489[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_8514390697440110489[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_8514390697440110489[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_8514390697440110489[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8514390697440110489[62] = 0;
   out_8514390697440110489[63] = 0;
   out_8514390697440110489[64] = 0;
   out_8514390697440110489[65] = 0;
   out_8514390697440110489[66] = 0;
   out_8514390697440110489[67] = 0;
   out_8514390697440110489[68] = 0;
   out_8514390697440110489[69] = 0;
   out_8514390697440110489[70] = 1;
   out_8514390697440110489[71] = 0;
   out_8514390697440110489[72] = 0;
   out_8514390697440110489[73] = 0;
   out_8514390697440110489[74] = 0;
   out_8514390697440110489[75] = 0;
   out_8514390697440110489[76] = 0;
   out_8514390697440110489[77] = 0;
   out_8514390697440110489[78] = 0;
   out_8514390697440110489[79] = 0;
   out_8514390697440110489[80] = 1;
}
void h_25(double *state, double *unused, double *out_2496555721360409747) {
   out_2496555721360409747[0] = state[6];
}
void H_25(double *state, double *unused, double *out_1087806053356049196) {
   out_1087806053356049196[0] = 0;
   out_1087806053356049196[1] = 0;
   out_1087806053356049196[2] = 0;
   out_1087806053356049196[3] = 0;
   out_1087806053356049196[4] = 0;
   out_1087806053356049196[5] = 0;
   out_1087806053356049196[6] = 1;
   out_1087806053356049196[7] = 0;
   out_1087806053356049196[8] = 0;
}
void h_24(double *state, double *unused, double *out_7811460842896347719) {
   out_7811460842896347719[0] = state[4];
   out_7811460842896347719[1] = state[5];
}
void H_24(double *state, double *unused, double *out_2470119545446273940) {
   out_2470119545446273940[0] = 0;
   out_2470119545446273940[1] = 0;
   out_2470119545446273940[2] = 0;
   out_2470119545446273940[3] = 0;
   out_2470119545446273940[4] = 1;
   out_2470119545446273940[5] = 0;
   out_2470119545446273940[6] = 0;
   out_2470119545446273940[7] = 0;
   out_2470119545446273940[8] = 0;
   out_2470119545446273940[9] = 0;
   out_2470119545446273940[10] = 0;
   out_2470119545446273940[11] = 0;
   out_2470119545446273940[12] = 0;
   out_2470119545446273940[13] = 0;
   out_2470119545446273940[14] = 1;
   out_2470119545446273940[15] = 0;
   out_2470119545446273940[16] = 0;
   out_2470119545446273940[17] = 0;
}
void h_30(double *state, double *unused, double *out_7310310875630599985) {
   out_7310310875630599985[0] = state[4];
}
void H_30(double *state, double *unused, double *out_5828884288135567559) {
   out_5828884288135567559[0] = 0;
   out_5828884288135567559[1] = 0;
   out_5828884288135567559[2] = 0;
   out_5828884288135567559[3] = 0;
   out_5828884288135567559[4] = 1;
   out_5828884288135567559[5] = 0;
   out_5828884288135567559[6] = 0;
   out_5828884288135567559[7] = 0;
   out_5828884288135567559[8] = 0;
}
void h_26(double *state, double *unused, double *out_2308637607969754340) {
   out_2308637607969754340[0] = state[7];
}
void H_26(double *state, double *unused, double *out_2216719916404751405) {
   out_2216719916404751405[0] = 0;
   out_2216719916404751405[1] = 0;
   out_2216719916404751405[2] = 0;
   out_2216719916404751405[3] = 0;
   out_2216719916404751405[4] = 0;
   out_2216719916404751405[5] = 0;
   out_2216719916404751405[6] = 0;
   out_2216719916404751405[7] = 1;
   out_2216719916404751405[8] = 0;
}
void h_27(double *state, double *unused, double *out_2426645001903131084) {
   out_2426645001903131084[0] = state[3];
}
void H_27(double *state, double *unused, double *out_3654120976335142648) {
   out_3654120976335142648[0] = 0;
   out_3654120976335142648[1] = 0;
   out_3654120976335142648[2] = 0;
   out_3654120976335142648[3] = 1;
   out_3654120976335142648[4] = 0;
   out_3654120976335142648[5] = 0;
   out_3654120976335142648[6] = 0;
   out_3654120976335142648[7] = 0;
   out_3654120976335142648[8] = 0;
}
void h_29(double *state, double *unused, double *out_6366801022728937550) {
   out_6366801022728937550[0] = state[1];
}
void H_29(double *state, double *unused, double *out_1940758249465591615) {
   out_1940758249465591615[0] = 0;
   out_1940758249465591615[1] = 1;
   out_1940758249465591615[2] = 0;
   out_1940758249465591615[3] = 0;
   out_1940758249465591615[4] = 0;
   out_1940758249465591615[5] = 0;
   out_1940758249465591615[6] = 0;
   out_1940758249465591615[7] = 0;
   out_1940758249465591615[8] = 0;
}
void h_28(double *state, double *unused, double *out_7428318269563976729) {
   out_7428318269563976729[0] = state[0];
}
void H_28(double *state, double *unused, double *out_3141640767603938959) {
   out_3141640767603938959[0] = 1;
   out_3141640767603938959[1] = 0;
   out_3141640767603938959[2] = 0;
   out_3141640767603938959[3] = 0;
   out_3141640767603938959[4] = 0;
   out_3141640767603938959[5] = 0;
   out_3141640767603938959[6] = 0;
   out_3141640767603938959[7] = 0;
   out_3141640767603938959[8] = 0;
}
void h_31(double *state, double *unused, double *out_8860149699662225608) {
   out_8860149699662225608[0] = state[8];
}
void H_31(double *state, double *unused, double *out_5988869197155768057) {
   out_5988869197155768057[0] = 0;
   out_5988869197155768057[1] = 0;
   out_5988869197155768057[2] = 0;
   out_5988869197155768057[3] = 0;
   out_5988869197155768057[4] = 0;
   out_5988869197155768057[5] = 0;
   out_5988869197155768057[6] = 0;
   out_5988869197155768057[7] = 0;
   out_5988869197155768057[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_977553736874856114) {
  err_fun(nom_x, delta_x, out_977553736874856114);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_778623081939477042) {
  inv_err_fun(nom_x, true_x, out_778623081939477042);
}
void car_H_mod_fun(double *state, double *out_2435242585289315952) {
  H_mod_fun(state, out_2435242585289315952);
}
void car_f_fun(double *state, double dt, double *out_7003703653612928503) {
  f_fun(state,  dt, out_7003703653612928503);
}
void car_F_fun(double *state, double dt, double *out_8514390697440110489) {
  F_fun(state,  dt, out_8514390697440110489);
}
void car_h_25(double *state, double *unused, double *out_2496555721360409747) {
  h_25(state, unused, out_2496555721360409747);
}
void car_H_25(double *state, double *unused, double *out_1087806053356049196) {
  H_25(state, unused, out_1087806053356049196);
}
void car_h_24(double *state, double *unused, double *out_7811460842896347719) {
  h_24(state, unused, out_7811460842896347719);
}
void car_H_24(double *state, double *unused, double *out_2470119545446273940) {
  H_24(state, unused, out_2470119545446273940);
}
void car_h_30(double *state, double *unused, double *out_7310310875630599985) {
  h_30(state, unused, out_7310310875630599985);
}
void car_H_30(double *state, double *unused, double *out_5828884288135567559) {
  H_30(state, unused, out_5828884288135567559);
}
void car_h_26(double *state, double *unused, double *out_2308637607969754340) {
  h_26(state, unused, out_2308637607969754340);
}
void car_H_26(double *state, double *unused, double *out_2216719916404751405) {
  H_26(state, unused, out_2216719916404751405);
}
void car_h_27(double *state, double *unused, double *out_2426645001903131084) {
  h_27(state, unused, out_2426645001903131084);
}
void car_H_27(double *state, double *unused, double *out_3654120976335142648) {
  H_27(state, unused, out_3654120976335142648);
}
void car_h_29(double *state, double *unused, double *out_6366801022728937550) {
  h_29(state, unused, out_6366801022728937550);
}
void car_H_29(double *state, double *unused, double *out_1940758249465591615) {
  H_29(state, unused, out_1940758249465591615);
}
void car_h_28(double *state, double *unused, double *out_7428318269563976729) {
  h_28(state, unused, out_7428318269563976729);
}
void car_H_28(double *state, double *unused, double *out_3141640767603938959) {
  H_28(state, unused, out_3141640767603938959);
}
void car_h_31(double *state, double *unused, double *out_8860149699662225608) {
  h_31(state, unused, out_8860149699662225608);
}
void car_H_31(double *state, double *unused, double *out_5988869197155768057) {
  H_31(state, unused, out_5988869197155768057);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
