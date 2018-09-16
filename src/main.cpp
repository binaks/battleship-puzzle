#include <iostream>

#include "../include/ship.h"
#include "../include/board.h"
#include "../include/cell.h"
#include "../include/util.h"

using namespace std;


int main (int argc, char *argv[]) {


    int qty = 1;
    int rows = 10;
    int cols = 10;

    int min_qty = 1;
    int max_qty = 100;
    int min_rc = 10;
    int max_rc = 15;

    // Checks arguments
    if ( argc > 1 ) {
        qty = stoi(argv[1]);
        if (!isValid (qty, min_qty, max_qty)) {
            cout << ">>> Invalid argument. Must be a value between " << min_qty << " and " << max_qty << "." << endl;
            return 1;
        }
    } if ( argc > 2 ) {
        rows = stoi(argv[2]);
        if (!isValid (rows, min_rc, max_rc)) {
            cout << ">>> Invalid argument. Must be a value between " << min_rc << " and " << max_rc << "." << endl;
            return 1;
        }
    } if ( argc > 3 ) {
        cols = stoi(argv[3]);
        if (!isValid (cols, min_rc, max_rc)) {
            cout << ">>> Invalid argument. Must be a value between " << min_rc << " and " << max_rc << "." << endl;
            return 1;
        }
    } if ( argc > 4 ) {
        cout << ">>> Invalid number of arguments." << endl;
    }
    // Ends argument checking

    // Writes the generated puzzles in a file
    writePuzzles (qty, rows, cols);

    return 0;
}
