#include <vita2d.h>

#include "utils.h"
#include "ball.h"

void ball_move(Ball * ball)
{
	ball->x += ball->speed_x;
	ball->y += ball->speed_y;
}

/*	Checks if the ball collisions to the wall and if the ball is near the paddle	*/
/*	Retruns a Position enum if the ball is on the range of the paddle	*/
Position ball_collision(Ball * ball)
{
	Position pos = MIDDLE;
	
	if(ball->x + BALL_RADIUS >= SCREEN_W)
	{
		ball->speed_x *= -1; 
	}
	else if(ball->x - BALL_RADIUS <= 0)
	{
		ball->speed_x *= 1;
	}
	
	if(ball->y <= PADDLE_H + BALL_RADIUS)
	{
		pos = UP;
	}
	else if(ball->y >= SCREEN_H - (PADDLE_H + BALL_RADIUS))
	{
		pos = DOWN;
	}
	
	return pos;
}

void draw_ball(Ball * ball)
{
	vita2d_draw_fill_circle(ball->x, ball->y, BALL_RADIUS, WHITE);
}