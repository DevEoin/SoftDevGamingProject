#pragma once
#include"EasyAI.h"


class GameManager
{
	Player* player1;
	Player* player2;
	EasyAI* ai;
	bool isGameOver;

public:
	//Game Managament
	void startGamePvP();
	void startGamePvE();
};

