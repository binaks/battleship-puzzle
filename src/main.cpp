#include <iostream>
#include "../include/ship.h"
#include "../include/board.h"
#include "../include/cell.h"

using namespace std;

int main (int argc, char *argv[]) {
    int qty;
    int rows;
    int cols;

    if ( argc == 1 ) {
        qty = 1;
    } else if ( argc == 2 ) {
        qty = stoi(argv[1]);
    } else if ( argc == 3 ){
        qty = stoi(argv[1]);
        rows = stoi(argv[2]);
    } else if ( argc == 4){
        qty = stoi(argv[1]);
        rows = stoi(argv[2]);
        cols = stoi(argv[3]);
    }

    return 0;
}
