#include <iostream>
#include <vector>

class Ship {
    int health;
    char character;
    std::vector<*Position> positions;
public:
    Ship(int health, char character);
    char getChar();
    int getHealth();
    void pushPosition(const *Position newPos);
};