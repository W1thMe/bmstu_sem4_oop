#ifndef RC_H
#define RC_H

typedef enum
{
    OK,
    EXIT_ERROR          = 1,
    ERROR_FILE_OPEN     = -1,
    ERROR_FILE_EMPTY    = -2,
    ERROR_FILE_DATA     = -3,
    ERROR_ALLOCATE      = -4,
    EMPTY_FILE_PATH     = -5,
    ERROR_FILE_FEW_DATA = -6,
    ERROR_MOVE_X_EMPTY  = -7,
    ERROR_MOVE_Y_EMPTY  = -8,
    ERROR_MOVE_Z_EMPTY  = -9,
    ERROR_ROT_X_EMPTY   = -10,
    ERROR_ROT_Y_EMPTY   = -11,
    ERROR_ROT_Z_EMPTY   = -12,
    ERROR_SCALE_X_EMPTY = -13,
    ERROR_SCALE_Y_EMPTY = -14,
    ERROR_SCALE_Z_EMPTY = -15,
    MODEL_EMPTY         = -16,
    ERROR_PEAK_NAME     = -17,
	ERROR_DATA_WRITE    = -18,
	ERROR_SCALE			= -19,
	ERROR_ROTATE		= -20,
    ERROR_MOVE			= -21,
    ERROR_DRAW          = -22,
    ERROR_SAVE          = -23,
    ERROR_COPY          = -24,
    ERROR_DATA          = -25,
    ERROR_LOAD          = -26,
    ERROR_RESET         = -27,
    ERROR_NO_ACTION     = -28
} err_t;

#endif // RC_H
