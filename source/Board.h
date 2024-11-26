#include <iostream>
#include <vector>
#include "Ship.h"

class Board {
    int size; // chess board is 8x8
    std::vector<Ship*> ships; // vector to store pieces
    
public:
    std::vector<std::vector<char>> hits;
    Board();
    void printGridShips();
    void printGridHits();
    void addShip(Ship* newShip);
    bool hitPos(int x, int y);
};