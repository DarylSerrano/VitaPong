#ifndef	GAME_H
#define	GAME_H

#include <ctrl.h>

#include "utils.h"
#include "paddle.h"
#include "ball.h"

typedef enum State
{
	MAIN_MENU,
	IN_GAME
} State;

typedef struct Game
{
	State gameState;
	int playing;
	int started;
} Game;

void draw_ingame(Paddle * pj1, Paddle * pj2, Ball * ball);
void draw_main_menu();

int collision_check(Paddle * pj1, Paddle * pj2, Ball * ball);

void input_paddles(Paddle * pj1, Paddle * pj2, SceCtrlData * pad);
void input_process(Game * game);

#endif