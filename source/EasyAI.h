#include "AI.h"

class EasyAI : public AI {
public:
	EasyAI(Board* playerBoard);
	virtual void placeShips();
	virtual void playTurn();
};