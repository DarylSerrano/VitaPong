#ifndef	__BALL_H__
#define	__BALL_H__

#include "utils.h"

typedef struct Ball
{
	int x;
	int y;
	int speed_x;
	int speed_y;
	int is_moving;
} Ball;

void ball_move(Ball * ball);

/*	Checks if the ball collisions to the wall and if the ball is near the paddle	*/
/*	Retruns a Position enum if the ball is on the range of the paddle	*/
Position ball_collision(Ball * ball);

void draw_ball(Ball * ball);

#endif