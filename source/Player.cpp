#include "Player.h"
#include <cmath>

Player::Player(std::string name) {
	this->name = name;
	playerBoard = new Board();
	playerBoard->addShip(new Ship(2, 'L')); //Lifeboat
	playerBoard->addShip(new Ship(3, 'S')); //Submarine
	playerBoard->addShip(new Ship(3, 'C')); //Cruiser
	playerBoard->addShip(new Ship(4, 'B')); //Battleship
	playerBoard->addShip(new Ship(5, 'D')); //Destroyer
}

bool Player::recieveHit(int x, int y) {
	return playerBoard->hitPos(x, y);
}

void Player::placeShips() {
	bool valid = false;
	int healths[5] = { 2, 3, 3, 4, 5 };
	for (int i = 0; i < 5; i++) {
		valid = false;
		std::vector<Position> temporaryP = std::vector<Position>(healths[i]);
		while (!valid) {
			bool outOfBounds = true;
			for (int j = 0; j < 1; j++) {
				
				int x, y, xL, yL;
				while (outOfBounds) {
					std::cout << this->name <<" please enter the x value of the " << j + 1 << ". position of a " << healths[i] << " health ship: ";
					std::cin >> x;
					std::cout << this->name << " please enter the y value of the " << j + 1 << ". position of a " << healths[i] << " health ship: ";
					std::cin >> y;
					std::cout << this->name << " please enter the x value of the " << healths[i] << ". position of a " << healths[i] << " health ship: ";
					std::cin >> xL;
					std::cout << this->name << " please enter the y value of the " << healths[i] << ". position of a " << healths[i] << " health ship: ";
					std::cin >> yL;
					if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9) && (xL >= 0 && xL <= 9) && (yL >= 0 && yL <= 9)) {
						outOfBounds = false;
					}
					if ((x == xL && abs(y - yL) == healths[i] - 1) || (y == yL && abs(x - xL) == healths[i] - 1)) {
						outOfBounds = false;
					}
					else {
						std::cout << "Position out of bounds, please try again" << std::endl;
						outOfBounds = true;
					}
				}
				for (int k = 0; k < healths[i]; k++) {
					Position newPos{ x, y };
					temporaryP[k] = newPos;
					if (x < xL && y == yL) {
						x++;
					}
					else if (x > xL && y == yL)
					{
						x--;
					}
					else if (y < yL && x == xL) {
						y++;
					}
					else if (y > yL && x == xL) {
						y--;
					}
				}
			}

			if (!outOfBounds) {
				valid = true;
			}
			else {
				std::cout << "Positions were not inputted incrementaly next to each other, please try again" << std::endl;
			}
		}
		playerBoard->setPositions(temporaryP, i);
		this->printShips();
	}
}

void Player::printShips() {
	playerBoard->printGridShips();
}

void Player::printHits() {
	playerBoard->printGridHits();
}