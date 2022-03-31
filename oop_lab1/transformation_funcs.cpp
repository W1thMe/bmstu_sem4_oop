#include "transformation_funcs.h"
#include "transform_arithmetic_oprs.h"

err_t scale_model(model_t *model, points_t *scale_coefs)
{
	err_t rc = OK;

    if (!model || !scale_coefs)
		rc = ERROR_SCALE;

    if (!rc)
        rc = scale_coords(model->peaks, &model->center_point, model->peaks_num, scale_coefs);

    return rc;
}

err_t scale_coords(points_t *peaks, points_t *center_point, int n, points_t *scale_coefs)
{
    err_t rc = OK;

    if (!peaks || !center_point)
        rc = ERROR_SCALE;

    for (int i = 0; !rc && i < n; i++)
        rc = mult_coefs(peaks + i, scale_coefs);

    if (!rc)
        rc = mult_coefs(center_point, scale_coefs);

    return rc;
}

err_t move_model(model_t *model, points_t *move_coefs)
{
    err_t rc = OK;

    if (!model || !move_coefs)
        rc = ERROR_MOVE;

    if (!rc)
        rc = move_coords(model->peaks, &model->center_point, model->peaks_num, move_coefs);

    return rc;
}

err_t move_coords(points_t *peaks, points_t *center_point, int n, points_t *move_coefs)
{
    err_t rc = OK;

    if (!peaks || !center_point)
        rc = ERROR_MOVE;

    for (int i = 0; !rc && i < n; i++)
       rc = add_coefs(peaks + i, move_coefs);

    if (!rc)
        rc = add_coefs(center_point, move_coefs);

    return rc;
}

void rotate_peaks(points_t *peaks, points_t *center, int n, points_t *angles)
{
    for (int i = 0; i < n; i++)
        rotate_coords(peaks + i, angles, center);
}

err_t rotate_model(model_t *model, points_t *angles)
{
    err_t rc = OK;

    if (!model || !angles)
        rc = ERROR_ROTATE;

    if (!rc)
        rotate_peaks(model->peaks, &model->center_point, model->peaks_num, angles);

    return rc;
}

err_t rotate_coords(points_t *peak, points_t *angles, points_t *center_dot)
{
    err_t rc = OK;

    if (!peak || !angles || !center_dot)
        rc = ERROR_ROTATE;
    else
    {
        transform_center_dot(peak, center_dot, from_abs_to_rel);
        rotation(peak->x, peak->z, angles->y);
        rotation(peak->y, peak->z, angles->x);
        rotation(peak->x, peak->y, angles->z);
        transform_center_dot(peak, center_dot, from_rel_to_abs);
    }

    return rc;
}

