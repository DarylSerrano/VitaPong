#ifndef	GAME_H
#define	GAME_H

#include "paddle.h"

typedef enum State
{
	MAIN_MENU,
	IN_GAME
} State;

typedef struct Game
{
	State gameState;
	
} Game;

#endif