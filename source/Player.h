#include "Board.h"
#include <string>

// The Player class represents a player in the game.
// It provides basic functionalities such as placing ships, checking hits, and managing the player's board.
class Player {
protected:
    std::string name;       // The name of the player.
    Board* playerBoard;     // A pointer to the player's board, which manages ships and hits.

public:
    // Constructor that initializes the player with a given name.
    // The player's board is set up during initialization.
    Player(std::string name);
    ~Player(); // Destructor to deallocate memory of the Board pointer

    // Virtual function to allow placing ships.
    // Overriden by EasyAI for custom ship placement logic.
    virtual void placeShips();

    // Checks if a given position (x, y) has already been hit.
    // Returns true if the position was previously hit, otherwise false.
    bool checkAlreadyHit(int x, int y);

    // Receives a hit at the specified position (x, y).
    // Returns true if a ship was hit, otherwise false.
    bool recieveHit(int x, int y);

    // Prints the current state of the player's board, including ship positions.
    void printShips();

    // Prints the current state of the board showing hits and misses.
    void printHits();

    // Returns the number of ships the player still has left on the board.
    int getPlayerShipsLeft();
};
