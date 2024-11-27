#ifndef GRID_H
#define GRID_H

#include <vector>
#include <string>
#include "Cell.h"

class Grid {
private:
    int width, height;
    std::vector<std::vector<Cell>> cells;

public:
    Grid(int w, int h);
    void initializeRandom();
    void initializeFromFile(const std::string& filename);
    void update();
    bool isValidCell(int x, int y) const;
    int countAliveNeighbors(int x, int y) const;
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    const std::vector<std::vector<Cell>>& getCells() const { return cells; }

    // Opérateur d'égalité pour comparer deux grilles
    bool operator==(const Grid& other) const;
};

#endif // GRID_H
