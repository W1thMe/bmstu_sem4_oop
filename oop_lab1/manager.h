#ifndef MANAGER_H
#define MANAGER_H

#include "rc.h"
#include "defines.h"
#include "model_structs.h"
#include "model_events.h"
#include "draw_functions.h"
#include "io_stream_funcs.h"
#include "events_struct.h"
#include "transformation_funcs.h"

err_t action_manager(event_t event);

#endif // MANAGER_H
