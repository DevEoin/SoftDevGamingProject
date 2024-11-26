#include "GameManager.h"
#include <random>

void GameManager::startGamePvP(){
	player1 = new Player("Player 1");
	player2 = new Player("Player 2");

	player1->placeShips();
	player2->placeShips();
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
	while (!isGameOver) {
		bool hit1 = false;
		bool hit2 = false;

		do
		{
			player2->printHits();
			int x1;
			int y1;
			while (true) {
				std::cout << "Player 1 turn, Enter x: ";
				std::cin >> x1;
				std::cout << "Enter y: ";
				std::cin >> y1;
				if (x1 >= 0 && x1 <= 9 && y1 >= 0 && y1 <= 9) {
					break;
				}
				else {
					std::cout << "Invalid inputs, try again" << std::endl;
				}
			}

			if (player2->checkAlreadyHit(x1, y1)) {
				hit1 = true;
			}
			else {
				if (player2->recieveHit(x1, y1)) {
					std::cout << "Ship Hit " << "X: " << x1 << " Y: " << y1;
					hit1 = true;
				}
				else {
					hit1 = false;
				}

				player2->printHits();
				if (player2->getPlayerShipsLeft() == 0) {
					std::cout << "Player 1 wins!!!";
					isGameOver = true;
				}
			}
		} while (hit1 && !isGameOver);

		if (isGameOver) {
			break;
		}

		do
		{
			player1->printHits();
			int x2;
			int y2;
			while (true) {
				std::cout << "Player 2 turn, Enter x: ";
				std::cin >> x2;
				std::cout << "Enter y: ";
				std::cin >> y2;
				if (x2 >= 0 && x2 <= 9 && y2 >= 0 && y2 <= 9) {
					break;
				}
				else {
					std::cout << "Invalid inputs, try again" << std::endl;
				}
			}
			
			if (player1->checkAlreadyHit(x2, y2)) {
				hit2 = true;
			}
			else {
				if (player1->recieveHit(x2, y2)) {
					std::cout << "Ship Hit " << "X: " << x2 << " Y: " << y2;
					hit2 = true;
				}
				else {
					hit2 = false;
				}

				player1->printHits();
				if (player1->getPlayerShipsLeft() == 0) {
					std::cout << "Player 2 wins!!!";
					isGameOver = true;
				}
			}
		} while (hit2 && !isGameOver);
	}
}

void GameManager::startGamePvE() {
	player1 = new Player("Player 1");
	ai = new EasyAI("EasyAI");

	ai->placeShips();
	player1->placeShips();
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
	while (!isGameOver) {
		bool hit1 = false;
		bool hit2 = false;

		do
		{
			ai->printHits();
			int x1;
			int y1;
			while (true) {
				std::cout << "Player 1 turn, Enter x: ";
				std::cin >> x1;
				std::cout << "Enter y: ";
				std::cin >> y1;
				if (x1 >= 0 && x1 <= 9 && y1 >= 0 && y1 <= 9) {
					break;
				}
				else {
					std::cout << "Invalid inputs, try again" << std::endl;
				}
			}

			if (ai->checkAlreadyHit(x1, y1)) {
				hit1 = true;
			}
			else {
				if (ai->recieveHit(x1, y1)) {
					std::cout << "Ship Hit " << "X: " << x1 << " Y: " << y1;
					hit1 = true;
				}
				else {
					hit1 = false;
				}

				ai->printHits();
				if (ai->getPlayerShipsLeft() == 0) {
					std::cout << "Player 1 wins!!!";
					isGameOver = true;
				}
			}
		} while (hit1 && !isGameOver);

		if (isGameOver) {
			break;
		}

		do
		{
			player1->printHits();
			int x2;
			int y2;

			while (true) {
				std::random_device rd;
				std::mt19937 gen(rd());
				std::uniform_int_distribution<> posD(0, 9);
				std::uniform_int_distribution<> dirD(1, 2);
				x2 = posD(gen);
				y2 = posD(gen);
				if (x2 >= 0 && x2 <= 9 && y2 >= 0 && y2 <= 9) {
					break;
				}
			}

			if (player1->checkAlreadyHit(x2, y2)) {
				hit2 = true;
			}
			else {
				if (player1->recieveHit(x2, y2)) {
					std::cout << "Ship Hit " << "X: " << x2 << " Y: " << y2;
					hit2 = true;
				}
				else {
					hit2 = false;
				}

				player1->printHits();
				if (player1->getPlayerShipsLeft() == 0) {
					std::cout << "EasyAI wins!!!";
					isGameOver = true;
				}
			}
		} while (hit2 && !isGameOver);
	}
}