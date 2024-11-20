#include <iostream>

class Board {
    const int size = 10; // chess board is 8x8
    std::vector<Ship*> ships; // vector to store pieces

public:
    Board();
    void printGrid();
}