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
	std::vector<std::vector<Position>> positions = std::vector<std::vector<Position>>(5);
	for (int i = 0; i < 5; i++) {
		valid = false;
		positions[i] = std::vector<Position>(healths[i]);
		std::vector<Position> temporaryP = std::vector<Position>(healths[i]);
		while (!valid) {
			for (int j = 0; j < 1; j++) {
				bool outOfBounds = true;
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
			Position previous{};
			bool mistake = false;
			for (auto p : temporaryP) {
				if (previous.getX() == -1) {
					previous.changePosition(temporaryP[0].getX(), temporaryP[0].getY());
				}
				else {
					if (p.getX() != previous.getX() && p.getY() != previous.getY()) {
						mistake = true;
						break;
					}
					else if ((p.getX() == previous.getX() && (p.getY() == previous.getY() + 1 || p.getY() == previous.getY() - 1))
						|| (p.getY() == previous.getY() && (p.getX() == previous.getX() + 1 || p.getX() == previous.getX() - 1))) {
						
					}
					else {
						bool nothing = false;
						for (auto p2 : temporaryP) {
							if ((p.getX() == p2.getX() && (p.getY() == p2.getY() + 1 || p.getY() == p2.getY() - 1))
								|| (p.getY() == p2.getY() && (p.getX() == p2.getX() + 1 || p.getX() == p2.getX() - 1))) {
								mistake = false;
								break;
							}
							nothing = true;
						}
						if (nothing) {
							mistake = true;
						}
					}
					
				}
				previous = p;
			}

			if (!mistake) {
				valid = true;
			}
			else {
				std::cout << "Positions were not inputted incrementaly next to each other, please try again" << std::endl;
			}
		}
		positions[i] = temporaryP;
	}
	playerBoard->setPositions(positions);
	this->printShips();
}

void Player::printShips() {
	playerBoard->printGridShips();
}

void Player::printHits() {
	playerBoard->printGridHits();
}