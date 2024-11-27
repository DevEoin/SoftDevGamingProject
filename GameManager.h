#pragma once
#include "EasyAI.h"

class GameManager
{
	Player* player1; // Pointer to the first player
	Player* player2; // Pointer to the second player
	EasyAI* ai; // Pointer to the EasyAI object, used for AI-related functionality
	bool isGameOver; // Boolean flag to track the status of the game (if the game is over)

public:
	// Game Management Functions

	void startGamePvP(); // Function to initiate a Player vs Player game (two human players)
	void startGamePvE(); // Function to initiate a Player vs Easy AI game (human player vs EasyAI)
};
