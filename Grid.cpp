#include "Grid.h"
#include <iostream>

Grid::Grid(int width, int height) : width(width), height(height) {
    cells.resize(height, std::vector<Cell>(width, Cell(0, 0, false)));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            cells[y][x] = Cell(x, y, false);
        }
    }
}

void Grid::initialize(const std::vector<std::vector<bool>>& initialState) {
    for (int y = 0; y < initialState.size(); ++y) {
        for (int x = 0; x < initialState[y].size(); ++x) {
            cells[y][x].setState(initialState[y][x]);
        }
    }
}

void Grid::update() {
    std::vector<std::vector<Cell>> newCells = cells;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int aliveNeighbors = countAliveNeighbors(x, y);
            bool currentState = cells[y][x].getState();

            if (currentState) {
                if (aliveNeighbors < 2 || aliveNeighbors > 3) {
                    newCells[y][x].setState(false);
                }
            } else {
                if (aliveNeighbors == 3) {
                    newCells[y][x].setState(true);
                }
            }
        }
    }
    cells = newCells;
}

int Grid::countAliveNeighbors(int x, int y) const {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int nx = x + j;
            int ny = y + i;
            if (i == 0 && j == 0) continue;
            if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                if (cells[ny][nx].getState()) {
                    ++count;
                }
            }
        }
    }
    return count;
}

void Grid::display() const {
    for (const auto& row : cells) {
        for (const auto& cell : row) {
            std::cout << (cell.getState() ? "1 " : "0 ");
        }
        std::cout << std::endl;
    }
}

bool Grid::isStable(const Grid& other) const {
    return cells == other.cells;
}

const std::vector<std::vector<Cell>>& Grid::getCells() const {
    return cells;
}
