#include <iostream>
#include <iomanip>
#include "../include/board.h"

Board::Board()
: Board(10,10) {}


Board::Board(int n_cols, int n_rows) {

    this->n_cols = n_cols;
    this->n_rows = n_rows;
    
    // Initializing the matrix with water tiles 
    std::vector <Cell> placeholder;

    for (auto i(0); i < n_rows; ++i) {
        cells.push_back(placeholder);

        for (auto j(0); j < n_cols; ++j) {
            cells[i].push_back(WATER);
        }
    }
}

void Board::drawBoard() {
// Prints the board
    std::cout << std::endl;

    for (auto i(0); i < n_rows; ++i) {
        std::cout << std::setw(20) << std::setfill(' ');
        for (auto j(0); j < n_cols; ++j) {
            std::cout << cellToString(cells[i][j]) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void Board::placeShip(Ship ship) {
    // coordinates to cell where the ship will be placed
    int x = 2;
    int y = 3;
    // TODO: assign x,y random values

    // placing the battleship
    if (ship.size == 4) {
        // if the cell is free
        if (cells[x][y] == WATER) {
            // TODO: place ship in the cell
        } else {
            // TODO: place ship in another cell
        } 
    }
}
