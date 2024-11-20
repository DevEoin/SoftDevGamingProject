#include <iostream>

class Ship {
    int health;
    char character;
public:
    Ship(int health, char character);
    char getChar();
    int getHealth();
};