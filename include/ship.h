#ifndef SHIPS_H
#define SHIPS_H
#include <vector>
#include "cell.h"

class Ship {
public:
    int size;
    std::vector <Cell> horizontal;
    std::vector <Cell> vertical;

    Ship (int, std::vector <Cell>, std::vector <Cell>);
};

#endif
