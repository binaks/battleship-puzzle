#include "../include/util.h"
#include <cstdlib>
#include <ctime>
#include "../include/board.h"

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
