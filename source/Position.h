#include <iostream>

class Position {
    int x;
    int y;
public:
    Position(int xPos = -1, int yPos = -1);
    int getX();
    int getY();
    void changePosition(int x, int y);
};