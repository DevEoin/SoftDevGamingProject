#include <iostream>
#include <vector>
#include "Position.h"

class Ship {
    int health;
    char character;
    std::vector<Position> positions;
public:
    Ship(int health, char character);
    char getChar();
    int getHealth();
    void pushPosition(Position newPos);
    void hit(int x, int y);
    bool checkForPos(int x, int y);
    std::vector<Position> getPositions();
};