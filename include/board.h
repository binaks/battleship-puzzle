#include <vector>
#include <string>
#include "cell.h"
#include "ship.h"

#ifndef BOARDS_H
#define BOARDS_H

class Board {
public:
    int n_cols;
    int n_rows;

    std::vector < std::vector <std::string> > cells;

    Board ();
    Board (int, int, std::vector < std::vector <std::string> >);

    void drawBoard();     // Prints the board
    void placeShip(Ship); // Places a ship in a random valid location
};

#endif
