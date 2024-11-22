#include "Board.h"
#include <iostream>

using std::cout, std::cin, std::endl;

Board::Board() {
    this->size = 10;
    ships.resize(5);
    for(auto ship : ships) {
        ship = nullptr;
    }
    hits.resize(10);
    for (auto column : hits) {
        column.resize(10);
    }
}

void Board::printGrid(){
  cout<<endl;
  cout << endl << "   ";
  for (int i = 0; i < size; i++) {
      cout << "  " << i << "  ";
  }
  cout<< endl << "   ";
  for (int i = 0; i < this->size; i++) {
      cout << "-----";
  }
  for (int i = 0; i < this->size; i++) {
      cout << std::endl;
      cout << i;
      for (int j = 0; j < this->size; j++) {
          cout << " | ";
          bool foundAShip = false;
          for (auto ship : this->ships) {
              if (ship != nullptr && ship->checkForPos(i, j)) {
                  cout << ship->getChar();
                  foundAShip = true;
                  break;
              }
          }
          if (!foundAShip) {
              cout << " ";
          }
          cout << " ";
          if (j == size - 1) {
              cout << " |";
          }
      }
      std::cout << endl << "   ";
      for (int k = 0; k < size; k++) {
          cout << "-----";
      }
  }
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
        if (ship->checkForPos(x, y)) {
            hits[x][y] = 'X';
            return true;
        }
    }
    hits[x][y] = 'O';
    return false;
}