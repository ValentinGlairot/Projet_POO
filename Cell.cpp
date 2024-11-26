#include "Cell.h"

Cell::Cell(int x, int y, bool isAlive) : x(x), y(y), isAlive(isAlive) {}

bool Cell::getState() const {
    return isAlive;
}

void Cell::setState(bool state) {
    isAlive = state;
}

int Cell::getX() const {
    return x;
}

int Cell::getY() const {
    return y;
}

// Implement the operator==
bool Cell::operator==(const Cell& other) const {
    return isAlive == other.isAlive;
}
