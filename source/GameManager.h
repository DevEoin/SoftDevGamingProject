#pragma once
#include "Player.h"
#include "EasyAI.h"

class GameManager
{
	Player* player1;
	Player* player2;
	EasyAI aiPlayer;
	bool isGameOver;

public:
	GameManager();

	//Game Managament
	void startGame();
	void takeTurn();
	void displayStatus();
};

