#ifndef EVENTS_STRUCT_H
#define EVENTS_STRUCT_H

#include "model_structs.h"
#include "defines.h"

typedef struct
{
	graphic_scene_t scene;
	points_t coord_param;
	char *filename;
	int action;
} event_t;

#endif // EVENTS_STRUCT_H
