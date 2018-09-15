#include <iostream>
#include <iomanip>
#include "../include/board.h"
#include "../include/util.h"

Board::Board()
: Board(10,10) {}


Board::Board(int n_cols, int n_rows) {

    this->n_cols = n_cols;
    this->n_rows = n_rows;
    
    // Initializing the matrix with water tiles 
    std::vector <Cell> placeholder;

    for (auto i(0); i <= n_rows + 1; ++i) {
        cells.push_back(placeholder);

        for (auto j(0); j <= n_cols + 1; ++j) {
            if (i == 0 or j == 0 or i == (n_rows + 1) or j == (n_cols + 1)) {
                cells[i].push_back(BORDER);
            } else {
                cells[i].push_back(WATER);
            }
        }
    }
}

void Board::drawBoard() {
// Prints the board
    std::cout << std::endl;

    for (auto i(0); i <= n_rows + 1; ++i) {
        std::cout << std::setw(20) << std::setfill(' ');
        for (auto j(0); j <= n_cols + 1; ++j) {
            std::cout << cellToString(cells[i][j]) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void Board::generate_puzzle() {

    // creating the ships
    Ship battleship(4);
    Ship cruiser(3);
    Ship destroyer(2);
    Ship subimarine(1);
    // coordinates to cell where the ship will be places
    // placing the battleship
    
    
    int x = randomize(1,n_rows);
    int y = randomize(1,n_cols);
    // finding a free position
    while ( cells[x][y] != WATER ){
        x = randomize(1,n_rows);
        y = randomize(1,n_cols);
    }
}

void Board::placeShip() {

}
