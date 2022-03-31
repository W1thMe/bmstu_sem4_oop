#include "manager.h"

err_t action_manager(event_t event)
{
	err_t rc = OK;
	static model_t model = model_init();

	switch(event.action)
	{
		case FILE_OPEN:
           rc = load_model_from_file(&model, event.filename);
		   break;
		case FILE_SAVE:
            rc = save_model_to_file(&model, event.filename);
			break;
        case ROTATE:
            rc = rotate_model(&model, &event.coord_param);
			break;
		case SCALE:
            rc = scale_model(&model, &event.coord_param);
            break;
		case MOVE:
            rc = move_model(&model, &event.coord_param);
			break;
		case DRAW:
            rc = draw_model(&model, event.scene);
			break;
		case QUIT:
            rc = reset_model(&model);
			break;
        default:
            rc = ERROR_NO_ACTION;
	}

   return rc;
}
