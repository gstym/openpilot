#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_7569354656790451798);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4882156975285941590);
void pose_H_mod_fun(double *state, double *out_5814428664983507972);
void pose_f_fun(double *state, double dt, double *out_5774518282165166048);
void pose_F_fun(double *state, double dt, double *out_8025296144773174735);
void pose_h_4(double *state, double *unused, double *out_8507801575896652222);
void pose_H_4(double *state, double *unused, double *out_4616481183100609868);
void pose_h_10(double *state, double *unused, double *out_4484960606295619259);
void pose_H_10(double *state, double *unused, double *out_3400459211528847226);
void pose_h_13(double *state, double *unused, double *out_3480051689038598104);
void pose_H_13(double *state, double *unused, double *out_1404207357768277067);
void pose_h_14(double *state, double *unused, double *out_8093714864730119229);
void pose_H_14(double *state, double *unused, double *out_7699269615395982164);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}