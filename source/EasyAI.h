#include "Player.h"

class EasyAI : public Player {
public:
	EasyAI(std::string nameAI);
	virtual void placeShips();
};