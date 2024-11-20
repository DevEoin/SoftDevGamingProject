#include <iostream>
#include <vector>
#include "Ship.h"

Ship::Ship(int health, char character) {
    this->health = health;
    this->character = character;
    this->positions.resize(health);
    for(auto variable : positions) {
        variable = nullptr;
    }
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

void Ship::hit() {
    health--;
}

bool Ship::checkForPos(int pos) {
    for(auto shipPos : positions) {
        if(pos == shipPos.getPos()) {
            return true;
        }
    }
    return false;
}