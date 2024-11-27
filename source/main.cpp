#include <iostream>
#include "GameManager.h"

int main()
{
	// Prompt the user to choose the game mode: 1 for Player vs Player (PvP), 2 for Player vs Easy AI (PvE)
	std::cout << "Press 1 for PvP, 2 for PvE: ";
	int choice;
	std::cin >> choice; // Get user input for game mode selection

	// If the user chooses PvP
	if (choice == 1) {
		// Create a GameManager object and start the PvP game
		GameManager gm{};
		gm.startGamePvP(); // Start Player vs Player game
	}
	// If the user chooses PvE
	else if (choice == 2) {
		// Create a GameManager object and start the PvE game
		GameManager gm{};
		gm.startGamePvE(); // Start Player vs Easy AI game
	}
	// If the user provides an invalid input
	else {
		// Display an error message and end the program
		std::cout << "Invalid input, program ending";
	}
}
