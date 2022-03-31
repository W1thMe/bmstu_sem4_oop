#include "read_file.h"

err_t read_model(model_t *new_model, FILE *f)
{
    err_t rc = OK;

    if (!new_model || !f)
        rc = ERROR_LOAD;
    else
        rc = read_center_dot(new_model->center_point, f);

    if (!rc)
        rc = read_peaks_edge_nums(new_model->peaks_num, new_model->edges_num, f);

    if (!rc)
    {
        rc = create_model(*new_model);

        if (!rc)
            rc = read_peaks(new_model->peaks, new_model->peaks_num, f);

        if (!rc)
            rc = read_edges(new_model->edges, new_model->edges_num, f);

        if (rc && rc != ERROR_ALLOCATE)
            reset_model(new_model);
    }

    return rc;
}

err_t read_center_dot(points_t &center_dot, FILE *f)
{
	err_t rc = OK;
	float center_x = 0, center_y = 0, center_z = 0;

    if (!f)
        rc = ERROR_FILE_OPEN;
    else
    {
        int check_input = fscanf(f, "%f%f%f\n", &center_x, &center_y, &center_z);

        if (check_input != CORRECT_CENTER_DOT)
        {
            rc = ERROR_FILE_DATA;
        }

        if (!rc)
        {
            center_dot.x = center_x;
            center_dot.y = center_y;
            center_dot.z = center_z;
        }
    }

	return rc;
}

err_t read_peaks_edge_nums(int &peaks_num, int &edges_num, FILE *f)
{
	err_t rc = OK;

    if (!f)
        rc = ERROR_FILE_OPEN;
    else
    {
        int check_input = fscanf(f, "%d%d", &peaks_num, &edges_num);

        if (check_input != CORRECT_INPUT || peaks_num <= 0 || edges_num <= 0)
            rc = ERROR_FILE_DATA;
    }

	return rc;
}

err_t read_peaks(points_t *peaks, int n, FILE *f)
{
	err_t rc = OK;

    if (!peaks || !f)
        rc = ERROR_FILE_DATA;

    for (int i = 0; !rc && i < n; i++)
        rc = read_one_peak(peaks[i], f);

    return rc;
}

err_t read_one_peak(points_t &peak, FILE *f)
{
	err_t rc = OK;
	int vertex = 0;
	float x = 0, y = 0, z = 0;

    if (!f)
        rc = ERROR_FILE_OPEN;
    else
    {
        int check_input = fscanf(f, "%d%f%f%f\n", &vertex, &x, &y, &z);

        if (check_input != CORRECT_PTS_NUM)
        {
            rc = ERROR_FILE_DATA;
        }

        if (!rc)
        {
            peak.x = x;
            peak.y = y;
            peak.z = z;
            peak.peak_num = vertex;
        }
    }

	return rc;
}

err_t read_edges(edges_t *edges, int n, FILE *f)
{
	err_t rc = OK;

    if (!edges || !f)
        rc = ERROR_FILE_DATA;

    for (int i = 0; !rc && i < n; i++)
        rc = read_one_edge(edges[i], f);

    return rc;
}

err_t read_one_edge(edges_t &edge, FILE *f)
{
	err_t rc = OK;
	int peak1 = 0, peak2 = 0;

    if (!f)
        rc = ERROR_FILE_OPEN;
    else
    {
        int check_input = fscanf(f, "%d%d\n", &peak1, &peak2);

        if (check_input != CORRECT_INPUT)
        {
            rc = ERROR_FILE_DATA;
        }

        if (!rc)
        {
            edge.peak1 = peak1;
            edge.peak2 = peak2;
        }
    }

	return rc;
}
