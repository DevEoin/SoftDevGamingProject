#include <iostream>
#include "GameManager.h"

int main()
{
	std::cout << "Press 1 for PvP, 2 for PvE: ";
	int choice;
	std::cin >> choice;
	if (choice == 1) {
		GameManager gm{};
		gm.startGamePvP();
	}
	else if(choice == 2) {
		GameManager gm{};
		gm.startGamePvE();
	}
	else {
		std::cout << "Invalid input, program ending";
	}
}