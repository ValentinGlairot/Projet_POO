#ifndef GRID_H
#define GRID_H

#include <vector>
#include <string>  // Ajoutez cette ligne
#include "Cell.h"

class Grid {
private:
    int width, height;
    std::vector<std::vector<Cell>> cells;

public:
    Grid(int w, int h);
    void initializeRandom();
    void initializeFromFile(const std::string& filename); // Utilise std::string
    void update();
    bool isValidCell(int x, int y) const;
    int countAliveNeighbors(int x, int y) const;
    const std::vector<std::vector<Cell>>& getCells() const { return cells; }
};

#endif // GRID_H
