#include "mem.h"

err_t create_model(model_t &model)
{
	err_t rc = OK;

	model.peaks = (points_t*)malloc(model.peaks_num * sizeof(points_t));

	if (!model.peaks)
		rc = ERROR_ALLOCATE;

	if (!rc)
		model.edges = (edges_t*)malloc(model.edges_num * sizeof(edges_t));

	if (!rc && !model.edges)
	{
		rc = ERROR_ALLOCATE;
		free(model.peaks);
	}

	return rc;
}

err_t reset_model(model_t *model)
{
    err_t rc = OK;

    if (!model)
        rc = ERROR_RESET;
    else
    {
        free(model->edges);
        free(model->peaks);
        model->peaks = NULL;
        model->edges = NULL;
    }

    return rc;
}
