#ifndef DRAW_ARITHMETIC_OPRS_H
#define DRAW_ARITHMETIC_OPRS_H

#include "defines.h"
#include "model_structs.h"

float calc_y_coord_perspective(float y, float z, int width, int distance);
void calc_perspective_for_peak(points_t &peak, graphic_scene_t &scene);
float calc_x_coord_perspective(float x, float z, int height, int distance);

#endif // DRAW_ARITHMETIC_OPRS_H
