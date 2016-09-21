#include <psp2/ctrl.h>
#include <vita2d.h>

#include "game.h"

void draw_ingame(Paddle * pj1, Paddle * pj2, Ball * ball, vita2d_pgf * pgf)
{
	// Draw Scores
	vita2d_pgf_draw_textf(pgf, SCORE_POSITION_PJ1, 0, WHITE, 1.0f, "%d", pj1->score);
	vita2d_pgf_draw_textf(pgf, SCORE_POSITION_PJ2, 0, WHITE, 1.0f, "%d", pj1->score);
	
	// Draw Ball
	draw_ball(ball);
	
	//Draw Paddles
	draw_paddle(pj1);
	draw_paddle(pj2);
	
}

void draw_main_menu(vita2d_pgf * pgf)
{
	vita2d_pgf_draw_text(pgf, MIDDLE_SCREEN, SCREEN_H/2, WHITE, 1.0f, "Press start to play");
	vita2d_pgf_draw_text(pgf, MIDDLE_SCREEN, SCREEN_H/2 + 30, WHITE, 3.0f, "VITA PONG");
}

int collision_check(Paddle * pj1, Paddle * pj2, Ball * ball)
{
	Position pos = ball_collision(ball);
	int passed = 0;
	
	switch(pos)
	{
		case Position.UP:
			passed = paddle_collision(pj2);
			break;
		case Position.DOWN:
			passed = paddle_collision(pj1);
			break;
		default:
			break;
	}
	
}

void input_paddles(Paddle * pj1, Paddle * pj2, SceCtrlData * pad)
{	
	// pj1 inputs
	if(pad->buttons & SCE_CTRL_CIRCLE)
	{
		paddle_move_right(pj1);
	}
	else if(pad->buttons & SCE_CTRL_SQUARE)
	{
		paddle_mave_left(pj1);
	}
	
	// pj2 inputs
	if(pad->buttons & SCE_CTRL_RIGHT)
	{
		paddle_move_right(pj2);
	}
	else if(pad->buttons & SCE_CTRL_LEFT)
	{
		paddle_move_left(pj2);
	}
	
	
}

void input_process(Game * game, SceCtrlData * pad)
{
	sceCtrlPeekBufferPositive(0, pad, 1);
	
	if(game->gameState == State.IN_GAME)
	{
		
	}
}


