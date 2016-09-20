#ifndef	PADDLE_H
#define	PADDLE_H

typedef enum Paddle_Pos
{
	UP, DOWN
} Paddle_Pos;

typedef struct Paddle
{
	int height;
	int weight;
	int x;
	int y;
	int paddle_speed;
	Paddle_Pos paddle_pos;
	int score;
} Paddle;

/*	If ball != NULL the ball moves with the paddle	*/
void paddle_move_left(Paddle * paddle, Ball * ball);
void paddle_move_right(Paddle * paddle, Ball * ball);

/*	Checks collision betwen Ball and the Paddle */
int paddle_collision(Paddle * paddle, Ball * ball);

/*	Shots the ball ont the corresponding direction if the game hasn't started yet	*/
void shoot_ball(Ball * ball);

#endif