#include "Position.h"
#define SIZE  10

Position::Position(int x, int y) {
    this->x = x;
    this->y = y;
}

int Position::getX() {
    return this->x;
}

int Position::getY() {
    return this->y;
}

void Position::changePosition(int x, int y) {
    this->x = x;
    this->y = y;
}