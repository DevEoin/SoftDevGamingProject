#include "Ship.h"

class Board {
    int size;                      // The size of the board (assumed to be a square grid).
    int shipsLeft;                 // The number of ships remaining on the board.
    std::vector<Ship*> ships;      // A collection of pointers to ships on the board.
    std::vector<std::vector<char>> hits; // A 2D grid tracking hits and misses.

public:
    Board(); // Constructor to initialize the board.
    ~Board(); // Destructor for releasing ships vector memory

    // Prints the board with the current positions of ships.
    void printGridShips();

    // Prints the board showing hits ('X'), misses ('O'), and empty spaces.
    void printGridHits();

    // Adds a new ship to the board.
    // Takes a pointer to a Ship object as input.
    void addShip(Ship* newShip);

    // Registers a hit at the given coordinates (x, y).
    // Returns true if a ship is hit, false otherwise.
    bool hitPos(int x, int y);

    // Sets the positions of a ship on the board.
    // Takes a vector of Position objects and an index (i) to associate with a specific ship.
    void setPositions(std::vector<Position> positions, int i);

    // Returns the number of ships left on the board.
    int getShipsLeft();

    // Checks if a specific position (x, y) is already occupied by a ship.
    // Returns true if the position is taken, false otherwise.
    bool isPosTaken(int x, int y);

    // Checks if a specific position (x, y) has already been hit.
    // Returns true if the position was hit, false otherwise.
    bool isPosHit(int x, int y);
};
