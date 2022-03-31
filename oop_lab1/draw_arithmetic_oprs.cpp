#include "draw_arithmetic_oprs.h"

void calc_perspective_for_peak(points_t &peak, graphic_scene_t &scene)
{
    peak.x = calc_x_coord_perspective(peak.x, peak.z, scene.width, scene.distance);
    peak.y = calc_y_coord_perspective(peak.y, peak.z, scene.height, scene.distance);
}

float calc_x_coord_perspective(float x, float z, int width, int distance)
{
    float x_coord = (width / 2) + ((x * distance) / (z + distance));

    return x_coord;
}

float calc_y_coord_perspective(float y, float z, int height, int distance)
{
    float y_coord = (height / 2) + ((y * distance) / (z + distance) * -1);

    return y_coord;
}
