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

void Ship::pushPosition(Position newPos) {
    this->positions.push_back(newPos);
}

void Ship::hit(int x, int y) {
    health--;
    for (int i = 0; i < positions.size(); i++) {
        if (x == this->positions[i].getX() && y == positions[i].getY()) {
            this->positions.erase(positions.begin() + i);
        }
    }
}

bool Ship::checkForPos(int x, int y) {
    for(auto shipPos : positions) {
        if(x == shipPos.getX() && y == shipPos.getY()) {
            return true;
        }
    }
    return false;
}

std::vector<Position> Ship::getPositions() {
    return positions;
}