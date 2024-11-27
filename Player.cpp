#include "Player.h"
#include <cmath>

// Constructor for Player class: initializes the player's name and board, and adds ships to the board.
Player::Player(std::string name) {
    this->name = name;               // Set the player's name.
    playerBoard = new Board();       // Allocate a new board for the player.

    // Add ships to the board with specific health values and identifiers.
    playerBoard->addShip(new Ship(2, 'L')); // Lifeboat (2 health)
    playerBoard->addShip(new Ship(3, 'S')); // Submarine (3 health)
    playerBoard->addShip(new Ship(3, 'C')); // Cruiser (3 health)
    playerBoard->addShip(new Ship(4, 'B')); // Battleship (4 health)
    playerBoard->addShip(new Ship(5, 'D')); // Destroyer (5 health)
}

// Function to handle when a player receives a hit at position (x, y).
// Returns true if the position contains a ship and was successfully hit.
bool Player::recieveHit(int x, int y) {
    return playerBoard->hitPos(x, y);
}

// Function to place ships on the board.
void Player::placeShips() {
    this->printShips();              // Print the current state of ships the board.
    bool valid = false;              // Variable to check if a placement is valid.
    int healths[5] = { 2, 3, 3, 4, 5 }; // Array holding the health values for the ships.

    // Loop through all the ships to place them one by one.
    for (int i = 0; i < 5; i++) {
        valid = false;               // Reset valid to false for each ship.
        std::vector<Position> temporaryP = std::vector<Position>(healths[i]); // Temporary positions for the ship.

        // Repeat until a valid position is found for the current ship.
        while (!valid) {
            bool outOfBounds = true; // Flag to check if positions are out of bounds.
            int x, y, xL, yL;        // Variables to store ship's start and end positions.

            // Ensure the start and end positions are within bounds and valid.
            while (outOfBounds) {
                std::cout << this->name << " please enter the x value of the first position of a " << healths[i] << " health ship: ";
                std::cin >> x;
                std::cout << this->name << " please enter the y value of the first position of a " << healths[i] << " health ship: ";
                std::cin >> y;
                std::cout << this->name << " please enter the x value of the " << healths[i] << ". position of a " << healths[i] << " health ship: ";
                std::cin >> xL;
                std::cout << this->name << " please enter the y value of the " << healths[i] << ". position of a " << healths[i] << " health ship: ";
                std::cin >> yL;

                // Check if the positions are within bounds and match the ship's length.
                if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9) &&
                    (xL >= 0 && xL <= 9) && (yL >= 0 && yL <= 9)) {
                    if ((x == xL && abs(y - yL) == healths[i] - 1) ||
                        (y == yL && abs(x - xL) == healths[i] - 1)) {
                        outOfBounds = false;
                    }
                    else {
                        std::cout << "Position out of bounds, please try again" << std::endl;
                        outOfBounds = true;
                    }
                }
            }

            // Assign positions to the ship and ensure no overlap with other ships.
            for (int k = 0; k < healths[i]; k++) {
                Position newPos{ x, y };  // Create a new position.

                // Check if the position is already occupied by another ship.
                if (playerBoard->isPosTaken(x, y)) {
                    outOfBounds = true;  // Mark as invalid if overlapping.
                    break;
                }
                temporaryP[k] = newPos;  // Store the valid position.

                // Increment or decrement coordinates based on the ship's direction.
                if (x < xL && y == yL) {
                    x++;
                }
                else if (x > xL && y == yL) {
                    x--;
                }
                else if (y < yL && x == xL) {
                    y++;
                }
                else if (y > yL && x == xL) {
                    y--;
                }
            }

            // Check if the positions are valid and not overlapping.
            if (!outOfBounds) {
                valid = true;         // Mark placement as valid.
            }
            else {
                std::cout << "Positions were not inputted correctly or are already taken, please try again" << std::endl;
            }
        }

        // Save the valid ship positions on the board.
        playerBoard->setPositions(temporaryP, i);
        this->printShips();          // Print the updated board after placing the ship.
    }
    std::cout << std::endl << std::endl << std::endl << std::endl;
}

// Function to print the player's board with ships.
void Player::printShips() {
    std::cout << std::endl << std::endl << "                    " << this->name << " Board";
    playerBoard->printGridShips();
}

// Function to print the player's board with hit markers.
void Player::printHits() {
    std::cout << std::endl << std::endl << "                    " << this->name << " Board";
    playerBoard->printGridHits();
}

// Function to get the number of ships the player has left.
int Player::getPlayerShipsLeft() {
    return playerBoard->getShipsLeft();
}

// Function to check if a position has already been hit.
bool Player::checkAlreadyHit(int x, int y) {
    return playerBoard->isPosHit(x, y);
}

//Player Destructor to deallocate the playerBoard
Player::~Player() {
    delete playerBoard;
    playerBoard = nullptr;
}
