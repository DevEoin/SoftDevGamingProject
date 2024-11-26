#include "Board.h"
#include<string>
class Player {

	Board* playerBoard;
	std::string name;

public:
	Player(std::string name);
	void placeShips();
	bool recieveHit(int x, int y);
};