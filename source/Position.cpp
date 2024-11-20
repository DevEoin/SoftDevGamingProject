#include "Position.h"
#define SIZE = 8

Position::Position(char x, char y) {
    this->x = x;
    this->y = y;

    int x1 = '8' - xPos;
    int y1 = yPos - 'A';
    pos = x1*SIZE + y1;
}

char Position::getX() {
    return this->x;
}

char Position::getY() {
    return this->y;
}

int Position::getPos() {
    return pos;
}