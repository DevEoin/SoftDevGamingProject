#include <iostream>
#include "Board.h"

int main()
{
    Board aBoard{};
    aBoard.printGridShips();
    Ship ship1{ 2, 's'};
    Position pos(0, 0);
    ship1.pushPosition(pos);
    pos.changePosition(0, 1);
    ship1.pushPosition(pos);
    aBoard.addShip(&ship1);
    aBoard.printGridShips();
    aBoard.printGridHits();
    aBoard.hitPos(0, 5);
    aBoard.printGridHits();
}