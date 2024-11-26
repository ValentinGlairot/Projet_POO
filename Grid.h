#ifndef GRID_H
#define GRID_H

#include <vector>
#include "Cell.h"

class Grid {
private:
    int width;
    int height;
    std::vector<std::vector<Cell>> cells;

public:
    Grid(int width, int height);
    void initialize(const std::vector<std::vector<bool>>& initialState);
    void update();
    void display() const;
    bool isStable(const Grid& other) const;
    const std::vector<std::vector<Cell>>& getCells() const;
    int countAliveNeighbors(int x, int y) const;
};

#endif // GRID_H
