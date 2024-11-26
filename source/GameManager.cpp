#include "GameManager.h"

void GameManager::startGame(){
	player1 = new Player("Player 1");
	player2 = new Player("Player 2");

	player1->placeShips();
	player2->placeShips();

	while (true) {
		bool hit1 = true;
		bool hit2 = true;

		do
		{
			int x1;
			int y1;
			std::cout << "Player 1 turn, Enter x";
			std::cin >> x1;
			std::cout << "Enter y";
			std::cin >> y1;

			if (player2->recieveHit(x1, y1)) {
				std::cout << "Ship Hit " << "X: " << x1 << " Y: " << y1;
			}
			else {
				hit1 = false;
			}

			player2->printHits();
			


		} while (hit1);

		do
		{
			int x2;
			int y2;
			std::cout << "Player 2 turn, Enter x";
			std::cin >> x2;
			std::cout << "Enter y";
			std::cin >> y2;

			if (player1->recieveHit(x2, y2)) {
				std::cout << "Ship Hit " << "X: " << x2 << " Y: " << y2;
			}
			else {
				hit2 = false;
			}

			player1->printHits();



		} while (hit2);


	}
}