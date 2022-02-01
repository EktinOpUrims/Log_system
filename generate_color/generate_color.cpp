#include <cstdlib>
#include <ctime>

#include "generate_color.h"
#include "color.h"
#include "globals.h"


int curr_color = 0;

colors get_random_color()
{
    curr_color = (curr_color + 1) % reset_color;
    return static_cast<colors>(curr_color);

    return static_cast<colors> (rand() % reset_color);
}


std::ostream& operator<< (std::ostream& os, colors color)
{
    switch (color) {
        case RED:
            os << KRED;
            break;
        case GREEN:
            os << KGRN;
            break;
        case YELLOW:
            os << KYEL;
            break;
        case BLUE:
            os << KBLU;
            break;
        case MAGENTA:
            os << KMAG;
            break;
        case CYN:
            os << KCYN;
            break;
        case reset_color:
            os << RST;
            break;
    }
    return os;
}

