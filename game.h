#ifndef	__GAME_H__
#define	__GAME_H__

#include "utils.h"
#include "ball.h"
#include "paddle.h"

#include <psp2/ctrl.h>
#include <vita2d.h>

typedef enum State
{
	MAIN_MENU,
	IN_GAME
} State;

typedef struct Game
{
	State game_state;
	Paddle * pj1;
	Paddle * pj2;
	Ball * ball;
} Game;

void draw_ingame(Paddle * pj1, Paddle * pj2, Ball * ball, vita2d_pgf * pgf);
void draw_main_menu(vita2d_pgf * pgf);

int collision_check(Paddle * pj1, Paddle * pj2, Ball * ball);

void prepare_in_game(Paddle * pj1, Paddle * pj2, Ball * ball);

void input_paddles(Paddle * pj1, Paddle * pj2, Ball * ball, SceCtrlData * pad);
void input_process(Game * game, SceCtrlData * pad);

#endif