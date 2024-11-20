#include <iostream>
#include <vector>
#include "Ship.h"

Ship::Ship(int health, char character) {
    this->health = health;
    this->character = character;
    this->positions.resize(health);
}

int Ship::getHealth() {
    return this->health;
}

char Ship::getChar() {
    return this->character;
}

void Ship::pushPosition(const *Position newPos) {
    this->positions.push_back(newPos);
}