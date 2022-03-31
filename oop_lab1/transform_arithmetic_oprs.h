#ifndef TRANSFORM_ARITHMETIC_OPRS_H
#define TRANSFORM_ARITHMETIC_OPRS_H

#include <cmath>
#include "defines.h"
#include "rc.h"
#include "model_structs.h"

#define DISTANCE 1000
#define ANGLE M_PI / 180

// TRANSFORMATION
//void rotation(float &c_1, float &c_2, float center1, float center2, float angle);
void rotation(float &coord1, float &coord2, float angle);
err_t add_coefs(points_t *peaks, points_t *coefs);
err_t mult_coefs(points_t *peaks, points_t *coefs);
// TRANSFORMATION

void transform_center_dot(points_t *peak, points_t *center_dot, float calc_coord(float p1, float p2));
float from_abs_to_rel(float point, float center);
float from_rel_to_abs(float point, float center);

#endif // TRANSFORM_ARITHMETIC_OPRS_H
