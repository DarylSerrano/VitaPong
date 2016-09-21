#ifndef	PADDLE_H
#define	PADDLE_H

#include "utils.h"
#include "ball.h"

typedef struct Paddle
{
	int height;
	int width;
	int x;
	int y;
	Position pos;
	int score;
} Paddle;

/*	If ball != NULL the ball moves with the paddle	*/
void paddle_move_left(Paddle * paddle, Ball * ball);
void paddle_move_right(Paddle * paddle, Ball * ball);

/*	Checks collision betwen Ball and the Paddle */
int paddle_collision(Paddle * paddle, Ball * ball);

/*	Shots the ball ont the corresponding direction if the game hasn't started yet	*/
void paddle_shoot_ball(Paddle * paddle, Ball * ball);

/*	Positions the ball on the position of the corresponding paddle player	*/
void ball_reposition(Ball * ball, Player player);

void draw_paddle(Paddle * paddle);

#endif