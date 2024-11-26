#include "Ship.h"

class Board {
    int size;
    int shipsLeft;
    std::vector<Ship*> ships;
    std::vector<std::vector<char>> hits;
    
public:
    Board();
    void printGridShips();
    void printGridHits();
    void addShip(Ship* newShip);
    bool hitPos(int x, int y);
    void setPositions(std::vector<Position> positions, int i);
    int getShipsLeft();
    bool isPosTaken(int x, int y);
    bool isPosHit(int x, int y);
};