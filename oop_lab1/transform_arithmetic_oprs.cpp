#include "transform_arithmetic_oprs.h"

void rotation(float &coord1, float &coord2, float angle)
{
    float tmp1 = coord1, tmp2 = coord2;
    angle *= ANGLE;

    coord1 = tmp1 * cos(angle) - tmp2 * sin(angle);
    coord2 = tmp1 * sin(angle) + tmp2 * cos(angle);
}

err_t add_coefs(points_t *peaks, points_t *coefs)
{
    err_t rc = OK;

    if (!peaks || !coefs)
        rc = ERROR_MOVE;

    if (!rc)
    {
        peaks->x += coefs->x;
        peaks->y += coefs->y;
        peaks->z += coefs->z;

    }

    return rc;
}

err_t mult_coefs(points_t *peaks, points_t *coefs)
{
    err_t rc = OK;

    if (!peaks || !coefs)
        rc = ERROR_SCALE;

    if (!rc)
    {
        peaks->x *= coefs->x;
        peaks->y *= coefs->y;
        peaks->z *= coefs->z;
    }

    return rc;
}

void transform_center_dot(points_t *peak, points_t *center_dot, float calc_coord(float p1, float p2))
{
    peak->x = calc_coord(peak->x, center_dot->x);
    peak->y = calc_coord(peak->y, center_dot->y);
    peak->z = calc_coord(peak->z, center_dot->x);
}

float from_abs_to_rel(float point, float center)
{
    float res = point - center;

    return res;
}

float from_rel_to_abs(float point, float center)
{
    float res = point + center;

    return res;
}
