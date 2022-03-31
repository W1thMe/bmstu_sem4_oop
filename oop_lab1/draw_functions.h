#ifndef DRAW_FUNCTIONS_H
#define DRAW_FUNCTIONS_H

#include "defines.h"
#include "rc.h"
#include "model_structs.h"
#include "draw_arithmetic_oprs.h"
#include "mainwindow.h"
#include "defines.h"
#include "transform_arithmetic_oprs.h"

err_t draw_model(model_t *model, graphic_scene_t &scene);
err_t find_peak(points_t &peak1, points_t *peaks, int cmp_peak, int n);
err_t draw_model_edges(model_t *model, graphic_scene_t &scene);
void draw_one_edge(canvas_t *canvas, points_t &peak1, points_t &peak2);
err_t get_edge(points_t &peak1, points_t &peak2, points_t *all_peaks,edges_t *edge_i, int n);

#endif // DRAW_FUNCTIONS_H
