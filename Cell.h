#ifndef CELL_H
#define CELL_H

class Cell {
private:
    bool isAlive;

public:
    Cell(bool alive = false) : isAlive(alive) {}
    bool getState() const { return isAlive; }
    void setState(bool state) { isAlive = state; }

    // Opérateur d'égalité pour comparer deux cellules
    bool operator==(const Cell& other) const {
        return isAlive == other.isAlive;
    }
};

#endif // CELL_H
