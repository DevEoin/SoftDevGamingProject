#include "Player.h"

// The EasyAI class represents a simple AI player in the game.
// It inherits from the Player class and overrides ship placement with automated logic.
class EasyAI : public Player {
public:
    // Constructor to initialize the EasyAI with a given name.
    // Calls the Player constructor to set up the name and board.
    EasyAI(std::string nameAI);

    // Overrides the placeShips() function to automate ship placement for the EasyAI.
    virtual void placeShips();
};
