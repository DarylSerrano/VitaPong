#ifndef	UTILS_H
#define UTILS_H

#define	SCREEN_W	966
#define SCREEN_H	544	
#define MIDDLE_SCREEN	(SCREEN_W/2)

/*	Dimension and speed of a paddle	*/
#define PADDLE_W		150
#define	PADDLE_H		30
#define PADDLE_SPEED	7

/*	Default position of the top paddle	*/
#define	PLAYER_TOP_POS_X	(MIDDLE_SCREEN)
#define PLAYER_TOP_POS_Y	0

/*	Default position of the bottom paddle	*/
#define PLAYER_BOTTOM_POS_X		(MIDDLE_SCREEN)
#define	PLAYER_BOTTOM_POS_Y		(SCREEN_H-PADDLE_H)

/*	Dimension and speed of a ball	*/
#define	BALL_RADIUS		20
#define	BALL_SPEED		5

/*	Scores position	*/
#define	SCORE_POSITION_PJ1	(SCREEN_W-10)
#define	SCORE_POSITION_PJ2	0

/*	Color utils	*/
#define	TRANS   RGBA8(  0,   0,   0, 0)
#define	BLACK   RGBA8(  0,   0,   0, 255)
#define	WHITE   RGBA8(255, 255, 255, 255)
#define	GREEN   RGBA8(  0, 255,   0, 255)
#define	RED     RGBA8(255,   0,   0, 255)
#define	BLUE    RGBA8(  0,   0, 255, 255)
#define	GRAY    RGBA8( 70,  70,  70, 255)
#define	CYAN    RGBA8(  0, 255, 255, 255)
#define	ORANGE  RGBA8(255, 165,	  0, 255)
#define	YELLOW	RGBA8(255, 255, 0, 255)

/*	Definition of NULL	*/
#define	NULL	( (void *) 0)

typedef enum Position
{
	UP, DOWN, MIDDLE
} Position;

#endif