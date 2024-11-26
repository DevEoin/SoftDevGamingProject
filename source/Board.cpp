#include "Board.h"
#include <iostream>

using std::cout, std::cin, std::endl;

Board::Board() {
    this->size = 10;
    this->shipsLeft = 5;
    ships.resize(5);
    for(auto ship : ships) {
        ship = nullptr;
    }
    hits = std::vector<std::vector<char>> (size, std::vector<char>(size, ' '));
}

void Board::printGridShips() {
    cout << endl;
    cout << endl << "   ";

    // Print column headers
    for (int i = 0; i < size; i++) {
        cout << "  " << i << "  ";
    }
    cout << endl << "   ";

    // Print top border
    for (int i = 0; i < this->size; i++) {
        cout << "-----";
    }

    // Print grid rows
    for (int i = 0; i < this->size; i++) {
        cout << std::endl;
        cout << i;

        // Print cells in the row
        for (int j = 0; j < this->size; j++) {
            cout << " | ";
            bool foundAShip = false;

            // Check if a ship exists at the current position
            for (auto ship : this->ships) {
                if (ship != nullptr && ship->checkForPos(i, j)) {
                    cout << ship->getChar();
                    foundAShip = true;
                    break;
                }
            }

            // If no ship is found, print a space
            if (!foundAShip) {
                cout << " ";
            }
            cout << " ";

            // Close the row if it's the last column
            if (j == size - 1) {
                cout << " |";
            }
        }

        // Print row border
        std::cout << endl << "   ";
        for (int k = 0; k < size; k++) {
            cout << "-----";
        }
    }
    cout << endl;
}

void Board::printGridHits() {
    cout << endl;
    cout << endl << "   ";
    for (int i = 0; i < size; i++) {
        cout << "  " << i << "  ";
    }
    cout << endl << "   ";
    for (int i = 0; i < this->size; i++) {
        cout << "-----";
    }
    for (int i = 0; i < this->size; i++) {
        cout << std::endl;
        cout << i;
        for (int j = 0; j < this->size; j++) {
            cout << " | " << hits[i][j] << " ";
            if (j == size - 1) {
                cout << " |";
            }
        }
        std::cout << endl << "   ";
        for (int k = 0; k < size; k++) {
            cout << "-----";
        }
    }
    cout << endl;
}

void Board::addShip(Ship* newShip) {
    for (int i = 0; i < ships.size(); i++) {
        if (ships[i] == nullptr) {
            ships[i] = newShip;
            break;
        }
    }
}

bool Board::hitPos(int x, int y) {
    for (auto ship : ships) {
        if (ship != nullptr && ship->checkForPos(x, y)) {
            hits[x][y] = 'X';
            ship->hit(x, y);
            if (ship->getHealth() == 0) {
                std::cout << "Ship with " << ship->getPositions().size() << " health sunk!";
                shipsLeft--;
            }
            return true;
        }
    }
    hits[x][y] = 'O';
    return false;
}

void Board::setPositions(std::vector<Position> positions, int i) {
    for (int j = 0; j < ships[i]->getHealth(); j++) {
        ships[i]->pushPosition(positions[j]);
    }
}

int Board::getShipsLeft() {
    return shipsLeft;
}
bool Board::isPosTaken(int x, int y) {
    for (auto ship : ships) {
        if (ship != nullptr && ship->checkForPos(x, y)) {
            return true;
        }
    }
    return false;
}

bool Board::isPosHit(int x, int y) {
    if (hits[x][y] == 'X' || hits[x][y] == 'O') {
        std::cout << "Position has already been fired upon, please try again" << std::endl;
        return true;
    }
    return false;
}