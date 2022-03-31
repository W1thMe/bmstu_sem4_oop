#ifndef MEM_H
#define MEM_H

#include <cstdlib>
#include "defines.h"
#include "rc.h"
#include "model_structs.h"

err_t create_model(model_t &model);
err_t reset_model(model_t *model);

#endif // MEM_H
