#include <iostream>
#include "Player.h"

int main()
{
	Player player1{ "Player One" };
	player1.printShips();
	player1.placeShips();
	player1.printShips();
}