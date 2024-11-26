#include "Board.h"
#include<string>
class Player {
protected:
	std::string name;
	Board* playerBoard;

public:
	Player(std::string name);
	virtual void placeShips();
	bool checkAlreadyHit(int x, int y);
	bool recieveHit(int x, int y);
	void printShips();
	void printHits();
	int getPlayerShipsLeft();
};