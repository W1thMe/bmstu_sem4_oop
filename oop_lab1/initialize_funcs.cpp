#include "initialize_funcs.h"

void init_peaks(points_t *peak1, points_t *peak2)
{
    points_t tmp1 = { .x = 0, .y = 0, .z = 0, .peak_num = 0 };
    points_t tmp2 = { .x = 0, .y = 0, .z = 0, .peak_num = 0 };

    *peak1 = tmp1;
    *peak2 = tmp2;
}

model_t model_init()
{
    model_t model;

    model.center_point = { .x = 0, .y = 0, .z = 0, .peak_num = 0 };
    model.peaks = nullptr;
    model.edges = nullptr;
    model.edges_num = 0;
    model.peaks_num = 0;

    return model;
}
