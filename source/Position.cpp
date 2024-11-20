#include "Position.h"

Position::Position(int x, int y) {
    this->x = x;
    this->y = y;
}

char Position::getX() {
    return this->x;
}

char Position::getY() {
    return this->y;
}