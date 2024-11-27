#include "EasyAI.h"
#include <random>

// Constructor for EasyAI, inheriting from Player.
// Initializes the AI with the given name.
EasyAI::EasyAI(std::string nameAI) : Player(nameAI) {
}

// Function for placing ships randomly on the board for the AI.
void EasyAI::placeShips() {
    this->printShips(); // Display the AI's board (for debugging or tracking purposes).
    bool valid = false; // Variable to check if a ship's placement is valid.
    int healths[5] = { 2, 3, 3, 4, 5 }; // Array holding the health (size) of the ships.

    // Loop through all ships and place them one by one.
    for (int i = 0; i < 5; i++) {
        valid = false; // Reset valid flag for the current ship.
        std::vector<Position> temporaryP = std::vector<Position>(healths[i]); // Temporary positions for the current ship.

        // Repeat until a valid position is found for the current ship.
        while (!valid) {
            bool outOfBounds = true; // Flag to check if positions are out of bounds.
            int x, y, xL, yL;       // Variables to hold the start (x, y) and end (xL, yL) positions of the ship.

            // Randomly generate positions for the ship until they are within bounds.
            while (outOfBounds) {
                std::random_device rd;                          // Random device for seeding.
                std::mt19937 gen(rd());                         // Random number generator.
                std::uniform_int_distribution<> posD(0, 9);     // Distribution for generating positions (0-9).
                std::uniform_int_distribution<> dirD(1, 2);     // Distribution for generating directions (1 or 2).

                x = posD(gen);                                  // Random starting x-coordinate.
                y = posD(gen);                                  // Random starting y-coordinate.
                int dir = dirD(gen);                            // Random direction (1 = vertical, 2 = horizontal).

                // If vertical placement (dir == 1)
                if (dir == 1) {
                    yL = y; // Maintain the same y-coordinate.
                    dir = dirD(gen); // Randomly decide direction along the x-axis.

                    // Check if the ship should extend to the top or bottom.
                    if (dir == 1) {
                        if (x - healths[i] < 0) {
                            xL = x + healths[i] - 1; // Extend to the bottom if towards the top is not.
                        }
                        else {
                            xL = x - healths[i] - 1; // Extend to the top otherwise.
                        }
                    }
                    else {
                        if (x + healths[i] > 9) {
                            xL = x - healths[i] - 1; // Extend to the top towards the bottom is not.
                        }
                        else {
                            xL = x + healths[i] - 1; // Extend to the bottom otherwise.
                        }
                    }
                }
                else { // If horizontal placement (dir == 2)
                    xL = x; // Maintain the same x-coordinate.
                    dir = dirD(gen); // Randomly decide direction along the y-axis.

                    // Check if the ship should extend left or right along y-axis.
                    if (dir == 1) {
                        if (y - healths[i] < 0) {
                            yL = y + healths[i] - 1; // Extend rigth if left not possible.
                        }
                        else {
                            yL = y - healths[i] - 1; // Extend left otherwise.
                        }
                    }
                    else {
                        if (y + healths[i] > 9) {
                            yL = y - healths[i] - 1; // Extend left if right not possible.
                        }
                        else {
                            yL = y + healths[i] - 1; // Extend right otherwise.
                        }
                    }
                }

                // Check if the start and end positions are within bounds and valid for the ship's size.
                if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9) &&
                    (xL >= 0 && xL <= 9) && (yL >= 0 && yL <= 9)) {
                    if ((x == xL && abs(y - yL) == healths[i] - 1) ||
                        (y == yL && abs(x - xL) == healths[i] - 1)) {
                        outOfBounds = false; // Valid positions found.
                    }
                    else {
                        outOfBounds = true; // Invalid positions.
                    }
                }
            }

            // Assign positions to the ship, ensuring no overlap with existing ships.
            for (int k = 0; k < healths[i]; k++) {
                Position newPos{ x, y }; // Create a new position for the ship.

                // Check if the position is already occupied by another ship.
                if (playerBoard->isPosTaken(x, y)) {
                    outOfBounds = true; // Mark as invalid if overlapping.
                    break;
                }
                temporaryP[k] = newPos; // Store the valid position.

                // Adjust coordinates for the next segment of the ship.
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

            // If all positions are valid and not overlapping, finalize the placement.
            if (!outOfBounds) {
                valid = true;
            }
            else {
                std::cout << "Positions were not inputted correctly or are already taken, please try again" << std::endl;
            }
        }

        // Save the valid ship positions on the board.
        playerBoard->setPositions(temporaryP, i);
        this->printShips(); // Display the updated board after placing the ship.
    }
}
