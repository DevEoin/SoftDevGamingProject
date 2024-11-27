#include "GameManager.h"
#include <random>

void GameManager::startGamePvP() {
	// Initialize players
	player1 = new Player("Player 1"); // Create Player 1
	player2 = new Player("Player 2"); // Create Player 2

	// Players place their ships
	player1->placeShips();
	player2->placeShips();
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;

	// Game loop until game over
	while (!isGameOver) {
		bool hit1 = false;
		bool hit2 = false;

		// Player 1's turn
		do
		{
			// Print Player 2's hits grid
			player2->printHits();
			int x1;
			int y1;

			// Input validation loop for Player 1
			while (true) {
				std::cout << "Player 1 turn, Enter x: "; // Ask for Player 1's move
				std::cin >> x1;
				std::cout << "Enter y: "; // Ask for Player 1's y-coordinate
				std::cin >> y1;
				if (x1 >= 0 && x1 <= 9 && y1 >= 0 && y1 <= 9) {
					break; // Valid coordinates
				}
				else {
					std::cout << "Invalid inputs, try again" << std::endl; // Invalid input
				}
			}

			// Check if Player 1 has already hit the position
			if (player2->checkAlreadyHit(x1, y1)) {
				hit1 = true; // Position already hit
			}
			else {
				// Check if the hit is successful
				if (player2->recieveHit(x1, y1)) {
					std::cout << "Ship Hit " << "X: " << x1 << " Y: " << y1;
					hit1 = true;
				}
				else {
					hit1 = false; // Missed hit
				}

				player2->printHits(); // Update the hits grid
				// Check if Player 2 has lost all ships
				if (player2->getPlayerShipsLeft() == 0) {
					std::cout << "Player 1 wins!!!"; // Player 1 wins
					isGameOver = true; // End game
				}
			}
		} while (hit1 && !isGameOver); // Repeat if Player 1 hits and the game is not over

		// Check if game is over
		if (isGameOver) {
			break;
		}

		// Player 2's turn
		do
		{
			// Print Player 1's hits grid
			player1->printHits();
			int x2;
			int y2;

			// Input validation loop for Player 2
			while (true) {
				std::cout << "Player 2 turn, Enter x: "; // Ask for Player 2's x-coordinate
				std::cin >> x2;
				std::cout << "Enter y: "; // Ask for Player 2's y-coordinate
				std::cin >> y2;
				if (x2 >= 0 && x2 <= 9 && y2 >= 0 && y2 <= 9) {
					break; // Valid coordinates
				}
				else {
					std::cout << "Invalid inputs, try again" << std::endl; // Invalid input
				}
			}

			// Check if Player 2 has already hit the position
			if (player1->checkAlreadyHit(x2, y2)) {
				hit2 = true; // Position already hit
			}
			else {
				// Check if the hit is successful
				if (player1->recieveHit(x2, y2)) {
					std::cout << "Ship Hit " << "X: " << x2 << " Y: " << y2;
					hit2 = true;
				}
				else {
					hit2 = false; // Missed hit
				}

				player1->printHits(); // Update the hits grid
				// Check if Player 1 has lost all ships
				if (player1->getPlayerShipsLeft() == 0) {
					std::cout << "Player 2 wins!!!"; // Player 2 wins
					isGameOver = true; // End game
				}
			}
		} while (hit2 && !isGameOver); // Repeat if Player 2 hits and the game is not over
	}
}

void GameManager::startGamePvE() {
	// Initialize Player 1 and AI
	player1 = new Player("Player 1");
	ai = new EasyAI("EasyAI");

	// Players and AI place their ships
	ai->placeShips();
	player1->placeShips();
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;

	// Game loop until game over
	while (!isGameOver) {
		bool hit1 = false;
		bool hit2 = false;

		// Player 1's turn
		do
		{
			// Print AI's hits grid
			ai->printHits();
			int x1;
			int y1;

			// Input validation loop for Player 1
			while (true) {
				std::cout << "Player 1 turn, Enter x: "; // Ask for Player 1's move
				std::cin >> x1;
				std::cout << "Enter y: "; // Ask for Player 1's y-coordinate
				std::cin >> y1;
				if (x1 >= 0 && x1 <= 9 && y1 >= 0 && y1 <= 9) {
					break; // Valid coordinates
				}
				else {
					std::cout << "Invalid inputs, try again" << std::endl; // Invalid input
				}
			}

			// Check if Player 1 has already hit the position
			if (ai->checkAlreadyHit(x1, y1)) {
				hit1 = true; // Position already hit
			}
			else {
				// Check if the hit is successful
				if (ai->recieveHit(x1, y1)) {
					std::cout << "Ship Hit " << "X: " << x1 << " Y: " << y1;
					hit1 = true;
				}
				else {
					hit1 = false; // Missed hit
				}

				ai->printHits(); // Update the hits grid
				// Check if AI has lost all ships
				if (ai->getPlayerShipsLeft() == 0) {
					std::cout << "Player 1 wins!!!"; // Player 1 wins
					isGameOver = true; // End game
				}
			}
		} while (hit1 && !isGameOver); // Repeat if Player 1 hits and the game is not over

		// Check if game is over
		if (isGameOver) {
			break;
		}

		// AI's turn (Randomly chosen coordinates)
		do
		{
			// Print Player 1's hits grid
			player1->printHits();
			int x2;
			int y2;

			// Randomly generate coordinates for AI's move
			while (true) {
				std::random_device rd;
				std::mt19937 gen(rd());
				std::uniform_int_distribution<> posD(0, 9); // Random x and y coordinates
				x2 = posD(gen);
				y2 = posD(gen);
				if (x2 >= 0 && x2 <= 9 && y2 >= 0 && y2 <= 9) {
					break; // Valid coordinates
				}
			}

			// Check if AI has already hit the position
			if (player1->checkAlreadyHit(x2, y2)) {
				hit2 = true; // Position already hit
			}
			else {
				// Check if the hit is successful
				if (player1->recieveHit(x2, y2)) {
					std::cout << "Ship Hit " << "X: " << x2 << " Y: " << y2;
					hit2 = true;
				}
				else {
					hit2 = false; // Missed hit
				}

				player1->printHits(); // Update the hits grid
				// Check if Player 1 has lost all ships
				if (player1->getPlayerShipsLeft() == 0) {
					std::cout << "EasyAI wins!!!"; // AI wins
					isGameOver = true; // End game
				}
			}
		} while (hit2 && !isGameOver); // Repeat if AI hits and the game is not over
	}
}
