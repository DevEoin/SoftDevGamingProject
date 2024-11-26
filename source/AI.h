#include "Board.h"

class AI {
protected:
	Board* aiBoard;

public:
	virtual void placeShips() = 0;
	virtual void playTurn() = 0;
};