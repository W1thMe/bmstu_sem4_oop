#ifndef DEFINES_H
#define DEFINES_H

#define DISTANCE 1000
#define MAX_LEN 100
#define ZERO "0"
#define ONE "1"

#include <QGraphicsScene>

typedef QGraphicsScene canvas_t;

typedef struct
{
	double width;
    double distance;
	double height;
	canvas_t *canvas;
} graphic_scene_t;


#endif // DEFINES_H
