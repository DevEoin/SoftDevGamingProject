#include <iostream>
#include <vector>
#include "Ship.h"

class Board {
    int size;
    std::vector<Ship*> ships;
    std::vector<std::vector<char>> hits;
    
public:
    Board();
    void printGridShips();
    void printGridHits();
    void addShip(Ship* newShip);
    bool hitPos(int x, int y);
    void setPositions(std::vector<Position> positions);
};