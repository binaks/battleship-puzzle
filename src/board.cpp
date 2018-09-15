#include "../include/board.h"
#include "../include/util.h"

Board::Board()
: Board(10,10) {}


Board::Board(int n_rows, int n_cols) {

    this->n_rows = n_rows;
    this->n_cols = n_cols;
    
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

void Board::drawBoard( std::ofstream *ofs ) {
    *ofs << std::endl;

    for (auto i(0); i <= n_rows + 1; ++i) {
        *ofs << std::setw(20) << std::setfill(' ');
        for (auto j(0); j <= n_cols + 1; ++j) {
            *ofs << cellToString(cells[i][j]) << " ";
        }
        *ofs << std::endl;
    }

    *ofs << std::endl;
}

void Board::generate_puzzle() {

    // creating the ships
    Ship battleship(4, {LEFT,MIDDLE,MIDDLE,RIGHT}, {UP,MIDDLE,MIDDLE,DOWN});
    Ship cruiser(3,{LEFT,MIDDLE,RIGHT},{UP,MIDDLE,DOWN});
    Ship destroyer(2, {LEFT,RIGHT}, {UP,DOWN});
    Ship subimarine(1, {ATOM}, {ATOM});
    // coordinates to cell where the ship will be placed
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
