#include "Grid.h"

Grid::Grid(int rows, int cols, const std::vector<std::vector<bool>>& initialState)
    : rows(rows), cols(cols), cells(initialState) {}

bool Grid::isAlive(int row, int col) const {
    return row >= 0 && row < rows && col >= 0 && col < cols && cells[row][col];
}

int Grid::countLiveNeighbors(int row, int col) const {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i != 0 || j != 0) {
                count += isAlive(row + i, col + j);
            }
        }
    }
    return count;
}

void Grid::update() {
    std::vector<std::vector<bool>> newCells = cells;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            int liveNeighbors = countLiveNeighbors(r, c);
            if (cells[r][c]) {
                newCells[r][c] = (liveNeighbors == 2 || liveNeighbors == 3);
            } else {
                newCells[r][c] = (liveNeighbors == 3);
            }
        }
    }

    cells = newCells;
}

const std::vector<std::vector<bool>>& Grid::getCells() const {
    return cells;
}
