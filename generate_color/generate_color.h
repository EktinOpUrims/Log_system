#pragma once
#include <ostream>

enum colors {RED, GREEN, YELLOW, BLUE, MAGENTA, CYN, reset_color};

colors get_random_color();

std::ostream& operator<< (std::ostream& os, colors color);