#include <iostream>
#include <vector>
#include "Ship.h"

class Board {
    int size; // chess board is 8x8
    std::vector<Ship*> ships; // vector to store pieces
public:
    Board();
    void printGrid();
    void addShip(Ship* newShip);
};