#include <iostream>

class Position {
    int x; // x-coordinate
    int y; // y-coordinate
public:
    Position(int xPos = -1, int yPos = -1); // Constructor to initialize position
    int getX(); // Get x-coordinate
    int getY(); // Get y-coordinate
    void changePosition(int x, int y); // Change the position
};
