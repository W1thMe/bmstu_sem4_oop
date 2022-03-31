#include "model_events.h"
#include "events_struct.h"

err_t prepare_to_quit()
{
	err_t rc = OK;
	event_t event;

	rc = fixing_quit_event(event);
	rc = action_manager(event);

	return rc;
}

err_t fixing_open_file_event(event_t &event, char *new_filename)
{
    err_t rc = OK;
	event.action = FILE_OPEN;

    if (!new_filename)
        rc = ERROR_FILE_OPEN;
    else
        event.filename = new_filename;

    return rc;
}

err_t fixing_quit_event(event_t &event)
{
	err_t rc = OK;
	event.action = QUIT;

	return rc;
}

err_t fixing_scale_event(event_t &event, points_t &point)
{
	err_t rc = OK;

	event.action = SCALE;
	event.coord_param = point;

	return rc;
}

err_t fixing_move_event(event_t &event, points_t &point)
{
	err_t rc = OK;

	event.action = MOVE;
	event.coord_param = point;

	return rc;
}

err_t fixing_save_to_file_event(event_t &event, char *new_filename)
{
	err_t rc = OK;
	event.action = FILE_SAVE;

	if (strcmp(event.filename, new_filename))
		event.filename = new_filename;
	else
		rc = ERROR_FILE_OPEN;

	return rc;
}

err_t fixing_draw_event(event_t &event, graphic_scene_t &scene)
{
	err_t rc = OK;

	event.action = DRAW;
	event.scene = scene;

	return rc;
}

err_t fixing_rotation_event(event_t &event,  points_t &point)
{
	err_t rc = OK;

	event.action = ROTATE;
	event.coord_param = point;

	return rc;
}
