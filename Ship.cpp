#include <iostream>
#include <vector>
#include "Ship.h"

// Constructor to initialize a Ship with a given health (size) and character representation
Ship::Ship(int health, char character) {
    this->health = health; // Set the ship's health to the given value
    this->character = character; // Set the ship's character representation (e.g., 'B' for Battleship)
    this->positions.resize(health); // Resize the positions vector to match the health (size) of the ship
}

// Method to get the current health of the ship (how many positions it occupies)
int Ship::getHealth() {
    return this->health; // Return the ship's current health
}

// Method to get the character that represents the ship (e.g., 'B', 'S', 'D')
char Ship::getChar() {
    return this->character; // Return the ship's character representation
}

// Method to add a new position to the ship's positions vector
void Ship::pushPosition(Position newPos) {
    this->positions.push_back(newPos); // Add the new position to the ship's positions list
}

// Method to handle when the ship is hit at a specific position (x, y), reducing its health
void Ship::hit(int x, int y) {
    health--; // Decrease the ship's health by 1 (since it's hit)
    for (int i = 0; i < positions.size(); i++) { // Loop through all the positions occupied by the ship
        if (x == this->positions[i].getX() && y == positions[i].getY()) { // If the position matches the hit
            this->positions.erase(positions.begin() + i); // Remove the hit position from the ship's positions
        }
    }
}

// Method to check if the ship occupies a specific position (x, y)
bool Ship::checkForPos(int x, int y) {
    for (auto shipPos : positions) { // Loop through the ship's positions
        if (x == shipPos.getX() && y == shipPos.getY()) { // If the given position matches any of the ship's positions
            return true; // Return true, indicating the ship occupies that position
        }
    }
    return false; // If no match is found, return false
}

// Method to return all positions the ship occupies as a vector of Position objects
std::vector<Position> Ship::getPositions() {
    return positions; // Return the vector of positions the ship occupies
}
