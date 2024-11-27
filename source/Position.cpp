#include "Position.h"
#define SIZE  10

Position::Position(int x, int y) { // Constructor to initialize x and y coordinates
    this->x = x; // Set x coordinate
    this->y = y; // Set y coordinate
}

int Position::getX() { // Return the x coordinate
    return this->x;
}

int Position::getY() { // Return the y coordinate
    return this->y;
}

void Position::changePosition(int x, int y) { // Change the position to new x and y values
    this->x = x; // Set new x coordinate
    this->y = y; // Set new y coordinate
}
