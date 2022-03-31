#ifndef SAVE_FILE_H
#define SAVE_FILE_H

#include "defines.h"
#include "rc.h"
#include "model_structs.h"

err_t save_center_dot_to_file(FILE *f, points_t *center_dot);
err_t save_params_to_file(FILE *f, int n_peaks, int n_edges);
err_t save_peaks_to_file(FILE *f, points_t *peaks, int n);
err_t save_edges_to_file(FILE *f, edges_t *edges, int n);
err_t save_model(model_t *model, FILE *f);
err_t modelcpy(model_t *model1, model_t *model2);

#endif // SAVE_FILE_H
