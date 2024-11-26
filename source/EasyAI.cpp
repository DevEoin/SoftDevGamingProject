#include "EasyAI.h"
#include <random>

EasyAI::EasyAI(std::string nameAI) : Player(nameAI){
}

void EasyAI::placeShips() {
    this->printShips();
    bool valid = false;
    int healths[5] = { 2, 3, 3, 4, 5 };

    for (int i = 0; i < 5; i++) {
        valid = false;
        std::vector<Position> temporaryP = std::vector<Position>(healths[i]);

        while (!valid) {
            bool outOfBounds = true;
            int x, y, xL, yL;

            while (outOfBounds) {
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> posD(0, 9);
                std::uniform_int_distribution<> dirD(1, 2);
                x = posD(gen);
                y = posD(gen);
                int dir = dirD(gen);
                if (dir == 1) {
                    yL = y;
                    dir = dirD(gen);

                    if (dir == 1) {
                        if (x - healths[i] < 0) {
                            xL = x + healths[i] - 1;
                        }
                        else {
                            xL = x - healths[i] - 1;
                        }
                    }
                    else {
                        if (x - healths[i] > 9) {
                            xL = x - healths[i] - 1;
                        }
                        else {
                            xL = x + healths[i] - 1;
                        }
                    }
                }
                else {
                    xL = x;
                    dir = dirD(gen);

                    if (dir == 1) {
                        if (y - healths[i] < 0) {
                            yL = y + healths[i] - 1;
                        }
                        else {
                            yL = y - healths[i] - 1;
                        }
                    }
                    else {
                        if (y - healths[i] > 9) {
                            yL = y - healths[i] - 1;
                        }
                        else {
                            yL = y + healths[i] - 1;
                        }
                    }
                
                }

                if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9) && (xL >= 0 && xL <= 9) && (yL >= 0 && yL <= 9)) {
                    if ((x == xL && abs(y - yL) == healths[i] - 1) || (y == yL && abs(x - xL) == healths[i] - 1)) {
                        outOfBounds = false;
                    }
                    else {
                        std::cout << "Position out of bounds, please try again" << std::endl;
                        outOfBounds = true;
                    }
                }
            }

            for (int k = 0; k < healths[i]; k++) {
                Position newPos{ x, y };
                if (playerBoard->isPosTaken(x, y)) {
                    outOfBounds = true;
                    break;
                }
                temporaryP[k] = newPos;

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

            if (!outOfBounds) {
                valid = true;
            }
            else {
                std::cout << "Positions were not inputted correctlly or are already taken, please try again" << std::endl;
            }
        }

        playerBoard->setPositions(temporaryP, i);
        this->printShips();
    }
}