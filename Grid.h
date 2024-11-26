#ifndef GRID_H
#define GRID_H

#include <vector>

class Grid {
private:
    int rows, cols;
    std::vector<std::vector<bool>> cells;

public:
    Grid(int rows, int cols, const std::vector<std::vector<bool>>& initialState);
    bool isAlive(int row, int col) const;
    int countLiveNeighbors(int row, int col) const;
    void update();
    const std::vector<std::vector<bool>>& getCells() const;
};

#endif
