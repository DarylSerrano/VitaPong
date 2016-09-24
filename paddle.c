#include <stdio.h>
#include <vita2d.h>

#include "paddle.h"

/*	If ball != NULL the ball moves with the paddle	*/
void paddle_move_left(Paddle * paddle, Ball * ball)
{
	if(paddle->x > 0)
	{
		paddle->x -= PADDLE_SPEED;
	}
	
	if(ball != NULL)
	{
		ball->x = paddle->x + (PADDLE_W / 2);
	}
}

void paddle_move_right(Paddle * paddle, Ball * ball)
{
	if(paddle->x + PADDLE_W < SCREEN_W)
	{
		paddle->x += PADDLE_SPEED;
	}
	
	if(ball != NULL)
	{
		ball->x = paddle->x + (PADDLE_W / 2);
	}
}

/*	Checks collision betwen Ball and the Paddle  and returns true if the ball has passed the paddle	*/
int paddle_collision(Paddle * paddle, Ball * ball)
{
	int passed = 0;
	
	if(paddle->pos == UP)
	{
		if(ball->y - BALL_RADIUS > 0 && ball->y - BALL_RADIUS <= PADDLE_H)
		{
			if(ball->x > paddle->x && ball->x < paddle->x + (PADDLE_W/3))
			{
				ball->speed_x = -ball->speed_y;
				ball->speed_y = -ball->speed_y;
			}
			else if(ball->x >= paddle->x + 2*(PADDLE_W/3) && ball->x <= paddle->x + 3*(PADDLE_W/3))
			{
				ball->speed_x = ball->speed_y;
				ball->speed_y = -ball->speed_y;
			}
			else if(ball->x >= paddle->x + (PADDLE_W/3) && ball->x < paddle->x + 2*(PADDLE_W/3))
			{
				ball->speed_y = -ball->speed_y;
			}
			else if(ball->x + BALL_RADIUS == paddle->x) // left side
			{
				ball->speed_x = ball->speed_y;
				ball->speed_y = -ball->speed_y;
			}
			else if(ball->x - BALL_RADIUS == paddle->x + PADDLE_W)// right side
			{
				ball->speed_x = -ball->speed_y;
				ball->speed_y = -ball->speed_y;	
			}
		}
		else if(ball->y + BALL_RADIUS <= 0)
		{
			passed = 1;
			ball->is_moving = 0;
		}
	}
	else if(paddle->pos == DOWN)
	{
		if(ball->y + BALL_RADIUS < SCREEN_H && ball->y + BALL_RADIUS >= SCREEN_H - PADDLE_H)
		{
			if(ball->x > paddle->x && ball->x < paddle->x + (PADDLE_W/3))
			{
				ball->speed_x = ball->speed_y;
				ball->speed_y = -ball->speed_y;
			}
			else if(ball->x >= paddle->x + 2*(PADDLE_W/3) && ball->x <= paddle->x + 3*(PADDLE_W/3))
			{
				ball->speed_x = -ball->speed_y;
				ball->speed_y = -ball->speed_y;
			}
			else if(ball->x >= paddle->x + (PADDLE_W/3) && ball->x < paddle->x + 2*(PADDLE_W/3))
			{
				ball->speed_y = -ball->speed_y;
			}
			else if(ball->x + BALL_RADIUS  == paddle->x) // left side
			{
				ball->speed_x = -ball->speed_y;
				ball->speed_y = -ball->speed_y;
			}
			else if(ball->x - BALL_RADIUS == paddle->x + PADDLE_W)// right side
			{
				ball->speed_x = ball->speed_y;
				ball->speed_y = -ball->speed_y;	
			}
		}
		else if(ball->y - BALL_RADIUS >= SCREEN_H)
		{
			passed = 1;
			ball->is_moving = 0;
		}
	}
	
	return passed;
}

/*	Shots the ball ont the corresponding direction if the game hasn't started yet	*/
void paddle_shoot_ball(Paddle * paddle, Ball * ball)
{
	ball->is_moving = 1;
	paddle->has_ball = 0;
	
	ball->speed_x = BALL_SPEED;
	
	if(paddle->pos == UP)
	{
		ball->speed_y = BALL_SPEED;
	}
	else if(paddle->pos == DOWN)
	{
		ball->speed_y = -BALL_SPEED;
	}
}

/*	Positions the ball on the position of the corresponding paddle player	*/
void ball_reposition(Ball * ball, Paddle * paddle)
{
	ball->x = paddle->x + (PADDLE_W / 2);
	
	if(paddle->pos == UP)
	{
		ball->y = paddle->y +  PADDLE_H + BALL_RADIUS;
	}
	else if(paddle->pos == DOWN)
	{
		ball->y = paddle->y - BALL_RADIUS;
	}
}

void draw_paddle(Paddle * paddle)
{
	vita2d_draw_rectangle(paddle->x, paddle->y, PADDLE_W, PADDLE_H, WHITE);
}

