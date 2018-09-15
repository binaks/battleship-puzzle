#include "../include/util.h"
#include <cstdlib>
#include <ctime>
#include "../include/board.h"

int randomize(int init_range, int end_range){
    srand(time(0));
    return rand() % (end_range - init_range) + init_range;
} 
