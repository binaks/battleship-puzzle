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
// Drawing the puzzle ignoring the border cells
void Board::drawBoard( std::ofstream *ofs ) {
    *ofs << std::endl;

    for (auto i(1); i <= n_rows; ++i) {
        *ofs << std::setw(20) << std::setfill(' ');
        for (auto j(1); j <= n_cols; ++j) {
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
    Ship submarine(1, {ATOM}, {ATOM});
    
    // coordinates to cell where the ship will be placed
    placeShip(battleship);

    for( int i = 0; i < 2; i++)
        placeShip(cruiser);

    for(int i = 0; i < 3; i++)
        placeShip(destroyer);

    for(int i = 0; i < 4; i++)
        placeShip(submarine);
    
}

void Board::placeShip(Ship ship) {
    bool good_position = false;
    
    // initializing the random positions
    int r = randomize(1,n_rows);
    int c = randomize(1,n_cols);
    // initializing the booleans
    bool vertical_position = true;
    bool horizontal_position = true;
    
    while( not good_position ) {

        // finding a free position
        while(cells[r][c] != WATER){
            r = randomize(1,n_rows);
            c = randomize(1,n_cols);
        }

        // Checking if we can place the ship in the horizontal
        // #1 checking if it fits
        if ( c + ship.size - 1 > n_cols ){ 
            horizontal_position = false;
        }
        else {
        // #2 checking if the surroundings are free
            for( auto i(r - 1); i <= r + 1; ++i ){
                for ( auto j(c - 1); j <= c + ship.size; ++j){
                    if( cells[i][j] != WATER and cells[i][j] != HALO and cells[i][j] != BORDER ){
                        horizontal_position = false;
                        break;
                    }
                }
            }
        }

        // Checking if we can place the ship in the vertical
        // #1 checking if it fits
        if ( r + ship.size - 1 > n_rows ){
            vertical_position = false;
        }
        else {
        // #2 checking if the surroundings are free
            for( auto i(r - 1); i <= r + ship.size; ++i ){
                for( auto j(c - 1); j <= c + 1; ++j ){
                    if( cells[i][j] != WATER and cells[i][j] != HALO and cells[i][j] != BORDER ){
                        vertical_position = false;
                        break;
                    }
                }
            }
        }
        
        // Now we know if it's possible to place the ship and in which positions
        if ( vertical_position or horizontal_position ){
            good_position = true;
        }
    }
    if ( vertical_position and horizontal_position ) {
        // lets randomize if it's gonna be vertical or horizontal
        int v_or_h = randomize(0,1);
        if ( v_or_h == 0 ){
            horizontal_position = false;
        }
        else {
            vertical_position = false;
        }
    }
    if ( horizontal_position ) {
        // Place the ship in the horizontal position
        for (auto i(r - 1); i <= r + 1; ++i){
            for (auto j(c - 1); j <= c + ship.size; ++j){
                if( i == r and ship.size > j - c ){
                    cells[i][j] = ship.horizontal[j - c];
                }
                else{
                    cells[i][j] = HALO;
                }
            }
        }
    }
    else {
        // Place the ship in the vertical position
        for (auto i(r - 1); i <= r + ship.size; ++i){
            for (auto j(c - 1); j <= c + 1; ++j){
                if( j == c and ship.size > i - r){
                    cells[i][j] = ship.vertical[i - r];
                }
                else{
                    cells[i][j] = HALO;
                }
            }
        } 
    } 
}
