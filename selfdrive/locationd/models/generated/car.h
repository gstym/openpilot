#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_977553736874856114);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_778623081939477042);
void car_H_mod_fun(double *state, double *out_2435242585289315952);
void car_f_fun(double *state, double dt, double *out_7003703653612928503);
void car_F_fun(double *state, double dt, double *out_8514390697440110489);
void car_h_25(double *state, double *unused, double *out_2496555721360409747);
void car_H_25(double *state, double *unused, double *out_1087806053356049196);
void car_h_24(double *state, double *unused, double *out_7811460842896347719);
void car_H_24(double *state, double *unused, double *out_2470119545446273940);
void car_h_30(double *state, double *unused, double *out_7310310875630599985);
void car_H_30(double *state, double *unused, double *out_5828884288135567559);
void car_h_26(double *state, double *unused, double *out_2308637607969754340);
void car_H_26(double *state, double *unused, double *out_2216719916404751405);
void car_h_27(double *state, double *unused, double *out_2426645001903131084);
void car_H_27(double *state, double *unused, double *out_3654120976335142648);
void car_h_29(double *state, double *unused, double *out_6366801022728937550);
void car_H_29(double *state, double *unused, double *out_1940758249465591615);
void car_h_28(double *state, double *unused, double *out_7428318269563976729);
void car_H_28(double *state, double *unused, double *out_3141640767603938959);
void car_h_31(double *state, double *unused, double *out_8860149699662225608);
void car_H_31(double *state, double *unused, double *out_5988869197155768057);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}