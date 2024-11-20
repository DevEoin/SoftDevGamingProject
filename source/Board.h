#include <iostream>

class Board {
    int size; // chess board is 8x8
    std::vector<Ship*> ships; // vector to store pieces
public:
    Board();
    void printGrid();
}