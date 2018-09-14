#include <iostream>
#include <iomanip>
#include "../include/board.h"

Board::Board() {
    n_cols = 10;
    n_rows = 10;
    
    std::vector <std::string> placeholder;

    for (auto i(0); i < n_rows; ++i) {
        cells.push_back(placeholder);

        for (auto j(0); j < n_cols; ++j) {
            cells[i].push_back(cellToString(WATER));
        }
    }
}

void Board::drawBoard() {
    std::cout << std::endl;

    for (auto i(0); i < n_rows; ++i) {
        std::cout << std::setw(20) << std::setfill(' ');
        for (auto j(0); j < n_cols; ++j) {
            std::cout << cells[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}
