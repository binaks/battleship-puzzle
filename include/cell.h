#include <string>

#ifndef CELL_H
#define CELL_H

enum Cell {WATER, LEFT, RIGHT, MIDDLE, UP, DOWN, ATOM, HALO, BORDER};

std::string cellToString (Cell c);

#endif
