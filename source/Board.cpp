#include "Board.h"
#include <iostream>

using std::cout, std::cin, std::endl;

// Constructor for the Board class
Board::Board() {
    this->size = 10; // Initialize the grid size to 10x10
    this->shipsLeft = 5; // Initialize the number of ships left to 5
    ships.resize(5); // Resize the ships vector to hold 5 ships

    // Initialize all ship pointers to nullptr
    for (auto ship : ships) {
        ship = nullptr;
    }

    // Create a 10x10 grid for recording hits, initialized with spaces
    hits = std::vector<std::vector<char>>(size, std::vector<char>(size, ' '));
}

// Method to print the grid with ship placements
void Board::printGridShips() {
    cout << endl;
    cout << endl << "   ";

    // Print column headers
    for (int i = 0; i < size; i++) {
        cout << "  " << i << "  ";
    }
    cout << endl << "   ";

    // Print top border of the grid
    for (int i = 0; i < this->size; i++) {
        cout << "-----";
    }

    // Iterate over each row of the grid
    for (int i = 0; i < this->size; i++) {
        cout << std::endl;
        cout << i; // Print row index

        // Iterate over each column in the row
        for (int j = 0; j < this->size; j++) {
            cout << " | "; // Separator
            bool foundAShip = false;

            // Check if a ship occupies the current position
            for (auto ship : this->ships) {
                if (ship != nullptr && ship->checkForPos(i, j)) {
                    cout << ship->getChar(); // Print ship character
                    foundAShip = true;
                    break;
                }
            }

            // If no ship is found, print a space
            if (!foundAShip) {
                cout << " ";
            }
            cout << " ";

            // Close the row with a vertical bar for the last column
            if (j == size - 1) {
                cout << " |";
            }
        }

        // Print the horizontal border for the row
        std::cout << endl << "   ";
        for (int k = 0; k < size; k++) {
            cout << "-----";
        }
    }
    cout << endl;
}

// Method to print the grid showing hits and misses
void Board::printGridHits() {
    cout << endl;
    cout << endl << "   ";

    // Print column headers
    for (int i = 0; i < size; i++) {
        cout << "  " << i << "  ";
    }
    cout << endl << "   ";

    // Print top border of the grid
    for (int i = 0; i < this->size; i++) {
        cout << "-----";
    }

    // Iterate over each row of the grid
    for (int i = 0; i < this->size; i++) {
        cout << std::endl;
        cout << i; // Print row index

        // Iterate over each column in the row
        for (int j = 0; j < this->size; j++) {
            cout << " | " << hits[i][j] << " "; // Print hit, miss or a blank space if not hit
            if (j == size - 1) {
                cout << " |"; // Close the row with a vertical bar for the last column
            }
        }

        // Print the horizontal border for the row
        std::cout << endl << "   ";
        for (int k = 0; k < size; k++) {
            cout << "-----";
        }
    }
    cout << endl;
}

// Method to add a new ship to the board
void Board::addShip(Ship* newShip) {
    for (int i = 0; i < ships.size(); i++) {
        if (ships[i] == nullptr) { // Find the first available slot for the ship
            ships[i] = newShip;
            break;
        }
    }
}

// Method to process a hit attempt at a specific position
bool Board::hitPos(int x, int y) {
    for (auto ship : ships) {
        if (ship != nullptr && ship->checkForPos(x, y)) {
            hits[x][y] = 'X'; // Mark a hit on the grid
            ship->hit(x, y); // Notify the ship of the hit

            // If the ship's health reaches 0, mark it as sunk
            if (ship->getHealth() == 0) {
                std::cout << "Ship with " << ship->getPositions().size() << " health sunk!";
                shipsLeft--; // Decrement the number of remaining ships
            }
            return true; // Hit was successful
        }
    }

    // If no ship is hit, mark the position as a miss
    hits[x][y] = 'O';
    return false;
}

// Method to assign positions to a specific ship
void Board::setPositions(std::vector<Position> positions, int i) {
    for (int j = 0; j < ships[i]->getHealth(); j++) {
        ships[i]->pushPosition(positions[j]); // Add each position to the ship
    }
}

// Method to get the number of ships left on the board
int Board::getShipsLeft() {
    return shipsLeft;
}

// Method to check if a position is already occupied by a ship
bool Board::isPosTaken(int x, int y) {
    for (auto ship : ships) {
        if (ship != nullptr && ship->checkForPos(x, y)) {
            return true; // Position is occupied
        }
    }
    return false; // Position is free
}

// Method to check if a position has already been hit
bool Board::isPosHit(int x, int y) {
    if (hits[x][y] == 'X' || hits[x][y] == 'O') { // Check for prior marks
        std::cout << "Position has already been fired upon, please try again" << std::endl;
        return true; // Position has been targeted before
    }
    return false; // Position is fresh
}

// Destructor to clean up dynamically allocated ships
Board::~Board() {
    for (auto ship : ships) {
        if (ship != nullptr) {
            delete ship; // Free memory allocated for the ship
            ship = nullptr;
        }
    }
}
