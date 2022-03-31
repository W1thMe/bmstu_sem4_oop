#ifndef TRANSFORMATION_FUNCS_H
#define TRANSFORMATION_FUNCS_H

#include "model_structs.h"
#include "model_events.h"
#include "defines.h"
#include "rc.h"

err_t scale_model(model_t *model, points_t *scale_coefs);
err_t move_model(model_t *model, points_t *move_coefs);

err_t rotate_model(model_t *model, points_t *angles);
err_t rotate_coords(points_t *peak, points_t *angles, points_t *center_dot);
void rotate_peaks(points_t *peaks, points_t *center, int n, points_t *angles);
void peak_coords_from_absolute_to_relative(points_t *peak, points_t *center_dot);

err_t scale_coords(points_t *peaks, points_t *center_point, int n, points_t *scale_coefs);
err_t move_coords(points_t *peaks, points_t *center_point, int n, points_t *move_coefs);

#endif // TRANSFORMATION_FUNCS_H
