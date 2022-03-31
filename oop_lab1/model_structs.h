#ifndef MODEL_STRUCTS_H
#define MODEL_STRUCTS_H

typedef struct
{
	float x;
	float y;
	float z;
	int peak_num;
} points_t;

typedef struct
{
	int peak1;
	int peak2;
} edges_t;

typedef struct
{
	points_t center_point;
	points_t *peaks;
	edges_t *edges;
	int peaks_num;
	int edges_num;
} model_t;

#endif // MODEL_STRUCTS_H
