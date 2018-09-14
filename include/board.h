#include <vector>
#include <string>
#include "cell.h"

#ifndef BOARDS_H
#define BOARDS_H

class Board {
public:
    int n_cols;
    int n_rows;

    std::vector < std::vector <std::string> > cells;

    Board ();
    Board (int, int, std::vector < std::vector <std::string> >);

    void drawBoard();
};

#endif
