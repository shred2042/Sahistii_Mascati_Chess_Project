#pragma once

#define INF 500000

#define PION_PRIORITATE 1
#define TURA_PRIORITATE 40
#define CAL_PRIORITATE 5
#define NEBUN_PRIORITATE 5
#define REGE_PRIORITATE 100
#define REGINA_PRIORITATE 80

struct Position
{
	int x, y;
};

struct Move
{
	int coef, x1, y1, x2, y2;
};



#define WHITE -1
#define BLACK 1

//char litere[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };