#include <iostream>
#include <vector>
#include "Position.h"

class Ship {
    int health; // The health of the ship, represents the number of positions the ship occupies
    char character; // A character to represent the ship (e.g., 'B' for Battleship)
    std::vector<Position> positions; // A vector holding the positions the ship occupies on the board

public:
    // Constructor to initialize a Ship with a specified health (size) and a character representation
    Ship(int health, char character);

    // Method to get the character that represents the ship
    char getChar();

    // Method to get the current health of the ship (number of positions it still occupies)
    int getHealth();

    // Method to add a new position to the ship's positions vector
    void pushPosition(Position newPos);

    // Method to handle when the ship is hit; reduces health when hit on one of its positions
    void hit(int x, int y);

    // Method to check if the ship occupies a specific position (x, y)
    bool checkForPos(int x, int y);

    // Method to get all positions the ship occupies as a vector of Position objects
    std::vector<Position> getPositions();
};
