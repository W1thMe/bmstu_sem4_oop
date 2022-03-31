#include "io_stream_funcs.h"

err_t load_model_from_file(model_t *model, char *filename)
{
	err_t rc = OK;
    FILE *f = nullptr;

    if (!model || !filename)
        rc = ERROR_LOAD;
    else
    {
        f = fopen(filename, "r");

        if (!f)
            rc = ERROR_FILE_OPEN;
    }

    if (!rc)
    {
        model_t new_model = model_init();

        rc = read_model(&new_model, f);
        fclose(f);

        if (!rc)
		{
            reset_model(model);
            rc = modelcpy(model, &new_model);
        }

	}

	return rc;
}

err_t save_model_to_file(model_t *model, char *filename)
{
	err_t rc = OK;

    if (!model || !filename)
        rc = ERROR_SAVE;
    else
    {
        FILE *f = fopen(filename, "w");

        if (!f)
        {
            rc = ERROR_FILE_OPEN;
        }
        else
        {
            rc = save_model(model, f);
            fclose(f);
        }
    }

	return rc;
}
