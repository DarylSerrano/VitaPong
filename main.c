#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <psp2/ctrl.h>
#include <psp2/types.h>
#include <psp2/moduleinfo.h>
#include <psp2/kernel/processmgr.h>

#include <vita2d.h>

#include "ball.h"
#include "paddle.h"
#include "game.h"

PSP2_MODULE_INFO(0, 0, "VitaPong");

Game * init_game();
void exit_game(vita2d_pgf * pgf);
void draw(vita2d_pgf * pgf, Game * game);
void update(Game * game, SceCtrlData * pad);

int main()
{
	Game * game;
	vita2d_pgf * pgf;
	SceCtrlData pad;

	// Initialize graphics
	vita2d_init();
	vita2d_set_clear_color(BLACK);

	pgf = vita2d_load_default_pgf();
	sceCtrlSetSamplingMode(SCE_CTRL_MODE_DIGITAL);

	memset(&pad, 0, sizeof(pad));

	game = init_game();

	while(1)
	{
		/*
		vita2d_start_drawing();
		vita2d_clear_screen();
		vita2d_pgf_draw_textf(pgf, MIDDLE_SCREEN, SCREEN_H/2, WHITE, 1.0f, "Test: posicion de pj1 %d", game->pj1->x);
		vita2d_pgf_draw_textf(pgf, MIDDLE_SCREEN, SCREEN_H/2+10, WHITE, 1.0f, "Test: posicion de pj1 %d", game->ball->x);
		vita2d_end_drawing();
		vita2d_swap_buffers();
		*/
		update(game, &pad);
		draw(pgf, game);
	}

	exit_game(pgf);

	return 0;
}

Game * init_game()
{
	Game * game;
	// Initialize game variables
	Paddle * pj1 = malloc(sizeof(Paddle));
	Paddle * pj2 = malloc(sizeof(Paddle));
	Ball * ball = malloc(sizeof(Ball));

	pj1->x = PLAYER_BOTTOM_POS_X;
	pj1->y = PLAYER_BOTTOM_POS_Y;
	pj1->pos = DOWN;
	pj1->score = 0;
	pj1->has_ball = 0;

	pj2->x = PLAYER_TOP_POS_X;
	pj2->y = PLAYER_TOP_POS_Y;
	pj2->pos = UP;
	pj2->score = 0;
	pj2->has_ball = 0;

	ball->x = 0;
	ball->y = 0;
	ball->speed_x = BALL_SPEED;
	ball->speed_y = BALL_SPEED;
	ball->is_moving = 0;

	game = malloc(sizeof(Game));
	game->game_state = MAIN_MENU;
	game->pj1 = pj1;
	game->pj2 = pj2;
	game->ball = ball;

	return game;
}

void exit_game(vita2d_pgf * pgf)
{
	/*
	free(game->pj1);
	free(game->pj2);
	free(game->ball);
	free(game);*/

	vita2d_fini();
   	vita2d_free_pgf(pgf);
    sceKernelExitProcess(0);
}

void update(Game * game, SceCtrlData * pad)
{
	input_process(game, pad);

	if((game->ball)->is_moving)
	{
		ball_move(game->ball);
		if(collision_check(game->pj1, game->pj2, game->ball))
		{
			prepare_in_game(game->pj1, game->pj2, game->ball);
		}
	}
}

void draw(vita2d_pgf * pgf, Game * game)
{
	vita2d_start_drawing();
	vita2d_clear_screen();

	switch(game->game_state)
	{
		case MAIN_MENU:
			draw_main_menu(pgf);
			break;
		case IN_GAME:
			draw_ingame(game->pj1, game->pj2, game->ball, pgf);
			break;
		default:
			break;
	}

	vita2d_end_drawing();
	vita2d_swap_buffers();
}