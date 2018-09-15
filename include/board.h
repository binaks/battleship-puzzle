#include <vector>
#include <string>
#include "cell.h"
#include "ship.h"

#ifndef BOARDS_H
#define BOARDS_H

class Board {
public:
    int n_rows;
    int n_cols;

    std::vector < std::vector <Cell> > cells;

    Board ();
    Board (int, int);

    void drawBoard();     // Prints the board
    void generate_puzzle(); // Generate the puzzle
    void placeShip(); // Places a ship in a random valid location
};

#endif
