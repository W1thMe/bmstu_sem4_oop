#include "save_file.h"

err_t save_model(model_t *model, FILE *f)
{
	err_t rc = OK;

    if (!model || !f)
        rc = ERROR_SAVE;
    else
    {
        rc = save_center_dot_to_file(f, &model->center_point);

        if (!rc)
            rc = save_params_to_file(f, model->peaks_num, model->edges_num);

        if (!rc)
            rc = save_peaks_to_file(f, model->peaks, model->peaks_num);

        if (!rc)
            rc = save_edges_to_file(f, model->edges, model->edges_num);
    }

	return rc;
}

err_t save_center_dot_to_file(FILE *f, points_t *center_dot)
{
    err_t rc = OK;
    int rec_symbols = 0;

    if (!center_dot || !f)
        rc = ERROR_SAVE;
    else
    {
        rec_symbols = fprintf(f, "%f %f %f\n", center_dot->x, center_dot->y, center_dot->z);

        if (rec_symbols <= 0)
            rc = ERROR_DATA_WRITE;
    }

    return rc;
}

err_t save_params_to_file(FILE *f, int n_peaks, int n_edges)
{
	err_t rc = OK;
	int rec_symbols = 0;

    if (!f)
        rc = ERROR_SAVE;
    else
    {
        rec_symbols = fprintf(f, "%d %d\n", n_peaks, n_edges);

        if (rec_symbols <= 0)
            rc = ERROR_DATA_WRITE;
    }

	return rc;
}

err_t save_peaks_to_file(FILE *f, points_t *peaks, int n)
{
	err_t rc = OK;
	int rec_symbols = 0;

    if (!peaks || !f)
        rc = ERROR_SAVE;

    for (int i = 0; !rc && i < n; i++)
    {
        rec_symbols = fprintf(f, "%f %f %f\n", peaks[i].x, peaks[i].y, peaks[i].z);

        if (rec_symbols <= 0)
            rc = ERROR_DATA_WRITE;
    }

	return rc;
}

err_t save_edges_to_file(FILE *f, edges_t *edges, int n)
{
	err_t rc = OK;
	int rec_symbols = 0;

    if (!edges || !f)
        rc = ERROR_SAVE;

    for (int i = 0; !rc && i < n; i++)
    {
        rec_symbols = fprintf(f, "%d %d\n", edges[i].peak1, edges[i].peak2);

        if (rec_symbols <= 0)
            rc = ERROR_DATA_WRITE;
    }

	return rc;
}

err_t modelcpy(model_t *model1, model_t *model2)
{
    err_t rc = OK;

    if (!model1 || !model2)
        rc = ERROR_COPY;
    else
    {
        model1->edges_num = model2->edges_num;
        model1->peaks_num = model2->peaks_num;
        model1->edges = model2->edges;
        model1->peaks = model2->peaks;
    }

    return rc;
}
