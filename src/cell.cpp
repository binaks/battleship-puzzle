#include "../include/cell.h"

std::string cellToString (Cell c) {
    if      (c == LEFT  ) return "◄";
    else if (c == RIGHT ) return "►";
    else if (c == MIDDLE) return "■";
    else if (c == UP    ) return "▲";
    else if (c == DOWN  ) return "▼";
    else if (c == ATOM  ) return "●";
    else if (c == BORDER) return "≈";
    else return "≈";
} 
