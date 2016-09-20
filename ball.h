#ifndef	BALL_H
#define	BALL_H

typedef enum Player
{
	PJ1,
	PJ2
} Player;

typedef struct Ball
{
	int x;
	int y;
	int speed_x;
	int speed_y;
	int is_moving;
	int diameter;
} Ball;

#ifdef	SQUARE_BALL
typedef struct Square_Ball
{
	int x;
	int y;
	int speed_x;
	int speed_y;
	int is_moving;
	int width;
	int height;
} Square_Ball;
#endif

void move_ball(Ball * ball);

/*	Positions the ball on the position of the corresponding paddle player	*/
void reposition_ball(Player);

/*	Checks if the ball collisions to the wall and if the ball is near the paddle	*/
/*	Retruns true if the ball is on the range of the paddle	*/
int ball_collision(Ball * ball);

#endif