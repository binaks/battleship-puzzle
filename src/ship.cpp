#include "../include/ship.h"

Ship::Ship(int _size, std::vector <Cell> _horizontal, std::vector <Cell> _vertical) {
    size = _size;
    horizontal = _horizontal;
    vertical = _vertical;
}
