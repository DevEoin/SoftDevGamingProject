#include "Ship.h"

Ship::Ship(int health, char character) {
    this->health = health;
    this->character = character;
}

int Ship::getHealth() {
    return this->health;
}

char Ship::getChar() {
    return this->character;
}