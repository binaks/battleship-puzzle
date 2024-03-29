#include <random>

#include "../include/board.h"
#include "../include/util.h"

using namespace std;
// Returns a random number in a range
int randomize(int init_range, int end_range){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(init_range,end_range);

    return dist(gen);
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
    std::ofstream ofs;

    
    // Opening the file
    ofs.open(puzzles);
    
    // Writes as many puzzles as specified in qty
    
    // We commit this parts because it's not working to n puzzles
    //for (auto i(0); i < qty; i++) {
        ofs << "PUZZLE " << /*i+*/1 << std::endl;

        // Placeholder for randomly generated puzzle
        Board puzzle(rows, cols);
        puzzle.generate_puzzle();
        puzzle.drawBoard(&ofs);
    //}

    // Closing the file
    ofs.close();
}
