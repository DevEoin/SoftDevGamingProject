#include "Player.h"

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
		std::vector<Position> positions = std::vector<Position>(healths[i]);
		while (!valid) {
			for (int j = 0; j < healths[i]; i++) {
				bool outOfBounds = true;
				int x, y;
				while (outOfBounds) {
					std::cout << "Please enter the x value of the " << j << ". position of a " << healths[i] << " health ship: ";
					std::cin >> x;
					std::cout << "Please enter the y value of the " << j << ". position of a " << healths[i] << " health ship: ";
					std::cin >> y;
					if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9)) {
						outOfBounds = false;
					}
				}
				Position newPos{ x, y };
				positions.push_back(newPos);
			}
			Position previous{};
			bool mistake = false;
			for (auto p : positions) {
				if (previous.getX() == -1) {
					previous.changePosition(positions[0].getX(), positions[0].getY());
				} else {
					if (p.getX() != previous.getX() && p.getY() != previous.getY()) {
						mistake = true;
						break;
					}
					
				}
			}

			if (!mistake) {
				valid = true;
			}
		}
	}
}