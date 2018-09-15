#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>

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

    void drawBoard(std::ofstream*); // Prints the board
    void generate_puzzle(); // Generate the puzzle
    void placeShip(Ship); // Places a ship in a random valid location
};

#endif
