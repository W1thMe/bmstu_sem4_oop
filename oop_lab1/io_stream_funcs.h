#ifndef IO_STREAM_FUNCS_H
#define IO_STREAM_FUNCS_H

#include "rc.h"
#include "defines.h"
#include "read_file.h"
#include "save_file.h"
#include "mem.h"
#include "model_structs.h"

err_t save_model_to_file(model_t *model, char *filename);
err_t load_model_from_file(model_t *model, char *filename);

#endif // IO_STREAM_FUNCS_H
