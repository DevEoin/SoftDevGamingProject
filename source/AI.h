#include "Board.h"

class AI {
protected:
	Board* aiBoard;
	Board* playerBoard;

public:
	virtual void placeShips() = 0;
	virtual void playTurn() = 0;
};