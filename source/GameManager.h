#pragma once
#include "Player.h"


class GameManager
{
	Player* player1;
	Player* player2;
	bool isGameOver;

public:
	//Game Managament
	void startGame();

};

