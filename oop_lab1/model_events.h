#ifndef MODEL_EVENTS_H
#define MODEL_EVENTS_H

#include "rc.h"
#include "defines.h"
#include "transformation_funcs.h"
#include "mem.h"
#include "read_file.h"
#include "save_file.h"
#include "draw_functions.h"
#include "mainwindow.h"
#include "model_structs.h"
#include "manager.h"
#include "events_struct.h"

#define FILE_OPEN 1
#define FILE_SAVE 2
#define QUIT      3
#define DRAW	  4
#define SCALE	  5
#define ROTATE    6
#define MOVE	  7

err_t fixing_save_to_file_event(event_t &event, char *new_filename);
err_t fixing_open_file_event(event_t &event, char *new_filename);
err_t fixing_quit_event(event_t &event);
err_t fixing_draw_event(event_t &event, graphic_scene_t &scene);
err_t fixing_scale_event(event_t &event, points_t &point);
err_t fixing_move_event(event_t &event, points_t &point);
err_t fixing_rotation_event(event_t &event, points_t &point);
err_t prepare_to_quit();
model_t  model_init();

#endif // MODEL_EVENTS_H
