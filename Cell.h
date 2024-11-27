#ifndef CELL_H
#define CELL_H

class Cell {
private:
    bool isAlive;

public:
    Cell(bool alive = false) : isAlive(alive) {}
    bool getState() const { return isAlive; }
    void setState(bool state) { isAlive = state; }
};

#endif // CELL_H
