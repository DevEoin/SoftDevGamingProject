#include "Board.h"
#include<string>
class Player {

	std::string name;
	Board* playerBoard;

public:
	Player(std::string name);
	void placeShips();
	bool recieveHit(int x, int y);
	void printShips();
	void printHits();
};