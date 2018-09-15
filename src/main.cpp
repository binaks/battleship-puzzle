#include <iostream>
#include "../include/ship.h"
#include "../include/board.h"
#include "../include/cell.h"

using namespace std;

int main (int argc, char *argv[]) {
    int puzzles;
    int cols;
    int rows;
     
    if ( argc > 3 ){
        puzzles = stoi(argv[1]);
        cols = stoi(argv[2]);
        rows = stoi(argv[3]);

        Board cruiser(cols,rows);
        cruiser.drawBoard();
    }
    else{
        Board cruiser;
        cruiser.drawBoard();
    }

    return 0;
}
