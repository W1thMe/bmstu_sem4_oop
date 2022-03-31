#ifndef READ_FILE_H
#define READ_FILE_H

#include "rc.h"
#include "mem.h"
#include "defines.h"
#include "model_structs.h"
#include "initialize_funcs.h"

#define CORRECT_INPUT 2
#define CORRECT_PTS_NUM 4
#define CORRECT_CENTER_DOT 3

err_t read_peaks_edge_nums(int &peaks_num, int &edges_num, FILE *f);
err_t read_center_dot(points_t &center_dot, FILE *f);
err_t read_peaks(points_t *peaks, int n, FILE *f);
err_t read_edges(edges_t *edges, int n, FILE *f);
err_t read_one_peak(points_t &peak, FILE *f);
err_t read_one_edge(edges_t &edge, FILE *f);
err_t read_model(model_t *new_model, FILE *f);

#endif // READ_FILE_H
