#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "../include/board.h"
#include "../include/util.h"

// Returns a random number in a range
int randomize(int init_range, int end_range){
    srand(time(0));
    return rand() % (end_range - init_range) + init_range;
}

// Checks if the argument given is in a valid range
bool isValid (int arg, int min, int max) {
    if ( arg >= min and arg <= max )
        return true;
    else return false;
}

// Writes generated puzzles in a file
void writePuzzles (int qty, int rows, int cols) {
    std::string puzzles = "puzzles"; // Name of the file where the puzzles will be written
    std::ifstream ifs;
    
    // Opening the file
    ifs.open(puzzles);

    // 
    for (auto i(0); i < qty; i++) {
    }

    // Closing the file
    ifs.close();

}
