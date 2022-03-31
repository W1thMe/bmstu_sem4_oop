#include "draw_functions.h"

err_t draw_model(model_t *model, graphic_scene_t &scene)
{
	err_t rc = OK;

	scene.canvas->clear();

    if (!model)
        rc = ERROR_DRAW;

    if (!rc)
        rc = draw_model_edges(model, scene);

    return rc;
}

err_t draw_model_edges(model_t *model, graphic_scene_t &scene)
{
	err_t rc = OK;
    points_t peak1, peak2;

    if (!model)
        rc = ERROR_DRAW;
    else
        init_peaks(&peak1, &peak2);

    for (int i = 0; !rc && i < model->edges_num; i++)
	{
        rc = get_edge(peak1, peak2, model->peaks, model->edges + i, model->peaks_num);

		if (!rc)
		{
            calc_perspective_for_peak(peak1, scene);
            calc_perspective_for_peak(peak2, scene);
			draw_one_edge(scene.canvas, peak1, peak2);
		}
	}

	return rc;
}

err_t get_edge(points_t &peak1, points_t &peak2, points_t *all_peaks, edges_t *edge_i, int n)
{
    err_t rc = OK;

    if (!all_peaks || !edge_i)
        rc = ERROR_DRAW;

    if (!rc)
    {
        rc = find_peak(peak1, all_peaks, edge_i->peak1, n);

        if (!rc)
            rc = find_peak(peak2, all_peaks, edge_i->peak2, n);
    }

    return rc;
}

err_t find_peak(points_t &peak1, points_t *peaks, int cmp_peak, int n)
{
    err_t rc = OK;
	bool flag = false;

    if (!peaks)
        rc = ERROR_DATA;

    for (int i = 0; !rc && i < n; i++)
	{
        if (peaks[i].peak_num == cmp_peak)
		{
            peak1 = peaks[i];
			flag = true;
		}
	}

    if (!rc && !flag)
        rc = ERROR_PEAK_NAME;

    return rc;
}

void draw_one_edge(canvas_t *canvas, points_t &peak1, points_t &peak2)
{
	QPen ribpen(Qt::black);
	ribpen.setWidth(1);

	canvas->addLine(peak1.x, peak1.y, peak2.x, peak2.y, ribpen);
}
